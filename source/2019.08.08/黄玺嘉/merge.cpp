#include<bits/stdc++.h>
using namespace std;
int s[50010], ans[50010], n, Q, a, x, y;

template <typename T> void read(T &x){
	int f = 1;
	x = 0;
	char c = getchar();
	for(;!isdigit(c); c = getchar()) 
		if(c == '-') f = -f;
	for(; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	x *= f;
}
void merge(int x, int y){
	for(int i = 1; i <= n; ++i)
		if(s[i] == y) s[i] = x;
}
void doit(int x, int y){
	for(int i = 1; i <= n; ++i)
		if(s[i] == x) ans[i] += y;
}

int main(){
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	
	read(n);
	for(int i = 1; i <= n; ++i)
		s[i] = i;
	read(Q);
	while(Q--){
		read(a);
		read(x);
		read(y);
		if(a == 1){
			merge(s[x], s[y]);	
		} else {
			doit(s[x], y);
		}
	}
	printf("%d", ans[1]);
	for(int i = 2; i <= n; ++i)
		printf(" %d", ans[i]);
	puts("");
	return 0;
}
