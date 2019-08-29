#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int x[111111],y[111111],p[111111];
double P[211111];
template <typename T> void read(T &x){
	T f=1; x=0; char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
			f=-f;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
}
template <typename T> void writing(T x){
	if (x>9){
		writing(x/10);
	}
	putchar(x%10+'0');
}
template <typename T> void write(T x){
	if (x<0){
		x=-x;
		putchar('-');
	}
	writing(x);
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int n,m,q;
	read(n);
	read(m);
	read(q);
	for (int i=1;i<=n;i++){
		read(x[i]);
		read(y[i]);
		read(p[i]);
		P[x[i]]=y[i]*1.0*p[i]/(MOD*1.0);
	}
	double ans=0.0;
	for (int i=1;i<=q;i++){
		int l,r;
		read(l);
		read(r);
		double maxx=0.0;
		for (int j=l;j<=r;j++){
			maxx=max(maxx,P[i]);
		}
		ans=ans+maxx;
	}
	int k=ceil(ans);
	writeln(k);
	return 0;
}

