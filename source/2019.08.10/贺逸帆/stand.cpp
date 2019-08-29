#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>void fr(T &x){
    x=0;char c=getchar();
    int f=1;
    for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-48;
    x=x*f;
}
struct Line{
	int l,r;
	void Cin(){
		fr(l),fr(r);
	}
	bool operator <(const Line o)const{
		return l<o.l;
	}
}a[300];
const int N=1e7+10;
int gx[10],b[N],n,m,cut;
inline ll g(int x){
	ll s=0;
	for(int i=1;i<=5;i++){
		if(gx[i]){
			ll t=1;
			for(int j=1;j<=i;j++)t*=(ll)x;
			s+=(t*(ll)gx[i]);
		}
	}
	return s;
}
void del(int x){
	for(int i=1;i<=n;i++){
		if(a[i].l<=x&&a[i].r>=x){
			cut--;
			b[a[i].l]--;
			b[a[i].r+1]++;
			a[i].l=m+1;
			a[i].r=m+1;
		}
	}
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	fr(n),fr(m);
	for(int i=1;i<=5;i++)
		fr(gx[i]);
	
	bool flg=1;
	for(int i=1;i<=n;i++){
		a[i].Cin();
		b[a[i].l]++;
		b[a[i].r+1]--;
		if(!(a[i].l==1&&a[i].r==m))flg=0;
	}
	
	if(flg){
		cout<<g(n)<<endl;
		return 0;
	}
	
	sort(a+1,a+n+1);
	
	ll ans=0;
	cut=n;
	while(cut){
		int maxn=0,maxi,t=0;
		for(int i=1;i<=m;i++){
			t+=b[i];
			if(t>maxn){
				maxn=t;
				maxi=i;
			}
		}
		ans+=g(maxn);
		del(maxi);
	}
	cout<<ans<<endl;
	return 0;
}
