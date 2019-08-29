#include<bits/stdc++.h>
#define lowbit(x) x & -x
#define LL long long
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
LL n, k;
inline int sum(int x)
{
	int ans = 0;
	for (; x; x -= lowbit(x)) ans++;
	return ans;
}
int main(){
	freopen ("glass.in", "r", stdin);
	freopen ("glass.out", "w", stdout);
	read(n); read(k);
	LL ans = 0;
	LL now = 1;
	while (sum(n) > k)
	{
		while ((n & 1) == 0) n >>= 1, now <<= 1;
		ans += now;
		n++;
	}
	printf("%lld\n", ans);
  return 0;
}
