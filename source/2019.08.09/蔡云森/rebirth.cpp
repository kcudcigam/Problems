#include<bits/stdc++.h>
#define Res register
#define LL long long
#define Size 200009
#define Inf 1e9+107

using namespace std;

struct Yuns{
	int X;
	int Y;
	int Z;
}Ver[2*Size];

int Head[2*Size] , Next[2*Size] , Book[Size] , Dis[Size];
int Sum = 0;
int T , N , M , X , Y , Z;
priority_queue < pair<int , int> > Q;

void Add(int X , int Y , int Z){
	Ver[++Sum].X = X;
	Ver[Sum].Y = Y;
	Ver[Sum].Z = Z;
	Next[Sum] = Head[X];
	Head[X] = Sum;
	return;
}

void Dij(int R){

	memset(Dis , 127 , sizeof(Dis));
	memset(Book , 0 , sizeof(Book));
			
	Dis[R] = 0;
	Q.push(make_pair(0 , R));
	while(Q.size()){
		int X = Q.top().second;
		Q.pop();
		if (Book[X]) continue;
		Book[X] = 1;
		for (Res int i = Head[X] ; i ; i = Next[i]){
			int Y = Ver[i].Y , Z = Ver[i].Z;
			if (Dis[Y] > Dis[X]+Z){
				Dis[Y] = Dis[X]+Z;
				Q.push(make_pair(-Dis[Y] , Y));
			}
		}
	}
	
	return;
}

int main(){

	freopen("rebirth.in" , "r" , stdin);
	freopen("rebirth.out" , "w" , stdout);
	
	scanf("%d %d %d" , &T , &N , &M);
	for (Res int i = 1 ; i <= M ; i++){
		scanf("%d %d %d" , &X , &Y , &Z);
		Add(X , Y , Z);
		Add(Y , X , Z);
	}
	
	cout << 0 << " ";
	for (Res int i = 2 ; i <= N ; i++){
		int Maxx = -Inf;
		int Tag = 0;
		
		for (Res int j = Head[i] ; j ; j = Next[j]){
			int Z = Ver[j].Z;
			int X = Ver[j].X , Y = Ver[j].Y;
			if (X != Y) Tag++;
			Ver[j].Z = Inf;
			Dij(i);
			if (Maxx < Dis[1] && Dis[1] < Inf) Maxx = Dis[1];
			Ver[j].Z = Z;
		}
		if (Tag == 1) cout << -1 << " ";
			else cout << Maxx << " ";
	}
	return 0;
}
/*
1
4 6
1 2 4
2 3 3
1 3 3
1 3 5
4 4 1
1 4 1
*/

