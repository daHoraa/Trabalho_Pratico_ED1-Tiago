#include <stdio.h>
#include <stdlib.h>

struct lista{
    char caractere;
    int linha; 
    int n_vezes;  
    struct lista *prox;
};

typedef struct lista Lista;

Lista* lst_cria(){
    return NULL;
}

Lista* lst_insere(Lista *l, char c, int li){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->caractere = c;
    novo->linha = li;
    novo->n_vezes = 1;
    novo->prox = l;
    return novo;
}

void lst_imprime(Lista* l){
    Lista* p;
    for (p = l; p!=NULL; p=p->prox)
        printf("%c -> %i|%i\n", p->caractere, p-> linha, p-> n_vezes);
}

Lista* lst_busca(Lista* l, char c, int li){
    Lista*p;
    for(p = l; p!=NULL; p=p->prox){
        if(p->caractere == c && p->linha == li)
            return p;
    }
    return NULL;
}

Lista *lst_libera(Lista* l){
    Lista* p = l;
    while (p!=NULL){
        Lista* t = p->prox;
        free (p);
        p = t;
    }
}

void main(){
    FILE *fp = fopen("C:\\Users\\DELL\\Documents\\EDI\\arquivo.txt","r");
    char vetor[100];
    char caractere;
    int i;
    int li;

    Lista *l;

    do{  
        caractere = getc(fp);

        if(caractere == '\n'){
            li++;
            lst_imprime(l);
            free(l);
            Lista*l = lst_cria();
        }

        vetor[i] = caractere;
        if(lst_busca(l,caractere, li)==NULL){ 
            lst_insere(l, caractere, li);
        }
        i++;
    } while(caractere != EOF);
    fclose(fp);
    lst_libera(l);
}