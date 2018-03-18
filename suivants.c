#include "suivants.h"

void initialise_suivants(void){
  int i,j;

  // Initialiser toutes les cases du tableau à 0
  for(i=0; i <= NB_NON_TERMINAUX; i++)
    for(j=0; j <= NB_TERMINAUX; j++)
      suivants[i][j] = 0;

  suivants[_programme_][FIN]=1;

  suivants[_optDecVariables_][ID_FCT]=1;
  suivants[_optDecVariables_][FIN]=1;
  suivants[_optDecVariables_][ACCOLADE_OUVRANTE]=1;

  suivants[_listeDecVariables_][POINT_VIRGULE]=1;
  suivants[_listeDecVariables_][PARENTHESE_FERMANTE]=1;

  suivants[_listeDecVariablesBis_][POINT_VIRGULE]=1;
  suivants[_listeDecVariablesBis_][PARENTHESE_FERMANTE]=1;

  suivants[_optTailleTableau_][VIRGULE]=1;
  suivants[_optTailleTableau_][POINT_VIRGULE]=1;
  suivants[_optTailleTableau_][PARENTHESE_FERMANTE]=1;

  suivants[_listeDecFonctions_][FIN]=1;

  suivants[_optListeDecVariables_][PARENTHESE_FERMANTE]=1;

  suivants[_instruction_][ID_VAR]=1;
  suivants[_instruction_][ACCOLADE_OUVRANTE]=1;
  suivants[_instruction_][SI]=1;
  suivants[_instruction_][TANTQUE]=1;
  suivants[_instruction_][ID_FCT]=1;
  suivants[_instruction_][RETOUR]=1;
  suivants[_instruction_][ECRIRE]=1;
  suivants[_instruction_][POINT_VIRGULE]=1;

  suivants[_listeInstructions_][ACCOLADE_FERMANTE]=1;

  suivants[_optSinon_][ID_VAR]=1;
  suivants[_optSinon_][ACCOLADE_OUVRANTE]=1;
  suivants[_optSinon_][ACCOLADE_FERMANTE]=1;
  suivants[_optSinon_][SI]=1;
  suivants[_optSinon_][TANTQUE]=1;
  suivants[_optSinon_][ID_FCT]=1;
  suivants[_optSinon_][RETOUR]=1;
  suivants[_optSinon_][ECRIRE]=1;
  suivants[_optSinon_][POINT_VIRGULE]=1;

  suivants[_expressionBis_][POINT_VIRGULE]=1;
  suivants[_expressionBis_][ALORS]=1;
  suivants[_expressionBis_][FAIRE]=1;
  suivants[_expressionBis_][PARENTHESE_FERMANTE]=1;
  suivants[_expressionBis_][CROCHET_FERMANT]=1;
  suivants[_expressionBis_][VIRGULE]=1;
  suivants[_expressionBis_][DEUXPOINTS]=1; 




  suivants[_conjonctionBis_][OU]=1;
  suivants[_conjonctionBis_][POINT_VIRGULE]=1;
  suivants[_conjonctionBis_][ALORS]=1;
  suivants[_conjonctionBis_][FAIRE]=1;
  suivants[_conjonctionBis_][PARENTHESE_FERMANTE]=1;
  suivants[_conjonctionBis_][CROCHET_FERMANT]=1;
  suivants[_conjonctionBis_][VIRGULE]=1;
  suivants[_conjonctionBis_][INTERROGATION]=1; 
  suivants[_conjonctionBis_][DEUXPOINTS]=1; 

  suivants[_comparaisonBis_][OU]=1;
  suivants[_comparaisonBis_][POINT_VIRGULE]=1;
  suivants[_comparaisonBis_][ALORS]=1;
  suivants[_comparaisonBis_][FAIRE]=1;
  suivants[_comparaisonBis_][PARENTHESE_FERMANTE]=1;
  suivants[_comparaisonBis_][CROCHET_FERMANT]=1;
  suivants[_comparaisonBis_][VIRGULE]=1;
  suivants[_comparaisonBis_][ET]=1;
  suivants[_comparaisonBis_][INTERROGATION]=1;
  suivants[_comparaisonBis_][DEUXPOINTS]=1;

  suivants[_expArithBis_][EGAL]=1;
  suivants[_expArithBis_][INFERIEUR]=1;
  suivants[_expArithBis_][OU]=1;
  suivants[_expArithBis_][ET]=1;
  suivants[_expArithBis_][POINT_VIRGULE]=1;
  suivants[_expArithBis_][ALORS]=1;
  suivants[_expArithBis_][FAIRE]=1;
  suivants[_expArithBis_][PARENTHESE_FERMANTE]=1;
  suivants[_expArithBis_][CROCHET_FERMANT]=1;
  suivants[_expArithBis_][VIRGULE]=1;
  suivants[_expArithBis_][INTERROGATION]=1;
  suivants[_expArithBis_][DEUXPOINTS]=1;


  suivants[_termeBis_][ET] = 1;
  suivants[_termeBis_][OU] = 1;
  suivants[_termeBis_][POINT_VIRGULE] = 1;
  suivants[_termeBis_][ALORS] = 1;
  suivants[_termeBis_][FAIRE] = 1;
  suivants[_termeBis_][PARENTHESE_FERMANTE] = 1;
  suivants[_termeBis_][CROCHET_FERMANT] = 1;
  suivants[_termeBis_][VIRGULE] = 1;
  suivants[_termeBis_][ET] = 1;
  suivants[_termeBis_][EGAL] = 1;
  suivants[_termeBis_][INFERIEUR] = 1;
  suivants[_termeBis_][PLUS] = 1;
  suivants[_termeBis_][MOINS] = 1;
  suivants[_termeBis_][INFERIEUR] = 1;
  suivants[_termeBis_][INTERROGATION] = 1;
  suivants[_termeBis_][DEUXPOINTS] = 1;


  suivants[_optIndice_][ET] = 1;
  suivants[_optIndice_][OU] = 1;
  suivants[_optIndice_][POINT_VIRGULE] = 1;
  suivants[_optIndice_][ALORS] = 1;
  suivants[_optIndice_][FAIRE] = 1;
  suivants[_optIndice_][PARENTHESE_FERMANTE] = 1;
  suivants[_optIndice_][CROCHET_FERMANT] = 1;
  suivants[_optIndice_][VIRGULE] = 1;
  suivants[_optIndice_][ET] = 1;
  suivants[_optIndice_][EGAL] = 1;
  suivants[_optIndice_][INFERIEUR] = 1;
  suivants[_optIndice_][PLUS] = 1;
  suivants[_optIndice_][MOINS] = 1;
  suivants[_optIndice_][FOIS] = 1;
  suivants[_optIndice_][DIVISE] = 1;
  suivants[_optIndice_][INTERROGATION] = 1; 


  suivants[_listeExpressions_][PARENTHESE_FERMANTE]=1;

  suivants[_listeExpressionsBis_][PARENTHESE_FERMANTE]=1;

}

int est_suivant(int terminal, int non_terminal)
{
  return suivants[non_terminal][terminal];
}
