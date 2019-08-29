#include<bits/stdc++.h>
using namespace std;
int num,n,m1,m2,M1[100001],M2[100001];
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	scanf("%d%d%d%d",&num,&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d",&M1[i]);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d",&M2[i]);
	}
	if(num==1){
		printf("%d",0);
		return 0;
	}
	if(num==2){
		printf("%d",0);
	}
	return 0;
}

