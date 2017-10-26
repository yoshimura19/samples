
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
#define nrand() ( double )rand() / RAND_MAX	/*���[0,1]�ň�l���z���闐��*/
#include <conio.h> /* getch */
#pragma warning(disable : 4996)

#define MAX(a, b) ((a) > (b) ? (a) : (b))	//�ő�l������
#include "mt19937ar.h"


//�錾
int n;				//������
int m;				//�����L����
int rmax;			//�ő�s�d��
int cmax;			//�ő��d��
int *row_weight;	//�s�d��
int *col_weight;	//��d��
int **row_list;		//�s���X�g
int **col_list;		//�񃊃X�g
int **twin_list;	//�s�Ɨ���֘A�t���郊�X�g
double R;			//��������


int **H;			//�����s��
int **H1;
int **H2;
int **inv_H1;		//�t�s��
int **G;			//�����s��

int temp;			//���ϐ�
double temp_d;		//���ϐ�

int *message;		//���r�b�g
int *code_word;		//������
double *sending_word;	//���M��
double *received_word;	//��M��
double *lambda;		//�ΐ��ޓx��

double noise;

double **alpha;
double **beta;

double *bit_reliability;	//�r�b�g�M���x
int *estimated_word;	//�����

double average_iteration = 0;


/*************** �R�Z�b�g ***************/
int *coset;	//
int *r;
int *s;		
/****************************************/


//�����s��ǂݍ��݁E�������m��
void init_decoder(FILE *fp){
    int i,j,k;		//���[�v�J�E���^

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
		//�e�s�̂P�������Ă����ԍ�
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
		//�e��̂P�������Ă���s�ԍ�
		for(j = 0; j < col_weight[i]; j++){
			fscanf(fp,"%d",&col_list[i][j]);
			col_list[i][j] -= 1;
			//���X�g�̊֘A�t��
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

/*************** �R�Z�b�g ***************/
	coset = (int *)malloc(sizeof(int)*n);
	r = (int *)malloc(sizeof(int)*m);
	s = (int *)malloc(sizeof(int)*m);
/****************************************/

}


//�����s��
void init_generate_H(void){
	int i,j;			//���[�v�J�E���^
	for(i = 0; i < m; i++){
		H[i] = (int *)malloc(sizeof(int)*n);
	}
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++)	//������
			H[i][j]=0;
		for(j = 0; j < row_weight[i]; j++)
			H[i][row_list[i][j]] = 1;
	}
}

//�����s��쐬
void init_generate_G(void){
	int i,j,k;			//���[�v�J�E���^
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

	//�����s��̕����E�t�s��쐬�p�̒P�ʍs��
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
	//�t�s��̍쐬�i�|���o���@�j
	for(i = 0; i < m; i++){
		//�Ίp������0�̂Ƃ�1�ɂ��鏈��
		if(H1[i][i] == 0){
			for(j = i; j < m; j++){
				if(i != j && H1[j][i] == 1){
					//�s������
					for(k = 0; k < m; k++){
						temp = H1[i][k];
						H1[i][k] = H1[j][k];
						H1[j][k] = temp;
						temp = inv_H1[i][k];
						inv_H1[i][k] = inv_H1[j][k];
						inv_H1[j][k] = temp;
					}
					break;		//���[�vj���E
				}
			}
		}

		//�Ίp�����ȊO��0�ɂ��鏈��
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
//			printf("�����s��쐬���s:%d���\n",i);
//			printf("enter�ŏI��\n");
//			getch(); //�v�����v�g��~�p
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

			printf("�����_��1:%d\n",randam1);
			printf("�����_��2:%d\n",randam2);
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
						row_list[j][temp] = k;		//�s���X�g
						temp += 1;
					}
				}
			}

			//�e��̂P�������Ă���s�ԍ�
			for(j = 0; j < col_weight[randam1]; j++){
				temp = col_list[randam1][j];
				col_list[randam1][j] = col_list[randam2][j];
				col_list[randam2][j] = temp;

				//���X�g�̊֘A�t��
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
			printf("�����s�񂪍쐬�ł��Ȃ������s��\n",i);
			getch(); //�v�����v�g��~�p
			exit (0);
		}

	}

	//�����s��G
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

