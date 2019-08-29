#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
  int f=1;x=0;char c=getchar();
  for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
  for (; isdigit(c);c=getchar()) x=x*10+c-'0';
  x*=f;
}
int a[1000008],b[1000008]; 
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
    int n,m,i,j;
    cin>>n>>m;
    for (i=1;i<=n;i++)
      a[i]=i;
    for (i=1;i<=m;i++)
	{
	  int k,x,y,z;
	  read(k);read(x);read(y);
	  if (k==1) {
	  	z=a[y];
	  	for (j=1;j<=n;j++)
	  	  if (a[j]==z) a[j]=a[x];
	  }
	  if (k==2)
	  {
	  	for (j=1;j<=n;j++)
	      if (a[j]==a[x])  b[j]=b[j]+y;	
	  }	
	}    
	for (i=1;i<n;i++)
	  cout<<b[i]<<" ";
	cout<<b[n]<<endl;																			
	return 0;
}


