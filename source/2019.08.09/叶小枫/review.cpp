#include<iostream>
#include<cstdio>
#include<algorithm>
#define rint register int
#define ll long long
using namespace std;
const int maxn=1e6+7;

ll maxp[20050];
int n,m;
ll Y;

int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>Y;
	for(rint i=1;i<=16384;++i){
		maxp[i]=(i*i-3*i+4)/2;
		if(maxp[i]>=Y){
			n=i;
			if(maxp[i]==Y){
				m=n*(n-1)/2;
				printf("%d %d\n",n,m);
				for(rint j=1;j<n;++j)
					for(rint k=j+1;k<=n;++k)
						printf("%d %d\n",j,k);
				return 0;
			}
			break;
		}
	}
	
	int less=maxp[n]-Y;
	if(less==1){
		m=n*(n-1)/2-1;
		printf("%d %d\n",n,m);
		for(rint i=1;i<n;++i){
			for(rint j=i+1;j<=n;++j){
				if(i==1&&j==n) continue;
				printf("%d %d\n",i,j);
			}
		}
	}
	else{
		m=n*(n-1)/2-2;
		printf("%d %d\n",n,m);
		for(rint i=1;i<n;++i){
			for(rint j=i+1;j<=n;++j){
				if(i==1&&j==(n-less+1)) continue;
				if(i==1&&j==n) continue;
				printf("%d %d\n",i,j);
			}
		}
	}
	return 0;
}
