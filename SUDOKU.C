#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main (){
	int a[81],b[81],i,j,sudoku_no,block_no,num=0,column,rows,condition=0;

	//this loop sets all values in array to zero, so to remove all garbage value
	for(i=0;i<81;i++){
 		a[i]=0;
	}

	//sudoku_no is a variable which will be used for selecting sudoku from many,
	// which are yet to be uploaded.
	sudoku_no=1;
	if(sudoku_no==1){

		//setting values
		a[1]=4; a[2]=6; a[3]=5; a[6]=3; a[9]=1;
		a[12]=4; a[13]=3; a[15]=7; a[17]=5; a[18]=7;
		a[23]=8; a[27]=5; a[33]=8; a[37]=8; a[38]=7;
		a[41]=6; a[43]=5; a[45]=9; a[46]=6; a[49]=8;
		a[51]=1; a[52]=4; a[54]=8; a[55]=5; a[56]=4;
		a[57]=1; a[58]=2; a[64]=2; a[66]=8; a[67]=6;
		a[76]=5; a[78]=2; a[79]=1; a[80]=8;

		// setting for condition checking mechanism
		for(i=0;i<=80;i++){
			if(a[i]==0){
				b[i]=i;
			}
			else{
				b[i]=81;
			}
		}
	}

	//gaming loop starts
	while(1){

		//displaying sudoku
		printf("\nx-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n\n");
		printf("|------------+------------+------------|\n");
		printf("|  %d   %d   %d |  %d   %d   %d |  %d   %d   %d |\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
		printf("|  %d   %d   %d |  %d   %d   %d |  %d   %d   %d |\n",a[9],a[10],a[11],a[12],a[13],a[14],a[15],a[16],a[17]);
		printf("|  %d   %d   %d |  %d   %d   %d |  %d   %d   %d |\n",a[18],a[19],a[20],a[21],a[22],a[23],a[24],a[25],a[26]);
		printf("|------------+------------+------------|\n");
		printf("|  %d   %d   %d |  %d   %d   %d |  %d   %d   %d |\n",a[27],a[28],a[29],a[30],a[31],a[32],a[33],a[34],a[35]);
		printf("|  %d   %d   %d |  %d   %d   %d |  %d   %d   %d |\n",a[36],a[37],a[38],a[39],a[40],a[41],a[42],a[43],a[44]);
		printf("|  %d   %d   %d |  %d   %d   %d |  %d   %d   %d |\n",a[45],a[46],a[47],a[48],a[49],a[50],a[51],a[52],a[53]);
		printf("|------------+------------+------------|\n");
		printf("|  %d   %d   %d |  %d   %d   %d |  %d   %d   %d |\n",a[54],a[55],a[56],a[57],a[58],a[59],a[60],a[61],a[62]);
		printf("|  %d   %d   %d |  %d   %d   %d |  %d   %d   %d |\n",a[63],a[64],a[65],a[66],a[67],a[68],a[69],a[70],a[71]);
		printf("|  %d   %d   %d |  %d   %d   %d |  %d   %d   %d |\n",a[72],a[73],a[74],a[75],a[76],a[77],a[78],a[79],a[80]);
		printf("|------------+------------+------------|\n");


		while (1)
		{
			//taking block no as input
			printf("Enter Block Number:- ");
			scanf("%d",&block_no);

			if(block_no-1==b[block_no-1]){
				while (1)
				{
					//taking no. to be entered as input
					printf("Enter a Number(1-9):- ");
					scanf("%d",&num);

					//checking if entered no. is valid or not
					if(num>0 && num<10 || num==33){
					    if(num>0 && num<10){
                            a[block_no-1]=num;
					    }
						break;
					}
					else{
						printf("No. must be between 1-9\n");
					}
				}
				break;
			}
			else{
				printf("You can't enter in block no %d\n",block_no);
			}
		}

        //column scan
		condition=0;
		for(column=0;column<=8;column++){
			for(rows=column;rows<=column+72;rows+=9){
				for(i=column;i<=column+72;i+=9){
					if(rows!=i && a[rows]!=0 && a[i]!=0 && a[rows]==a[i]){
						condition=1;
						break;
                    }
                }
				if(condition==1){
					break;
                }
            }
			if(condition==1){
				break;
            }
        }

        // row scan
		for(column=0;column<=72;column+=9){
			for(rows=column;rows<=column+8;rows++){
				for(i=column;i<=column+8;i++){
					if(rows!=i && a[rows]!=0 && a[i]!=0 && a[rows]==a[i]){
						condition=1;
						break;
					}
				}
				if(condition==1){
					break;
				}
			}
			if(condition==1){
				break;
			}
		}

		//block scan
		for(column=0;column<=8;column+=3){
			for(rows=column;rows<=column+54;rows+=27){
				i=rows;
				while (i<=rows+20)
				{
					j=rows;
					while (j<=rows+20)
					{
					    if(i!=j && a[i]!=0 && a[j]!=0 && a[i]==a[j]){
							condition=1;
							break;
						}
						if((j+1)%3==0){
							j+=7;
						}
						else
						{
							j+=1;
						}
					}
					if((i+1)%3==0){
						i+=7;
					}
					else
					{
						i+=1;
					}
					if(condition==1){
						break;
					}
				}
				if(condition==1){
						break;
				}
			}
			if(condition==1){
				break;
			}
		}

		// zero scan
		for(i=0;i<=80;i++){
			if(a[i]==0){
				condition=1;
				break;
			}
		}

		// exit condition
		if(num==33 || condition==0){
			break;
		}
	}
	printf("\n              Winner Winner Chicken Dinner!!\n");
	return 1;
}