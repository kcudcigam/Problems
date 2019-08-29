#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n,x,ans;
struct Node{
	int a,b,c;
}num[1005];
bool operator < (Node a,Node b){
	return a.a>b.a;
}

void check(int  back_m,int n_mon){  //back_m为面值编号   n_mon为需找金额 
		/*
		if(n_mon<num[back_m].a){
			check(back_m+1,n_mon);
		}
		else {
		*/
		int t_back; //找钱所剩需找金额 
		for(int j=1;j<=num[back_m].c;j++){
			t_back=n_mon-num[back_m].a*j;
			if(t_back>0)
			continue;
			else if(t_back==0){
				ans++;
				ans%=MOD;
				return;
			}
			else if(t_back<0){
				t_back+=num[back_m].a;
				check(back_m+1,t_back);
				break;
			}
			
		}
		if(t_back== (n_mon-num[back_m].a*num[back_m].c) )
		check(back_m+1,t_back);
	//}
}

void deal(int g_mon,int mon){ //g_mon为付出面值编号 mon为所需付面值 
	/*
	for(int i=1;i<=n;i++)
	cout<<num[i].a<<" "<<num[i].b<<" "<<num[i].c<<endl;
	*/
		for(int j=1;j<=num[g_mon].b;j++){
			int t_mon=num[g_mon].a*j;  //已付 
			if(t_mon<mon){
				if(g_mon==n){
					continue;
				}
				else{
				for(int o=1;o<=(n-g_mon);o++)
				deal(g_mon+o,mon-t_mon);
				}
			}
			else if(t_mon==mon){
				ans++;
				ans%=MOD;
				return ;
			}
			else if(t_mon>mon){
				check(g_mon+1,t_mon-mon);
				break;
			}
		}
	}
	
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d %d",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&num[i].a,&num[i].b,&num[i].c);
	}
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++){
	deal(i,x);
	}
	printf("%d\n",ans);
	return 0;
}


