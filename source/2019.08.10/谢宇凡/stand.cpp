#include<bits/stdc++.h>
using namespace std;

template<typename T>void read(T &x){
    x=0;char c=getchar();
    int f=1;
    for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-48;
    x=x*f;
}

struct node{
	int l,r;
}a[300];

bool cmp(node x,node y){
	return x.l<y.l;
}

int n,m,k[6],sum;
bool vis[300];

int check(){
	for (int i=1;i<=n;++i)	if (!vis[i])	return 1;
	return 0;
}

int find(){
	priority_queue<int,vector<int>,greater<int> > q;
	int pla;
	for (int i=1;i<=n;++i){
			if (vis[i])	continue;
			if (q.empty()||q.top()>=a[i].l)	q.push(a[i].r);
				else{
					if (q.size()>sum)	sum=q.size(),pla=q.top();
					while (q.top()<a[i].l&&!q.empty())	q.pop();
					q.push(a[i].r);
				}
		}
	if (q.size()>sum)	sum=q.size(),pla=q.top();
	return pla;
}

long long calc(int x){
	long long y=x;
	long long num=0;
	for (int i=1;i<=5;++i){
		num+=k[i]*y;
		y*=x;
	}
	return num; 
}

int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=5;++i)	read(k[i]);
	for (int i=1;i<=n;++i){
		read(a[i].l);
		read(a[i].r);
	}
	sort(a+1,a+n+1,cmp);
	long long ans=0;
	int pla;
	while (check()){
		sum=0;
		int pla=find();
		ans+=calc(sum);
		for (int i=1;i<=n;++i)
			if (a[i].l<=pla&&a[i].r>=pla)	vis[i]=1;
	}
	printf("%lld\n",ans);
	return 0;
}



