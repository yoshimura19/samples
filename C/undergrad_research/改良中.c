#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

                                                        /* !�֐� */
double gaussianRand(double, double);                    /* �K�E�X�G��  */
double LLR(double);                                     /* �ΐ��ޓx��  */
double sign(double,double);                             /* signal�֐�(�����_,�x�[�^) */
double gallager_f(double);                              /* gallager_f�֐� */
int    Puncturing(int,int);                             /* ��l����(min-max)*/


                                            /* !�O���[�o���ϐ� */
int n=504;                                     /* ������(��������) */
double sigma=0.5,midium=0;                   /* �G���̃p�����^*/
int iteration = 10;                          /* ������ */ 
int puncnum = 5;                             /* �p���N�`���� */
double rate = 0.5;                           /* �p���N�`�����[�g(���g�p) */
int send[504]={},estimate[504]={};                         /* ���M��,��M�� */
int puncture[100]={};                                       
double codeword[504]={},receive[504]={};                    /* ��M��A������ */
int row_weight[300][10]={};                                      
int column_weight[10][600]={};
double alpha[600][600]={},beta[600][600]={},lamda[600]={};    /* �A���t�@�A�x�[�^ */
int r_w[600]={};									/* �e�s�̏d�ݐ� */
int c_w[600]={};									/* �e��d�ݐ� */


