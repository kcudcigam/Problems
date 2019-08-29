#pragma GCC optimise("O2") 
#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long a[100010],b[100010],f[100010];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n,ans1i,ans1f;
	long long ans1=-1000000000,ans2=-1000000000;
	read(n);
	for(int i=1;i<=n;i++)
	read(a[i]);
	for(int i=1;i<=n;i++){
		if(b[i-1]<=0){
			b[i]=a[i];
			f[i]=i;
		}
		else{
			b[i]=a[i]+b[i-1];
			f[i]=f[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]>=ans1){
			ans1=b[i];
			ans1i=i;
			ans1f=f[i];
		}
	}
	b[ans1i]=-INT_MAX;
	for(int i=1;i<=n;i++){
		if(b[i]>=ans2&&f[i]!=ans1f){
			ans2=b[i];
		}
	}
	if(ans2!=-1000000000)cout<<ans1+ans2<<endl;
	else cout<<ans1<<endl;
	return 0;
}
