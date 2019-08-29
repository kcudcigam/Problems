#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define N 1005
typedef long long ll;
using namespace std;
int p=1000000007;
int ip(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int n,x,y,ans;
int a[N],b[N],c[N];
bool vis[N][N],Vis[N][N];
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=ip(),x=ip();
	rep(i,1,n) a[i]=ip(),b[i]=ip(),c[i]=ip(),y+=a[i];
	rep(i,1,x){
		rep(np,1,n){
			rep(j,1,b[np]){
			    rep(k,1,n){
				    rep(m,1,c[k]){
				    	if(vis[np][j]&&Vis[k][m]) continue;
					    if(j*a[np]<=y-x) continue;
					    if(i==j*a[np]&&i==m*a[k]) ans++,ans%=p;
					    vis[np][j]=Vis[k][m]=1;
				    }
		    	}
	    	}
		}
    }
    printf("%d",ans);
	return 0;
}


