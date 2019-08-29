#include<bits/stdc++.h>
using namespace std;
bool a[2050][2050],b[3][3],c[2050][2050];
int al,ar,n,m,i,j,k,l,s,d,f,r,h[2050][2055],tx[100005],ty[100005];
void gett(){
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			bool k=b[i][j];
			for(int ii=0;ii<=al;ii++){
				for(int jj=0;jj<=ar;jj++){
					c[i*al+i+ii][j*ar+j+jj]=!(a[ii][jj]^k);
				}
			}
		}
	}
	al=(al+1)*2-1;
	ar=(ar+1)*2-1;
	for(int i=0;i<=al;i++){
		for(int j=0;j<=ar;j++){
			a[i][j]=c[i][j];
		}
	}
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	cin>>n>>m;
	a[0][0]=true;
	a[0][1]=true;
	a[1][0]=true;
	a[1][1]=false;
	b[0][0]=true;
	b[0][1]=true;
	b[1][0]=true;
	b[1][1]=false;
	al=1;
	ar=1;
	if(n<=1050&&m<=1050){
		while(al/2<=n||ar/2<=m){
			gett();
		}
		/*for(i=0;i<=al;i++){
			for(j=0;j<=ar;j++){
				if(a[i][j]==true){
					cout<<".";
				}
				else{
					cout<<"*";
				}
			}
			cout<<endl;
		}*/
		if(a[n][m]==true){
			cout<<"infinity"<<endl;
		}
		else{
			f=1;
			r=1;
			tx[f]=n;
			ty[f]=m;
			memset(h,0,sizeof(h));
			while(f<=r){
			//	cout<<f<<" "<<r<<endl;
				h[tx[f]][ty[f]]=1;
				if(a[tx[f]-1][ty[f]]==false&&h[tx[f]-1][ty[f]]==0){
					r++;
					tx[r]=tx[f]-1;
					ty[r]=ty[f];
					h[tx[r]][ty[r]]=1;
				}
				if(a[tx[f]+1][ty[f]]==false&&h[tx[f]+1][ty[f]]==0){
					r++;
					tx[r]=tx[f]+1;
					ty[r]=ty[f];
					h[tx[r]][ty[r]]=1;
				}
				if(a[tx[f]][ty[f]-1]==false&&h[tx[f]][ty[f]-1]==0){
					r++;
					tx[r]=tx[f];
					ty[r]=ty[f]-1;
					h[tx[r]][ty[r]]=1;
				}
				if(a[tx[f]][ty[f]+1]==false&&h[tx[f]][ty[f]+1]==0){
					r++;
					tx[r]=tx[f];
					ty[r]=ty[f]+1;
					h[tx[r]][ty[r]]=1;
				}
				f++;
			}
			cout<<r<<endl;
		}
	}
	else{
		cout<<"infinity"<<endl;
	}
	return 0;
}


