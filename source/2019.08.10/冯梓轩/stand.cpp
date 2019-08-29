#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,z;
}a[300];
long long g[6],b[300000],c[300000],x=0;
bool cmp(node a,node b){
	if(a.l!=b.l)return a.l<b.l;
	return a.r<b.r;
}
long long f(long long q){
	return g[1]*q+g[2]*q*q+g[3]*q*q*q+g[4]*q*q*q*q+g[5]*q*q*q*q*q;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n,m,ma,h,ml=1,mr;
	cin>>n>>m;
	mr=m;
	for(int i=1;i<=5;i++)cin>>g[i];
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		ml=max(ml,a[i].l);
		mr=min(mr,a[i].r);
	}
	if(ml<=mr){
		cout<<f(n)<<endl;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	m=a[n].r;
	for(int i=1;i<=n;i++){
		ma=0;
		for(int j=1;j<=n;j++){
			if(a[j].z!=0&&(a[j].z<a[i].l||a[j].z>a[i].r))continue;
			if(a[j].r<a[i].l)continue;
			if(a[j].l>a[i].r)break;
			for(int k=max(a[i].l,a[j].l);k<=min(a[i].r,a[j].r);k++)b[k]++;
		}
		for(int j=a[i].l;j<=a[i].r;j++){
			if(b[j]>ma){
				ma=b[j];
				h=j;
			}
		}
		a[i].z=h;
		c[h]++;
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)x+=f(c[i]);
	cout<<x<<endl;
	return 0;
}
