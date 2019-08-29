#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long ans,Num,n,n1,n2,a,b;
int f[200005];
int main(){
    freopen("refrain.in","r",stdin);
    freopen("refrain.out","w",stdout);
    read(Num);
    read(n);
    read(n1);
    read(n2);
    for(int i=1;i<=n1;i++){
    	read(a);
    	read(b);
    	f[a]++;
    	f[b]++;
	}
	for(int i=1;i<=n2;i++){
		read(a);
		read(b);
		f[a]++;
		f[b]++;
	}
    if(n==1||n==2){
    	cout<<0<<endl;
    	return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*(n-f[i]);
	}
	cout<<ans<<endl;
	return 0;
}

