#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
int qread(){
	int w=1,c,ret;
	while((c=getchar())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getchar())>='0'&&c<='9')
	ret=ret*10+c-'0';return ret*w;
}
char readc(){
	char c;
	while((c=getchar())==' '||c=='\n');
	return c;
}
const int MAXN =1e2+3;
int cnt,n,ans;
priority_queue<int,vector<int>,less<int> > pq01,pq10,pq00;
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	
	n=qread();
	up(1,n,i){
		int t1=(readc()=='1'),t2=(readc()=='1'),w=qread();
		if(t1&&t2) ans+=w,cnt++; else{
			if(t1) pq10.push(w); else
			if(t2) pq01.push(w); else
			pq00.push(w);
		}
	}
	while(!pq01.empty()&&!pq10.empty()){
		ans+=pq01.top()+pq10.top();
		pq01.pop(),pq10.pop();
	}
	while(!pq01.empty()) pq00.push(pq01.top()),pq01.pop();
	while(!pq10.empty()) pq00.push(pq10.top()),pq10.pop();
	while(!pq00.empty()&&cnt) ans+=pq00.top(),pq00.pop(),cnt--;
	printf("%d\n",ans);
	return 0;
} 
