﻿#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>     // getch/

// 疑似命令
#define _CRT_SECURE_NO_WARNINGS       // C++ エラー

//#define N 504                         // 符号長(符号化後)
#define FILENAME1 "10"                  // 検査行列のファイル名
#define SEED (unsigned int)time(NULL)   // 乱数の設定  ランダム((unsigned int)time(NULL))
#define Printi(X) printf("%d ",X)       // 出力関数(int,double,改行)
#define Printd(X) printf("%0.3f ",X)
#define Printn printf("\n")

// 関数
void   check_matrix(FILE *fp);                         // 検査行列読み込み
double gaussianRand(double,double);                    // ガウス雑音 
void LLR(double*);                                     // 対数尤度比計算
double sign(double);                                   // signal関数
double gallager_f(double);                             // gallager_f関数
int    Puncturing(int,int);                            // 一様乱数(min-max)

// 出力用関数
void output_check_matrix();                            // 検査行列
void output_message_to_lamda();                        // 送信,符号,受信語,尤度
void output_alpha_to_beta();                           // アルファ＆ベータ
void output_bit_reliability_to_estimation();           // ビット信頼度→推定語

// 宣言
int n;                                               // 符号長(符号化後(検査行列))
int m;                                               // 検査記号数
int iteration=10;                                    // 反復回数
int trial=100;                                         // 試行回数
double R = 0.5;                                      // 符号化率
double sigma, midium=0,SN=2;                         // 雑音のパラメタ (SN比で計算)
int *message, *estimation;                           // 送信語(組織符号データ部分),推定語
double *codeword, *receive;                          // 符号語,受信語
int r_max, c_max;                                    // 最大行重み,最大列重み
int *r_weight, *c_weight;                            // 各行重み数,各列重み数
int **r_list, **c_list, **ref_list;                  // 行・列・twin(ひも付け)リスト
double **alpha, **beta, *lamda, *bit_reliability;    // アルファ,ベータ,ラムダ,ビット信頼度

