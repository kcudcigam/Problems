#include<bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> void fr(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int N=500010;
int fa[2*N],l;
int v[N];
int getfather(int x){
	if(x==fa[x])return x;
	if(v[x])return getfather(fa[x]);
	return fa[x]=getfather(fa[x]);
}
int ask(int x){
	if(x==fa[x])return v[x];
	return v[x]+ask(fa[x]);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n,q;
	fr(n),fr(q);
	
	l=n;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int opt,a,b,x,y;
	while(q--){
		fr(opt),fr(a),fr(b);
		if(opt==1){
			x=getfather(a);
			y=getfather(b);
			if(x!=y){
				if(v[y]||v[x]){
					if(v[y]&&v[x]){
						l++;
						fa[y]=fa[x]=l;
						fa[l]=l;
					}else if(v[y]){
						fa[y]=x;
					}else fa[x]=y;
				}else fa[y]=x;
			}
		}else{
			x=getfather(a);
			v[x]+=b;
		}
	}
	
	for(int i=1;i<n;i++){
		cout<<ask(i)<<' ';
	}
	cout<<ask(n)<<endl;
	return 0;
}


