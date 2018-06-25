typedef struct NO *arvAvl;

arvAvl *cria_arvAvl();

void liberar_arvAvl(arvAvl *raiz);

int altura_arvAvl(arvAvl *raiz);

int alt_no(struct NO *no);

void rotacaoRR(arvAvl *raiz);

void rotacaoRL(arvAvl *raiz);

void rotacaoLL(arvAvl *raiz);

void rotacaoLR(arvAvl *raiz);

int fatorBalanceamento_NO(struct NO *no);

int maior(int x,int y);

int insere_arvAvl(arvAvl *raiz, int valor);

int remove_arvAvl(arvAvl *raiz, int valor);

struct NO *procuramenor(struct NO *atual);

int totalNO_arvAvl(arvAvl *raiz);

void preOrdem_arvAvl(arvAvl *raiz);

void posOrdem_arvAvl(arvAvl *raiz);


int consulta_arvAvl(arvAvl *raiz, int valor);

