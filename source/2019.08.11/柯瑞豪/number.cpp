#include<bits/stdc++.h>
using namespace std;
int t,num;
bool f[10];
int A[25];
long long n;
bool work(long long x){
	memset(f,0,sizeof(f));
	A[0]=0;
	while(x){
		A[++A[0]]=int(x%10);
		x/=10;
	}
	int cnt=0;
    for(int i=1;i<=A[0];i++){
		if(f[A[i]])continue;
	    cnt++;
	   	f[A[i]]=1;
	}
	if(cnt>2)return 0;
	return 1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
    scanf("%d",&t);
    while(t--){
    	scanf("%lld",&n);
    	if(n<102){printf("1\n");continue;}
    	if(work(n))printf("1\n");
    	else printf("2\n");
	}
	return 0;
}
