#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
char a[1000010];
long long po(long long x,long long m){
	if(m==0)return 1;
	long long t=po(x,m/2);
	if(m%2)return ((t*t)%md*x)%md;
	return (t*t)%md;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	char ch,y;
	long long n,s=0,t,x=0,g=1;
	cin>>n;
	while(cin>>ch){
		if(islower(ch)==0)break;
		a[x]=ch;
		x++;
		if(x!=1){
			if(a[x-2]==a[x-1])g++;
			else{
				s+=g;
				g=1;
			}
		}
	}
	s=(s+g)%md;
	s=(s+po(26,n))%md;
	t=(po(26,n-x)*(x+1))%md;
	s=(s+md-t)%md;
	cout<<s<<endl;
	return 0;
} 