/************ メイン関数 ***************************************************************/
int main(void)
{
     FILE *fp;
     int i=0,j=0,k=0,h=0,loop=0;                          // ループカウンタ
     int temp,count,error,parity;                            // 計算記憶用(int)
     double sum, sum2, product, temp1;                // 計算記憶用(double)
     sigma = sqrt((pow(10,(-SN/10)))/(2*R));          // 雑音の分散計算
    
     fp = fopen(FILENAME1,"r");                       // 検査行列読み込み,配列(matrix)作成
     if(fp == NULL){
          printf("error:指定の検査行列ファイルは存在しません\n");              
          getch();                                     // 停止用
          return 0;
     }
     check_matrix(fp);
     fclose(fp);
     //output_check_matrix();                         // !出力,検査行列
    
    
    
    srand(SEED);                                      // 乱数発生
    
    
//     printf("試行回数入力");
//     scanf("%d",&trial);
     for(h=0;h<trial;h++){                            // 試行回数
     printf("%d回目",h+1);
    
    
    
     for(i=0;i<n;i++){                                // 送信語決定
          message[i] = 0;     //全0送信
//          if(50 < Puncturing(1,100))                   // ランダム送信
/*          message[i] = 1;
          else
          message[i] = 0; */
     }
    
    
     for(i=0;i<n;i++){  
         if(message[i] == 0)                          // 変調(BPSK) 0→1,1→-1 (簡易)
               codeword[i] = 1;
          else
              codeword[i] = -1;
     }
    
                                         // 受信信号取得(AWGN:ガウス雑音付加)
     for(i=0;i<n;i++){
          receive[i] = codeword[i] + gaussianRand(sigma,midium);
     }
    
    
     LLR(receive);                                    // 受信語の対数尤度比計算 (関数)
     //output_message_to_lamda();                     // !出力,送信～対数尤度
    
    
     for(i=0;i<m;i++){                                // beta初期化
          for(j=0;j<r_weight[i];j++){
               beta[i][j] = 0;
          }
     }
    
     for(loop=0;loop<iteration;loop++){               // Sumproduct開始 反復開始
    
     for(i=0;i<m;i++){                                // 行処理
          for(j=0;j<r_weight[i];j++){
               product = 1.0;
               sum = 0.0;
               for(k=0;k<r_weight[i];k++){
                    if(k != j){
                         temp1 = lamda[r_list[i][k]] + beta[i][k];
                         sum += gallager_f(fabs(temp1));
                         product *= sign(temp1);
                    }
               }
               alpha[i][j] = product * gallager_f(sum);    //α     //     Printd(alpha[i][j]);
          }//Printn;
     }
    
    
     for(i=0;i<n;i++){                               // 列処理
          sum2 = 0;
          for(j=0;j<c_weight[i];j++){
               sum = 0;
               for(k=0;k<c_weight[i];k++){
                    if(k != j){
                         sum += alpha[c_list[i][k]][ref_list[i][k]];
                         }
               }
               beta[c_list[i][j]][ref_list[i][j]] = sum;   // B(beta)
               sum2 +=  alpha[c_list[i][j]][ref_list[i][j]];
          }
          bit_reliability[i] = lamda[i] + sum2;       // ビット信頼度
     }
     // output_alpha_to_beta();
    
    
     for(i=0;i<n;i++){                               // 推定語作成（AWGN通信路）
          if(bit_reliability[i]>=0){
               estimation[i]=1;
          } else{
               estimation[i]=0;
          }
     }
     // output_bit_reliability_to_estimation();      // !出力,ビット信頼度～推定語
    
    
     parity = 0;
     for(i=0;i<m;i++){                               // パリティ検査
          temp = 0;
          for(k=0;k<r_weight[i];k++){
               temp += estimation[r_list[i][k]];
          }
          if(temp % 2 != 0)
               parity += 1;
     }
    
     if(parity == 0){
          printf("検査終了 %d",parity);
          break;
     }
    
     error = 0;
     for(i=0;i<n;i++){
          if(codeword[i] != estimation[i])
               error += 1;
     } printf("誤り%d ",error);
    
     } printf("反復回数%d\n",loop);                  // 反復終了 ******************
    
     }                                               // 試行終了    
    
     return 0;
}
/*************** 検査行列読み込み＆配列確保 ***********************************************/
void check_matrix(FILE *fp){
    
     int i=0,j=0,k=0;                          // ループカウンタ
    
     fscanf(fp,"%d/n",&n);
     fscanf(fp,"%d/n",&m);
     fscanf(fp,"%d/n",&r_max);
     fscanf(fp,"%d/n",&c_max);
    
     r_weight = (int *)malloc(sizeof(int) * m);
     if(r_weight == NULL) exit(0);
     for(i=0;i<m;i++){
          fscanf(fp,"%d",&r_weight[i]);
     }
     c_weight = (int *)malloc(sizeof(int) * n);
     if(c_weight == NULL) exit(0);
     for(i=0;i<n;i++){
          fscanf(fp,"%d",&c_weight[i]);
     }
     r_list = (int **)malloc(sizeof(int*) * m);
     if(r_weight == NULL) exit(0);
     for(i=0;i<m;i++){
          r_list[i] = (int *)malloc(sizeof(int) * r_max);
          for(j = 0;j<r_weight[i];j++){
               fscanf(fp,"%d",&r_list[i][j]);
               r_list[i][j] -= 1;
          }
     }
     c_list = (int **)malloc(sizeof(int*) * n);
     ref_list = (int **)malloc(sizeof(int*) * n);
     for(i = 0; i < n; i++){
          c_list[i] = (int *)malloc(sizeof(int) * c_max);
          ref_list[i] = (int *)malloc(sizeof(int) * c_max);
          for(j = 0; j < c_weight[i]; j++){
               fscanf(fp,"%d",&c_list[i][j]);
               c_list[i][j] -= 1;
               //リストの関連付け
               for(k = 0; k < r_weight[c_list[i][j]]; k++){
                    if(r_list[c_list[i][j]][k] == i){
                         ref_list[i][j] = k;
                         break;
                    }
               }
          }
     }
    
     message = (int *)malloc(sizeof(int) * n);                 // 組織符号 データ部分
     estimation = (int *)malloc(sizeof(int) * n);
     codeword = (double *)malloc(sizeof(double) * n);
     receive = (double *)malloc(sizeof(double) * n);
     bit_reliability = (double *)malloc(sizeof(double) * n);
    
     alpha = (double **)malloc(sizeof(double*) * m);
     for(i=0;i<m;i++){
          alpha[i] = (double *)malloc(sizeof(double) * r_max);
     }
     beta = (double **)malloc(sizeof(double*) * n);
     for(i=0;i<n;i++){
          beta[i] = (double *)malloc(sizeof(double) * c_max);
     }
     lamda = (double *)malloc(sizeof(double) * n);
}
/*** 出力 **** 検査行列読み込み確認用 ***********************************************/
void output_check_matrix(void){
    
     int i=0,j=0,k=0;                          // ループカウンタ
    
     Printi(n),Printi(m),Printi(r_max),Printi(c_max),Printn;
     for(i=0;i<m;i++){
          Printi(r_weight[i]);
     } Printn;
     for(i=0;i<n;i++){
          Printi(c_weight[i]);
     } Printn;
     for(i=0;i<m;i++){
          for(j = 0;j<r_weight[i];j++){
               Printi(r_list[i][j]+1);
          }Printn;
     } Printn;
     for(i=0;i<n;i++){
          for(j = 0;j<c_weight[i];j++){
               Printi(c_list[i][j]+1);
          }Printn;
     }Printn;
     for(i=0;i<n;i++){
          for(j = 0;j<c_weight[i];j++){
               Printi(ref_list[i][j]);
          }Printn;
     }Printn;
}
/*********** ガウス雑音 *********************************************************************/
double gaussianRand( double vd_stdev,double vd_meanValue )    //  引数01: 標準偏差   引数02: 平均値 //
{                                                             
    const double Pi =3.14159265358979; 
    double rtnNum = 0.0;                                        //  リターン用                                   
    static int sw = 0;                                          //  リターンの切替用                             
                                                            
    double randNum_1;                                           //  乱数その１                                   
    double randNum_2;                                           //  乱数その２                                   
    double whiteGaussianNoise_1;                                //  ホワイトガウスノイズその１                   
    static double whiteGaussianNoise_2;                         //  ホワイトガウスノイズその２                   
                    
    if( sw == 0 )                                               //  スイッチが0か          
    {                                                           //  スイッチが0なら      
        sw = 1;                                                 //  スイッチ切替え   
        randNum_1 = ((double)rand()) / RAND_MAX;                //  (0,9]の乱数取得     
        randNum_2 = ((double)rand()) / RAND_MAX;                //  (0,9]の乱数取得    
                                          
        whiteGaussianNoise_1 = vd_stdev * sqrt( -2.0 * log( randNum_1 ) ) *    //  正規乱数１ 
                                   cos( 2.0 * Pi * randNum_2 ) + vd_meanValue;
        whiteGaussianNoise_2 = vd_stdev * sqrt( -2.0 * log( randNum_1 ) ) *    //  正規乱数２
                                   sin( 2.0 * Pi * randNum_2 ) + vd_meanValue;
                                                           
        rtnNum = whiteGaussianNoise_1;                          //  リターンに正規乱数１を設定
    }                                                      
    else                                                        //  スイッチが0以外の場合 
    {                                                         
        sw = 0;                                                 //  スイッチ切替え
                                             
        rtnNum = whiteGaussianNoise_2;                          //  リターンに正規乱数２を設定    
    }                              
                             
    return( rtnNum );                                           //  生成した正規乱数を返して終了   
}
/********** 対数尤度比計算 *******************************************************************/
void LLR (double receive[]){                                   // 受信語 → 対数尤度
    
     int i;
     for(i=0;i<n;i++){                               
     lamda[i] = 2 * receive[i] / pow(sigma,2.0);
     }
     return;
}
/***出力* 送信語～対数尤度比 ****************************************************************/
void output_message_to_lamda(void){
     int i;
/*     for(i=0;i<n;i++){                               
          Printd(message[i]);
     } Printn;
*/     for(i=0;i<n;i++){                              
          Printd(codeword[i]);
     } Printn;
     for(i=0;i<n;i++){                               
          Printd(receive[i]);
     } Printn;
     for(i=0;i<n;i++){                               
          Printd(lamda[i]);
     } Printn;
}
/********** シグナル関数 ********************************************************** *********/
double sign(double temp)
{
     if(temp >= 0)
          return 1;
     else
          return -1;
}
/************ Gallager関数 *****************************************************************/
double gallager_f(double x)
{
     double numerator, denominator;
     if(x < 0.00001)
     // gallager_f(0.00001)=12.21;                             // アンダーフロー対策
          return 12.21;    
     if(x > 1000)
          return 0.000001;                                        // オーバーフロー対策
          numerator = exp(x) + 1;
          denominator = exp(x) - 1;
     return log(numerator/denominator);    
}
/***出力* アルファ～ベータ ****************************************************************/
void output_alpha_to_beta(void){
    
     int i,j,k;                          // ループカウンタ
    
     for(i=0;i<m;i++){
          for(j=0;j<c_weight[i];j++){           // アルファ出力
               Printd(alpha[i][j]);
               Printn;
          }
     }
     for(i=0;i<n;i++){
          for(j=0;j<c_weight[i];j++){           // ベータ出力
               Printd(alpha[i][j]);
               Printn;
          }
     }
     return;
}
/***出力* ビット信頼度→推定語 *************************************************************/
void output_bit_reliability_to_estimation(void){
    
     int i,j,k;                          // ループカウンタ
    
     for(i=0;i<n;i++){         
     //     Printd(bit_reliability[i]);     // ビット信頼度
     Printi(estimation[i]);              // 推定語
     }Printn,Printi(i),Printn;
}
/************* 一様乱数(for puncturing) ***************************************************/
int Puncturing(int min,int max){
     return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}