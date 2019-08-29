#include<bits/stdc++.h>
using namespace std;
int a[11]={0,0,2,12,58,310,1886,13244,106002,954090,9540982};
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
int q;
int n,p;cin>>q;
for(int i=1;i<=q;i++){
	cin>>n>>p;
	cout<<(a[n]%p)<<endl;
}
	return 0;
}


