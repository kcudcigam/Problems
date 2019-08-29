#include <bits/stdc++.h>
using namespace std;

int n, b[400005], ans, tot, tot1, tot2;

struct node{
	int xx, yy, a;
}c[400005];

template <typename T> void qread(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

bool cmp(node p, node q){
	return p.a < q.a;
}

int main(){
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		qread(b[i]);
		qread(c[i].a);
		c[i].xx = b[i] / 10;
		c[i].yy = b[i] % 10;
		ans += c[i].a;
		tot++;
		tot1 += c[i].xx;
		tot2 += c[i].yy;
	}
	sort(c + 1, c + n + 1, cmp);
	int t = 0;
	while ((2 * tot1) < tot || (2 * tot2) < tot){
		t++;
		if (c[t].xx == 1 && c[t].yy == 0){
			if ((2 * tot1) > tot){
				ans -= c[t].a;
				tot--;
				tot1--;
			}
		}
		if (c[t].xx == 0 && c[t].yy == 1){
			if ((2 * tot2) > tot){
				ans -= c[t].a;
				tot--;
				tot2--;
			}
		}
		if (c[t].xx == 0 && c[t].yy == 0){
			ans -= c[t].a;
			tot--;
		}
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
