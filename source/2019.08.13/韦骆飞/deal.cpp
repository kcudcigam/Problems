#include <bits/stdc++.h>
using namespace std;
long long q,value[10005],num1[10005],num2[10005],f[10005],m,ans,n,a,c,b,ap[10005],pp;
void dfs(int dep,int value2)
{
	if (dep==0)
	{
		if (value2==m)
		{
			ans=(ans+1)%1000000007;
	}
		return;
	
	}
	if (value2==f[dep])
	{
		ans=(ans+1)%1000000007;
	}
	for (int i=0;i<=num1[dep];i++)
	  {
	  	int k=value2+value[dep]*(i-2);
	  	if (k>m*2) break;
	  	ap[dep]=i;
	  	dfs(dep-1,value2+value[dep]*i);
	  }
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	  {
	  	cin>>a>>b>>c;
	  	if (b+c>0) {
	  	q++;
	  	value[q]=a;
	  	num1[q]=b;
	  	num2[q]=c;
	  	num1[q]+=num2[q]; }
	   } 
	for (int i=q;i>0;i--)
	  {
	  	f[i]=f[i+1]+(num1[i]-num2[i])*value[i];
	  }
	dfs(q,0);
	cout<<ans<<endl;
	return 0;
}