//�����s��쐬(�_�~�[)
void init_generate_G2(void){
	int i;			//���[�v�J�E���^

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


//���M��
void init_sending_word(void){
	int i,j;	//���[�v�J�E���^

/*	
	//���̍쐬�i�����_���j
	for(i = 0; i < m; i++){
		if(genrand_real1() >= 0.5)	//������0.5�ȏ�̏ꍇ
			message[i] = 1;	//���r�b�g��1
		else				//������0.5�����̏ꍇ
			message[i] = 0;	//���r�b�g��0
	}

	//������̍쐬
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
	//������All0
	for(i = 0; i < n; i++){
		code_word[i] = 0;
	}

/**************** �R�Z�b�g ***************/
	for(i = 0; i < n; i++){
		if(genrand_real1() >= 0.5)	//������0.5�ȏ�̏ꍇ
			coset[i] = 1;	//���r�b�g��1
		else				//������0.5�����̏ꍇ
			coset[i] = 0;	//���r�b�g��0

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


	//���M��(bpsk)
	for(i = 0; i < n; i++){
		if(code_word[i] == 0)
			sending_word[i] = -1;
		else
			sending_word[i] = 1;
	}



}

//��M��E�ΐ��ޓx��v�Z
void init_lambda(double SNR){
	int i;
	double x1,x2;	//�����_���ϐ�


	//��M��i�K�E�X�G���̕t���j
	for(i = 0; i < n; i++){
//		x1 = nrand();		//���[0,1]�ň�l���z���闐��
//		x2 = nrand();		//���[0,1]�ň�l���z���闐��
//MT�@�[������
		x1 = genrand_real1();		//���[0,1]�ň�l���z���闐��
		x2 = genrand_real1();		//���[0,1]�ň�l���z���闐��
		noise = sqrt(pow((double)10,(double)-SNR/10) / (2 * R) ) 
			* sqrt(-2*log(x1+(double)pow((double)10,(double)-21)))*cos(2*3.14*x2);
		received_word[i] = sending_word[i] + noise;		//��M��
	}

	//�ΐ��ޓx��i2�l���͂`�v�f�m�ʐM�H
	for(i = 0; i < n; i++)
		lambda[i] = (2 * received_word[i]) / (pow(10, (double)-SNR/10)/2);

}
//sign�֐�
int sign(double p){
	if(p >= 0)
		return 1;
	else
		return -1;
}
//Gallager��f�֐�
double gallager_f(double q){
	if(q<=0.0001)			//exp(0)�ŃG���[�������H
		return 9.903488;	//x2���傫������E����������ƃI�[�o�[�t���[��������̂ŋߎ�
	if(q>=1000)
		return 0.000001;;
	return log( (exp(q)+1)/(exp(q)-1) );
}
//sum_product
void sum_product(int iteration){
	int i,j,k,l;		//���[�v�J�E���^
	double sum;
	double sum2;
	int prod;

	int count;
	int parity;

	

	for(l = 1;l <= iteration; l++){		//�����𖞂����܂ŌJ��Ԃ��i�p���e�B�����j	
		for(i = 0; i < m; i++){	//�s����
			for(j = 0; j < row_weight[i]; j++){	
				prod = 1;	//������
				sum = 0;
				for(k = 0; k < row_weight[i]; k++){
					if(k != j){
						temp_d = lambda[row_list[i][k]] + beta[i][k];
						sum += gallager_f( fabs(temp_d) );
						prod *= sign(temp_d);
					}
				}
/********************* �R�Z�b�g **************************/
				alpha[i][j] = r[i] * prod * gallager_f(sum);	//��
/*********************************************************/
//				alpha[i][j] = prod * gallager_f(sum);	//��
			}
		}
		for(i = 0; i < n; i++){	//�񏈗��E�r�b�g�M���x
			sum2 = 0;
			for(j = 0; j< col_weight[i]; j++){	
				sum = 0;
				for(k = 0; k < col_weight[i]; k++){
					if(k != j){
						sum += alpha[col_list[i][k]][twin_list[i][k]];
					}
				}
				beta[col_list[i][j]][twin_list[i][j]] = sum;	//��
				sum2 += alpha[col_list[i][j]][twin_list[i][j]];
			}
			bit_reliability[i] = lambda[i] + sum2;	//�r�b�g�M���x
		}

		//�����iAWGN�ʐM�H�j
		for(i = 0; i < n; i++){
			if(bit_reliability[i]>=0){
				estimated_word[i]=1;
			}
			else{
				estimated_word[i]=0;
			}
		}

/*
		printf("����:%d\n",l);
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
//�R�Z�b�g

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


	}		//sum-product����
	l -= 1;

	average_iteration += l;		//���ϔ�����

}


/* ********************************* �o�� ********************************* */

//�ǂݍ��ݏo��
void output_r(void){
	int i,j;		//���[�v�J�E���^
	printf("������n:%d\n",n);
	printf("�����L��m:%d\n",m);
	printf("�s�d�݂̍ő�lrmax:%d\n",rmax);
	printf("��d�݂̍ő�lcmax:%d\n",cmax);

	printf("�e�s�̍s�d��:\n");
	for(i = 0; i < m ; i++){
		printf("%d",row_weight[i]);
	}
	printf("\n");
	
	printf("�e��̗�d��:\n");
	for(i = 0; i < n; i++){
		printf("%d",col_weight[i]);
	}
	printf("\n");

	printf("�e�s�̂P�������Ă����ԍ�:\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < row_weight[i]; j++){
			printf("%4d",row_list[i][j] + 1);
		}
		printf("\n");
	}

	printf("�e��̂P�������Ă���s�ԍ�:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < col_weight[i]; j++){
			printf("%4d",col_list[i][j] + 1);
		}
		printf("\n");
	}

	printf("�֘A���X�g:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < col_weight[i]; j++){
			printf("%4d",twin_list[i][j] + 1);
		}
		printf("\n");
	}

}
//�����s��o��
void output_H(void){
	int i,j;	//���[�v�J�E���^
	printf("H\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d",H[i][j]);
		}
		printf("\n");
	}
}
//�����s��o��
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
//���E������E���M��o��
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
//��M��E�ΐ��ޓx��o��
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
//�����o��
void output_estimated_word(void){
	int i;
	printf("estimated_word\n");
	for(i=0;i<n;i++)
		printf("%d",estimated_word[i]);
	printf("\n");
}


