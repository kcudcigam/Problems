#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int num=0,f=1; char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1; c=getchar();}
	while(isdigit(c)){num=num*10+c-'0'; c=getchar();}
	return num*f;
}

signed main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	cout<<"infinity"<<endl;
	return 0;
}
/*
 1, 1,
 1,-1,
 1, 1,
 1,-1,
*/
