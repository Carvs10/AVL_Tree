#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>

class NO_AVL
{
	public:

	NO_AVL *esq;
	NO_AVL *dir; 
	int chave;
	int altura;
		
};

int altura(NO_AVL *N)
{

	if(N == NULL)
		return 0;
	return N->altura;
}

int max(int a, int b)
{
	return( a > b)? a : b;
}

NO_AVL* novoNO(int chave)
{
	NO_AVL* no = new NO_AVL();
	no->esq = NULL;
	no->dir = NULL;
	no->altura = 1;
	no->chave = chave;

	return(no);

}

void preOrdem( NO_AVL *raiz)
{

	if(raiz != NULL){

		cout << raiz->chave << " ";
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

int getBalance(NO_AVL *n)
{

	if(N == NULL)
		return 0;
	return altura(N->esq) - altura(n->dir);
}

NO_AVL *rotaEsq(NO_AVL *x)
{

	NO_AVL *y = x->dir;
	NO_AVL *T2 = y->esq;

	y->esq = x;
	x->dir = T2;

	x->altura = max(altura(x->esq), altura(x->dir)) + 1;

	y->altura = max(altura(y->esq), altura(y->dir)) + 1;

	return y;
}	
	
NO_AVL *rotacDir(NO_AVL *y)
{

	NO_AVL *x = y->esq;
	NO_AVL *T2 = x->dir;

	x->dir = y;
	y->esq = T2;

	y->altura = max(altura(y->esq), altura(y->dir)) + 1;
	x->altura = max(altura(x->esq), altura(x->dir)) + 1;


	return x;
}

	

NO_AVL* inserir(NO_AVL* no, int chave)
{
	/* Inserir como em uma Binaru Search Tree*/
	if(no == NULL)
		return(novoNO(chave));

	if(chave < no->chave)
		no->esq = inserir(no->esq, chave);
	else if(chave > no->chave)
		no->dir = inserir(no->dir, chave);
	else
		return no;


	/* Atualizar a altura do ancestral do no*/
	no->altura = 1 + max(altura(no->esq), altura(no->dir));

	/* Obter o fator de balanceamento */

	int balanceamento = getBalance(no);

	/// Casos de NO desbalenceado

	//Rota Dir-Esq
	if(balanceamento < -1 && chave < no->dir->chave)
	{
		no->dir = rotacDir(no->dir);
		return rotaEsq(no);
	}

	//Rotac Esq-Dir
	if(balanceamento > 1 && chave > no->esq->chave)
	{
		no->esq = rotaEsq(no->esq);
		return rotacDir(no);
	}

	//Rotac Esq
	if(balanceamento > 1 && chave < no->esq->chave)
		return rotacDir(no);

	if (balanceamento < -1 && chave > no->dir->chave)
		return rotaEsq(no);
	

	return no;
	
}