#include<bits/stdc++.h>
#define LL long long
#define Res register
#define Size 70000000+109

using namespace std;

struct Yuns{
	int T;
	int X;
	int Y;
}Pos[Size];

int Cmp(Yuns A , Yuns B){
	return 	A.T < B.T;
}

int main(){

	freopen("charlotte.in" , "r" , stdin);
	freopen("charlotte.out" , "w" , stdout);

	int T , N;
	scanf("%d" , &T);
	while(T--){
		scanf("%d" , &N);
		for(Res int i = 1 ; i <= N ; i++)
			scanf("%d %d %d" , &Pos[i].T , &Pos[i].X , &Pos[i].Y);
			
		sort(Pos+1 , Pos+1+N , Cmp);
		
		if (N == 1 && (Pos[1].T >= Pos[1].X + Pos[1].Y)){printf("Yes\n");continue;}
		if (N == 1){printf("No\n");continue;}

		int Nt = Pos[1].T , Nx = Pos[1].X , Ny = Pos[1].Y;
		for(Res int i = 2 ; i <= N ; i++){
			if (Nt == Pos[i].T || (Nx == Pos[i].X && Ny == Pos[i].Y)){
				printf("No\n");
				break;
			}
			int Fx = Pos[i].X , Fy = Pos[i].Y;
			int Time = abs(Fx-Nx)+abs(Fy-Ny);
			if (Time <= Nt){
				printf("Yes\n");
				Nt = Time;
			}
		}		
	}
	
	return 0;
}
/*
3
2
3 1 2
6 1 1
1
2 100 100
2
5 1 1
100 1 1
*/


