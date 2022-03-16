struct lista{
    int info;
    struct lista *prox;
};
 
typedef struct lista Lista;
 
/*definindo lista duplamente encadeada*/
struct lista2{
    int info;
    struct lista2 *ant;
    struct lista2 *prox;
};
 
typedef struct lista2 Lista2;
 
/*definindo lista circular*/
struct listaC{
    int info;
    struct listaC *prox;
};
 
typedef struct listaC ListaC;
 
/*Funcoes de lista encadeada*/
 
Lista* lst_cria();
 
Lista* lst_insere(Lista *l, int i);
 
void lst_imprime(Lista *l);
 
int lst_vazia(Lista *l);
 
Lista* lst_busca(Lista *l, int v);
 
Lista *lst_retira(Lista *l, int v);
 
void lst_libera(Lista *l);
 
Lista *lst_insere_ordenado(Lista *l, int v);
 
int lst_igual(Lista *l1, Lista *l2);
 
int lst_compara(Lista *l1, Lista *l2, int n);
 
/*listas circulares*/
ListaC* lstc_cria ();
 
int survivor (ListaC* l1, int v);
 
ListaC* lstc_insere (ListaC *l1,int v);
 
void lcirc_imprime(ListaC *l1); 
 
ListaC* lstc_remove(ListaC *l1, int v);
 
/*listas duplamente encadeadas*/
Lista2 *lst2_insere(Lista2 *l, int v);
 
Lista2 *lst2_busca(Lista2 *l, int v);
 
Lista2 *lst2_retira(Lista2 *l, int v);

void lst_imprime_rec(Lista *l);

Lista *lst_retira_rec(Lista *l, int v);

void lst_libera_rec (Lista *l);