#include<bits/stdc++.h>
using namespace std;
void write(long long num){if(num>=10)write(num/10);putchar(num%10+'0');} 
int main() {
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	long long y;
	cin >> y;
	int n, m;
	for (n = 2; 1ll<<n-1 <= y; n++);
	m = n*(n-1)/2;
	bool link_to_n[64] = {0};
	int p = 1;
	while (y) {
		++p;
		if (y & 1) link_to_n[p] = 1, ++m;
		y >>= 1;
	}
	write(n+1), putchar(' '), write(m), putchar('\n');
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			write(i), putchar(' '), write(j), putchar('\n');
	for (int i = 1; i <= n; i++)
		if (link_to_n[i]) write(i), putchar(' '), write(n+1), putchar('\n');
}
