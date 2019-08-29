#include<cstdio>
using namespace std;
int n,f[300002],u[300002],v[300002];
int Max[300002]; //Max[i]表示在i的联通块里最长的路径
int jl1[300002],jl2[300002]; // jl[i]表示在i的联通块里最长的路径的头和尾 
int Now[300002],cp[300002]; // Now[i]表示以当前节点为端点的最长路径 cp表示另一头的数 
int fx,fy,x,y,Nx,Ny,Cx,Cy;
int Find(int x){
	if (x != f[x])
		return f[x] = Find(f[x]);
	else
		return x;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i){
		f[i] = i;
		jl1[i]= i;
		cp[i] = i;
	}
	for (int i = 1; i < n; ++ i){
		scanf("%d%d",&x,&y);
		fx = Find(x);
		fy = Find(y);
		if (fx > fy){
			int t = fx;
			fx = fy;
			fy = fx;
		}
		if (Now[y]+1+Now[x] > Max[fx]){
			Max[fx] = Now[y]+1+Now[x];
			jl1[fx] = cp[x];
			jl2[fx] = cp[y];
		}
		Nx = Now[x];
		Ny = Now[y];
		if (Nx+1 > Ny){
			Now[y] = Nx+1;
			cp[y] = Cx;
		}
		if (Ny+1 > Nx){
			Now[x] = Ny+1;
			cp[x] = Cy;
		}
		f[fy] = fx;
		printf("%d\n",Max[fx]);
	}
	return 0;
}
/*
5
3 5
3 4
1 2
1 3
*/
