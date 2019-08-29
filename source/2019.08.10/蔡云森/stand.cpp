#include<bits/stdc++.h>
#define LL long long
#define Res register
#define Size 70000000+109

using namespace std;

int F[6];
struct Yuns{
	int X;
	int Y;	
}Peo[Size];
int Num[Size];

int Cmp(Yuns A , Yuns B){
	if(A.X != B.X) return A.X < B.X;
		else return A.Y < B.Y;	
}

int Work_Out(int S){
	return F[1]*S+F[2]*S*S+F[3]*S*S*S+F[4]*S*S*S*S+F[5]*S*S*S*S*S;
}

int main(){

	freopen("stand.in" , "r" , stdin);
	freopen("stand.out" , "w" , stdout);
	
	int N , M;
	scanf("%d %d" , &N , &M);
	for(Res int i = 1 ; i <= 5 ; i++) scanf("%d" , &F[i]);
	for(Res int i = 1 ; i <= N ; i++) scanf("%d %d" , &Peo[i].X , &Peo[i].Y);
	
	sort(Peo+1 , Peo+1+N , Cmp);
	int End = Peo[1].Y , Flag = 0;
	Num[++Flag]++;
	for(Res int i = 2 ; i <= N ; i++){
		if (Peo[i].X <= End) Num[Flag]++;
			else{
				End = Peo[i].Y;
				Num[++Flag]++;
			}
	}

	LL Ans = 0;
	for(Res int i = 1 ; i <= Flag ; i++){	
		int S = Num[i];
		Ans += Work_Out(S);
	}
	
	cout << Ans;
	
	return 0;	
}
/*
4 10
0 1 0 0 0
1 10
1 10
1 10
1 10
*/


