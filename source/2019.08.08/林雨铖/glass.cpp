#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,a[1000000];
int main()
{
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	a[1]=n;
	for (int i=2;;i++)
	{
		if (a[i-1]==1)
		break;
		a[i]=a[i-1]>>1;
		n-=a[i];
		a[i-1]%=2;
	}
	//cout<<n<<endl;
	if (n>k)
	{
		for (;;)
		{
			if (n<=k)
				break;
			ans++;a[1]++;n++;
			for (int i=2;;i++)
			{
				//for (int j=1;j<=5;j++)
			//	cout<<a[j]<<' ';
			//	cout<<n<<' '<<ans<<endl;
				if (a[i-1]==1)
					break;
				if (a[i-1]==2)
				{
					a[i]++;
					n--;
					a[i-1]=0;
				}
				//for (int j=1;j<=5;j++)
				//cout<<a[j]<<' ';
				//cout<<n<<' '<<ans<<endl;
			}
			//cout<<endl;
			//if (ans>4)
			//break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

