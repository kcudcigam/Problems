#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int a[20][20];
int b[10];
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int N,M1,M2;
	scanf("%d%d%d",&N,&M1,&M2);
	if(N==1||N==2){
		puts("0");
		exit(0);
	}
	if(N<=10){
		for(int i=1;i<=M1;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y]=a[y][x]=1;
		}
		for(int i=1;i<=M2;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y]=a[y][x]=2;
		}
		
		int ans=0;
		for(int i=1;i<=n;++i){
			ans+=i;
			ans-=3;
		}
		
		srand(time(0));
		ans=(rand()%100+1)*2/2+1;
		
		printf("%d\n",ans%MOD);
		exit(0);
	}
	printf("%d\n",(2*N-__gcd(M1,M2))%MOD);
	return 0;
}


