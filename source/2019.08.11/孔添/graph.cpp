#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct node{
	int y,len;
};
bool h[300010];
vector <node> MAP[300010];
long long deal(int st,int ed){
	if(st==ed) return 0;
	vector<node> p=MAP[st];
	long long MIN=1e18;
	while((!p.empty())){
		int y=p.back().y;
		long long l=p.back().len;
		if(h[y]==false){
			h[y]=true;
			long long MAX=max(deal(y,ed),l);
			MIN=min(MIN,MAX);
			h[y]=false;
		}
	
		p.pop_back();
	}
	return MIN;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m>>q;
	
	int x,y,l;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&l);
		node p;
		p.len=l,p.y=y;
		MAP[x].push_back(p);
		p.y=x;
		MAP[y].push_back(p); 
	}
	
	for(int i=1;i<=q;++i){
		scanf("%d%d",&x,&y);
		h[x]=true;
		long long p=deal(x,y);
		if(p==1e18)
			cout<<-1<<endl;
		else 
			cout<<p<<endl;
		h[x]=false;
	}
	return 0;
}


