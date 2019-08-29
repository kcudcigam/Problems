#include<bits/stdc++.h>
using namespace std;
long long n,q,t,x,y;
long long s[500010];
int fa[500010];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int get(int x){
	if (x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void me(int x,int y){
	fa[get(x)]=get(y);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);read(q);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (long long i=1;i<=q;i++){
		read(t);read(x);read(y);
		if (t==1) me(x,y);
		if (t==2){
			for (int j=1;j<=n;j++){
				if(fa[j]==x) s[j]+=y;
			}
		}
	}
	for (int i=1;i<=n;i++){
		printf("%lld ",s[i]);
	}
	cout<<endl;
	return 0;
}


