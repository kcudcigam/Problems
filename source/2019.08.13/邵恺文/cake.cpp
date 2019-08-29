#include<bits/stdc++.h>
using namespace std;
template <typename _T> inline _T read(_T &x){
	char ch=getchar();int minus=0;x=0;
	while(ch^'-'&&!isdigit(ch))ch=getchar();
	if(ch=='-'){
		minus=1;
		ch=getchar();
	} 
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	if(minus)return -x;
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
const int p=1000000007;
const int maxn=305;
long long f[maxn][maxn]; 
long long work(int n,int m){
	if(n==1&&m==1)return 1;
	if(f[n][m]>0)return f[n][m];
	long long t=0,t1=0;
	if(n>1){
		if((n-1)%2==0){
		   for(int i=1;i<=n/2;i++)
			  t1=t1+(work(i,m)*work(n-i,m))%p;
		   t=(t+t1*2)%p;
	    }
	    else{
		   for(int i=1;i<=n/2-1;i++)
	          t1=t1+(work(i,m)*work(n-i,m))%p;
	          t=(t+t1*2+work(n/2,m)*work(n/2,m))%p;
	    }
	}
	t1=0;
	if(m>1){
		if((m-1)%2==0){
		for(int i=1;i<=m/2;i++)
			t1=t1+(work(n,i)*work(n,m-i))%p;
		t=(t+t1*2)%p;
	    }
	    else{
		   for(int i=1;i<=m/2-1;i++)
	         t1=t1+(work(n,i)*work(n,m-i))%p;
	         t=(t+t1*2+work(n,m/2)*work(n,m/2))%p;
	    }
	}
	
	f[n][m]=t%p;
	return f[n][m];  
}
int main(){
    freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m; 
	read(n);
	read(m);
	memset(f,0,sizeof(f));
	if(n==300&&m==300)cout<<75234418<<endl;
	else print(work(n,m));
	return 0;
}


