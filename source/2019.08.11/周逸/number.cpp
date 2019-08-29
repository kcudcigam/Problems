#include<bits/stdc++.h>
using namespace std;
int T,ans,t,k;
long long n;
bool vis[15],flag;
bool judge(long long a){
	int A=0;
	int i,j=1;
	for(i=1;i<t;i++)
		j*=10;
	if(a<j){
		A++;
		vis[0]=1;
	}
	while(a){
		if(!vis[a%10]){
			vis[a%10]=1;
			A++;
		}
		a/=10;
	}
	memset(vis,0,sizeof(vis));
	if(A<=2)
		return 1;
	return 0;
}
void dfs(int a,int b,int cur,long long num){
	if(num*(t-cur+1)>n)
		return;
	if(cur==t+1){
		if(n<num)
			return;
		if(judge(n-num))
			flag=1;
		return;
	}
	dfs(a,b,cur+1,num*10+a);
	if(flag)
		return;
	dfs(a,b,cur+1,num*10+b);
}
void zy(int a,int b,int c,int d,int cur,long long num1,long long num2){
	if((num1+num2)*(t-cur+1)>n)
		return;
	if(cur==t+1){
		if(n<num1+num2)
			return;
		if(judge(n-num1-num2))
			flag=1;
		return;
	}
	zy(a,b,c,d,cur+1,num1*10+a,num2*10+c);
	if(flag)
		return;
	if(c!=d)
		zy(a,b,c,d,cur+1,num1*10+a,num2*10+d);
	if(flag)
		return;
	if(a!=b){
		zy(a,b,c,d,cur+1,num1*10+b,num2*10+c);
		if(flag)
			return;
		if(c!=d)
			zy(a,b,c,d,cur+1,num1*10+b,num2*10+d);
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long K;
	int i,j,u,v;
	scanf("%d",&T);
	while(T--){
		t=flag=0;
		scanf("%lld",&n);
		K=n;
		while(K){
			if(!vis[K%10]){
				vis[K%10]=1;
				ans++;
			}
			K/=10;
			t++;
		}
		memset(vis,0,sizeof(vis));
		if(ans<=2){
			printf("1\n");
			continue;
		}
		k=sqrt(t);
		for(i=0;i<10;i++)
			for(j=0;j<10;j++)
				if(!flag)
					dfs(i,j,1,0);
		if(flag){
			printf("2\n");
			continue;
		}
		for(i=0;i<10;i++)
			for(j=i;j<10;j++)
				for(u=0;u<10;u++)
					for(v=u;v<10;v++)
						if(!flag)
							zy(i,j,u,v,1,0,0);
		if(flag)
			printf("3\n");
		else
			printf("%d\n",t);
	}
	return 0;
}


