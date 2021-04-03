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
#include "entradadados.h"
#include "textlib.h"


void main(){
    int intMenuChoice = 0, intExit = 0;
    while (intExit != 1){
        printStartMenu();
        scanf("%d", &intMenuChoice);
        fflush(stdin);

        switch (intMenuChoice) {

            case 1:
                letrasMaiscEspaco();
                break;
            case 2:
                letrasMinuscEspaco();
                break;
            case 3:
                letrasMaiscEspacoEspeciais();
                break;
            case 4:
                letrasMinuscEspacoEspeciais();
                break;
            case 5:
                numerosInteiros();
                break;
            case 6:
                numerosDecimais();
                break;
            case 7:
                letrasMaiscMinuscNumEspaco();
                break;
            case 8:
                todosCaracteres();
                break;
            default:
                printf(MENU_EXIT_PROGRAM);
                intExit = 1;
                break;
        }


    }


}