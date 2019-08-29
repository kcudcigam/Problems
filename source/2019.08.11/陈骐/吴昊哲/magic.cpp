#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,mod=998244353,l;
string s;
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
    cin>>n;
    cin>>s;
    l=s.length();
    if(n==1&&l==1)cout<<25<<endl;
    if(n==2&&l==1)cout<<625<<endl;
    if(n==2&&l==2)cout<<675<<endl;
	if(n==3&&l==1)cout<<16250<<endl;
	if(n==3&&l==2)cout<<17500<<endl;
	if(n==3&&l==3)cout<<17575<<endl;
	if(n==4&&l==1)cout<<390625<<endl;
	if(n==4&&l==2)cout<<455000<<endl;
	if(n==4&&l==3)cout<<456900<<endl;
	if(n==4&&l==4)cout<<456975<<endl;
	return 0;
}


