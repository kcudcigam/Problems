#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>void fr(T &x){
    x=0;char c=getchar();
    int f=1;
    for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-48;
    x=x*f;
}
const int N=300010;
int head[N],d[N],ver[N],Next[N],n,ans,tot;
bool v[N];
void add(int x,int y){
	tot++;
	ver[tot]=y;Next[tot]=head[x];head[x]=tot;
}
void dp(int x){
	v[x]=1;
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		if(v[y])continue;
		dp(y);
		ans=max(ans,d[x]+d[y]+1);
		d[x]=max(d[x],d[y]+1);
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n;
	fr(n);
	
	for(int i=1,x,y;i<n;i++){
		fr(x),fr(y);
		add(x,y);
		add(y,x);
		ans=0;
		for(int i=1;i<=n;i++)v[i]=0,d[i]=0;
		dp(x);
		cout<<ans<<endl;
	}
	return 0;
}


