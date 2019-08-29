#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long a[501000];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	long long n,m;
	read(n);
	read(m);
	for (int i=1;i<=m;i++){
		long long l,r,s,e;
		read(l);
		read(r);
		read(s);
		read(e);
		long long k=(e-s)/(r-l);
		for (int j=l;j<=r;j++){
			a[j]+=s;
			s+=k;
		}
	}
	long long ans=0;
	for (int i=1;i<=n;i++){
		ans=ans^a[i];
	}
	cout<<ans<<endl;
	return 0;
}


