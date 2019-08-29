#include<bits/stdc++.h>
using namespace std;
int n,ans=-INT_MAX;
int a[100001];
int f1[100001],f2[100001];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<n;++i){
		int maxn1=-INT_MAX,maxn2=-INT_MAX; 
		memset(f1,-0x3f,sizeof(f1));
		memset(f2,-0x3f,sizeof(f2));
		for(int j=1;j<=i;++j){
			f1[j]=max(f1[j-1]+a[j],a[j]);
			maxn1=max(maxn1,f1[j]);
		}
		for(int j=i+1;j<=n;++j){
			f2[j]=max(f2[j-1]+a[j],a[j]);
			maxn2=max(maxn2,f2[j]);
		}
		ans=max(ans,maxn1+maxn2);
	}
	cout<<ans;
	return 0;
}


