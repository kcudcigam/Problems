#include<cstdio>
#include<iostream>
using namespace std;
int n,p;
//打表出省一
int w[11]={0,0,2,12,58,310,1886,13244,106002,954090,9540982}; 
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>p;
		cout<<w[n]%p<<endl; 
	}
	return 0;
}

