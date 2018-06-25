typedef struct MassaDeDados massa;
typedef struct NO *arvAVL;

arvAVL *cria_arvAVL ();

void liberar_arvAVL(arvAVL *raiz);

int vazia_arvAVL(arvAVL *raiz);

int altura_arvAVL(arvAVL *raiz);

int totalNO_arvAVL(arvAVL *raiz);

void preOrdem_arvAVL(arvAVL *raiz);

void emOrdem_arvAVL(arvAVL *raiz);

void posOrdem_arvAVL(arvAVL *raiz);

int insere_arvAVL(arvAVL *raiz, massa valor);

int remove_arvAVL(arvAVL *raiz, massa valor);

int consulta_arvAVL(arvAVL *raiz, massa valor);

struct NO *procuramenor(struct NO *atual);

void libera_NO(struct NO *no);

int fatorBalanceamento_NO(struct NO *no);

void rotacaoLL(arvAVL *raiz);

void rotacaoLR(arvAVL *raiz);

void rotacaoRR(arvAVL *raiz);

void rotacaoRL(arvAVL *raiz);

int alt_no(struct NO *no);

int maior (int x, int y);
