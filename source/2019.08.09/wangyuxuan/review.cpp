#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
LL x,n,m;
pair<int,int> a[1<<20];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	read(x);n=log2(x)+3;
	for (int i=2;i<n;++i)
		for (int j=1;j<i;++j)
			a[++m]=make_pair(j,i);
	for (int i=2;i<n;++i)
		if (x&(1<<(i-2))) a[++m]=make_pair(i,n);
	cout<<n<<' '<<m<<'\n';
	for (int i=1;i<=m;++i)
		cout<<a[i].first<<' '<<a[i].second<<'\n';
	return 0;
}
