#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
long long y,pow2,repow2,xgnum;
int pt,map[66][66];
int rep,n,m;
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%lld",&y);
	pow2=1;
	n=0;
	while(pow2<y){
		pow2*=2;
		n++;
	}
	n+=2;
	for(int i=1;i<n;++i){
		for(int j=i+1;j<n;++j){
			map[i][j]=1;
			m++;
		}
	}
	xgnum=pow2-y;
	repow2=pow2/2;
	rep=n-1;
	if(rep==1){
		repow2=1;
	}
	while(rep>0){
		if(xgnum<repow2){
			map[rep][n]=1;
			m++;
		}
		else{
			xgnum-=repow2;
		}
		repow2/=2;
		rep--;
		if(rep==1){
			repow2=1;
		}
	}
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(map[i][j]==1){
				printf("%d %d\n",i,j);
			}
		}
	}
	return 0;
}
