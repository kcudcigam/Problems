#include<bits/stdc++.h>
using namespace std;
int zuhe1[400010],zuhe2[400010],zuhe3[400010];
long long tot1=0,tot2=0,tot3=0,ans=0;
int read(){
	int p=1,q=0;
	char ch=getchar();
	while(ch>'9'&&ch<'0'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n=read();
	int sup1=0,sup2=0;
	for(int i=1;i<=n;++i){
		int mm=read();
		int act=read();
		if(mm==11){
		ans+=act;
		sup1++;
		sup2++;
		}
		else if(mm==1)zuhe1[++tot1]=act;//01
		else if(mm==10)zuhe2[++tot2]=act;//10
		else zuhe3[++tot3]=act;//00
	}
	
	sort(zuhe1+1,zuhe1+tot1+1);
	sort(zuhe2+1,zuhe2+tot2+1);
	sort(zuhe3+1,zuhe3+tot3+1);
	
	while(tot2>0&&tot1>0){
		ans+=zuhe1[tot1--];
		ans+=zuhe2[tot2--];
	}
	if(tot2==0){
		while((tot3||tot1)&&sup1&&sup2){
			if(zuhe3[tot3]>=zuhe1[tot1]){
				sup1--;
				sup2--;
				ans+=zuhe3[tot3--];
			}	
			else {
				sup2++;
				sup1--;
				ans+=zuhe1[tot1--];
			}
		}
		while (sup1&&tot1){
			sup1--;
			ans+=zuhe1[tot1--];
		}	
	}
	
	else {
	while((tot3||tot2)&&sup1&&sup2){
			if(zuhe3[tot3]>=zuhe2[tot2]){
				sup1--;
				sup2--;
				ans+=zuhe3[tot3--];
			}
			else {
				sup1++;
				sup2--;
				ans+=zuhe2[tot2--];
			}	
		}
		while (sup2&&tot2){
			sup2--;
			ans+=zuhe2[tot2--];
		}	
	}
	cout<<ans<<endl;
	return 0;
}
/*
6 00 10
11 20
10 20
11 10
01 5
01 20
8
11 20
11 10
00 20
00 10
01 40
10 10
01 30
00 30

.
*/
