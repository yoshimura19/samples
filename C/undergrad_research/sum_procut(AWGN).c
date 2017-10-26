
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
#define nrand() ( double )rand() / RAND_MAX	/*区間[0,1]で一様分布する乱数*/
#include <conio.h> /* getch */
#pragma warning(disable : 4996)

#define MAX(a, b) ((a) > (b) ? (a) : (b))	//最大値を決定
#include "mt19937ar.h"


//宣言
int n;				//符号長
int m;				//検査記号数
int rmax;			//最大行重み
int cmax;			//最大列重み
int *row_weight;	//行重み
int *col_weight;	//列重み
int **row_list;		//行リスト
int **col_list;		//列リスト
int **twin_list;	//行と列を関連付けるリスト
double R;			//符号化率


int **H;			//検査行列
int **H1;
int **H2;
int **inv_H1;		//逆行列
int **G;			//生成行列

int temp;			//仮変数
double temp_d;		//仮変数

int *message;		//情報ビット
int *code_word;		//符号語
double *sending_word;	//送信語
double *received_word;	//受信語
double *lambda;		//対数尤度比

double noise;

double **alpha;
double **beta;

double *bit_reliability;	//ビット信頼度
int *estimated_word;	//推定語

double average_iteration = 0;


/*************** コセット ***************/
int *coset;	//
int *r;
int *s;		
/****************************************/


//検査行列読み込み・メモリ確保
void init_decoder(FILE *fp){
    int i,j,k;		//ループカウンタ

    fscanf(fp,"%d\n",&n);
    fscanf(fp,"%d\n",&m);
    fscanf(fp,"%d\n",&rmax);
    fscanf(fp,"%d\n",&cmax);

    row_weight = (int *)malloc(sizeof(int)*m);
	for(i = 0; i < m; i++)
		fscanf(fp,"%d",&row_weight[i]);
    col_weight = (int *)malloc(sizeof(int)*n);
	for(j = 0; j < n; j++)
		fscanf(fp,"%d",&col_weight[j]);

	row_list = (int **)malloc(sizeof(int*)*m);
	for(i = 0; i < m; i++){
		row_list[i] = (int *)malloc(sizeof(int)*rmax);
		//各行の１が立っている列番号
		for(j = 0; j < row_weight[i]; j++){
			fscanf(fp,"%d",&row_list[i][j]);
			row_list[i][j] -= 1;
		}
	}
	col_list = (int **)malloc(sizeof(int*)*n);
	twin_list = (int **)malloc(sizeof(int*)*n);
	for(i = 0; i < n; i++){
		col_list[i] = (int *)malloc(sizeof(int)*cmax);
		twin_list[i] = (int *)malloc(sizeof(int)*cmax);
		//各列の１が立っている行番号
		for(j = 0; j < col_weight[i]; j++){
			fscanf(fp,"%d",&col_list[i][j]);
			col_list[i][j] -= 1;
			//リストの関連付け
			for(k = 0; k < row_weight[col_list[i][j]]; k++){
				if(row_list[col_list[i][j]][k] == i){
					twin_list[i][j] = k;
					break;
				}


			}

		}
	}

	alpha = (double **)malloc(sizeof(double*)*m);
    for (i = 0; i < m; i++)
		alpha[i] = (double *)malloc(sizeof(double)*rmax);
    beta = (double **)malloc(sizeof(double*)*n);
    for (i = 0; i < n; i++)
		beta[i] = (double *)malloc(sizeof(double)*cmax);

	H = (int **)malloc(sizeof(int*)*m);

	message = (int *)malloc(sizeof(int)*m);
	code_word = (int *)malloc(sizeof(int)*n);
	sending_word = (double *)malloc(sizeof(double)*n);	
	received_word = (double *)malloc(sizeof(double)*n);
	lambda = (double *)malloc(sizeof(double)*n);
	bit_reliability = (double *)malloc(sizeof(double)*n);
	estimated_word = (int *)malloc(sizeof(int)*n);

/*************** コセット ***************/
	coset = (int *)malloc(sizeof(int)*n);
	r = (int *)malloc(sizeof(int)*m);
	s = (int *)malloc(sizeof(int)*m);
/****************************************/

}