int main(void)
{
		FILE *fp;
	int i=0,j=0,k=0,loop=0;
	int row_max,column_max,row,column;
	double sum,product,credit;
	double temp,error;
	int temp1;


	for(i=0;i<n;i++){                             /* ������쐬(�o�C�|�[���ϊ� 0��+1,1��-1)*/
		codeword[i] = 1;
	/*	printf("codeword[%d]=%0.2f\n",i+1,codeword[i]); */
	}

		                                          

										         /* �p���N�`�������O�r�b�g����  */
/*	srand((unsigned int)time(NULL));
	for(i=0;i < n; i++){
			temp1 = 0;
			temp1 = Puncturing(0,100);
		if( temp1 >= 100 - (double)puncnum / (double)n * 100 ){
			puncture[i] = 1;
		} else {
			puncture[i] = 0;
		}
			printf("%d   %d\n",temp1, puncture[i]);
	}
*/

													/* �p���N�`���p�����^�\�� */
/*	temp1 = 0;
		for(i=0;i<n; i++){
			if( puncture[i] == 1){
				temp1++;
				printf("%d ",i+1);
			}
		}
	printf("�σ��[�g%0.2f\n",1 - (double)puncnum / (double)n );
	printf("\n�p���N�`����%d, �p���N�`���\�萔%d\n",temp1,puncnum);
*/
	
	
	
	srand((unsigned int)time(NULL));              /* ��M�M���擾(�K�E�X�G���t��) */
	for(i=0;i<n;i++){                            
		receive[i] = codeword[i] + gaussianRand(sigma,midium);
/*      printf("receive[%d]=%0.5f\n",i+1,receive[i]);  */
	}
	

	for(i=0;i<n;i++){                             /* �ΐ��ޓx���쐬(��M��ɑ΂���) */
		lamda[i]=LLR(receive[i]);
/*		printf("\nlamda[%d]=%0.5f",i+1,lamda[i]);  */
	}
	

	fp = fopen("10","r"); 
	fscanf(fp,"%d",&column);    // ��(������)
	fscanf(fp,"%d",&row);       // �s��(�����L����)
	fscanf(fp,"%d",&row_max);    // �s�d�ݍő�
	fscanf(fp,"%d",&column_max);  // ��d�ݍő�
/*	printf("%d %d %d %d\n",column,row,row_max,column_max);   */
	for(i=0;i<row;i++){                // �e�s�̏d�ݐ�
		fscanf(fp,"%d",&r_w[i]);
	}
	for(i=0;i<column;i++){             // �e��̏d�ݐ��@
		fscanf(fp,"%d",&c_w[i]);
	}
	for(i=0; i<row ;i++){
		for(j=0; j<row_max ;j++){
			fscanf(fp,"%d",&row_weight[i][j]);
		} 
	}
	for(i=0; i<column ; i++){
		for(j=0; j<column_max ;j++){
			fscanf(fp,"%d",&column_weight[i][j]);   
		} 
	}
	fclose(fp);



														/* �t�@�C���ǂݍ��݊m�F */
/*	printf("%d %d %d %d\n",column,row,row_max,column_max);   
	for(i=0;i<row;i++){                // �e�s�̏d�ݐ�
		printf("%d ",r_w[i]);
	} printf("\n");
	for(i=0;i<column;i++){             // �e��̏d�ݐ��@
		printf("%d ",c_w[i]);
	}  printf("\n\n");
	for(i=0; i<row ;i++){               // �s�d�݈ʒu�m�F
		for(j=0; j<row_max ;j++){
			printf("%d ",row_weight[i][j]);
		} printf("\n");
	} printf("\n");
	for(i=0; i<column ; i++){
		for(j=0; j<column_max ;j++){
			printf("%d ",column_weight[i][j]);    //��d�݈ʒu�m�F 
		} printf("\n");
	}  printf("\n");
*/	



/*	for(loop=0;loop < iteration; loop++){                          // �����J�n 
*/	
	
	temp1 =0;
	for(i=0; i<row; i++){                                            // �s����
		for(j=0; j < row_max ; j++){
			 sum=0;
			 product=1;
			for(k=0; k < row_max ;k++){
				product *= sign(lamda[ row_weight[i][k]-1] , beta[i][row_weight[i][k]-1] );
				sum += gallager_f(fabs(lamda[row_weight[i][k]-1] + beta[i][row_weight[i][j]-1]));
			}  
			alpha[i][row_weight[i][j]-1] = product * sign(lamda[row_weight[i][j]-1] , beta[i][row_weight[i][j]-1]) 
			              * gallager_f(sum - gallager_f(fabs(lamda[row_weight[i][j]-1] + beta[i][row_weight[i][j]-1])));
		}  
	} 
	
/*	for(i=0; i<row; i++){
		for(j=0; j<row_max; j++){
			printf("alpha(%d)(%d)=%0.3f  ",i+1,row_weight[i][j],alpha[i][ row_weight[i][j] - 1]);     // �A���t�@�m�F
					temp1++;
				}  printf("\n");
			} 	 printf("%d",temp1); //���m�F
*/


/*	
	i=0;
	j=0;
	for(i=0; j<row_max; j++){
		printf("alpha(%d)(%d)=%0.3f\n",i+1,row_weight[i][j],alpha[i][ row_weight[i][j] - 1]);     // �A���t�@�m�F
	}
	

	printf("\n");
	printf("alpha[%d][%d]=%0.3f bata[][]=%0.3f \n",column_weight[j][i]-1,j,alpha[column_weight[j][i]-1][j],beta[column_weight[j][i]-1][j] = alpha[column_weight[j][i]-1][j]);
	
*/	
/*	printf("\n");
	i=135;
	printf("alpha(1)(%d)=%0.3f\n",column_weight[i][0],alpha[column_weight[i][0] - 1][0]);
*/

	i=0;
	j=0;
	for(j=0;j<60;j++){                                           // �񏈗� 
		for(i=0;i< column_max;i++){ 
			  sum=0;
			for(k=0; k < column_max; k++){
			 	sum += alpha[column_weight[j][k]-1][j]; // printf("alpha[%d][%d]=%0.3f sum=%0.3f \n",column_weight[j][k],j+1,alpha[column_weight[j][k]-1][j],sum);
			} 
			beta[column_weight[j][i]-1][j] = sum - alpha[column_weight[j][i]-1][j];
			printf("\nbeta[%d][%d]=%0.3f\n",column_weight[j][i],j+1,beta[column_weight[j][i]-1][j]);
		}  
	}


/*	printf("\n");
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if(beta[i][j] != 0){
				printf("beta(%d)(%d)=%0.3f   ",i+1,j+1,beta[i][j]);       // �x�[�^�m�F 
			}
		} // printf("\n");
	}  // printf("\n");
*/
	
	
/*	for(j=0;j<column;j++){                                           // �r�b�g�M���x�v�Z 
		credit = 0;
		for(k=0;k<column_max ;k++){                            
		credit += alpha[column_weight[j][k]-1][j];	
		}
		credit += lamda[j];
		
		if(0 <= credit){                                             // �����̌��� 
			estimate[j] = 0;
		} else {
			estimate[j] = 1;
		}
	//	printf("%0.3f %0.3f %0.3f �����%d=%d \n",lamda[j],credit-lamda[j],credit,j+1,estimate[j]); 
	}// printf("\n");                                                 // �����m�F 
*/	
	
	
/*	int parity=0;                                                       // �p���e�B���� 
	for(i=0;i<column;i++){
		for(k=0;k<row_max;k++){
			parity += estimate[row_weight[i][k]-1];
		//	printf("\n%d %d  %d",row_weight[i][k],estimate[row_weight[i][k]-1],parity);  // �����m�F 
		} 
	}// printf("\n\n");
	
	if(parity % 2 == 0){
		 printf("�p���e�B�����I��\n");
		break;
	}		
	}																		// �����I��(loop) 
	*/

	// printf("������%d\n",loop);
	
	
	                                                                    /* ���M��Ǝ�M��m�F */
/*	printf("���M��ƕ�����\n");                                         
	for(i=0;i<n;i++){
		printf("%d",send[i]);	
	}printf("\n");
	for(i=0;i<n;i++){
		printf("%d",estimate[i]);	
	}printf("\n");
*/	
	
																		/* ��藦 */
/*	error = 0;
	for(i=0;i<n;i++){                                                    
		if(send[i] != estimate[i]){
		error += 1.0;}
	} 
	printf("��藦%f\n",error/(double)n);
*/





	scanf("%d",&temp1);

	return 0;
}

