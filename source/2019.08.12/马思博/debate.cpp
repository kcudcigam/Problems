#include<bits/stdc++.h>
using namespace std;

int f[400005][4],infmt[400005][2],w[400005];

int main()
{
    freopen("debate.in","r",stdin);
    freopen("debate.out","w",stdout);
    int n,a;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>s;
    	infmt[i][0]=s[0]-'0';
    	infmt[i][1]=s[1]-'0';
    	cin>>w[i];
	}
	f[1][0]=w[1];f[1][1]=infmt[1][0];f[1][2]=infmt[1][1];f[1][3]=1;
	for(int i=2;i<=n;i++)
	{
		int x=infmt[i][0],y=infmt[i][1];
		for(int j=1;j<i;j++)
		  if((f[j][1]+x)>=(f[j][3]+2)/2&&
		     (f[j][2]+y)>=(f[j][3]+2)/2&&
			  f[j][0]+w[i]>f[i][0])
		  {
		  	  f[i][0]=f[j][0]+w[i];
		  	  f[i][1]=f[j][1]+x;
		  	  f[i][2]=f[j][2]+y;
		  	  f[i][3]=f[j][3]+1;
		  }   
	}
	//for(int i=1;i<=n;i++) cout<<f[i][0]<<" "<<f[i][1]<<" "<<f[i][2]<<" "<<f[i][3]<<endl;
	cout<<f[n][0];
	return 0;
}


