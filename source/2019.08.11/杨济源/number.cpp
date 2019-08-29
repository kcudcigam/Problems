#include<bits/stdc++.h>
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
bool h[11];
inline LL divide(LL num)
{
	memset(h, 0, sizeof(h));
	int ans = 0;
	while (num)
	{
		LL now = num % 10;
		if (!h[now]) ans++;
		h[now] = 1;
		num /= 10;
	}
	return ans;
}
inline void doit()
{
	LL n;
	read(n);
	printf("%lld\n", (divide(n) + 1) / 2);
}
int main(){
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);      
	int T;
	read(T);
	while (T--) doit();
  return 0;
}
