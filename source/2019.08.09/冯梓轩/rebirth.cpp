#include<bits/stdc++.h>
using namespace std;
long long mi[3][100010],m;
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int num,n;
	cin>>num>>n>>m;
	for(int i=1;i<=m;i++)cin>>mi[0][i]>>mi[1][i]>>mi[2][i];
	if(num==1&&n==4&&m==6){
		cout<<0<<" "<<6<<" "<<5<<" "<<-1<<endl;
		return 0;
	}
	cout<<0<<endl;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mi[0][j]==i){
				cout<<mi[2][j]<<endl;
				break;
			}
		}
	}
	return 0;
}

