#include<bits/stdc++.h>
using namespace std;
int x1,x2,z1,z2,mi,l,r,ans,k,y,a[600000],b[600000],n,m,i,c,x,z;
int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int ch1(int p)
{
	int l=z1,r=z2,ans=z1-1,mi;
	while (l<=r) {
		mi=(l+r)/2;
		if (a[p]>b[mi]) {
			ans=mi;
			l=mi+1;
		}
		else r=mi-1;
	}
	return (p-x1+ans-z1+1);
}
int ch2(int p)
{
	int l=z1,r=z2,ans=z1-1,mi;
	while (l<=r) {
		mi=(l+r)/2;
		if (a[p]>=b[mi]) {
			ans=mi;
			l=mi+1;
		}
		else r=mi-1;
	}
	return (p-x1+ans-z1+1);
}
int ch3(int p)
{
	int l=x1,r=x2,ans=x1-1,mi;
	while (l<=r) {
		mi=(l+r)/2;
		if (b[p]>a[mi]) {
			ans=mi;
			l=mi+1;
		}
		else r=mi-1;
	}
	return (p-z1+ans-x1+1);
}
int ch4(int p)
{
	int l=x1,r=x2,ans=x1-1,mi;
	while (l<=r) {
		mi=(l+r)/2;
		if (b[p]>=a[mi]) {
			ans=mi;
			l=mi+1;
		}
		else r=mi-1;
	}
	return (p-z1+ans-x1+1);
}
int main(){
  freopen("median.in","r",stdin);
  freopen("median.out","w",stdout);
  cin>>n>>m;
  for(i=1;i<=n;i++)
  a[i]=ri();
  for (i=1;i<=n;i++)
  b[i]=ri();
  for (i=1;i<=m;i++)
  {
  	c=ri();
  	if (c==1) {
  		x=ri(); y=ri(); z=ri();
  		if (x==0) a[y]=z;
  		else b[y]=z;
	  }
	  else {
	  	x1=ri(); x2=ri();z1=ri();z2=ri();
	  	ans=-1;
	  	k=(x2-x1+1+z2-z1+1)/2;
		l=x1; r=x2;
		while (l<=r) {
			mi=(l+r)/2;
			if (ch1(mi)>k) {
				r=mi-1;
			}
			else if (ch2(mi)<k) {
			l=mi+1;
		   }
			else {
			ans=a[mi];
			break;
		    }
		}   
		if (ans==-1) {
		l=z1; r=z2;
		while (l<=r) {
			mi=(l+r)/2;
			if (ch3(mi)>k) {
				r=mi-1;
			}
			else if (ch4(mi)<k) l=mi+1;
			else {
			ans=b[mi];
			break;
		    }
		}   
		} 
		cout<<ans<<endl;
	  }
  }
  return 0;
}


