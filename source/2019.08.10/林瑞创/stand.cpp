#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[6],l[255],r[255];
int shop[10000010],v[255];
long long ans;

inline int read(){
	int f=1,num=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return f*num;
}

long long  g(int x){
	ll ans=0;
	for(int i=1;i<=5;i++){
		ll sum=(ll)a[i];
		for(int j=1;j<=i;j++)sum*=(ll)x;
		ans+=sum;
	}
	return ans;
}

void dfs(int x){
	ans+=g(shop[x]);  bool flag=1;
	memset(shop,0,sizeof(shop));
	for(int i=1;i<=n;i++){
		if(l[i]<=x&&x<=r[i])v[i]=1;
		if(!v[i])flag=0,shop[l[i]]++,shop[r[i]+1]--;
	}
	if(flag)return;
	for(int i=1;i<=m;i++){
		shop[i]+=shop[i-1];
		if(shop[x]<shop[i])x=i;
	}
	dfs(x);
}

int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=5;i++)a[i]=read();
    for(int i=1;i<=n;i++){
    	l[i]=read(),r[i]=read();
        shop[l[i]]++;  shop[r[i]+1]--;
	}
	
	int maxn=0;
	for(int i=1;i<=m;i++){
		shop[i]+=shop[i-1];
		if(shop[maxn]<shop[i])maxn=i;
	}
    dfs(maxn);
    printf("%d\n",ans);
	return 0;
}


