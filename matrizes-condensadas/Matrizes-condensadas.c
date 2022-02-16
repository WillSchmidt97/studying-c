//Programa lerá duas matrizes pré-definidas num arquivo de texto. Em seguida, irá condensa-las, isso é
//Removerá todos os zeros que nela estão contidos. Além disso, o programa somará as matrizes, assim como
//somará as diagonais e mulplicará as mesmas. Para o programa funcionar, o usuário deve digitar matrizes.txt
//Arquivo de texto esse salvo dentro da mesma pasta do programa.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node;

void printaramatriz(int **Matriz);

void printaramatrizcondensada(Node *node);

Node *ConstrutorMatriz(int **Matrix);

int **ConstrutorMatriz2(Node *root);

int retornodevalor(Node *root, int i, int j);

Node *SomadorDeMatrizes(Node *root_A, Node *root_B);

int *SomarDiagonalPrincipal(Node *root_A, Node *root_B);

int Somadorsobdiagonal(Node *root);

Node *MultiplicadorMatriz(Node *rootA, Node *rootB);

void liberar(Node *node);

int main(){

    char arquivo[100];

    //ATENÇÃO: DIGITAR EXATAMENTE COMO ESTA NO NOME DO ARQUIVO DE TEXTO, SEGUIDO POR SUA EXTENÇÃO
    printf("Digite matrizes.txt para abrir o arquivo de texto que esta armazenado na mesma pasta. Em seguida, o programa realizara as operacoes. ");

    scanf("%s", arquivo);

    FILE *filePointer;

    filePointer = fopen(arquivo, "r");

    if(filePointer == NULL){
        printf("Erro!\n");
        return 0;
    }

    int** MatrizA = (int**) malloc(15*sizeof(int*));

    for(int i=0; i<15; i++){
        MatrizA[i] = (int*) malloc(15*sizeof(int));
    }

    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){ 

            int Contador;

            fscanf(filePointer,"%d", &Contador);
            
            MatrizA[i][j] = Contador;
        }
    }

    int** MatrizB = (int**) malloc(15*sizeof(int*));

    for(int i=0; i<15; i++){
        MatrizB[i] = (int*) malloc(15*sizeof(int));
    }

    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){ 

            int Contador;

            fscanf(filePointer,"%d", &Contador);
            
            MatrizB[i][j] = Contador;
        }
    }

    Node *rA = ConstrutorMatriz(MatrizA);
    Node *rB = ConstrutorMatriz(MatrizB);

    printf("Matriz A condensada:");
    printaramatrizcondensada(rA);

    printf("Matriz B condensada:");
    printaramatrizcondensada(rB);

    int **MatrizAINT = ConstrutorMatriz2(rA);
    int **MatrizBINT = ConstrutorMatriz2(rB);

    printf("Matriz A:\n");
    printaramatriz(MatrizAINT);

    printf("Matriz B:\n");
    printaramatriz(MatrizBINT);

    Node *somador = SomadorDeMatrizes(rA, rB);
    printf("Soma das matrizes:");
    printaramatrizcondensada(somador);

    int *sumDiagonal = SomarDiagonalPrincipal(rA, rB);

    printf("Soma da diagonal principal: \n");
    for(int i=0; i<15; i++){
        printf("%d ", sumDiagonal[i]);
    }
    printf("\n\n");

    int sumUnderMainDiagonal = Somadorsobdiagonal(rA);

    printf("Soma sob a diagonal principal: %d\n\n", sumUnderMainDiagonal);
    Node *Multiplicador = MultiplicadorMatriz(rA, rB);
    printf("Produto das matrizes: ");
    printaramatrizcondensada(Multiplicador);
    for(int i=0; i<15; i++){
        free(MatrizA[i]);
        free(MatrizB[i]);
        free(MatrizAINT[i]);
        free(MatrizBINT[i]);
    }

    free(MatrizA);
    free(MatrizB);
    free(MatrizAINT);
    free(MatrizBINT);
    free(sumDiagonal);
    liberar(rA);
    liberar(rB);
    liberar(somador);
    liberar(Multiplicador);
    fclose(filePointer); 
    return 0;
}

struct Node{
    Node *next;
    int line;
    int column;
    int value;
};

