#include<bits/stdc++.h>
using namespace std;
int T,tot=0;
int a[20],s[1000010],ha[8000010];
bool pd(int x){
	int res=0;
	memset(a,0,sizeof(a));
	while(x){
		if(a[x%10]==0)res++;
		a[x%10]++;
		x/=10;
	}
	return res<=2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=300000;i++){
		if(pd(i)){
			s[++tot]=i;
		}
	}
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=tot;j++){
			int x=s[i]+s[j];
			ha[x]=1;
		}
	}
	cin>>T;
	for(int i=1;i<=T;i++){
		int x;cin>>x;
		if(pd(x))cout<<1<<endl;
		else if(x>8000000)cout<<3<<endl;
		else if(ha[x]==1)cout<<2<<endl;
		else cout<<3<<endl;
	}
	return 0;
}
/*
4
1818
23123
269105
21093203
*/
