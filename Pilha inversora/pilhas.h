#define N 500
 
typedef struct pilha_vet {
    int n;
    int vet[N];
} Pilha;
 
struct lista{
    int info;
    struct lista *prox;
};
 
typedef struct lista Lista;
 
typedef struct pilha_lst{
    Lista *prim;
} Pilha_lst;
 
Pilha *pilha_cria();
void pilha_push(Pilha *p, int v);
int pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
void pilha_imprime(Pilha *p);
 
Pilha_lst *pilha_lst_cria();
void pilha_lst_push(Pilha_lst *p, int v);
int pilha_lst_pop(Pilha_lst *p);
int pilha_lst_vazia(Pilha_lst *p);
void pilha_lst_libera(Pilha_lst *p);
void pilha_lst_imprime(Pilha_lst *p);