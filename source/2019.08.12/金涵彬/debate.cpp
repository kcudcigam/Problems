#include<bits/stdc++.h>
using namespace std;
int a,b;
int n;
struct Info{
	char fi,se;
	int z;
}sz[400010];
bool pd(Info aa,Info bb){
	return aa.z>bb.z;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sz[i].fi>>sz[i].se>>sz[i].z;
		if(sz[i].fi=='1'){
			a++;
		}
		if(sz[i].se=='1'){
			b++;
		} 
	}
	int x=0,y=0;
	int hy=0;
	int sl=min(a,b);
	int tt=0;
	sort(sz+1,sz+n+1,pd);
	for(int i=1;i<=n;i++){
		if(b<=a&&y<sl){
			if(sz[i].se=='1'){
				y++;
				if(sz[i].fi=='1'){
					x++;
				}
				hy+=sz[i].z;
				sz[i].z=-1;
				tt++;
			}
		}else{
			if(sz[i].fi=='1'&&x<sl){
				x++;
				if(sz[i].se=='1'){
					y++;
				}
				hy+=sz[i].z;
				sz[i].z=-1;
				tt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(b<=a&&x<sl){
			if(sz[i].fi=='1'&&sz[i].z!=-1){
				x++;
				if(sz[i].se=='1'){
					y++;
				}
				hy+=sz[i].z;
				sz[i].z=-1;
				tt++;
			}
		}else{
			if(sz[i].se=='1'&&y<sl&&sz[i].z!=-1){
				y++;
				if(sz[i].fi=='1'){
					x++;
				}
				hy+=sz[i].z;
				sz[i].z=-1;
				tt++;
			}
		}
	}
	
	for(int i=1;i<=n&&tt<sl*2;i++){
		if(sz[i].z!=-1){
			sl--;
			hy+=sz[i].z;
			tt++;
		}
	}
	cout<<hy<<endl;
	return 0;
}
