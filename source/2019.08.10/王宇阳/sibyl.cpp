#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;
	   char c=getchar();
	   while(c>'9' || c<'0'){if(c=='-')f=-1;c=getchar();}
	   while(c<='9' && c>='0'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	   return x*f;
}
vector<int>vec[300005];
int sum[300005];
int n,m,Q;
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=read();m=read();Q=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	while(Q--){
		int p=read();
		if(!p){
			int x=read();
			cout<<sum[x]<<endl;	
		}else{
			int x=read(),y=read();
			sum[x]+=y;
			for(int i=0;i<vec[x].size();i++){
				sum[vec[x][i]]+=y;
			}
		}
	}
	return 0;
}


