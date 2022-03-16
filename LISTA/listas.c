#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

/*Funcoes de lista encadeada*/

Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista *l, int i){
	Lista *novo = (Lista*) malloc (sizeof(Lista));
	novo -> info = i;
	novo -> prox = l;
	return novo;
}

void lst_imprime(Lista *l){
	Lista *p;
	for (p=l;p!=NULL;p=p->prox)
		printf ("Info: %d\n", p->info);
}

int lst_vazia(Lista *l){
	if (l==NULL)
		return 1;
	else
		return 0;
}

Lista* lst_busca(Lista *l, int v){
	Lista *p;
	for (p=l;p!=NULL;p=p->prox){
		if (p->info==v)
			return p;
		else
			printf("n achei kk\n");
	}
	return NULL;
}

Lista *lst_retira(Lista *l, int v){
	Lista *ant=NULL;
	Lista *p=l;
	while (p!=NULL&&p->info!=v){
		ant=p;
		p=p->prox;
	}
	if (p==NULL)
		return l;
	if (ant==NULL)
		l=p->prox;
	else
		ant->prox=p->prox;
	free (p);
	return l;
}

void lst_libera(Lista *l){
	Lista *p=l;
	while (p!=NULL){
		Lista *t=p->prox;
		free(p);
		p=t;
	}
}

Lista *lst_insere_ordenado(Lista *l, int v){
	Lista *novo;
	Lista *ant = NULL;
	Lista *p = l;
	while (p!=NULL&&p->info<v){
		ant=p;
		p=p->prox;
	}
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info=v;
	if (ant==NULL){
		novo->prox=l;
		l=novo;
	}
	else {
		novo->prox=ant->prox;
		ant->prox=novo;
	}
	return l;
}

int lst_igual(Lista *l1, Lista *l2){
	while(1){
		if (!l1 && !l2)
			return 1;
		else if(!l1||!l2)
			return 0;
		else if(l1->info!=l2->info)
			return 0;
		l1=l1->prox;
		l2=l2->prox;
	}
}

int lst_compara(Lista *l1, Lista *l2,int n){
	int i=0;
	while (i<n){
		if (!l1 && !l2){
			printf ("As listas tem o mesmo número de elementos\n");
			return 0;
		}else if (!l1 && l2){
			printf("A lista 2 tem mais elementos que a 1");
			return 1;
		}else if (l1 && !l2){
			printf("A lista 1 tem mais elementos que a 2");
			return -1;
		}
		if (l1->info < l2->info){
			printf("%dº: O elemento '%d' da lista 2 é maior que o seu correspondente da lista 1\n",i+1,l2->info); //lista 2 é maior que a lista 1");
			i++;
		}else if (l1->info > l2->info){
			printf("%dº: O elemento '%d' da lista 1 é maior que o seu correspondente da lista 2\n",i+1,l1->info);
			i++;
		}
		l1=l1->prox;
		l2=l2->prox;
	}
	return 0;
}

/*listas circulares*/
ListaC* lstc_cria (){
    ListaC *temp, *r, *l1;
    int a;
    char ch;
    r=NULL;
    l1=NULL;
        while(ch!='N'){
            printf("Digite um numero \n");
            scanf("%d", &a);
            temp = (ListaC*)malloc(sizeof(ListaC));
            temp->info = a;
            temp->prox = NULL;
            if (l1 == NULL){
                l1 = temp;
            }else{
                r->prox = temp;
            }
            r = temp;
            printf("Quer adicionar outro número? Digite S ou N: ");
            scanf(" %c", &ch);
        }
        // printf("a\n");
        r->prox = l1;
        return l1;
    }

int survivor(ListaC *l1, int v){
        ListaC *p, *q;
        int i;
        q = p = l1;
        while (p->prox != p){
            for (i=0;i<v-1;i++){
                q = p;
                p = p->prox;
            }
            q->prox = p->prox;
            printf("%d morreu\n", p->info);
            free(p);
            p = q->prox;
        }
        l1 = p;
        return (p->info);
}

ListaC* lstc_insere(ListaC *l1, int v){
	if (!l1){
		ListaC *novo = (ListaC*) malloc(sizeof(ListaC));
		novo->info = v;
		novo->prox = novo;
		return novo; 
	}
	ListaC* ult = l1;
	while (ult->prox != l1)
		ult = ult->prox;
	ListaC *novo = (ListaC*) malloc(sizeof(ListaC));
	novo->info = v;
	novo->prox = l1;
	ult->prox = novo;
	return novo;
}

void lcirc_imprime(ListaC *l1){
	ListaC *temp;
        temp = l1;
        int c = 10;
        do {
	        printf("%d ", temp->info);
	        temp = temp->prox;
	        c--;
	    } while (c && l1!=temp);
        printf("\n");
}

ListaC* lstc_remove(ListaC *l1, int v){
	if (l1 && l1==l1->prox &&l1->info==v){
		free(l1);
		return NULL;
	}
	for (ListaC* temp=l1;temp->prox && temp->prox!=l1;temp=temp->prox){
		if (temp->prox->info==v){
			ListaC* prox=temp->prox->prox;
			free(temp->prox);
			temp->prox=prox;
			break;
		}
	}
	return l1;

}

/*listas duplamente encadeadas*/
Lista2 *lst2_insere(Lista2 *l, int v){
	Lista2 *novo=(Lista2*) malloc(sizeof(Lista2));
	novo->info=v;
	novo->prox=l;
	novo->ant=NULL;
	if (l!=NULL)
		l->ant=novo;
	return novo;
}

Lista2 *lst2_busca(Lista2 *l, int v){
	/*Lista *p;
	for (p=l;p!=NULL;p=p->prox)
		if (p->info==v)
			return p;
	return NULL; */
}

Lista2 *lst2_retira(Lista2 *l, int v){
	Lista2 *p=lst2_busca(l,v);
	if (p==NULL)
		return l;
	if (l==p)
		l=p->prox;	
	else 
		p->ant->prox=p->prox;
	if (p->prox!=NULL)
		p->prox->ant=p->ant;
	free(p);
	return l;
}

void lst_imprime_rec(Lista *l){
	if (!lst_vazia(l)){
		printf("%d" ,l->info);
		lst_imprime_rec(l->prox);
	}
}

Lista *lst_retira_rec(Lista *l, int v){
	if (!lst_vazia(l)){
		if (l->info==v){
			Lista *t=l;
			l=l->prox;
			free(t);
		}else 
			l->prox=lst_retira_rec(l->prox,v);
	}
	return l;
}

void lst_libera_rec (Lista *l){
	if (!lst_vazia(l)){
		lst_libera_rec(l->prox);
		free(l);
	}
}