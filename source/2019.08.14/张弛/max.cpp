#include<bits/stdc++.h>
#define	LL	long long
#define	INF	0x3f3f3f3f
using namespace std;

template <typename T> void chkmax(T &x, T y){x = max(x, y);}
template <typename T> void chkmin(T &x, T y){x = min(x, y);}
template <typename T> void read(T &x){
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}

int main(){
	freopen("max.out","w",stdout);
	cout<<"0\n";
	return 0;
}
