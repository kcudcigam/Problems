#include<bits/stdc++.h>
using namespace std;
int ri() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int n,m;
int a[500011],b[500010];
priority_queue<int>sg;
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=ri();
	m=ri();
	for(int i=1;i<=n;i++){
		a[i]=ri();
	}
	for(int i=1;i<=n;i++){
		b[i]=ri();
	}
	for(int i=1;i<=m;i++){
		int cz;
		cz=ri();
		if(cz==1){
			int x,y,z;
			x=ri();
			y=ri();
			z=ri();
			if(x==0){
				a[y]=z;
			}else{
				b[y]=z;
			}
		}else{
			int l,r,ll,rr;
			l=ri();
			r=ri();
			ll=ri();
			rr=ri();
			int t=(r-l+1)+(rr-ll+1);
			for(int j=l;j<=r;j++){
				sg.push(a[j]);
			}
			for(int j=ll;j<=rr;j++){
				sg.push(b[j]);
			}
			int tt=0;
			while(!sg.empty()){
				tt++;
				if(tt==(t+1)/2){
					cout<<sg.top()<<endl;
				}
				sg.pop();
			}
		}
	}
	return 0;
}


