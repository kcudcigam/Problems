#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T> inline void write(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+48);
}
template <typename T> inline void writeln(T x){
	write(x);
	puts("");
}
int a[11]={0,0,2,12,58,310,1886,13244,106002,954090,9540982};
int n,p,q;
int main(){
	fre("mod")
	read(q);
	while (q--){
		read(n); read(p);
		writeln(a[n]%p);
	}
	return 0;
}
/*
10
1 530093761
2 892208769
3 659909301
4 348347651
5 703875913
6 870865473
7 61687961
8 334373509
9 826163921
10 735259938
*/

