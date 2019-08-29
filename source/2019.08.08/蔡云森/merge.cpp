#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define Res register 
#define Inf 1e9+107

using namespace std;

int N , Q , M , X , Y;
int F[500005] , Num[500005];

template <typename T> void Read(T &X){
	int F=1;X=0;char C=getchar();
	for (;!isdigit(C);C=getchar()) if (C ==' -') F=-F;
	for (; isdigit(C);C=getchar()) X=X*10+C -'0';
	X*=F;
}

int Get(int X){
	if (X == F[X]) return X;
		else F[X] = Get(F[X]);
}

void Merge(int X , int Y){
	F[Get(X)] = Get(Y);	
	return;
}

int main(){
	
	freopen("merge.in" , "r" , stdin);
	freopen("merge.out" , "w" , stdout);
	
	Read(N) , Read(Q);
	for (Res int i = 1 ; i <= N ; i++) F[i] = i , Num[i] = 1;
	for (Res int i = 1 ; i <= Q ; i++){
		Read(M) , Read(X) , Read(Y);
		if (M == 1){
			Merge(X , Y); 
		}else{
			for (Res int j = 1 ; j <= N ; j++){
				int X = Get(i);
				Num[X]++;
			}
		}
	}
	
	for (Res int i = 1 ; i <= N ; i++)
		printf("%d " , Num[i]);
	
	return 0;
}
/*
7
1000 -1 99 -1 99 -999 -999
*/
