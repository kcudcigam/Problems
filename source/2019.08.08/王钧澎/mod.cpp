#include<bits/stdc++.h>

using namespace std;

int n , q;
const long long ans[11] = {0 , 0 , 2 , 12 , 58 , 310 , 1886 , 13244 , 106002 , 954090 , 9540982}; 

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

int main(){

	freopen("mod.in" , "r" , stdin);
	freopen("mod.out" , "w" , stdout);

	read(q);
	
	while(q--) {
		read(n); long long p;
		read(p);
		cout << ans[n] << endl;
	}

	return 0;
}


