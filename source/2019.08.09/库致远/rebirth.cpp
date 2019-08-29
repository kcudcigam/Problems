#include<bits/stdc++.h>
using namespace std;
int num,Ans_Min,tol,a[4000][4000],aa[4000][4000],n,m,dis[100000],k[100000],u[1000000],v[1000000],w[1000000];
int work(int x){
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (aa[i][k]+aa[k][j]<aa[i][j]) aa[i][j]=aa[i][k]+aa[k][j];
			}
		}
	}
	return aa[1][x];
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
    cin>>num;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	for (int j=1;j<=n;j++){
    		if (i==j){
    			a[i][j]=0;
    			a[j][i]=0;
			}else a[i][j]=a[j][i]=999999999;
		}
	}
    for (int i=1;i<=m;i++){
    	cin>>u[i*2-1]>>v[i*2-1]>>w[i*2-1];
    	u[i*2]=v[i*2-1];
    	v[i*2]=u[i*2-1];
    	w[i*2]=w[i*2-1];
    	a[u[i*2-1]][v[i*2-1]]=w[i*2-1];
    	a[u[i*2]][v[i*2]]=w[i*2];
	}
	tol=m*2;
	k[1]=0;
	for (int i=2;i<=n;i++){
		Ans_Min=-1;
		for (int j=1;j<=tol;j++){
			if (u[j]==i){
			//	cout<<"sgsg"<<i<<endl;
				int sb=w[j],g;
				int f1=a[i][j],f2=a[j][i];
				a[i][j]=999999999;
				a[j][i]=999999999;
				for (int ii=1;ii<=n;ii++){
					for (int jj=1;jj<=n;jj++){
						aa[ii][jj]=a[ii][jj];
					}
				}
			    g=work(i);
			  //  cout<<g<<endl;
				a[i][j]=f1;
				a[j][i]=f2;
		        if (g>Ans_Min ) Ans_Min=g; 
			}
		}
		if (Ans_Min>=99999999) k[i]=-1;else k[i]=Ans_Min;
	}
    for 	(int i=1;i<=n;i++){
    	cout<<k[i]<<" ";
	}

	return 0;
}

