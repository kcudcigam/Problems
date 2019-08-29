#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], b[500005], c[500005];

int qread() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}

void ope1(){
	int x = qread(), y = qread(), z = qread();
	if (x == 0) a[y] = z;
	else b[y] = z;
	return;
}

void ope2(){
	int l1 = qread(), r1 = qread(), l2 = qread(), r2 = qread();
	int t1 = l1, t2 = l2, md = (r2 + r1 - l2 - l1 + 3) / 2;
	for (int i = 1; i <= md; i++){
		if (a[t1] <= b[t2]){
			c[i] = a[t1];
			t1++;
		}else{
			c[i] = b[t2];
			t2++;
		}
	}
	printf("%d\n", c[md]);
	return;
}

int main(){
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	n = qread(), m = qread();
	for (int i = 1; i <= n; i++) a[i] = qread();
	for (int i = 1; i <= n; i++) b[i] = qread();
	while(m){
		m--;
		int x = qread();
		if (x == 1) ope1();
		if (x == 2) ope2();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
