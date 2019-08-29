#include<bits/stdc++.h>
using namespace std;
int fa[500010],a,b,c,d,e,s[500010],t;
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int wrkk(int x)
{
	int p=x;
	while (x!=fa[x]) x=fa[x];
	while (p!=x)
	{
		t=fa[x];
		fa[x]=x;
		p=t;
	}	
	return x;
}
void wrk(int x,int y)
{
	int fx=wrkk(x),fy=wrkk(y);
	if (fx!=fy)	fa[fx]=fy;
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);read(b);
	for (int i=1;i<=a;i++) fa[i]=i;
	for (int i=1;i<=b;i++)
	{
		read(c);read(d);read(e);
		if (c==2) 
		{
			for (int j=1;j<=a;j++)
			if (wrkk(j)==wrkk(d)) s[j]+=e;
		}
		else wrk(d,e);
	}
	for (int i=1;i<a;i++) cout<<s[i]<<' ';
	cout<<s[a]<<endl;
	return 0;
}


