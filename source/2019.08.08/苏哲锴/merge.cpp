#include<bits/stdc++.h> 
#define N 100001
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n,Q,st,a,b,c;
struct S{
	int b,w;
	S(int B,int W){
		b=B;w=W;
	}
};
vector<int>son[N];
int v[N],f[N];

int find(int i){
	if (f[i]==i) return f[i];
	else return find(f[i]);
}

int dfs(int a,int b){
	v[a]+=b;
	
	for(int i=1;i<=son[a].size();i++){
	c=son[a][i];
    if(c<=n)
	dfs(c,b);
	}
	
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int j=1;j<=Q;j++){
		cin>>st>>a>>b;
		if(st==1) {
			int fa=find(a);
			int fb=find(b);
			if(fa!=fb){
			f[a]=b;
			son[a].push_back(b);
			son[b].push_back(a);}
		}
		if(st==2){
			dfs(a,b);
			
			}
		}
	
  for(int e=1;e<=n;e++) 
  {
  	cout<<v[e]<<" " ;
  }
  
   return 0;
}

