#include<bits/stdc++.h>
using namespace std;
int maxn=1000000007,n,f[2000][2000],a[10000],ans,vis[1000],num,M1,M2,aa,b,jc[600000],mc[600000],p;
int check()
{
	for (int i=1;i<n;i++)
	  for (int j=1;j<=n;j++)
	    {
	    	if (i!=j&&f[i][j]!=0&&f[i][j]!=f[a[i]][a[j]])
	    	return 1;
		}
}
void dfs(int dep)
{
	if (dep>n)
	{
		if (check()==1)
		{
			ans=(ans+1)%maxn;
			return;
	    }
	    return;
	}
	for (int i=1;i<=n;i++)
	  {
	  	a[dep]=i;
	  	if (vis[i]==0)
	  	{
	  		vis[i]=1;
	  		dfs(dep+1);
	  		vis[i]=0;
		  }
	  }
}
int main(){
    ios::sync_with_stdio(false);
    freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>num;
	cin>>n>>M1>>M2;
	jc[1]=1;
	for (int i=2;i<=n;i++)
	  jc[i]=(long long)(jc[i-1]*i)%maxn; 
	mc[1]=2;
	for (int i=2;i<=n;i++)
	  mc[i]=(mc[i-1]*2)%maxn; 
	for (int i=2;i<=n;i++)
	if (num==1)
	{
		cout<<0<<endl;
		return 0;
	}
	if (num==2)
	{
		if (M1==1&&M2==1)
		cout<<1<<endl;
		else cout<<0<<endl;
		return 0; 
	 } 
	for (int i=1;i<=M1;i++) 
	  {
	  	cin>>aa>>b;
	  	if (num<=17)
	  	{
	  		f[aa][b]=1;
	  		f[b][aa]=1;
		  }
	   } 
	for (int i=1;i<=M2;i++) 
	  {
	  	cin>>aa>>b;
	  	if (num<=17)
	  	{
	  		f[aa][b]=2;
	  		f[b][aa]=2;
		  }
	   } 
	if (num<=6)
	{
		dfs(1);
		cout<<ans%maxn<<endl;
		return 0;
	}
	if (num<=10) 
	{
		p=n-(M1+M2)*2; 
		ans=(long long)((long long)(jc[p]*jc[M1])%maxn)*(jc[M2])%maxn;
		ans=(long long)((long long)(ans*mc[M1])%maxn)*mc[M2]%maxn;
		ans=(long long)jc[n]+maxn-ans;
		ans%=maxn;
		cout<<ans<<endl;
	}
	return 0;
}


