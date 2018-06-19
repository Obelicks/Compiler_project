#include <stdio.h>
#include "../headers/gen.h"

void generate_LIST(LIST *l){
  fprintf(stderr, "enter generate_LIST with variable %d\n",l->kind );
  LIST* apointer;//
  int countes = 0;
  int countes2;
  switch (l->kind) {
    case parK:
      if(l->val.parL == NULL){
        return NULL;
      }
      generate_LIST(l->val.parL);
      break;

    case varlistK:
      fprintf(stderr, "generating var_list" );
      apointer = l->val.varlistL.var_decl_list;
      while (apointer !=NULL){
        countes ++;
        apointer = apointer->val.varlistL.var_decl_list;
      }
      countes = countes * 3;
      countes2 = countes * 4;
      fprintf(stdout,";section	.text\n");

      fprintf(stdout,"global allocate \n");

      fprintf(stdout,"allocate:\n");


      fprintf(stdout,"mov	45, eax\n");	//	 ;sys_brk
      fprintf(stdout,"xor	ebx, ebx\n");
      fprintf(stdout,"int	80h\n");

      fprintf(stdout,"add	$%i, eax\n", countes2);
      fprintf(stdout,"mov	eax, ebx\n");
      fprintf(stdout,"mov	45, eax\n");	//	 ;sys_brk
      fprintf(stdout,"int	80h\n");

      fprintf(stdout,"cmp	0, eax\n");
      fprintf(stdout,"jl	exit\n");
      fprintf(stdout,"mov	eax, edi\n");	 //;EDI = highest available address
      fprintf(stdout,"sub	4, edi\n");		 //;pointing to the last DWORD
      fprintf(stdout,"mov	$%i, ecx\n", countes);	// ;number of DWORDs allocated
      fprintf(stdout,"xor	eax, eax\n");	 //;clear eax
      fprintf(stdout,"std\n");			// ;backward
      fprintf(stdout,"rep	stosd\n"); //          ;repete for entire allocated area
      fprintf(stdout,"cld\n");			// ;put DF flag to normal state

      fprintf(stdout,"exit:\n");
      fprintf(stdout,"mov	1, eax\n");
      fprintf(stdout,"xor	ebx, ebx\n");
      fprintf(stdout,"int	80h\n");



      //generate_TYPE(l->val.varlistL.var_type);
      //generate_LIST(l->val.varlistL.var_decl_list);



    case varK:

      generate_TYPE(l->val.varL);
      break;

    case decK:
    
      generate_DEC(l->val.decL.declaration);
      break;

    case stateK:
      generate_STM(l->val.stateL);
      break;

    case statelistK:
      //fprintf(stderr,"statelist1\n");
      generate_STM(l->val.statelistL.statement);
      //fprintf(stderr,"statelist2\n");
      generate_LIST(l->val.statelistL.statement_list);
      break;

    case actlistK:
      generate_LIST(l->val.actlistL);
      break;

    case expressionK:
      generate_EXP(l->val.expressionL);
      break;

    case explistK:
      generate_EXP(l->val.explistL.expression);
      generate_LIST(l->val.explistL.exp_list);
      break;

    default:
      fprintf(stderr,"in default case in LIST\n");
      break;
  }

}
