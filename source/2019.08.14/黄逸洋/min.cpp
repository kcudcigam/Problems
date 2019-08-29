#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
struct Seg{
	long long l,r,minn;
}t[200010];
long long n,A,B,C,D,a[200010];
long long dp[2000][2000],hh[200010],h[200010];
void build(long long i,long long l,long long r){
	t[i].l=l;t[i].r=r;
	if(l==r){
		t[i].minn=a[l];
		return;
	}
	long long m=(l+r)>>1;
	build(i<<1,l,m);
	build(i<<1|1,m+1,r);
	t[i].minn=min(t[i<<1].minn,t[i<<1|1].minn);
}
long long query(long long i,long long L,long long R){
	if(L<=t[i].l&&t[i].r<=R){
		return t[i].minn;
	}
	long long m=(t[i].l+t[i].r)>>1;
	long long res=0x3f3f3f3f;
	if(L<=m)res=min(res,query(i<<1,L,R));
	if(m+1<=R)res=min(res,query(i<<1|1,L,R));
	return res;
}
long long F(long long x){
	return A*x*x*x+B*x*x+C*x+D;
} 
long long Minn(long long l,long long r){
	return query(1,l,r);
}
long long dfs(long long l,long long r){
//	cout<<l<<' '<<r<<endl;
	if(dp[l][r])return dp[l][r];
	if(l==r)return dp[l][r]=F(a[l]);
	long long res=F(Minn(l,r));
	for(long long i=l;i<r;i++){
		res=max(res,dfs(l,i)+dfs(i+1,r));
	}
	return dp[l][r]=res;
}
void baoli(){
	build(1,1,n);
	writeln(dfs(1,n));
}
void xiagao(){
	if(C==0){
		writeln(n*D);
	}else{
		long long ans=0;
		while(1){
			long long minn=1e18,mini;
			for(long long i=1;i<=n;i++){
				if(!hh[i]&&a[i]<minn){
					minn=a[i];mini=i;
				}
			}
			ans+=h[mini];
			hh[mini]=1;
			if(minn>0){
				for(int i=mini-1;i>=1&&a[i]>=a[mini]&&h[i]<0;i--)hh[i]=1;
				for(int i=mini+1;i<=n&&a[i]>=a[mini]&&h[i]<0;i++)hh[i]=1;
			}else{
				for(int i=mini-1;i>=1&&a[i]>=a[mini]&&h[i]<0;i--)hh[i]=1;
				for(int i=mini+1;i<=n&&a[i]>=a[mini]&&h[i]<0;i++)hh[i]=1;
			}
			
			long long flg=0;
			for(long long i=1;i<=n;i++){
				if(!hh[i])flg=1;
			}
			if(!flg)break;
		}
		writeln(ans);
	}
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	
	read(n);read(A);read(B);read(C);read(D);
	for(long long i=1;i<=n;i++){
		read(a[i]);
		h[i]=F(a[i]);
	}
	if(A==0&&B==0){
		xiagao();
	}else{
		baoli();
	}
	return 0;
}


