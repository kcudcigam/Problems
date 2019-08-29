#include<bits/stdc++.h>
using namespace std;
vector<int> d;
int n,m;
int a[500001],b[500001];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout); 
	read(n);read(m);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(b[i]);
	for(int i=1;i<=m;++i){
		int t;
		read(t);
		if(t==1){
			int x,y,z;
			read(x);read(y);read(z);
			if(x)b[y]=z;
			else a[y]=z;
		}
		else {
			int l,r,x,y;
			read(l);read(r);read(x);read(y);
			d.clear();
			for(int j=l;j<=r;++j)d.push_back(a[j]);
			for(int j=x;j<=y;++j)d.push_back(b[j]);
			stable_sort(d.begin(),d.end());
			printf("%d\n",d[(r-l+1+y-x+1)/2]);
	}
}
	return 0;
}


