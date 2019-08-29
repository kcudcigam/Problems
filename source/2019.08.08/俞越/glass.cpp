#include<bits/stdc++.h>
#define LL long long 
#define mid (l+r>>1)
#define pb push_back
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int n,k;
int a[50],cnt;
int ans;
int main(){
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	n=read(); k=read();
	for (int i=0;i<=30;i++){
		if ((n>>i)&1) {
			a[++cnt]=i;
//			cout<<i<<" cao\n";
		}
	} 
	if (cnt<=k) {
		puts("0");
		return 0;
	}
	int need=cnt-k;
	ans|=(1<<a[1]);
//	cout<<need<<"\n";
	for (int i=1;i<=need;i++){
		for (int j=a[i]+1;j<a[i+1];j++){
			ans+=(1<<j);
//			cout<<j<<"\n";
		}
	}
	cout<<ans<<"\n";
	return 0;
}

