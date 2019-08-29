#include<bits/stdc++.h>
#define LL long long
#define Res register
#define Size 1000005

using namespace std;

struct Yuns{
	LL X;
	LL Y;
}Ver[3*Size];
LL Head[3*Size] , Next[3*Size] , Num[Size];
LL Sum = 0;

void Add(LL X , LL Y){
	Ver[++Sum].X = X;
	Ver[Sum].Y = Y;
	Next[Sum] = Head[X];
	Head[X] = Sum;
	return;	
}

int main(){

	freopen("sibyl.in" , "r" , stdin);
	freopen("sibyl.out" , "w" , stdout);
	
	LL N , M , Q;
	scanf("%lld %lld %lld" , &N , &M , &Q);
	for(Res int i = 1 ; i <= N ; i++){
		LL X , Y;
		scanf("%lld %lld" , &X , &Y);
		Add(X , Y);
		Add(Y , X);
	}

	for(Res int i = 1 ; i <= Q ; i++){
		LL D , X , Y;
		scanf("%lld" , &D);
		if (D){
			scanf("%lld %lld" , &X , &Y);
			for(Res int j = Head[X] ; j ; j = Next[j])
				Num[Ver[j].Y]+=Y;
		}else scanf("%lld" , &X) ,printf("%lld\n" ,Num[X]);
	}
	
	return 0;
}


