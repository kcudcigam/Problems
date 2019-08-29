#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
int a[40],cnt,fac[20],sum[40],len[40],ans[40];
bool inv[40],u[40];
inline void pre(){
	fac[0]=1;
	for(register int i=1;i<=11;i++){
		fac[i]=fac[i-1]*i;
	}
}
inline bool judge(){
	for(register int i=2;i<=31;i++){
		if(!a[i]) continue; 
		if(i==2){
			if(a[2]==a[1]) return false;
		}
		else if(i==3){
			continue;
		}
		else if(i==4){
			if(a[3]==a[4]||a[4]==a[1]) {
				return false;
			}
		}
		else if(i==6){
			if(a[2]==a[6]||a[6]==a[5]){
				return false;
			}
		}
		else if(i==8){
			if(a[3]==a[8]) return false;
		}
		else if(i==13){
			if(a[13]==a[7]||a[12]==a[13]) return false;
		}
		else if(i==14){
			if(a[14]==a[8]||a[14]==a[9]){
				return false;
			}
		}
		else if(i==19){
			if(a[19]==a[14]) return false;
		}
		else if(i==25){
			if(a[25]==a[19]||a[25]==a[20]){
				return false;
			}
		}
		else if(i==30){
			if(a[30]==a[26]||a[30]==a[27]) return false;
		}
		else if(i==31){
			if(a[30]==a[31]||a[31]==a[27]||a[31]==a[28]){
				return false;
			}
		}
		else if(i==7){
			if(a[6]==a[7]) return false;
		}
		else if(i==24){
			if(a[24]==a[23]||a[24]==a[18]){
				return false;
			}
		}
		else if(i==5){
			if(a[4]==a[5]||a[1]==a[5]||a[2]==a[5]){
				return false;
			}
		}	
		else {
			if(a[i]==a[i-6]||a[i]==a[i-1]||a[i]==a[i-5]){
				return false;
			}
		}
	}
	return true;
}
inline bool check(int x,int val){
	long long ans=1;
	if(ans>=val) return false;
	for(register int i=1;i<=x;i++){
		ans=(long long)ans*i;
		if(ans>=val) return false;
	}
	return true;
}
inline void kantuo(int x){
	x--;
	for(register int i=1;i<=cnt;i++){
		if(check(cnt-i,x+1)){
			int now=x/fac[cnt-i];
			int j;
			for(j=1;j<=cnt;j++){
				if(!u[j]){
					if(now==0) break;
					now--;
				}
			}
			ans[i]=j;
			u[j]=true;
			x%=fac[cnt-i];
		}
		else {
			for(register int j=1;j<=cnt;j++){
				if(!u[j]){
					ans[i]=j;
					u[j]=true;
					break;
				}
			}
		}
	}
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	scanf("%d%d",&k,&n);
	bool flag=false;
	for(register int i=1;i<=31;i++){
		scanf("%d",&a[i]);
		if(a[i]>k||a[i]<0){
			flag=true;
		}
		inv[a[i]]=true;
		if(!a[i]){
			cnt++;
		}
	}
	for(register int i=1;i<=31;i++){
		if(inv[i]){
			sum[i]=sum[i-1]+1;
		}
		else sum[i]=sum[i-1];
	}
	if(k==1||k==2){
		printf("No way\n");
		return 0;
	}
	if(flag){
		printf("No way\n");
		return 0;
	}
	if(!judge()){
		printf("No way\n");
		return 0;
	}
	if(check(cnt,n)){
		printf("No way\n");
		return 0;
	}
	if(k==31){	
		pre();
		cnt=0;
		for(register int i=1;i<=31;i++){
			if(inv[i]) continue;
			cnt++;
		}
		if(check(cnt,n)){
			printf("No way\n");
			return 0;
		}
		kantuo(n);
		cnt=0;
		printf("Found\n");
		for(register int i=1;i<=31;i++){
			if(a[i]){
				len[i]=a[i];
			}
			else {
				++cnt;
				len[i]=ans[cnt]+sum[ans[cnt]];
				printf("%d ",len[i]);
			}
		}
		return 0;
	}
	printf("No way\n");
}
