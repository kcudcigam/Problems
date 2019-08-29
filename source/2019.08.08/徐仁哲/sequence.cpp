#pragma GCC optimise("O2") 
#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long a[500010];
long long l,r,s,e,ls;
long long ans=0;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m;
	read(n);
	read(m);
	for(int i=1;i<=m;i++){
		read(l);
		read(r);
		read(s);
		read(e);
		if(s!=e) ls=(e-s)/(r-l);
		else ls=s;
		for(int j=l;j<=r;j++){
			a[j]+=ls;
			s+=ls;
		}
	}
	for(int i=1;i<=n;i++)
	ans=ans^a[i];
//	for(int i=1;i<=n;i++)
//	cout<<a[i]<<endl;
	cout<<ans<<endl;
	return 0;
}
