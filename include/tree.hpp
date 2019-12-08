#ifndef TREE_H
#define TREE_H 


#include <iostream>
#include <sstream>
#include <queue>
#include <string>

namespace AVL
{

	struct Avl_Node 
	{

	public:
		int altura;
		int chave;
		Avl_Node*  esq;
		Avl_Node* dir;


		Avl_Node(int ch, Avl_Node *es = nullptr, Avl_Node *di = nullptr, int at = 1) : chave {ch}, esq {es}, dir {di}, altura {at} {}

		Avl_Node &operator=(const Avl_Node &other)
		{
			altura = other.altura;
			chave = other.chave;
			dir = other.dir;
			esq = other.esq;

			return *this;
		}

	};

	class Tree
	{
	private:
		
		Avl_Node* raiz;

		int altura(Avl_Node *R);

		Avl_Node *rotacEsq(Avl_Node *z);
		Avl_Node *rotacDir(Avl_Node *w);

		Avl_Node *busca(Avl_Node *no, int chave);
		Avl_Node *inserir(Avl_Node *no, int chave);

		int balanceamento(Avl_Node *R);


	public:

		Tree(Avl_Node *r = nullptr) : raiz{r} {}

		std::string toString();

		Avl_Node * achar(int chave) {return busca(raiz, chave);} 

		void adicionar(int chave) { raiz = inserir(raiz, chave) ;}

	};

}
#endif