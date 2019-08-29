#include<bits/stdc++.h>
using namespace std;
struct Info{
	int x;
	int y;
	int len;
}a[500010];
int b[200010];
int N,M;
void gao(int n,int q){
	if(n==1){
		printf("%d\n",q);
		return;
	}
	for(int i=1;i<=M;++i){
		if(a[i].y!=n&&a[i].x!=n)continue;
		if(a[i].y==n)swap(a[i].x,a[i].y);
		gao(a[i].y,q+a[i].len);
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int Num;
	scanf("%d%d%d",&Num,&N,&M);
	for(int i=1;i<=M;++i){
		scanf("%d%d%d",&a[i].y,&a[i].x,&a[i].len);
	}
	
	for(int i=1;i<N;++i){
		if(i==1){
			printf("%d",0);
			continue;
		}
		gao(i,0);
	}
	printf("\n");
	return 0;
}


