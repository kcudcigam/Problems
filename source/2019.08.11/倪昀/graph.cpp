#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define N 1010
using namespace std;
struct info{
	int x,y,z;
}edge[N];
vector<int>a[N];
vector<int>S;
int fa[N],f[N],b[N][N],flg=0;
stack<int>stk;
inline int cmp(info a,info b){
	return a.z<b.z;
}
inline int Find(int x){
	if(fa[x]!=x)fa[x]=Find(fa[x]);
	return fa[x];
}
inline void dfs(int s,int e){
	if(flg)return;
	f[s]=1;
	stk.push(s);
	if(s==e){
		flg=1;
		while(stk.size()){
			int tmp=stk.top();
			S.push_back(tmp);
			stk.pop();
		}
		return;
	}
	fir(i,0,a[s].size()-1)
	    if(!f[a[s][i]]&&b[s][a[s][i]])dfs(a[s][i],e);
	if(flg)return;
	stk.pop();
}
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*f;
}
int main(){
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    int n=read(),m=read(),Q=read();
    memset(b,0,sizeof(b));
    fir(i,1,m){
    	int x=read(),y=read(),z=read();
    	a[x].push_back(y);
    	a[y].push_back(x);
    	edge[i].x=x,edge[i].y=y,edge[i].z=z;
	}
	sort(edge+1,edge+m+1,cmp);
	fir(i,1,n)fa[i]=i;
	fir(i,1,m)
	    if(Find(edge[i].x)!=Find(edge[i].y))
	        fa[Find(edge[i].y)]=Find(edge[i].x),b[edge[i].x][edge[i].y]=edge[i].z,b[edge[i].y][edge[i].x]=edge[i].z;
	fir(i,1,Q){
		int x=read(),y=read();
		if(Find(x)!=Find(y)){
			cout<<-1<<endl;
			continue;
		}
		memset(f,0,sizeof(f));
		while(S.size())S.pop_back();
		flg=0;
		dfs(x,y);
		int ans=0;
		fir(i,0,S.size()-2)
		    ans=max(ans,b[S[i]][S[i+1]]);
		cout<<ans<<endl;
	}
	return 0;
}