//検査行列
void init_generate_H(void){
	int i,j;			//ループカウンタ
	for(i = 0; i < m; i++){
		H[i] = (int *)malloc(sizeof(int)*n);
	}
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++)	//初期化
			H[i][j]=0;
		for(j = 0; j < row_weight[i]; j++)
			H[i][row_list[i][j]] = 1;
	}
}

//生成行列作成
void init_generate_G(void){
	int i,j,k;			//ループカウンタ
	int randam1;
	int randam2;
	H1 = (int **)malloc(sizeof(int*)*m);
	H2 = (int **)malloc(sizeof(int*)*m);
	inv_H1 = (int **)malloc(sizeof(int*)*m);
	G = (int **)malloc(sizeof(int*)*m);
	for(i = 0; i < m; i++){
		H1[i] = (int *)malloc(sizeof(int)*m);
		H2[i] = (int *)malloc(sizeof(int)*m);
		inv_H1[i] = (int *)malloc(sizeof(int)*m);
		G[i] = (int *)malloc(sizeof(int)*n);
	}
	int count;

	//検査行列の分割・逆行列作成用の単位行列
	//H=[ H1^T | H2^T ]
	for(i = 0; i < m; i++){
		for(j = 0; j < m; j++){
			H1[i][j] = H[j][i];
			H2[i][j] = H[j][m+i];
			if(i == j)
				inv_H1[i][j]=1;
			else
				inv_H1[i][j]=0;
		}
	}

	count = 0;
	//逆行列の作成（掃き出し法）
	for(i = 0; i < m; i++){
		//対角成分が0のとき1にする処理
		if(H1[i][i] == 0){
			for(j = i; j < m; j++){
				if(i != j && H1[j][i] == 1){
					//行を交換
					for(k = 0; k < m; k++){
						temp = H1[i][k];
						H1[i][k] = H1[j][k];
						H1[j][k] = temp;
						temp = inv_H1[i][k];
						inv_H1[i][k] = inv_H1[j][k];
						inv_H1[j][k] = temp;
					}
					break;		//ループj離脱
				}
			}
		}

		//対角成分以外を0にする処理
		for(j = 0; j < m; j++){
			if(i != j && H1[j][i] == 1){
				for(k = 0; k < m; k++){
					H1[j][k] += H1[i][k];
					inv_H1[j][k] += inv_H1[i][k];
					H1[j][k] = H1[j][k]%2;
					inv_H1[j][k] = inv_H1[j][k]%2;
				}
			}
		}

		if(H1[i][i] == 0){
//			printf("生成行列作成失敗:%d列目\n",i);
//			printf("enterで終了\n");
//			getch(); //プロンプト停止用
//			exit (0);

			for(j = 0; j < m; j++){
				randam1 = (int)floor(nrand() * m);
				if(i < randam1){
					break;
				}
			}

			for(j = 0; j < m; j++){
				randam2 = m+j;
				if(H2[j][i] == 1)
					break;
			}

/*

			printf("ランダム1:%d\n",randam1);
			printf("ランダム2:%d\n",randam2);
*/


			for(j = 0; j < m; j++){
				temp = H[j][randam1];
				H[j][randam1] = H[j][randam2];
				H[j][randam2] = temp;

				H1[randam1][j] = H[j][randam1];
				H2[randam2-m][j] = H[j][randam2];

			}

			for(j = 0; j < m; j++){
				temp = 0;
				for(k = 0; k < n; k++){
					if(H[j][k] == 1){
						row_list[j][temp] = k;		//行リスト
						temp += 1;
					}
				}
			}

			//各列の１が立っている行番号
			for(j = 0; j < col_weight[randam1]; j++){
				temp = col_list[randam1][j];
				col_list[randam1][j] = col_list[randam2][j];
				col_list[randam2][j] = temp;

				//リストの関連付け
				for(k = 0; k < row_weight[col_list[randam1][j]]; k++){
					if(row_list[col_list[randam1][j]][k] == randam1){
						twin_list[randam1][j] = k;
					}
					if(row_list[col_list[randam2][j]][k] == randam2){
						twin_list[randam2][j] = k;
					}
				}
			}

			i = -1;
		}
		count += 1;

		if(count > 10000){
			printf("生成行列が作成できない検査行列\n",i);
			getch(); //プロンプト停止用
			exit (0);
		}

	}

	//生成行列G
	for(i = 0; i < m; i++){
		for(j = 0; j < m; j++){
			temp = 0;
			for(k = 0;k < m; k++){
				temp += H2[i][k] * inv_H1[k][j];
			}
			G[i][j] = temp%2;
		}
		for(j = m; j < n; j++){
			if(j == i+m)
				G[i][j] = 1;
			else
				G[i][j] = 0;
		}
	}

}

