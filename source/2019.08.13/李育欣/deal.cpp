#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,X,now1,now2,ans,a[10001],b[10001],c[10001],h1[10001],h2[10001];
void dfs2(int x);
void dfs1(int x,int Mi){
	if(now1==x){
		if(now1-x>=Mi)return;
		memset(h2,0,sizeof(h2));
		now2=0;
		dfs2(now1-x);return;
	}
	for(int i=1;i<=n;i++){
		if(!h1[i]){
			h1[i]=1;
			for(int j=0;j<=b[i];j++){
				now1+=a[i]*j;
				int mi=a[n];
				if(j!=0)mi=min(Mi,a[i]);
				dfs1(x,mi);
				now1-=a[i]*j;	
			}
			h1[i]=0;
		}
	}
}
void dfs2(int x){
	if(now2==x){
		ans++;ans%=mod;return;
	}
	for(int i=1;i<=n;i++){
		if(!h2[i]){
			h2[i]=1;
			for(int j=0;j<=c[i];j++){
				now2+=a[i]*j;
				dfs2(x);
				now2-=a[i]*j;
			}
			h2[i]=0;
		}
	}
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d%d",&n,&X);
	int add1=0,add2=0;
	for(int i=1;i<=n;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[i]=x;b[i]=y;c[i]=z;
		add1+=a[i]*b[i];add2+=a[i]*c[i];
	}
	add1=min(add1,add2+X);
	for(int i=X;i<=add1;++i){
		memset(h1,0,sizeof(h1));
		now1=0;
		dfs1(i,a[n]);
	}
	printf("%d",ans);
	return 0;
}


