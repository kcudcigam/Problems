#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[6005][6005]={0};
int b[6005]={0};
int s[6005]={0};
int r[6005]={0};
void check(int x)
{
	for (int i=1;i<=n;i++)
	{
		if (a[x][i]==1) 
		{
			s[i]=1;
			if (r[i]==0)check(i);
	    }
	    r[i]=1;
	}
}
int main(){
    freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);	
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		a[n][n]=1; 
	int flag;
	int x,y;
	for (int i=1;i<=q;i++)
	{
		cin>>flag>>x>>y;
		if (flag==1) 
		{
			a[x][y]=1;
			a[y][x]=1;
		}
		else
		{
		    for (int j=1;j>=n;j++)
		    s[j]=0;
		    for (int j=1;j>=n;j++)
		    r[j]=0;
			s[x]=1;
			check(x);
			for (int j=1;j<=n;j++)
			if (s[j]==1) b[j]+=y;
		}
	}
	for (int i=1;i<=n-1;i++)
		cout<<b[i]<<" ";
	cout<<b[n]<<endl;	
	return 0;
}


