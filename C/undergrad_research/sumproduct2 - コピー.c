#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

                                           /* !関数 */
double gaussianRand(double, double);        /* ガウス雑音  */
double LLR(double);                         /* 対数尤度比  */


                                            /* !グローバル変数 */
int n=5;                                     /* 符号長(符号化後) */
const double Pi =3.141592;                   /* 円周率 */
double sigma=0.5,midium=0;                   /* 雑音のパラメタ*/


int main(void){                                  /* !メイン */
	
	int i=0;
	int send[100]={0};
	double codeword[100]={0},receive[100]={0},lamda[100]={0};   
	
	
	for(i=0;i<n;i++){                             /* 符号語作成(バイポーラ変換 0→+1,1→-1)*/
		codeword[i] = -1;
		printf("codeword[%0.2f]\n",codeword[i]);
	}
	
	
	srand((unsigned int)time(NULL));              /* 受信信号取得(ガウス雑音付加) */
	for(i=0;i<n;i++){                            
		receive[i] = codeword[i] + gaussianRand(sigma,midium);
		printf("receive[%0.5f]\n",receive[i]);
	}
	

	for(i=0;i<n;i++){                             /* 対数尤度比列作成(受信後に対する) */
		lamda[i]=LLR(receive[i]);
		printf("\nlamda[%0.5f]",lamda[i]);
	}
	
	
	return 0;
}









/*********** ガウス雑音 **************/
 double gaussianRand( double vd_stdev,double vd_meanValue )    //  引数01: 標準偏差   引数02: 平均値 //
{                                                              
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