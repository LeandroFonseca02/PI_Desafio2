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



void main(){
    setlocale(LC_ALL, "Portuguese");
    int intMenuChoice = 0, intExit = 0;
    while (intExit != 1){
        clear_screen();
        printStartMenu();
        scanf("%d", &intMenuChoice);
        clsKeyboardBuffer();
        switch (intMenuChoice) {

            case 1:
                clear_screen();
                letrasMaiscEspaco();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 2:
                clear_screen();
                letrasMinuscEspaco();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 3:
                clear_screen();
                letrasMaiscEspacoEspeciais();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 4:
                clear_screen();
                letrasMinuscEspacoEspeciais();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 5:
                clear_screen();
                numerosInteiros();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 6:
                clear_screen();
                numerosDecimais();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 7:
                clear_screen();
                letrasMaiscMinuscNumEspaco();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            case 8:
                clear_screen();
                todosCaracteres();
                clsKeyboardBuffer();
                intExit = checkContinue();
                break;
            default:
                clear_screen();
                printf(MENU_EXIT_PROGRAM);
                intExit = 1;
                break;
        }


    }


}