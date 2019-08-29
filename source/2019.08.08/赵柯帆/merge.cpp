#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
vector<int>a[6010];
int s[6010],fa[6010];
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int t,n;
	read(n);read(t);
	
	for(int i=1;i<=n;i++){
		a[i].push_back(i);
		fa[i]=i;
	}
	while(t--){
		int x,y,z;
		read(x);read(y);read(z);
		if(x==1){
			if(fa[y]!=fa[z]){
				for(int i=0;i<a[z].size();i++){
					a[y].push_back(a[z][i]);
					fa[a[z][i]]=y;
				}
				a[z].clear();
			}
		}else{
			for(int i=0;i<a[fa[y]].size();i++){
				s[a[fa[y]][i]]+=z;
			}
		}
	}
	
	for(int i=1;i<n;i++){
		printf("%d ",s[i]);
	}
	printf("%d\n",s[n]);
	return 0;
}

