#include<bits/stdc++.h>
using namespace std;
int T,n,i,f,o,t,x,y,g,p;
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		f=0;o=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&t,&x,&y);
			g=abs(g-x-y);
			if(g>t-o){
				f=1;
			}
			p=t-o-g;
			if(p==0){
				g=x+y;o=t;
				continue;
			}
			if(g%2==0&&(t-o)%2){
				f=1;
			}
			if(g%2&&(t-o)%2==0){
				f=1;
			}
			g=x+y;o=t;
		}
		if(f==1){
			printf("No\n");
		}
		else{
			printf("Yes\n");
		}
	}
	return 0;
}
