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
template<typename T> void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T> void chkmax(T &x,T y){x=x>y?x:y;}
int dp[300010];int nu[3010];bool in[300010];
inline bool ss(int x){
	int n1=0;int n2=0;
	while(x){
		if(!n1){n1=x%10+1;}
		else if(n1&&n1!=x%10+1&&!n2){n2=x%10+1;}
		else if(n1&&n2&&n2!=x%10+1&&n1!=x%10+1)return false;
		x/=10;
	}
	return true;
}
int cnt[20];
inline int ts(long long x){
	while(x){cnt[x%10]=1;x/=10;}
	int ret=0;
	rep(i,0,9){ret+=(cnt[i]==1);cnt[i]=0;}
	return ret;
}
inline void Pretreatment(){
	int len=0;int ret=0;
	rep(i,1,300000){if(ss(i)){nu[++len]=i;in[i]=1;}} 
	rep(i,1,300000){
		if(in[i]){dp[i]=1;continue;}
		dp[i]=INT_MAX; 
		rep(j,1,len){
			if(nu[j]>i)break;
			chkmin(dp[i],dp[i-nu[j]]+1);
		}
	}
}

long long s[5000010];int len=0;long long num[15];
inline void dfs(int dep,int zd,long long v,int t1,int t2){
	if(dep==zd){
		if(t1==0){s[++len]=v+1ll*t2*num[zd-1];}
		else{s[++len]=v+1ll*t1*num[zd-1];s[++len]=v+1ll*t2*num[zd-1];}
	}else{
		dfs(dep+1,zd,v*10+t1,t1,t2);
		dfs(dep+1,zd,v*10+t2,t1,t2);
	}
	return;
}
inline void P(){
	num[0]=1;
	rep(i,1,13)num[i]=num[i-1]*10;
	rep(i,1,9){
		long long tmp=0;
		rep(j,1,13){tmp*=10;tmp+=i;s[++len]=tmp;}
		rep(j,1,13)dfs(1,j,0,0,i);
	}
	rep(i,1,9){
		rep(j,i+1,9){
			rep(k,1,13)dfs(1,k,0,i,j);
		}
	}
	sort(s+1,s+len+1);
	len=unique(s+1,s+len+1)-s;s[len]=1e13;
}
inline int pos(long long x){
	int l=1;int r=len;int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(s[mid]<=x){ans=mid;l=mid+1;}
		else{r=mid-1;}
	}
	return ans;
}
long long co[110];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	Pretreatment();P();
	int T;read(T);
	long long mx=0;
	rep(i,1,T){read(co[i]);chkmax(mx,co[i]);}
	
	if(mx<=1e13){
		rep(i,1,T){
			if(co[i]<=300000){write(dp[co[i]]);}
			else{
				int t1=pos(co[i]/3);bool f=false;int t=0;
				rep(j,t1,len){
					if(s[j]>co[i])break;
					if(co[i]==s[j]){write(1);f=true;break;}
					int t2=pos((co[i]-s[j])/2);
					rep(k,t2,len){
						if(s[j]+s[k]>co[i])break;
						if(co[i]==s[j]+s[k]){write(2);f=true;break;}
						int t3=pos(co[i]-s[j]-s[k]);
						if(s[t3]==co[i]-s[j]-s[k]){
							write(3);f=true;break;
						}
					}
					if(f==true)break;
				}
			}
		}
	}else{
		rep(i,1,T){
			if(co[i]<=300000){write(dp[co[i]]);}
			else{write((ts(co[i])+1)/2);}
		}
	}
	return 0;
}//99982399983
