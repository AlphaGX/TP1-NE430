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


#define tc_clear_screen() puts("\x1B[2J")
#define tc_move_cursor(X, Y) printf("\033[%d;%dH", Y, X)
void print_tree(){
	int x,y,yf;
	void print_tree_aux(Noeud* n){
		//printf("[%ld] 0:%ld | 1:%ld\n",n,n->zero,n->one);
		if(n->zero) {
			printf("0"); x++; yf=1;
			print_tree_aux(n->zero);
		}
		if(n->one) {
			printf("1"); x++; yf=1;
			print_tree_aux(n->one);
		}
		if(yf) {
			y++; yf=0;
			tc_move_cursor(70, y); printf("[");
		}
		x--;
		tc_move_cursor(x, y);
	}
	x=71; y=5; yf=1;
	tc_move_cursor(70, y); printf("[");
	//tc_clear_screen();
	print_tree_aux(&tree_root);
}
	

void free_tree_aux(Noeud* n){
	if(n){
		free_tree_aux(n->zero);
		free_tree_aux(n->one);
		free(n);
	}
	return;
}
void free_tree(){
	free_tree_aux(tree_root.zero);
	free_tree_aux(tree_root.one);
}



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
		(same pour 1)
		masque<<1
	}
	noeud.entry = gw
*/
{
	Noeud* n = &tree_root;
	printf("Hello\t");//mask:%uX\tgw:%uX\t",netmask,gw);
	while(netmask){
		printf("%d",(addr>>31)&1);
		if(addr&0x80000000){ // Case 1
			if(!n->one)
				n->one=malloc(sizeof(Noeud));
			n = n->one;
		} else //	---- ---- - Case 0
			/*{
			if(!n->zero)
				n->zero=malloc(sizeof(Noeud));
			n = n->zero;
			}*/
			n = n->zero ? n->zero : (n->zero=malloc(sizeof(Noeud)));
			
		netmask<<=1;
		addr<<=1;
	}
	printf("\tlast node %ld\n",n);
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
	gw = p->gw
*/
{
	Noeud* n;//ode
	Noeud* b;//ackup
	if(addr&0x80000000) n=tree_root.one;
	else n=tree_root.zero;
	while(n){
		if (n->entry) b = n;
		addr<<=1;
		if(addr&0x80000000) n=n->one;
		else n=n->zero;
	}
	return b->entry;
	/* main temporaire 
	printf("\nPrint\n");
	print_tree();
	printf("\nFree\n");
	free_tree();
	exit(0);
	*/
	
}




