#include<iostream>
using namespace std;
int x,y;
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	cin>>x>>y;
	if(x%4==0||y%4==0)
	{
		cout<<"infinity"<<endl;
		return 0;
	}
	return 0;
}
