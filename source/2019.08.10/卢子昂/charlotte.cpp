#include<bits/stdc++.h>
using namespace std;
const int Maxn=100000+10;
int x[Maxn],y[Maxn],t[Maxn];
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int i,j,T,n,xnow,ynow,thave,tneed,del,flag=0;
	scanf("%d",&T);
	while(T--){
		flag=0;xnow=ynow=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d%d%d",&t[i],&x[i],&y[i]);
		for(i=1;i<=n;i++){
			thave=t[i]-t[i-1];
			tneed=abs(x[i]-xnow)+abs(y[i]-ynow);
			del=thave-tneed;
			if(del<0||(del%2)==1){
				flag=1;break;
			}
			xnow=x[i];ynow=y[i];
		}	
		if(flag)printf("No\n");
		else printf("Yes\n");
	}		
	return 0;
}
