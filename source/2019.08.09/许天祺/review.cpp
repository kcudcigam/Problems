#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,tot,i,nod=1,x[50005],y[50005];
signed main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>n;
	nod=1;
	while(n)
	{
		i++;
		if (n%2==1)
		{
			tot++;
			x[tot]=1;y[tot]=nod+1;
			for(int j=nod+1;j<=nod+i+1;j++)
				for(int k=j+1;k<=nod+i+1;k++)
				{
					tot++;
					x[tot]=j;y[tot]=k;
				}
			tot++;
			x[tot]=nod+i+1;y[tot]=0;
			nod+=i+1;
		}
		n/=2;
	}
	cout<<nod+1<<" "<<tot<<endl;
	for(int i=1;i<=tot;i++)
	{
		cout<<x[i]<<" ";
		if (y[i]==0) cout<<nod+1;
		else cout<<y[i];
		cout<<endl;
	}
	return 0;
} 
