#include<bits/stdc++.h>
using namespace std;
struct Info{
	int x;
	int y;
}a[300010];
int b[300010];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	
	int n,m,Q;
	scanf("%d %d %d",&n,&m,&Q);
	for(int i=1;i<=m;++i){
		scanf("%d %d",&a[i].x,&a[i].y);	
	}
	
//	if(n<=3000&&m<=3000&Q<=3000){
		for(int i=1;i<=Q;++i){
			int Type;
			scanf("%d",&Type);
			switch(Type){
				case 1:{
					int x,y;
					scanf("%d %d",&x,&y);
					b[x]+=y;
					break;
				}
				case 0:{
					int x;
					scanf("%d",&x);
					
					int ans=b[x];
					for(int i=1;i<=m;++i){
						if(a[i].x==x){
							ans+=b[a[i].y];
						}
						if(a[i].y==x){
							ans+=b[a[i].x];
						}
					}
					
					printf("%d\n",ans);
					break;
				}
			}
		}
		return 0;
//	}
/*ass ass ass ass ass ass ass ass ass ass ass ass*/	
	return 0;
}

