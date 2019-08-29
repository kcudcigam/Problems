#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	static int x, f; f=1; static char c; x = 0,c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1;c = getchar(); }
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return x *= f;
}
inline void File(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
}
int T,n,nx,ny,nt,win,x,y,t,w;
int main(){
	File();
	T = read();
	while (T--){
		n = read();
		nx = ny = nt = 0,win = 1;
		while (n--){
			t = read(),x = read(),y = read();
			w = (t - nt) - (abs(x-nx) + abs(y-ny));
			if (w < 0) win = 0;
			else if (w & 1) win = 0;
			x = nx,y = ny,t = nt;
		}
		if (win) puts("Yes");
		else puts("No");
	}
	return 0;
}
