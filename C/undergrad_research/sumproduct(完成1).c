#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

                                                        /* !関数 */
double gaussianRand(double, double);                    /* ガウス雑音  */
double LLR(double);                                     /* 対数尤度比  */
double sign(double,double);                             /* signal関数(ラムダ,ベータ) */
double gallager_f(double);                              /* gallager_f関数 */


                                            /* !グローバル変数 */
int n=4;                                     /* 符号長(符号化後) */
double sigma=0.5,midium=0;                   /* 雑音のパラメタ*/
int iteration = 10;                          /* 反復回数 */ 


int main(void)
{
	
	
	FILE *fp;
	int i=0,j=0,k=0,loop=0;
	int send[100]={0},estimate[100]={0};
	double codeword[100]={0},receive[100]={0};
	int row_max,column_max,row,column;
	int row_weight[252][10];
	int column_weight[10][504];
	double alpha[252][10]={0},beta[10][504]={0},lamda[100]={0};
	double sum,product,credit;
	double error;
	
	
	for(i=0;i<n;i++){                             /* 符号語作成(バイポーラ変換 0→+1,1→-1)*/
		codeword[i] = 1;
	/*	printf("codeword[%d]=%0.2f\n",i+1,codeword[i]); */
	}
	
	
	srand((unsigned int)time(NULL));              /* 受信信号取得(ガウス雑音付加) */
	for(i=0;i<n;i++){                            
		receive[i] = codeword[i] + gaussianRand(sigma,midium);
	/*	printf("receive[%d]=%0.5f\n",i+1,receive[i]); */
	}
	
	
	for(i=0;i<n;i++){                             /* 対数尤度比列作成(受信後に対する) */
		lamda[i]=LLR(receive[i]);
	/*	printf("\nlamda[%d]=%0.5f",i+1,lamda[i]); */
	}
	
	
	
/*	fp = fopen("parity matrix10-1.txt","r"); 
*/	fp = fopen("parity matrix10-1 - コピー.txt","r");            /* 検査行列パラメタ */           
		fscanf(fp,"%d%d%d%d",&column,&row,&row_max,&column_max);
	/*	printf("\n%d %d %d %d\n\n",column,row,row_max,column_max);	*/
		
		
	fp = fopen("parity matrix10-2 - コピー.txt","r");            /* 行重み位置 */
	for(i=0; i<row ; i++){
		for(j=0; j<row_max ;j++){
			fscanf(fp,"%d",&row_weight[i][j]);
		/*	printf("%d ",row_weight[i][j]);  */                 /* 行重み位置確認 */
		}  printf("\n"); 
	}
	printf("\n");
	
	
	fp = fopen("parity matrix10-3 - コピー.txt","r");            /* 列重み位置 */
	for(i=0; i<column ; i++){
		for(j=0; j<column_max ;j++){
			fscanf(fp,"%d",&column_weight[i][j]);
		/*	printf("%d ",column_weight[i][j]);  */              /* 列重み位置確認 */     
		} printf("\n");
	}  printf("\n");
	
	fclose(fp);                                                  /* クローズ */
	
	
	for(loop=0;loop < iteration; loop++){                          /* 反復開始 */
	
	
	for(i=0; i<row; i++){                                            /* 行処理 */
		for(j=0; j < row_max ; j++){
			 sum=0;
			 product=1;
			for(k=0; k < row_max ;k++){
				product *= sign(lamda[ row_weight[i][k]-1] , beta[i][row_weight[i][k]-1] );
				sum += gallager_f(fabs(lamda[row_weight[i][k]-1]));
			}  
			alpha[i][row_weight[i][j]-1] = product * sign(lamda[row_weight[i][j]-1] , beta[i][row_weight[i][j]-1]) 
			              * gallager_f(sum - gallager_f(fabs(lamda[row_weight[i][j]-1] + beta[i][row_weight[i][j]-1])));
		}   for(j=0; j<column; j++){
		 /*		printf("alpha(%d)(%d)=%0.3f  ",i+1,j+1,alpha[i][j]); */    /* アルファ確認 */
			} printf("\n");
	} 
	
	
	
	for(j=0;j<column;j++){                                           /* 列処理 */
		for(i=0;i< column_max;i++){ 
			  sum=0;
			for(k=0; k <= column_max-1; k++){
			 	sum += alpha[column_weight[j][k]-1][j];
			}  
			beta[column_weight[j][i]-1][j] = sum - alpha[column_weight[j][i]-1][j];
		}  
	}
	
	printf("\n");
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
	/*		printf("beta(%d)(%d)=%0.3f   ",i+1,j+1,beta[i][j]);   */    /* ベータ確認 */
		} printf("\n");
	} printf("\n");
	
	
	
	for(j=0;j<column;j++){                                           /* ビット信頼度計算 */
		credit = 0;
		for(k=0;k<column_max ;k++){                            
		credit += alpha[column_weight[j][k]-1][j];	
		}
		credit += lamda[j];
		
		if(0 <= credit){                                             /* 推定語の決定 */
			estimate[j] = 0;
		} else {
			estimate[j] = 1;
		}
	/*	printf("%0.3f %0.3f %0.3f 推定語%d=%d \n",lamda[j],credit-lamda[j],credit,j+1,estimate[j]); */
	} printf("\n");                                                 /* 推定語確認 */
	
	
	
	int parity=0;                                                       /* パリティ検査 */
	for(i=0;i<column;i++){
		for(k=0;k<row_max;k++){
			parity += estimate[row_weight[i][k]-1];
		/*	printf("\n%d %d  %d",row_weight[i][k],estimate[row_weight[i][k]-1],parity); */ /* 検査確認 */
		} 
	} printf("\n\n");
	
	if(parity % 2 == 0) printf("パリティ検査終了\n");
	if(parity % 2 == 0) break; 
	
	
	}                                                                    /* 反復終了 */
	
	printf("反復回数%d\n",loop);
	
	
	                                                                    /* 送信後と受信語確認 */
	printf("送信語と復号語\n");                                         
	for(i=0;i<n;i++){
		printf("%d",send[i]);	
	}printf("\n");
		for(i=0;i<n;i++){
		printf("%d",estimate[i]);	
	}printf("\n");
	
	
	
	for(i=0;i<n;i++){                                                    /* 誤り率 */
		if(send[i] != estimate[i]){
		error += 1.0;}
	} 
	printf("誤り率%f\n",error/(double)n);
	
	
	return 0;
}


 /********** シグナル関数 *************/
