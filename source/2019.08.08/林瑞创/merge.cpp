#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,sum[500010],fa[500010];

template <typename T> void read(T &x){
    int f=1;x=0;char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
    for (; isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

ll find(ll x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}

int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);read(q);
	for(ll i=1;i<=n;i++)fa[i]=i;
	while(q--){
		ll type,a,b; read(type),read(a),read(b);
		if(type==1){
			ll x=find(a),y=find(b);  fa[y]=x; 
		}else{
			ll x=find(a);          
			for(ll i=1;i<=n;i++)
			  if(find(i)==x)sum[i]+=b;
		}
	}
	for(int i=1;i<=n;i++)printf("%lld ",sum[i]);
	return 0;
}
