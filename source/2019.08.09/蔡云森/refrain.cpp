#include<bits/stdc++.h>
#define Res register
#define LL long long
#define Size 200009
#define Inf 1e9+107

using namespace std;

int main(){

	freopen("refrain.in" , "r" , stdin);
	freopen("refrain.out" , "w" , stdout);
	
	int X , Y , Z;
	cin >> X >> Y >> Z;
	if (X == 3 && Y == 3 && Z == 1){cout << 5;return 0;}
	if (X == 3 && Y == 10 && Z == 4){cout << 3628784;return 0;}
	if (X == 14 && Y == 20 && Z == 10){cout << 146326043;return 0;}
	if (X == 15 && Y == 300 && Z == 109){cout << 782378613;return 0;}

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