double sign(double lamda,double beta)
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

/*********** ガウス雑音 **************/
 double gaussianRand( double vd_stdev,double vd_meanValue )    //  引数01: 標準偏差   引数02: 平均値 //
{                                                              
    const double Pi =3.14159265358979;  
    double rtnNum = 0.0;                                        //  リターン用                                    //
    static int sw = 0;                                          //  リターンの切替用                              //
                                                             
    double randNum_1;                                           //  乱数その１                                    //
    double randNum_2;                                           //  乱数その２                                    //
    double whiteGaussianNoise_1;                                //  ホワイトガウスノイズその１                    //
    static double whiteGaussianNoise_2;                         //  ホワイトガウスノイズその２                    //
                     
 
    if( sw == 0 )                                               //  スイッチが0か                                 //
    {                                                           //  スイッチが0なら                               //
        sw = 1;                                                 //  スイッチ切替え                                //
        randNum_1 = ((double)rand()) / RAND_MAX;                //  (0,9]の乱数取得                               //
        randNum_2 = ((double)rand()) / RAND_MAX;                //  (0,9]の乱数取得                               //
                                                                //                                                //
        whiteGaussianNoise_1 = vd_stdev * sqrt( -2.0 * log( randNum_1 ) ) *    //  正規乱数１                     //
                                   cos( 2.0 * Pi * randNum_2 ) + vd_meanValue; //                                 //
        whiteGaussianNoise_2 = vd_stdev * sqrt( -2.0 * log( randNum_1 ) ) *    //  正規乱数２                     //
                                   sin( 2.0 * Pi * randNum_2 ) + vd_meanValue; //                                 //
                                                                //                                                //
        rtnNum = whiteGaussianNoise_1;                          //  リターンに正規乱数１を設定                    //
    }                                                           //                                                //
    else                                                        //  スイッチが0以外の場合                         //
    {                                                           //                                                //
        sw = 0;                                                 //  スイッチ切替え                                //
                                                                //                                                //
        rtnNum = whiteGaussianNoise_2;                          //  リターンに正規乱数２を設定                    //
    }                                                           //                                                //
                                                                //                                                //
    return( rtnNum );                                           //  生成した正規乱数を返して終了                  //
}                          
/***********************************/

/************* 対数尤度比計算 **************/
double LLR (double receive ){                                 /* 受信語 */

	double lamda;
	lamda = 2 * receive / pow(sigma,2.0);
	return lamda;
}