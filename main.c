#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct pessoa{
    char nome[20];
    int idade;
};

struct pessoa *p_aux, min;
int *i, *k;

void tirar(void *pBuffer, int *i, int *k, int *cp, char *trashnome, struct pessoa *p){
p = p_aux + 1;
    for(*i = 0; *i < *cp; *i = *i + 1){
        if(strcmp(p->nome, trashnome) == 0){
            for(*k = *i; *k < *cp; *k = *k + 1){
                *p = *(p+1);
                p = p + 1;
            }
            *cp = *cp - 1;
            pBuffer = realloc(pBuffer, sizeof(int)*4 + sizeof(struct pessoa)*2*(*cp + 1));
        }
        p = p + 1;
    }
}

void InsertSort(int *i, int *k, int *cp, struct pessoa *p){
p = p_aux + 1;
    for(*i = 1; *i < *cp; *i = *i + 1){
        *k = *i - 1;
        *p_aux = *(p + (*i));
        while ((*k) >= 0 && (p+(*k))->idade > p_aux->idade){
            *(p + *k + 1) = *(p + *k);
            *k = *k -1;
        }
    *(p + *k + 1) = *p_aux;
    }
}

void BubbleSort(int *i, int *k, int *cp, struct pessoa *p){
p = p_aux + 1;
    for(*i = 1; *i < *cp; *i = *i + *i){
        for(*k = 0; *k < *cp -1; *k = *k + 1){
            if((p+(*k))->idade > (p+(*k + 1))->idade){                
                *p_aux = *(p + *k);
                *(p + *k) = *(p + *k + 1);
                *(p + *k + 1) = *p_aux;
            }

        }

    }

}

void SelectionSort(int *a, int *i, int *k, struct pessoa *p, int *cp){	
	p = p_aux + 1;
	for(*i = 0; *i < (*cp-1); *i = *i + 1){
		*a = *i;
		for(*k = (*i+1); *k < *cp; *k = *k + 1){
			if((p+*k)->idade < (p+*a)->idade){
				*a = *k;
			}
		}
			if((p+(*i))->idade != (p+(*a))->idade){
				*p_aux = *(p + *i);
				*(p + *i) = *(p + *a);
				*(p + *a) = *p_aux;					
			}
		
	}
}

void QuickSort(struct pessoa *p, int esq, int *cp){
	int a=0;
	p = p_aux + 1;
		*i = esq;
		*k = *cp-1;
		a = (p+((*i + *k)/2))->idade; //a = média
		do{
			while ((p+(*i))->idade < a) *i= *i+1;
			while (a < (p+(*k))->idade)  *k= *k-1;
			if (*i <= *k){
				
				*p_aux = *(p + *i);
				*(p + *i) = *(p + *k);
				*(p + *k) = *p_aux;

				*i = *i+1;
				*k = *k-1;
			}			
		}while (*i <= *k);
			if (esq < *k) QuickSort(p, esq, k);
			if (*i < *cp) QuickSort(p, *i, cp);
}


int main(){
    void *pBuffer;                  //somente ponteiros
    struct pessoa *p;
    int *a, *cp, dir;
    char *trashnome;

    pBuffer = malloc((sizeof(int)*4));

        a = (int*)pBuffer;
        cp = a + 1;
        i = cp + 1;
        k = i + 1;
        trashnome = (char*)(k + 1);
        p_aux = (struct pessoa*)(trashnome + 1);
        p = p_aux;

do{
    printf("Escolha:\n\n 1 - incluir\n 2 - buscar\n 3 - listar\n 4 - remove\n 5 - ordenar\n 6 - sair\n\n"); 
    scanf("%d", a);

    if(*a >= 1 && *a<=6){
        switch(*a){
            case 1:
                *cp = *cp + 1;                                      //contador de pessoa comeca com 1
                pBuffer = realloc(pBuffer, (sizeof(int)*4) + (sizeof(struct pessoa)*(*cp)) + (sizeof(char)*20));       //realloc de 4 inteiros, struct de n pessoas, e 20 espaços para char

                    a = (int*)pBuffer;
                    cp = a + 1;
                    i = cp + 1;
                    k = i + 1;
                    trashnome = (char*)(k + 1);
                    p_aux = (struct pessoa*)(trashnome + 1);
                    p = p_aux;                                              //inicio da agenda

                    p = p + *cp;                                          //pula pra proxima pessoa de acordo com o numero de pessoas
                    printf("Nome:\n"); scanf("%s", p->nome);
                    printf("Idade:\n"); scanf("%d", &p->idade);
            break;

            case 2:
                printf("Digite o nome da pessoa que voce deseja buscar:\n");
                scanf("%s", trashnome);                                          //char para comparar o nome
                p = p_aux + 1;                                                  //set comeco da agenda
                if(*cp >= 1){
                    for(*k = 0; *k < *cp; *k = *k + 1){
                        if(strcmp((p+*k)->nome, trashnome) == 0){
                            printf("Nome: %s\n", (p+*k)->nome);
                            printf("Idade: %d\n\n", (p+*k)->idade);              // (p+*k) e um incrementador
                        }
                    }
                }else if(*cp < 1){
                    printf("nao tem nenhuma pessoa na agenda:\n");
                }
            break;

            case 3:
                if (*cp >= 1){
                    p = p_aux;   //set começo da agenda
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
                printf("Digite o nome a ser removido:\n");
                scanf("%s", trashnome);
                tirar(pBuffer, i, k, cp, trashnome, p);
            break;

            case 5:
                   printf("1 - InsertSort\n");
                   printf("2 - BubbleSort\n");
                   printf("3 - SelectionSort\n");
                   printf("4 - QuickSort\n");

                   scanf("%d", a);

                    switch(*a){
                        case 1:
                            InsertSort(i, k, cp, p);
                        break;

                        case 2:
                            BubbleSort(i, k, cp, p);
                        break;

                        case 3:
                        	SelectionSort(a, i, k, p, cp);
                        break;

                        case 4:           
                           	QuickSort(p, 0, cp); 
                        break;
                    }                                                        
            break;

            case 6:
                printf("SAINDO DO PROGRAMA:\n"); exit(1);
            break;
            }
    }else{
        printf("opção invalida:\n QUIT !\n");
        exit(1);
    }
   }while(*a != 6);
   free(pBuffer);
    return 0;
}
