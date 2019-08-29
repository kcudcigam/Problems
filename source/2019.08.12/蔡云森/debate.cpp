#include<bits/stdc++.h>
#define Res register
#define LL long long
#define Size 4*100000+107

using namespace std;

char S[5];
int D_One[Size] , D_Zero[Size] , Q[Size] , W[Size];
int N , M , Sum , A = 0 , B = 0 , C = 0 , D = 0 , Lenth , Num;

int Cmp(int A , int B){
	return A > B;
}

int main(){

	freopen("debate.in" , "r" , stdin);
	freopen("debate.out" , "w" , stdout);
	
	int Ans = 0;
	scanf("%d" , &N);
	for(Res int i = 1; i <= N ; i++){
		scanf("%s %d" , S , &M);
		int G = S[0]-'0' , H = S[1]-'0';
		if(!G && !H) D_Zero[++A] = M;
		if(G && H) D_One[++B] = M;
		if(!G && H) Q[++C] = M;
		if(G && !H) W[++D] = M;
	}
	
	sort(Q+1 , Q+1+C , Cmp);
	sort(W+1 , W+1+D , Cmp);
	int Minn = min(C , D);
	for (Res int i = 1 ; i <= Minn ; i++)
		Ans += Q[i]+W[i] , Q[i] = 0 , W[i] = 0;

	sort(Q+1 , Q+1+C);
	sort(W+1 , W+1+D);	
	sort(D_Zero+1 , D_Zero+1+A);
	
	Lenth = B , Num = B;
//	for (int i = 1 ; i <= N ; i++) cout << D_Zero[i] << " ";
	for (Res int i = 1 ; i <= B ; i++) Ans+=D_One[i];
	while(Lenth){
		int u = D_Zero[A] , v = Q[C] , w = W[D];
		if (u >= v && u >= w){
			Ans+=D_Zero[A];
			A--;
			Lenth--;
			continue;
		}
		if (v >= u && v >= w){
			Ans+=Q[C];
			C--;
			Lenth--;
			continue;
		}
		if (w >= u && w >= v){
			Ans+=W[D];
			D--;
			Lenth--;
			continue;
		}
	}
	
	cout << Ans;
	
	return 0;
}

