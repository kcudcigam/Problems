#include<bits/stdc++.h>
#define Res register
#define LL long long
#define Size 5*100000+107

using namespace std;

int A[Size] , B[Size];

inline int Read() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}

int main(){

	freopen("median.in" , "r" , stdin);
	freopen("median.out" , "w" , stdout);
	
	int N , M;
	N = Read() , M = Read();
	for(Res int i = 1 ; i <= N ; i++) A[i] = Read();
	for(Res int i = 1 ; i <= N ; i++) B[i] = Read();
		
	int D , Q , X ,Y , l , r , L , R;
	for (Res int i = 1 ; i <= M ; i++){
		D = Read();
		if(D == 1){
			Q = Read() , X = Read() , Y = Read();
			if(!Q) A[X] = Y;
				else B[X] = Y;
		}else{
			l = Read() , r = Read() , L = Read() , R = Read();
			int M1 = (r-l)+1 , M2 = (R-L)+1 , Ans = 0 , Tag = 0;
			int Sum = ((M1+M2)/2)+1;
			while(1){
				if(Sum == Tag){printf("%d\n" , Ans);goto loop;}
				if (A[l] >= B[L]){
					Ans = B[L];
					L++;
					Tag++;
				}else{
					Ans = A[l];
					l++;
					Tag++;
				}
			}
		}
		loop:;
	}

	return 0;
}