//���C���֐�
int main(){
	int h,i,j;			//���[�v�J�E���^
	double SNR;			//SN��
	int iteration = 100;//������
	int loop = 1;	//���s��
	int bit_error = 0;	//�r�b�g���
	int word_error = 0;	//���[�h���
	double BER,WER;		//�r�b�g�G���[���[�g����[�h�G���[���[�g

//�t�@�C���ǂݍ���
	FILE *write;		//���ʏ������ݗp
	write = fopen("output_AWGN.txt","w+");

	FILE *fp;			//�����s��ǂݍ���
	fp = fopen("10.txt","r");
	if(fp == NULL){
		printf("�t�@�C�����I�[�v���ł��܂���\n");
		printf("enter�ŏI��\n");
		getch();		//�v�����v�g��~�p
		return 0;
	}
	init_decoder(fp);	
	fclose(fp);

	R = (double)m / (double)n;			//�������� 


//	output_r();
	init_generate_H();	//�����s��쐬
//	output_H();
//	init_generate_G2();	//�����s��쐬
//	output_G();


	srand((unsigned) time(NULL));
//MT�@�[������
	init_genrand((unsigned) time(NULL));


	for(SNR = 0; SNR <= 4; SNR += 0.5){

	for(h = 1; h <= loop; h++){	//���s��
		init_sending_word();	//���r�b�g�E������E���M��

//		output_word();
		init_lambda(SNR);		//��M��E�ΐ��ޓx��
//		output_lambda();
		sum_product(iteration);	//sum-produt�����@�E�����
//		output_estimated_word();

		//�r�b�g��茟�o
		temp = 0;
		for(i = 0; i < n; i++){
			if(estimated_word[i] != code_word[i]){
				bit_error += 1;
				temp +=1;
			}
		}


		if(temp != 0){
//			printf("��:%d;��:%d",h,temp);
			word_error += 1;
		}
		if(h%500 == 0){
			printf("��%d ",h);
		}

		//���̏�����
		for(i = 0; i < m; i++){
			for(j = 0; j < row_weight[i]; j++)
				beta[i][j] = 0;
		}
		//���s��~
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
		printf("SNR:%.2f BER:%.8f WER:%.8f ���M�r�b�g��:%d ���s��:%d BE��:%d WE��:%d ���ϔ�����:%.2f\n",SNR,BER,WER,n*h,h,bit_error,word_error,average_iteration);
		fprintf(write,"SNR:%.2f BER:%.8f WER:%.8f ���M�r�b�g��:%d ���s��:%d BE��:%d WE��:%d ���ϔ�����:%.2f\n",SNR,BER,WER,n*h,h,bit_error,word_error,average_iteration);


	}
	else{
		printf("���Ȃ�\n");
	}



	bit_error = 0;		//������
	word_error = 0;		//������
	average_iteration = 0;	//������

	}

	fclose(write);
	printf("enter�ŏI��\n");
	getch(); //�v�����v�g��~�p



	return 0;
}


//MT�@����
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
