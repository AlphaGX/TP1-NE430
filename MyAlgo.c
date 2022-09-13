/* Oui */





typedef struct {
	noeud* zero;
	noeud* one;
	uint32_t entry;	
} noeud;

/* InitMyAlgo */
/* creer tree_root */

/* InsertMyAlgo */
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

/* lookupMyAlgo */
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