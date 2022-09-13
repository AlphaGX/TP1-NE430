/* Oui */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node {
	struct node* zero;
	struct node* one;
	uint32_t entry;	
} Noeud;


Noeud tree_root = {NULL,NULL,0};


/* InitMyAlgo */
void initMyAlgo(){
/* creer tree_root */
return;
}
/* InsertMyAlgo */
void insertMyAlgo(unsigned int addr,unsigned int netmask,unsigned int gw)
/*
	noeud = tree_root
	Tant que (masque){
		Lire premier bit
		Si 0 , 
			si nn noeud.zero , creer noeud.zero
			noeud = noeud.zero
		fin si
		(same pour 1) Si 1 , noeud = noeud.one
		masque<<1
	}
	noeud.entry = gw
*/
{
	Noeud* n = &tree_root;
	while(netmask){
		if(addr&0x80000000){ // Case 1
			if(!n->one)
				n->one=malloc(sizeof(Noeud));
			n = n->one;
		} else { //	---- ---- - Case 0
			n = n->zero ? n->zero : malloc(sizeof(Noeud));
		}
		netmask<<=1;
		addr<<=1;
	}
	n->entry = gw;
}
/* lookupMyAlgo */
unsigned int lookupMyAlgo(unsigned int addr)
/*
	noeud = tree_root
	*p;
	Lire premier bit i
		Si 0 , 
			suivant = noeud.zero
		Si 1 , 
			suivant = noeud.one
	Tant que (suivant){
		Si noeud.gw
			Alors *p = noeud
		Lire premier bit i
		Si 0 , 
			suivant = noeud.zero
		Si 1 , 
			suivant = noeud.one
		i++
	}
	noeud.entry = gw
*/
{}




