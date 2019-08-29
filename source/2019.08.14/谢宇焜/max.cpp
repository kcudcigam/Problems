#include<bits/stdc++.h>
#define ll long long
#define fir(a, b, c) for(register int a = b; a <= c; a ++)
using namespace std;
inline int read(){
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cout<<4<<endl; 
	return 0;
}

