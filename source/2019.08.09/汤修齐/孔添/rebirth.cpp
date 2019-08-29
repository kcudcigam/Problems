#include<bits/stdc++.h>
using namespace std;
int n,m,fl;
long long MIN;
struct node{
	int y;
	int len;
	int i;
};
vector<node> MAP[200010];
long long a[200010];
int b[200010];
bool h[500010];
void deal(int num,int dep,long long tot){
	if(b[dep-1]==1){
		if(tot<MIN){
			MIN=tot;
		}
		return;
	}
	vector<node> p=MAP[num];
	if(p.empty()){
		MIN=-1;
		return;
	}
	while((!p.empty())){
		int ii=p.back().i;
		int y=p.back().y;
		int len=p.back().len;
		if(ii!=fl&&h[y]==false&&tot+len<MIN){
			h[y]=true;
			b[dep]=y;
			deal(y,dep+1,tot+len);
			h[y]=false;
		}
		p.pop_back() ;
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);	
	int num;
	cin>>num;
	cin>>n>>m;
	int x,y,len;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&len);
		node p;
		p.len=len,p.y=y,p.i=i;
		MAP[x].push_back(p);
		p.y=x;
		if(x!=y)
			MAP[y].push_back(p); 
	}
	
	cout<<0;
	for(int i=2;i<=n;++i){
		vector<node> p=MAP[i];
		long long MAX=-1;
		while((!p.empty())){
			MIN=1e18;
			fl=p.back().i;
			int y=p.back().y;
			deal(i,1,0);
			MAX=max(MAX,MIN);
			p.pop_back() ;
		}
		if(MAX!=1e18)
			cout<<" "<<MAX;
		else
			cout<<" "<<-1;
	}
	
	cout<<endl;
	return 0;
}

