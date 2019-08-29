#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c,d,e[200002],ans,mins,s[200002],cs[200002],lastq,lasti;
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	cin>>n>>a>>b>>c>>d;
	mins=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&e[i]);
		mins=min(mins,e[i]);
	} 
	if(mins>0)
	{
		if((((a*mins)+b)*mins+c)*mins+d>0)
		{
			for(int i=1;i<=n;i++) ans=ans+(((a*e[i])+b)*e[i]+c)*e[i]+d;
			cout<<ans<<endl;
		}
		else
		{
		if(a==0&&b==0&&c<=0&&d<=0) cout<<d+c*mins<<endl;
		else
		{
		for(int i=1;i<=n;i++) s[i]=s[i-1]+(((a*e[i])+b)*e[i]+c)*e[i]+d;
		lastq=0;lasti=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]>=0)
			{
			 lastq=i;
			 cs[i]=s[i]-lasti;	
			}
			else
			{
				if(s[i]<0)
				{
					if(s[lastq]<s[i]) 
					{
						cs[i]=s[i]-s[i-1];
						if(s[i+1]>s[i]) lastq=i;lasti=s[i];
					}
					else cs[i]=s[i]-s[i-1];
				}
			}
		}
		cout<<cs[n]<<endl;	
		}	
		}
	}
	else
	{
		for(int i=1;i<=n;i++) ans=ans+(((a*e[i])+b)*e[i]+c)*e[i]+d;
			cout<<ans<<endl;
	}
	return 0;
}


