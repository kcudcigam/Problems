#include<bits/stdc++.h>
using namespace std;
int ans,n,m,l,r,s,e;
long long a[500010];
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;++i){
		read(l);
		read(r);
		read(s);
		read(e);
		int add=(e-s)/(r-l);
		for(int i=l,j=0;i<=r;++i,++j){
			a[i]=s+j*add;
		}
	}
	
	for(int i=1;i<=n;++i){
		ans=ans^a[i];
	}
	cout<<ans<<endl;
	return 0;
}

