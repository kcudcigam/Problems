#include<bits/stdc++.h> 

using namespace std;
const int mod=1e9+7;
const int MAXN=1005;
int num,n,m1,m2,cnt1[MAXN],cnt2[MAXN],ori[MAXN][MAXN];

struct Node
{
	int x,y;
	bool operator <(const Node & b)
	const
	{
		return x<b.x;
	}
};

map<Node,int> m;

Node make_node(int x,int y)
{
	Node tem;
	tem.x=x;tem.y=y;
	return tem;
}




void read(int &p)
{
	p=0;char s=getchar();int flag=1;
	while(!isdigit(s))
	{
		if(s=='-') flag=-1;
		s=getchar();
	}
	for(;isdigit(s);s=getchar()) p=p*10+s-'0';
	p*=flag;
}

int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	read(num);read(n);read(m1);read(m2);
	int x,y;
	for(int i=1;i<=m1;i++)
	{
		read(x);read(y);ori[x][y]=ori[y][x]=1;cnt1[x]++;cnt1[y]++;
	}
	for(int i=1;i<=m2;i++)
	{
		read(x);read(y);ori[x][y]=ori[y][x]=-1;cnt2[x]++;cnt2[y]++;
	}
	int tn=n,ans=1;
	while(tn)
	{
		ans=(ans*tn)%mod;
		tn--;
	}
	
	if(num<=6)
	{
		int a[15];
		for(int i=1;i<=n;i++) a[i]=i;
		do
		{
			int flag=1;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(ori[i][j]!=ori[a[i]][a[j]])
					{
						flag=0;
						break;
					}
				}
			}
			ans-=flag;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans<<endl;
		return 0;
	}
	
	if(num<=20)
	{
		for(int i=1;i<=n;i++)	m[make_node(cnt1[i],cnt2[i])]++;
		
		int cnt=1;
		for(int i=1;i<=n;i++)
		{
			cnt*=m[(make_node(cnt1[i],cnt2[i]))];
			m[(make_node(cnt1[i],cnt2[i]))]--;
			cnt%=mod;	
		}
		
		cout<<((ans-cnt+1)%mod+mod)%mod<<endl;
		return 0;
	}
	

	return 0;
}
