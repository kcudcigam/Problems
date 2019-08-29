#include<bits/stdc++.h>
#define LL long long 
#define mid (l+r>>1)
#define pb push_back
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
bool y[17][17][17][17];
int n,w[17],a[17],ans;
bool check(int a1,int a2,int a3,int a4){
	memset(y,0,sizeof y);
//	cout<<1;
	a[1]=a1; a[2]=a2; a[3]=a3; a[4]=a4;
	while (1){
		bool flag=0;
//		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<"\n";
		if (y[a[1]][a[2]][a[3]][a[4]]) {
//			cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<"  fk\n";
//			system("pause");
			return 1;
		}
		y[a[1]][a[2]][a[3]][a[4]]=1;
		for (int i=1;i<=4;i++){
			if (a[i]) a[i]--;
			else continue;
			if (a[i]) {
				for (int j=1;j<=4;j++) if (!a[j]) {
					a[j]=w[a[i]];
					break;
				}
			}
			else flag=1;
		}
//		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" - "<<flag<<"\n";
		if (!flag || a[1]+a[2]+a[3]+a[4]==0) return 0;
	}
	return 0;
}
int main(){
	freopen("bob.in","r",stdin);
	freopen("bob.out","w",stdout);
	n=read();
	for (int i=1;i<n;i++) w[i]=read(); 
//	cout<<1;
	for (int j0=0;j0<=n;j0++){
		for (int j1=0;j1<=n;j1++){
			for (int j2=0;j2<=n;j2++){
				for (int j3=0;j3<=n;j3++){
					if (check(j0,j1,j2,j3)) ans++;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}

