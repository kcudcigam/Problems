#include<bits/stdc++.h>
using namespace std;
int hh[555555];
int cc[555555];
template <typename T> void read(T &x){
	int f=1;
	x=0;
	char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
    freopen("merge.in","r",stdin);
    freopen("merge.out","w",stdout);
	int n,Q;
	read(n);
	read(Q);
	for (int i=1;i<=n;i++){
		hh[i]=i;
	}
	memset(cc,0,sizeof(cc));
	for (int i=1;i<=n;i++){
		int q,x,y;
		read(q);
		read(x);
		read(y);
		if (q==1){
			for (int j=1;j<=n;j++){
				if (hh[j]=y){
					hh[j]=x;
				}
			}
		}
		else {
			for (int j=1;j<=n;j++){
				if (hh[j]==hh[x]){
					cc[j]+=y;
				}
			}
		}
	}
	for (int i=1;i<n;i++){
		cout<<cc[i]<<endl;
	}
	cout<<cc[n]<<endl;
	return 0;
}


