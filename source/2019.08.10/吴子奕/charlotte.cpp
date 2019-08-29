#include<bits/stdc++.h>
using namespace std;
/*void read(int &x){
	int f=1,r=0;char ch=getchar();
	do ch=getchar(); while(!isdigit(ch)&&ch!='-');
	if(ch=='-'){f=-1;ch=getchar();}
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	x=f*r;
}*/
int workkk(){
	int n;
	cin>>n;
	int a[10009][4];
	for(int i=1;i<=n;i++){
	cin>>a[i][1]>>a[i][2]>>a[i][3];
	}	int t2,x2,y2,t1,x1,y1;t1=x1=y1=0;
	for(int i=1;i<=n;i++){
	   if(i>=2){
	   	t1=a[i-1][1];
	   	x1=a[i-1][2];
	   	y1=a[i-1][3];
	   }
		t2=a[i][1];x2=a[i][2];y2=a[i][3];
		if(t2%2!=(x2+y2)%2){
			cout<<"No"<<endl;
			return 0;
		}
		if((t2-t1)<(abs(x2-x1)+abs(y2-y1))){
			cout<<"No"<<endl;
			return 0;
		}
		
	}cout<<"Yes"<<endl;
		
	return 0;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
int t;
   cin>>t;
   for(int g=1;g<=t;g++){
   	workkk();
   }
    
	return 0;
}


