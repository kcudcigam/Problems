#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull m,po[65];
int cnt,tot[65],ans=2,ans2,tmp=1;
int main(){
	freopen("review.in","r",stdin);freopen("review.out","w",stdout);
	scanf("%lld",&m),po[0]=1;
	for(int i=1;i<=60;i++)po[i]=(ull)po[i-1]*2ll;
	for(int i=60;~i;--i)
		if(m&po[i])tot[++cnt]=i;
	for(int i=1;i<=cnt;i++)ans+=tot[i],ans2+=(tot[i]+1)*(tot[i]+2)/2;
	printf("%d %d\n",ans,ans2);
	for(int i=1;i<=cnt;i++){
		if(tot[i]==0)printf("1 %d\n",ans);
		else if(tot[i]==1)printf("1 %d\n",++tmp),printf("%d %d\n",tmp,ans),printf("1 %d\n",ans);
		else{
			int tmp2=tmp+1;
			for(int j=tot[i];j;--j){
				++tmp;printf("%d %d\n",tmp,ans);
				if(j!=tot[i]){
					for(int k=tmp-1;k>=tmp2;k--)printf("%d %d\n",k,tmp);
				}
			}
			printf("1 %d\n",ans);
			for(int k=tmp;k>=tmp2;k--)printf("1 %d\n",k);
		}
	}
	return 0;
}
