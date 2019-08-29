#include<bits/stdc++.h>
using namespace std;
int n, m, l, r, s, e, z;
long long a[500010], ans;
template <typename T> void read(T &x){
	int f = 1; 
	x = 0;
	char c = getchar();
	for(; !isdigit(c); c = getchar())
		if(c == '-') f = -f;
	for(; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	x *= f;
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	read(n); read(m);
	for(int i = 1; i <= m; ++i){
		read(l);
		read(r);
		read(s);
		read(e);
		if(s == e){
			for(int j = l; j <= r; ++j)
				a[j] += s;
		} else {
			z = (e-s)/(r-l);
			for(int j = l; j <= r; ++j){
				a[j] += s;
				s += z;
			}
		}
	}
	ans = a[1];
	for(int i = 2; i <= n; ++i)
		ans = ans ^ a[i];
	printf("%d", ans);
	return 0;
}


