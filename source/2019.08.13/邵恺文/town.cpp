#include<bits/stdc++.h>
using namespace std;
template <typename _T> inline _T read(_T &x){
	char ch=getchar();int minus=0;x=0;
	while(ch^'-'&&!isdigit(ch))ch=getchar();
	if(ch=='-'){
		minus=1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	if(minus)return -x;
	return x;
}
int n;
const int maxn=300000;
int f[maxn],h[2005][2005];
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	read(n);
	for(int i=1;i<=n-1;i++){
		int x,y;
		read(x);read(y);
		h[x][y]=h[y][x]=1;
		if(i==1){
			cout<<1<<endl;
			f[x]=f[y]=1;
			continue;
		}
		int t1=max(f[x],f[y]+1);
		int t2=max(f[x]+1,f[y]);
		int ans=0;
		ans=max(f[x]+f[y]+1,t2);
		f[x]=t1;f[y]=t2;
		cout<<max(ans,t1)<<endl;
	}
	return 0;
}


