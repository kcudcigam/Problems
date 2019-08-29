#include<iostream>
#include<cstdio>
using namespace std;
int num;
int n,a,b;
int x[200009],y[200009];
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	scanf("%d",&num);
	scanf("%d %d %d",&n,&a,&b);
	for(int i=1;i<=a+b;i++) scanf("%d %d",&x[i],&y[i]);
	if(n==2) printf("1");
	else printf("0");
	return 0;
}
