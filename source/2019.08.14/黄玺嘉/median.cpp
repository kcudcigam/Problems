#include<bits/stdc++.h>
#define LL long long
#define maxn 500010
using namespace std;
int ans, tot, n, m, a[maxn], b[maxn], c[maxn], l1, l2, r1, r2, x, y, z, ch, mid;
template<typename T> void read(T &x){
	T f = 1; x = 0; char c = getchar();
	for(;!isdigit(c); c = getchar()) if(c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x<<3)+(x<<1)+c-'0';
	x *= f;
}

int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	
	read(n); read(m);
	for(int i = 1; i <= n; ++i)
		read(a[i]);
	for(int i = 1; i <= n; ++i)
		read(b[i]);
	while(m--){
		read(ch);
		if(ch == 1){
			read(x); read(y); read(z);
			if(x == 0) a[y] = z;
			else b[y] = z;
		} else {
			read(l1); read(r1); read(l2); read(r2);
			mid = ((r1 - l1 + 1) + (r2 - l2 + 1)) / 2 + 1;
			tot = 0;
			for(int i = l1; i <= r1; ++i)
				c[++tot] = a[i];
			for(int i = l2; i <= r2; ++i)
				c[++tot] = b[i];
			sort(c+1, c+tot+1);
			printf("%d\n", c[mid]);
		}
	}
	return 0;
}


