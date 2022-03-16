//definindo estrutura da arvore binaria
typedef struct arv{
	char dado;
	struct arv *esq;
	struct arv *dir;
}Arv;

//typedef struct arv Arv;

//definindo estrutura da arvore variavel
typedef struct arvvar{
	char dado;
	struct arvvar *prim; //ponteiro para o primeiro filho
	struct arvvar *prox; //ponteiro para o irmao
}Arvv;

//typedef struct arvvar Arvv;

//arvores binarias
Arv *arv_criavazia();
Arv *arv_cria(char c, Arv *sae, Arv *sad);
int arv_vazia(Arv *a);
void arv_imprime (Arv *a);
Arv *arv_libera (Arv *a);
int arv_pertence (Arv *a, char c);
static int max2(int a, int b);
int arv_altura (Arv *a);
Arv *arv_insere(Arv *a, char c);
void arv_imprimeO (Arv *a);

//arvores variaveis
Arvv *arvv_cria (char c);
void arvv_insere (Arvv *a, Arvv *sa);
void arvv_imprime (Arvv *a);
int arvv_pertence (Arvv *a, char c);
void arvv_libera (Arvv *a);
int arvv_altura (Arvv *a);

