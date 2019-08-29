#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
    a[1]=0;
    a[2]=2;
    a[3]=12;
    a[4]=58;
    a[5]=310;
    a[6]=1886;
    a[7]=13244;
    a[8]=106002;
    a[9]=954090;
    a[10]=9040982;
    int n,m,i,x,y;
    cin>>n;
    for (i=1;i<=n;i++)
    {
    	cin>>x>>y;
    	cout<<a[x]%y<<endl;
	}
	return 0;
}


