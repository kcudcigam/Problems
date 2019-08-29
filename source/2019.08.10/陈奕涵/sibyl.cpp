#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	while(ch<'0' || ch>'9')ch=getchar();
	int ans=0;
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans;
}
//图 
const int maxn=300010;
int n,m,q;
vector<int>e[maxn];
//操作
struct ask{
	int opt,x,val;
	void reads(){
		opt=read(),x=read();
		if(opt==1)val=read();
	}
}a[maxn];
int cnt,p[maxn],ans[maxn]; 
void cut(){
	for(int i=1;i<=q;++i)
		if(a[i].opt==0)p[++cnt]=i;
}
int c[maxn],vis[maxn];queue<int>temp;
void add(int x,int val){
	ans[x]+=val;
	for(int i=0;i<e[x].size();++i)
		ans[e[x][i]]+=val;
}
void solve(int l,int r){
	if(l>r)return;
	for(int i=l;i<=r;++i){
		int x=a[i].x;c[x]+=a[i].val;
		if(!vis[x]){
			vis[x]=true;
			temp.push(x);
		}
	}
	while(!temp.empty()){
		int x=temp.front();temp.pop();
		add(x,c[x]);
		c[x]=0,vis[x]=false;
	}
}
int main()
{
	freopen("sibyl.in ","r",stdin );
	freopen("sibyl.out","w",stdout);
	//读入 
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=q;++i)a[i].reads();
	//处理操作
	cut();
	for(int i=1;i<=cnt;++i){
		solve(p[i-1]+1,p[i]-1);
		printf("%d\n",ans[a[p[i]].x]);
	}
	return 0;
}