/*********** �K�E�X�G�� **************/
 double gaussianRand( double vd_stdev,double vd_meanValue )    //  ����01: �W���΍�   ����02: ���ϒl //
{                                                              
    const double Pi =3.14159265358979;  
    double rtnNum = 0.0;                                        //  ���^�[���p                                    //
    static int sw = 0;                                          //  ���^�[���̐ؑ֗p                              //
                                                             
    double randNum_1;                                           //  �������̂P                                    //
    double randNum_2;                                           //  �������̂Q                                    //
    double whiteGaussianNoise_1;                                //  �z���C�g�K�E�X�m�C�Y���̂P                    //
    static double whiteGaussianNoise_2;                         //  �z���C�g�K�E�X�m�C�Y���̂Q                    //
                     
 
    if( sw == 0 )                                               //  �X�C�b�`��0��                                 //
    {                                                           //  �X�C�b�`��0�Ȃ�                               //
        sw = 1;                                                 //  �X�C�b�`�ؑւ�                                //
        randNum_1 = ((double)rand()) / RAND_MAX;                //  (0,9]�̗����擾                               //
        randNum_2 = ((double)rand()) / RAND_MAX;                //  (0,9]�̗����擾                               //
                                                                //                                                //
        whiteGaussianNoise_1 = vd_stdev * sqrt( -2.0 * log( randNum_1 ) ) *    //  ���K�����P                     //
                                   cos( 2.0 * Pi * randNum_2 ) + vd_meanValue; //                                 //
        whiteGaussianNoise_2 = vd_stdev * sqrt( -2.0 * log( randNum_1 ) ) *    //  ���K�����Q                     //
                                   sin( 2.0 * Pi * randNum_2 ) + vd_meanValue; //                                 //
                                                                //                                                //
        rtnNum = whiteGaussianNoise_1;                          //  ���^�[���ɐ��K�����P��ݒ�                    //
    }                                                           //                                                //
    else                                                        //  �X�C�b�`��0�ȊO�̏ꍇ                         //
    {                                                           //                                                //
        sw = 0;                                                 //  �X�C�b�`�ؑւ�                                //
                                                                //                                                //
        rtnNum = whiteGaussianNoise_2;                          //  ���^�[���ɐ��K�����Q��ݒ�                    //
    }                                                           //                                                //
                                                                //                                                //
    return( rtnNum );                                           //  �����������K������Ԃ��ďI��                  //
}
                          
/************* �ΐ��ޓx��v�Z **************/
double LLR (double receive ){                                   /* ��M�� */

	double lamda;
	lamda = 2 * receive / pow(sigma,2.0);
	return lamda;
}

 /********** �V�O�i���֐� *************/
double sign(double lamda,double beta)
{
	if(lamda + beta >= 0)
		return 1;
	else
		return -1;
}


/************ Gallager�֐� *************/
double gallager_f(double x)
{
	double numerator, denominator;
	if(x < 0.00001){
	/* gallager_f(0.00001)=12.21; */                            /* �A���_�[�t���[�΍� */
		return 12.21;
	} else {
		numerator = exp(x) + 1;
		denominator = exp(x) - 1;
		return log(numerator/denominator);
	}
}

/************* ��l����(for puncturing)*******/
int Puncturing(int min,int max){

	return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}