#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1,r=0;char ch;
	do ch=getchar(); while(!isdigit(ch)&&ch!='-');
	if(ch=='-'){f=-1;ch=getchar();}
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	x=f*r;
}
struct info{
	int x,y;
	friend bool operator <(info a,info b){
		return a.x<b.x;
	}
};
priority_queue<info> q;
int n,tot=0,INF;
vector<int> v;
int ver[100010],nxt[100010],head[100010];
int inv[100010],vis[100010],dis[100010];
map<int,int> ma;
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
void mem(){
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++)dis[i]=INT_MAX/2;
	INF=dis[1];
}
void jr(int x){
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(!inv[y]){
			inv[y]=1;
			v.push_back(y);
			jr(y);
		}
	}
}
void dj(int x){
	while(!q.empty())q.pop();
	dis[x]=0;
	q.push((info){0,x});
	while(!q.empty()){
		info p=q.top();q.pop();
		int Now=p.y;
		if(vis[Now])continue;
		vis[Now]=1;
		for(int i=head[Now];i;i=nxt[i]){
			int y=ver[i];
			if(dis[y]>dis[Now]+1){
				dis[y]=dis[Now]+1;
				q.push((info){dis[y],y});
			}
		}
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	cin>>n;
	if(n<=300){
		for(int u=1;u<n;u++){
			int x,y;cin>>x>>y;
			add(x,y);add(y,x);
			for(int i=1;i<=n;i++)inv[i]=0;
			v.clear();
			v.push_back(x);inv[x]=1;
			jr(x);
			int ans=0;
			for(int i=0;i<v.size();i++){
				mem();
				dj(v[i]);
				for(int ve=1;ve<=n;ve++){
					if(dis[ve]!=INF)ans=max(ans,dis[ve]);
				}
			}
			cout<<ans<<endl;
		}
	}else{		
		for(int u=1;u<n;u++){
			int x,y;read(x);read(y);
			add(x,y);add(y,x);
			int ans1=0,ans2=0;
			mem();dj(x);
			for(int i=1;i<=x;i++){
				if(dis[i]!=INF)ans1=max(ans1,dis[i]);
			}
			mem();dj(y);
			for(int i=y;i<=n;i++){
				if(dis[i]!=INF)ans2=max(ans2,dis[i]);
			}
			cout<<ans1+ans2+1<<endl;
		}	
	}
	return 0;
}
/*
5 
3 5
3 4
1 2
1 3

4
1 2
3 4
2 4 
*/

