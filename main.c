/*
Ismat - Engenheria Informática 1º Ano
Programação Imperatica - Prof. Francisco Pereira
Leandro Fonseca
10/03/2020 - 17:47
Resumo: Desafio 2
Inputs:
Outputs:
 */

#include <stdio.h>

#define MENU_SEPARADOR "###############################################\n"
#define MENU_DATA_TYPE "#                Tipo de Dados                #\n"
#define MENU_DATA_TYPE_STRING "#\t\t\t\t1.Caracteres                  #\n"
#define MENU_DATA_TYPE_NUM "#\t\t\t\t2.Numéricos                   #\n"

void main(){
    printf(MENU_SEPARADOR);
    printf(MENU_DATA_TYPE);
    printf(MENU_SEPARADOR);
    printf(MENU_DATA_TYPE_STRING);
    printf(MENU_DATA_TYPE_NUM);
}