#include<iostream>
#include<cstdio>
using namespace std;
int a[100],k,n,sum;
void dfs(int x,int s)
{
	int i;
	if(k==31){
		sum++;
		if(sum==n){
			for(i=1;i<=31;i++){
				printf("%d ",a[i]);
			}
			exit(0);
		}
	}
	if(x==1){
		if(a[2]==a[x]||a[x]==a[4]||a[x]==a[9]||a[x]==a[14]||a[x]==a[19]){
			return;
		}
		if(a[x]==a[5]||a[x]==a[11]||a[x]==a[17]||a[x]==a[23]||a[x]==a[29]){
			return;
		}
		a[x]=s;
		dfs(x++,s++);
	}
	if(x==2){
		if(a[x]==a[1]||a[x]==a[5]||a[x]==a[10]||a[x]==a[15]||a[x]==a[20]||a[x]==a[25]){
			return;
		}
		if(a[x]==a[6]||a[x]==a[12]||a[x]==a[18]||a[x]==a[24]){
			return;
		}
		a[x]=s;
		dfs(x++,s++);
	}
	if(x==3){
		if(a[x]==a[4]||a[x]==a[5]||a[x]==a[6]||a[x]==a[7]||a[x]==a[8]){
			return;
		}
		if(a[x]==a[9]||a[x]==a[15]||a[x]==a[21]||a[x]==a[27]||a[x]==a[31]){
			return;
		}
		a[x]=s;
		dfs(x++,s++);
	}
	if(x==4){
		if(a[x]==a[1]||a[x]==a[3]||a[x]==a[5]||a[x]==a[7]||a[x]==a[6]) return;
		if(a[x]==a[9]||a[x]==a[14]||a[x]==a[19]||a[x]==a[10]||a[x]==a[16]||a[x]==a[22]||a[x]==a[28]) return;
		a[x]=s;dfs(x++,s++);
	}
	if(x==5){
		if(a[x]==a[1]||a[x]==a[2]||a[x]==a[3]||a[x]==a[4]||a[x]==a[7]||a[x]==a[6]) return;
		if(a[x]==a[10]||a[x]==a[15]||a[x]==a[20]||a[x]==a[25]||a[x]==a[11]||a[x]==a[17]||a[x]==a[23]||a[x]==a[29]) return;
		a[x]=s;dfs(x++,s++);
	}
	if(x==6){
		if(a[x]==a[2]||a[x]==a[12]||a[x]==a[18]||a[x]==a[24]||a[x]==a[3]) return;
		if(a[x]==a[4]||a[x]==a[5]||a[x]==a[7]||a[x]==a[11]||a[x]==a[16]||a[x]==a[21]||a[x]==a[26]) return;
		a[x]=s;dfs(x++,s++);
	}
	if(x==7){
		if(a[x]==a[13]||a[x]==a[3]||a[x]==a[4]||a[x]==a[5]||a[x]==a[6]) return;
		if(a[x]==a[12]||a[x]==a[17]||a[x]==a[22]||a[x]==a[27]||a[x]==a[30]) return;
		a[x]=s;dfs(x++,s++);
	}
	if(x==8){
		if(a[x]==a[13]||a[x]==a[3]||a[x]==a[4]||a[x]==a[5]||a[x]==a[6]) return;
		if(a[x]==a[12]||a[x]==a[17]||a[x]==a[22]||a[x]==a[27]||a[x]==a[30]) return;
		a[x]=s;dfs(x++,s++);
	}
}
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	int i;
	scanf("%d%d",&k,&n);
	for(i=1;i<=31;i++){
		scanf("%d",&a[i]);
	}
//	dfs(1,1);
    printf("No way");
	return 0;
}


