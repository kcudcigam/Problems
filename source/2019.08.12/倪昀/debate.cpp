#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
priority_queue<int>p[10];
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*f;
}
int main(){
    freopen("debate.in","r",stdin);
    freopen("debate.out","w",stdout);
    int n=read();
    fir(i,1,n){
    	string s;
    	cin>>s;
    	int x=read();
    	if(s=="00")p[1].push(x);
    	if(s=="01")p[2].push(x);
    	if(s=="10")p[3].push(x);
    	if(s=="11")p[4].push(x);
	}
	long long ans=0;
	while(p[2].size()&&p[3].size()){
		ans+=p[2].top()+p[3].top();
		p[2].pop(),p[3].pop();
	}
	int f=2;
	if(p[3].size())f=3;
	while(p[f].size())p[1].push(p[f].top()),p[f].pop();
	while(p[4].size()&&p[1].size()){
		ans+=p[4].top()+p[1].top();
		p[4].pop(),p[1].pop();
	}
	while(p[4].size()){
		ans+=p[4].top();
		p[4].pop();
	}
	cout<<ans<<endl;
	return 0;
}
