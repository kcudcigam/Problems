#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(T &x){
	char ch=getchar();
	int minus=0;x=0;
	while(ch^'-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')minus=1,ch=getchar();
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	if(minus)x=-x;
	return x;
}
template <typename T> void printe(const T x)
{
    if(x>=10)printe(x/10);
    putchar(x%10+'0');
}
template <typename T> inline void print(const T x)
{
    if(x<0)putchar('-'),printe(-x);
    else printe(x);
}
int A,B,C,D,n;
long long func(long long x){
	long long t=A*x*x*x+B*x*x+C*x+D;
	return t;
}
const int maxn=200003; 
int a[maxn];
struct node{
	int mi;
	long long val;
}f[maxn];
long long s[maxn];
int main(){
	freopen("min.in","r",stdin);
    freopen("min.out","w",stdout);
	read(n);read(A);read(B);read(C);read(D);
	for(int i=1;i<=n;i++)read(a[i]);
	int tot=0;
	f[++tot].val=func(a[1]);
	f[tot].mi=a[1];
	long long ans=0;
    for(int i=2;i<=n;i++){
    	long long t=func(a[i]);
    	if(t>0||f[tot].val>0)f[++tot].val=t,f[tot].mi=a[i];
		else{
			if(f[tot].mi>a[i]){
				f[tot].mi=a[i];
				f[tot].val=t; 
			} 
		}	
	}
	for(int i=1;i<=tot;i++)ans+=f[i].val;
	if(tot==n){
		print(ans);
		putchar('\n');
	}
	s[0]=0;
	for(int i=1;i<=tot;i++)
	  s[i]=s[i-1]+f[i].val;
	int minus=0;
	for(int i=1;i<=tot;i++){
		if(minus==0){
			if(f[i].val<0)minus=i;
			continue;	
		}
		if(minus>0&&f[i].val<0){
			int t1=abs( f[max(f[minus].mi,f[i].mi)].val );
			int t2=s[i-1]-s[minus];
			if(t1>t2)ans+=(t1-t2);
			minus=i;
		}
	}
	print(ans);
	putchar('\n');
	return 0;
}


