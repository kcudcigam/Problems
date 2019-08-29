#include<bits/stdc++.h>
#define N 500010
#define ll long long
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
int n,m;
int a[N];
int b[N];
int f[N];
int tmp1,tmp2;
int search1(int x){
	int le=0,ri=n+1;
	while (le<ri-1){
		int mid=(le+ri)>>1;
		if (x>=b[mid]) le=mid;else ri=mid;
	}
	return le;
}
int search2(int x){
	int le=0,ri=n+1;
	while (le<ri-1){
		int mid=(le+ri)>>1;
		if (x>=a[mid]) le=mid;else ri=mid;
	}
	return le;
}
struct node{
	int maxn,tag;
};
node tr[N<<2];
void pushup(int i){
	tr[i].maxn=max(tr[i<<1].maxn,tr[i<<1|1].maxn);
	return;
}
void build(int i,int L,int R){
	if (L==R){
		tr[i].maxn=f[L];
		return;
	}
	int mid=(L+R)>>1;
	build(i<<1,L,mid);
	build(i<<1|1,mid+1,R);
	pushup(i);
	return;
}
void pushdown(int i){
	if (tr[i].tag){
		tr[i<<1].maxn+=tr[i].tag;
		tr[i<<1|1].maxn+=tr[i].tag;
		tr[i<<1].tag+=tr[i].tag;
		tr[i<<1|1].tag+=tr[i].tag;
		tr[i].tag=0;
	}
	return;
}
void change(int i,int L,int R,int idx,int s){
	if (L==R){
		tr[i].maxn=s;
		return;
	}
	pushdown(i);
	int mid=(L+R)>>1;
	if (idx<=mid) change(i<<1,L,mid,idx,s);
	else change(i<<1|1,mid+1,R,idx,s);
	pushup(i);
	return;
}
void add(int i,int L,int R,int ql,int qr,int s){
	if (L<=ql&&R>=qr){
		tr[i].maxn+=s;
		tr[i].tag+=s;
		return;
	}
	int mid=(ql+qr)>>1;
	if (L<=mid) add(i<<1,L,R,ql,mid,s);
	if (R>mid) add(i<<1|1,L,R,mid+1,qr,s);
	pushup(i);
	return;
}
pair<int,int> find(int i,int L,int R,int ql,int qr,int wl,int kth){
	if (ql==qr){
		pair<int,int> x;
		x.first=ql;
		x.second=tr[i].maxn;
		return x;
	}
	pushdown(i);
	pair<int,int> res;
	if (L<=ql&&R>=qr){
		int mid=(ql+qr)>>1;
		if (mid-L+1+tr[i<<1].maxn-wl+1>=kth) res=find(i<<1,L,R,ql,mid,wl,kth);
		else res=find(i<<1|1,L,R,mid+1,qr,wl,kth);
		pushup(i);
		return res;
	}
	int mid=(ql+qr)>>1;
	if (L<=mid&&mid-L+1+tr[i<<1].maxn-wl+1>=kth||R<=mid) res=find(i<<1,L,R,ql,mid,wl,kth);
	else res=find(i<<1|1,L,R,mid+1,qr,wl,kth);
	pushup(i);
	return res;
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	tmp1=1;
	while (tmp1<=n){
		while (tmp2<n&&b[tmp2+1]<a[tmp1]) tmp2++;
		f[tmp1]=tmp2;
		++tmp1;
	}
	build(1,1,n);
	while (m--){
		int opt;
		read(opt);
		if (opt==1){
			int x,y,z;
			read(x);read(y);read(z);
			if (!x){
				a[y]=z;
				change(1,1,n,y,search1(z-1));
			}
			else{
				int r=b[y];
				b[y]=z;
				if (r<z){
					int k1=search2(r)+1;
					int k2=search2(z);
					if (k1<=k2) add(1,k1,k2,1,n,-1);
				}
				else if (r>z){
					int k1=search2(z)+1;
					int k2=search2(r);
					if (k1<=k2) add(1,k1,k2,1,n,1);
				}
			}
		}
		else{
			int pl1,pr1,pl2,pr2;
			read(pl1);read(pr1);read(pl2);read(pr2);
			int t=(pr1-pl1+pr2-pl2+3)/2;
			int w=search2(b[pl2]);
			if (w>=pl1){
				if (w>=pr1){
					if (pr1-pl1+1>=t){
						printf("%d\n",a[pl1+t-1]);
						continue;
					}
					t-=pr1-pl1+1;
					printf("%d\n",b[pl2+t-1]);
					continue;
				}
				if (w-pl1+1>=t){
					printf("%d\n",a[pl1+t-1]);
					continue;
				}
				t-=w-pl1+1;
				pl1=w+1;
			}
			w=search2(b[pr2]);
			if (w<pl1){
				if (pr2-pl2+1>=t){
						printf("%d\n",b[t+pl2-1]);
						continue;
				}
				printf("%d\n",a[t-pr2+pl2+pl1-2]);
				continue;
			}
			if (pr2<n){
				w=search2(b[pr2+1]);
				if (w<pr1) pr1=w;
				if (pr1-pl1+pr2-pl2+2<t){
					t-=pr1-pl1+pr2-pl2+2;
					printf("%d\n",a[pr1+t]);
					continue;
				}
			}
			pair<int,int> ans=find(1,pl1,pr1,1,n,pl2,t);
			if (ans.first==pr1&&ans.first-pl1+ans.second-pl2+2<t) printf("%d\n",b[t-ans.first+pl1+pl2-2]);
			else if (ans.first-pl1+ans.second-pl2+2==t) printf("%d\n",a[ans.first]);
			else printf("%d\n",b[t-ans.first+pl1+pl2-1]);
		}
	}
	return 0;
}

