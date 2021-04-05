/*
Ismat - Engenheria Informática 1º Ano
Programação Imperatica - Prof. Francisco Pereira
Leandro Fonseca
05/04/2021 - 00:20
Resumo: Desafio 2
Aviso: Este programa foi desenvolvido utilizando ANSI C para a plataforma Linux Ubuntu 64bit
 */

#include <stdio.h>
#include "entradadados.h"
#include "textlib.h"
#include <locale.h>



int main(){
    setlocale(LC_ALL, "en_US.UTF-8");  // importa as variáveis de ambiente
    setlocale (LC_CTYPE, "en_US.UTF-8");    //Forçar para en_US.UTF-8
    int intMenuChoice = 0, intExit = 0, intValidationChoice = 0;
    printf(MENU_REGEX_GETCHE);
    scanf("%d", &intValidationChoice);
    clsKeyboardBuffer();

    while (intExit != 1){
        system("clear");
        printStartMenu();
        scanf("%d", &intMenuChoice);
        clsKeyboardBuffer();
        switch (intMenuChoice) {

            case 1:
                intValidationChoice == 1 ? letrasMaiscEspaco() : regexInput("^.*(([A-Z])).*$");
                intExit = checkExit();
                break;
            case 2:
                intValidationChoice == 1 ? letrasMinuscEspaco() : regexInput("^.*(([a-z])).*$");
                intExit = checkExit();
                break;
            case 3:
                intValidationChoice == 1 ? letrasMaiscEspacoEspeciais() : regexInput("^.*(([A-Z])).*$");
                intExit = checkExit();
                break;
            case 4:
                intValidationChoice == 1 ? letrasMinuscEspacoEspeciais() : regexInput("^.*(([a-z])).*$");
                intExit = checkExit();
                break;
            case 5:
                intValidationChoice == 1 ? numerosInteiros() : regexInput("^.*(([0-9])).*");
                intExit = checkExit();
                break;
            case 6:
                intValidationChoice == 1 ? numerosDecimais() : regexInput("^.*[0-9]+.*");
                intExit = checkExit();
                break;
            case 7:
                intValidationChoice == 1 ? letrasMaiscMinuscNumEspaco() : regexInput("^.*(([a-zA-Z0-9])).*$");
                intExit = checkExit();
                break;
            case 8:
                intValidationChoice == 1 ? todosCaracteres() : regexInput("^.*(([a-zA-Z0-9])).*$");
                intExit = checkExit();
                break;
            default:
                printf(MENU_EXIT_PROGRAM);
                intExit = 1;
                break;
        }


    }

    return 0;
}