#include<bits/stdc++.h>
using namespace std;
int ans[11]={0,0,2,12,58,310,1886,13244,106002,954090,9540982},q,p,n;
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	cin>>q;
	while(q--)
	{
		cin>>n>>p;
		cout<<ans[n]%p<<endl;
	}
	return 0;
}
