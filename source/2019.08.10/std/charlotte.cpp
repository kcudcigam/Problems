#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
const int N = 101000;
int n,x[N],y[N],t[N];
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T;read(T);
	while(T--){
		read(n);
		for(int i=1;i<=n;i++)
			read(t[i]),read(x[i]),read(y[i]);
		int tx=0,ty=0,lst=0;
		for(int i=1;i<=n;i++){
			int delt=t[i]-lst,dis=abs(x[i]-tx)+abs(y[i]-ty);
			if(delt&1^dis&1||dis>delt){puts("No");goto end;}
			tx=x[i];ty=y[i];lst=t[i];
		}
		puts("Yes");
end:;
	}
	return 0;
}
