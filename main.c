#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct pessoa{
    char nome[20];
    int idade;
};

int main(){
    void *pBuffer;                  //somente ponteiros
    struct pessoa *p;
    int *a, *cp, *i, *k;
    char *trashnome;

    pBuffer = malloc((sizeof(int)*4));

        a = (int*)pBuffer;
        cp = a + 1;
        i = cp + 1;
        k = i + 1;
        trashnome = (char*)(k + 1);
        p = (struct pessoa*)(trashnome + 1);

do{
    printf("Escolha:\n\n 1 - incluir\n 2 - buscar\n 3 - listar\n 4 - remove\n 5 - sair\n\n"); scanf("%d", a);

    if(*a >= 1 && *a<=5){
        switch(*a){
            case 1:
                *cp = *cp + 1;                                      //contador de pessoa comeca com 1
                pBuffer = realloc(pBuffer, (sizeof(int)*4) + (sizeof(struct pessoa)*(*cp)) + (sizeof(char)*20));       //realloc de 4 inteiros, struct de n pessoas, e 20 espaços para char

                    a = (int*)pBuffer;                              //set no endereço de memoria    //casting   //armazenamento de variaveis
                    cp = a + 1;
                    i = cp + 1;
                    k = i + 1;
                    trashnome = (char*)(k + 1);
                    p = (struct pessoa*)(trashnome + 1);            //inicio da agenda

                    p = p + *cp;                                    //pula pra proxima pessoa de acordo com o numero de pessoas
                    printf("Nome:\n"); scanf("%s", p->nome);
                    printf("Idade:\n"); scanf("%d", &p->idade);
            break;

            case 2:
                printf("Digite o nome da pessoa que voce deseja buscar:\n");
                scanf("%s", trashnome);                             //char para comparar o nome

                if(*cp >= 1){
                    p = (struct pessoa*)(trashnome + 1);            //set comeco da agenda
                    p = p + 1;                                      // pular 1, se nao buga na hora de buscar
                    for(*k = 0; *k < *cp; *k = *k + 1){
                           if(strcmp(p->nome, trashnome) == 0){
                                printf("Nome: %s\n", p->nome);
                                printf("Idade: %d\n\n", p->idade);
                            }
                            p = p + 1;                              //prox nome da agenda
                    }
                }else{
                printf("nao tem nenhuma pessoa na agenda:\n");
                }
            break;

            case 3:
                if (*cp >= 1){
                    p = (struct pessoa*)(trashnome + 1);    //set começo da agenda
                    for(*i = 0; *i < *cp; *i = *i + 1){
                            p = p + 1;                      //prox pessoa
                            printf("Nome: %s\n", p->nome);
                            printf("Idade: %d\n\n", p->idade);
                    }
                }else{
                    printf("Nenhum usuario foi digitado:\n");
                }
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
   }while(*a != 5);
    return 0;
}
