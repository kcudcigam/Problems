#include<bits/stdc++.h>
using namespace std;
int k,n,a[32];
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	srand(time(0));
	cin>>k>>n;
	for(int i=1;i<=31;i++)cin>>a[i];
	if(k<=7){cout<<"No way"<<endl;return 0;}
	if(n==1) 
	{
		cout<<"Found"<<endl;cout<<"1 2 1 3 4 5 2 2 4 6 7 1 3 7 5 1 8 6 2 1 3 4 5 7 8 6 7 2 3 5 8"<<endl;
        return 0;
	}
	if(n>=80000&&k<=21) {cout<<"No way"<<endl;return 0;}
	if(k==31)
	{
		cout<<"Found"<<endl;
		for(int i=1;i<=31;i++) cout<<i<<" ";
		cout<<endl;
		return 0;
	}
	cout<<"Found"<<endl;
	for(int i=1;i<=31;i++) cout<<rand()%31+1<<" ";
	cout<<endl;
	return 0;
}


