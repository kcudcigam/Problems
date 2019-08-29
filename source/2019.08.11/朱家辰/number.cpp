#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int t,len,cnt,ans;
ll a[25];
bool vis[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ll x;
		scanf("%lld",&x);
		ans=0;
		while(x)
		{
			ans++;
			ll tmp=x,p=1;
			len=cnt=0;
			memset(vis,0,sizeof(vis));
			while(tmp)
			{
				a[++len]=tmp%10;
				if(!vis[a[len]])
				{
					vis[a[len]]=true;
					cnt++;
				}
				tmp/=10;
				p*=10;
			}
			p/=10;
			if(cnt<=2) break;
			ll k1,k2;
			if(a[len-2]<a[len-1]&&a[len-2]<a[len]) k1=max(a[len],a[len-1]),k2=a[len-2];
			else k1=max(a[len],a[len-1]),k2=min(a[len],a[len-1]);
			ll k=0;
			for(int i=len;i>=1;i--)
			{
				if(a[i]>=k1) k=k+k1*p;
				else k=k+k2*p;
				p/=10;
			}
			x-=k;
		}
		printf("%d\n",min(ans,4));
	}
	return 0;
}


