#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=35;
ll n,k,a[10][N],b[10][N],c[10][N],h[10][N],ans[N],cnt,biaoji[N],ok;
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=fl;
}
void wr(ll x){
	 if(x<0) putchar('-'),x=-x;
	 if(x<10) putchar(x+'0');
	 if(x>9) wr(x/10),putchar(x%10+'0');
}
void add(ll x,ll y){
	if(x==1||x==2||x==4||x==5||x==6||x==10||x==11) a[0][y]=1;
	if(x==3||x==4||x==8||x==9||x==10||x==14||x==15) a[1][y]=1;
	if(x==6||x==7||x==11||x==12||x==13||x==17||x==18) a[2][y]=1;
	if(x==10||x==11||x==15||x==16||x==17||x==21||x==22) a[3][y]=1;
	if(x==14||x==15||x==19||x==20||x==21||x==25||x==26) a[4][y]=1;
	if(x==17||x==18||x==22||x==23||x==24||x==28||x==29) a[5][y]=1;
	if(x==21||x==22||x==26||x==27||x==28||x==30||x==31) a[6][y]=1;
	if(x==1||x==2) h[0][y]=1;
	if(x==3||x==4||x==5||x==6||x==7) h[1][y]=1;
	if(x==8||x==9||x==10||x==11||x==12||x==13) h[2][y]=1;
	if(x==14||x==15||x==16||x==17||x==18) h[3][y]=1;
	if(x==19||x==20||x==21||x==22||x==23||x==24) h[4][y]=1;
	if(x==25||x==26||x==27||x==28||x==29) h[5][y]=1;
	if(x==30||x==31) h[6][y]=1;
	if(x==7||x==13) b[0][y]=1;
	if(x==2||x==6||x==12||x==18||x==24) b[1][y]=1;
	if(x==1||x==5||x==11||x==17||x==23||x==29) b[2][y]=1;
	if(x==4||x==10||x==16||x==22||x==28) b[3][y]=1;
	if(x==3||x==9||x==15||x==21||x==27||x==31) b[4][y]=1;
	if(x==8||x==14||x==20||x==26||x==30) b[5][y]=1;
	if(x==19||x==25) b[6][y]=1;
	if(x==3||x==8) c[0][y]=1;
	if(x==1||x==4||x==9||x==14||x==19) c[1][y]=1;
	if(x==2||x==5||x==10||x==15||x==20||x==25) c[2][y]=1;
	if(x==6||x==11||x==16||x==21||x==26) c[3][y]=1;
	if(x==7||x==12||x==17||x==22||x==27||x==30) c[4][y]=1;
	if(x==13||x==18||x==23||x==28||x==31) c[5][y]=1;
	if(x==24||x==29) c[6][y]=1;
	return ;
}
void bac(ll x,ll y){
	if(x==1||x==2||x==4||x==5||x==6||x==10||x==11) a[0][y]=0;
	if(x==3||x==4||x==8||x==9||x==10||x==14||x==15) a[1][y]=0;
	if(x==6||x==7||x==11||x==12||x==13||x==17||x==18) a[2][y]=0;
	if(x==10||x==11||x==15||x==16||x==17||x==21||x==22) a[3][y]=0;
	if(x==14||x==15||x==19||x==20||x==21||x==25||x==26) a[4][y]=0;
	if(x==17||x==18||x==22||x==23||x==24||x==28||x==29) a[5][y]=0;
	if(x==21||x==22||x==26||x==27||x==28||x==30||x==31) a[6][y]=0;
	if(x==1||x==2) h[0][y]=0;
	if(x==3||x==4||x==5||x==6||x==7) h[1][y]=0;
	if(x==8||x==9||x==10||x==11||x==12||x==13) h[2][y]=0;
	if(x==14||x==15||x==16||x==17||x==18) h[3][y]=0;
	if(x==19||x==20||x==21||x==22||x==23||x==24) h[4][y]=0;
	if(x==25||x==26||x==27||x==28||x==29) h[5][y]=0;
	if(x==30||x==31) h[6][y]=0;
	if(x==7||x==13) b[0][y]=0;
	if(x==2||x==6||x==12||x==18||x==24) b[1][y]=0;
	if(x==1||x==5||x==11||x==17||x==23||x==29) b[2][y]=0;
	if(x==4||x==10||x==16||x==22||x==28) b[3][y]=0;
	if(x==3||x==9||x==15||x==21||x==27||x==31) b[4][y]=0;
	if(x==8||x==14||x==20||x==26||x==30) b[5][y]=0;
	if(x==19||x==25) b[6][y]=0;
	if(x==3||x==8) c[0][y]=0;
	if(x==1||x==4||x==9||x==14||x==19) c[1][y]=0;
	if(x==2||x==5||x==10||x==15||x==20||x==25) c[2][y]=0;
	if(x==6||x==11||x==16||x==21||x==26) c[3][y]=0;
	if(x==7||x==12||x==17||x==22||x==27||x==30) c[4][y]=0;
	if(x==13||x==18||x==23||x==28||x==31) c[5][y]=0;
	if(x==24||x==29) c[6][y]=0;
	return ;
}
bool check(ll x,ll y){
	if(x==1||x==2||x==4||x==5||x==6||x==10||x==11) if(a[0][y]==1) return 0;
	if(x==3||x==4||x==8||x==9||x==10||x==14||x==15) if(a[1][y]==1) return 0;
	if(x==6||x==7||x==11||x==12||x==13||x==17||x==18) if(a[2][y]==1) return 0;
	if(x==10||x==11||x==15||x==16||x==17||x==21||x==22) if(a[3][y]==1) return 0;
	if(x==14||x==15||x==19||x==20||x==21||x==25||x==26) if(a[4][y]==1) return 0;
	if(x==17||x==18||x==22||x==23||x==24||x==28||x==29) if(a[5][y]==1) return 0;
	if(x==21||x==22||x==26||x==27||x==28||x==30||x==31) if(a[6][y]==1) return 0;
	if(x==1||x==2) if(h[0][y]==1) return 0;
	if(x==3||x==4||x==5||x==6||x==7) if(h[1][y]==1) return 0;
	if(x==8||x==9||x==10||x==11||x==12||x==13) if(h[2][y]==1) return 0;
	if(x==14||x==15||x==16||x==17||x==18) if(h[3][y]==1) return 0;
	if(x==19||x==20||x==21||x==22||x==23||x==24) if(h[4][y]==1) return 0;
	if(x==25||x==26||x==27||x==28||x==29) if(h[5][y]==1) return 0;
	if(x==30||x==31) if(h[6][y]==1) return 0;
	if(x==7||x==13) if(b[0][y]==1) return 0;
	if(x==2||x==6||x==12||x==18||x==24) if(b[1][y]==1) return 0;
	if(x==1||x==5||x==11||x==17||x==23||x==29) if(b[2][y]==1) return 0;
	if(x==4||x==10||x==16||x==22||x==28) if(b[3][y]==1) return 0;
	if(x==3||x==9||x==15||x==21||x==27||x==31) if(b[4][y]==1) return 0;
	if(x==8||x==14||x==20||x==26||x==30) if(b[5][y]==1) return 0;
	if(x==19||x==25) if(b[6][y]==1) return 0;
	if(x==3||x==8) if(c[0][y]==1) return 0;
	if(x==1||x==4||x==9||x==14||x==19) if(c[1][y]==1) return 0;
	if(x==2||x==5||x==10||x==15||x==20||x==25) if(c[2][y]==1) return 0;
	if(x==6||x==11||x==16||x==21||x==26) if(c[3][y]==1) return 0;
	if(x==7||x==12||x==17||x==22||x==27||x==30) if(c[4][y]==1) return 0;
	if(x==13||x==18||x==23||x==28||x==31) if(c[5][y]==1) return 0;
	if(x==24||x==29) if(c[6][y]==1) return 0;
	return 1;
}
void dfs(ll x){
	if(ok) return ;
	if(x==32){
		cnt++;
		if(cnt==n){
//			cout<<"---------"<<endl;
//			wr(cnt);cout<<endl;
			putchar('F');putchar('o');putchar('u');putchar('n');putchar('d');puts("");
			for(ll i=1;i<=31;i++) wr(ans[i]),putchar(' ');
			puts("");
			ok=1;
		}
		return ;
	}
	if(biaoji[x]) dfs(x+1);
	else
		for(ll i=1;i<=k;i++)
			if(check(x,i)) add(x,i),ans[x]=i,dfs(x+1),bac(x,i),ans[x]=0;
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	rd(k);rd(n);
	for(ll i=1;i<=31;i++){
		rd(ans[i]);
		if(ans[i]>0)
			if(check(i,ans[i])) add(i,ans[i]),biaoji[i]=1;
			else{putchar('N');putchar('o');putchar(' ');putchar('w');putchar('a');putchar('y');puts("");return 0;}
	}
	if(k<7||k==7&&n>10080){putchar('N');putchar('o');putchar(' ');putchar('w');putchar('a');putchar('y');puts("");return 0;}
	dfs(1);
	if(!ok){putchar('N');putchar('o');putchar(' ');putchar('w');putchar('a');putchar('y');puts("");return 0;}
	return 0;
}
