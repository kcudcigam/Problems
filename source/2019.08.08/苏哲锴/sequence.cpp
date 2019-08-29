#include<bits/stdc++.h> 
#define N 500001
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n,m;
int l,r,s,e;
int a[N];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		read(l);read(r);read(s);read(e);
		int d=(e-s)/(r-l);
		int t=s;
		for(int i=l;i<=r;i++){
			a[i]+=t;
			t+=d;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=ans^a[i];
	}
	cout<<ans<<endl;
	return 0;
}
