#include<bits/stdc++.h>
#define ll long long
#define mod 10000007
const int maxn=100005,maxm=200005;
using namespace std;
int ans;
int n,m,q;
int id[maxm],wi[maxm];
ll pi[maxm];
double p[maxm];
int l[maxn],r[maxn];
void dfs(int t){
	if(t==m+1){
		int an=0,mx,k;
		for(int i=1;i<=q;i++){
			mx=0;
			for(int j=l[i];j<=r[i];j++){
				mx=max(mx,wi[j]);
				}
			ans+=mx*
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&id[i],&wi[i],&pi[i]);
		if(pi[i]==1)p[i]=1;
		else p[i]=(double)((double)pi[i]/(double)(mod+1));  
	}
	for(int i=1;i<=q;i++)scanf("%d%d",l[i],r[i]);
	dfs(0);
	return 0;
}

