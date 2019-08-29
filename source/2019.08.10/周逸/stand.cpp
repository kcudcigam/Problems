#include<bits/stdc++.h>
using namespace std;
const int maxn=300;
int n,m;
int x1,x2,x3,x4,x5;
int l[maxn],r[maxn];
bool flag;
long long G(int x){
	return (long long)x*(x1+x*(x2+(long long)x*(x3+x*((long long)x4+x*x5))));
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d%d",&x1,&x2,&x3,&x4,&x5);
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		if(l[i]!=1||r[i]!=m)
			flag=1;
	}
	if(!flag){
		int weight[maxn];
		long long value[maxn],f[maxn];
		for(i=1;i<=n;i++){
			weight[i]=i;
			value[i]=G(i);
		}
		for(i=1;i<=n;i++)
			for(j=weight[i];j<=n;j++)
				f[j]=max(f[j],f[j-weight[i]]+value[i]);
		printf("%lld",f[n]);
		return 0;
	}
	
	return 0;
}
