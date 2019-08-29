#include<bits/stdc++.h>
using namespace std;
template <typename T>void read(T &x){
   int f=1;x=0;char c=getchar();
   for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
   for(;isdigit(c);c=getchar())x=x*10+c-'0';
   x*=f;
}
long long ans=0;
int n,p;
int a[5000],pre[5000];
void cp(){
	int s=0;
	for(int i=1;i<=n;i++)if(pre[i]!=a[i])s++;
	if(pre[1]==0)s=0;
	ans=(ans+s)%p;
	for(int i=1;i<=n;i++)pre[i]=a[i];
}
bool v[10];
void dfs(int s){
	if(s>n){
		cp();
    }
	for(int i=1;i<=n;i++){
		if(v[i]==false){
			a[s]=i;
		    v[i]=true;
		    dfs(s+1);
		    v[i]=false;
		}	
	}
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int q;
	read(q);
	for(int i=1;i<=q;i++){
		read(n);read(p);
		ans=0;
		memset(pre,0,sizeof(pre));
		memset(a,0,sizeof(a));
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}


