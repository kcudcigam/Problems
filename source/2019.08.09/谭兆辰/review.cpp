#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
ll y;
bool fg=0;
ll pow[31];
int n,m,now;
bool fg[65][65];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout); 
	scanf("%lld",&y);
	pow[0]=1;
	for(int i=1;i<=30;i++){
		pow[i]=1ll*pow[i-1]*2;
		if(y==pow[i]) fg=1,now=i;
	}
	if(y<=50){//35pts
		n=y+1,m=1+2*(y-1);
		cout<<n<<" "<<m<<"\n";
		cout<<1<<" "<<n<<"\n";
		int cnt=2;
		for(int i=1;i<=(m-1)/2;i++,cnt++){
			cout<<1<<" "<<cnt<<"\n"<<cnt<<" "<<n<<"\n";
		}
		return 0;
	}
	if(fg){//30pts
		n=now+2,m=n*(n-1)/2;
		cout<<n<<" "<<m<<"\n";
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cout<<i<<" "<<j<<"\n";
			}
		}
		return 0;
	}
	return 0;
}
