#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define ll long long
#define N 500005
//int dp[N][2];
using namespace std;
vector<ll>ans;
int n,m;
ll a[N],b[N];
ll ip(){
    char c=getchar();ll x=0;
	for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar()) x=x*10-'0'+c; return x;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=ip(),m=ip();rep(i,1,n) a[i]=ip();rep(i,1,n) b[i]=ip();
	rep(i,n+1,2*n) a[i]=b[i-n];
//	rep(i,1,2*n) cerr<<a[i]<<" ";cerr<<"\n";
	while(m--){
		ans.clear();
		int opt=ip(),x,y,z,h;
		if(opt==1) {
			x=ip(),y=ip(),z=ip();
			if(x==0) a[y]=z;
			else a[y+n]=z;
		}
		else{
			x=ip(),y=ip(),z=ip(),h=ip();
            rep(i,x,y) ans.push_back(a[i]);
            rep(i,n+z,n+h) ans.push_back(a[i]);
            sort(ans.begin(),ans.end());
            printf("%lld\n",ans[((h-z+1)+(y-x+1))/2]);
		}
    }
	return 0;
}

