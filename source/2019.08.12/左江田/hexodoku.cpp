#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int map[8][8]={0,0,0,0,0,0,0,0,
               0,0,1,2,0,0,0,0,
			   0,3,4,5,6,7,0,0,
			   0,8,9,10,11,12,13,0,
			   0,0,14,15,16,17,18,0,
			   0,0,19,20,21,22,23,24,
			   0,0,0,25,26,27,28,29,
			   0,0,0,0,0,30,31,0};
int x[32],y[32],tmap[8][8],n,k,num,okf;
int bok[32][32],boh[32][32],bol1[32][32],bol2[111][32];
int dfs(int pos){
	if(okf==1){
		return 0;
	}
	if(tmap[x[pos]][y[pos]]!=0){
		if(pos==31){
			k--;
			if(k==0){
				okf=1;
				printf("Found\n");
				for(int i=1;i<=31;++i){
					printf("%d ",tmap[x[i]][y[i]]);
				}printf("\n");
			}
		}
		else{
			dfs(pos+1);
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		if( (boh[x[pos]][i]==0&&bol1[y[pos]][i]==0&&bol2[y[pos]-x[pos]+31][i]==0)&&
		    (bok[5][i]==0||!(map[x[pos]][y[pos]]==1||map[x[pos]][y[pos]]==2||map[x[pos]][y[pos]]==5||map[x[pos]][y[pos]]==4||map[x[pos]][y[pos]]==6||map[x[pos]][y[pos]]==10||map[x[pos]][y[pos]]==11))&&
		    (bok[9][i]==0||!(map[x[pos]][y[pos]]==3||map[x[pos]][y[pos]]==4||map[x[pos]][y[pos]]==8||map[x[pos]][y[pos]]==9||map[x[pos]][y[pos]]==10||map[x[pos]][y[pos]]==14||map[x[pos]][y[pos]]==15))&&
		    (bok[12][i]==0||!(map[x[pos]][y[pos]]==6||map[x[pos]][y[pos]]==7||map[x[pos]][y[pos]]==12||map[x[pos]][y[pos]]==11||map[x[pos]][y[pos]]==13||map[x[pos]][y[pos]]==17||map[x[pos]][y[pos]]==18))&&
		    (bok[16][i]==0||!(map[x[pos]][y[pos]]==10||map[x[pos]][y[pos]]==11||map[x[pos]][y[pos]]==15||map[x[pos]][y[pos]]==16||map[x[pos]][y[pos]]==17||map[x[pos]][y[pos]]==21||map[x[pos]][y[pos]]==22))&&
		    (bok[20][i]==0||!(map[x[pos]][y[pos]]==14||map[x[pos]][y[pos]]==15||map[x[pos]][y[pos]]==19||map[x[pos]][y[pos]]==20||map[x[pos]][y[pos]]==21||map[x[pos]][y[pos]]==25||map[x[pos]][y[pos]]==26))&&
		    (bok[23][i]==0||!(map[x[pos]][y[pos]]==17||map[x[pos]][y[pos]]==18||map[x[pos]][y[pos]]==22||map[x[pos]][y[pos]]==23||map[x[pos]][y[pos]]==24||map[x[pos]][y[pos]]==28||map[x[pos]][y[pos]]==29))&&
		    (bok[27][i]==0||!(map[x[pos]][y[pos]]==21||map[x[pos]][y[pos]]==22||map[x[pos]][y[pos]]==26||map[x[pos]][y[pos]]==27||map[x[pos]][y[pos]]==28||map[x[pos]][y[pos]]==30||map[x[pos]][y[pos]]==31))){
			if(map[x[pos]][y[pos]]==1||map[x[pos]][y[pos]]==2||map[x[pos]][y[pos]]==5||map[x[pos]][y[pos]]==4||map[x[pos]][y[pos]]==6||map[x[pos]][y[pos]]==10||map[x[pos]][y[pos]]==11){
				bok[5][i]=1;
			}
			if(map[x[pos]][y[pos]]==3||map[x[pos]][y[pos]]==4||map[x[pos]][y[pos]]==8||map[x[pos]][y[pos]]==9||map[x[pos]][y[pos]]==10||map[x[pos]][y[pos]]==14||map[x[pos]][y[pos]]==15){
				bok[9][i]=1;
			}
			if(map[x[pos]][y[pos]]==6||map[x[pos]][y[pos]]==7||map[x[pos]][y[pos]]==12||map[x[pos]][y[pos]]==11||map[x[pos]][y[pos]]==13||map[x[pos]][y[pos]]==17||map[x[pos]][y[pos]]==18){
				bok[12][i]=1;
			}
			if(map[x[pos]][y[pos]]==10||map[x[pos]][y[pos]]==11||map[x[pos]][y[pos]]==15||map[x[pos]][y[pos]]==16||map[x[pos]][y[pos]]==17||map[x[pos]][y[pos]]==21||map[x[pos]][y[pos]]==22){
				bok[16][i]=1;
			}
			if(map[x[pos]][y[pos]]==14||map[x[pos]][y[pos]]==15||map[x[pos]][y[pos]]==19||map[x[pos]][y[pos]]==20||map[x[pos]][y[pos]]==21||map[x[pos]][y[pos]]==25||map[x[pos]][y[pos]]==26){
				bok[20][i]=1;
			}
			if(map[x[pos]][y[pos]]==17||map[x[pos]][y[pos]]==18||map[x[pos]][y[pos]]==22||map[x[pos]][y[pos]]==23||map[x[pos]][y[pos]]==24||map[x[pos]][y[pos]]==28||map[x[pos]][y[pos]]==29){
				bok[23][i]=1;
			}
			if(map[x[pos]][y[pos]]==21||map[x[pos]][y[pos]]==22||map[x[pos]][y[pos]]==26||map[x[pos]][y[pos]]==27||map[x[pos]][y[pos]]==28||map[x[pos]][y[pos]]==30||map[x[pos]][y[pos]]==31){
				bok[27][i]=1;
			}
			tmap[x[pos]][y[pos]]=i;
			boh[x[pos]][i]=1;
			bol1[y[pos]][i]=1;
			bol2[y[pos]-x[pos]+31][i]=1;
			if(pos==31){
				k--;
				if(k==0){
					printf("Found\n");
					okf=1;
					for(int j=1;j<=31;++j){
						printf("%d ",tmap[x[j]][y[j]]);
					}printf("\n");
				}
			}
			else{
				dfs(pos+1);
			}
			if(map[x[pos]][y[pos]]==1||map[x[pos]][y[pos]]==2||map[x[pos]][y[pos]]==5||map[x[pos]][y[pos]]==4||map[x[pos]][y[pos]]==6||map[x[pos]][y[pos]]==10||map[x[pos]][y[pos]]==11){
				bok[5][i]=0;
			}
			if(map[x[pos]][y[pos]]==3||map[x[pos]][y[pos]]==4||map[x[pos]][y[pos]]==8||map[x[pos]][y[pos]]==9||map[x[pos]][y[pos]]==10||map[x[pos]][y[pos]]==14||map[x[pos]][y[pos]]==15){
				bok[9][i]=0;
			}
			if(map[x[pos]][y[pos]]==6||map[x[pos]][y[pos]]==7||map[x[pos]][y[pos]]==12||map[x[pos]][y[pos]]==11||map[x[pos]][y[pos]]==13||map[x[pos]][y[pos]]==17||map[x[pos]][y[pos]]==18){
				bok[12][i]=0;
			}
			if(map[x[pos]][y[pos]]==10||map[x[pos]][y[pos]]==11||map[x[pos]][y[pos]]==15||map[x[pos]][y[pos]]==16||map[x[pos]][y[pos]]==17||map[x[pos]][y[pos]]==21||map[x[pos]][y[pos]]==22){
				bok[16][i]=0;
			}
			if(map[x[pos]][y[pos]]==14||map[x[pos]][y[pos]]==15||map[x[pos]][y[pos]]==19||map[x[pos]][y[pos]]==20||map[x[pos]][y[pos]]==21||map[x[pos]][y[pos]]==25||map[x[pos]][y[pos]]==26){
				bok[20][i]=0;
			}
			if(map[x[pos]][y[pos]]==17||map[x[pos]][y[pos]]==18||map[x[pos]][y[pos]]==22||map[x[pos]][y[pos]]==23||map[x[pos]][y[pos]]==24||map[x[pos]][y[pos]]==28||map[x[pos]][y[pos]]==29){
				bok[23][i]=0;
			}
			if(map[x[pos]][y[pos]]==21||map[x[pos]][y[pos]]==22||map[x[pos]][y[pos]]==26||map[x[pos]][y[pos]]==27||map[x[pos]][y[pos]]==28||map[x[pos]][y[pos]]==30||map[x[pos]][y[pos]]==31){
				bok[27][i]=0;
			}
			tmap[x[pos]][y[pos]]=0;
			boh[x[pos]][i]=0;
			bol1[y[pos]][i]=0;
			bol2[y[pos]-x[pos]+31][i]=0;
		}
	} 
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	for(int i=1;i<=7;++i){
		for(int j=1;j<=7;++j){
			if(map[i][j]!=0){
				x[map[i][j]]=i;
				y[map[i][j]]=j;
			}
		}
	}
	scanf("%d %d",&n,&k);
	for(int i=1;i<=31;++i){
		scanf("%d",&num);
		tmap[x[i]][y[i]]=num;
		boh[x[i]][num]=1;
		bol1[y[i]][num]=1;
		bol2[y[i]-x[i]+31][num]=1;
		if(map[x[i]][y[i]]==1||map[x[i]][y[i]]==2||map[x[i]][y[i]]==5||map[x[i]][y[i]]==4||map[x[i]][y[i]]==6||map[x[i]][y[i]]==10||map[x[i]][y[i]]==11){
			bok[5][num]=1;
		}
		if(map[x[i]][y[i]]==3||map[x[i]][y[i]]==4||map[x[i]][y[i]]==8||map[x[i]][y[i]]==9||map[x[i]][y[i]]==10||map[x[i]][y[i]]==14||map[x[i]][y[i]]==15){
			bok[9][num]=1;
		}
		if(map[x[i]][y[i]]==6||map[x[i]][y[i]]==7||map[x[i]][y[i]]==12||map[x[i]][y[i]]==11||map[x[i]][y[i]]==13||map[x[i]][y[i]]==17||map[x[i]][y[i]]==18){
			bok[12][num]=1;
		}
		if(map[x[i]][y[i]]==10||map[x[i]][y[i]]==11||map[x[i]][y[i]]==15||map[x[i]][y[i]]==16||map[x[i]][y[i]]==17||map[x[i]][y[i]]==21||map[x[i]][y[i]]==22){
			bok[16][num]=1;
		}
		if(map[x[i]][y[i]]==14||map[x[i]][y[i]]==15||map[x[i]][y[i]]==19||map[x[i]][y[i]]==20||map[x[i]][y[i]]==21||map[x[i]][y[i]]==25||map[x[i]][y[i]]==26){
			bok[20][num]=1;
		}
		if(map[x[i]][y[i]]==17||map[x[i]][y[i]]==18||map[x[i]][y[i]]==22||map[x[i]][y[i]]==23||map[x[i]][y[i]]==24||map[x[i]][y[i]]==28||map[x[i]][y[i]]==29){
			bok[23][num]=1;
		}
		if(map[x[i]][y[i]]==21||map[x[i]][y[i]]==22||map[x[i]][y[i]]==26||map[x[i]][y[i]]==27||map[x[i]][y[i]]==28||map[x[i]][y[i]]==30||map[x[i]][y[i]]==31){
			bok[27][num]=1;
		}
	}
	dfs(1);
	if(okf==0){
		printf("No way");
	}
} 
