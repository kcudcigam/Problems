#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,x;
int book[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		memset(book,0,sizeof(book));
		int ans=0;
		while(x){
			int k=x%10;
			if(!book[k]){
				ans++;
				if(ans>1) break;
				book[k]=1;
			}
			x/=10;
		}
		if(ans==1) printf("1\n");
		else printf("2\n");
	}
	return 0;
}
