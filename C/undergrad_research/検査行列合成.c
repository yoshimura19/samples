#include<stdio.h>
#include<math.h>

#define N 1024                            // 符号長
#define M 512                             // 検査記号数(2^k) 4096=2^12,2048,1024,512,256
#define CW 4                              // 列最大重み
#define RW 20                             // 行最大重み
#define Printi(X) printf("%d ",X)       // 出力関数(int,double,改行)
#define Printd(X) printf("%0.3f ",X)
#define Printn printf("\n")
#define FILENAME1 "h1 512(10)"
#define FILENAME2 "H2作成"
#define FILENAME3 "E^2RC検査行列"

//宣言                                 // H1,H2のパラメタにより要変更
int n1,n2;                                  // 列数(H1＆H2)
int m1,m2;
int c_list[N+3][CW+2];
int r_list[M+3][RW+2];
int r_max=RW;
int c_max=CW;
int r_weight[M+2];                       // 各行重み数    [行数]
int c_weight[N+2];                     // 各列重み数 [H2の列数]
//int matrix[M+2][M+2]={};                 // 検査行列 ([1][1]スタート)

int c1_list[M+3][CW+2];               // H1用
int r1_list[M+3][RW+2];
int r1_max;
int c1_max;
int r1_weight[M+2];                       // 各行重み数    [行数]
int c1_weight[M+2];                     // 各列重み数 [H2の列数]

int c2_list[M+3][CW+2];               // H2用
int r2_list[M+3][RW+2];
int r2_max;
int c2_max;
int r2_weight[M+2];                       // 各行重み数    [行数]
int c2_weight[M+2];                     // 各列重み数 [H2の列数]


//出力関数
void output_check_matrix1();                            // H1
void output_check_matrix2();                            // H2
void output_check_matrix();                           // 合成H


int main(void){
	
	int i,j,k,m,temp;
	double temp1;
	int depth=0;
	FILE *fp;
	FILE *fp1;
	FILE *fp2;
	
	                                                   
	fp1 = fopen(FILENAME1,"r");                   // H1読み込み
	
	fscanf(fp1,"%d/n",&n1);
    fscanf(fp1,"%d/n",&m1);
    fscanf(fp1,"%d/n",&r1_max);
    fscanf(fp1,"%d/n",&c1_max);
    
    for(i=0;i<m1;i++){
          fscanf(fp1,"%d",&r1_weight[i]);
    }
	for(i=0;i<n1;i++){
          fscanf(fp1,"%d",&c1_weight[i]);
    }
	for(i=0;i<m1;i++){
		for(j = 0;j<r1_weight[i];j++){
        fscanf(fp1,"%d",&r1_list[i][j]);
		}
    }
	for(i = 0;i<n1;i++){
		for(j = 0;j< c1_weight[i]; j++){
		fscanf(fp1,"%d",&c1_list[i][j]);
		}
	}
	
	fclose(fp1);
//	output_check_matrix1();                          // H1出力用
	
	
	fp2 = fopen(FILENAME2,"r");                   // H2読み込み
	
	fscanf(fp2,"%d/n",&n2);
    fscanf(fp2,"%d/n",&m2);
    fscanf(fp2,"%d/n",&r2_max);
    fscanf(fp2,"%d/n",&c2_max);
    
    for(i=0;i<m2;i++){
          fscanf(fp2,"%d",&r2_weight[i]);
    }
	for(i=0;i<n2;i++){
          fscanf(fp2,"%d",&c2_weight[i]);
    }
	for(i=0;i<m2;i++){
		for(j = 0;j<r2_weight[i];j++){
        fscanf(fp2,"%d",&r2_list[i][j]);
		}
    }
	for(i = 0; i < n2; i++){
		for(j = 0;j<c2_weight[i]; j++){
		fscanf(fp2,"%d",&c2_list[i][j]);
		}
	}
	
	fclose(fp2);
	//output_check_matrix2();                          // H2出力用
	
	                                                  // 合成 H1＆H2
	r_max = r1_max + r2_max;
	if(c1_max > c2_max) c_max = c1_max;
	else  c_max = c2_max;
	
	for(i=0;i<M;i++){
		r_weight[i] = r1_weight[i] + r2_weight[i];
	}
	for(i=0;i<n1;i++){
		c_weight[i] = c1_weight[i];
	}
	for(i=0;i<n2;i++){
		c_weight[i+m1] = c2_weight[i];
	} c_weight[N-1] = 1;                               // *最後の列は列重み１
	for(i=0;i<M;i++){
		for(j=0;j<r1_weight[i];j++){
        r_list[i][j] = r1_list[i][j];
        }
        for(j=r1_weight[i];j<(r1_weight[i]+r2_weight[i]);j++){
        r_list[i][j] = n1 + r2_list[i][j-r1_weight[i]];
        }
    }	
    for(i=0;i<n1;i++){
		for(j=0;j<c1_weight[i]; j++){
		c_list[i][j] = c1_list[i][j];
		}
	}
	for(i=n1;i<(n1+n2);i++){
		for(j=0;j<c2_weight[i-n1];j++){
		c_list[i][j] = c2_list[i-n1][j];
		}
	}
	//output_check_matrix();                            // 合成 H 出力用
		
	
	
	fp = fopen(FILENAME3,"w");                            // ファイル書き出し
	
	fprintf(fp,"%d %d %d %d\n",N,M,r_max,c_max);
	
	for(i=0;i<M;i++){
		fprintf(fp,"%d ",r_weight[i]);
	} fprintf(fp,"\n");
	for(i=0;i<N;i++){
		fprintf(fp,"%d ",c_weight[i]);
	} fprintf(fp,"\n\n");
	for(i=0;i<M;i++){
		for(j=0;j<r_weight[i];j++){
        fprintf(fp,"%d ",r_list[i][j]);
        } fprintf(fp,"\n");
    } fprintf(fp,"\n\n");
    for(i = 0; i < N; i++){
		for(j = 0;j<c_weight[i]; j++){
		fprintf(fp,"%d ",c_list[i][j]);
		} fprintf(fp,"\n");
    } fprintf(fp,"\n");
	
	fclose(fp);
	
	printf("検査行列合成完了\n\n");
	
	return;
}

