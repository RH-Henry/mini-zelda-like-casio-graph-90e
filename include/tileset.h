void map(int x, int y, int z, int grid[17][10][4],int i){
    if (x==0 && y==0 && z==-1){
        x0y0zm1(grid,i);
    }
    if (x==0 && y==1 && z==-1){
        x0y1zm1(grid,i);
    }
}


void x0y0zm1(int grid[17][10][4],int i) {
    int j;
    int k;
    for (i = 0; i < 17; i++) {
        for (j = 0; j < 10; j++) {
            for (k=0; k<10; k++){
                grid[i][j][k] = 0;
                }
        }
    }
    grid[0][0][0]=1;
    grid[0][0][2]=6;
    grid[0][1][0]=1;
    grid[0][1][2]=2;
    grid[0][2][0]=1;
    grid[0][2][2]=2;
    grid[0][3][0]=1;
    grid[0][3][2]=2;
    grid[0][4][0]=1;
    grid[0][4][2]=2;
    grid[0][5][0]=1;
    grid[0][5][2]=2;
    grid[0][6][0]=1;
    grid[0][6][2]=2;
    grid[0][7][0]=1;
    grid[0][7][2]=2;
    grid[0][8][0]=1;
    grid[0][8][2]=5;
    grid[1][0][0]=1;
    grid[1][0][2]=3;
    grid[1][1][0]=1;
    grid[1][1][1]=1;
    grid[1][7][0]=1;
    grid[1][7][1]=1;
    grid[1][8][0]=1;
    grid[1][8][2]=1;
    grid[2][0][0]=1;
    grid[2][0][2]=3;
    grid[2][8][0]=1;
    grid[2][8][2]=1;
    grid[3][0][0]=1;
    grid[3][0][2]=3;
    grid[3][8][0]=1;
    grid[3][8][2]=1;
    grid[4][0][0]=1;
    grid[4][0][2]=3;
    grid[4][8][0]=1;
    grid[4][8][2]=1;
    grid[5][0][0]=1;
    grid[5][0][2]=3;
    grid[5][8][0]=1;
    grid[5][8][2]=1;
    grid[6][0][0]=1;
    grid[6][0][2]=3;
    grid[6][4][0]=1;
    grid[6][4][1]=1;
    grid[6][5][0]=1;
    grid[6][5][1]=1;
    grid[6][6][0]=1;
    grid[6][6][1]=1;
    grid[6][8][0]=1;
    grid[6][8][2]=1;
    grid[7][0][0]=1;
    grid[7][0][2]=9;
    grid[7][0][3]=1;
    grid[7][8][0]=1;
    grid[7][8][2]=1;
    grid[8][0][0]=1;
    grid[8][0][2]=10;
    grid[8][0][3]=1;
    grid[8][8][0]=1;
    grid[8][8][2]=1;
    grid[9][0][0]=1;
    grid[9][0][2]=3;
    grid[9][4][0]=1;
    grid[9][4][1]=1;
    grid[9][5][0]=1;
    grid[9][5][1]=1;
    grid[9][6][0]=1;
    grid[9][6][1]=1;
    grid[9][8][0]=1;
    grid[9][8][2]=1;
    grid[10][0][0]=1;
    grid[10][0][2]=3;
    grid[10][8][0]=1;
    grid[10][8][2]=1;
    grid[11][0][0]=1;
    grid[11][0][2]=3;
    grid[11][8][0]=1;
    grid[11][8][2]=1;
    grid[12][0][0]=1;
    grid[12][0][2]=3;
    grid[12][8][0]=1;
    grid[12][8][2]=1;
    grid[13][0][0]=1;
    grid[13][0][2]=3;
    grid[13][8][0]=1;
    grid[13][8][2]=1;
    grid[14][0][0]=1;
    grid[14][0][2]=3;
    grid[14][1][0]=1;
    grid[14][1][1]=1;
    grid[14][7][0]=1;
    grid[14][7][1]=1;
    grid[14][8][0]=1;
    grid[14][8][2]=1;
    grid[15][0][0]=1;
    grid[15][0][2]=7;
    grid[15][1][0]=1;
    grid[15][1][2]=4;
    grid[15][2][0]=1;
    grid[15][2][2]=4;
    grid[15][3][0]=1;
    grid[15][3][2]=4;
    grid[15][4][0]=1;
    grid[15][4][2]=4;
    grid[15][5][0]=1;
    grid[15][5][2]=4;
    grid[15][6][0]=1;
    grid[15][6][2]=4;
    grid[15][7][0]=1;
    grid[15][7][2]=4;
    grid[15][8][0]=1;
    grid[15][8][2]=8;
    
}



