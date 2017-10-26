#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

                                           /* !�֐� */
double gaussianRand(double, double);        /* �K�E�X�G��  */
double LLR(double);                         /* �ΐ��ޓx��  */


                                            /* !�O���[�o���ϐ� */
int n=5;                                     /* ������(��������) */
const double Pi =3.141592;                   /* �~���� */
double sigma=0.5,midium=0;                   /* �G���̃p�����^*/


int main(void){                                  /* !���C�� */
	
	int i=0;
	int send[100]={0};
	double codeword[100]={0},receive[100]={0},lamda[100]={0};   
	
	
	for(i=0;i<n;i++){                             /* ������쐬(�o�C�|�[���ϊ� 0��+1,1��-1)*/
		codeword[i] = -1;
		printf("codeword[%0.2f]\n",codeword[i]);
	}
	
	
	srand((unsigned int)time(NULL));              /* ��M�M���擾(�K�E�X�G���t��) */
	for(i=0;i<n;i++){                            
		receive[i] = codeword[i] + gaussianRand(sigma,midium);
		printf("receive[%0.5f]\n",receive[i]);
	}
	

	for(i=0;i<n;i++){                             /* �ΐ��ޓx���쐬(��M��ɑ΂���) */
		lamda[i]=LLR(receive[i]);
		printf("\nlamda[%0.5f]",lamda[i]);
	}
	
	
	return 0;
}









/*********** �K�E�X�G�� **************/
 double gaussianRand( double vd_stdev,double vd_meanValue )    //  ����01: �W���΍�   ����02: ���ϒl //
{                                                              
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
/***********************************/

/************* �ΐ��ޓx��v�Z **************/
double LLR (double receive ){                                 /* ��M�� */

	double lamda;
	lamda = 2 * receive / pow(sigma,2.0);
	return lamda;
}