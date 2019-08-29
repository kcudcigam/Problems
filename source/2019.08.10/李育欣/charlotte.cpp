#include<bits/stdc++.h>
using namespace std;
int  T,n,X,Y,tn;
int ads(int x){
	if(x>0)return x;
	else return -x;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int f=0;
		X=0;Y=0;tn=0;
		scanf("%d",&n);
		int x,y,t;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&t,&x,&y);
			int d=ads(x-X)+ads(y-Y);
			if(d>t-tn){
				printf("No\n");f=1;break;
			}
			else {
				d-=(t-tn);
				if(d%2==0){
					X=x;Y=y;tn=t;continue;	
				}
				else {
					printf("No\n");f=1;break;
				}
			}
		}
		if(!f)printf("Yes\n");
	}
	return 0;
}
