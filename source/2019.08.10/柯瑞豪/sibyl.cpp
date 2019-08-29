#include<bits/stdc++.h>
using namespace std;
const int N=300010;
int n,m,Q,L[N];
vector<int> A[N];
queue<int> q;
bool f[N];
long long Ans[N],C[N];
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c&15);
		c=getchar();
	}
	return x*w;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=read();m=read();Q=read();
	for(int i=1,x,y;i<=m;i++){
		x=read();y=read();
		if(x==y)continue;
		A[x].push_back(y);
		A[y].push_back(x);
	}
	for(int x=1;x<=n;x++){
		sort(A[x].begin(),A[x].end());
		L[x]=unique(A[x].begin(),A[x].end())-A[x].begin();
	}
	int type;
	bool flag=0;
	while(Q--){
		type=read();
		if(type){
			flag=1;
			int x=read(),y=read();
			C[x]+=(long long)y;
			if(!f[x]){q.push(x);f[x]=1;}
		}
		else {
			if(flag){
			    while(!q.empty()){
			    	int x=q.front();q.pop();f[x]=0;
			        for(int i=0;i<L[x];i++){
				        Ans[A[x][i]]+=C[x];
			        }
			        C[x]=0;
		    	}
				flag=0; 	
			}
			printf("%lld\n",Ans[read()]);
		}
	}
	return 0;
}
