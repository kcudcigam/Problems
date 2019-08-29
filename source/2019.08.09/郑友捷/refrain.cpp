#include<cstdio>
#include<algorithm>
using namespace std;
int num,n,m1,m2;
bool inv[20][20],inv1[20][20],inv2[20][20],inv3[20][20];
int tot1,tot2;
int a[20];
const int mod=1e9+7;
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	scanf("%d%d%d%d",&num,&n,&m1,&m2);
	if(n==1){
		printf("0\n");
	}
	if(n<=10){
		for(register int i=1;i<=m1;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			inv[x][y]=inv[y][x]=inv1[x][y]=inv1[y][x]=true;
		}
		for(register int i=1;i<=m2;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			inv2[x][y]=inv2[y][x]=inv3[x][y]=inv3[y][x]=true;
		}
		int sum=0;
		for(register int i=1;i<=n;i++){
			a[i]=i;
		}
		do{
			bool flag=false;
			for(register int i=1;i<=n;i++){
				for(register int j=i+1;j<=n;j++){
					if(inv[i][j]&&(!inv1[a[i]][a[j]])){
						sum++;
						sum%=mod;
						flag=true;
						break;
					}
					if(inv2[i][j]&&(!inv3[a[i]][a[j]])){
						sum++;
						sum%=mod;
						flag=true;
						break;
					}
				}
				if(flag) break;
			}
		}while(next_permutation(a+1,a+n+1));
		printf("%d\n",sum);		
	}
}