void x0y1zm1(int grid[17][10][4],int i) {
    int j;
    int k;
    for (i = 0; i < 17; i++) {
        for (j = 0; j < 10; j++) {
            for (k=0; k<10; k++){
                grid[i][j][k] = 0;
                }
        }
    }
    grid[0][0][0]=1;
    grid[0][0][2]=6;
    grid[0][1][0]=1;
    grid[0][1][2]=2;
    grid[0][2][0]=1;
    grid[0][2][2]=2;
    grid[0][3][0]=1;
    grid[0][3][2]=2;
    grid[0][4][0]=1;
    grid[0][4][2]=2;
    grid[0][5][0]=1;
    grid[0][5][2]=2;
    grid[0][6][0]=1;
    grid[0][6][2]=2;
    grid[0][7][0]=1;
    grid[0][7][2]=2;
    grid[0][8][0]=1;
    grid[0][8][2]=5;
    grid[1][0][0]=1;
    grid[1][0][2]=3;
    grid[1][1][0]=1;
    grid[1][1][1]=1;
    grid[1][2][0]=1;
    grid[1][2][1]=1;
    grid[1][8][0]=1;
    grid[1][8][2]=1;
    grid[2][0][0]=1;
    grid[2][0][2]=3;
    grid[2][1][0]=1;
    grid[2][1][1]=1;
    grid[2][8][0]=1;
    grid[2][8][2]=1;
    grid[3][0][0]=1;
    grid[3][0][2]=3;
    grid[3][4][0]=1;
    grid[3][4][1]=1;
    grid[3][5][0]=1;
    grid[3][5][1]=1;
    grid[3][8][0]=1;
    grid[3][8][2]=1;
    grid[4][0][0]=1;
    grid[4][0][2]=3;
    grid[4][4][0]=1;
    grid[4][4][1]=1;
    grid[4][5][0]=1;
    grid[4][5][1]=1;
    grid[4][6][0]=1;
    grid[4][6][1]=1;
    grid[4][8][0]=1;
    grid[4][8][2]=1;
    grid[5][0][0]=1;
    grid[5][0][2]=3;
    grid[5][5][0]=1;
    grid[5][5][1]=1;
    grid[5][6][0]=1;
    grid[5][6][1]=1;
    grid[5][8][0]=1;
    grid[5][8][2]=1;
    grid[6][0][0]=1;
    grid[6][0][2]=3;
    grid[6][8][0]=1;
    grid[6][8][2]=1;
    grid[7][0][0]=1;
    grid[7][0][2]=3;
    grid[7][8][0]=1;
    grid[7][8][2]=13;
    grid[7][8][3]=1;
    grid[8][0][0]=1;
    grid[8][0][2]=3;
    grid[8][8][0]=1;
    grid[8][8][2]=14;
    grid[8][8][3]=1;
    grid[9][0][0]=1;
    grid[9][0][2]=3;
    grid[9][8][0]=1;
    grid[9][8][2]=1;
    grid[10][0][0]=1;
    grid[10][0][2]=3;
    grid[10][7][0]=1;
    grid[10][7][1]=1;
    grid[10][8][0]=1;
    grid[10][8][2]=1;
    grid[11][0][0]=1;
    grid[11][0][2]=3;
    grid[11][7][0]=1;
    grid[11][7][1]=1;
    grid[11][8][0]=1;
    grid[11][8][2]=1;
    grid[12][0][0]=1;
    grid[12][0][2]=3;
    grid[12][8][0]=1;
    grid[12][8][2]=1;
    grid[13][0][0]=1;
    grid[13][0][2]=3;
    grid[13][1][0]=1;
    grid[13][1][1]=1;
    grid[13][2][0]=1;
    grid[13][2][1]=1;
    grid[13][8][0]=1;
    grid[13][8][2]=1;
    grid[14][0][0]=1;
    grid[14][0][2]=3;
    grid[14][1][0]=1;
    grid[14][1][1]=1;
    grid[14][2][0]=1;
    grid[14][2][1]=1;
    grid[14][3][0]=1;
    grid[14][3][1]=1;
    grid[14][8][0]=1;
    grid[14][8][2]=1;
    grid[15][0][0]=1;
    grid[15][0][2]=7;
    grid[15][1][0]=1;
    grid[15][1][2]=4;
    grid[15][2][0]=1;
    grid[15][2][2]=4;
    grid[15][3][0]=1;
    grid[15][3][2]=4;
    grid[15][4][0]=1;
    grid[15][4][2]=4;
    grid[15][5][0]=1;
    grid[15][5][2]=4;
    grid[15][6][0]=1;
    grid[15][6][2]=4;
    grid[15][7][0]=1;
    grid[15][7][2]=4;
    grid[15][8][0]=1;
    grid[15][8][2]=8;
}