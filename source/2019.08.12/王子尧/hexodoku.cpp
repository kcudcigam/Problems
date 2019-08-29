#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define pb push_back
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int co[40];int cnt=0;
bool h[8][35];bool z[8][35];bool y[8][35];bool q[8][35];
int t[35][3];vector<int>yy[35];
int k,n;bool f=false;
inline bool chck(int x,int w){
	if(h[t[x][0]][w]||z[t[x][1]][w]||y[t[x][2]][w])return false;
	rep(i,0,(int)(yy[x].size()-1)){
		if(q[yy[x][i]][w])return false;
	}
	return true;
}
inline void dfs(int dep){
	if(dep>31){
		cnt++;
		if(cnt==n)f=true;
	}else{
		if(co[dep]){dfs(dep+1);}
		else{
			rep(i,1,k){
				if(chck(dep,i)){
					co[dep]=i;h[t[dep][0]][i]=1;
					z[t[dep][1]][i]=1;y[t[dep][2]][i]=1;
					rep(j,0,(int)(yy[dep].size()-1)){
						q[yy[dep][j]][i]=1;
					}
					dfs(dep+1);
					if(f==true)return;
					co[dep]=0;h[t[dep][0]][i]=0;
					z[t[dep][1]][i]=0;y[t[dep][2]][i]=0;
					rep(j,0,(int)(yy[dep].size()-1)){
						q[yy[dep][j]][i]=0;
					}
				}
			}
		}
	}
	return;
}
inline void P(){
	t[1][0]=1;t[2][0]=1;t[30][0]=7;t[31][0]=7;
	rep(i,3,7)t[i][0]=2;
	rep(i,8,13)t[i][0]=3;
	rep(i,14,18)t[i][0]=4;
	rep(i,19,24)t[i][0]=5;
	rep(i,25,29)t[i][0]=6;//h
	t[3][1]=t[8][1]=1;t[24][1]=t[29][1]=7;
	t[1][1]=2;t[2][1]=3;t[30][1]=5;t[31][1]=6;
	for(int i=4;i<=19;i+=5)t[i][1]=2;
	for(int i=5;i<=25;i+=5)t[i][1]=3;
	for(int i=6;i<=26;i+=5)t[i][1]=4;
	for(int i=7;i<=27;i+=5)t[i][1]=5;
	for(int i=13;i<=28;i+=5)t[i][1]=6;//z
	t[7][2]=t[13][2]=1;t[19][2]=t[25][2]=7;
	t[2][2]=2;t[1][2]=3;t[31][2]=5;t[30][2]=6;
	for(int i=6;i<=24;i+=6)t[i][2]=2;
	for(int i=5;i<=29;i+=6)t[i][2]=3;
	for(int i=4;i<=28;i+=6)t[i][2]=4;
	for(int i=3;i<=27;i+=6)t[i][2]=5;
	for(int i=8;i<=26;i+=6)t[i][2]=6;//y
	yy[1].pb(1);yy[2].pb(1);yy[3].pb(2);yy[4].pb(1);
	yy[4].pb(2);yy[5].pb(1);yy[6].pb(1);yy[6].pb(3);
	yy[7].pb(3);yy[8].pb(2);yy[9].pb(2);yy[10].pb(1);
	yy[10].pb(2);yy[10].pb(4);yy[11].pb(1);yy[11].pb(3);
	yy[11].pb(4);yy[12].pb(3);yy[13].pb(3);yy[14].pb(2);
	yy[14].pb(5);yy[15].pb(2);yy[15].pb(4);yy[15].pb(5);
	yy[16].pb(4);yy[17].pb(3);yy[17].pb(4);yy[17].pb(6);
	yy[18].pb(3);yy[18].pb(6);yy[19].pb(5);yy[20].pb(5);
	yy[21].pb(4);yy[21].pb(5);yy[21].pb(7);yy[22].pb(4);
	yy[22].pb(6);yy[22].pb(7);yy[23].pb(6);yy[24].pb(6);
	yy[25].pb(5);yy[26].pb(5);yy[26].pb(7);yy[27].pb(7);
	yy[28].pb(6);yy[28].pb(7);yy[29].pb(6);yy[30].pb(7);
	yy[31].pb(7);//q
	return;
}

int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);

	P();
	read(k);read(n);
	rep(i,1,31)read(co[i]);
	rep(i,1,31){
		if(co[i]){
			h[t[i][0]][co[i]]=1;
			z[t[i][1]][co[i]]=1;y[t[i][2]][co[i]]=1;
			rep(j,0,(int)(yy[i].size()-1)){
				q[yy[i][j]][co[i]]=1;
			}
		}
	}
	if(k<=7){puts("No way");return 0;}
	
	dfs(1);
	if(f==false){puts("No way");return 0;}
	else{puts("Found");}
	rep(i,1,31){qwq(co[i]);putchar((i==31)?'\n':' ');}
	return 0;
}
