#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct pessoa{
    char nome[20];
    int idade;
};

int main(){
    void *pBuffer; //aloc
    struct pessoa *p; //aloc
    int *a, *cp, *i, *k;
    char *trashnome; //alloc
    cp = 0;


        /*if(*cp == 0){ // para nao zerar o malloc
            cp = 1;
        }*/
    pBuffer = malloc((sizeof(int)*4) + (sizeof(struct pessoa)*5) + (sizeof(char)*20));
        /*if(*cp == 1){ // recuperando valor original
            cp = 0;
        }*/
    a = (int*)pBuffer;
    cp = a + 1;
    i = cp + 1;
    p = (struct pessoa*)i + 1;
    k = (int*)p + 1;
    trashnome = (char*)k + 1;

do{
    printf("Escolha:\n\n 1 - incluir\n 2 - buscar\n 3 - listar\n 4 - exit\n\n"); scanf("%d", a);


    if (*a >= 1 || *a<=5){
        switch(*a){
            case 1:
                pBuffer = realloc(pBuffer, (sizeof(int)*4) + (sizeof(struct pessoa)*5) + (sizeof(char)*20));

                a = (int*)pBuffer;
                cp = a + 1;
                i = cp + 1;
                p = (struct pessoa*)i + 1;
                k = (int*)p + 1;
                trashnome = (char*)k + 1;

                printf("Nome:\n"); scanf("%s", p->nome);
                printf("Idade:\n"); scanf("%d", &p->idade);
               // p = p + 1;
                *cp = *cp + 1;


            break;

            case 2:
                printf("Digite o nome da pessoa que voce deseja buscar:\n");
                scanf("%s", trashnome);

                //printf("trash: %s\n", trashnome);
                //printf("p->nome %s\n", p->nome);


                if(*cp >= 1){
                    p = (struct pessoa*)i + 1;
                    for(*k = 0; *k < *cp; *k = *k + 1){
                        //printf("p->nome %s\n", p->nome);
                           if(strcmp(p->nome, trashnome) != 0){
                                printf("Nome: %s\n", p->nome);
                                printf("Idade: %d\n\n", p->idade);
                            }else{
                            printf("Esse nome nao tem na agenda:\n");
                            }
                            p = p + 1;
                    }
                }else{
                printf("nao tem nenhuma pessoa na agenda:\n");
                }






           //   printf("i: %d, cp: %d", *i, *cp); //teste

            break;

            case 3:

                if (*cp >= 1){
                        p = (struct pessoa*)i + 1;
                    for(*i = 0; *i < *cp; *i = *i + 1){
                        printf("Nome: %s\n", p->nome);
                        printf("Idade: %d\n\n", p->idade);
                        p = p + 1;
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
   }while(*a != 4);

    return 0;
}
