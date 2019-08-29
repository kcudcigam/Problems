#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
vector<int>v[300010];
int val[300010];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,q;
	read(n);read(m);read(q);
	for(int i=1;i<=m;i++){
		int x,y;
		read(x);read(y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	for(int i=1;i<=q;i++){
		int a;
		read(a);
		if(a==1){
			int x,y;
			read(x);read(y);
			val[x]+=y; 
			for(int i=0;i<v[x].size();i++){
				val[v[x][i]]+=y;
			}
		}else{
			int x;
			read(x);
			cout<<val[x]<<endl;
		}
	}
	return 0;
}


