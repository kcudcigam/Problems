#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int a[1010],b[1010];
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int n,m;
	read(n);read(m);
	
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++){
		read(b[i]);
	}
	for(int i=1;i<=m;i++){
		int tem;
		read(tem);
		if(tem==1){
			int x,y,z;
			read(x);read(y);read(z);
			if(x==0){
				a[y]=z;
			}else{
				b[y]=z;
			}
		}else{
			int l,r,x,y;
			read(l);read(r);read(x);read(y);
			if(a[r]<=b[x]){
				if(r-l+1<y-x+1){
					cout<<b[((r+y)-(l+x)+2)/2-r+l+x]<<endl;
				}else{
					cout<<a[((r+y)-(l+x)+2)/2+l]<<endl;
				}
			}else if(a[l]>=b[y]){
				if(r-l+1>y-x+1){
					cout<<a[((r+y)-(l+x)+2)/2-y+x+l]<<endl;
				}else{
					cout<<b[((r+y)-(l+x)+2)/2+x]<<endl;
				}
			}else{
				vector<int>v;
				for(int i=l;i<=r;i++){
					v.push_back(a[i]);
				}
				for(int i=x;i<=y;i++){
					v.push_back(b[i]);
				}
				sort(v.begin(),v.end());
				cout<<v[v.size()/2]<<endl;
			}
		}
	}
	return 0;
}


