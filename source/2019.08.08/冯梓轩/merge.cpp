#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar())if (c=='-') f=-f;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n,q,x,y,z;
	read(n);
	read(q);
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=1;i<=q;i++){
		read(x);
		read(y);
		read(z);
		if(x==1){
			if(a[y]==a[z])continue;
			for(int j=1;j<=n;j++){
				if(a[j]==a[z])a[j]=a[y];
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(a[j]==a[y])b[j]+=z;
			}
		}
	}
	for(int i=1;i<n;i++)cout<<b[i]<<' ';
	cout<<b[n]<<endl;
	return 0;
}
