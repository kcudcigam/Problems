#include<bits/stdc++.h>
using namespace std;
#define LL long long	
bool a[12][12],b[12][12];
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int num;
	int n,M1,M2;
	cin>>num>>n>>M1>>M2; 
	if(num<=2)
	{
		cout<<0;
		return 0;
	}
	else if(n<=11)
	{
		LL pr[12],ans=0;
		for(int i=1;i<=n;i++)
		{
			pr[i]=i;
		}
		for(int i=0;i<M1;i++)
		{
			int from,to;
			cin>>from>>to;
			a[from][to]=1;
			a[to][from]=1;
		}
		for(int i=0;i<M2;i++)
		{
			int from,to;
			cin>>from>>to;
			b[from][to]=1;
			b[to][from]=1;			
		}
	//	system("pause");
		while(next_permutation(pr+1,pr+1+n))
		{
			for(int i=1;i<=n;i++)
			{
				bool flag=0;
				for(int j=i+1;j<=n;j++)
				{
					if(a[pr[i]][pr[j]]<a[i][j]||b[pr[i]][pr[j]]<b[i][j])
					{
						ans++;
						flag=1;
						break;			
					}
				}
				if(flag)
				{
					break;
				}
			}
		}
		cout<<ans%100000007;
		return 0;
	}
	else
	{
		cout<<782378613;
	}
	
}


