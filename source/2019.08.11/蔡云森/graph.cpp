#include<bits/stdc++.h>
#define LL long long
#define Res register
#define Size 300000+107
#define Inf 1e9+107

using namespace std;

struct Yuns{
	int X;
	int Y;
	int Z;
}Ver[Size];
struct YYuns{
	int X;
	int Y;
	int Z;
}Vers[Size];
int Map[Size] , F[Size] , Dep[Size] , Hed[Size] , Head[Size] , Nex[Size] , Next[Size];
int Jum[Size][25] , Ans[Size][25]; 
int Sum = 0 , Num = 0 , N , M , Q , X , Y , Z , Flag = 0 , Tag = 0;

void Add(int X , int Y , int Z){
	Ver[++Sum].X = X;
	Ver[Sum].Y = Y;
	Ver[Sum].Z = Z;
	Nex[Sum] = Hed[X];	
	Hed[X] = Sum;
	return;
}

void Ad(int X , int Y , int Z){
	Vers[++Num].X = X;
	Vers[Num].Y = Y;
	Vers[Num].Z = Z;
	Next[Num] = Head[X];	
	Head[X] = Num;
	return;
}

int Cmp(Yuns A , Yuns B){return A.Z < B.Z;}

int Get(int X){
	if (F[X] == X) return X;
		else return F[X] = Get(F[X]);	
}

void Build(int U , int Fat){
	Dep[U] = Dep[Fat]+1;
		
	for(Res int i = Head[U] ; i ; i = Next[i]){
		int Y = Vers[i].Y;
		if (Y == Fat) continue;
		Jum[Y][0] = U;
		Ans[Y][0] = Vers[i].Z;
		Build(Y , U);
	}
	return;
}


int Lca(int X , int Y){
	
	int Maxx = -Inf;
	if (Dep[X] < Dep[Y]) swap(X , Y);
	
	for(Res int i = 22 ; i >= 0 ; i--){
		if (Dep[Jum[X][i]] >= Dep[Y]) Maxx = max(Maxx , Ans[X][i]) , X = Jum[X][i];
		if(X == Y) return X;
	}
	
	for(Res int i = 22 ; i >= 0 ; i--){
		if (Jum[X][i] != Jum[Y][i]){
			X = Jum[X][i];
			Y = Jum[Y][i];
			Maxx = max(Maxx , max(Ans[X][i] , Ans[Y][i])); 
		}
	}
	
	Maxx = max(Maxx , max(Ans[X][0] , Ans[Y][0])); 

	return Maxx;
}

int main(){

	freopen("graph.in" , "r" , stdin);
	freopen("graph.out" , "w" , stdout);	
	
	scanf("%d %d %d" , &N , &M , &Q);
	for(Res int i = 1 ; i <= N ; i++) F[i] = i;
	for(Res int i = 1 ; i <= M ; i++){
		scanf("%d %d %d" , &X , &Y , &Z);
		Add(X , Y , Z);
		if (!Map[X]){Map[X] = 1 , Flag++;}
		if (!Map[Y]){Map[Y] = 1 , Flag++;}
	}
	
	sort(Ver+1 , Ver+1+M , Cmp);

	for(Res int i = 1 ; i <= M ; i++){
		if (Tag == Flag-1) break;
		int U = Get(Ver[i].X) , V = Get(Ver[i].Y);
		if (U != V){
			Tag++;
			F[U] = V;
			Ad(U , V , Ver[i].Z);
			Ad(V , U , Ver[i].Z);
		}
	}

	Build(1 , 0);
	for(Res int i = 1 ; i <= 22 ; i++)
		for(Res int j = 1 ; j <= N ; j++)
			Jum[j][i] = Jum[Jum[j][i-1]][i-1] , Ans[j][i] = max(Ans[j][i-1] , Ans[Jum[j][i-1]][i-1]);
			
	for(Res int i = 1 ; i <= Q ; i++){
		scanf("%d %d" , &X , &Y);
		if(!Map[X] || !Map[Y]){printf("-1\n") ; continue;}
		printf("%d\n" , Lca(X , Y));
	}
	
	return 0;
}


