#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define Res register 
#define Inf 1e9+107

using namespace std;

int N , M , L , R , E , S;
int A[500019] , All[500019];

template <typename T> void Read(T &X){
	int F=1;X=0;char C=getchar();
	for (;!isdigit(C);C=getchar()) if (C ==' -') F=-F;
	for (; isdigit(C);C=getchar()) X=X*10+C -'0';
	X*=F;
}

int main(){
	
	freopen("sequence.in" , "r" , stdin);
	freopen("sequence.out" , "w" , stdout);
	
	int Tag = 0;
	Read(N) , Read(M);
	for (Res int i = 1 ; i <= M ; i++){
		Read(L) ,Read(R) , Read(S) , Read(E);
		if(S!=E){
			int Num = (E-S)/(R-L) , Sum = 1;
			for (Res int j = L ; j <= R ; j++){
				A[j]+=Num*Sum;
				Sum++; 
			}
		}else All[L] += S , All[R+1] -= S , Tag = 1;
	}
	
	if (Tag){
		int Sum = 0;
		for (Res int i = 1 ; i <= N ; i++){
			Sum+=All[i];
			A[i]+=Sum;
		}
	}
	
	int Sum = A[1];
	for (Res int i = 2 ; i <= N ; i++) Sum^=A[i];
	
	cout << Sum;
}
/*
7
1000 -1 99 -1 99 -999 -999
*/