//生成行列作成(ダミー)
void init_generate_G2(void){
	int i;			//ループカウンタ

	H1 = (int **)malloc(sizeof(int*)*m);
	H2 = (int **)malloc(sizeof(int*)*m);
	inv_H1 = (int **)malloc(sizeof(int*)*m);
	G = (int **)malloc(sizeof(int*)*m);
	for(i = 0; i < m; i++){
		H1[i] = (int *)malloc(sizeof(int)*m);
		H2[i] = (int *)malloc(sizeof(int)*m);
		inv_H1[i] = (int *)malloc(sizeof(int)*m);
		G[i] = (int *)malloc(sizeof(int)*n);
	}

}


//送信語
void init_sending_word(void){
	int i,j;	//ループカウンタ

/*	
	//情報の作成（ランダム）
	for(i = 0; i < m; i++){
		if(genrand_real1() >= 0.5)	//乱数が0.5以上の場合
			message[i] = 1;	//情報ビットが1
		else				//乱数が0.5未満の場合
			message[i] = 0;	//情報ビットが0
	}

	//符号語の作成
	for(i = 0; i < n; i++){
		temp = 0;
		for(j = 0; j < m; j++){
			temp += message[j] * G[j][i];
		}
		code_word[i] = temp%2;	
	}
*/

	for(i = 0; i < m; i++){
		message[i] = 0;
	}
	//符号語All0
	for(i = 0; i < n; i++){
		code_word[i] = 0;
	}

/**************** コセット ***************/
	for(i = 0; i < n; i++){
		if(genrand_real1() >= 0.5)	//乱数が0.5以上の場合
			coset[i] = 1;	//情報ビットが1
		else				//乱数が0.5未満の場合
			coset[i] = 0;	//情報ビットが0

		code_word[i] += coset[i];
	}

	for(i = 0; i < m; i++){
		s[i] = 0;
		for(j = 0; j < n; j++){
			s[i] += code_word[j] * H[i][j];
		}
		s[i] = s[i]%2;
		if(s[i] == 1){
			r[i] = -1;

		}
		else{
			r[i] = 1;
		}
		
	}

/*****************************************/


	//送信語(bpsk)
	for(i = 0; i < n; i++){
		if(code_word[i] == 0)
			sending_word[i] = -1;
		else
			sending_word[i] = 1;
	}



}

