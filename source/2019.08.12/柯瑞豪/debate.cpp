#include<bits/stdc++.h>
using namespace std;
const int N=400010;
priority_queue<int> q[2];
int A[N];
int n,ans,num,cnt;
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
	x=(x<<1)+(x<<3)+(c&15);
	c=getchar();
	}
	return x*w;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		int a=s[0]-'0',b=s[1]-'0',c=read();
        if((a+b)==2)ans+=c,num++,cnt++;
        if((a+b)==1){
        	if(!b)q[0].push(c);
        	else q[1].push(c); 
		}
		if(!(a+b))A[++A[0]]=c;
	}
	
	sort(A+1,A+A[0]+1);
	
	while(!q[0].empty()&&!q[1].empty()){
		int x=q[0].top(),y=q[1].top();
		ans+=x+y;
		q[0].pop();q[1].pop();
		num+=2;cnt++;
	}
	int flag=0;
	if(q[0].empty())flag=1;
	
	int a=-1;
	if(!q[flag].empty())a=q[flag].top();
	
	while((cnt<<1)>num){
		if(q[flag].empty()&&(A[0]==0))break;
		if(a>A[A[0]]){
			ans+=a;q[flag].pop();
			if(!q[flag].empty())a=q[flag].top();
		}
		else {
			ans+=A[A[0]--];
		}
		num++;
	}
	cout<<ans<<endl;
	return 0;
}
