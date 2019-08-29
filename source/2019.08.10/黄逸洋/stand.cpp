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
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
long long A,B,C,D,E;
long long l[2000],r[2000],tag[2000],a[10000010];
long long G(long long x){
	return A*x+B*x*x+C*x*x*x+D*x*x*x*x+E*x*x*x*x*x; 
}
long long flg=1;
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);

	long long n,m;
	read(n);read(m);
	read(A);read(B);read(C);read(D);read(E);
	
	for(long long i=1;i<=n;i++){
		read(l[i]);read(r[i]);
		if(l[i]!=1||r[i]!=m)flg=0;
	}
	
	if(flg){
		writeln(G(n));
	}else{
		long long ans=0,tot=0;
		while(1){
			for(long long i=1;i<=m;i++)a[i]=0;
			for(long long i=1;i<=n;i++){
				if(!tag[i]){
					a[l[i]]++;a[r[i]+1]--;
				}
			}
			for(long long i=1;i<=m;i++)a[i]+=a[i-1];
			
			long long maxx=-1,maxi;
			for(long long i=1;i<=m;i++){
				if(a[i]>maxx){
					maxx=a[i];
					maxi=i;
				}
			}
			
			ans+=G(maxx);
			for(long long i=1;i<=n;i++){
				if(!tag[i]&&l[i]<=maxi&&maxi<=r[i]){
					tag[i]=1;
					tot++; 
				}
			}
			if(tot==n)break;
		}
		writeln(ans);
	}
	return 0;
}
/*
8 250
10 10 10 10 10
1 250
1 250
1 250
1 250
1 250
1 250
1 250
1 250

*/

