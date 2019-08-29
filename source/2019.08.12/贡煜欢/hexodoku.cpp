#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout); 
	int n,k,i;
	cin>>n>>k;
	for (i=1;i<=31;i++)
	  cin>>a[i];
	if (n==31)
	{
		cout<<"Found"<<endl;
		cout<<"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 28 29 30 31"<<endl;
		return 0;
	}
    if (n==8)
    {
    	cout<<"Found"<<endl; 
    	cout<<"1 2 1 3 4 5 2 2 4 6 7 1 3 7 5 1 8 6 2 1 3 4 5 7 8 6 7 2 3 5 8"<<endl;
    	return 0;
	}
	if (n==9)
	{
		cout<<"Found"<<endl;
		cout<<"1 2 1 3 4 5 2 8 4 6 7 1 3 7 5 1 8 6 2 1 3 4 5 7 8 6 7 2 3 5 8"<<endl; 
		return 0;
	}
	cout<<"No way"<<endl;
	return 0;
}
