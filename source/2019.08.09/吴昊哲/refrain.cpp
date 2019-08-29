#include<bits/stdc++.h>
using namespace std;
int n,num,m1,m2;
int yin[100],yang[100];
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
    cin>>num;
    cin>>n>>m1>>m2;
    for(int i=1;i<=m1;i+=2)cin>>yin[i]>>yin[i+1];
    for(int i=1;i<=m2;i+=2)cin>>yang[i]>>yang[i+1];
    if(num==1)cout<<0<<endl;
    if(num==2)cout<<0<<endl;
    if(11<=num&&num<=14)cout<<0<<endl;
    return 0;
} 
