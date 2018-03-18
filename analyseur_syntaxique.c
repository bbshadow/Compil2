
#include "analyseur_syntaxique.h"


extern char *yytext;
FILE *yyin;
int uniteCourante;


/* depart tp4 */



void programme(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
	if(est_premier(uniteCourante, _optDecVariables_) || est_premier(EPSILON,_optDecVariables_)){
		optDecVariables();
		listeDecFonctions();
	}
  else {
    printf( "Erreur de syntaxe 1 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
 }



void optDecVariables(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
  if(est_premier(uniteCourante, _listeDecVariables_) || est_premier(EPSILON, _listeDecVariables_)){
   listeDecVariables();
    if (uniteCourante == POINT_VIRGULE)
    {
      consommer(POINT_VIRGULE,&uniteCourante,1);
    }  else {
      printf( "Erreur de syntaxe 3bis : %d", uniteCourante );
      exit( -1 );
    }
  }
  
  else if(est_suivant(uniteCourante,_optDecVariables_)){
    /* rien */
  }
  else {
    printf( "Erreur de syntaxe 3 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}




void listeDecVariables(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
  if(est_premier(uniteCourante,_declarationVariable_) || est_premier(EPSILON,_declarationVariable_)){
   declarationVariable();
   listeDecVariablesBis();
  }
  //test
  else {
  	//Test
    printf( "Erreur de syntaxe 4 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}



void listeDecVariablesBis(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
  if(uniteCourante == VIRGULE){
    consommer(VIRGULE,&uniteCourante,1);
   declarationVariable();
   listeDecVariablesBis();
  } 
  else if(est_suivant(uniteCourante,_listeDecVariablesBis_)){
    /* rien */
  }
  else {
    printf( "Erreur de syntaxe 5 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}


void declarationVariable(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
   if(uniteCourante == ENTIER){
    consommer(ENTIER,&uniteCourante,1);

    if(uniteCourante == ID_VAR){
      consommer(ID_VAR,&uniteCourante,1);
      optTailleTableau();
    } 
    else {
      printf( "Erreur de syntaxe 6 : %d", uniteCourante );
      exit( -1 );
    }

  }
  else {
    printf( "Erreur de syntaxe 7 : %d", uniteCourante );
    exit( -1 );
  } 
  affiche_balise_fermante(__FUNCTION__, 1);
}


void optTailleTableau(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
 if(uniteCourante == CROCHET_OUVRANT){
    consommer(CROCHET_OUVRANT,&uniteCourante,1);
    
    if(uniteCourante == NOMBRE){
      consommer(NOMBRE,&uniteCourante,1); 
      if(uniteCourante == CROCHET_FERMANT){
        consommer(CROCHET_FERMANT,&uniteCourante,1);
      }  
      else {
        printf( "Erreur de syntaxe 8 : %d", uniteCourante );
        exit( -1 );
      }  
    } 
    else {
      printf( "Erreur de syntaxe 9 : %d", uniteCourante );
      exit( -1 );
    }

  }
  else if(est_suivant(uniteCourante,_optTailleTableau_)){
    /* rien */
  }
  else {
    printf( "Erreur de syntaxe 10 : %d", uniteCourante );
    exit( -1 );
  } 
  affiche_balise_fermante(__FUNCTION__, 1);
}


void listeDecFonctions(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
  if(est_premier(uniteCourante,_declarationFonction_)||est_premier(EPSILON,_declarationFonction_)){
    declarationFonction();
    listeDecFonctions();   
  }
  else if(est_suivant(uniteCourante,_listeDecFonctions_)){
    /* rien */
  }
  else {
    printf( "Erreur de syntaxe 11 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}


void declarationFonction(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
 if(uniteCourante == ID_FCT){
    consommer(ID_FCT,&uniteCourante,1);
    listeParam();
    optDecVariables();
    instructionBloc();
  }
  else {
    printf( "Erreur de syntaxe 12 : %d", uniteCourante );
    exit( -1 );
  } 
  affiche_balise_fermante(__FUNCTION__, 1);
}

void listeParam(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
  if(uniteCourante == PARENTHESE_OUVRANTE){
    consommer(PARENTHESE_OUVRANTE,&uniteCourante,1);
    optListeDecVariables();
    if(uniteCourante == PARENTHESE_FERMANTE){
      consommer(PARENTHESE_FERMANTE,&uniteCourante,1); 
    } 
    else {
      printf( "Erreur de syntaxe 13 : %d", uniteCourante );
      exit( -1 );
    }
  } 
  else {
    printf( "Erreur de syntaxe 14 : %d", uniteCourante );
    exit( -1 );
  } 
  affiche_balise_fermante(__FUNCTION__, 1);
}

void optListeDecVariables(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
  if(est_premier(uniteCourante,_listeDecVariables_)||est_premier(EPSILON,_listeDecVariables_)){
   listeDecVariables();   
  }
  else if(est_suivant(uniteCourante,_optListeDecVariables_)){
    /* rien */
  }
  else {
    printf( "Erreur de syntaxe 15 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void instruction(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
  if(est_premier(uniteCourante,_instructionAffect_)||est_premier(EPSILON,_instructionAffect_)){
    instructionAffect();   
  }
  else if(est_premier(uniteCourante,_instructionBloc_)||est_premier(EPSILON,_instructionBloc_)){
    instructionBloc();   
  }
  else if(est_premier(uniteCourante,_instructionSi_)||est_premier(EPSILON,_instructionSi_)){
    instructionSi();   
  }
  else if(est_premier(uniteCourante,_instructionTantque_)||est_premier(EPSILON,_instructionTantque_)){
    instructionTantque();   
  }
  else if(est_premier(uniteCourante,_instructionAppel_)||est_premier(EPSILON,_instructionAppel_)){
    instructionAppel();   
  }
  else if(est_premier(uniteCourante,_instructionRetour_)||est_premier(EPSILON,_instructionRetour_)){
    instructionRetour();   
  }
  else if(est_premier(uniteCourante,_instructionEcriture_)||est_premier(EPSILON,_instructionEcriture_)){
    instructionEcriture();   
  }
  else if(est_premier(uniteCourante,_instructionVide_)||est_premier(EPSILON,_instructionVide_)){
    instructionVide();   
  } else {
    printf( "Erreur de syntaxe 16 : %d", uniteCourante );
    exit( -1 );
  } 
  affiche_balise_fermante(__FUNCTION__, 1);
}

void instructionAffect(){
 affiche_balise_ouvrante(__FUNCTION__, 1);
   if(est_premier(uniteCourante,_var_)||est_premier(EPSILON,_var_)){
    var();
    if(uniteCourante == EGAL){
        consommer(EGAL,&uniteCourante,1);       
        expression();
        if(uniteCourante == POINT_VIRGULE){
         consommer(POINT_VIRGULE,&uniteCourante,1);
        }
         else {
          printf( "Erreur de syntaxe 17 : %d", uniteCourante );
          exit( -1 );
        } 
    }
    else {
      printf( "Erreur de syntaxe 18 : %d", uniteCourante );
       exit( -1 );
     } 
            
  }
   else {
     printf( "Erreur de syntaxe 19 : %d", uniteCourante );
     exit( -1 );
    }
  affiche_balise_fermante(__FUNCTION__, 1); 
  
}

void instructionBloc(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
  if(uniteCourante == ACCOLADE_OUVRANTE){
    consommer(ACCOLADE_OUVRANTE,&uniteCourante,1);
    listeInstructions();
    if(uniteCourante == ACCOLADE_FERMANTE){
      consommer(ACCOLADE_FERMANTE,&uniteCourante,1); 
    } 
    else {
      printf( "Erreur de syntaxe 20 : %d", uniteCourante );
      exit( -1 );
    }
  } 
  else {
    printf( "Erreur de syntaxe 21 : %d", uniteCourante );
    exit( -1 );
  } 
  affiche_balise_fermante(__FUNCTION__, 1);
}


void listeInstructions(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
  if(est_premier(uniteCourante,_instruction_)||est_premier(EPSILON,_instruction_)){
    instruction();
    listeInstructions();
  }
  else if(est_suivant(uniteCourante,_listeInstructions_)){
    /* rien */
  }
  else {
    printf( "Erreur de syntaxe 22 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);

}

void instructionSi(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
  if(uniteCourante == SI){
    consommer(SI,&uniteCourante,1);
    expression();
    if(uniteCourante == ALORS){
      consommer(ALORS,&uniteCourante,1); 
      instructionBloc();
      optSinon();
    } 
    else {
      printf( "Erreur de syntaxe 23 : %d", uniteCourante );
      exit( -1 );
    }
  } 
  else {
    printf( "Erreur de syntaxe 24 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1); 
}

void optSinon(){
  affiche_balise_ouvrante(__FUNCTION__, 1);
 if(uniteCourante == SINON){
    consommer(SINON,&uniteCourante,1);
    instructionBloc();    
  } 
  else if(est_suivant(uniteCourante,_optSinon_)){
    /* rien */
  }
  else {
    printf( "Erreur de syntaxe 25 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1); 
}


void instructionTantque(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
	if(uniteCourante == TANTQUE){
    consommer(TANTQUE,&uniteCourante,1);
    expression();
    if(uniteCourante == FAIRE){
      consommer(FAIRE,&uniteCourante,1); 
      instructionBloc();     
    } 
    else {
      printf( "Erreur de syntaxe 26 : %d", uniteCourante );
      exit( -1 );
    }
  } 
  else {
    printf( "Erreur de syntaxe 27 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1); 
}

void instructionAppel(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
 if(est_premier(uniteCourante,_instructionAppel_)||est_premier(EPSILON,_instructionAppel_)){
    appelFct();
    if(uniteCourante == POINT_VIRGULE){
      consommer(POINT_VIRGULE,&uniteCourante,1);
    }
    else{
      printf( "Erreur de syntaxe 28 : %d", uniteCourante );
      exit( -1 );
    }
  }  
  else {
    printf( "Erreur de syntaxe 29 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void instructionRetour(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
 if(uniteCourante == RETOUR){
    consommer(RETOUR,&uniteCourante,1);
    expression();
    if(uniteCourante == POINT_VIRGULE){
      consommer(POINT_VIRGULE,&uniteCourante,1);           
    } 
    else {
      printf( "Erreur de syntaxe 30 : %d", uniteCourante );
      exit( -1 );
    }
  } 
  else {
    printf( "Erreur de syntaxe 31 : %d", uniteCourante );
    exit( -1 );
  } 
  affiche_balise_fermante(__FUNCTION__, 1);
}

void instructionEcriture(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (uniteCourante == ECRIRE)
  {
    consommer(ECRIRE,&uniteCourante,1);
    if (uniteCourante == PARENTHESE_OUVRANTE)
    {
      consommer(PARENTHESE_OUVRANTE,&uniteCourante,1);
      expression();
      if (uniteCourante == PARENTHESE_FERMANTE)
      {
        consommer(PARENTHESE_FERMANTE,&uniteCourante,1);
        if (uniteCourante == POINT_VIRGULE)
        {
          consommer(POINT_VIRGULE,&uniteCourante,1);
        } else {
          printf( "Erreur de syntaxe 32 : %d", uniteCourante );
          exit( -1 );
        }
      } else {
        printf( "Erreur de syntaxe 33 : %d", uniteCourante );
        exit( -1 );
      }
    } else {
      printf( "Erreur de syntaxe 34 : %d", uniteCourante );
      exit( -1 );
    }
  }

  else {
    printf( "Erreur de syntaxe 35 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void instructionVide(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (uniteCourante == POINT_VIRGULE)
  {
    consommer(POINT_VIRGULE,&uniteCourante,1);
  }

  else {
    printf( "Erreur de syntaxe 36 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void expression(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (est_premier(uniteCourante,_conjonction_)||est_premier(EPSILON,_conjonction_))
  {
    conjonction();
    expressionBis();
  }

  else {
    printf( "Erreur de syntaxe 37 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void expressionBis(){

	affiche_balise_ouvrante(__FUNCTION__, 1); 
  
  if (uniteCourante == OU)
  {
    consommer(OU,&uniteCourante,1);
    conjonction();
    expressionBis();
  } 
  else if (uniteCourante == INTERROGATION)
  {
    consommer(INTERROGATION,&uniteCourante,1);
    expression();
    if (uniteCourante == DEUXPOINTS)
    {
      consommer(DEUXPOINTS,&uniteCourante,1);
      expression();
    } else {
    printf( "Erreur de syntaxe 37 bis : %d", uniteCourante );
    exit( -1 );
  }
  }

  else if (est_suivant(uniteCourante,_expressionBis_))
  {
    /* rien */
  }

  else {
    printf( "Erreur de syntaxe 38 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void conjonction(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (est_premier(uniteCourante,_comparaison_)||est_premier(EPSILON,_comparaison_))
  {
    comparaison();
    conjonctionBis();
  }

  else {
    printf( "Erreur de syntaxe 39 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void conjonctionBis(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (uniteCourante == ET)
  {
    consommer(ET,&uniteCourante,1);
    comparaison();
    conjonctionBis();
  }

  else if (est_suivant(uniteCourante,_conjonctionBis_))
  {
    /* rien */
  }

  else {
    printf( "Erreur de syntaxe 40 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void comparaison(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (est_premier(uniteCourante,_expArith_)||est_premier(EPSILON,_expArith_))
  {
    expArith();
    comparaisonBis();
  }

  else {
    printf( "Erreur de syntaxe 41 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void comparaisonBis(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (uniteCourante == EGAL)
  {
    consommer(EGAL,&uniteCourante,1);
    expArith();
    comparaisonBis();
  } 

  else if (uniteCourante == INFERIEUR)
  {
    consommer(INFERIEUR,&uniteCourante,1);
    expArith();
    comparaisonBis();
  }

  else if (est_suivant(uniteCourante,_comparaisonBis_))
  {
    
  }

  else {
    printf( "Erreur de syntaxe 42 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void expArith(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (est_premier(uniteCourante,_terme_)||est_premier(EPSILON,_terme_))
  {
    terme();
    expArithBis();
  } 

  else {
    printf( "Erreur de syntaxe 43 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void expArithBis(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (uniteCourante == PLUS)
  {
    consommer(PLUS,&uniteCourante,1);
    terme();
    expArithBis();
  } 

  else if (uniteCourante == MOINS)
  {
    consommer(MOINS,&uniteCourante,1);
    terme();
    expArithBis();
  } 

  else if (est_suivant(uniteCourante,_expArithBis_))
  {
    /* rien */
  }

  else {
    printf( "Erreur de syntaxe 44 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void terme(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (est_premier(uniteCourante,_negation_)||est_premier(EPSILON,_negation_))
  {
    negation();
    termeBis();
  } 

  else {
    printf( "Erreur de syntaxe 45 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void termeBis(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (uniteCourante == FOIS)
  {
    consommer(FOIS,&uniteCourante,1);
    negation();
    termeBis();
  } 

  else if (uniteCourante == DIVISE)
  {
    consommer(DIVISE,&uniteCourante,1);
    negation();
    termeBis();
  } 

  else if (est_suivant(uniteCourante,_termeBis_)){ /*rien*/ } 
  
  else {
    printf( "Erreur de syntaxe 46 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

void negation(){
	affiche_balise_ouvrante(__FUNCTION__, 1); 
  if (uniteCourante == NON)
  {
    consommer(NON,&uniteCourante,1);
    negation();
  } 

  else if (est_premier(uniteCourante,_facteur_)||est_premier(EPSILON,_facteur_))
  {
    facteur();
  } 

  else {
    printf( "Erreur de syntaxe 47 : %d", uniteCourante );
    exit( -1 );
  }
  affiche_balise_fermante(__FUNCTION__, 1);
}

// DONE
n_exp *facteur () {
  n_exp *$$ = NULL;
  n_var *$1 = NULL;
  n_appel *$2 = NULL;

  if (uniteCourante == PARENTHESE_OUVRANTE)
  {
	  affiche_balise_ouvrante(__FUNCTION__, 1); 
    consommer(PARENTHESE_OUVRANTE,&uniteCourante,1);
    $$ = expression();
    if (uniteCourante == PARENTHESE_FERMANTE)
    {
      consommer(PARENTHESE_FERMANTE,&uniteCourante,1);
      affiche_balise_fermante(__FUNCTION__, 1);
      return $$;
    } else {
      printf( "Erreur de syntaxe 48 : %d", uniteCourante );
      exit( -1 );
    }
  } 

  else if (uniteCourante == NOMBRE)
  {
    affiche_balise_ouvrante(__FUNCTION__, 1);
    consommer(NOMBRE,&uniteCourante,1);
    affiche_balise_fermante(__FUNCTION__, 1);
    $$ = cree_n_exp_entier(/*TODO*/);
    return $$;
  } 

  else if(est_premier(uniteCourante,_appelFct_)||est_premier(EPSILON,_appelFct_)){
    affiche_balise_ouvrante(__FUNCTION__, 1);
    $2 = appelFct();
    affiche_balise_fermante(__FUNCTION__, 1);
    $$ = cree_n_exp_appel($2);
    return $$;    
  } 

  else if (est_premier(uniteCourante,_var_)||est_premier(EPSILON,_var_))
  {
    affiche_balise_ouvrante(__FUNCTION__, 1);
    $1 = var();
    affiche_balise_fermante(__FUNCTION__, 1);
    $$ = cree_n_exp_var($1);
    return $$;
  } 

  else if (uniteCourante == LIRE)
  {
    affiche_balise_ouvrante(__FUNCTION__, 1);
    consommer(LIRE,&uniteCourante,1);
    if (uniteCourante == PARENTHESE_OUVRANTE)
    {
      consommer(PARENTHESE_OUVRANTE,&uniteCourante,1);
      if (uniteCourante == PARENTHESE_FERMANTE)
      {
        consommer(PARENTHESE_FERMANTE,&uniteCourante,1);
        affiche_balise_fermante(__FUNCTION__, 1);
        $$ = cree_n_exp_lire();
        return $$;
      } else {
        printf( "Erreur de syntaxe 49 : %d", uniteCourante );
        exit( -1 );
      }
    } else {
      printf( "Erreur de syntaxe 50 : %d", uniteCourante );
      exit( -1 );
    }
  } 

  else {
    printf( "Erreur de syntaxe 51 : %d", uniteCourante );
    exit( -1 );
  }
  
  return $$;

}

// DONE
n_var var(){
  n_exp $2 = NULL;
  n_var $$ = NULL;

  if (uniteCourante == ID_VAR)
  {
	  affiche_balise_ouvrante(__FUNCTION__, 1); 
    consommer(ID_VAR,&uniteCourante,1);
    char * tmp = yytext();
    $2 = optIndice();
    $$ = cree_n_var_indicee(tmp, $2); // TODO
    affiche_balise_fermante(__FUNCTION__, 1);
    return $$;
    
  } else {
    printf( "Erreur de syntaxe 52 : %d", uniteCourante );
    exit( -1 );
  }

  return $$;
}

// DONE
n_exp *optIndice (){
  n_exp $$ = NULL;
  if (uniteCourante == CROCHET_OUVRANT)
  {
	  affiche_balise_ouvrante(__FUNCTION__, 1); 
    consommer(CROCHET_OUVRANT,&uniteCourante,1);
    $$ = expression();
    if (uniteCourante == CROCHET_FERMANT)
    {
      consommer(CROCHET_FERMANT,&uniteCourante,1);
      affiche_balise_fermante(__FUNCTION__, 1);
      return $$;
    } else {
      printf( "Erreur de syntaxe 53 : %d", uniteCourante );
      exit( -1 );
    }
  } 

  else if (est_suivant(uniteCourante,_optIndice_)){ 
    affiche_balise_ouvrante(__FUNCTION__, 1);
    affiche_balise_fermante(__FUNCTION__, 1);
    return $$;
  }
  
  else {
    printf( "Erreur de syntaxe 54 : %d", uniteCourante );
    exit( -1 );
  }
  
  return $$;
}

// DONE
n_appel *appelFct(){
  n_appel *$$ = NULL;
  n_l_exp *$3 = NULL;
  if (uniteCourante == ID_FCT)
  {
	  affiche_balise_ouvrante(__FUNCTION__, 1); 
    char * tmp = yytext();
    consommer(ID_FCT,&uniteCourante,1);
    if (uniteCourante == PARENTHESE_OUVRANTE)
    {
      consommer(PARENTHESE_OUVRANTE,&uniteCourante,1);
      $3 = listeExpressions();
      if (uniteCourante == PARENTHESE_FERMANTE)
      {
        consommer(PARENTHESE_FERMANTE,&uniteCourante,1);
        $$ = cree_n_appel(tmp, $2);
        affiche_balise_fermante(__FUNCTION__, 1);
        return $$;
      } else {
        printf( "Erreur de syntaxe 56 : %d", uniteCourante );
        exit( -1 );
      }
    } else {
      printf( "Erreur de syntaxe 57 : %d", uniteCourante );
      exit( -1 );
    }
  } else {
      printf( "Erreur de syntaxe 58 : %d", uniteCourante );
      exit( -1 );
  }

  return $$;
}

// DONE
n_l_exp *listeExpressions(){
  n_l_exp *$$ = NULL;
  n_exp *$1 = NULL;
  n_l_exp *$2 = NULL;

  if(est_premier(uniteCourante,_expression_)||est_premier(EPSILON,_expression_)){
	  affiche_balise_ouvrante(__FUNCTION__, 1); 
    $1 = expression();
    $2 = listeExpressionsBis($$);
    $$ = cree_n_l_exp($1,$2);
    affiche_balise_fermante(__FUNCTION__, 1);
    return $$;
  } 

  else if (est_suivant(uniteCourante,_listeExpressions_)){
    affiche_balise_ouvrante(__FUNCTION__, 1);
    affiche_balise_fermante(__FUNCTION__, 1);
    return $$;
  }
  
  else {
    printf( "Erreur de syntaxe 59 : %d", uniteCourante );
    exit( -1 );
  }
    $$ = cree_n_l_exp($1,$2);
    affiche_balise_fermante(__FUNCTION__, 1);
    return $$;  
}

// DONE
n_l_exp *listeExpressionsBis (n_l_exp *herite) {
  n_exp *$2 =NULL;
  n_l_exp *herite_fils = NULL;
  n_l_exp *$$ = NULL;

  if (uniteCourante == VIRGULE)
  {
	  affiche_balise_ouvrante(__FUNCTION__, 1); 
    consommer(VIRGULE,&uniteCourante,1);
    $2 = expression();
    herite_fils = cree_n_l_exp($2, herite);
    affiche_balise_fermante(__FUNCTION__, 1);
    return listeExpressionsBis(herite_fils);
  } 

  else if (est_suivant(uniteCourante,_listeExpressionsBis_)){
    affiche_balise_ouvrante(__FUNCTION__, 1);
    affiche_balise_fermante(__FUNCTION__, 1);
    return herite;
  }
  
  else {
    printf( "Erreur de syntaxe 60 : %d", uniteCourante );
    exit( -1 );
  }

}


int main(int argc, char **argv) {  
  
  //char nom[100];
  //char valeur[100];  
  if(argc <3){
     yyin = fopen(argv[1], "r");
  }
  else if(argc == 3){
     yyin = fopen(argv[2], "r");
  }
 
  if(yyin == NULL){
    fprintf(stderr, "impossible d'ouvrir le fichier %s\n", argv[1]);
    exit(1);
  }
 
  if(argc<3){
    initialise_premiers();
    initialise_suivants();
    uniteCourante = yylex();  
    programme();
    return 0;
  }
  if (strcmp(argv[1],"-l")==0)
  {
      test_yylex_internal(yyin);
  } 

  if(strcmp(argv[1],"-s") ==0){
     initialise_premiers();
     initialise_suivants();
     uniteCourante = yylex();
 
      programme();
  }

 
  
  return 0;
}