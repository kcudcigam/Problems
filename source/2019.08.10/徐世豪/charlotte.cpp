#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int T,n;
int t[100009],x[100009],y[100009];
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int q=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d %d %d",&t[i],&x[i],&y[i]);
		for(int i=0;i<n;i++){
			int k=t[i+1]-t[i];
			int s=abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
			if(s>k||(s<k&&(k-s)%2==1)){q=1;break;}
		}
		if(q) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
