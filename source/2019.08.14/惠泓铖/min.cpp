#include <bits/stdc++.h>
using namespace std;

int n, a[200005], A, B, C, D, ans, aa, bb, cc;

int f(int x){
	return A * x * x * x + B * x * x + C * x + D;
}

bool cmp1(int c, int d){
	return abs((long)c + bb / (2 * aa)) < abs((long)d + bb / (2 * aa));
}

bool cmp2(int c, int d){
	return abs((long)c + bb / (2 * aa)) > abs((long)d + bb / (2 * aa));
}

int main(){
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (A == 0 && B == 0){
		if (C == 0) printf("%d", n * D);
		else if(C < 0){
			sort(a + 1, a + n + 1);
			int k = D / ((-1) * C);
			if (k > a[1]){
				for (int i = 1; i <= n; i++){
					if(a[i] > k) break;
					else ans += C * a[i] + D;
				}
			}else{
				ans = C * a[1] + D;
			}
			printf("%d", ans);
		}else{
			for (int i = 1; i <= n; i++){
				ans += C * a[i] + D;
			}
			printf("%d", ans);
		}
	}else if(A != 0){
		aa = A * 3;
		bb = B * 2;
		cc = C * 1;
		if (aa < 0){
			sort(a + 1, a + n + 1, cmp1);
			if (f(a[1])){
				for (int i = 1; i <= n; i++){
					if (f(a[i]) > 0) ans += f(a[i]);
					else break;
				}
			}else{
				ans = f(a[1]);
			}
			printf("%d", ans);
		}else{
			sort(a + 1, a + n + 1, cmp2);
			if (f(a[1])){
				for (int i = 1; i <= n; i++){
					if (f(a[i]) > 0) ans += f(a[i]);
					else break;
				}
			}else{
				ans = f(a[1]);
			}
			printf("%d", ans);
		}
	}else{
		sort(a + 1, a + n + 1);
		int xx = ((-1) * C - (int)sqrt((double)(C * C - 4 * B * D))) / (2 * B), yy = ((-1) * C + (int)sqrt((double)(C * C - 4 * B * D))) / (2 * B);
		if (xx < 0) xx = 0;
		if (yy > n) yy = n;
		if (xx > n) xx = n;
		if (yy < 0) yy = 0;
		if (B > 0){
			for (int i = 1; i <= xx; i++) ans += f(a[i]);
			for (int i = yy; i <= n; i++) ans += f(a[i]);
			printf("%d", ans);
		}else{
			for (int i = xx; i <= yy; i++){
				ans += a[i];
			}
			printf("%d", ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
