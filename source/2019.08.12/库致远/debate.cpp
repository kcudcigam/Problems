#include<bits/stdc++.h>
using namespace std;
struct nok{
	int f;//是否支持 
	int val;
};
nok a[400005];
int b[400005],c[400005],b_1,c_1;
char x,y,z;
int f_1,f_2,k,n,su;
int s_h;//当前可加数 
bool cmp(nok x,nok y){
	return x.val >y.val;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x>>y>>k;
		if (x=='1' && y!='1') {
		a[i].f =1;
		f_1++;
	}
		if (y=='1' && x!='1') {
		a[i].f =2;
		f_2++;
	}
		if (x=='1' && y=='1') 
		{
		a[i].f =3;
		su+=k;
		s_h++; 
	    }
		a[i].val=k;
	}
	sort(a+1,a+n+1,cmp);
	if (f_1==0 || f_2==0){
	{
	for (int i=1;i<=s_h;i++){
	  if (i>n) break;
	  if (a[i].f ==3){
	  	s_h++;
	  }	else su+=a[i].val;
	}
    }
  }else {
  	for (int i=1;i<=n;i++){
  		if (a[i].f==1) b[++b_1]=a[i].val;
  		if (a[i].f==2) c[++c_1]=a[i].val;
  	}
	    sort(b+1,b+b_1+1,greater<int> () );
	    sort(c+1,c+c_1+1,greater<int> () );
	    int g=min(f_1,f_2);
	    for (int i=1;i<=g;i++){
	    	su+=b[i]+c[i];
		}
		for (int i=1;i<=s_h;i++){
	  if (i>n) break;
	  if (a[i].f !=0){
	  	s_h++;
	  }	else su+=a[i].val;
	}
	  }
	  
  
  
  cout<<su<<endl;
	return 0;
}


