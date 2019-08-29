#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define rint register int
#define ll long long
using namespace std;
const int maxn=1e6+7;
const int inf=1e8;

int n,m;
int num[maxn],opt[maxn];
int ans=0;

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

void makeopt(int l,int r,int s,int e){
	opt[l]=s;opt[r]=e;
	if(s==e){
		for(rint i=l+1;i<=r-1;++i)
			opt[i]=s;
	}
	else{
		int cnt=r-l+1;
		int d=(e-s)/(cnt-1);
		for(rint i=l+1;i<=r-1;++i)
			opt[i]=opt[i-1]+d;
	}
	
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int l,r,s,e;
	read(n); read(m);
	for(rint i=1;i<=m;++i){
		read(l); read(r); read(s); read(e);
		makeopt(l,r,s,e);
		for(rint j=1;j<=n;++j) num[j]+=opt[j];
//		for(rint i=1;i<=n;++i) printf("%d ",opt[i]); printf("\n");
		memset(opt,0,sizeof(opt));
	}
	ans=num[1];
	for(rint i=2;i<=n;++i){
		ans^=num[i];
	}
//	for(rint i=1;i<=n;++i) printf("%d ",num[i]); printf("\n");
	printf("%d",ans);
	return 0;
}

/*
6 3
2 4 -3 5
1 4 -9 0
3 6 6 9

ans=9;
*/











