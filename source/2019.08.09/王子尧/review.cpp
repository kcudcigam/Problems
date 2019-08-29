#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
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
long long a[110][2];long long b[1000010][2];
inline long long lowbit(long long x){return x&(-x);}
int tmp=0;
inline void op(int n,int m){
	qwq(n);putchar(' ');write(m);tmp++;
	return;
}
inline int bs(long long x){
	int ret=0;
	while(x){x/=2;ret++;}
	return ret;
} 

int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);

	long long Y;read(Y);
	int len=0;long long Y1=Y;
	for(long long i=2;i*i<=Y1;i++){
		if(Y1%i==0){
			int cnt=0;
			while(Y1%i==0){cnt++;Y1/=i;}
			b[++len][0]=cnt;b[len][1]=i;
		}
	}
	if(Y1>1){b[++len][0]=1;b[len][1]=Y1;}
	
	long long n=0;long long m=0;long long temp=0;
	rep(i,1,len){
		n+=1ll*b[i][0]*(b[i][1]+1);m+=1ll*b[i][0]*(2ll*b[i][1]-1);
		temp+=b[i][0];
	}
	n-=temp-1;
	
	long long n2=1;long long m2=0;long long Y2=Y;int len2=0;
	while(Y2){a[++len2][0]=lowbit(Y2);Y2-=lowbit(Y2);}
	rep(i,1,len2){a[i][1]=bs(a[i][0]);n2+=2*a[i][1];}
	rep(i,1,len2)m2+=3*a[i][1]+1;
	m2--;
	
	if(n<=n2){
		op(n,m);int l=1;
		rep(i,1,len){
			rep(j,1,b[i][0]){
				op(l,l+b[i][1]);
				rep(k,2,b[i][1]){op(l,l+k-1);op(l+k-1,l+b[i][1]);}
				l+=b[i][1];
			}
		}
	}else{ 
		op(n2,m2);int l=2;
		rep(i,1,len2){
			op(1,l);op(l,l+1);op(1,l+1);l+=1;
			rep(j,2,a[i][1]){
				op(l,l+1);op(l,l+2);op(l+1,l+2);l+=2;
			}
			if(l!=n2)op(l,n2);
			l++;
		}
	}
	return 0;
}
