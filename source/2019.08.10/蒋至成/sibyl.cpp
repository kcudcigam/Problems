#include<bits/stdc++.h>
using namespace std;
int n,m,q;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
vector<int> a[300001];
int ans[300001];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	read(n);read(m);read(q);
	for(int i=1;i<=m;++i){
		int x,y;
		read(x);read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=q;++i){
		int t,x,y;
		read(t);
		if(t){
			read(x);read(y);
			ans[x]+=y;
			for(int j=0;j<a[x].size();++j){
				ans[a[x][j]]+=y;
			}
		}
		else {
			read(x);
			cout<<ans[x]<<'\n'; 
		}
	}
	return 0;
}


