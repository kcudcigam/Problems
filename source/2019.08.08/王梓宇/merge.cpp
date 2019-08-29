#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int f[500010];
int n,m;
long long a[500010];
inline int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]); 
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;++i){
		f[i]=i;
	}
	int op,x,y;
	while(m--){
		read(op),read(x),read(y);
		if(op==1){
			int le=find(x),re=find(y);
			f[le]=re;
		}
		if(op==2){
			for(int i=1;i<=n;++i){
				if(find(i)==x){
					a[i]+=y;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		printf("%lld ",a[i]);
	}
	return 0;
}

