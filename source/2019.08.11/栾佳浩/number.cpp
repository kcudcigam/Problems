#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int t;
int b[15];
ll ton[20];
int pd(ll x)
{
	memset(b,0,sizeof b);
	int ans=0;
	while(x)
	{
		if(b[x%10]==0)ans++;
		b[x%10]++;
		x/=10;
	}
	return ans<=2;
}
int dfs(ll res,ll x,ll y,int num)
{
//	cout<<res<<" "<<x<<" "<<y<<" "<<num<<endl;
	if(res==0)return true;
	for(int i=1;i<=9;i++)
	{
		if(pd(x+1ll*i*ton[num]))
		{
			ll nwx,nwy,nwres;
			if(i>res%10&&res/10!=0)
			{
				nwx=x+1ll*i*ton[num];
				nwy=y+1ll*(res%10+10-i)*ton[num];
				nwres=res/10;
				nwres--;
			}
			else if(i<=res%10)
			{
				//cout<<"pr";
				nwx=x+1ll*i*ton[num];
				nwy=y+1ll*(res%10-i)*ton[num];
				nwres=res/10;
			}
			if(pd(nwy))if(dfs(nwres,nwx,nwy,num+1))return  true;
		}
	} 
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ton[1]=1;
	for(int i=2;i<=18;i++)
	{
		ton[i]=ton[i-1]*10;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(pd(n))puts("1");
		else if(n<=10000000000000ll)
		{
			if(dfs(n,0,0,1))puts("2");
			else puts("3");
		}
		else 
		{
			int ans=0;
			while(n)	
			{
				if(!b[n%10])b[n%10]=1,ans++;
				n/=10;	
			}
			printf("%d\n",(ans+1)/2);
		}
	}
}