/*** 出力 **** H1出力 ***********************************************/
void output_check_matrix1(void){
	
	int i=0,j=0,k=0;                          // ループカウンタ
	
	Printi(n1); Printi(m1); Printi(r1_max); Printi(c1_max); Printn; Printn;
	
	for(i=0;i<m1;i++){
         printf("%d ",r1_weight[i]);
    }
	for(i=0;i<n1;i++){
         printf("%d ",c1_weight[i]);
    }
    for(i=0;i<m1;i++){
		for(j = 0;j<r1_weight[i];j++){
		printf("%d ",r1_list[i][j]);
		} Printn;
    }
	for(i=0;i<n1;i++){
		for(j = 0;j<c1_weight[i];j++){
		printf("%d ",c1_list[i][j]);
		} Printn;
    } 
}
/*** 出力 **** H2出力 ***********************************************/
void output_check_matrix2(void){
	
	int i=0,j=0,k=0;                          // ループカウンタ
	
	Printi(n2); Printi(m2); Printi(r2_max); Printi(c2_max); Printn; Printn;
	
	for(i=0;i<m2;i++){
         printf("%d ",r2_weight[i]);
    }
	for(i=0;i<n2;i++){
         printf("%d ",c2_weight[i]);
    }
    for(i=0;i<m2;i++){
		for(j = 0;j<r2_weight[i];j++){
		printf("%d ",r2_list[i][j]);
		} Printn;
    }
	for(i=0;i<n2;i++){
		for(j = 0;j<c2_weight[i];j++){
		printf("%d ",c2_list[i][j]);
		} Printn;
    }
}   

/*** 出力 **** 合成検査行列出力 ***********************************************/
void output_check_matrix(void){
	
	int i=0,j=0,k=0;                          // ループカウンタ
	
	Printi(N); Printi(M); Printi(r_max); Printi(c_max); Printn; Printn;
	
	for(i=0;i<M;i++){
		printf("%d ",r_weight[i]);
	}
	for(i=0;i<N;i++){
		printf("%d ",c_weight[i]);
	}
	for(i=0;i<M;i++){
		for(j=0;j<r_weight[i];j++){
        printf("%d ",r_list[i][j]);
        } Printn;
    }
    for(i = 0; i < N; i++){
		for(j = 0;j<c_weight[i]; j++){
		printf("%d ",c_list[i][j]);
		} Printn;
    }
}