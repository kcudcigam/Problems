#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define ull long double
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int n,m;
struct wzy{
	int ls,rs;ull sum,tag;
}tree[1000010];
int tot=1;
inline void build(int l,int r,int pos){
	if(l>=r)return;
	int mid=(l+r)>>1;
	tree[pos].ls=++tot;tree[pos].rs=++tot;
	build(l,mid,tree[pos].ls);build(mid+1,r,tree[pos].rs);
	return;
}
inline void down(int pos,int l,int r,int mid){
	tree[tree[pos].ls].sum+=tree[pos].tag*(mid-l+1);
	tree[tree[pos].rs].sum+=tree[pos].tag*(r-mid);
	tree[tree[pos].ls].tag+=tree[pos].tag;
	tree[tree[pos].rs].tag+=tree[pos].tag;
	tree[pos].tag=0;return;
}
inline void add(int l,int r,ull aw,int al,int ar,int pos){
	if(!aw)return;
	if(l>r)return;
	if(al<=l&&r<=ar){
		tree[pos].sum+=(r-l+1)*aw;tree[pos].tag+=aw;
	}else{
		int mid=(l+r)>>1;
		if(tree[pos].tag!=0)down(pos,l,r,mid);
		if(al<=mid)add(l,mid,aw,al,ar,tree[pos].ls);
		if(ar>mid)add(mid+1,r,aw,al,ar,tree[pos].rs);
		tree[pos].sum=tree[tree[pos].ls].sum+
		tree[tree[pos].rs].sum;
	}
	return;
}
inline ull query(int l,int r,int pos,int x){
	if(l>r)return 0;
	if(l==r)return tree[pos].sum;
	int mid=(l+r)>>1;
	if(tree[pos].tag!=0)down(pos,l,r,mid);
	ull ans=0;
	if(x<=mid)ans+=query(l,mid,tree[pos].ls,x);
	if(x>mid)ans+=query(mid+1,r,tree[pos].rs,x);
	tree[pos].sum=tree[tree[pos].ls].sum+
		tree[tree[pos].rs].sum;
	return ans;
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);

	read(n);read(m);
	build(1,n,1);
	rep(i,1,m){
		int l,r;long long s,e;
		read(l);read(r);read(s);read(e);
		ull temp=r-l;ull t1=e-s;
		if(l==r){
			add(1,n,s,l,l,1);add(1,n,-s,l+1,l+1,1);
		}else{
			ull nop=t1/temp;
			add(1,n,s,l,l,1);add(1,n,nop,l+1,r,1);
			if(r+1<=n)add(1,n,-e,r+1,r+1,1);
		}
	}
	long long ans=0;ull tx=0;
	rep(i,1,n){tx+=query(1,n,1,i);ans^=(long long)tx;}
	write(ans);
	return 0;
}
