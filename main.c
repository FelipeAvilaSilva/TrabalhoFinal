#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct pessoa{
    char nome[20];
    int idade;
};

int main(){
    void *pBuffer; //aloc
    struct pessoa *p; //aloc
    int *a; //alloc

    pBuffer = malloc(sizeof(int) + sizeof(struct pessoa));
    a = pBuffer;
    p = (struct pessoa*)a + 1;
do{
    printf("Escolha:\n\n 1 - incluir\n 2 - buscar\n 3 - listar\n 4 - exit\n\n"); scanf("%d", a);


    if (*a >= 1 || *a<=5){
        switch(*a){
            case 1:
                pBuffer = (void*) realloc(pBuffer, sizeof(int) + sizeof(struct pessoa));
                a = pBuffer;
                p = (struct pessoa*)a + 1;


                printf("Nome:\n"); scanf("%s", p->nome);
                printf("Idade:\n"); scanf("%d", &p->idade);

            break;

            case 2:

            break;

            case 3:

            break;

            case 4:

            break;

            case 5:
                printf("SAINDO DO PROGRAMA:\n"); exit(1);
            break;
            }
    }else{
        printf("opção invalida:\n QUIT !\n");
        exit(1);
    }
   }while(*a != 4);

    return 0;
}
