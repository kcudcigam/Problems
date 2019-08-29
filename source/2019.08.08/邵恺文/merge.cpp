#include<bits/stdc++.h>
using namespace std;
template <typename T>void read(T &x){
   int f=1;x=0;char c=getchar();
   for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
   for(;isdigit(c);c=getchar())x=x*10+c-'0';
   x*=f;
}
const int maxn=500000;
int fa[maxn+5],a[maxn+5],s[maxn+5];
int getf(int x){
	if(x==fa[x])return x;
	else {
		fa[x]=getf(fa[x]);
		return fa[x];
	}
}
void merge(int x,int y){
	fa[getf(y)]=getf(x);
}
int main(){
    freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n,q,d,x,y,b,a;
	read(n);
	for(int i=1;i<=n;i++)fa[i]=i;
	read(q);
	for(int i=1;i<=q;i++){
		read(d);
		if(d==1){
			read(x);read(y);
			if(x>y)swap(x,y);
			merge(x,y);
		}
		if(d==2){
			read(a);read(b);
			int t=getf(a);
			for(int i=1;i<=n;i++)
			if(getf(i)==t)s[i]=s[i]+b;
		}
	}
	for(int i=1;i<n;i++)printf("%d ",s[i]);
	printf("%d\n",s[n]);
	return 0;
}


