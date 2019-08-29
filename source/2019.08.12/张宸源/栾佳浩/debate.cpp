#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=400005;
int asp[maxn];
int sp1[maxn];
int sp2[maxn];
int nsp[maxn];
int o1,o2,o3,o4;
char s[5];
long long ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		if(s[0]=='1')
		{
			if(s[1]=='1')
			{
				o1++;
				scanf("%d",&asp[o1]);
				ans+=asp[o1];
			}
			else
			{
				o2++;
				scanf("%d",&sp1[o2]);
			}
		}
		else 
		{
			if(s[1]=='1')
			{
				o3++;
				scanf("%d",&sp2[o3]);
			}
			else 
			{
				o4++;
				scanf("%d",&nsp[o4]);
			}
		}
	}
	sort(sp1+1,sp1+1+o2,cmp);
	sort(sp2+1,sp2+1+o3,cmp);
	for(int i=1;i<=min(o2,o3);i++)
	{
		ans+=sp1[i]+sp2[i];
	}
	if(o2<o3)
	{
		for(int i=o2+1;i<=o3;i++)
		{
			nsp[++o4]=sp2[i];
		}
	}
	else 
	{
		for(int i=o3+1;i<=o2;i++)
		{
			nsp[++o4]=sp1[i];
		}
	}	
	sort(nsp+1,nsp+1+o4,cmp);
	for(int i=1;i<=o1;i++)
	{
		ans+=nsp[i];
	}
	printf("%lld",ans);
}
