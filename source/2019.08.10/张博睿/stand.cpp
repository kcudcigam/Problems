#include<bits/stdc++.h>
using namespace std;
int n,m,x,x2,x3,x4,x5,tot[10002],a[300],b[300],sq,h[10010002],c[10010002],d,e,k,la[10002],kd[10002],bh,mm,kk;
long long ans,ax[300],ac;
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	cin>>n>>m;
	cin>>x>>x2>>x3>>x4>>x5;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(a[i]>b[i]) swap(a[i],b[i]);
	}
	sq=floor(sqrt(m));
	for(int i=1;i<=m;i++) h[i]=(i-1)/sq+1;
	for(int i=1;i<=n;i++)
	{
		d=a[i];e=b[i];
		while(d%sq!=1)d++;
		while(e%sq!=0)e--;
		if(h[b[i]]-h[a[i]]<=1) for(int j=a[i];j<=b[i];j++) c[j]++;
		else
		{
		for(int j=a[i];j<d;j++) c[j]++;
		for(int j=b[i];j>e;j--) c[j]++;
		for(int j=d;j<=e;j+=sq) tot[h[j]]++;	
		}
	}
	ac=0;
	memset(kd,0,sizeof(kd));
	for(int i=1;i<=m;i+=sq)
	 for(int j=i;j<=i+sq-1;j++) 
	  if(c[j]+tot[h[j]]>kd[h[i]]) 
	  {
		kd[h[i]]=c[j]+tot[h[j]];
		la[h[i]]=j;
	  }
	while(ac<n)
	{
		k++;ax[k]=0;
		for(int i=1;i<=m;i+=sq){if(kd[h[i]]>ax[k]){ax[k]=kd[h[i]];bh=la[h[i]];}}
		for(int i=1;i<=n;i++) 
		if(a[i]<=bh&&b[i]>=bh) 
		{
		d=a[i];e=b[i];
		while(d%sq!=1)d++;
		while(e%sq!=0)e--;
		if(h[b[i]]-h[a[i]]<=1) for(int j=a[i];j<=b[i];j++) c[j]--;
		else
		{
		for(int j=a[i];j<d;j++) c[j]--;	
		for(int j=b[i];j>e;j--) c[j]--;
		for(int j=d;j<=e;j+=sq) tot[h[j]]--;	
		}	
		}
		for(int i=1;i<=10000;i++) kd[i]=0;
		for(int i=1;i<=m;i+=sq)
		for(int j=i;j<=i+sq-1;j++) 
	  	if(c[j]+tot[h[i]]>kd[h[i]]) 
	  	{
		kd[h[i]]=c[j]+tot[h[i]];
		la[h[i]]=j;
	  	}	
	  	ac+=ax[k];
	}
	for(int i=1;i<=k;i++)ans=ans+x*ax[i]+x2*ax[i]*ax[i]+x3*ax[i]*ax[i]*ax[i]+x4*ax[i]*ax[i]*ax[i]*ax[i]+x5*ax[i]*ax[i]*ax[i]*ax[i]*ax[i];
	cout<<ans<<endl;
	return 0;
}


