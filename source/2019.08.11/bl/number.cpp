#include<bits/stdc++.h>
#define ll long long
#define maxi 300000
#define pb push_back
using namespace std;
ll x;
int dp[maxi+10],t;
vector<int> no;
bool p1(int x){
	int p=x%10,q=-1;
	while (x){
		if (p!=x%10&&q!=x%10){if (q==-1)q=x%10;else return 0;}
		x/=10;
	}
	return 1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (int i=1;i<=maxi;i++){dp[i]=10;if (p1(i)){no.pb(i);dp[i]=1;}};
	for (int i=1;i<=maxi;i++)
		for (auto j:no){if (j>i||j+i>maxi)break;dp[j+i]=min(dp[j+i],dp[i]+1);}
	cin>>t;
	while (t--){
		cin>>x;
		cout<<dp[x]<<endl;
	}
    return 0;
}
