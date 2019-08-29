#include<bits/stdc++.h>
using namespace std;

int a[17000][2];
int vis[17000];

int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	int y;
	cin>>y;
	if(y==1) {cout<<"2 1"<<endl<<"1 2";return 0;}
	int n=3,m=0,tot=2;
	while(tot<y) tot*=2,n++;
	for(int i=1;i<n;i++)
	   for(int j=i+1;j<=n;j++)
	   {
	   	   m++;
	   	   a[m][0]=i;
	   	   a[m][1]=j;
	   }
	int ca=tot-y,sum=m;
	for(int i=sum;i>n;i--)
	{
		if(ca-a[i][0]+1>=0&&a[i][1]-a[i][0]>1)
		{
			vis[i]=true;
			ca=ca-a[i][0]+1;
			m--;
		}
		if(ca==0) break;
	}
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=sum;i++) 
	if(!vis[i]) cout<<a[i][0]<<" "<<a[i][1]<<endl;
	return 0;
}

