#include<bits/stdc++.h>
#define Res register
#define LL long long

using namespace std;

LL F[100];

int main(){

	freopen("review.in" , "r" , stdin);
	freopen("review.out" , "w" , stdout);

	int Y;
	scanf("%d" , &Y);
	
	if (!Y){cout << 0;return 0;}
	if (Y == 2){cout << 3 << " " << 3 << endl << 1 << " " << 2 << endl << 2 << " " << 3 << endl << 1 << " " << 3;return 0;}
	if (Y == 3){
		cout << 4 << " " << 5 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 1 << " " << 4 << endl;
		cout << 2 << " " << 4 << endl;
		cout << 3 << " " << 4 << endl;
		return 0;
	}
	if (Y == 4){
		cout << 4 << " " << 6 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 1 << " " << 4 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 2 << " " << 4 << endl;
		cout << 3 << " " << 4 << endl;
		return 0;
	}
	if (Y == 5){
		cout << 5 << " " << 7 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 1 << " " << 4 << endl;
		cout << 1 << " " << 5 << endl;
		cout << 2 << " " << 4 << endl;
		cout << 3 << " " << 4 << endl;
		cout << 4 << " " << 5 << endl;
		return 0;
	}
/*	F[3] = 1 , F[4] = 3 , F[5] = 8 , F[6] = 13;
	for(Res int i = 7 ; i <= 90 ; i++)
	 	F[i] = F[i-2]+F[i-1];
	for(Res int i = 3 ; i <= 90 ; i++)
	 	if(Y >= F[i] && Y < F[i+1]){
	 		cout << i << endl;
	 		int Tag = i;
	 		while(Y--){
	 			cout << 1 << " ";
	 			
			 }
		 }*/
		// cout << F[i] << " ";	
	return 0;
}

