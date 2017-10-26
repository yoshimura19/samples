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