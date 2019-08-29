#include<bits/stdc++.h>
using namespace std;
int n,x,a[1002],b[1002],c[1002],ans,d,h[1002],f,e,g;
void ducker(int dep)
{
	if(dep>n) 
	{
		if(f!=e) return;
		g=1;
	}
	for(int i=0;i<=c[dep];i++)
	{
		if(g==1) return;
		h[dep]=i;
		f=f+a[dep]*i;	
		ducker(dep+1);
		f=f-a[dep]*i;
	}
}
void duck(int dep)
{
	if(dep>n) 
	{
		if(d<x) return;
		for(int j=1;j<=n;j++) if(a[j]<=d-x&&h[j]>0) return;
		if(d>x)
		{
			e=d-x;
			g=0;
			ducker(1);
			if(g==1)
			{
			ans++;
			if(ans>1000000007) ans=ans%1000000007;
			}
		}
		else
		{
		ans++;
		if(ans>1000000007) ans=ans%1000000007;
		}
		return;
	}
	for(int i=0;i<=b[dep];i++)
	{
		h[dep]=i;
		d=d+a[dep]*i;	
		duck(dep+1);
		d=d-a[dep]*i;
	}
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	duck(1);
	cout<<ans%1000000007<<endl;
	return 0;
}


