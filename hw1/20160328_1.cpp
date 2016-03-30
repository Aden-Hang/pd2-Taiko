#include<iostream> 
using namespace std;

extern int array[9][9]={{7,0,0,6,0,0,0,0,8},
						{0,0,6,1,0,0,0,0,3},
						{0,0,4,9,0,0,7,1,0},
						{0,0,7,0,1,0,0,0,5},
						{0,8,0,0,4,3,0,2,0},
						{4,0,0,2,0,0,8,0,0}, 
						{0,4,5,0,0,7,1,0,0},
						{2,0,0,0,0,1,9,0,0},
						{1,0,0,0,0,8,0,0,7}};
				

int main()
{
	int i,j,k,row,col,l,r,m,s,check,num; 
	int stop[9][9] ;
	int block[90][10];
	//�ƻsarray
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			stop[i][j]=array[i][j];
		}
	} 
	//�ŧiblock�}�C[90][10] 
	for(i=1;i<90;i++)
	{
		for(j=0;j<10;j++)
		{
			block[i][j]=j;
		}
	}
	//��J�w���A�ñN����ܬ�0 
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(stop[i][j]!=0)
			{
				block[(10*i)+j+1][0]=stop[i][j];
				for(k=1;k<10;k++)
				{
					block[(10*i)+j+1][k]=0;
				}
			}
		}
	}
			//����� 
			for(i=1;i<90;i++)
			{
				if(block[i][0]!=0)//i=26
				{
					row=(i/10);		//row=2
					col=(i%10);		//col=6
					for(k=(10*row);k<10*(row+1);k++)
					{
						block[k][block[i][0]]=0;
					}
				}
			}
			//�C���� 
			for(i=1;i<90;i++)
			{
				if(block[i][0]!=0)//i=26
				{
					row=(i/10);		//row=2
					col=(i%10);		//col=6
					for(k=col;k<90;k+=10)
					{	
						block[k][block[i][0]]=0;
		 			}
				}
			}
			//������
			for(l=0;l<9;l+=3)
			{
				for(i=l;i<l+21;i+=10)
				{
					for(j=i+1;j<i+4;j++)
					{
						if(block[j][0]!=0)
						{
							for(k=l;k<l+21;k+=10)
							{
								for(r=k+1;r<k+4;r++)
								{
									block[r][block[j][0]]=0;
								}
							}
						}
					}
				}
			}
			for(l=30;l<39;l+=3)
			{
				for(i=l;i<l+21;i+=10)
				{
					for(j=i+1;j<i+4;j++)
					{
						if(block[j][0]!=0)
						{
							for(k=l;k<l+21;k+=10)
							{
								for(r=k+1;r<k+4;r++)
								{
									block[r][block[j][0]]=0;
								}
							}
						}
					}
				}
			}
			for(l=60;l<69;l+=3)
			{
				for(i=l;i<l+21;i+=10)
				{
					for(j=i+1;j<i+4;j++)
					{
						if(block[j][0]!=0)
						{
							for(k=l;k<l+21;k+=10)
							{
								for(r=k+1;r<k+4;r++)
								{
									block[r][block[j][0]]=0;
								}
							}
						}
					}
				}
			}
			//�C�ߤ@��
			for(l=0;l<9;l++)
			{
				for(k=1;k<10;k++)
				{	
					check=0;
					for(i=10*l+1;i<10*l+10;i++)
					{
						if(block[i][k]==k)
						{
							check++;
						}
					}
					if(check==1)
					{
						for(m=10*l+1;m<10*l+10;m++)
						{
							if(block[m][k]==k)
							{
								block[m][0]=k;
								for(s=1;s<10;s++)
								{
									block[m][s]=0;
								}
							}
						}
					}
				}
			}
			//��ߤ@��
			for(l=0;l<9;l++)
			{
				for(k=1;k<10;k++)
				{	
					check=0;
					for(i=l+1;i<82+l;i+=10)
					{
						if(block[i][k]==k)
						{
							check++;
						}
					}
					if(check==1)
					{
						for(m=l+1;m<82+l;m+=10)
						{
							if(block[m][k]==k)
							{
								block[m][0]=k;
								for(s=1;s<10;s++)
								{
									block[m][s]=0;
								}
							}
						}
					}
				}
			}
			//��J�ߤ@�� 
			for(i=1;i<90;i++)
			{
				if(i%10==0)continue;
				check=0;
				for(j=1;j<10;j++)
				{
					if(block[i][j]==0)
					{
						check++;
					}	
					if(block[i][j]!=0)
					{
						num=block[i][j];	
					}
				}
				(check==8)?block[i][0]=num:num=0;
			}
			//��J���סA��l�k0 
			for(i=1;i<90;i++)
			{
				if(i%10==0)continue;
				if(block[i][0]!=0)
				{
					for(j=1;j<10;j++)
					{
						block[i][j]=0;
					}
				}
			}
			//print block;
			for(i=1;i<90;i++)
			{
				if(i%10==0)
				{
					cout<<endl;
					continue;
				}
				for(j=0;j<10;j++)
				{
					cout<<block[i][j]<<" ";
				}
				cout<<endl;
			}

	return 0;	
}