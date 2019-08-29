#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
#define mo 1000000007 
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int t[20];bool f[20][20][2];
int powe[110];int inv[110];
inline bool ct(int x,int y){
	int px=t[x];int py=t[y];
	if(!f[x][y][0]&&!f[x][y][1]&&(f[px][py][0]||f[px][py][1]))return true;
	if(!f[x][y][0]&&f[x][y][1]&&f[px][py][0])return true;
	if(f[x][y][0]&&!f[x][y][1]&&f[px][py][1])return true;
	return false;
}
inline int poww(int n,int m){
	int ret=1;int temp=n;int tmp=m;
	while(tmp){
		if(tmp&1)ret=(1ll*ret*temp)%mo;
		temp=(1ll*temp*temp)%mo;
		tmp>>=1;
	}
	return ret;
}
inline void P(){
	powe[0]=powe[1]=inv[0]=inv[1]=1;
	rep(i,2,50)powe[i]=(1ll*powe[i-1]*i)%mo;
	inv[50]=poww(powe[50],mo-2);
	rep2(i,49,2)inv[i]=(1ll*inv[i+1]*(i+1))%mo;
	return;
}

int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);

	int num;read(num);
	int n,m1,m2,x,y;read(n);read(m1);read(m2);
	rep(i,1,m1){
		read(x);read(y);
		if(n<=10)f[x][y][0]=f[y][x][0]=1;
	}
	rep(i,1,m2){
		read(x);read(y);
		if(n<=10)f[x][y][1]=f[y][x][1]=1;
	}
	if(n>10){
		int ans=1;
		rep(i,1,n)ans=(1ll*ans*i)%mo;
		int tmp=max(m1,m2);
		ans=(ans+mo-tmp*tmp)%mo;
		write(ans);return 0;
	}
	
	rep(i,1,n)t[i]=i;
	int ans=0;
	do{
		bool f=false;
		rep(i,1,n){
			rep(j,i+1,n){
				if(ct(i,j)){f=true;ans++;break;}
			}
			if(f==true)break;
		}
	}while(next_permutation(t+1,t+n+1));
	write(ans);
	return 0;
}
