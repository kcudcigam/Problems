#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
int a[200001];
int b[200001];
long long lianxi[400001][2];
void read(long long &x)
{
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
		ch=getchar();
		if(ch=='-')f=-1;
	}
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    x*=f;
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	long long num;
	read(num);
	long long n,m,k;
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++){
		read(lianxi[i][0]);read(lianxi[i][1]);
		a[lianxi[i][0]]++;b[lianxi[i][0]]=lianxi[i][1];
		a[lianxi[i][1]]++;b[lianxi[i][1]]=lianxi[i][0];
	}
	for(int i=1;i<=k;i++){
		read(lianxi[i][0]);read(lianxi[i][1]);
		if(b[lianxi[i][0]]!=lianxi[i][1]){
			a[lianxi[i][0]]++;a[lianxi[i][1]]++;
	}
	}
	long long sum1=1,sum2=1;
	int gs=0;
	for(int i=1;i<=m+k;i++){
		if(lianxi[i][0]==2)lianxi[i][1]=2;
		if(lianxi[i][1]==2)lianxi[i][2]=2;
		if(lianxi[i][1]==1&&lianxi[i][2]==1)sum2=(sum2*2)%mod;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0)gs++;
		sum1=(sum1*i)%mod;
	}
	for(int i=1;i<=gs;i++){
		sum2=(sum2*i)%mod;
	}
	long long sum=(sum1+mod-sum2)%mod;
	cout<<sum;
	return 0;
}


