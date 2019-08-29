#include<bits/stdc++.h>
using namespace std;
long long i,n,m,j,a[500005],ans,l,r,s,e,k;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
} 
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>l>>r>>s>>e;
		k=(e-s)/(r-l);
		a[l]+=s;
		for (j=l+1;j<=r;j++)
		{
			s+=k;
			a[j]+=s;
		}
	}
	ans=a[1];
	for (i=2;i<=n;i++)
	ans=(ans^a[i]);
	cout<<ans<<endl;
	return 0;
}


