#include<bits/stdc++.h>
using namespace std;
int n;
int a[105];
int b[15];
int gg;
void work(int x){
	while(x){
	int o;
	o=x%10;
	if(b[o]==0)gg++; 
	b[o]++;
	x/=10;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		gg=0;memset(b,0,sizeof(b));
		scanf("%d",&a[i]);
		work(a[i]);
		if(gg<=2)printf("1\n");
		else if(gg>=5)printf("3\n");
		else printf("2\n");
	}
	return 0;
}
