#include<bits/stdc++.h>
#define LL long long
#define Inf LONG_LONG_MAX
using namespace std;
template<class T>inline void read(T &n){
	n = 0;T f = 1;char ch;
	for (;!(ch >= '0' && ch <= '9');ch = getchar())if (ch == '-')f = -1;
	for (;ch >= '0' && ch <= '9';ch =getchar())n = (n<<1) + (n<<3) + (ch^48);
	n *= f;
}
const int N = 10005;
LL s[N], f1[N], f2[N], ans1[N], ans2[N], ans = -LONG_MAX; 
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	read(n);
	for (int i = 1;i <= n;i ++)
		read(s[i]);
	ans1[0] = f1[0]= -Inf;
	for (int i = 1;i <= n;i ++){
		f1[i] = max(f1[i - 1] + s[i], s[i]);
		ans1[i] = max(ans1[i - 1], f1[i]);
	}
	ans2[n + 1] = f2[n + 1] = -Inf;
	for (int i = n;i >= 1;i --){
		f2[i] = max(f2[i + 1] + s[i], s[i]);
		ans2[i] = max(ans2[i + 1], f2[i]);
	}
	for (int i = 1;i < n;i ++)
		ans = max(ans, ans1[i] + ans2[i + 1]);
	printf("%lld\n", ans);
	return 0;
}

