#include<bits/stdc++.h>
//#include<windows.h>
#define N 16
using namespace std;
int k,ans;
int a[N];
int q[4],w[4];
int f[N][N][N][N][2];
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
bool nxt(int *w){
	bool flag=false;
	for (int i=0;i<4;i++){
		if (w[i]==0) continue;
		w[i]--;
		if (w[i]){
			for (int j=0;j<4;j++)
				if (w[j]==0){
					w[j]=a[w[i]];
					break;
				}
		}
		else flag=true;
	}
	return flag;
}
void dfs(int w[],int p){
//	cout<<w[0]<<' '<<w[1]<<' '<<w[2]<<' '<<w[3]<<' '<<p<<' '<<f[w[0]][w[1]][w[2]][w[3]][0]<<endl;
//	system("pause");
	int t1=w[0],t2=w[1],t3=w[2],t4=w[3];
	//memcpy(w2,w,sizeof(w));
	//cout<<"pass";
	if (abs(f[w[0]][w[1]][w[2]][w[3]][p])==1) return;
	if (!nxt(w)){
		if (p==0){
			f[w[0]][w[1]][w[2]][w[3]][0]=-1;
			return;
		}
		else{
			if (f[w[0]][w[1]][w[2]][w[3]][0]==2){
				f[t1][t2][t3][t4][1]=1;
				return;
			}
			if (f[w[0]][w[1]][w[2]][w[3]][0]==0) f[w[0]][w[1]][w[2]][w[3]][0]=2;
			dfs(w,0);
			f[t1][t2][t3][t4][1]=f[w[0]][w[1]][w[2]][w[3]][0];
		}
		return;
	}
	if (f[w[0]][w[1]][w[2]][w[3]][0]==2){
		f[t1][t2][t3][t4][0]=f[t1][t2][t3][t4][1]=1;
		return;
	}
	if (f[w[0]][w[1]][w[2]][w[3]][0]==0) f[w[0]][w[1]][w[2]][w[3]][0]=2;
	dfs(w,1);
	f[t1][t2][t3][t4][1]=f[t1][t2][t3][t4][0]=f[w[0]][w[1]][w[2]][w[3]][1];
	return;
}
int main(){
	freopen("bob.in","r",stdin);
	freopen("bob.out","w",stdout);
	read(k);
	for (int i=1;i<k;i++) read(a[i]);
	f[0][0][0][0][0]=f[0][0][0][0][1]=-1;
	for (q[0]=0;q[0]<=k;q[0]++)
		for (q[1]=0;q[1]<=k;q[1]++)
			for (q[2]=0;q[2]<=k;q[2]++)
				for (q[3]=0;q[3]<=k;q[3]++)
					if (f[q[0]][q[1]][q[2]][q[3]][0]==0){
						f[q[0]][q[1]][q[2]][q[3]][0]=2;
						memcpy(w,q,sizeof(q));
						dfs(w,0);
					}
	for (q[0]=0;q[0]<=k;q[0]++)
		for (q[1]=0;q[1]<=k;q[1]++)
			for (q[2]=0;q[2]<=k;q[2]++)
				for (q[3]=0;q[3]<=k;q[3]++)
					{
						if (f[q[0]][q[1]][q[2]][q[3]][0]==1||f[q[0]][q[1]][q[2]][q[3]][0]==0) ans++;
		//				cout<<q[0]<<' '<<q[1]<<' '<<q[2]<<' '<<q[3]<<' '<<f[q[0]][q[1]][q[2]][q[3]][0]<<'\n';
					}
	printf("%d\n",ans);
	return 0;
}

