#include<bits/stdc++.h>
using namespace std;

template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}

int n,ans;
long long m;
const int maxn=500005;
int a[maxn];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	while(m--) {
		int l,r,s,e,tot;
		read(l); read(r); read(s); read(e);
		if(s==e) {
			for(int i=l;i<=r;i++) {
				a[i]+=s;
			}
		}
		else {
			int t=(s-e)/(r-l);
			for(int i=l;i<=r;i++)  {
				a[i]+=s+tot*t;
			}	
		}
	}
	if(n>=2){
	ans=a[1]^a[2];	
	}
	else {
		printf("%d\n",&a[1]);
		return 0;	
	}
	for(int i=3;i<=n;i++) {
		ans^=a[i];
	}
	printf("%d\n",ans);
	return 0;
}
