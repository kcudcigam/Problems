#include<bits/stdc++.h>
#define maxn 400010
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int a[5][maxn];
int n[5],ans;
int res[maxn],tot;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n[0]);
	for(int i=1;i<=n[0];i++)
	{
		char s[4];
		scanf("%s",s);
		if(s[0]=='1'&&s[1]=='1') n[1]++,scanf("%d",&a[1][n[1]]);
		else
		{
			if(s[0]=='1'&&s[1]=='0') n[2]++,scanf("%d",&a[2][n[2]]);
			else
			{
				if(s[0]=='0'&&s[1]=='1') n[3]++,scanf("%d",&a[3][n[3]]);
				else n[4]++,scanf("%d",&a[4][n[4]]);
			}
		}
	}
	for(int i=1;i<=4;i++)
	sort(a[i]+1,a[i]+n[i]+1,cmp);
	for(int i=1;i<=n[2]&&i<=n[3];i++)
	ans+=a[2][i]+a[3][i];
	if(n[2]<n[3])
	{
		for(int i=n[2]+1;i<=n[3];i++)
		res[++tot]=a[3][i];
	}
	else
	{
		for(int i=n[3]+1;i<=n[2];i++)
		res[++tot]=a[2][i];
	}
	int now,i,j;
	for(now=1,i=1,j=1;now<=n[1]&&(i<=tot||j<=n[4]);now++)
	{
		ans+=a[1][now];
		if(res[i]>a[4][j]) ans+=res[i],i++;
		else ans+=a[4][j],j++;
	}
	while(now<=n[1]) ans+=a[1][now],now++;
	printf("%d\n",ans);
	return 0;
}


