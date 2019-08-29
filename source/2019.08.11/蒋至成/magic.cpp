#include<bits/stdc++.h>
using namespace std; 
const int p=998244353;
int ans;
char a[10];
long long n;
string st; 
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int power(int x,int y){
	int aws=1;
	for(int i=1;i<=y;++i){
		aws*=x;
		aws%=p;
	}
	return aws%p;
}
void dfs(int dep){
	if(dep>n){
		int xb=0,k=0;
		bool pd=0;
		for(int i=1;i<=n;++i){
			if(a[i]==st[xb]){
				xb++;
				if(pd)k++;
				pd=0;
				if(xb==st.size()){
					if(i!=n)k++;
					break;
				} 
			}
			else pd=1;
		}
		if(k>1||xb!=st.size()){ans++;ans%=p;}
		return ;
	}
	for(int i=1;i<=26;++i){
		a[dep]=(char)(i+96);
		dfs(dep+1);
	}
} 
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	cin>>st;
	if(n<=4){
	dfs(1);
	cout<<ans%p;
	}
	else if(n==st.size())cout<<(power(26,n)-1)%p;
	return 0;
}


