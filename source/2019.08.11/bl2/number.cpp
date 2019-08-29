#include<bits/stdc++.h>
#define ll long long
#define maxi 10000000000000ll
#define pb push_back
using namespace std;
ll x;
int t;
vector<ll> no,n1;
bool p1(ll x){
	int p=x%10,q=-1;
	while (x){
		if (p!=x%10&&q!=x%10){if (q==-1)q=x%10;else return 0;}
		x/=10;
	}
	return 1;
}
void make(ll p,int x,int y){
	if (p<=maxi){
		no.pb(p);
		if (p!=0||x!=0)make(p*10+x,x,y);
		if (p!=0||y!=0)make(p*10+y,x,y);
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (int i=0;i<9;i++)
		for (int j=i+1;j<=9;j++)make(0,i,j);
	sort(no.begin(),no.end());
	cin>>t;
	while (t--){
		cin>>x;
		int an=3;
		if (p1(x)) an=1;
		else for (int i=0;i<no.size()&&no[i]*2<=x;i++)if (p1(x-no[i])){an=2;break;}
		cout<<an<<endl;
	}
    return 0;
}
