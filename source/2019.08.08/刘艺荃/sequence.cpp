#include<bits/stdc++.h>
#define int long long 
using namespace std;
void read(int &x){
	int f=1,r=0;char ch;
	do ch=getchar(); while(!isdigit(ch)&&ch!='-');
	if(ch=='-'){f=-1;ch=getchar();}
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	x=f*r;
}
int n,m;
struct info{
	int l,r,sum,tag;
}a[500010];
int b[500010];
void push_up(int pos){
	a[pos].sum=a[pos*2].sum+a[pos*2+1].sum;
}
void push_down(int pos){
	if(!a[pos].tag)return ;
	a[pos*2].sum+=a[pos].tag*(a[pos*2].r-a[pos*2].l+1);
	a[pos*2+1].sum+=a[pos].tag*(a[pos*2+1].r-a[pos*2+1].l+1);
	a[pos*2].tag+=a[pos].tag;
	a[pos*2+1].tag+=a[pos].tag;
	a[pos].tag=0;
}
void build(int pos,int l,int r){
	a[pos].l=l,a[pos].r=r;
	if(l==r){a[pos].sum=0;return ;}
	int mid=(l+r)/2;
	build(pos*2,l,mid);
	build(pos*2+1,mid+1,r);
	//push_up(pos);
}
void modifyone(int pos,int p,int d){
	if(a[pos].l==a[pos].r){a[pos].sum+=d;return ;}
	int mid=(a[pos].l+a[pos].r)/2;
	if(p<=mid)modifyone(pos*2,p,d);
	else modifyone(pos*2+1,p,d);
	push_up(pos);
}
void modifys(int pos,int l,int r,int d){
	if(l<=a[pos].l&&r>=a[pos].r){
		a[pos].sum+=d*(a[pos].r-a[pos].l+1);
		a[pos].tag+=d;
		return ;
	}
	push_down(pos);
	int mid=(a[pos].l+a[pos].r)/2;
	if(l<=mid)modifys(pos*2,l,r,d);
	if(r>mid)modifys(pos*2+1,l,r,d);
	push_up(pos);
}
int query(int pos,int l,int r){
	if(l<=a[pos].r&&r>=a[pos].r)return a[pos].sum;
	push_down(pos);
	int mid=(a[pos].l+a[pos].r)/2;
	int res=0;
	if(l<=mid)res+=query(pos*2,l,r);
	if(r>mid)res+=query(pos*2+1,l,r);
	return res;
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);
	build(1,1,n+1);
	for(int i=1;i<=m;i++){
		int l,r,s,e;
		read(l);read(r);read(s);read(e);
		int gc=(e-s)/(r-l);
		modifyone(1,l,s);
		modifyone(1,r+1,-e);
		if(gc!=0)modifys(1,l+1,r,gc);
		for(int i=1;i<=n+1;i++){
			b[i]=query(1,1,i);
		}
	}
	int ans=b[1];
	for(int i=2;i<=n;i++){
		ans=ans^b[i];
	}
	cout<<ans<<endl;
	return 0;
} 
/*
5 2
1 5 2 10
2 4 1 1
*/
