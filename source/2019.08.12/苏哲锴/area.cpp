#include<bits/stdc++.h>
#define N 1001
using namespace std;
bool f;
int ans;
int s[1000000];
int a[N];
int main(){
freopen("area.in","r",stdin);
freopen("area.out","w",stdout);
int x,y;
cin>>x>>y;
if(x==0||y==0) cout<<"infinity"<<endl,exit(0);
if(x%4==1&&y%2==0||y%4==1&&x%2==0) cout<<"infinity"<<endl,exit(0);
if(y%4==1&&x%4==1) ans=1,cout<<ans<<endl,exit(0);

int cnt=0;
int temp=1;
while(temp<max(x,y)){
  temp*=2;cnt++;
}
a[1]=1;a[2]=5;a[3]=20;s[1]=1;s[2]=6;s[3]=26;
//int twos[10000];
//twos[1]=1;
//for(int i=2;i<=n;i++) twos[i]=twos[i-1]*2;
for(int i=3;i<=cnt;i++){
	a[i]=(i-1)*(i-1)*4+a[i-1]-s[i-2];
	s[i]=s[i-1]+a[i];
	}
cout<<a[cnt]<<endl;

	return 0;
}


