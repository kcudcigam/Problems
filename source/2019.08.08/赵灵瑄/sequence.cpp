#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
  int f=1;x=0;char c=getchar();
  for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
  for (; isdigit(c);c=getchar()) x=x*10+c -'0';
  x*=f;
}
long long n,m,l,r,s,e,t,ans;
long long a[500005];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    read(n);
    read(m);
    for(int i=1;i<=m;i++){
    	cin>>l>>r>>s>>e;
    	a[l]=a[l]+s;
    	a[r]=a[r]+e;
    	t=(e-s)/(r-l);
    	for(int j=l+1;j<=r-1;j++)
    	   a[j]=a[j]+s+t*(j-l);
	}
	ans=a[1];
	for(int i=2;i<=n;i++)
		ans=ans^a[i];
	cout<<ans<<endl;
	return 0;
}


