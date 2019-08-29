#include<iostream>
#include<cstdio>
using namespace std;
int tot,f,o;
int book[500005],s[500005];
int t,n,i,j,y,x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=300000;i++){
		y=i;tot=0;
		while(y){
			x=y%10;
			if(book[x]==0){
				tot++;book[x]=1;
			}
			if(tot>2) break;
			y=y/10;
		}
		if(tot<=2){
			s[i]=1;o++;
		}
		for(j=0;j<=10;j++){
			book[j]=0;
		}
	}
	while(t--){
		f=0;
		scanf("%d",&n);
		if(s[n]==1){
			printf("1\n");
			continue;
		}
		for(i=1;i<=n;i++){
			if(s[i]&&s[n-i]){
				f=1;
				break;
			}
		}
		if(f==1){
			printf("2\n");
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}

