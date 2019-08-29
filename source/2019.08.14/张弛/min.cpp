#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=210000,inf=LLONG_MAX;
int mx[N],f[N],a[N];
stack<pair<int,int> > q;
int read(){
	int x=0,f=1; char c=0;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	return x*f;
}
int query(int t,int L,int R,int l,int r){
	if(l>r) return 0;
	if(L==l && R==r) return mx[t];
	int mid=(L+R)/2,ans=-inf;
	if(l<=mid) ans=query(t*2,L,mid,l,min(mid,r));
	if(r>mid) ans=max(ans,query(t*2+1,mid+1,R,max(l,mid+1),r));
	return ans;
}
void modify(int t,int l,int r,int x){
	if(l==r){ mx[t]=f[x]; return;}
	int mid=(l+r)/2;
	if(x<=mid) modify(t*2,l,mid,x);
	else modify(t*2+1,mid+1,r,x);
	mx[t]=max(mx[t*2],mx[t*2+1]);
}
signed main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	int n=read(),A=read(),B=read(),C=read(),D=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	q.push(make_pair(-inf,0));
	memset(mx,192,sizeof(mx));
	modify(1,0,n,0);
	f[0]=-inf;
	for(int i=1;i<=n;i++){
		int x=a[i],w=A*x*x*x+B*x*x+C*x+D;
		while(x<=q.top().first) q.pop();
		int t=q.top().second;
		f[i]=max(f[t],query(1,0,n,t,i-1)+w);
		modify(1,0,n,i);
		q.push(make_pair(a[i],i));
	}
	cout<<f[n]<<"\n";
	return 0;
}
