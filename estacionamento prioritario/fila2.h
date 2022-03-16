#define N 100

struct fila{
	int n;
	int ini;
	float vet[N];
};

struct lista{
	float placa;
	int idade;
	struct lista *prox;
};
typedef struct lista Lista;

struct filal{
	Lista *ini;
	// Lista *fim; 
};



typedef struct fila Fila2;
typedef struct filal FilaL2;


FilaL2 *fila_cria_l();
// void fila_insere_l(FilaL2 *f, char v[20]);
// char *fila_retira_l(FilaL2 *f);
int fila_vazia_l(FilaL2 *f);
// void fila_libera_l(FilaL2 *f);
void fila_imprime_l(FilaL2 *f);
// Lista* fila_busca_l(FilaL2 *fila, char informacao[]);
void fila_insere_ini_l(FilaL2 *fila, float v, int i);
Lista fila_retira_fim_l(FilaL2 *fila);
Lista* fila_busca_l(FilaL2 *fila, float placa);
Lista *lst_insere_ordenado(Lista *l, float v, int i);
