#include<bits/stdc++.h>

using namespace std;
const int MAXN=300005;
const int MAXM=300005;

int a[MAXN],head[MAXN],tail,n,m,q,laz[MAXN];

struct Edge
{
	int x,y,nex;
}e[MAXM*2];

void read(int &p)
{
	char s=getchar();int flag=1;p=0;
	while(!isdigit(s))
	{
		if(s=='-') flag=-1;
		s=getchar();
	}
	for(;isdigit(s);s=getchar()) p=p*10+s-'0';
	p*=flag;
 } 


void add(int x,int y)
{
	e[++tail].x=x;e[tail].y=y;
	e[tail].nex=head[x];head[x]=tail;
}

void downn(int x)
{
	if(laz[x])
	{
		for(int i=head[x];i;i=e[i].nex)
		{
			int y=e[i].y;
			a[y]+=laz[x];
		}
		laz[x]=0;
	}
}

int askk(int x)
{
	for(int i=head[x];i;i=e[i].nex)
	{
		downn(e[i].y);
	}
	return a[x];
}

void chan(int x,int y)
{
	laz[x]+=y;
	a[x]+=y;
}

int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);

	read(n);read(m);read(q);
	int flag,x,y;
	for(int i=1;i<=m;i++)
	{
		read(x);read(y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=q;i++)
	{
		//cout<<"A"<<endl;
		read(flag);
		if(flag==0)
		{
			read(x);
			printf("%d\n",askk(x));
		}
		else
		{
			read(x);read(y);
			//cout<<x<<" "<<y<<endl;
			chan(x,y);
		}
	}
	return 0;
 } 
