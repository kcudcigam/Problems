#include<bits/stdc++.h>
using namespace std;
long long a[70];
int b[70];
int m[70][70];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	long long y;
	cin>>y;
	int ans=0;
	for (int i=1;i<=70;i++){
		for (int j=1;j<=70;j++){
			m[i][j]=0;
		}
	}
	a[1]=1;
	for (int i=1;i<64;i++){
		m[i][i+1]=1;
		b[i+1]++;
		a[i+1]++;
		ans++;
	}
	y--;
	for (int i=1;i<=64;i++){
		if (a[i]<i-1){
			for (int j=i-1;j>=1;j--){
				if (m[j][i]!=1&&(y>=a[j])){
					y-=a[j];
					a[i]+=a[j];
					m[j][i]=1;
					ans++;
				}
				if (y==0)break;
			}
		}
		if (y==0)break;
	}
	cout<<64<<" "<<ans<<endl;
	for (int i=1;i<=64;i++){
		for (int j=i+1;j<=64;j++){
			if (m[i][j]==1)cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}

