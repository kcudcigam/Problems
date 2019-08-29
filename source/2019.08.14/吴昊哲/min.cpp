#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ri() 
{
	char c=getchar();ll x=0,f=1;
	for(;c<'0'||c>'9';c=getchar())if(c == '-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)-'0'+c;
	return x*f;
}
ll n,A,B,C,D,a[1000000],flag;
ll ans;
ll cal(ll x) 
{
    return ((A*x+B)*x+C)*x+D;
}
int main() 
{
	freopen("min.in","r",stdin);
	freopen("min.out","r",stdout);
    n=ri();A=ri();B=ri();C=ri();D=ri();
    for(ll i=1;i<=n;i++)
	{
		a[i]=ri();
		if(a[i]<0)flag=1;
	}
	if(flag==0)
	{
		for(ll i=1;i<=n;i++)
	    {
		    if(cal(a[i])<0)continue;
	        else
	        {
	    	    ans+=cal(a[i]);
			    flag=10;
		    }
	    }	
		if(flag!=10)
	    {
	        int maxn;
	        for(int i=1;i<=n-1;i++)
	        {
	    	    maxn=max(cal(a[i]),cal(a[i+1]));
		    }
		    ans=cal(maxn);
	    }
	}
    if(flag==1)
	{
		for(ll i=1;i<=n;i++)
	    {
		    if(cal(a[i])<0)continue;
	        else
	        {
	    	    ans+=cal(a[i]);
			    flag=10;
		    }
	    }	
		if(flag!=10)
	    {
	        int maxn;
	        for(int i=1;i<=n-1;i++)
	        {
	    	    maxn=max(cal(a[i]),cal(a[i+1]));
		    }
		    ans=cal(maxn);
	    }
	}	
    cout<<ans<<endl;
	return 0;
}

