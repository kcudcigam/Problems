#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

typedef long long ll;

template <class T_> void read(T_ &x) {
	char ch;bool flag=false;x=0;
	while(!isdigit(ch=getchar()))
		(ch=='-')&&(flag=true);
	do{(x*=10)+=ch-'0';
	}while(isdigit(ch=getchar()));
	(flag)&&(x=-x);
} 

ll a[500005],tl[500005],tr[500005],s[500005],e[500005];
ll add[2000005];

#define kl k<<1
#define kr k<<1|1

void pushdown(int k) {
	if(add[k]==0ll)return;
	add[kl]+=add[k];
	add[kr]+=add[k];
	add[k]=0ll;
}
void modify(int k,int l,int r,int x,int y,ll v) {
	if(x<=l&&r<=y) {
		add[k]+=v;
		return;
	}
	if(y<l||r<x)return;
	pushdown(k);
	int mid=(l+r)>>1;
	modify(kl,l,mid,x,y,v);
	modify(kr,mid+1,r,x,y,v);
}
void query(int k,int l,int r) {
	if(l==r) {
		a[l]=add[k];
		return;
	}
	pushdown(k);
	int mid=(l+r)>>1;
	query(kl,l,mid);
	query(kr,mid+1,r); 
}

int main(void) {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	int n,m;
	read(n);read(m);
	bool flag=true;
	for(int i=1;i<=m;++i) {
		read(tl[i]);read(tr[i]);read(s[i]);read(e[i]);
		if(s[i]!=e[i])flag=false;
	}
	ll ans;
	if(flag) {
		for(int i=1;i<=m;++i) {
			modify(1,1,n,tl[i],tr[i],s[i]);
		}
		query(1,1,n);
		ans=a[1];
		for(int i=2;i<=n;++i)ans^=a[i];
	}
	else {
		for(int i=1;i<=m;++i) {
			ll v=(e[i]-s[i])/(tr[i]-tl[i]);
			for(int j=tl[i];j<=tr[i];++j)
				a[j]+=s[i]+(j-tl[i])*v;
		}
		ans=a[1];
		for(int i=2;i<=n;++i)ans^=a[i];
	}
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
}
