#include<bits/stdc++.h>
using namespace std;
int n,K,tot;
int a[40];
int qvq[40];int vis[40];
int bex[10][40];
int bel[10][40];
int ber[10][40];
int k[10][40]={{1,2,4,5,6,10,11},{3,4,8,9,10,14,15},{10,11,15,16,17,21,22},{6,7,11,12,13,17,18},{14,15,19,20,21,25,26},{21,22,26,27,28,30,31},{17,18,22,23,24,28,29}};
int find_x(int  x){
if(x<=2) return 1;if(x<=7) return 2;if(x<=13) return 3;if(x<=18) return 4;if(x<=24) return 5;if(x<=29) return 6;return 7;
}
int find_l(int x){
	if(x==3||x==8) return 1;
	if(x==1||x==4||x==9||x==14||x==19) return 2;
	if(x==2||x==5||x==10||x==15||x==20||x==25) return 3;
	if(x==6||x==11||x==16||x==21||x==26) return 4;
	if(x==7||x==12||x==17||x==22||x==27||x==30) return 5;
	if(x==13||x==18||x==23||x==28||x==31) return 6;
	if(x==24||x==29) return 7;
	return 7;
}
int find_r(int x){
	if(x==7||x==13) return 1;
	if(x==2||x==6||x==12||x==18||x==24) return 2;
	if(x==1||x==5||x==11||x==17||x==23||x==29) return 3;
	if(x==4||x==10||x==16||x==22||x==28) return 4;
	if(x==3||x==9||x==15||x==21||x==27||x==31) return 5;
	if(x==8||x==14||x==20||x==26||x==30) return 6;
	if(x==19||x==25) return 7;
	return 7;
}
bool check(){
	for(int i=0;i<7;++i){
		memset(qvq,0,sizeof(qvq));
		for(int j=0;j<7;++j){
			qvq[a[k[i][j]]]++;
		}
		for(int k=1;k<=31;++k){
			if(qvq[k]>1){
				return false;
			}
		}
	}
	return true;
}
void print(){
	printf("Found\n");
	for(int i=1;i<=31;++i){
		printf("%d ",a[i]);
	}
}
void dfs(int x){
	if(vis[x]){
		dfs(x+1);
	}
	if(!check()){
		return;
	}
	if(x==32){
		tot++;
		if(tot==K){
		print();
		exit(0);
		}
		return;
	}
	if(!vis[x]){
		for(int i=1;i<=n;++i){
			if(!bex[find_x(x)][i]){
			if(!bel[find_l(x)][i]){
				if(!ber[find_r(x)][i]){
						bex[find_x(x)][i]=bel[find_l(x)][i]=ber[find_r(x)][i]=1;
						a[x]=i;
						dfs(x+1);
						bex[find_x(x)][i]=bel[find_l(x)][i]=ber[find_r(x)][i]=0;
						a[x]=0;
				}
			}
		}
	}
	}
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	scanf("%d%d",&n,&K);
	for(int i=1;i<=31;++i){
		scanf("%d",&a[i]);
		if(a[i]){
			vis[i]=1;
			bex[find_x(i)][a[i]]=1;
			bel[find_l(i)][a[i]]=1;
			ber[find_r(i)][a[i]]=1;
		}
	}
	if(n<=6&&K>0){
		printf("No way");
		return 0;
	}
	if(n==7&&K>10080){
		printf("No way");
		return 0;
	}
	dfs(1);
	return 0;
}