//受信語・対数尤度比計算
void init_lambda(double SNR){
	int i;
	double x1,x2;	//ランダム変数


	//受信語（ガウス雑音の付加）
	for(i = 0; i < n; i++){
//		x1 = nrand();		//区間[0,1]で一様分布する乱数
//		x2 = nrand();		//区間[0,1]で一様分布する乱数
//MT法擬似乱数
		x1 = genrand_real1();		//区間[0,1]で一様分布する乱数
		x2 = genrand_real1();		//区間[0,1]で一様分布する乱数
		noise = sqrt(pow((double)10,(double)-SNR/10) / (2 * R) ) 
			* sqrt(-2*log(x1+(double)pow((double)10,(double)-21)))*cos(2*3.14*x2);
		received_word[i] = sending_word[i] + noise;		//受信語
	}

	//対数尤度比（2値入力ＡＷＧＮ通信路
	for(i = 0; i < n; i++)
		lambda[i] = (2 * received_word[i]) / (pow(10, (double)-SNR/10)/2);

}
//sign関数
int sign(double p){
	if(p >= 0)
		return 1;
	else
		return -1;
}
//Gallagerのf関数
double gallager_f(double q){
	if(q<=0.0001)			//exp(0)でエラーが発生？
		return 9.903488;	//x2が大きすぎる・小さすぎるとオーバーフロー発生するので近似
	if(q>=1000)
		return 0.000001;;
	return log( (exp(q)+1)/(exp(q)-1) );
}
//sum_product
void sum_product(int iteration){
	int i,j,k,l;		//ループカウンタ
	double sum;
	double sum2;
	int prod;

	int count;
	int parity;

	

	for(l = 1;l <= iteration; l++){		//条件を満たすまで繰り返す（パリティ検査）	
		for(i = 0; i < m; i++){	//行処理
			for(j = 0; j < row_weight[i]; j++){	
				prod = 1;	//初期化
				sum = 0;
				for(k = 0; k < row_weight[i]; k++){
					if(k != j){
						temp_d = lambda[row_list[i][k]] + beta[i][k];
						sum += gallager_f( fabs(temp_d) );
						prod *= sign(temp_d);
					}
				}
/********************* コセット **************************/
				alpha[i][j] = r[i] * prod * gallager_f(sum);	//α
/*********************************************************/
//				alpha[i][j] = prod * gallager_f(sum);	//α
			}
		}
		for(i = 0; i < n; i++){	//列処理・ビット信頼度
			sum2 = 0;
			for(j = 0; j< col_weight[i]; j++){	
				sum = 0;
				for(k = 0; k < col_weight[i]; k++){
					if(k != j){
						sum += alpha[col_list[i][k]][twin_list[i][k]];
					}
				}
				beta[col_list[i][j]][twin_list[i][j]] = sum;	//β
				sum2 += alpha[col_list[i][j]][twin_list[i][j]];
			}
			bit_reliability[i] = lambda[i] + sum2;	//ビット信頼度
		}

		//推定語（AWGN通信路）
		for(i = 0; i < n; i++){
			if(bit_reliability[i]>=0){
				estimated_word[i]=1;
			}
			else{
				estimated_word[i]=0;
			}
		}

/*
		printf("反復:%d\n",l);
		for(i=0;i<n;i++){
			printf("%d",estimated_word[i]);
		}
		printf("\n");

		count=0;
		for(i=0;i<m;i++){
			parity = 0;
			for(j=0;j<n;j++)
				parity += H[i][j] * estimated_word[j];
			if(parity%2 == 1){
				count += 1;
				break;
			}
		}
		if(count==0)
			break;

*/
//コセット

		count = 0;
		for(i = 0; i < m; i++){
			parity = 0;
			for(j = 0; j < n; j++){
				parity += estimated_word[j] * H[i][j];
			}
			parity = parity%2;
			if(parity != s[i]){
				count += 1;
				break;
			}
		}
		if(count == 0){
			l += 1;
			break;
		}


	}		//sum-product反復
	l -= 1;

	average_iteration += l;		//平均反復回数

}


/* ********************************* 出力 ********************************* */

