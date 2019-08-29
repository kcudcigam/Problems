#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,l1,r1,l2,r2,mid,k1,k2,k;
int ans,a[500000],b[500000],z;
int read(){
    char c=getchar(); 
    int x=0; 
    for (;c<'0'||c>'9';c=getchar());
    for (;c>='0'&&c<='9';c=getchar()) 
	    x=x*10-'0'+c; 
	return x;
}
int main(){
	freopen("mediam.in","r",stdin);
	freopen("mediam.out","w",stdout);
	
	n=read();m=read();
	for (int i=1;i<=n;i++)
	   a[i]=read();
	for (int i=1;i<=n;i++)
	   b[i]=read();
	for (int i=1;i<=m;i++){
		k=read();
		if (k==1){
			x=read();
			y=read();
			z=read();
			if (x==0) a[y]=z;
			else b[y]=z;
		}
		else{
			l1=read();
			r1=read();
			l2=read();
			r2=read();
			mid=(r1-l1+r2-l2+3)/2;
			k1=l1;k2=l2;
			ans=0;
			for (int j=1;j<=mid;j++){
				if (a[k1]<b[k2]&&k1<=r1) ans=a[k1],k1++;
				else if (a[k1]>=b[k2]&&k2<=r2) ans=b[k2],k2++;
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}

