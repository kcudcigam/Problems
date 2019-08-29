#include<bits/stdc++.h>
using namespace std;
const int mo=1000000007;
struct node{
	int a,b,c;
}h[1010];
long long n,x,y=0,t=0,f[1010];
bool ok(int k,int ch){
	if(k==0&&ch==0)return 1;
	if(k==0&&ch!=0)return 0;
	int tt=min(h[k].b,ch/h[k].a);
	return ok(k-1,ch-tt*h[k].a);
}
void dfs(int dep,long long sum){
	if(sum>y+x)return;
	if(sum>=x){
		for(int i=1;i<dep;i++)if(sum-x>=h[i].a&&f[i]!=0)return;
		if(ok(n,sum-x))t=(t+1)%mo;
		return;
	}
	if(dep>n)return;
	for(int i=0;i<=h[dep].b;i++){
		f[dep]=i;
		dfs(dep+1,sum+h[dep].a*i);
	}
	return;
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>h[i].a>>h[i].b>>h[i].c;
		y=y+h[i].c*h[i].a;
	}
	dfs(1,0);
	cout<<t<<endl;
	return 0;
}
