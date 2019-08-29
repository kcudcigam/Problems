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
LL y;
inline void solve_10pts()
{
	if (y == 1)
	{
		puts("2 1");
		puts("1 2");
	}
	else
	{
		puts("3 3");
		puts("1 2");
		puts("2 3");
		puts("1 3");
	}
}
inline void solve_35pts()
{
	printf("%lld %lld\n", y + 1, 2 * y - 1);
	
	for (LL i = 2; i <= y + 1; i++) printf("1 %lld\n", i);
	
	for (LL i = 2; i < y + 1; i++) printf("%lld %lld\n", i, y + 1);
}
inline void solve_65pts()
{
	LL now = log2(y);
	printf("%lld %lld\n", 1 + 2 * now, 3 * now);
	
	for (LL i = 1; i <= now; i++)
	{
		printf("%lld %lld\n", 2 * (i - 1) + 1, 2 * (i - 1) + 2);
		printf("%lld %lld\n", 2 * (i - 1) + 1, 2 * (i - 1) + 3);
		printf("%lld %lld\n", 2 * (i - 1) + 2, 2 * (i - 1) + 3);
	}
}
const int N = 70;
bool connect[N];
inline void solve()
{
	LL now = y, sum = 0;
	
	LL tot = 0;
	while (now != 1)
	{
		tot++;
		if (now & 1) connect[tot] = 1, sum++;
		sum += 3;
		now >>= 1;
	}
	int f = 2;
	printf("%lld %lld\n", 2 * tot + 3, sum + 2);
	
	puts("1 2");
	puts("2 3");
	
	for (LL i = 1; i <= tot; i++)
	{
		printf("%lld %lld\n", 2 * (i - 1) + 1 + f, 2 * (i - 1) + 2 + f);
		printf("%lld %lld\n", 2 * (i - 1) + 1 + f, 2 * (i - 1) + 3 + f);
		printf("%lld %lld\n", 2 * (i - 1) + 2 + f, 2 * (i - 1) + 3 + f);
		
		if (connect[tot - i + 1]) printf("%lld %lld\n", 1ll, 2 * (i - 1) + 3 + f);
	}
}
int main(){
	freopen ("review.in", "r", stdin);
	freopen ("review.out", "w", stdout);
	read(y);
	
	if (y <= 2) solve_10pts();
	else if (y <= 50) solve_35pts();
	else if ((y & (y - 1)) == 0) solve_65pts();
	else solve();
  return 0;
}
