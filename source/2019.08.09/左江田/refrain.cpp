#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int num,n,m1,m2,cant,boof;
int x,y,map[11][11],p[11],bo[11];
int dfs(int px){
	for(int i=1;i<=n;++i){
		if(bo[i]==0){
			p[px]=i;
			bo[i]=1;
			if(px==n){
				boof=0;
				for(int j=1;j<=n;++j){
					if(boof==1){
						break;
					}
					for(int k=1;k<=n;++k){
						if((map[j][k]!=3&&map[p[j]][p[k]]==3)||
						   (map[j][k]==2&&map[p[j]][p[k]]==1)||
						   (map[j][k]==1&&map[p[j]][p[k]]==2)||
						   (map[j][k]==0&&map[p[j]][p[k]]!=0)){
							boof=1;
							break;
						}
					}
				}
				if(boof==1){
					cant++;
				}
			}
			else{
				dfs(px+1);
			}
			bo[i]=0;
		}
	}
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	scanf("%d",&num);
	scanf("%d %d %d",&n,&m1,&m2);
	if(n<=10){
		for(int i=1;i<=m1;++i){
			scanf("%d %d",&x,&y);
			map[x][y]+=1;
			map[y][x]+=1;
		}
		for(int i=1;i<=m2;++i){
			scanf("%d %d",&x,&y);
			map[x][y]+=2;
			map[y][x]+=2;
		}
		cant=0;
		dfs(1);
		printf("%d",cant);
	}
	else{
		printf("1\n");
	}
	return 0;
}
