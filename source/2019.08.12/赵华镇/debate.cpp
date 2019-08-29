#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int x,y,z;
}p[500005];
char s[500005];
int sum,num,t,tt,ss,m;
int sum1,sum2,book[500005];
int cmp(node i,node j)
{
	return i.z>j.z;
}
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s %d",s+1,&p[i].z);
		p[i].x=s[1]-48;p[i].y=s[2]-48;
		sum1+=p[i].x;sum2+=p[i].y;
	}
	if(sum1<sum2) t=1;
	else t=2;
	m=min(sum1,sum2)*2;
	if(m>=n){
		for(i=1;i<=n;i++){
			sum+=p[i].z;
		}
		printf("%d",sum);
		return 0;
	}
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++){
		if(t==1){
			if(p[i].x==1){
				book[i]=1;ss++;
				sum+=p[i].z;
				num+=p[i].y;
			}
		}
		else{
			if(p[i].y==1){
				book[i]=1;ss++;
				sum+=p[i].z;
				num+=p[i].x;
			}
		}
	}
	if(num>=m/2){
		for(i=1;i<=n;i++){
			if(book[i]==0){
				ss++;
				if(ss>m){
					break;
				}
				sum+=p[i].z;	
			}
		}
		printf("%d",sum);
		return 0;
	}
	tt=m/2-num;
	for(i=1;i<=n;i++){
		if(book[i]==0){
			if((t==1&&p[i].y==1)||(t==2&&p[i].x==1)){
				tt--;ss++;
				if(tt<0){
					break;
				}
				sum+=p[i].z;
			}
		}
	}
	for(i=1;i<=n;i++){
		if(ss<m&&book[i]==0){
			sum+=p[i].z;
			ss++;
		}
	}
	printf("%d",sum);
	return 0;
}
