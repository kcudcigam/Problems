#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q[3];
int cnt[3];

template <typename T> void read(T &x){
	x=0;char c=getchar();int f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}

int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n,i,a,b;
	long long ans=0;
	int c1,c2;
	read(n);
	for(i=1;i<=n;i++){
		read(b);
		c2=b%10;b/=10;c1=b%10;
		read(a);
		if(c1==1&&c2==1){cnt[0]++;ans+=a;}
		else if(c1==1&&c2==0){cnt[1]++;q[1].push(a);}
		else if(c1==0&&c2==1){cnt[2]++;q[2].push(a);}
		else if(c1==0&&c2==0)q[0].push(a);
	}
	
	int dd;
	dd=min(cnt[1],cnt[2]);
	int id;
	if(cnt[1]>=cnt[2])id=1;
	else id=2;
	
	for(i=1;i<=dd;i++){
		ans+=q[1].top();ans+=q[2].top();
		q[1].pop();q[2].pop();
	}
		
	for(i=1;i<=cnt[0];i++){
		if(q[id].top()>=q[0].top()){
			ans+=q[id].top();
			q[id].pop();
		}
		else{
			ans+=q[0].top();
			q[0].pop();
		}
	}
	
	printf("%lld",ans);
	return 0;
}


