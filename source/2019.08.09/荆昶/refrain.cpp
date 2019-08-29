#include<bits/stdc++.h>
using namespace std;
short int l[200001];
bool b[200001];
long long s;
int n,m1,m2;
void f(int p)
{
	if(p>n) return;
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
//			if((l[i]&1)==0&&(l[p]&1)==1||(l[i]&2)==0&&(l[p]&2)==1)
			if(l[i]^l[p])
			{
				long long r=1;
				for(int j=n-p;j>=1;j--)
				{
					r*=j;
					r%=1000000007;
				}
				s+=r;
				s%=1000000007;
			}
			else
			{
				b[i]=1;
				f(p+1);
				b[i]=0;
			}
		}
	}
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int num;
	scanf("%d",&num);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		l[x]|=1;l[y]|=1;
	}
	for(int i=1;i<=m2;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		l[x]|=2;l[y]|=2;
	}
	f(1);
	printf("%d",s);
	return 0;
}

