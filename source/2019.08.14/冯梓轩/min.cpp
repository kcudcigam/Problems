#include<bits/stdc++.h>
using namespace std;
int ri(){
	char c=getchar();
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)-'0'+c;return x*f;
}
int n,A,B,C,D,a[200010];
long long f[200010],k=0,mi=0,t;
long long fm(long long x){
	return ((A*x+B)*x+C)*x+D;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	bool f=0;
	n=ri();
	A=ri();
	B=ri();
	C=ri();
	D=ri();
	for(int i=1;i<=n;i++){
		a[i]=ri();
		t=fm(a[i]);
		if(t>=0){
			k+=t;
			if(f){
				k+=mi;
				f=0;
				mi=0;
			}
		}
		else{
			if(t<mi)mi=t;
			f=1;
		}
	}
	if(f)k+=mi;
	cout<<k<<endl;
	return 0;
}
