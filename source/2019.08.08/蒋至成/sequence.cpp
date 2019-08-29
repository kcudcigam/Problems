#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n,m,bo[500001],bl[500001],br[500001];
long long a[500001],add[500001];
void build(){
	int block=sqrt(n);
	int num=n/block;
	if(n%block)num++;
	for(int i=1;i<=n;++i){
		bo[i]=(i-1)/block+1;
	}
	for(int i=1;i<=num;++i){
		bl[i]=(i-1)*block+1;
		br[i]=i*block;
	}
	br[num]=min(br[num],n);
}
void addd(int l,int r,int s,int e){
	int x=bo[l],y=bo[r];
	for(int i=x+1;i<y;++i)add[i]+=s;
	if(x==y){
		for(int i=l;i<=r;++i)a[i]+=s;
	}
	else{
	for(int i=l;i<=br[x];++i)a[i]+=s;
	for(int i=bl[y];i<=r;++i)a[i]+=s;	
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);
	build();
	for(int i=1;i<=m;++i){
		int l,r,s,e;
		read(l);read(r);read(s);read(e);
		if(s==e){addd(l,r,s,e);}
		else{
		int bas=s,ad=(e-s)/(r-l);
		for(int i=l;i<=r;++i){
		a[i]+=bas+(i-l)*ad;
		}
		}
}
	long long ans=a[1]+add[bo[1]];
	for(int i=2;i<=n;++i){
		ans=ans^(a[i]+add[bo[i]]);
	}
	cout<<ans;
	return 0;
}


