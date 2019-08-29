#include<bits/stdc++.h>
using namespace std;
template <typename T>void read(T &x){
   int f=1;x=0;char c=getchar();
   for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
   for(;isdigit(c);c=getchar())x=x*10+c-'0';
   x*=f;
}
const int maxn=500000;
long long a[maxn+5];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m;
	read(n);
	read(m);
	int l,r,s,e;
	for(int i=1;i<=m;i++){
		read(l);read(r);read(s);read(e);
		int cha=(e-s)/(r-l);
		a[l]+=s;s=s+cha;
		for(int j=l+1;j<=r;j++){
			a[j]=a[j]+s;
			s=s+cha;
		}	  
	}
	long long ans=a[1];
	for(int i=2;i<=n;i++)
	  ans=ans^a[i];
	cout<<ans<<endl;
	return 0;
}


