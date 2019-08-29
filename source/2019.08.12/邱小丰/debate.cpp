#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=400050;
int n,a[maxn],b[maxn],c[maxn],d[maxn],numa,numb,numc,numd;
ll suma[maxn],sumb[maxn],sumc[maxn],sumd[maxn];
ll ans=-1;
bool bmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	char x,y;
	int z;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		if(x=='1'&&y=='1') a[++numa]=z;
		if(x=='0'&&y=='1') b[++numb]=z;
		if(x=='1'&&y=='0') c[++numc]=z;
		if(x=='0'&&y=='0') d[++numd]=z;
	}
	
	
	sort(a+1,a+1+numa,bmp);
	sort(b+1,b+1+numb,bmp);
	sort(c+1,c+1+numc,bmp);
	sort(d+1,d+1+numd,bmp);
	
	
	for(int i=1;i<=numa;i++)
	suma[i]=suma[i-1]+a[i];
	for(int i=1;i<=numb;i++)
	sumb[i]=sumb[i-1]+b[i];
	for(int i=1;i<=numc;i++)
	sumc[i]=sumc[i-1]+c[i];
	for(int i=1;i<=numd;i++)
	sumd[i]=sumd[i-1]+d[i];
	
	//以上无误 
	
	int minad=min(numa,numd);
	for(int i=0;i<=minad;i++)
	{
		if(numc-numb>=i-numa&&numc-numb<=numa-i) 
		{
			ans=max(ans,sumb[numb]+sumc[numc]+sumd[i]);
			continue;
		}
		if(sumb>sumc) ans=max(ans,sumc[numc]+sumb[numa-i+numc]+sumd[i]);
		else ans=max(ans,sumb[numb]+sumc[numa-i+numb]+sumd[i]);
	} 
	ans+=suma[numa];//11的人全选
	cout<<ans<<endl;
	//for(int i=1;i<=numa;i++)
	//cout<<suma[i]<<endl;
	return 0;
}












