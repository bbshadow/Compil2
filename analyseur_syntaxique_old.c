#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboles.h"
#include "util.h"
#include "analyseur_syntaxique.h"


int yylex(void);
extern char *yytext;
FILE *yyin;
int uniteCourante;


/* depart tp4 */



void pg(){
	if(uniteCourante == est_premier(odv)){
		odv();
		ldf();
	}
}

void odv(){

}

void ldv(){

}

void ldvb(){

}

void dv(){

}

void ott(){

}

void ldf(){

}

void df(){

}

void lp(){

}

void oldv(){

}

void i(){

}

void iaff(){

}

void ib(){

}


void li(){

}

void isi(){

}

void osinon(){

}

void itq(){

}

void iapp(){

}

void iret(){

}

void iecr(){
  if (uniteCourante == ECRIRE)
  {
    uniteCourante = yylex();
    if (uniteCourante == '(')
    {
      uniteCourante = yylex();
      exp();
      if (uniteCourante == ')')
      {
        uniteCourante = yylex();
        if (uniteCourante == ';')
        {
          uniteCourante = yylex();
        } else {
          printf( "Erreur de syntaxe" );
          exit( -1 );
        }
      } else {
        printf( "Erreur de syntaxe" );
        exit( -1 );
      }
    } else {
      printf( "Erreur de syntaxe" );
      exit( -1 );
    }
  }

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void ivide(){
  if (uniteCourante == ';')
  {
    uniteCourante = yylex();
  }

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void exp(){
  if (est_premier(_conjonction_,uniteCourante))
  {
    conj();
    expB();
  }

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void expB(){
  if (uniteCourante == '|')
  {
    uniteCourante = yylex();
    conj();
    conjB();
  }

  else if (est_suivant(_expressionBis_,uniteCourante))
  {
    /* rien */
  }

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void conj(){
  if (est_premier(_comparaison_,uniteCourante))
  {
    comp();
    conjB();
  }

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void conjB(){
  if (uniteCourante == '&')
  {
    uniteCourante = yylex();
    comp();
    conjB();
  }

  else if (est_suivant(_conjonctionBis_,uniteCourante))
  {
    /* rien */
  }

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void comp(){
  if (est_premier(_expArith_,uniteCourante))
  {
    e();
    compb();
  }

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void compb(){
  if (uniteCourante == '=')
  {
    uniteCourante = yylex();
    e();
    compb();
  } 

  else if (uniteCourante == '<')
  {
    uniteCourante = yylex();
    e();
    compb();
  }

  else if (est_suivant(_comparaisonBis_,uniteCourante))
  {
    
  }

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void e(){
  if (est_premier(_terme_,uniteCourante))
  {
    t();
    eb();
  } 

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void eb(){
  if (uniteCourante == '+')
  {
    uniteCourante = yylex();
    t();
    eb();
  } 

  else if (uniteCourante == '-')
  {
    uniteCourante = yylex();
    t();
    eb();
  } 

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void t(){
  if (est_premier(_negation_,uniteCourante))
  {
    neg();
    tb();
  } 

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void tb(){
  if (uniteCourante == '*')
  {
    uniteCourante = yylex();
    neg();
    tb();
  } 

  else if (uniteCourante == '/')
  {
    uniteCourante = yylex();
    neg();
    tb();
  } 

  else if (est_suivant(_termeBis_,uniteCourante)){ /*rien*/ } 
  
  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void neg(){
  if (uniteCourante == '!')
  {
    uniteCourante = yylex();
    neg();
  } 

  else if (est_premier(_facteur_,uniteCourante))
  {
    f();
  } 

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void f(){
  if (uniteCourante == '(')
  {
    uniteCourante = yylex();
    exp();
    if (uniteCourante == ')')
    {
      uniteCourante = yylex();
    } else {
      printf( "Erreur de syntaxe" );
      exit( -1 );
    }
  } 

  else if (uniteCourante == NOMBRE)
  {
    uniteCourante = yylex();
  } 

  else if(est_premier(_appelFct_,uniteCourante)){
    appf();
  } 

  else if (est_premier(_var_,uniteCourante))
  {
    var();
  } 

  else if (uniteCourante == LIRE)
  {
    uniteCourante = yylex();
    if (uniteCourante == PARENTHESE_OUVRANTE)
    {
      uniteCourante = yylex();
      if (uniteCourante == PARENTHESE_FERMANTE)
      {
        uniteCourante = yylex();
      } else {
        printf( "Erreur de syntaxe" );
        exit( -1 );
      }
    } else {
      printf( "Erreur de syntaxe" );
      exit( -1 );
    }
  } 

  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }

}

void var(){
  if (uniteCourante == ID_VAR)
  {
    uniteCourante = yylex();
    oind();
  } else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void oind(){
  if (uniteCourante == ']')
  {
    uniteCourante = yylex();
    expB();
    if (uniteCourante == ']')
    {
      uniteCourante = yylex();
    } else {
      printf( "Erreur de syntaxe" );
      exit( -1 );
    }
  } 

  else if (est_suivant(_optIndice_,uniteCourante)){ /* rien */ }
  
  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void appf(){
  if (uniteCourante == ID_FCT)
  {
    uniteCourante = yylex();
    if (uniteCourante == '(')
    {
      uniteCourante = yylex();
      if (est_premier(_listeExpressions_,uniteCourante))
      {
        lexp();
        if (uniteCourante == ')')
        {
          uniteCourante = yylex();
        } else {
          printf( "Erreur de syntaxe" );
          exit( -1 );
  }
      }else {
        printf( "Erreur de syntaxe" );
        exit( -1 );
      }
    } else {
      printf( "Erreur de syntaxe" );
      exit( -1 );
    }
  } else {
      printf( "Erreur de syntaxe" );
      exit( -1 );
  }
}

void lexp(){
  if(est_premier(_expression_,uniteCourante)){
    exp();
    lexpb();
  } 

  else if (est_suivant(_listeExpressions_,uniteCourante)){/*rien*/}
  
  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}

void lexpb(){
  if (uniteCourante == ',')
  {
    uniteCourante = yylex();
    exp();
    lexpb();
  } 

  else if (est_suivant(_listeExpressionsBis_,uniteCourante)){/* rien */}
  
  else {
    printf( "Erreur de syntaxe" );
    exit( -1 );
  }
}


int main(int argc, char **argv) {  
  
  char nom[100];
  char valeur[100];  

  yyin = fopen(argv[1], "r");
  if(yyin == NULL){
    fprintf(stderr, "impossible d'ouvrir le fichier %s\n", argv[1]);
    exit(1);
  }
  uniteCourante = yylex();
  E();
  
  return 0;
}