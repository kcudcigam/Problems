#include<bits/stdc++.h>
using namespace std;
int n,a[500],b[500],c[500],d[10000005],e[10000005],la[40000007],m,i,x,y,z,s,h[500];
struct node{
	int x,y;
}f[40000007];
int ks(int p,int n)
{
	if (n==1) return p;
	else return p*ks(p,n-1);
}
void build(int p,int l,int r)
{
	if (l==r) {
	f[p].x=e[l];
	f[p].y=l;
    }
	else {
		int mid=(l+r)/2;
		build(p*2,l,mid);
		build(p*2+1,mid+1,r);
		if (f[p*2].x>f[p*2+1].x) {
			f[p].x=f[p*2].x;
			f[p].y=f[p*2].y;
		}
		else {
			f[p].x=f[p*2+1].x;
			f[p].y=f[p*2+1].y;
		}
	}
}
void ox(int p,int k)
{
	f[p].x-=k;
	la[p]+=k;
}
void lanbiao(int p)
{
	ox(p*2,la[p]);
	ox(p*2+1,la[p]);
	la[p]=0;
}
void ad(int p,int l,int r,int ll,int rr)
{
	if (l==ll&&r==rr) {
		f[p].x--;
		la[p]++;
   }
   else {
   	lanbiao(p);
   	int mid=(l+r)/2;
	 if (rr<=mid) ad(p*2,l,mid,ll,rr);
	 else if (ll>mid) ad(p*2+1,mid+1,r,ll,rr);
	 else {
	 	ad(p*2,l,mid,ll,mid);
	 	ad(p*2+1,mid+1,r,mid+1,rr);
	 } 
	 if (f[p*2].x>f[p*2+1].x) {
			f[p].x=f[p*2].x;
			f[p].y=f[p*2].y;
		}
		else {
			f[p].x=f[p*2+1].x;
			f[p].y=f[p*2+1].y;
		}
   }
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
    cin>>n>>m;
    for (i=1;i<=5;i++)
    cin>>a[i];
    for (i=1;i<=n;i++)
    {
    	cin>>b[i]>>c[i];
	}
	for (i=1;i<=n;i++)
	{
			d[b[i]]++;
			d[c[i]+1]--;
	}
	z=0;
	for (i=1;i<=m;i++)
	{
		z+=d[i];
		e[i]=z;
	}
	build(1,1,m);
	x=n;
	while (x!=0) {
		y=f[1].x; z=f[1].y;
	    for (i=1;i<=5;i++)
	    s+=ks(y,i)*a[i];
	    for (i=1;i<=n;i++)
	    {  
		if (b[i]<=z&&z<=c[i]&&h[i]==0) {
		h[i]=1;
		ad(1,1,m,b[i],c[i]);
		x--;
	     }
	    }
	}
	cout<<s<<endl;
	return 0;
}


