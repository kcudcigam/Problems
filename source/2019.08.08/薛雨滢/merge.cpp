#include<bits/stdc++.h>

using namespace std;
const int MAXN=500005;

int fa[MAXN],s[MAXN],n,q;

template <typename T> void read(T &x)
{
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}


int getfa(int x)
{
	if(fa[x]==x) return x;
	int ttem=fa[x];
	int tem=getfa(fa[x]);
	if(tem!=ttem) s[x]+=s[ttem];
	return fa[x]=tem;
}

void merge(int x,int y)
{
	int fx=getfa(x),fy=getfa(y);
	if(fx==fy) return ;
	s[fx]-=s[fy];
	fa[fx]=fy;
}

void work(int x,int y)
{
	int fx=getfa(x);
	s[fx]+=y;
}

int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	
	read(n);read(q);

	for(int i=1;i<=n;i++) fa[i]=i;
	int flg,x,y;
	for(int i=1;i<=q;i++)
	{
		read(flg);read(x);read(y);
		if(flg==1)
		{
			merge(x,y);
		}
		else
		{
			work(x,y);
		}
	}
	
//	for(int i=1;i<=n;i++) cout<<i<<" "<<s[i]<<" "<<getfa(i)<<" "<<s[getfa(i)]<<endl;
	
	for(int i=1;i<=n;i++) 
	{
		int tem=getfa(i);
		if(i==tem)	printf("%d",s[i]);
		else printf("%d",s[i]+s[tem]);
		if(i<n) putchar(' ');
	}
	
	return 0;
}
