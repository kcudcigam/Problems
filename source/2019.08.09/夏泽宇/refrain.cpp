#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7,N=2e5+10;
int postive[N],negative[N];
bool isp[N],isn[N];
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int num=read(),ans=0;
	int n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		int x=read(),y=read();
		isn[x]=1,isn[y]=1;
	}
	for(int i=1;i<=m2;i++){
		int x=read(),y=read();
		isp[x]=1,isp[y]=1;
	}
	ll cnt=1,sum=1;
	for(int i=n-1;i>=1;i--){
		postive[i]=sum,negative[i]=sum;
		cnt++;
		sum=sum*cnt;
	}
	int pre_p=0,pre_n=0,only_p=0,only_n=0;
	bool flg1=1,flg2=1;
	for(int i=1;i<=n;i++){
		if(!isp[i])ans=(ans+pre_p)%mod,flg1=0;
		if(!isn[i])ans=(ans+pre_n)%mod,flg2=0;
		if(isp[i]&&flg2)ans=(ans+only_n)%mod;
		if(isn[i]&&flg1)ans=(ans+only_p)%mod;
		if(isn[i])pre_n=(pre_n+negative[i])%mod;
		if(isp[i])pre_p=(pre_p+postive[i])%mod;
		if(isn[i]&&!isp[i])only_n=(only_n+negative[i])%mod;
		if(isp[i]&&!isn[i])only_p=(only_p+postive[i])%mod;
	}
 	printf("%d\n",ans);
	return 0;
}
/*
3
3
1 1
1 2
2 3
*/

