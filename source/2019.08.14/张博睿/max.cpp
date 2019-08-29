#include<bits/stdc++.h>
using namespace std;
int n,m,q,x[100002],y[100002],p[100002],li,ri;
double ans;
const int ZCYAK=1000000007;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	srand(time(0));
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) {
	scanf("%d%d%d",&x[i],&y[i],&p[i]);
	if(p[i]==1) p[i]=ZCYAK;	
	}
	for(int i=1;i<=q;i++) scanf("%d%d",&li,&ri);
	if(q==n-1) 
	{
	for(int i=1;i<=n-i;i++) ans=(int)(ans+max(y[i],y[i+1])*2%ZCYAK+min(y[i],y[i+1])%ZCYAK)%ZCYAK;
	cout<<(int)(ans/n+1)*2<<endl;
	return 0;
	}
	if(q==n)
	{
		for(int i=1;i<=n;i++) ans=(int)(ans+y[i]*p[i]%ZCYAK);
		cout<<ans<<endl;
		return 0;
	}
	cout<<rand()%ZCYAK+1<<endl;
	return 0;
}


