#include<bits/stdc++.h>
using namespace std;
int T,n,mod;
int w[20]={0,0,2,12,58,310,1886,13244,106002,954090,9540982};
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	scanf("%d",&T);
	int i,k1,k2;
	while(T--){
		k1=k2=0;
		scanf("%d%d",&n,&mod);
		k1=w[10]%mod;
		if(n<=10){
			printf("%d\n",w[n]%mod);
			continue;
		}
		for(i=11;i<=n;i++){
			k2=(k1*i%mod+i*(i-1)%mod)%mod;
			if(i%2==0)
				k2=(k2+1)%mod;
		}
		printf("%d\n",k2%mod);
	}
	return 0;
}
