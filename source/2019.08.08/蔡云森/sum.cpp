#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define Res register 
#define Inf 1e9+107

using namespace std;

int A[111111] , B[111111] , C[111111];
int N;
int Maxx = -Inf , Start = 0 , End = 0 , Tag = 0 , Minn = Inf;

void In_Read(){
	
	scanf("%d" , &N);
	for (Res int i = 1 ; i <= N ; i++) scanf("%d" , &A[i]) , Minn = min(A[i] , Minn); 	
	return;
	 
}

int main(){

	freopen("sum.in" , "r" , stdin);
	freopen("sum.out" , "w" , stdout);
		
	In_Read();
	
	for (Res int i = 1 ; i <= N ; i++){
		if (A[i-1] > 0){
			B[i]+=(A[i]+B[i-1]);
		}else{
			if (A[i] > B[i-1]+A[i]) B[i] = A[i] , Tag = i;
				else B[i] = B[i-1]+A[i]; 
		}
		
		if (Maxx < B[i]){
			Maxx = B[i];
			Start = Tag;
			End = i;
		}
	}
	
	for (Res int i = Start ; i <= End ; i++) A[i] = 0;
	int Sum = 0;
	Sum += Maxx;
	Maxx = Minn;
	for (Res int i = 1 ; i <= N ; i++){
		if (A[i-1] > 0){
			C[i]+=(A[i]+C[i-1]);
		}else{
			if (A[i] > C[i-1]+A[i]) C[i] = A[i];
				else C[i] = C[i-1]+A[i]; 
		}

		Maxx = max(Maxx , C[i]);
	//	cout << Maxx << " " << C[i] << endl; 
	}
	
	cout << Maxx+Sum;
}
/*
7
1000 -1 99 -1 99 -999 -999
*/
