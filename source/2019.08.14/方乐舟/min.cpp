#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c,d,ss;
long long aa[200010],s[200010];
template <typename T> void read(T &p){
int f=1;p=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) p=p*10+c-'0';
p*=f;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n);read(a);read(b);read(c);read(d);
	for (int i=1;i<=n;i++){
		read(aa[i]);
		s[i]=a*aa[i]*aa[i]*aa[i]+b*aa[i]*aa[i]+c*aa[i]+d;
		if (s[i]>0) ss+=s[i];
	}
	if (ss==0){
		sort(s+1,s+n+1);
		ss=s[n];
	}
	cout<<ss<<endl;
	return 0;
}