//読み込み出力
void output_r(void){
	int i,j;		//ループカウンタ
	printf("符号長n:%d\n",n);
	printf("検査記号m:%d\n",m);
	printf("行重みの最大値rmax:%d\n",rmax);
	printf("列重みの最大値cmax:%d\n",cmax);

	printf("各行の行重み:\n");
	for(i = 0; i < m ; i++){
		printf("%d",row_weight[i]);
	}
	printf("\n");
	
	printf("各列の列重み:\n");
	for(i = 0; i < n; i++){
		printf("%d",col_weight[i]);
	}
	printf("\n");

	printf("各行の１が立っている列番号:\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < row_weight[i]; j++){
			printf("%4d",row_list[i][j] + 1);
		}
		printf("\n");
	}

	printf("各列の１が立っている行番号:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < col_weight[i]; j++){
			printf("%4d",col_list[i][j] + 1);
		}
		printf("\n");
	}

	printf("関連リスト:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < col_weight[i]; j++){
			printf("%4d",twin_list[i][j] + 1);
		}
		printf("\n");
	}

}
//検査行列出力
void output_H(void){
	int i,j;	//ループカウンタ
	printf("H\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d",H[i][j]);
		}
		printf("\n");
	}
}
//生成行列出力
void output_G(void){
	int i,j;

	printf("H1\n");
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			printf("%d",H1[i][j]);
		}
		printf("\n");
	}
/*
	printf("inv_H1\n");
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			printf("%d",inv_H1[i][j]);
		}
		printf("\n");
	}

	printf("H2\n");
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			printf("%d",H2[i][j]);
		}
		printf("\n");
	}
*/
	printf("G\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d",G[i][j]);
		}
		printf("\n");
	}

}
//情報・符号語・送信語出力
void output_word(void){
	int i;
	printf("message\n");
	for(i = 0; i < m; i++)
		printf("%d",message[i]);
	printf("\n");

	printf("code word\n");
	for(i = 0; i < n; i++)
		printf("%d",code_word[i]);
	printf("\n");

	printf("sending word\n");
	for(i = 0; i < n; i++)
		printf("%2.0f",sending_word[i]);
	printf("\n");
}
//受信語・対数尤度比出力
void output_lambda(void){
	int i;
	printf("receved word\n");
	for(i = 0; i < n; i++)
		printf("%5.1f",received_word[i]);
	printf("\n");

	printf("lambda\n");
	for(i = 0; i < n; i++)
		printf("%5.1f",lambda[i]);
	printf("\n");
}
//推定語出力
void output_estimated_word(void){
	int i;
	printf("estimated_word\n");
	for(i=0;i<n;i++)
		printf("%d",estimated_word[i]);
	printf("\n");
}


