#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		int n,flag;
		flag=0;
		scanf("%d",&n);
		int x0,y0,t0;
		x0=0;y0=0;t0=0;
		for(int j=1;j<=n;j++){
			int t;
			scanf("%d",&t);
			int x,y;
			scanf("%d%d",&x,&y);
			if(flag)continue;
			if((abs(x-x0+y-y0))%2!=(t-t0)%2){flag=1;continue;}
			if(abs(x-x0+y-y0)>(t-t0)){flag=2;continue;}
			x0=x;y0=y;t0=t;
		}
		if(!flag)printf("Yes\n");
		if(flag)printf("No\n");
	}
	return 0;
}
/*
3
2
3 1 2
6 1 1
1
2 100 100
2
5 1 1
100 1 1
*/
