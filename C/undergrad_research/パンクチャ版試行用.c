#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>     // getch/

// �^������
#define _CRT_SECURE_NO_WARNINGS       // C++ �G���[

//#define N 504                         // ������(��������)
#define FILENAME1 "E^2RC�����s��"                  // �����s��̃t�@�C����
#define SEED (unsigned int)time(NULL)   // �����̐ݒ�  �����_��((unsigned int)time(NULL))
#define Printi(X) printf("%d ",X)       // �o�͊֐�(int,double,���s)
#define Printd(X) printf("%0.3f ",X)
#define Printn printf("\n")

// �֐�
void   check_matrix(FILE *fp);                         // �����s��ǂݍ���
double gaussianRand(double,double);                    // �K�E�X�G�� 
void LLR(double*);                                     // �ΐ��ޓx��v�Z
double sign(double);                                   // signal�֐�
double gallager_f(double);                             // gallager_f�֐�
int    Puncturing(int,int);                            // ��l����(min-max)

// �o�͗p�֐�
void output_check_matrix();                            // �����s��
void output_message_to_lamda();                        // ���M,����,��M��,�ޓx
void output_alpha_to_beta();                           // �A���t�@���x�[�^
void output_bit_reliability_to_estimation();           // �r�b�g�M���x�������

// �錾
int n;                                               // ������(��������(�����s��))
int m;                                               // �����L����
int iteration=100;                                    // ������
int trial=50000;                                         // ���s��
double P0 = 0.01;                                    // �p���N�`���䗦
double R = 0.5;                                      // ��������
double post_R; //= R / (1 - P0);                        // �p���N�`���㕄������
int count_punctured_bit;                             // �p���N�`����
int resend = 300;                                     // �đ��r�b�g��()
double sigma, midium=0,SN=0.5;                         // �G���̃p�����^ (SN��Ōv�Z)
int SN_ladder = 8;                                    // 0.5(1),1(2),1.5(3),2(4),2.5(5),
int *message, *estimation;                           // ���M��(�g�D�����f�[�^����),�����
double *codeword, *receive;                          // ������,��M��
int r_max, c_max;                                    // �ő�s�d��,�ő��d��
int *r_weight, *c_weight;                            // �e�s�d�ݐ�,�e��d�ݐ�
int **r_list, **c_list, **ref_list;                  // �s�E��Etwin(�Ђ��t��)���X�g
double **alpha, **beta, *lamda, *bit_reliability;    // �A���t�@,�x�[�^,�����_,�r�b�g�M���x
double *punctured_lamda;                    // �p���N�`���O�L���p(�đ��p)


