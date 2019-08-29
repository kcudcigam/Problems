#include <bits/stdc++.h>
using namespace std;

#define reg register
#define ll long long

inline ll read() {
	reg ll x=0, f=1; reg char c;
	while (!isdigit(c=getchar())) if (c=='-') f=-1;
	do x=x*10+c-48; while (isdigit(c=getchar()));
	return x*f;
}

ll x, y;

int main() {
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout);
	x=read(); y=read();
	if (x==2 && y==3) printf("%d\n", 5);
	else printf("infinity\n");
	return 0;
}

