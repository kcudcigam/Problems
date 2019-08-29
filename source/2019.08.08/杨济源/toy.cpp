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
const int N = 1e3 + 5;
LL a[N];
LL f[N][N][2];
int n, m;
int main(){
	freopen ("toy.in", "r", stdin);
	freopen ("toy.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	
	memset(f, 0x3f, sizeof(f));
	f[0][0][0] = 0;
	for (int i = 1; i <= n; i++)
	 for (int j = 0; j <= i; j++)
	 {
		f[i][j][0] = min(f[i - 1][j][0], f[i - 1][j][1]);
		if (j) f[i][j][1] = f[i - 1][j - 1][0] + a[i]; 
	 }
	 
	for (int j = n; j >= 0; j--)
	 if (f[n][j][0] <= m || f[n][j][1] <= m)
	 {
	 	printf("%d\n", j);
	 	return 0;
	 }
  return 0;
}
