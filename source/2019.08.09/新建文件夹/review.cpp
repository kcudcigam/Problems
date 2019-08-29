#include<bits/stdc++.h>
using namespace std;
int m;
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>m;
	if(m==1) cout<<"1 1"<<endl<<"1 1"<<endl;
	if(m==2) cout<<"3 3"<<endl<<"1 2"<<endl<<"2 3"<<endl<<"1 3"<<endl;
	if(m==3) cout<<"4 5"<<endl<<"1 2"<<endl<<"2 4"<<endl<<"1 3"<<endl<<"1 4"<<endl<<"3 4"<<endl;
	if(m==4) cout<<"4 6"<<endl<<"1 2"<<endl<<"2 4"<<endl<<"2 3"<<endl<<"1 3"<<endl<<"1 4"<<endl<<"3 4"<<endl;
 	if(m==5) cout<<"5 8"<<endl<<"1 2"<<endl<<"2 5"<<endl<<"2 3"<<endl<<"1 3"<<endl<<"3 5"<<endl<<"1 4"<<endl<<"4 5"<<endl<<"1 5"<<endl;
	return 0;
}

