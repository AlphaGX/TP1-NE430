#include <stdlib.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h> 
#include <string.h> 

#include <assert.h> //++

#define MAXLEN 100 

void initMyAlgo();

void insertMyAlgo(unsigned int addr,unsigned int netmask,unsigned int gw);

unsigned int lookupMyAlgo(unsigned int addr);
 
void print_tree();
void free_tree();
int test(char *path) //++
{
	FILE *fi;
	char s[MAXLEN],*p,*start,*start2; 
 	struct in_addr c; 
	unsigned int addr,gw,res,i; 

	// first sanity check 
	if (!path) return 0; 
	if ((fi=fopen(path,"r")) == NULL ) {perror("file unaccessible"); exit(1);} 

	i=0;
	// read file line by line (max = MAXLEN ) 
	while (fgets(s,MAXLEN,fi) != NULL) {
		s[MAXLEN-1]=0; 
		p=start=s; 
		// seek for blank char
		while (*p && (*p != ' ')) p++; 
		if (p > start) {
			*p=0; p++;  
			if (inet_aton(start,&c) == 0 ) continue; 
			addr=htonl(c.s_addr);  			
		}
		// skip remaining blank char 
		while (*p && (*p == ' ')) p++;

		// stat a new search for blank char 
		start2=p; 
		while (*p && (*p != ' ')) p++; 
		if (p > start2) {
			*p=0; p++;  
			if (inet_aton(start2,&c) == 0 ) continue; 
			gw=htonl(c.s_addr);
		}		
		// skip remaining blank char 
		while (*p && (*p == ' ')) p++;


		// call your function to get gateway corresponding to ip
		res = lookupMyAlgo(addr);
		if(res!=gw) printf("(res:%X)==(gw:%X) addr=%s %d\n",res,gw,start,i++);
		//assert(res==gw);
	}
	fclose(fi); 
	return 1; 
}




// This function must not be modified !!! 
int loadFile(char *path) 
{
	FILE *fi;
	char s[MAXLEN],*p,*start; 
 	struct in_addr c; 
	unsigned int addr,netmask,gw; 

	// first sanity check 
	if (!path) return 0; 
	if ((fi=fopen(path,"r")) == NULL ) return 0; 

	// read file line by line (max = MAXLEN ) 
	while (fgets(s,MAXLEN,fi) != NULL) {
		s[MAXLEN-1]=0; 
		p=start=s; 
		// seek for blank char
		while (*p && (*p != ' ')) p++; 
		if (p > start) {
			*p=0; p++;  
			if (inet_aton(start,&c) == 0 ) continue; 
			addr=htonl(c.s_addr);  			
		}
		// skip remaining blank char 
		while (*p && (*p == ' ')) p++;

		// stat a new search for blank char 
		start=p; 
		while (*p && (*p != ' ')) p++; 
		if (p > start) {
			*p=0; p++;  
			if (inet_aton(start,&c) == 0 ) continue; 
			netmask=htonl(c.s_addr);
		}		
		// skip remaining blank char 
		while (*p && (*p == ' ')) p++;

		// stat a new search for blank '\n' char 		
		start=p; 
		while (*p && (*p != '\n')) p++; 
		if (p > start) { 
			*p=0; p++;  
			if (inet_aton(start,&c) == 0 ) continue; 
			gw=htonl(c.s_addr);
		}

		// call your function to insert entry to routing table 
		insertMyAlgo(addr,netmask,gw); 	
	}
	fclose(fi); 
	return 1; 
}

// only for debug purpose might be modified ! 
int main (int argc,char *argv[])
{
	//char s[MAXLEN]; //--
	//int addr; //--
 	//struct in_addr a; //--
 
	initMyAlgo();  
	if ((argc > 1 ) && (loadFile(argv[1]))) { 
		/*while (1) {
			fgets(s,MAXLEN,stdin);
			s[MAXLEN-1]=0; 
			if (inet_aton(s,&a) == 0 ) continue; 
			addr=htonl(a.s_addr);
			a.s_addr=htonl(lookupMyAlgo(addr)); 
			printf("GW found = %s\n",inet_ntoa(a)); 		 
		}	*/ //--
		test("iptest.resultat"); //++
		
	}
	return 0; 	 
}

