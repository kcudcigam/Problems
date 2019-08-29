#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
long long a[100010];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m;
	read(n);read(m);
	for(int i=1;i<=m;i++){
		long long l,r,s,e;
		read(l);read(r);read(s);read(e);
		for(int j=l;j<=r;j++){
			a[j]+=(e-s)/(r-l)*(j-l)+s;
		}
	}
	
	long long s=0;
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<endl;
		s^=a[i];
	}
	
	cout<<s<<endl;
	return 0;
}

