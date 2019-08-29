#include<bits/stdc++.h>
using namespace std;
int n,ecnt,head[100005],dp1[100005],dp2[100005];
struct edge{
	int next;
	int to;
}e[200005];
void ae(int t1,int t2){
	e[++ecnt].to=t2;
	e[ecnt].next=head[t1];
	head[t1]=ecnt;
}
void dfs(int x,int fa){
	dp1[x]=0;
	dp2[x]=x;
	for(int i=head[x];i;i=e[i].next){
		int y=e[i].to;
		if(fa==y){
			continue;
		}
		dfs(y,x);
		if(dp1[y]+1>dp1[x]){
			dp1[x]=dp1[y]+1;
			dp2[x]=dp2[y];
		}
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		int t1,t2;
		cin>>t1>>t2;
		ae(t1,t2);
		ae(t2,t1);
		dfs(t1,0);
		int x=dp2[t1];
		dfs(x,0);
		cout<<dp1[x]<<endl;
	}
	return 0;
}
