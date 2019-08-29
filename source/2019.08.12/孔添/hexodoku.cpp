#include<bits/stdc++.h>
using namespace std;
int n,k,tot=2;
bool as;
int H[10][10];
struct node2{
	int x,y,num;
}a[50];
bool check(int x,int y,int num){
	for(int i=y-1;H[x][i];--i){
		int p=H[x][i];
		if(a[p].num==num) return false;
	}
	for(int i=y+1;H[x][i];++i){
		int p=H[x][i];
		if(a[p].num==num) return false;
	}
	
	for(int i=x-1;H[i][y];--i){
		int p=H[i][y];
		if(a[p].num==num) return false;
	}
	for(int i=x+1;H[i][y];++i){
		int p=H[i][y];
		if(a[p].num==num) return false;
	}
	
	for(int i=x-1,j=y-1;H[i][j];--i,--j){
		int p=H[i][j];
		if(a[p].num==num) return false;
	}
	for(int i=x+1,j=y+1;H[i][j];++i,++j){
		int p=H[i][j];
		if(a[p].num==num) return false;
	}
	
	int p=H[x][y];
	if(p==1||p==2||p==4||p==5||p==6||p==10||p==11)
		if(num==a[1].num||num==a[2].num||num==a[4].num||num==a[5].num||num==a[6].num||num==a[10].num||num==a[11].num)
			return false;
		
	if(p==3||p==4||p==8||p==9||p==10||p==14||p==15)
		if(num==a[3].num||num==a[4].num||num==a[8].num||num==a[9].num||num==a[10].num||num==a[14].num||num==a[15].num)
			return false;
		
	if(p==6||p==7||p==11||p==12||p==13||p==17||p==18)
	if(num==a[6].num||num==a[7].num||num==a[11].num||num==a[12].num||num==a[13].num||num==a[17].num||num==a[18].num)
			return false;
		
	if(p==10||p==11||p==15||p==16||p==17||p==21||p==22)
		if(num==a[10].num||num==a[11].num||num==a[15].num||num==a[16].num||num==a[17].num||num==a[21].num||num==a[22].num)
			return false;
		
	if(p==14||p==15||p==19||p==20||p==21||p==25||p==26)
		if(num==a[14].num||num==a[15].num||num==a[19].num||num==a[20].num||num==a[21].num||num==a[25].num||num==a[26].num)
			return false;
		
	if(p==21||p==22||p==26||p==27||p==28||p==30||p==31)
		if(num==a[21].num||num==a[22].num||num==a[26].num||num==a[27].num||num==a[28].num||num==a[30].num||num==a[31].num)
			return false;
		
	if(p==17||p==18||p==22||p==23||p==24||p==28||p==29)
		if(num==a[17].num||num==a[18].num||num==a[22].num||num==a[23].num||num==a[24].num||num==a[28].num||num==a[29].num)
			return false;
	return true;
}
void write(){
	if(tot==n){
		as=true;
		cout<<"Found"<<endl;
		for(int i=1;i<=31;++i){
			cout<<a[i].num<<" ";	
		}
		tot++;
		cout<<endl;
		return;
	}
}
void dfs(int dep){
	if(tot>n) return;
	if(dep==32){
		tot++;
		write();
		return;
	}
	
	if(a[dep].num){
		dfs(dep+1);
		return;
	}
	
	int x=a[dep].x,y=a[dep].y;
	for(int i=1;i<=k;++i){
		if(check(x,y,i)==true){
			a[dep].num=i;
			dfs(dep+1);
			a[dep].num=0;
		}
	}
	return;
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	H[1][2]=1,H[1][3]=2,a[1].x=1,a[1].y=2,a[2].x=1,a[2].y=3;//第1行 
	for(int i=1;i<=5;++i) H[2][i]=++tot,a[tot].x=2,a[tot].y=i;//第2行 
	for(int i=1;i<=6;++i) H[3][i]=++tot,a[tot].x=3,a[tot].y=i;//第3行 
	for(int i=2;i<=6;++i) H[4][i]=++tot,a[tot].x=4,a[tot].y=i;//第4行 
	for(int i=2;i<=7;++i) H[5][i]=++tot,a[tot].x=5,a[tot].y=i;//第5行 
	for(int i=3;i<=7;++i) H[6][i]=++tot,a[tot].x=6,a[tot].y=i;//第6行 
	H[7][5]=30,H[7][6]=31,a[30].x=7,a[30].y=5,a[31].x=7,a[31].y=6;//第7行
	
	tot=0;
	cin>>k>>n;
	int x;
	for(int i=1;i<=31;++i){
		cin>>x;
		a[i].num=x;
	}
	tot=0;
	dfs(1);
	
	if(!as)
		cout<<"No way"<<endl;
	return 0;
}
