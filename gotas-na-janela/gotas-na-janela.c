/* O programa irá representar gotas de chuva caindo na soleira de uma janela.
A cada instante de tempo, as gotas N descerão uma posição e as gotas E duas posições,
até atingir a soleira. Ao a se chocar gota N e gota E, a gota N deixa de exister, passando a ser
Apenas E. */

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct chuva{
    int x;
    int y;
    int c;
    char car;
    struct chuva *prox;
};
typedef struct chuva gota;

//Definindo os valores da matriz. Linha e coluna
#define MAX_LIN 10
#define MAX_COL 20
void leiturachuva(gota **comeco, FILE *fp, int n);
gota *buscador(gota *comeco, int i, int j){
    while(comeco != NULL){
        if((comeco)->x == i && (comeco)->y == j){
            return(comeco);
        }
        comeco=comeco->prox;
    }
    return(NULL);
}

void quebradegotas(gota **inicio, int x, int y);
int verificar(gota *gotaa, gota **inicio);
void novagota(gota *gotaa, gota **inicio);
void raindrops(gota **inicio);
void main(){
    FILE *fp;
    gota *inicio;
    int n;
    printf("Digite o numero de gotas que gostaria que o programa rodasse: ");
    scanf("%d", &n);
    inicio = NULL;
    fp = fopen("raindrop.txt", "r");
    leiturachuva(&inicio, fp, n);
    fclose(fp);
    raindrops(&inicio);
}
void leiturachuva(gota **inicio, FILE *fp, int n){
    for(int i = 0; i < n; i++){
        gota *aux;
        aux = malloc(sizeof(gota));
        fscanf(fp, "%d", &aux->x);
        fscanf(fp, "%d", &aux->y); 
        fscanf(fp, "%c", &aux->car);
        aux->c = 0;
        aux->prox = NULL;
        if(aux->x>MAX_LIN || aux->y>MAX_COL){
            free(aux);
            printf("Vazio. Excedeu o limite da janela.\n");
        }else{
            if(inicio!=NULL){
                aux->prox=*inicio;
            }else{
                aux->prox=NULL;
            }
            *inicio=aux;
        }
    }
}
void quebradegotas(gota **inicio, int x, int y){
    gota *aux, *temp_aux;
    aux = *inicio;
    temp_aux=NULL;
    while(aux!=NULL){
        if(aux->x == x && aux->y == y){
            if(temp_aux!=NULL){
                temp_aux->prox=aux->prox;
            }else{
                *inicio = aux->prox;
            }
            free(aux);
            return;
        }
        temp_aux=aux;
        aux=aux->prox;
    }
}
int verificar(gota *gotaa, gota **inicio){
    gota *aux = *inicio, *temp_aux = NULL;
    while(aux!=NULL){
        if(aux->car == 'e' && aux->x == gotaa->x && aux->y == gotaa->y){
            if(temp_aux==NULL){
                *inicio=gotaa->prox;
                free(gotaa);
            }else{
                temp_aux->prox=gotaa->prox;
                free(gotaa);
            }
            return(1);
        }
        temp_aux=aux;
        aux=aux->prox;
    }
    return(0);
}
void novagota(gota *gotaa, gota **inicio){
    if(gotaa->car != 'e'){
        if(verificar(gotaa, inicio)==1){
            return;
        }
    }
    if(gotaa->car == 'e'){
        gotaa->x+=2;
    }else{
        gotaa->x++;
    }
    if(gotaa->x>=MAX_LIN){
        quebradegotas(inicio, gotaa->x, gotaa->y);
    }else{
        gotaa->c = -1;
    }
}
void raindrops(gota **inicio){
    gota *aux, *temp_aux;
    int n = 0;
    while(*inicio!=NULL){
        for(int i = 0; i <= MAX_COL; i++){
            printf("-");
        }
        printf("\n");
        for(int i = 1; i < MAX_LIN; i++){
            printf("+");
            for(int j = 1; j < MAX_COL; j++){
                aux = *inicio;
                temp_aux = buscador(aux, i, j);
                if(temp_aux != NULL && temp_aux->c != -1){
                    if(temp_aux->car == 'e'){
                        printf("E");
                    }else{
                        printf("G");
                    }
                    novagota(temp_aux, inicio);
                }else{
                    printf(" ");
                }
            }
            printf("+\n");
        }
        for(int i = 0; i <= MAX_COL; i++){
            printf("-");
        }
        printf("\n");
        aux = *inicio;
        while(aux!=NULL){
            aux->c = 0;
            aux=aux->prox;
        }
        n++;
        Sleep(800);
    }
    for(int i = 0; i <= MAX_COL; i++){
        printf("-");
    }
    for(int i = 1; i < MAX_LIN; i++){
        printf("\n+");
        for(int j = 1; j < MAX_COL; j++){
            printf(" ");
        }
        printf("+");
    }
    printf("\n");
    for(int i = 0; i <= MAX_COL; i++){
        printf("-");
    }
    printf("\n");
    printf("Fim do programa. O numero de passos foi: %d\n", n);
}