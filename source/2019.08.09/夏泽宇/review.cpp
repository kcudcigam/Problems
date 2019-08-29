#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int a[110];
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	ll y=read(),cnt=0,branch=0;
	while(y){
		cnt++;
		if(y&1)a[cnt]=1,branch++;
		y/=2;
	}
	branch--;
	int End=3*cnt-2;
	int edge=(cnt-1)*4+branch;
	printf("%d %d\n",End,edge);
	for(int i=1;i<cnt;i++){
		printf("%d %d\n",3*i-2,3*i-1);
		printf("%d %d\n",3*i-2,3*i);
		printf("%d %d\n",3*i-1,3*i+1);
		printf("%d %d\n",3*i,3*i+1);
	}
	for(int i=1;i<cnt;i++){
		if(a[i])printf("%d %d\n",3*i-2,End);
	}
	return 0;
}


