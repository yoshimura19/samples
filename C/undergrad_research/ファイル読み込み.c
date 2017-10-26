#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int sign(double,double);                             /* シグナル関数(ラムダ,ベータ) */
double gallager_f(double);


int main(void)
{
	
	
	FILE *fp;
	int i=0,j=0,k=0;
	int row_max,column_max,row,column;
	int row_weight[252][10];
	int column_weight[10][504];
	double alpha[252][10]={0};
	double beta[10][504]={0};
	double sum,product;
	double lamda[500]={-9.3,2.5,-14.6,-8.2,-14.4};
	int temp;
	
/*	fp = fopen("parity matrix10-1.txt","r"); 
*/	fp = fopen("parity matrix10-1 - コピー.txt","r");            /* 検査行列パラメタ */           
		fscanf(fp,"%d%d%d%d",&column,&row,&row_max,&column_max);
		printf("%d %d %d %d\n\n",column,row,row_max,column_max);	
		
		
	fp = fopen("parity matrix10-2 - コピー.txt","r");            /* 行重み位置 */
	for(i=0; i<row ; i++){
		for(j=0; j<row_max ;j++){
			fscanf(fp,"%d",&row_weight[i][j]);
			printf("%d ",row_weight[i][j]);                   
		}  printf("\n"); 
	}
	printf("\n");
	
	
	fp = fopen("parity matrix10-3 - コピー.txt","r");            /* 列重み位置 */
	for(i=0; i<column ; i++){
		for(j=0; j<column_max ;j++){
			fscanf(fp,"%d",&column_weight[i][j]);
			printf("%d ",column_weight[i][j]);                    
		} printf("\n");
	}
	printf("\n");
	
	
	
	/*fclose(fp);   */                                      /* クローズ */
	
	/*
	printf("%d %d\n",row_weight[0][0],row_weight[0][1]);
	printf("%d %d\n",row_weight[1][0],row_weight[1][1]);
	printf("%d %d\n",row_weight[2][0],row_weight[2][1]);
	printf("%d %d\n",row_weight[3][0],row_weight[3][1]);
	
	printf("\n");
	
	printf("%d %d\n",column_weight[0][0],column_weight[0][1]);
	printf("%d %d\n",column_weight[1][0],column_weight[1][1]);
	printf("%d %d\n",column_weight[2][0],column_weight[2][1]);
	printf("%d %d\n",column_weight[3][0],column_weight[3][1]);
	*/
	
	
	i=0;
	k=0;
	printf("%f\n\n",gallager_f(fabs(lamda[(row_weight[i][k]-1)]))); 
	printf("%f\n",gallager_f(0.000183));
	printf("%f\n",gallager_f(gallager_f(fabs(-9.3))));
	printf("%f\n",gallager_f(fabs(2.5)));
	printf("%f\n",gallager_f(fabs(-14.6)));
	printf("%f\n",gallager_f(fabs(-8.2)));
	printf("%f\n",gallager_f( abs(lamda[ row_weight[i][k]-1 ]))); 
	
	
	
	i=0;
/*	for(i=0; i<row; i++){        */                     /* 行処理 */
		for(j=0; j < row_max ; j++){
			 sum=0;
			 product=1;
			for(k=0; k < row_max ;k++){
			product *= sign(lamda[ row_weight[i][k]-1] , beta[i][row_weight[i][k]-1] );
			sum = gallager_f( fabs(lamda[ row_weight[i][k]-1 ] /*+ beta[i][row_weight[i][k]-1]*/));
			}  /* printf("product=%0.1f, sum=%0.3f\n",product,sum); */ 
		alpha[i][j] =( (product / (sign(lamda[row_weight[i][j]-1] , beta[i][j])))
		             * gallager_f(sum - gallager_f(fabs(lamda[(row_weight[i][j]-1)] + beta[i][j]))));
		} printf("\n"); printf("product=%0.1f, sum=%f\n",product,sum);
		/*printf("alpha=%f\n",alpha[i][j]); */
/*	}*/

/*	for(i=0;i<column;i++){
		printf("%0.1f ",lamda[i]);
	}
	
	printf("\n\n%.5f\n\n",beta[3][4]);
*/	
	
	return 0;
}


 /********** シグナル関数 *************/
int sign(double lamda,double beta)
{
	if(lamda + beta >= 0)
		return 1;
	else
		return -1;
}


/************ Gallager関数 *************/
double gallager_f(double x)
{
	double numerator, denominator;
	if(x < 0.00001){
	/* gallager_f(0.00001)=12.21; */                 /* アンダーフロー対策 */
		return 12.21;
	} else {
		numerator = exp(x) + 1;
		denominator = exp(x) - 1;
		return log(numerator/denominator);
	}
}