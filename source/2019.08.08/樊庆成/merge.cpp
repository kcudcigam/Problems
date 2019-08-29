#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
for (; isdigit(c);c=getchar()) x=x*10+c -'0';
x*=f;
}
int n;
int q;
int main(){
	read(n);
	read(q);
	int a[n][2];
	for(int i=0;i<n;i++){
		a[i][0]=i;
		a[i][1]=0;
	}
	for(int i=1;i<=q;i++){
		int s,x,y;
		cin>>s>>x>>y;
		if(s==1){
			a[x-1][0]=a[y-1][0];
		}
		else{
			for(int j=0;j<n;j++){
				if(a[j][0]==a[x-1][0]){
					a[j][1]+=y;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i][1]<<" ";
	}
	return 0;
}