//メイン関数
int main(){
	int h,i,j;			//ループカウンタ
	double SNR;			//SN比
	int iteration = 100;//反復回数
	int loop = 1;	//試行回数
	int bit_error = 0;	//ビット誤り
	int word_error = 0;	//ワード誤り
	double BER,WER;		//ビットエラーレート･ワードエラーレート

//ファイル読み込み
	FILE *write;		//結果書き込み用
	write = fopen("output_AWGN.txt","w+");

	FILE *fp;			//検査行列読み込み
	fp = fopen("10.txt","r");
	if(fp == NULL){
		printf("ファイルをオープンできません\n");
		printf("enterで終了\n");
		getch();		//プロンプト停止用
		return 0;
	}
	init_decoder(fp);	
	fclose(fp);

	R = (double)m / (double)n;			//符号化率 


//	output_r();
	init_generate_H();	//検査行列作成
//	output_H();
//	init_generate_G2();	//生成行列作成
//	output_G();


	srand((unsigned) time(NULL));
//MT法擬似乱数
	init_genrand((unsigned) time(NULL));


	for(SNR = 0; SNR <= 4; SNR += 0.5){

	for(h = 1; h <= loop; h++){	//試行回数
		init_sending_word();	//情報ビット・符号語・送信語

//		output_word();
		init_lambda(SNR);		//受信語・対数尤度比
//		output_lambda();
		sum_product(iteration);	//sum-produt復号法・推定語
//		output_estimated_word();

		//ビット誤り検出
		temp = 0;
		for(i = 0; i < n; i++){
			if(estimated_word[i] != code_word[i]){
				bit_error += 1;
				temp +=1;
			}
		}


		if(temp != 0){
//			printf("試:%d;誤:%d",h,temp);
			word_error += 1;
		}
		if(h%500 == 0){
			printf("試%d ",h);
		}

		//βの初期化
		for(i = 0; i < m; i++){
			for(j = 0; j < row_weight[i]; j++)
				beta[i][j] = 0;
		}
		//試行停止
		if(word_error == 50){
			h += 1;
			break;
		}

	}
	h -= 1;


	if(bit_error != 0){
		BER = (double)bit_error / ( (double)n*(double)h );
		WER = (double)word_error / (double)h;
		average_iteration /= (double)h;
		printf("SNR:%.2f BER:%.8f WER:%.8f 送信ビット数:%d 試行回数:%d BE数:%d WE数:%d 平均反復数:%.2f\n",SNR,BER,WER,n*h,h,bit_error,word_error,average_iteration);
		fprintf(write,"SNR:%.2f BER:%.8f WER:%.8f 送信ビット数:%d 試行回数:%d BE数:%d WE数:%d 平均反復数:%.2f\n",SNR,BER,WER,n*h,h,bit_error,word_error,average_iteration);


	}
	else{
		printf("誤りなし\n");
	}



	bit_error = 0;		//初期化
	word_error = 0;		//初期化
	average_iteration = 0;	//初期化

	}

	fclose(write);
	printf("enterで終了\n");
	getch(); //プロンプト停止用



	return 0;
}


//MT法乱数
#include <stdio.h>
#include "mt19937ar.h"
/* Period parameters */  
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */
static unsigned long mt[N]; /* the array for the state vector  */
static int mti=N+1; /* mti==N+1 means mt[N] is not initialized */
/* initializes mt[N] with a seed */
void init_genrand(unsigned long s){
    mt[0]= s & 0xffffffffUL;
    for (mti=1; mti<N; mti++) {
        mt[mti] = 
	    (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti); 
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        mt[mti] &= 0xffffffffUL;
        /* for >32 bit machines */
    }
}
void init_by_array(unsigned long init_key[], int key_length){
    int i, j, k;
    init_genrand(19650218UL);
    i=1; j=0;
    k = (N>key_length ? N : key_length);
    for (; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525UL))
          + init_key[j] + j; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++; j++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
        if (j>=key_length) j=0;
    }
    for (k=N-1; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941UL))
          - i; /* non linear */
        mt[i] &= 0xffffffffUL; /* for WORDSIZE > 32 machines */
        i++;
        if (i>=N) { mt[0] = mt[N-1]; i=1; }
    }

    mt[0] = 0x80000000UL; /* MSB is 1; assuring non-zero initial array */ 
}
unsigned long genrand_int32(void){
    unsigned long y;
    static unsigned long mag01[2]={0x0UL, MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= N) { /* generate N words at one time */
        int kk;

        if (mti == N+1)   /* if init_genrand() has not been called, */
            init_genrand(5489UL); /* a default initial seed is used */

        for (kk=0;kk<N-M;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (;kk<N-1;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[N-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        mti = 0;
    }
  
    y = mt[mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}
long genrand_int31(void){
    return (long)(genrand_int32()>>1);
}
double genrand_real1(void){
    return genrand_int32()*(1.0/4294967295.0); 
    /* divided by 2^32-1 */ 
}
double genrand_real2(void){
    return genrand_int32()*(1.0/4294967296.0); 
    /* divided by 2^32 */
}
double genrand_real3(void){
    return (((double)genrand_int32()) + 0.5)*(1.0/4294967296.0); 
    /* divided by 2^32 */
}
double genrand_res53(void) { 
    unsigned long a=genrand_int32()>>5, b=genrand_int32()>>6; 
    return(a*67108864.0+b)*(1.0/9007199254740992.0); 
} 
