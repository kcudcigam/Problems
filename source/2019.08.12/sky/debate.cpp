#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=4*10e4+5;
int n,ans,check;
int a_per,b_per,all;//支持a,b的人数 
bool vis_a=false,vis_b=false,vis_al=false,none=true;
int all_num,no_num,a_num,b_num;
struct Node{
	int num,val;
}x[MAXN];
bool operator < (Node a,Node b){
	return a.val>b.val;	
}
/*
void deal(){
	int now_max=0;
	for(int i=1;i<=n;i++){
		if(x[i].num==11){
		++a_per;
		++b_per;
		ans+=x[i].val;
		++all;
		}
		else if(!vis_al && vis_a && vis_b){
			if(x[i].val>)
		}
		else if(x[i].num==0){
			if(0.5<=(double)a_per/(all+1) && 0.5<=(double)b_per/(all+1)){
				ans+=x[i].val;
				all++
			}
		}
		else if(x[i].num==10){
			if()
		7}
	
	}
}
*/
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x[i].num,&x[i].val);
		/*if(x[i].num==10)
		vis_a=true;
		else if(x[i].num==1)
		vis_b=true;
		*/
		if(x[i].num==11)
			++all_num;
		else if(x[i].num==0)
			++no_num;
		else if(x[i].num==1)
			++b_num;
		else if(x[i].num==10)
			++a_num;
		if(i==1)
		check=x[i].val;	
		if(check!=x[i].val)
			none=false;
	
	}
	if(none){
		ans+=all_num;
		ans+=min(all_num,no_num);
		int minn=min(a_num,b_num);
		ans+=minn;
		printf("%d\n",ans*check);
		return 0;
	}
	int temp_n=0,temp_a=0;
	if(a_num==0 && b_num==0){
		sort(x+1,x+n+1);
		/*
		for(int i=1;i<=n;i++){
			printf("%d %d\n",x[i].num,x[i].val);
		}
		printf("\n");
		*/
		for(int i=1;i<=n;i++){
			if(x[i].num==11){
				if(temp_a<=all_num){
				ans+=x[i].val;
				++temp_a;
				}
			}
			else if(x[i].num==0 && temp_n<all_num){
				ans+=x[i].val;
				++temp_n;
			}
			if(temp_n==all_num && temp_a==all_num){
					printf("%d\n",ans);
					return 0;
				}
			
		}
	}
	return 0;
}


