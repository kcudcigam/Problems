#include<bits/stdc++.h>
using namespace std;
long long n;
bool te=0;
int a[25];
int s[12];
int t,ans;
bool temp=1;
int chu(int x){
	int t=0;
	while(x>=10){
		a[++t]=x%10;
		x/=10;
		}
		a[++t]=x;
		return t;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>t;
while(t--){
	temp=1;
	ans=0;
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	cin>>n;
int len=chu(n);
	for(int i=1;i<=len;i++){
		s[a[i]]=1;
		}
		
	for(int i=0;i<=9;i++) ans+=s[i];
	if(ans<=2) cout<<1<<endl;
	else for(int j=1;j<=n/2;j++){
		int cnt=0;
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
int len=chu(j);
	for(int i=1;i<=len;i++){
		s[a[i]]=1;
		}
		
	for(int i=0;i<=9;i++) cnt+=s[i];
	//cout<<cnt<<"f1"<<endl;
	if(cnt<=2) te=1;
	if(te) {
		te=0;
		int cnt=0;
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
int len=chu(n-j);
	for(int i=1;i<=len;i++){
		s[a[i]]=1;
		}
		
	for(int i=0;i<=9;i++) cnt+=s[i];
//	cout<<cnt<<"f2"<<endl;
	if(cnt<=2) { cout<<2<<endl;temp=0;break;} 
	
	}
	}
	
 if (ans>2&&temp) cout<<3<<endl;
	}
	
	return 0;
}


