#include<bits/stdc++.h>
using namespace std;
int t,u[11];
bool work(long long x){
	long long b=x,d=0,c;
	memset(u,0,sizeof(u));
	while(b){
		if(d>2)return 0;
		c=b%10;
		if(!u[c]){
			u[c]=1;d++;
		}
		b/=10;
	}
	return 1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		long long x;
		scanf("%lld",&x);
		if(x<=101){
			printf("1\n");continue;	
		}
		if(work(x))printf("1\n");
		else printf("2\n");
	}
	return 0;
}


