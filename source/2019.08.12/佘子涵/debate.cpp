#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int n,nu,nz;
long long a[400010],ans;
char pd[10];
priority_queue<int> q,w,e;
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		scanf("%s",pd);
		read(a[i]);
		if(pd[0]=='1'&&pd[1]=='1'){
			ans+=a[i];
			nu++;nz++;
			continue;
		}
		if(pd[0]=='1'){
			q.push(a[i]);
			continue;
		}
		if(pd[1]=='1'){
			w.push(a[i]);
			continue;
		}
		e.push(a[i]);
	}
	while(q.size()&&w.size()){
		int x=q.top();int y=w.top();
		q.pop();w.pop();
		ans+=x+y;
		nu+=2;nz++;
	}
	while(nu<nz*2){
		int x=0,y=0;
		if(q.size()){
			x=q.top();
		}
		if(w.size()){
			x=w.top();
		}
		if(e.size()){
			y=e.top();
		}
		if(x>y){
			if(q.size()) q.pop();
			if(w.size()) w.pop();
			ans+=x;nu++;
		}
		else{
			e.pop();
			ans+=y;nu++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

