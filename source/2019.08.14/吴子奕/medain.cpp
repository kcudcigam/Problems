#include<bits/stdc++.h>
using namespace std;
int read(){
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int a1[500009];
int a2[500009];
int main(){
	freopen("medain.in","r",stdin);
	freopen("medain.out","w",stdout);
   int n,m;
    n=read();m=read();
    for(int i=1;i<=n;i++)
       a1[i]=read();
       for(int i=1;i<=n;i++)
           a2[i]=read();
           for(int i=1;i<=m;i++){
           	int k;
    	 k=read();
    	 if(k==1){
    	 	int x,y,z;
    	 	x=read();y=read();z=read();
			 if(x==0){
    	 		a1[y]=z;
			 }
			 if(x==1){		 	
    	 		a2[y]=z;			
			 }
			 }
		if(k==2){
			int l1,l2,r1,r2;
		 	l1=read();r1=read();l2=read();r2=read();
		 	int num=(r1+r2-l1-l2+2)/2+1;int j=l1;int p=l2;
		 	for(;p<=r2,j<=r1,num!=0;){		 		
		 			if(a1[j]<a2[p]){
		 				j++;
					 num--;
					 if(num==0)cout<<a1[j-1]<<endl;
				 }else {
				 	p++;
				 	num--;
				 	if(num==0)cout<<a2[p-1]<<endl;
				 }
			 }
		}
		   }
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int read(){
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int a1[500009][3];
int a2[500009][3];
int main(){
    int n,m;
    n=read();m=read();
    for(int i=1;i<=n;i++)
       a1[i][1]=read();
       for(int i=1;i<=n;i++)
           a2[i][1]=read();
           a1[0][2]=1;
           a2[0][2]=1;
           for(int i=1;i<=n;i++){
           	int j=max(a1[i-1][2],a1[i][2]);
           	for(;j<=n;j++){
           		
				   if(a2[j][1]>=a1[i][1]){	
				   a2[j][2]=i;
					   break;
				   }a1[i][2]=j;
				   
           		
			   }
		   }
		   for(int i=1;i<=n;i++){
           	int j=max(a2[i-1][2],a2[i][2]);
           	for(;j<=n;j++){
           		
				   if(a1[j][1]>=a2[i][1]){	
				   a1[j][2]=i;
					   break;
				   }a2[i][2]=j;
				   
           		
			   }
		   }for(int i=1;i<=n;i++){
    	 	cout<<a1[i][2]<<" "<<a2[i][2]<<endl;
		 }
    for(int i=1;i<=m;i++){
    	 int k;
    	 k=read();
    	 if(k==1){
    	 	int x,y,z;
    	 	x=read();y=read();z=read();
    	 	if(x==0){
    	 		int flag=0;
    	 		if(z>=a1[y][1])flag=1;
    	 		a1[y][1]=z;
    	 		if(flag==1)
				 for(int j=a1[y+1][2];j>=a1[y][2];j--){
    	 			if(z>=a2[j][1])a1[y][2]=j;
				 }
				if(flag==0)
				for(int j=a1[y-1][2];j<=a1[y][2];j++){
    	 			if(z>=a2[j][1])a1[y][2]=j;
				 }
				
			 }
			 if(x==1){
			 	int flag=0;
    	 		if(z>=a2[y][1])flag=1;
    	 		a2[y][1]=z;
    	 		if(flag==1)
				 for(int j=a2[y+1][2];j>=a2[y][2];j--){
    	 			if(z>=a1[j][1])a2[y][2]=j;
				 }
				if(flag==0)
				for(int j=a2[y-1][2];j<=a2[y][2];j++){
    	 			if(z>=a1[j][1])a2[y][2]=j;
				 }
				
			 }
		 }
		 if(k==2){
		 	int l1,l2,r1,r2;
		 	l1=read();r1=read();l2=read();r2=read();
		 	int num=(r1+r2-l1-l2+2)/2+1;
		 	while(num){
		 		if((a1[l1][2]<=l2&&a1[l1][2])){
		 			if((abs(a2[l2][2]-l1)+1)>=num){
		 				cout<<l1+num-1<<" "<<a1[l1+num-1][1]<<endl;
		 			break;
					 }
					 
					 if(a2[l1][2]+1<=r1){
					 l1+=(a2[l1][2]+1-l1);
					 num-=(a2[l2][2]-l1+1);}
					 else {
					   num-=(r1-l1+1);
					   l2+=num-1;
					   cout<<a2[l2][1]<<endl;break;
				 }
				 if((a2[l2][2]<=l1&&a2[l2][2])){
		 			if((abs(a1[l1][2]-l2)+1)>=num){
		 				cout<<l2+num-1<<" "<<a2[l2+num-1][1]<<endl;
		 			break;
					 }
					 if(a1[l2][2]+1<=r2){
					 l1+=(a1[l2][2]+1-l2);num-=(a1[l1][2]-l2+1);}
					 else {
					   num-=(r2-l2+1);
					   l1+=num-1;
					   cout<<a1[l1][1]<<endl;break;
				 }
				 }
				 
				 if(a2[l2][2]==0){
		 			if((abs(a2[l2][2]-l1)+1)>=num){
		 				cout<<l1+num-1<<" "<<a1[l1+num-1][1]<<endl;
		 			break;
					 }
					 if(a2[l1][2]+1<=r1){
					 l1+=(a2[l1][2]+1-l1);num-=(a2[l2][2]-l1+1);}
					 else {
					   num-=(r1-l1+1);
					   l2+=num-1;
					   cout<<a2[l2][1]<<endl;break;
				 }
				 }
				 if(a1[l1][2]==0){
		 			if((abs(a1[l1][2]-l2)+1)>=num){
		 				cout<<l2+num-1<<" "<<a2[l2+num-1][1]<<endl;
		 			break;
					 }
					 if(a1[l2][2]+1<=r2){
					 l1+=(a1[l2][2]+1-l2);num-=(a1[l1][2]-l2+1);}
					 else {
					   num-=(r2-l2+1);
					   l1+=num-1;
					   cout<<a1[1][1]<<endl;break;
				 }
				 }
				 
			 }
		 }
    }
	
}
	return 0;
}
*/

