#include<bits/stdc++.h>

using namespace std;
const int MAXN=300005;

int n,maxn1[MAXN],maxn2[MAXN],head[MAXN],a[MAXN],b[MAXN],fa[MAXN],tail;

struct Edge
{
	int x,y,nex;
}e[MAXN*2];

void add(int x,int y)
{
	e[++tail].x=x;e[tail].y=y;
	e[tail].nex=head[x];head[x]=tail;
}

void read(int &p)
{
	p=0;int flag=1;char s=getchar();
	while(!isdigit(s))
	{
		//cout<<s<<endl;
		if(s=='-') flag=-1;
		s=getchar();
	}
	for(;isdigit(s);s=getchar()) p=p*10+s-'0';
	p*=flag;
}

void dfs(int x)
{
	for(int i=head[x];i;i=e[i].nex)
	{
		int y=e[i].y;
		if(y!=fa[x])
		{
			fa[y]=x;
			dfs(y);
		}
	}
}

int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	read(n);
//	cout<<n<<endl;
	int x,y;
	for(int i=1;i<n;i++)
	{
		read(x);read(y);
		a[i]=x,b[i]=y; 
		add(x,y);add(y,x);
	}
	fa[1]=1;
	//cout<<"A";
	dfs(1);
	//cout<<"B";
	for(int i=1;i<n;i++)
	{
		x=a[i],y=b[i];
		if(fa[x]==y) swap(x,y);
		if(maxn1[y]+1>maxn1[x]) maxn2[x]=maxn1[x],maxn1[x]=maxn1[y]+1;
		else
		{
			if(maxn1[y]+1>maxn2[x]) maxn2[x]=maxn1[y]+1;
		}
		printf("%d\n",maxn1[x]+maxn2[x]); 
	//	for(int i=1;i<=n;i++) cout<<maxn1[i]<<" "<<maxn2[i]<<endl;
	}
	return 0;
 } 
