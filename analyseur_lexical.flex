/*
 * Analyseur lexical du compilateur L en FLEX
 */
 
%{
#include "symboles.h"
%}
%option yylineno
%option nounput
%option noinput

/* Déclarations à compléter ... */
var [a-zA-Z0-9_$]*
fct [a-zA-Z_]
%%
<<EOF>> 		{ return FIN;                 }  /* Fin de fichier */
";" 			return POINT_VIRGULE;
"," 			return VIRGULE;
"+" 			return PLUS;
"-" 			return MOINS;
"*" 			return FOIS;
"/"				return DIVISE;
"("				return PARENTHESE_OUVRANTE;
")"				return PARENTHESE_FERMANTE;
"["				return CROCHET_OUVRANT;
"]"				return CROCHET_FERMANT;
"{"				return ACCOLADE_OUVRANTE;
"}"				return ACCOLADE_FERMANTE;
"="				return EGAL;
"<"				return INFERIEUR;
"&"				return ET;
"|"				return OU;
"!"				return NON;
[0-9]+			return NOMBRE;
"si" 				return SI;
"alors" 			return ALORS;
"sinon" 			return SINON;
"tantque" 		return TANTQUE;
"faire" 			return FAIRE;
"entier"  		return ENTIER;
"retour"  		return RETOUR;
"lire"    		return LIRE;
"ecrire"  		return ECRIRE;
":"			return DEUXPOINTS;
"?"			return INTERROGATION;
"\n"			;
[ \t]			;

"#".*	;
"$"			return ID_VAR;
"$"{var} 		return ID_VAR;
{fct}{var} 		return ID_FCT;
%%
int yywrap(){
  return 1;
}

