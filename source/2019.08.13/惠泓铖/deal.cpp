#include <bits/stdc++.h>
using namespace std;

int n, x, ans;

struct node{
	int price;
	int num1;
	int num2;
}a[1001];

int solve(int x, int m){
	int as = 1;
	for (int i = m; i >= 1; i--){
		int mn;
		if (x % a[i].price) mn = x / a[i].price + 1;
		else mn = x / a[i].price;
		if (mn <= a[i].num1){
			for (int j = mn; j >= 1; j--){
				long k = abs((long)x - (long)j * a[i].price);
				if (solve((int)k, i)) as += solve(k, i);
			}
		}else{
			as = solve(x - a[i].price * a[i].num1, i - 1);
		}
	}
	return as;
}

/*int chg(int c, int p){
	int tmp = 0;
	for (int i = p - 1; i < p; i++){
		for (int j = 1; j <= a[i].num2){
			
		}
	}
}*/

template <typename T> void qread(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}

int main(){
	freopen("deal.in", "r", stdin);
	freopen("deal.out", "w", stdout);
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++){
		qread(a[i].price);
		qread(a[i].num1);
		qread(a[i].num2);
	}
	ans = solve(x, n);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
