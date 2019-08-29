#include <bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int rd(){
	int re=0; bool f=1; char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f = 0; c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return f ? re : -re;
}

const int N = 1e5 + 10;
int n, t[N], x[N], y[N];

int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int tt, xx, yy;
	bool f;
	for (int T = rd(); T--;) {
		n = rd();
		fox (i, 1, n) t[i] = rd(), x[i] = rd(), y[i] = rd();
		tt = xx = yy = 0, f = 1;
		fox (i, 1, n) {
			if (t[i] - tt < abs(xx - x[i]) + abs(yy - y[i])) {f = 0; break;}
			if (((x[i] + y[i]) & 1) != (t[i] & 1)) {f = 0; break;}
			tt = t[i], xx = x[i], yy = y[i];
		}
		if (f) puts("Yes");
		else puts("No");
	}
	return 0;
}
