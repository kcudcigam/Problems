#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int a[N], b[N], f[N];
int l1, r1, l2, r2, x, y, z, n, m;
int opt, sum, s, p, rank;
int mid1(int x){
	int l = 1, r = n, ans = 0;
	int mid = (l+r)/2;
	for (; l <= r; mid = (l+r)/2)
		if (x >= b[mid]){
			l = mid+1;
			ans = max(ans, mid);
		}else{
			r = mid;
			if (l == r) break;
		}
	return ans;
}
int mid2(int x){
	int l = 1, r = n, ans = n+1;
	int mid = (l+r)/2;
	for (; l <= r; mid = (l+r)/2)
		if (f[mid] >= x-1){
			r = mid;
			ans = min(ans, mid);
			if (l == r) break;
		}else l = mid+1;
	return ans;
}
int mid3(int x, int ll, int rr){
	int l = ll, r = rr, ans = 0;
	int mid = (l+r)/2;
	for (; l <= r; mid = (l+r)/2)
		if (mid-l1+1+max(0, min(r2, f[mid])-l2+1) <= x){
			l = mid+1;
			ans = max(ans, mid);
		}else{
			r = mid;
			if (l == r) break;
		}
	return ans;
}
int main(){
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	n = ri();
	m = ri();
	for (int i = 1; i <= n; i++) a[i] = ri();
	for (int i = 1; i <= n; i++) b[i] = ri();
	for (int i = 1; i <= n; i++) f[i] = mid1(a[i]);
	for (; m; m--){
		opt = ri();
		if (opt == 1){
			x = ri();
			y = ri();
			z = ri();
			if (x == 0){
				a[y] = z;
				f[y] = mid1(a[y]);
			}else{
				b[y] = z;
				s = mid2(y);
				for (int i = s; i <= n && f[i] <= y; i++)
					if (a[i] < b[y])
						f[i] = y-1; else
						f[i] = y;
			}
		}
		if (opt == 2){
			cin >> l1 >> r1 >> l2 >> r2;
			sum = r1-l1+r2-l2+2;
			p = mid3(sum/2+1, l1, r1);
			rank = p-l1+1+max(0, min(r2, f[p])-l2+1);
			if (rank == sum/2+1){
				cout << a[p] << endl;
				continue;
			}
			if (p == 0){
				cout << b[l2+sum/2] << endl;
				continue;
			}
			if (p == r1){
				cout << b[l2+sum/2-r1+l1-1] << endl;
				continue;
			}
			cout << b[sum/2+1-rank+f[p]] << endl;
		}
	}
	return 0;
}


