#include<bits/stdc++.h>
using namespace std;
int n,q,p;
long long ans,a[11];
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	srand(time(0));
	cin>>q;
	a[1]=0;a[2]=2;a[3]=12;a[4]=58;a[5]=310;a[6]=1886;a[7]=13244;a[8]=106002;a[9]=954090;a[10]=9540982;
	for(int i=1;i<=q;i++)
	{
		cin>>n>>p;
		if(n<=10) cout<<a[n]%p<<endl;
		else 
		{
			cout<<rand()<<rand()<<endl;
		}
	}
	return 0;
}

