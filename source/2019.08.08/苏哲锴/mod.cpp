#include<bits/stdc++.h> 
#define N 100001
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n,p;
int a[N];
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int q;
	read(q);
a[4]=60;
	for(int i=1;i<=q;i++){
		read(n);read(p);
		if(n==1) cout<<0<<endl;
		if(n==2) cout<<2%p<<endl;
		if(n==3) cout<<12%p<<endl;
		if(n==4) cout<<60%p<<endl;
		if(n>=5) {
			for(int i=5;i<=n;i++) 
			a[i]=(i%p)*(a[i-1]+i)%p-i;
			cout<<a[n]%p<<endl;
		}
		
 	}
	return 0;
}
