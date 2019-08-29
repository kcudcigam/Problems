#include<bits/stdc++.h>
using namespace std;
template<typename T>void fr(T &x){
    x=0;char c=getchar();
    int f=1;
    for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-48;
    x=x*f;
}
const int N=300010;
int head[N],ver[N],Next[N],tot,n,m,ans[N];
void add(int x,int y){
	tot++;
	Next[tot]=head[x];head[x]=tot;ver[tot]=y;
}
void Insert(int x,int y){
	ans[x]+=y;
	for(int i=head[x];i;i=Next[i])
		ans[ver[i]]+=y;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int q;
	fr(n),fr(m),fr(q);
	
	for(int i=1,x,y;i<=m;i++){
		fr(x),fr(y);
		add(x,y);
		add(y,x);
	}
	int opt,x,y;
	while(q--){
		fr(opt);
		if(opt==0){
			fr(x);
			printf("%d\n",ans[x]);
		}else{
			fr(x),fr(y);
			Insert(x,y);
		}
	}
	return 0;
}


