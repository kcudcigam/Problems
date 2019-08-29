#include<bits/stdc++.h>
#define MAXN 500010
using namespace std;

template <typename T> void read(T &x){
	x=0;char ch=getchar();T f=0;
	for (;!isdigit(ch);ch=getchar())	f|=ch=='-';
	for (;isdigit(ch);ch=getchar())	x=(x<<3)+(x<<1)+(ch^48);
	x=f?-x:x;
}

int a[MAXN],b[MAXN];
int n,m;

int get(int x,int l,int r){
	int ll=l,rr=r;
	while (ll<rr){
		int mid=(ll+rr)>>1;
		if (b[mid]<x)	ll=mid+1;
			else rr=mid;
	}
	return ll-1;
}

int getA(int x,int l,int r){
	int ll=l,rr=r;
	while (ll<rr){
		int mid=(ll+rr)>>1;
		if (a[mid]<x)	ll=mid+1;
			else rr=mid;
	}
	return ll-1;
}

int findB(int l1,int r1,int l2,int r2){
	int mid=(r1-l1+r2-l2+2)/2+1;
	int ll=l2,rr=r2;
	int pla;
	int mi;
	while (ll<rr){
		mi=(ll+rr)>>1;
		pla=getA(b[mi],l1,r1);
		if (pla-l1+mi-l2+2==mid)	break;
		if (pla-l1+mi-l2+2<mid)	ll=mi+1;
			else rr=mi;
	}
	return b[mi];
}

int find(int l1,int r1,int l2,int r2){
	int mid=(r1-l1+r2-l2+2)/2+1;
	if (a[r1]<b[l2]){
		if (r1-l1+1>=mid)	return a[l1+mid-1];
		return b[mid-r1+l1+l2-2];
	}
	if (a[l1]>b[r2]){
		if (r2-l2+1>=mid)	return b[l2+mid-1];
		return a[mid-r2+l2+l1-2];
	}
	int ll=l1,rr=r1;
	bool f=false;
	int pla;
	int mi;
	while (ll<rr){
		mi=(ll+rr)>>1;
		pla=get(a[mi],l2,r2);
		if (pla-l2+mi-l1+2==mid){f=true;break;}
		if (pla-l2+mi-l1+2<mid)	ll=mi+1;
			else rr=mi;
	}
	if (f)	return a[mi];
	return findB(l1,r1,l2,r2);
}

int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n;++i)	read(a[i]);
	for (int i=1;i<=n;++i)	read(b[i]);
	while (m--){
		int x;
		read(x);
		if (x==1){
			int y,z;
			read(x);read(y);read(z);
			if (x==0)	a[y]=z;
				else b[y]=z;
		}
		else {
			int l1,r1,l2,r2;
			read(l1);read(r1);read(l2);read(r2);
			printf("%d\n",find(l1,r1,l2,r2));
		}
	}
	return 0;
}
