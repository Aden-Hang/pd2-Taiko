#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
#include<stdlib.h>
using namespace std;
/*int data[9][9]={{0,2,1,0,6,0,5,9,0},
				{0,0,0,0,0,0,0,0,2},
				{4,0,0,2,0,5,0,6,3},
				{3,0,7,6,0,0,0,0,0},
				{0,9,5,0,0,0,3,2,0},
				{0,0,0,0,0,3,7,0,1},
				{9,3,0,4,0,2,0,0,7},
				{5,0,0,0,0,0,0,0,0},
				{0,1,2,0,9,0,6,3,0}};*/
int data[9][9]={{0,9,0,0,4,0,0,2,0},
				{0,0,1,0,0,6,0,0,7},
				{0,0,0,0,3,0,0,0,5},
				{7,0,0,2,0,0,0,0,8},
				{0,1,0,0,9,8,0,4,0},
				{2,0,0,4,0,0,0,0,6},
				{6,0,0,0,5,0,0,0,0},
				{9,0,0,3,0,0,8,0,0},
				{0,4,0,0,6,0,0,3,0}};
int map[90][10];

int main(){
	int i,j,m,s,k,g,check,limit=0,count,error,go,num,t;
	int alt[90][10]={0};
	int array[9];
	
	for(i=1;i<90;i++){
		for(j=0;j<10;j++){
			map[i][j]=j;
		}
	}
	for(i=0;i<9;i++){//�R���D�ئ����Ʀr 
		for(j=0;j<9;j++){
			if(data[i][j]!=0){
				map[10*i+j+1][0]=data[i][j];
				for(m=1;m<10;m++){
					map[10*i+j+1][m]=0;
				}
			}
		}
	}
	for(go=0;go<10000;go++){
		for(k=0;k<30;k++){
			for(i=1;i<90;i++){//�R���C 
				if(map[i][0]!=0){
					for(j=i/10*10+1;j<i/10*10+10;j++){
						map[j][map[i][0]]=0;
					}
				}
			}
			for(i=1;i<90;i++){//�R���� 
				if(map[i][0]!=0){
					for(j=i%10;j<i%10+81;j+=10){
						map[j][map[i][0]]=0;
					}
				}
			}
			for(i=0;i<21;i+=10){//�R����� 1 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=0;m<21;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=3;i<24;i+=10){//�R����� 2 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=3;m<24;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=6;i<27;i+=10){//�R����� 3 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=6;m<27;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=30;i<51;i+=10){//�R����� 4 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=30;m<51;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=33;i<54;i+=10){//�R����� 5 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=33;m<54;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=36;i<57;i+=10){//�R����� 6 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=36;m<57;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=60;i<81;i+=10){//�R����� 7 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=60;m<81;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=63;i<84;i+=10){//�R����� 8 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=63;m<84;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
			for(i=66;i<87;i+=10){//�R����� 9 
				for(j=i+1;j<i+4;j++){
					if(map[j][0]!=0){
						for(m=66;m<87;m+=10){
							for(s=m+1;s<m+4;s++){
								map[s][map[j][0]]=0;
							}
						}
					}
				}
			}
					
			for(m=0;m<90;m+=10){//��ߤ@�Ѷ�J 
				for(j=1;j<10;j++){
					check=0;
					for(i=m+1;i<m+10;i++){
						if(map[i][j]==j){
							check++;
						}
					}
					if(check==1){
						for(i=m+1;i<m+10;i++){
							if(map[i][j]!=0){
								map[i][0]=j;
								for(g=1;g<10;g++){
									map[i][g]=0;
								}	
							}
						}
					}
				}	
			}
			for(m=1;m<90;m++){//��ߤ@�Ѷ�J 
				if(m%10==0)continue;
				check=0;
				for(i=1;i<10;i++){
					if(map[m][i]==0){
						check++;
					}
				}
				if(check==8)
				for(i=1;i<10;i++){
					if(map[m][i]!=0){
						map[m][0]=i;
						map[m][i]=0;
					}
				}
			}
			for(m=1;m<90;m++){//�w�T�w �d�� 
				if(m%10==0)continue;
				if(map[m][0]!=0){
					for(i=1;i<10;i++){
						map[m][i]=0;
					}
				}
			}
		}
		error=0;
		for(i=0;i<81;i+=10){//���s�P�_�C 
			for(m=0;m<9;m++){
				array[m]=0;
			}
			for(j=i+1;j<i+10;j++){
				if(map[j][0]==1)array[0]++;	
				if(map[j][0]==2)array[1]++;	
				if(map[j][0]==3)array[2]++;	
				if(map[j][0]==4)array[3]++;	
				if(map[j][0]==5)array[4]++;	
				if(map[j][0]==6)array[5]++;	
				if(map[j][0]==7)array[6]++;	
				if(map[j][0]==8)array[7]++;	
				if(map[j][0]==9)array[8]++;	
			}
			for(s=0;s<9;s++){
				if(array[s]>1){
					error=1;
				}
			}
		}
		for(i=1;i<10;i++){//���s�P�_�� 
			for(m=0;m<9;m++){
				array[m]=0;
			}
			for(j=i;j<81+i;j+=10){
				if(map[j][0]==1)array[0]++;	
				if(map[j][0]==2)array[1]++;	
				if(map[j][0]==3)array[2]++;	
				if(map[j][0]==4)array[3]++;	
				if(map[j][0]==5)array[4]++;	
				if(map[j][0]==6)array[5]++;	
				if(map[j][0]==7)array[6]++;	
				if(map[j][0]==8)array[7]++;	
				if(map[j][0]==9)array[8]++;	
			}
			for(s=0;s<9;s++){
				if(array[s]>1){
					error=1;
				}
			}
		}
		for(m=0;m<9;m++){
				array[m]=0;
		}
		for(i=1;i<90;i++){//�P�_�C�ӼƦr�O�_�����E�� 
			
			if(i%10==0)continue;
			if(map[i][0]==1)array[0]++;	
			if(map[i][0]==2)array[1]++;	
			if(map[i][0]==3)array[2]++;	
			if(map[i][0]==4)array[3]++;	
			if(map[i][0]==5)array[4]++;	
			if(map[i][0]==6)array[5]++;	
			if(map[i][0]==7)array[6]++;	
			if(map[i][0]==8)array[7]++;	
			if(map[i][0]==9)array[8]++;	
			
		}
		for(s=0;s<9;s++){
				if(array[s]>9){
					error=1;
				}
			}
		for(i=1;i<90;i++)
			{
				if(i%10==0)continue;
				if(map[i][0]==0 && map[i][1]==0 && map[i][2]==0 && map[i][3]==0 && map[i][4]==0 && map[i][5]==0 && map[i][6]==0 && map[i][7]==0 && map[i][8]==0 && map[i][9]==0)
				{
					error=1;
					break;
				}
			}
		if(go==0)
			{
				for(i=1;i<90;i++)
				{
					for(j=0;j<10;j++)
					{
						alt[i][j]=map[i][j];
					}
				}
			}
		if(error==1){
			alt[limit/10][limit%10]=0;
			limit=0;
			for(g=1;g<90;g++){
				if(g%10==0)continue;
				for(s=0;s<10;s++){
					map[g][s]=alt[g][s];
				}
			}
		}
			for(g=1;g<90;g++){
				if(g%10==0)continue;
				for(s=0;s<10;s++){
					map[g][s]=alt[g][s];
				}
			}
		
		count=0;
		for(m=1;m<90;m++){//����� �q�� 
			if(m%10==0)continue;
			for(j=1;j<10;j++){
				if(map[m][j]==j){
					if(limit<10*m+j){
						map[m][0]=j;
						limit=10*m+j;
						count=1;
						for(g=1;g<10;g++){
							map[m][g]=0;
						}
						break;
					}
				}
				if(count==1)break;
			}
			if(count==1)break;
		}
		
		for(m=1;m<90;m++){//��ߤ@�Ѷ�J 
			if(m%10==0)continue;
			check=0;
			for(i=1;i<10;i++){
				if(map[m][i]==0){
					check++;
				}
			}
			if(check==8)
			for(i=1;i<10;i++){
				if(map[m][i]!=0){
					map[m][0]=i;
					map[m][i]=0;
				}
			}
		}
		for(m=1;m<90;m++){//�w�T�w �d�� 
			if(m%10==0)continue;
			if(map[m][0]!=0){
				for(i=1;i<10;i++){
					map[m][i]=0;
				}
			}
		}
	}
	if(error==1)cout<<error<<endl;	
	for(m=0;m<90;m+=10){
		for(i=0;i<10;i++){
			if(i==1)cout<<"-----------------"<<endl;
			for(j=m+1;j<m+10;j++){
				cout<<map[j][i]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}
	
	
	return 0;
}