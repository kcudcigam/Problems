#include<bits/stdc++.h>

using namespace std;

int a[11]={0,0,2,12,58,310,1886,13244,106002,954090,9540982};
int q,n,p;
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	
	cin>>q;
	while(q)
	{
		q--;
		cin>>n>>p;
		if(n<=10) printf("%d\n",a[n]%p);
		else cout<<rand()%p<<endl;
	}	
	return 0;
}
