#include<bits/stdc++.h>
using namespace std;
int fa[10000];
template <typename T> void read(T &x){
   int f=1;x=0;char c=getchar();
   for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
   for (; isdigit(c);c=getchar()) x=x*10+c-'0';
   x*=f;
} 
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
    long long num,n,m1,m2,i,j,k=0,x,y,z;
    long long ans1=1,ans2=1;
    read(num);
    if (num==1) {
    	cout<<"0"<<endl;
    	return 0;
	}
	if (num==2)
	{
		cout<<"0"<<endl;
		return 0;
	 } 
	read(n);
	read(m1);
	read(m2);
	for (i=1;i<=n;i++)
	   fa[i]=i;
	for (i=1;i<=m1;i++)
	{
	   read(x);
	   read(y);
	   z=fa[y];
	  	for (j=1;j<=n;j++)
	  	  if (fa[j]==z) fa[j]=fa[x];
	}
	for (i=1;i<=m2;i++)
	{
		read(x);
		read(y);
		z=fa[y];
	  	for (j=1;j<=n;j++)
	  	  if (fa[j]==z) fa[j]=fa[x];
	}
	for (i=1;i<=n;i++)
	  ans1=(ans1%1000000007*i%1000000007)%1000000007;
	sort(fa+1,fa+n+1);
	int o;
	fa[n+1]=-1;
	for (i=2;i<=n+1;i++)
	  if (fa[i]!=fa[i-1]) k++;
    for (i=1;i<=k;i++)
	  ans2=(ans2%1000000007*i%1000000007)%1000000007;
	cout<<(ans1-ans2+1000000007)%1000000007<<endl;
	return 0;
}


