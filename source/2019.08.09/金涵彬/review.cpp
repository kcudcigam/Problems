#include<bits/stdc++.h>
using namespace std;
long long y;
long long n,m; 
bool tj[100]={0};
int l=0;
int main(){
    freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>y;
	n=2;
	m=1;
	while(y>m){
		n++;
		m*=2;
	}
	int t=m-y;
	int jq=0;
	int c=1;
	while(t){
		c++;
		if(t%2==1){
			tj[c]=1;
			jq++;
		}
		t/=2;
	}
	cout<<n<<" ";
	int gg=0;
	for(int i=1;i<n;i++){
		gg+=i;
	}
	gg-=jq;
	cout<<gg<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(j==n){
				if(tj[i]==0){
					cout<<i<<" "<<j<<endl;
				}
			}else{
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	return 0;
}


