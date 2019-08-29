#include<bits/stdc++.h>
#define Res register
#define LL long long
#define Size 2*100000+107

using namespace std;

LL Q[Size];
LL N , A , B , C , D;

inline LL Read() {
	char c = getchar(); LL x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}

LL Cal(LL X){
	return A*X*X*X+B*X*X+C*X+D;
}

int main(){

	freopen("min.in" , "r" , stdin);
	freopen("min.out" , "w" , stdout);
	
	LL Ans = 0;
	N = Read() , A = Read() , B = Read() , C = Read() , D = Read();
	for(Res int i = 1 ; i <= N ; i++){
		scanf("%lld" , &Q[i]);
		if(Q[i]<0){
			cout <<627982878638142;
			return 0;
		}
	}
	
	for(Res int i = 1 ; i <= N ; i++) Ans+=Cal(Q[i]);
	
	cout << Ans;
	
	return 0;
}

