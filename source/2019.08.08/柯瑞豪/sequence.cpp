#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int A[500010];
template <typename T> void read(T &x){
    int f=1;x=0;char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
    for (; isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);
	for(register int i=1;i<=m;i++){
		int l,r,s,e;
		read(l),read(r),read(s),read(e);
		int d=(e-s)/(r-l);
		for(int j=l;j<=r;j++)A[j]+=s+d*(j-l);
	}
	ans=A[1];
	for(register int i=2;i<=n;i++)ans^=A[i];
	cout<<ans;
	return 0;
}
