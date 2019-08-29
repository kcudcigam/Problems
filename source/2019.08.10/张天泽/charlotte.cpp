#include<bits/stdc++.h>
using namespace std;
bool check(int t,int x,int y)
{
	int o;
	o=x+y;
	if  (o<=t && (t-o) %2 ==0 ) return true;
	else return false;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int x;
	cin>>x;
	for (int i=1;i<=x;i++)
	{
		int n;
		int k=1;
		cin>>n;
		for (int j=1;j<=n;j++)
		{
			bool p;
			int t,x,y;
			cin>>t>>x>>y;
			p=check(t,x,y);
			if (p==false) 
			{
				//cout<<"No"<<endl;
				k=0;
	//cout<<t<<x<<y<<endl;
			}
		
		}
			if (k==1) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
	 } 

	return 0;
}


