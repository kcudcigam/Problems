#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
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
template<typename T> void chkmax(T &x,T y){x=x>y?x:y;}
int co[100010];long long pre[100010];
int mx[100010][2];deque<pair<int,long long> >v;
deque<long long>v1;deque<pair<int,long long> >v2;

int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	
	int n;read(n);
	rep(i,1,n){read(co[i]);pre[i]=pre[i-1]+co[i];}
	rep2(i,n,1){
		while(!v.empty()
		&&v.back().second<=pre[i])v.pop_back();
		v.push_back(make_pair(i,pre[i]));
		mx[i][0]=v.front().first;
	}//iÎª¿ªÍ· 
	v.clear();v.push_back(make_pair(0,pre[0]));
	rep(i,1,n-1){
		mx[i][1]=v.front().first+1;
		while(!v.empty()
		&&v.back().second>=pre[i])v.pop_back();
		v.push_back(make_pair(i,pre[i]));
	}
	
	v1.push_back(pre[1]-pre[mx[1][1]-1]);
	rep(i,2,n){
		while(!v2.empty()
		&&v2.back().second<=pre[mx[i][0]]-pre[i-1])v2.pop_back();
		v2.push_back(make_pair(i,pre[mx[i][0]]-pre[i-1]));
	}
	long long ans=0;
	rep(i,1,n-1){
		chkmax(ans,v1.front()+v2.front().second);
		while(!v1.empty()
		&&v1.back()<=pre[i+1]-pre[mx[i+1][1]-1])v1.pop_back();
		v1.push_back(pre[i+1]-pre[mx[i+1][1]-1]);
		while(!v2.empty()&&v2.front().first<=i+1)v2.pop_front();
	}
	write(ans);
	return 0;
}
