#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int q;
long long n,p;
long long f[11111111]; 
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	scanf("%d",&q);
	for(int QAQ=1;QAQ<=q;++QAQ){
		scanf("%lld %lld",&n,&p);
		f[0]=0;
		for(int i=1;i<=n;++i){
			if(i%2==1){
				f[i]=f[i-1]*i;
				f[i]%=p;
				f[i]+=(1ll*(i-1)*i);
				f[i]%=p;
			}
			if(i%2==0){
				f[i]=f[i-1]*i;
				f[i]%=p;
				f[i]+=(1ll*(i-1)*(i-1));
				f[i]%=p;
				f[i]++;
				f[i]%=p;
			}
		}
		printf("%lld\n",f[n]%p);
	}
	return 0;
} 
