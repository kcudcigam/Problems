#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y,db[1000010],nxt[1000010],len[1000010],d,e,f,g,s,k,n[1000010],p;
bool v[1000010];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);read(b);read(c);memset(v,0,sizeof(v));
	for (int i=1;i<=b;i++)
	{
		read(x);read(y);
		db[i*2-1]=y;
		nxt[i*2-1]=len[x];
		len[x]=i*2-1;
		db[i*2]=x;
		nxt[i*2]=len[y];
		len[y]=i*2;
		if (x==1) v[y]=1;
		if (y==1) v[x]=1;
	}
	if ((a<=3000)&&(b<=3000)&&(c<=3000))
	{
		for (int i=1;i<=c;i++)
		{
			read(d);
			if (d==0)
			{
				read(e);
				s=n[e];
				k=len[e];
				while (k)
				{
					s+=n[db[k]];
					k=nxt[k];
				}
				cout<<s<<endl;
			}
			else
			{
				read(f);read(g);
				n[f]+=g;
			}
		}	
		return 0;	
	}
	for (int i=1;i<=c;i++)
	{
		read(d);
		if (d==0)
		{
			read(e);
			if (e==1) cout<<p+n[1]<<endl;
			else
			{
				s=n[e];
				k=len[e];
				while (k)
				{
					s+=n[db[k]];
					k=nxt[k];
				}
				cout<<s<<endl;				
			}
		}
		else
		{
			read(f);read(g);
			n[f]+=g;
			if (v[f]) p+=g;
		}
	}
	return 0;
}


