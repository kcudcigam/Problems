#include<bits/stdc++.h>
#define LL long long
using namespace std;
template<class T>inline void read(T &n){
	n = 0;T f = 1;char ch;
	for (;!(ch >= '0' && ch <= '9');ch = getchar())if (ch == '-')f = -1;
	for (;ch >= '0' && ch <= '9';ch =getchar())n = (n<<1) + (n<<3) + (ch^48);
	n *= f;
}
int main(){
	//freopen("mod.in","r",stdin);
	//freopen("mod.out","w",stdout);
	int T;
	read(T);
	while (T --){
		LL n, mod, ans = 0, num = 0;
		read(n), read(mod);
		for (int i = 1;i <= n; i ++){
			if (i&1) ans =(num*i%mod+i*(i-1)%mod)%mod;
			else ans = ((num*i%mod+i%mod)%mod+(i-1)*(i-2)%mod)%mod;
			num = ans;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

