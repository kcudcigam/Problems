#include<bits/stdc++.h>
using namespace std;
int n,m,q,ecnt,a[300005],head[300005];
struct edge{
	int to;
	int next;
}e[600005];
void ae(int x,int y){
	e[++ecnt].to=y;
	e[ecnt].next=head[x];
	head[x]=ecnt;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		int t1,t2;
		cin>>t1>>t2;
		ae(t1,t2);
		ae(t2,t1);
	}
	for(int i=1;i<=q;i++){
		int t1;
		cin>>t1;
		if(t1==1){
			int t2,t3;
			cin>>t2>>t3;
			a[t2]+=t3;
			for(int j=head[t2];j;j=e[j].next){
				a[e[j].to]+=t3;
			}
		}else{
			int t2;
			cin>>t2;
			cout<<a[t2]<<endl;
		}
	}
	return 0;
}
