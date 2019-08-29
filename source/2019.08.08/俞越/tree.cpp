#include<bits/stdc++.h>
#define LL long long 
#define mid (l+r>>1)
#define pb push_back
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int t[M*5],*id=t,*f[M],len[M],dep[M],son[M];
int n,k;
bool o[M],oo[M];
vector<int> v[M];
void Clear(){
	for (int i=0;i<=n;i++) v[i].clear();
	memset(son,0,sizeof son);
	memset(dep,0,sizeof dep);
	memset(len,0,sizeof len);
	memset(t,0,sizeof t);
	id=t;
	memset(f,0,sizeof f);
}
void dfs(int x,int fa){
	for (int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if (y==fa) continue;
		dep[y]=dep[x]+1;
		dfs(y,x);
		if (len[y]>len[son[x]]) son[x]=y;
	}
	len[x]=len[son[x]]+1;
//	cout<<x<<" "<<son[x]<<" "<<len[x]<<"   fk\n";
}
bool flag;
void calc(int x,int fa){
	if (flag) return ;
	if (son[x]){
		f[son[x]]=f[x]+1;
		calc(son[x],x);
	}
	for (int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if (y==fa || y==son[x]) continue;
		f[y]=id; id+=len[y]+2; calc(y,x);
		for (int j=0;j<=len[y];j++)
		f[x][j+1]+=f[y][j];
	}
	for (int i=1;i<=len[x];i++) f[x][i]+=f[x][i-1];
	int ll=min(len[x],k-1);
//	cout<<x<<" "<<ll<<" "<<dep[x]<<" "<<f[x][ll]<<"   mdzz\n";
	if (dep[x]>=k){
		if (f[x][ll]&1){
			if (o[x]==oo[x]){
				for (int i=0;i<=len[x];i++) f[x][i]++;
			}
		}
		else {
			if (o[x]!=oo[x]){
				for (int i=0;i<=len[x];i++) f[x][i]++;
			}
		}
	}
	else {
		if (f[x][ll]&1){
			if (o[x]==oo[x]){
				flag=1;
			}
		}
		else {
			if (o[x]!=oo[x]){
				flag=1;	
			}
		}
	}
//	cout<<f[x][0]<<"\n";
}
void work(){
	n=read(); k=read(); flag=0;
	for (int i=1;i<n;i++) {
		int x=read(),y=read(); 
		v[x].pb(y);
		v[y].pb(x);
	}
	for (int i=1;i<=n;i++) o[i]=read();
	for (int i=1;i<=n;i++) oo[i]=read();
	dep[1]=1; dfs(1,0);
	f[1]=id; id+=len[1]+2; 
	calc(1,0);
	if (flag) puts("No");
	else puts("Yes");
	Clear();
//	for (int i=1;i<=n;i++) {
//		if (len[i]>=k) cout<<i<<" --- "<<f[i][k]<<"\n";
//	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T=read();
	while (T--) work();
	return 0;
}

