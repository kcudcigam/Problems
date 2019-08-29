#include<bits/stdc++.h>
using namespace std;
pair<int,int> pa[64005];
int main()
{
   freopen("review.in","r",stdin);
   freopen("review.out","w",stdout);
	long long a;
	cin>>a;
	int pig=0;
	for(int i=2;i<=64;i++)
		for(int j=i+1;j<=64;j++)
			{
				pig++;
				pa[pig].first=i;
				pa[pig].second=j;
			}
	int TIme=64;
	while(TIme--)
		{
			if(a&1)
				{
					pig++;
					pa[pig].first=1;
					pa[pig].second=TIme;
				}
			a>>=1;
		}
	cout<<64<<" "<<pig<<endl;
	for(int i=1;i<=pig;i++) cout<<pa[i].first<<" "<<pa[i].second<<endl; 
	return 0;
}


