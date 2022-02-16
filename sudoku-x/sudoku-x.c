#include <stdio.h>
#include <stdlib.h>

int checkDiagonalPrincipal(int** matriz, int n){
    int i, j, lat = 1;
    int cont = 0;
    int counter = 0;
    int verificador[12];

    for(i = 0; i < n && lat; i++)
        for(j = 0; j < n && lat; j++)
            //condição para diagonal principal
            if (i == j)
            {
                verificador[cont] = matriz[i][j];
                cont++;
            }
    for (i = 0; i < n && lat; i++)
    {
        for (j = 0; j < n && lat; j++)
        {
            if (i != j)
            {
                if (verificador[i] == verificador[j])
                {
                    counter++;
                }
                
            }
            
        }
        
    }
    if (counter >= 1)
    {
        lat = 0;
    }
    
            

    return lat;
}

int CheckDiagonalSecundaria(int** matriz, int n){
    int i, j, lat = 1;
    int cont = 0;
    int counter = 0;
    int verificador[12];

    for(i = 0; i < n && lat; i++)
        for(j = 0; j < n && lat; j++)
            //condição para diagonal secúndaria
            if ((i+j) == (n - 1))
            {
                verificador[cont] = matriz[i][j];
                cont++;
            }
    for (i = 0; i < n && lat; i++)
    {
        for (j = 0; j < n && lat; j++)
        {
            if (i != j)
            {
                if (verificador[i] == verificador[j])
                {
                    counter++;
                }
                
            }
            
        }
        
    }
    if (counter >= 1)
    {
        lat = 0;
    }
    
            

    return lat;
}

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

    for(j = 0; j < 12 && lat; j++)
        for(i = 0; i < 12 && lat; i++)
            for(k = 0; k < 12 && lat; k++)
                if((i != k) && (matriz[i][j] == matriz[k][j]))
                    lat = 0;

    return lat;
}

void popularMatriz(int** matriz, int n){

    int i, j;

    printf("Quais valores do quadrado serão testado:\n");

    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%i", &matriz[i][j]);
            while(matriz[i][j] < 1 || matriz[i][j] > 12){
                printf("Apenas valores entre 1 e 12 são permetidos no sudoku X. Tente novamente.\n");
                scanf("%i", &matriz[i][j]);
            }
        }
    }
}

int checarMenor(int mini[3][4]){
    int i, j, num, possivel = 0;

    for(num = 1; num <= 12; num++){
        for(i = 0; i < 3; i++)
            for(j = 0; j < 4; j++)
                if(mini[i][j] == num) possivel++;
        if(possivel > 1) return 0;
        possivel = 0;
    }

    return 1;
}

int checarMenores(int** matriz, int n){
    int i, j, k, l, mini[3][4];

    for(i = 0; i < 12; i += 3)
        for(j = 0; j < 12; j += 4){
            for(k = 0; k < 3; k++)
                for(l = 0; l < 4; l++)
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
    //matriz[12][12]
    //(row*cols)*sizeof(int)
    int n = 12;

    int** matriz = createMatriz(n); 

    FILE *file = fopen("./matriz.txt", "r");

    if(file == NULL){
        printf("Error!");   
        return 0;         
    }

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            fscanf(file, "%d", &matriz[i][j]);
            while(matriz[i][j] < 1 || matriz[i][j] > 12){
                printf("Apenas valores entre 1 e 12 são permetidos no sudoku X. Tente novamente.\n");
                scanf("%d", &matriz[i][j]);
            }
        }
    }

    fclose(file);

    if(checkHorizontal(matriz, n) && checkVertical(matriz, n) && checarMenores(matriz, n) && checkDiagonalPrincipal(matriz, n) && CheckDiagonalSecundaria(matriz, n))
        printf("Parabens! A matriz inserida forma um Sudoku X.\n");
    else
        printf("Infelizmente a matriz inserida nao forma um Sudoku X.\n");

   
    freeMatriz(matriz, n);
    
    return 0;
}