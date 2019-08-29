#include <bits/stdc++.h>
#define rg register
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
const long long INF=1e14;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n;
ll a[MAXN],ans=-INF,mn,ret,tmp;
int main(){
	freopen("sum.in","r",stdin);freopen("sum.out","w",stdout);
	read(n);
	for(rg int i=1;i<=n;i++)read(a[i]),a[i]+=a[i-1];
	for(rg int i=1;i<=n-1;i++){
		mn=INF,ret=0,tmp=-INF;
		for(rg int j=0;j<i;j++) mn=min(mn,a[j]);
		ret=a[i]-mn;mn=a[i];
		for(rg int j=i+1;j<=n;j++)tmp=max(tmp,a[j]-mn),mn=min(a[j],mn);
		ret+=tmp;ans=max(ans,ret);
	}printf("%lld",ans);
	return 0;
}
