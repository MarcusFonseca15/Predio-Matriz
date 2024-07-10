    lin_bola--;
    dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
        if (dist_atual > dist_ant){
            lin_bola++;
        } else {lin_bola--;}


    //Move pra direita
        if (lin_bola++) {
            col_bola++;
            dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
                if (dist_atual > dist_ant){
                col_bola--;
                } else {col_bola++;}
        }
    
    //Move pra baixo
        if (col_bola--){
            lin_bola++;
         dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
        if (dist_atual > dist_ant){
                lin_bola--;
                } else {lin_bola++;}
        }

    //Move pra esquerda
        if (lin_bola--){
            col_bola--;
             dist_atual = abs(lin_buraco - lin_bola) + abs(col_buraco - col_bola);
             if (dist_atual > dist_ant){
                col_bola++;
                } else {col_bola--;}
        }