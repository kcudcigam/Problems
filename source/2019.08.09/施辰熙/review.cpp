#include<bits/stdc++.h>
using namespace std;
long long Y,N,M,d[100],n,m,c,b,a[100];
vector <int> C[500000];
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin >> Y;
	d[0]=1;
	if (Y==1)
	{
		cout << "2 1" << endl;
		cout << "1 2" << endl;
		exit(0);
	}
	for (int i=1;i<=50;i++)
	{
		d[i]=d[i-1]*2;
		if (d[i]==Y)
		{
			m=0;
			n=i+2;
			cout << n << ' ' << (2+i)*(i+1)/2 << endl;
			for (int p=1;p<n;p++)
			{
				for (int q=p+1;q<=n;q++)
				{
					cout << p << ' ' << q << endl;
				}
			}
			exit(0);
		}
	}
	for (int i=51;i<=61;i++)
	{
		d[i]=d[i-1]*2;
	}
	for (int i=0;i<=60;i++)
	{
		if (d[i]<Y&&d[i+1]>Y)
		{
			n=i+2;c=Y;
			for (int p=1;p<n;p++)
			{
				for (int q=p+1;q<=n;q++)
				{
					C[p].push_back(q);
				}
			}
			n++;b=-1;
			while (c!=0)
			{
				b++;
				a[b]=c%2;
				if (a[b]==1)
				{
					C[b+2].push_back(n);
				}
				c/=2;
			}
			for (int p=1;p<n;p++)
			{
				for (int q=0;q<C[p].size();q++)
				{
					m++;
				}
			}
			cout << n << ' ' << m << endl;
			for (int p=1;p<n;p++)
			{
				for (int q=0;q<C[p].size();q++)
				{
					cout << p << ' ' << C[p][q] << endl;
				}
			}
		}
	}
 	return 0;
}
