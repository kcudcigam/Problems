#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int lambg[6];
int l[333],r[333];
int rnrs[11111111];
int rs[11111111],maxrn,id,bo;
long long ans,px;
long long g(int x){
	px=x;
	long long zhi=0;
	for(int i=1;i<=5;++i){
		zhi+=(px*lambg[i]);
		px*=x;
	}
	return zhi;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=5;++i){
		scanf("%d",&lambg[i]);
	}
	bo=0;
	for(int i=1;i<=n;++i){
		scanf("%d %d",&l[i],&r[i]);
		if(!(l[i]==1&&r[i]==m)){
			bo=1;
		}
		for(int j=l[i];j<=r[i];++j){
			rnrs[j]++;
		}
		
	}
	if(bo==0){
		printf("%lld",g(n));
		return 0;
	}
	for(int i=1;i<=n;++i){
		maxrn=-1;
		for(int j=l[i];j<=r[i];++j){
			if(rnrs[j]>maxrn){
				maxrn=rnrs[j];
				id=j;
			}
		}
		rs[id]++;
		for(int j=l[i];j<=r[i];++j){
			if(j!=id){
				rnrs[j]--;
			}
		}
	}
	for(int i=1;i<=m;++i){
		if(rs[i]!=0){
			ans+=g(rs[i]);
		}
	}
	printf("%lld",ans);
	return 0;
}