void printaramatriz(int **Matriz){

    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            printf("%d ", Matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printaramatrizcondensada(Node *node){

    Node *printar = node;
    int linhaanterior = -1;
    while(1){

        if(printar->value == -1) break;

        if(linhaanterior != printar->line){
            printf("\n");
            linhaanterior = printar->line;
        }

        printf("%d ", printar->value);
        Node *aux = printar->next;
        printar = aux;
    }
    printf("\n\n");
}

Node *ConstrutorMatriz(int **matriz){
    Node *node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    node->value = -1;
    Node *r = node;

    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){

            if(matriz[i][j] == 0) continue;

            node->line = i;
            node->column = j;
            node->value = matriz[i][j];
            node->next = (Node*) malloc(sizeof(Node));

            Node *aux = node->next;
            aux->next = NULL;
            aux->value = -1;
            node = aux;

        }
    }


    return r;
}

int **ConstrutorMatriz2(Node *r){

    int** matriz = (int**) malloc(15*sizeof(int*));

    for(int i=0; i<15; i++){
        matriz[i] = (int*) malloc(15*sizeof(int));
    }

    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            matriz[i][j] = 0;
        }
    }
    while(1){

        if(r->value == -1) break;

        matriz[r->line][r->column] = r->value;

        Node *aux = r->next;
        r = aux;
    }

    return matriz;
}

int retornodevalor(Node *root, int i, int j){
    
    while(1){

        if(root->value == -1) break;

        if(root->line == i && root->column == j){
            return root->value;
        }

        Node *aux = root->next;
        root = aux;
    }

    return 0;
}

Node *SomadorDeMatrizes(Node *root_A, Node *root_B){

    Node *somar = (Node*) malloc(sizeof(Node*));
    somar->value = -1;
    somar->next = NULL;
    Node *root_ans = somar;

    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){

            int value_A = retornodevalor(root_A, i, j);
            int value_B = retornodevalor(root_B, i, j);

            if(value_A == 0 && value_B == 0) continue;

            somar->line = i;
            somar->column = j;
            somar->value = value_A+value_B;
            somar->next = (Node*) malloc(sizeof(Node));

            Node *aux = somar->next;
            aux->next = NULL;
            aux->value = -1;
            somar = aux;
        }
    }

    return root_ans;
}

int *SomarDiagonalPrincipal(Node *rA, Node *rB){

    int *diagonalsomador = (int*) malloc(15*sizeof(int*));

    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            if(i == j){
                int value_A = retornodevalor(rA, i, j);
                int value_B = retornodevalor(rB, i, j);
                diagonalsomador[i] = value_A + value_B;
            }
        }
    }
    return diagonalsomador;
}
int Somadorsobdiagonal(Node *r){

    int mais = 0;
    while(1){

        if(r->value == -1) break;
        if(r->column <= r->line-1){
            mais += r->value;
        }
        Node *aux = r->next;
        r = aux;
    }
    return mais;
}

Node *MultiplicadorMatriz(Node *rA, Node *rB){

    Node *multiplicadornovo = (Node*) malloc(sizeof(Node));
    multiplicadornovo->next = NULL;
    multiplicadornovo->value = -1;
    Node *vf = multiplicadornovo;
    Node *ara = rA;

    for(int i=0; i<15; i++){
        ara = rA;
        Node *linhaatual;
        while(ara->line != i){
            Node *aux = ara->next;
            ara = aux;
        }
        linhaatual = ara;

        for(int j=0; j<15; j++){
            Node *linha = linhaatual;
            Node *coluna = rB;

            multiplicadornovo->line = i;
            multiplicadornovo->column = j;
            multiplicadornovo->value = 0;

            while(1){

                if(coluna->value == -1) break;
                if(coluna->column == j){
                    int value = 0;                    
                    int lineToMultiply = coluna->line;
                    while(linha->line == i){
                            //indentificador de posição
                        if(linha->column == lineToMultiply){
                            value = coluna->value*linha->value;
                            break;
                        }
                        Node *aux_2 = linha->next;
                        linha = aux_2;
                    }   
                    multiplicadornovo->value += value;
                    linha = linhaatual;
                }
                Node *aux_1 = coluna->next;
                coluna = aux_1;
            }
            multiplicadornovo->next = (Node*) malloc(sizeof(Node));
            
            Node *aux_3 = multiplicadornovo->next;
            aux_3->next = NULL;
            aux_3->value = -1;
            multiplicadornovo = aux_3;
        }
    }
    return vf;
}

void liberar(Node *valores){

    while(valores != NULL){
        Node *aux = valores->next;
        free(valores);
        valores = aux;
    }
}