/*
Ismat - Engenheria Informática 1º Ano
Programação Imperatica - Prof. Francisco Pereira
Leandro Fonseca
05/04/2021 - 00:20
Resumo: Desafio 2
Inputs:
Outputs:
 */

#include <stdio.h>
#include "entradadados.h"
#include "textlib.h"
#include <locale.h>



int main(){
    setlocale(LC_ALL, "");  // importa as variáveis de ambiente
    setlocale (LC_CTYPE, "en_US.UTF-8");    //Forçar para en_US.UTF-8
    int intMenuChoice = 0, intExit = 0;
    while (intExit != 1){
        printStartMenu();
        scanf("%d", &intMenuChoice);
        clsKeyboardBuffer();
        switch (intMenuChoice) {

            case 1:
                letrasMaiscEspaco();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 2:
                letrasMinuscEspaco();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 3:
                letrasMaiscEspacoEspeciais();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 4:
                letrasMinuscEspacoEspeciais();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 5:
                numerosInteiros();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 6:
                numerosDecimais();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 7:
                letrasMaiscMinuscNumEspaco();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 8:
                todosCaracteres();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            default:
                printf(MENU_EXIT_PROGRAM);
                intExit = 1;
                break;
        }


    }

    return 0;
}