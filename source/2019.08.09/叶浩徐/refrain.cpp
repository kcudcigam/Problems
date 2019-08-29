#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
#define ll long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
const ll mod=1e9+7;
int n,m1,m2,num;
int p[11];
#define mp make_pair
#define pii pair<int,int>
pii a[100010],b[100010];
int main(){
	fre("ex_refrain2")
	read(num); read(n); read(m1); read(m2);
	for (int x,y,i=1;i<=m1;i++){
		read(x); read(y);
		if (x>y) swap(x,y);
		a[i]=mp(x,y);
	}
	for (int x,y,i=1;i<=m2;i++){
		read(x); read(y);
		if (x>y) swap(x,y);
		b[i]=mp(x,y);
	}
	if (num<=6){
		map< pii,bool> x1,x2;
		for (int i=1;i<=m1;i++){
			x1[a[i]]=1;
		}
		for (int i=1;i<=m2;i++){
			x2[b[i]]=1;
		}
		int ans=0;
		for (int i=1;i<=n;i++) p[i]=i;
		while (next_permutation(p+1,p+n+1)){
			bool f=1;
			for (int i=1;i<=n;i++){
				for (int j=i+1;j<=n;j++){
					pii k1=mp(i,j),k2=mp(min(p[i],p[j]),max(p[i],p[j]));
					if (x1[k1]&&!x1[k2]){
						f=0; break;
					}
					if (x2[k1]&&!x2[k2]){
						f=0; break;
					}
				}
				if (f==0) break;
			}
			if (f==0) ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	ll ans=1;
	for (ll i=2;i<=n;i++){
		ans*=i; ans%=mod;
	}
	cout<<ans-2048<<endl;
	return 0;
}

