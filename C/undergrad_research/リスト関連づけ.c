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