#include <stdio.h>
#include <stdlib.h>

int checkHorizontal(int** matriz, int n){

    int i, j, k, lat = 1;

    for(i = 0; i < n && lat; i++)
        for(j = 0; j < n && lat; j++)
            for(k = 0; k < n && lat; k++)
                if((j != k) && (matriz[i][j] == matriz[i][k]))
                    lat = 0;

    return lat;
}

int checkVertical(int** matriz, int n){

    int i, j, k, lat = 1;

    for(j = 0; j < 9 && lat; j++)
        for(i = 0; i < 9 && lat; i++)
            for(k = 0; k < 9 && lat; k++)
                if((i != k) && (matriz[i][j] == matriz[k][j]))
                    lat = 0;

    return lat;
}

void popularMatriz(int** matriz, int n){

    int i, j;

    printf("Quais valores do quadrado serão testado:\n");

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            scanf("%i", &matriz[i][j]);
            while(matriz[i][j] < 1 || matriz[i][j] > 9){
                printf("Apenas valores entre 1 e 9 são permetidos no sudoku. Digite outro valor.\n");
                scanf("%i", &matriz[i][j]);
            }
        }
    }
}

int checarMenor(int mini[3][3]){
    int i, j, num, possivel = 0;

    for(num = 1; num <= 9; num++){
        for(i = 0; i < 3; i++)
            for(j = 0; j < 3; j++)
                if(mini[i][j] == num) possivel++;
        if(possivel > 1) return 0;
        possivel = 0;
    }

    return 1;
}

int checarMenores(int** matriz, int n){
    int i, j, k, l, mini[3][3];

    for(i = 0; i < 9; i += 3)
        for(j = 0; j < 9; j += 3){
            for(k = 0; k < 3; k++)
                for(l = 0; l < 3; l++)
                    mini[k][l] = matriz[k+i][l+j];
            if(!checarMenor(mini))
                return 0;
        }

    return 1;
}

int** createMatriz(int n){
    //criando matriz com malloc
    int **matriz = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i<n; i++){
       matriz[i] = (int*)malloc(n*sizeof(int));
    }

    return matriz;
}

void freeMatriz(int **matriz, int n){
    //liberando memoria
    for(int i = 0; i< n; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main(){
    //matriz[9][9]
    //(row*cols)*sizeof(int)
    int n = 9;

    int** matriz = createMatriz(n); 

    FILE *file = fopen("./matriz.txt", "r");

    if(file == NULL){
        printf("Error!");   
        return 0;         
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            fscanf(file, "%d", &matriz[i][j]);
            while(matriz[i][j] < 1 || matriz[i][j] > 9){
                printf("Apenas valores entre 0 e 9 são permetidos no sudoku. Digite outro valor.\n");
                scanf("%d", &matriz[i][j]);
            }
        }
    }

    fclose(file);

    if(checkHorizontal(matriz, n) && checkVertical(matriz, n) && checarMenores(matriz, n))
        printf("A matriz inserida forma um Sudoku.\n");
    else
        printf("A matriz inserida nao forma um Sudoku.\n");

   
    freeMatriz(matriz, n);
    
    return 0;
}