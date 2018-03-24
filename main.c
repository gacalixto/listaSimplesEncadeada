#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//STRUCTS
typedef struct{
    int numero;
    int ranking;
}tipoAluno;

typedef struct node{
    tipoAluno info;
    struct node *prox;
}tipoLista;
//END STRUCTS

//FUNCTIONS
tipoLista *initList(){

    return NULL;
}

void addNodeTop(tipoLista **lista,tipoAluno al){

    tipoLista *new;
    new = (tipoLista*)calloc(sizeof(tipoLista),1);
    new->info=al;
    new->prox=*lista;
    *lista=new;

}

void addNodeEnd(tipoLista **lista,tipoAluno al){
    tipoLista *new,*prev,*act;
    new = (tipoLista*)calloc(sizeof(tipoLista),1);
    new->info=al;
    new->prox=NULL;
    if(*lista==NULL)
    {
        *lista=new;
    }
    else {
        prev=NULL;
        act=*lista;
        while (act != NULL) {
            prev = act;
            act = act->prox;

        }
        prev->prox=new;
    }
}

void showList(tipoLista *lista){
    tipoLista *aux;
    aux=lista;
    while(aux!=NULL){
        printf("Number:%d\nRanking:%d\n",aux->info.numero,aux->info.ranking);
        aux=aux->prox;
    }


}
//END FUNCTIONS

int main() {
    int opc;
    tipoLista *l;
    tipoAluno al;
    l=initList();

    do{
        printf("Choose an operation:\n");
        printf("1-Create List\n2-Insert a Node at the top\n3-Insert a node at the end\n4-Show List\n");
        printf("Input:");
        scanf("%d",&opc);
        switch (opc){
            case 1:
                l=initList();
                break;
            case 2:
                printf("Type a number:");
                scanf("%d",&al.numero);
                printf("type a ranking:");
                scanf("%d",&al.ranking);
                addNodeTop(&l,al);
                system("cls");
                break;
            case 3:
                printf("Type a number:");
                scanf("%d",&al.numero);
                printf("type a ranking:");
                scanf("%d",&al.ranking);
                addNodeEnd(&l,al);
                system("cls");
                break;
            case 4:
                showList(l);
                break;
        }

    }while(opc!=0);
    return 0;
}