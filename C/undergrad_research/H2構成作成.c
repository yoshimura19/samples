#include<stdio.h>
#include<math.h>

#define M 512                             // 検査記号数(2^k) 4096=2^12,2048,1024,512,256
#define CW 2                              // 列最大重み
#define RW 15                             // 行最大重み
#define Printi(X) printf("%d ",X)       // 出力関数(int,double,改行)
#define Printd(X) printf("%0.3f ",X)
#define Printn printf("\n")
#define FILENAME3 "H2作成"

//宣言
int gamma[15]={};                       // M=5000で12,(10000,13)
int s_gamma[15]={};                        // Sum(gamma) 
int c_list[M+3][CW+2];
int r_list[M+3][RW+2];
int r_max=RW;
int c_max=CW;
int r_weight[M+2];                       // 各行重み数    [行数]
int c_weight[M+100];                     // 各列重み数 [H2の列数]
int matrix[M+2][M+2]={};                 // 検査行列 ([1][1]スタート)

//出力関数
void output_gamma(int);
void output_list(void);


int main(void){
	
	int i,j,k,m,temp;
	double temp1;
	int depth=0;
	FILE *fp;
	
	
	m = 2*(int)(ceil((double)((double)(M)/2)));            // k-SRのk数を決定
	temp = m;
	for(i=0;1<temp;i++){                           
	temp = temp/2;
		depth++;
	}
	
	
	gamma[0] = M;
	for(i=1;i<=depth+1;i++){                               // k-SRの列数決定(k=1スタート)
		temp1 = 0.0;
		for(k=0;k<i;k++){
		temp1 += gamma[k];
		}
		gamma[i] = (int)floor((double)(M) - (temp1 / 2));
		if(gamma[i] == 0){
		gamma[i] = 1;                                      // (d+1)-SR
		break;
		}
	} 	
	output_gamma(depth);                                  // SR構成情報出力
	
	
	for(i=0;i<=depth;i++){                                // Sum_gammaの作成
		for(k=1;k<=i;k++){
		s_gamma[i] += gamma[k];
		}
		Printi(s_gamma[i]);
	} printf(" s_gamma_weight");  Printi(i); Printn; Printn;
	
	 
	                                                      // M=512のケース
	fp = fopen(FILENAME3,"w");                            // ファイル書き出し
	
	for(k=1;k<=depth;k++){                                           // 1-SRの計算
		for(j=0;j<gamma[k];j++){
			c_list[j+s_gamma[k-1]][0] = (j+1) + s_gamma[k-1];                     // 次数2で固定
			c_list[j+s_gamma[k-1]][1] = (j+1) + s_gamma[k-1]+gamma[k];
	//printf("%d %d\n",c_list[i][0],c_list[i][1]);
		} 
	}
	
/*	if(c_list[s_gamma[depth]-1][0]+1 != c_list[s_gamma[depth]][0]){
		c_list[s_gamma[depth]][0] = c_list[s_gamma[depth]-1][0]+1;
		c_list[s_gamma[depth]][1] = M;
		c_list[s_gamma[depth]+1][0] = M;
	}*/
	
	c_list[s_gamma[depth]][0]= M;                         // 最後1列
		
	
/*Printi(c_list[s_gamma[depth]-1][0]+1);
	Printi(c_list[s_gamma[depth]][0]);	
*/	

	for(i=1;i<=M;i++){                                   // H2作成
		for(j=0;j<c_max;j++){
		matrix[c_list[i-1][j]][i]=1;
		}
	}
	
	for(i=1;i<=512;i++){                                 // 行リスト作成
		k=0;
		for(j=1;j<=512;j++){
			if(matrix[i][j] != 0){
				r_list[i-1][k] = j;
	//			printf("%d ",r_list[i-1][k]);
				k++;
			}
		} //Printn;
	}
	
	temp =0;                                            // 行重み計算
	for(i=0;i<M;i++){
		k=0;
		for(j=0;j<RW;j++){
			if(r_list[i][j] != 0)
			k++;
		}
		r_weight[i]=k;
		if(temp < k);
		temp = k;
	//	printf("%d ",r_weight[i]);
	}
	r_max = temp;
//	printf("\n\n%d\n\n",r_max);
	
	
	Printn;
	//output_list();                                        // リストの出力
	
	temp = 0;
	for(i=0;i<M;i++){
		temp += r_weight[i];
	}
	printf("%f\n\n",(double)(temp)/(double)(M));
	
	
	
	fprintf(fp,"%d %d %d %d\n",M,M,r_max,c_max);            // ファイルへ書き出し
	for(i=0;i<M;i++){
		fprintf(fp,"%d ",r_weight[i]);
	}
	fprintf(fp,"\n");
	for(i=0;i<M;i++){
		fprintf(fp,"%d ",c_max);
	}
	
	fprintf(fp,"\n"); fprintf(fp,"\n");
	for(i=0;i<M;i++){                
		for(j=0;j<r_max;j++){
			if(r_list[i][j] == 0) break;
			fprintf(fp,"%d ",r_list[i][j]);
		} fprintf(fp,"\n");
	}
	
	fprintf(fp,"\n"); fprintf(fp,"\n");
	for(i=0;i<M;i++){
		fprintf(fp,"%d %d\n",c_list[i][0],c_list[i][1]);
	}
	fclose(fp);
	
	
	return;
}

/*********** γの出力 ************************/
void output_gamma(int depth)
{
	int temp,i;
	
	temp = 0;
	for(i=1;i<=depth+2;i++){                
		Printi(gamma[i]);
		temp += gamma[i];
	} 	
	printf("sum=%d M=%d depth=%d \n ",temp,M,depth);
}
/********** リストの出力 *********************/
void output_list(void)
{
	int i,j;                    
	
	for(i=0;i<M;i++){
		printf("%d ",r_weight[i]);
	} Printn; Printn;
	
	for(i=0;i<M;i++){                                  // 行リスト出力
		for(j=0;j<r_max;j++){
			if(r_list[i][j] == 0) break;
			printf("%d ",r_list[i][j]);
		} Printn;
	}	
	
/*	Printn;
	for(i=0;i<M;i++){
		printf("%d %d\n",c_list[i][0],c_list[i][1]);   // 列リスト出力
	}
*/	
}