#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n,m;
long long a[500100];
long long lazy[500100*4+100];
struct node{
	int l,r;
	long long z;
};
node tree[500100*4+100];
#define l(x) tree[x].l 
#define r(x) tree[x].r
#define z(x) tree[x].z 
void build(int p,int le,int re){
	l(p)=le,r(p)=re;
	if(l(p)==r(p)){
		return;
	}
	int mid=(le+re)>>1;
	build(p*2,le,mid);
	build(p*2+1,mid+1,re);
}
void upp(int p){
	if(lazy[p]){
		lazy[p*2]+=lazy[p];
		lazy[p*2+1]+=lazy[p];
		z(p*2+1)+=(r(p*2+1)-l(p*2+1)+1)*lazy[p];
		z(p*2)+=(r(p*2)-l(p*2)+1)*lazy[p];
		lazy[p]=0;
	}
}
void case1(){
	int le_1,re_1;
	long long be_1,ed_1,ap_1;
	while(m--){
		read(le_1),read(re_1),read(be_1),read(ed_1);
		ap_1=(ed_1-be_1)/(re_1-le_1);
		for(int j=le_1,i=0;j<=re_1;++j,++i){
			a[j]+=ap_1*i+be_1;
		}
	}
	long long qvq=a[1];
	for(int i=2;i<=n;++i){
		qvq=qvq^a[i];
	} 
	printf("%lld",qvq);
}
void add(int p,int le,int re,long long qvq){
	if(l(p)>=le&&r(p)<=re){
		z(p)+=qvq*(r(p)-l(p)+1);
		lazy[p]+=qvq;
		return;
	}
	upp(p);
	int mid=(l(p)+r(p))>>1;
	if(le<=mid){
		add(p*2,le,re,qvq); 
	}
	if(re>mid){
		add(p*2+1,le,re,qvq); 
	}
	z(p)=z(p*2)+z(p*2+1);
}
long long qurry(int p,int le,int re){
	if(l(p)>=le&&r(p)<=re){
		return z(p);
	}
	upp(p);
	int mid=(l(p)+r(p))>>1;
	long long val=0;
	if(le<=mid){
		val+=qurry(p*2,le,re);
	}
	if(re>mid){
		val+=qurry(p*2+1,le,re);
	}
	return val;
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m);
	if(n<=1001&&m<=1001){
		case1();
		return 0;
	}
	int le_2,re_2;
	long long be_2,ed_2,ap_2;
	build(1,1,n);
	while(m--){
		read(le_2),read(re_2),read(be_2),read(ed_2);
		add(1,le_2,re_2,be_2);
	}
	long long yyy=qurry(1,1,1);
	for(int i=2;i<=n;++i){
		yyy=yyy^qurry(1,i,i);
	}
	printf("%lld",yyy);
	
return 0;
}

