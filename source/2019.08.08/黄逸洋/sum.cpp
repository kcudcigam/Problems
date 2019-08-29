#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
long long a[200000],s[200000],res=0x3f3f3f3f;
struct Tree{
	long long l,r,minn;
}t[200000];
void build(long long i,long long l,long long r){
	t[i].l=l;t[i].r=r;
	if(l==r){
		t[i].minn=s[l];
		return;
	}
	long long m=(l+r)>>1;
	build(i<<1,l,m);
	build(i<<1|1,m+1,r);
	t[i].minn=min(t[i<<1].minn,t[i<<1|1].minn);
}
void query(long long i,long long L,long long R){
	if(L<=t[i].l&&t[i].r<=R){
		res=min(res,t[i].minn);
		return;
	}
	long long m=(t[i].l+t[i].r)>>1;
	if(R<=m){
		query(i<<1,L,R); 
	}else if(m+1<=L){
		query(i<<1|1,L,R);
	}else{
		query(i<<1,L,R);
		query(i<<1|1,L,R);
	}
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);

	long long n;
	read(n);
	for(long long i=1;i<=n;i++){
		read(a[i]);
		s[i]=s[i-1]+a[i];
	}
	
	build(1,0,n);
	
	long long ans=-0x3f3f3f3f;
	for(long long i=2;i<=n-2;i++){
		for(long long j=i+2;j<=n;j++){
			long long tmp=0;
			
			res=0x3f3f3f3f;
			query(1,0,i-1);
			tmp+=s[i]-res;
			
			res=0x3f3f3f3f;
			query(1,i,j-1);
			tmp+=s[j]-res;
			
			ans=max(ans,tmp);
		}
	}
	writeln(ans);
	return 0;
}
/*
7
2 -4 3 -1 2 -4 3

*/

