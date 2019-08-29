#include<bits/stdc++.h>
using namespace std;
int n,m,ecnt,head[100005],a[100005],f[100005];
struct edge{
	int to;
	int next;
}e[100005];
int fa(int x){
	if(x==f[x]){
		return x;
	}
	return fa(f[x]);
}
int ae(int t1,int t2){
	e[++ecnt].to=t2;
	e[ecnt].next=head[t1];
	head[t1]=ecnt;
}
int dfs(int x,int fa,int val){
	a[x]+=val;
	for(int i=head[x];i;i=e[i].next){
		int y=e[i].to;
		if(y==fa){
			continue;
		}
		dfs(y,x,val);
	}
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		if(t1==1){
			t2=fa(t2);
			t3=fa(t3);
			if(t2==t3){
				continue;
			}else{
				f[t2]=t3;
				ae(t3,t2);
				ae(t2,t3);
			}
		}else{
			t2=fa(t2);
			dfs(t2,0,t3);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
