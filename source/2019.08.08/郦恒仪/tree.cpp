#include<bits/stdc++.h>
#include<vector>
using namespace std;
int lianshu,rudu[200005],mu[200005],h[200005],fdas,fasd,n,m,i,j,k,l,s,d,f,r,baba[2000005],se[2000005];
vector<int>xx[200005];
vector<int>lian[200005];
void jianshu(int x){
	h[x]=1;
	for(int i=0;i<xx[x].size();i++){
		if(h[xx[x][i]]==0){
			baba[xx[x][i]]=x;
			jianshu(xx[x][i]);
		}
	}
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>fdas;
	for(fasd=1;fasd<=fdas;fasd++){
		memset(h,0,sizeof(h));
		cin>>n>>m;
		for(i=1;i<=n;i++){
			xx[i].clear();
		}
	//	cout<<n<<" "<<m<<"!"<<endl;
		for(i=1;i<n;i++){
			cin>>f>>r;
			xx[f].push_back(r);
			xx[r].push_back(f);
		}
		jianshu(1);
		for(i=1;i<=n;i++){
			cin>>se[i];
		}
		for(i=1;i<=n;i++){
			cin>>mu[i];
		}
		memset(rudu,0,sizeof(rudu));
		for(i=1;i<=n;i++){
			rudu[baba[i]]++;
		}
		lianshu=0;
		for(i=1;i<=n;i++){
			if(rudu[i]==0){
				lianshu++;
				lian[lianshu].clear();
				lian[lianshu].push_back(i);
				l=i;
				while(baba[l]!=0){
					l=baba[l];
					lian[lianshu].push_back(l);
				}
			}
		}
		for(i=1;i<=lianshu;i++){
			for(j=0;j<lian[i].size()-m+1;j++){
				if(se[lian[i][j]]!=mu[lian[i][j]]){
					for(k=j;k<=j+m-1;k++){
						se[lian[i][k]]=(se[lian[i][k]]+1)%2;
					}
				}
			}
		}
		d=0;
		for(i=1;i<=n;i++){
			if(se[i]!=mu[i]){
				d=1;
				break;
			}
		}
		if(d==0){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}

