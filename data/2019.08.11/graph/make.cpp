#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
ll R(){return ((1ll*rand()<<45)+(1ll*rand()<<30)+(1ll*rand()<<15)+rand())%1000000000000000000ll+1;}
int main(){
	freopen("graph20.in","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(false);
	int n=250000,m=300000,q=m;
	cout<<n<<' '<<m<<' '<<q<<endl;
	for (int i=2;i<=n-50000;i++)cout<<i-1<<' '<<i<<' '<<1+R()%1000000<<'\n';
	for (int i=n-50000;i<=m;i++){
		int x=1+R()%n,y=1+R()%n,z=1+R()%1000000;
		while (x==y)x=1+R()%n,y=1+R()%n,z=1+R()%1000000;
		cout<<x<<' '<<y<<' '<<z<<'\n';		
	}
	for (int i=1;i<=q;i++){
		int x=1+R()%n,y=1+R()%n;
		while (x==y)x=1+R()%n,y=1+R()%n;
		cout<<x<<' '<<y<<'\n';
	}
	return 0;
}
