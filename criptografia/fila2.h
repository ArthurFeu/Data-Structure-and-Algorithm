#define N 100

struct fila{
	int n;
	int ini;
	float vet[N];
};

struct lista{
	float id;
	char senha[6];
	char n;
	char info[7];
	struct lista *prox;
};

typedef struct lista Lista;

struct filal{
	Lista *ini;
};



typedef struct fila Fila2;
typedef struct filal FilaL2;


FilaL2 *fila_cria_l();
int fila_vazia_l(FilaL2 *f);
void fila_imprime_l(FilaL2 *f);
void fila_insere_ini_l(FilaL2 *fila, float v,char n[6]);
Lista* fila_busca_l(FilaL2 *fila, float id);
Lista *lst_insere_ordenado(Lista *l, float v,char n[6]);
