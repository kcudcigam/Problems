#include<bits/stdc++.h>
using namespace std;
int n,Q;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
void write(int a,bool flag)
{
	if(a||flag)
		{
			write(a/10,0);
			putchar(a%10+48);
		}
	return;
}
inline void puti(int a)
{
	write(a,1);
}
struct fuck_tree{
	struct info{int fa,lson,rson,dick;};
	info p[1000005];
	int zs;
	int fato[1000005];
	inline void begin()
		{
			for(int i=1;i<=n;i++) fato[i]=i;
			zs=n;
		}
	int find_father(int now)
		{
			if(fato[now]!=now) fato[now]=find_father(fato[now]);
			return fato[now];
		}
	inline void nbui(int a,int b)
		{
			int r1=find_father(a);
			int r2=find_father(b);
			if(r1==r2) return;
			zs++;
			fato[r1]=zs;
			fato[r2]=zs;
			fato[zs]=zs;
			p[r1].fa=zs;
			p[r2].fa=zs;
			p[zs].lson=r1;
			p[zs].rson=r2;
		}
	inline void dicker(int a,int b)
		{
			int r=find_father(a);
			p[r].dick+=b;
		}
	void endle(int now,int dick)
		{
			if(now==0) return;
			p[now].dick+=dick;
			dick=p[now].dick;
			endle(p[now].lson,dick);
			endle(p[now].rson,dick);
		}
	inline void endd()
		{
			for(int i=1;i<=zs;i++) if(p[i].fa==0) endle(i,0);
		}
	inline int outer()
		{
			endd();
			for(int i=1;i<=n;i++)
				{
					puti(p[i].dick);
					putchar(' ');
				}
			cout<<endl;
		}
};
fuck_tree ft;
int main()
{
    freopen("merge.in","r",stdin);
    freopen("merge.out","w",stdout);
	read(n);
	read(Q);
	ft.begin();
	while(Q--)
		{
			int op,a,b;
			read(op);
			read(a);
			read(b);
			if(op==1) ft.nbui(a,b);
			if(op==2) ft.dicker(a,b);
		}
	ft.outer();
	return 0;
}
/*
2 3
2 1 1
1 2 1
2 1 3
*/

