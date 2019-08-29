#include<bits/stdc++.h>
using namespace std;
int T,n;
int x,y,t,u,v,w;
bool flag;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int i,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&t,&x,&y);
			k=(t-w)-abs(x-u)-abs(y-v);
			if((k&1)||k<0)
				flag=1;
			u=x;
			v=y;
			w=t;
		}
		if(flag){
			printf("NO\n");
			flag=0;
		}
		else
			printf("YES\n");
		u=v=w=0;
	}
	return 0;
}


