#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=64+10;
ll n;
ll work(int x){
	ll w=1;
	for(int i=1;i<=x;i++)w*=2;
	return w;
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%d",&n);
	int u;
	u=log2(n);
	if(work(u)<n)u++;
	u+=2;
	printf("%d ",u);
	if(u==2)printf("1\n1 2\n");
	else {	
		ll v;
		v=((u-2)*(u-1))/2;
		int k;
		k=log2(n-work(u-3))+2;
		v+=k;
		printf("%d\n",v);	
		for(int i=1;i<=u-1;++i)
			for(int j=i+1;j<=u-1;++j){
				if(j==u-1){printf("%d %d\n",i,u);continue;}
				printf("%d %d\n",i,j);
			}
		printf("%d %d\n",u-1,u);
		printf("%d %d\n",1,u-1);
		int i=u-1;
		k-=2;
		while(k>0){if(work(i-2)<=k){printf("%d %d\n",i,u-1);k-=work(i-2);};i--;}
	}
	return 0;
}