/************ ���C���֐� ***************************************************************/
int main(void)
{
     FILE *fp;
     int i=0,j=0,k=0,z=0,h=0,w=0,loop=0;                          // ���[�v�J�E���^
     int temp,count,error,parity;        // �v�Z�L���p(int)
     double sum, sum2, product, temp1;                // �v�Z�L���p(double)
     sigma = sqrt((pow(10,(-SN/10)))/(2*R));          // �G���̕��U�v�Z
     int unrecovered_bit,decord_error;
     double BER,sum_BER=0,ave_BER;                       // �r�b�g��藦,�L���p,����
    
     fp = fopen(FILENAME1,"r");                       // �����s��ǂݍ���,�z��(matrix)�쐬
     if(fp == NULL){
          printf("error:�w��̌����s��t�@�C���͑��݂��܂���\n");              
          getch();                                     // ��~�p
          return 0;
     }
     check_matrix(fp);
     fclose(fp);
     //output_check_matrix();                         // !�o��,�����s��
    
    
    for(w=0;w<SN_ladder;w++){                                 // SN��ύX ���s��
    	printf("\nSN��%0.2f\n",SN);
    
    srand(SEED);                                      // ��������
    
    
//     printf("���s�񐔓���");
//     scanf("%d",&trial);
     for(h=0;h<trial;h++){                            // ���s��            /// ���s�X�^�[�g
     //printf("\n%d���\n",h+1);
    
    
    
     for(i=0;i<n;i++){                                // ���M�ꌈ��
          message[i] = 0;     //�S0���M
//       if(50 < Puncturing(1,100))                   // �����_�����M
/*          message[i] = 1;
          else
          message[i] = 0; */
     }
    
    
     for(i=0;i<n;i++){  
         if(message[i] == 0)                          // �ϒ�(BPSK) 0��1,1��-1 (�Ȉ�)
               codeword[i] = 1;
          else
              codeword[i] = -1;
     }
    
                                         // ��M�M���擾(AWGN:�K�E�X�G���t��)
     for(i=0;i<n;i++){
          receive[i] = codeword[i] + gaussianRand(sigma,midium);
     }
    
    
     LLR(receive);                                    // ��M��̑ΐ��ޓx��v�Z (�֐�)
     //output_message_to_lamda();                     // !�o��,���M�`�ΐ��ޓx
    
    
    count_punctured_bit = P0 * n;
    for(i=0;i<count_punctured_bit;i++){                              // �p���N�`�������O
    	punctured_lamda[-i+n-1] = lamda[-i+n-1];
    	lamda[-i+n-1] = 0;
    //	printf("%0.3f lamda[%d]=%0.3f\n",punctured_lamda[-i+n-1],-i+n-1,lamda[-i+n-1]);
    } 
    //Printi(i); Printn;
   // printf("lamda[%d]=",n-1-i); Printd(lamda[n-1-i]); Printn; Printn;
    
    
    
     for(i=0;i<m;i++){                                // beta������
          for(j=0;j<r_weight[i];j++){
               beta[i][j] = 0;
          }
     }
  
    
    for(loop=0;loop<iteration;loop++){               // Sumproduct�J�n �����J�n
    
    
    temp = unrecovered_bit;
    unrecovered_bit=0;                                // �đ��v������  
    for(i=0;i<count_punctured_bit;i++){
    	if(lamda[-i+n-1] == 0)
    	unrecovered_bit++;
    	}
    	if(unrecovered_bit==0){
    	break;
    }// printf("{������%d} ",unrecovered_bit);            // �p���N�`���������\��


	if(temp == unrecovered_bit){                       // �đ�(Send���đ�)
		//printf("decord_error\n");
		if(unrecovered_bit <= resend){
			for(i=0;i<unrecovered_bit;i++){
    			lamda[i+n-unrecovered_bit] = punctured_lamda[i+n-unrecovered_bit];
 			}//  	printf("\n{������0}");
 		break;
 		}                                              
        else if(unrecovered_bit > resend){
			for(i=0;i<resend;i++){
    			lamda[i+n-unrecovered_bit-1] = punctured_lamda[i+n-unrecovered_bit-1];
 			}//Printn;             // �đ��ŉ���
		}
	loop = 0;
	}
   // Printi(loop);
    
    
    
     for(i=0;i<m;i++){                                // �s����(�p���N�`������)
          for(j=0;j<r_weight[i];j++){
               product = 1.0;
               sum = 0.0;
               for(k=0;k<r_weight[i];k++){
                    if(k != j){
                         temp1 = lamda[r_list[i][k]] + beta[i][k];  // �����O��0
                         sum += gallager_f(fabs(temp1));
                         product *= sign(temp1);         // �Y��lamda���p���N�`���̏ꍇ0;
                    }
               }
               alpha[i][j] = product * gallager_f(sum);    //��     //     Printd(alpha[i][j]);
          }//Printn;
     }
    
    

     for(i=0;i<n;i++){                               // �񏈗�
          sum2 = 0;
          for(j=0;j<c_weight[i];j++){
               sum = 0;
               for(k=0;k<c_weight[i];k++){
                    if(k != j){
                    	if(alpha[c_list[i][k]][ref_list[i][k]] == 0){
                  	 	sum = 0;
                    	break;                                              // at least one alpha is not recovered
                    	} 
                      sum += alpha[c_list[i][k]][ref_list[i][k]];
                        }
               }
               beta[c_list[i][j]][ref_list[i][j]] = sum;   // B(beta)     // �����O��0
               if(sum != 0 && lamda[r_list[c_list[i][j]][ref_list[i][j]]] == 0){
               		lamda[r_list[c_list[i][j]][ref_list[i][j]]] = beta[c_list[i][j]][ref_list[i][j]];  // �p���N�`���m�[�h����(�X�V)
               }
               sum2 +=  alpha[c_list[i][j]][ref_list[i][j]];
          }
          bit_reliability[i] = lamda[i] + sum2;       // �r�b�g�M���x
     }
     // output_alpha_to_beta();
    
    
     for(i=0;i<n;i++){                               // �����쐬�iAWGN�ʐM�H�j
          if(bit_reliability[i]>=0){
               estimation[i]=1;
          } else{
               estimation[i]=0;
          }
     }
     // output_bit_reliability_to_estimation();      // !�o��,�r�b�g�M���x�`�����
    
    
     parity = 0;
     for(i=0;i<m;i++){                               // �p���e�B����
          temp = 0;
          for(k=0;k<r_weight[i];k++){
               temp += estimation[r_list[i][k]];
          }
          if(temp % 2 != 0)
               parity += 1;
     }
    
     if(parity == 0){
        //  printf("�����I�� %d",parity);
          break;
     }
    
     error = 0;
     for(i=0;i<(n * R);i++){                          // 
          if(codeword[i] != estimation[i])
               error += 1;
     }// printf("���%d ",error);
    
     }// printf("\n������%d\n",loop);                  // �����I�� ******************
	
	 BER = error / (double)(m);
	 // printf("\n�r�b�g��藦%f\n\n",BER);
	 sum_BER += BER;
	
	 if(h % 1000 == 0){
	 printf("���s��%d",h);
	 }
	 
     }                                               // ���s�I��    
     
     ave_BER = sum_BER / (double)(trial);
     printf("���s��%d\n���ό�藦%f\n",trial,ave_BER);
     ave_BER = 0,sum_BER=0;
    
    SN += 0.5;                                      // SN��ύX
    }
     
     
     
     return 0;
}
/*************** �����s��ǂݍ��݁��z��m�� ***********************************************/
void check_matrix(FILE *fp){
    
     int i=0,j=0,k=0;                          // ���[�v�J�E���^
    
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
               //���X�g�̊֘A�t��
               for(k = 0; k < r_weight[c_list[i][j]]; k++){
                    if(r_list[c_list[i][j]][k] == i){
                         ref_list[i][j] = k;
                         break;
                    }
               }
          }
     }
    
     message = (int *)malloc(sizeof(int) * n);                 // �g�D���� �f�[�^����
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
     punctured_lamda =  (double *)malloc(sizeof(double) * n );

}
/*** �o�� **** �����s��ǂݍ��݊m�F�p ***********************************************/
void output_check_matrix(void){
    
     int i=0,j=0,k=0;                          // ���[�v�J�E���^
    
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
/*********** �K�E�X�G�� *********************************************************************/
double gaussianRand( double vd_stdev,double vd_meanValue )    //  ����01: �W���΍�   ����02: ���ϒl //
{                                                             
    const double Pi =3.14159265358979; 
    double rtnNum = 0.0;                                        //  ���^�[���p                                   
    static int sw = 0;                                          //  ���^�[���̐ؑ֗p                             
                                                            
    double randNum_1;                                           //  �������̂P                                   
    double randNum_2;                                           //  �������̂Q                                   
    double whiteGaussianNoise_1;                                //  �z���C�g�K�E�X�m�C�Y���̂P                   
    static double whiteGaussianNoise_2;                         //  �z���C�g�K�E�X�m�C�Y���̂Q                   
                    
    if( sw == 0 )                                               //  �X�C�b�`��0��          
    {                                                           //  �X�C�b�`��0�Ȃ�      
        sw = 1;                                                 //  �X�C�b�`�ؑւ�   
        randNum_1 = ((double)rand()) / RAND_MAX;                //  (0,9]�̗����擾     
        randNum_2 = ((double)rand()) / RAND_MAX;                //  (0,9]�̗����擾    
                                          
        whiteGaussianNoise_1 = vd_stdev * sqrt( -2.0 * log( randNum_1 ) ) *    //  ���K�����P 
                                   cos( 2.0 * Pi * randNum_2 ) + vd_meanValue;
        whiteGaussianNoise_2 = vd_stdev * sqrt( -2.0 * log( randNum_1 ) ) *    //  ���K�����Q
                                   sin( 2.0 * Pi * randNum_2 ) + vd_meanValue;
                                                           
        rtnNum = whiteGaussianNoise_1;                          //  ���^�[���ɐ��K�����P��ݒ�
    }                                                      
    else                                                        //  �X�C�b�`��0�ȊO�̏ꍇ 
    {                                                         
        sw = 0;                                                 //  �X�C�b�`�ؑւ�
                                             
        rtnNum = whiteGaussianNoise_2;                          //  ���^�[���ɐ��K�����Q��ݒ�    
    }                              
                             
    return( rtnNum );                                           //  �����������K������Ԃ��ďI��   
}
/********** �ΐ��ޓx��v�Z *******************************************************************/
void LLR (double receive[]){                                   // ��M�� �� �ΐ��ޓx
    
     int i;
     for(i=0;i<n;i++){                               
     lamda[i] = 2 * receive[i] / pow(sigma,2.0);
     }
     return;
}
/***�o��* ���M��`�ΐ��ޓx�� ****************************************************************/
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
/********** �V�O�i���֐� ********************************************************** *********/
double sign(double temp)
{
	 if(temp == 0)
	 		return 0;
     else if(temp > 0)
          return 1;
     else 
          return -1;
}
/************ Gallager�֐� *****************************************************************/
double gallager_f(double x)
{
     double numerator, denominator;
     if(x < 0.00001)
     // gallager_f(0.00001)=12.21;                             // �A���_�[�t���[�΍�
          return 12.21;    
     if(x > 1000)
          return 0.000001;                                        // �I�[�o�[�t���[�΍�
          numerator = exp(x) + 1;
          denominator = exp(x) - 1;
     return log(numerator/denominator);    
}
/***�o��* �A���t�@�`�x�[�^ ****************************************************************/
void output_alpha_to_beta(void){
    
     int i,j,k;                          // ���[�v�J�E���^
    
     for(i=0;i<m;i++){
          for(j=0;j<r_weight[i];j++){           // �A���t�@�o��
               Printd(alpha[i][j]);
          }  Printn;
     }
     for(i=0;i<m;i++){
          for(j=0;j<r_weight[i];j++){           // �x�[�^�o��
               Printd(beta[i][j]);
          } Printn;
     }
     return;
}
/***�o��* �r�b�g�M���x������� *************************************************************/
void output_bit_reliability_to_estimation(void){
    
     int i,j,k;                          // ���[�v�J�E���^
    
     for(i=0;i<n;i++){         
     //     Printd(bit_reliability[i]);     // �r�b�g�M���x
     Printi(estimation[i]);              // �����
     }Printn,Printi(i),Printn;
}
/************* ��l����(for puncturing) ***************************************************/
int Puncturing(int min,int max){
     return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

// �p���N�`���Q�l *** R0 = 0.5 *** R = R0 / (1 - P0)  ***/////
/*
P0		R'
0.1		0.555555556
0.15		0.588235294
0.2		0.625
0.25		0.666666667
0.3		0.714285714
0.35		0.769230769
0.4		0.833333333
0.45		0.909090909
0.5		1
*/

/*
0.5	0
0.6	0.166666667
0.7	0.285714286
0.8	0.375
0.9	0.444444444
1	0.5
*/
///////////////////////////////////////////////////
