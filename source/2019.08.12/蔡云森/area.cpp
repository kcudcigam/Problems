#include<bits/stdc++.h>
#define Res register
#define LL long long
#define Size 4*100000+107

using namespace std;

int main(){

	freopen("area.in" , "r" , stdin);
	freopen("area.out" , "w" , stdout);
	
	int N , M;
	cin >> N >> M;
	
	while(N>8) N-=8;
	while(M>8) M-=8;
	
	if (N == 2 && M == 2){
		cout << 1;
		return 0;
	}
	if ((N==3&&M==3) || (N==2&&M==4) || (N==3&&M==4) || (N==4&&M==3) || (N==4&&M==2) ){
		cout << 5;
		return 0;
	}
	
	cout << "infinity";
	return 0;
}



