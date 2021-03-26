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
#include "coniolinux.h"

#define MENU_SEPARADOR "###############################################\n"
#define MENU_DATA_TYPE "#\t\t\t\tTipo de Dados                 #\n"
#define MENU_DATA_TYPE_STRING "#\t\t\t\t1.Caracteres                  #\n"
#define MENU_DATA_TYPE_NUM "#\t\t\t\t2.Numéricos                   #\n"
#define MENU_DATA_EXIT "#\t\t\t\t0.Sair do programa            #\n"
#define MENU_DATA_TYPE_OPTION "\nEscolha o tipo de dados: "
#define MENU_DATA_TYPE_STRING_LENGTH "\nIntroduza o comprimento da string(Ex:5;100): "
#define MENU_DATA_TYPE_TYPE1 "\n\n\t\t\t\t1.Letras Maiúsculas + espaço\n"
#define MENU_DATA_TYPE_TYPE2 "\t\t\t\t2.Letras minúsculas + espaço\n"
#define MENU_DATA_TYPE_TYPE3 "\t\t\t\t3.Letras Maiúsculas + espaço + caracteres especiais\n"
#define MENU_DATA_TYPE_TYPE4 "\t\t\t\t4.Letras minúsculas + espaço + caracteres especiais\n"
#define MENU_DATA_TYPE_TYPE5 "\t\t\t\t5.Números inteiros\n"
#define MENU_DATA_TYPE_TYPE6 "\t\t\t\t6.Números decimais\n"
#define MENU_DATA_TYPE_TYPE7 "\t\t\t\t7.Letras minúsculas + minúsculas + espaço + caracteres especiais\n"
#define MENU_DATA_TYPE_TYPE8 "\t\t\t\t8.Todos os caracteres\n"
#define MENU_EXIT_PROGRAM "\n\nA sair do programa..."


void printMenu(int intMenuID){
    if (intMenuID == 1){
        printf(MENU_SEPARADOR);
        printf(MENU_DATA_TYPE);
        printf(MENU_SEPARADOR);
        printf(MENU_DATA_TYPE_STRING);
        printf(MENU_DATA_TYPE_NUM);
        printf(MENU_DATA_EXIT);
        printf(MENU_SEPARADOR);
        printf(MENU_DATA_TYPE_OPTION);
    }else if (intMenuID == 2){
        printf(MENU_DATA_TYPE_TYPE1);
        printf(MENU_DATA_TYPE_TYPE2);
        printf(MENU_DATA_TYPE_TYPE3);
        printf(MENU_DATA_TYPE_TYPE4);
        printf(MENU_DATA_TYPE_TYPE5);
        printf(MENU_DATA_TYPE_TYPE6);
        printf(MENU_DATA_TYPE_TYPE7);
        printf(MENU_DATA_TYPE_TYPE8);
        printf(MENU_DATA_TYPE_OPTION);
    }
}

void entradaDados(int intTypeID, int intStringLength){
    char chrArray[intStringLength];
    char chrUserInput = 0;
    int intCounter = 0;

    for(intCounter = 0; intCounter < intStringLength; intCounter++){
        chrArray[intCounter] = '\0';
    }

    //Letras Maiúsculas + espaço
    for(intCounter = 0; intCounter < intStringLength; intCounter ++){
        if (intTypeID == 1){
            chrUserInput = getche();
            //Letras Maiúsculas + espaço
            if ((chrUserInput > 64 && chrUserInput < 91) || (chrUserInput == 32)) {
                chrArray[intCounter] = chrUserInput;
            }
            //Tecla de Enter
            else if(chrUserInput == 13){
                intCounter = intStringLength;
            }
            //Tecla de BackSpace
            else if(chrUserInput == 8){
                intCounter--;
                chrArray[intCounter] = chrUserInput;
                chrArray[intCounter+1] = '\0';
            }else{
                chrArray[intCounter] = 32;
            }
        }
    }

    //Letras minusculas + espaço
    for(intCounter = 0; intCounter < intStringLength; intCounter ++){
        if (intTypeID == 2){
            chrUserInput = getche();
            //Letras minusculas + espaço
            if ((chrUserInput > 96 && chrUserInput < 123) || (chrUserInput == 32)) {
                chrArray[intCounter] = chrUserInput;
            }
            //Tecla de Enter
            else if(chrUserInput == 13){
                intCounter = intStringLength;
            }
            //Tecla de BackSpace
            else if(chrUserInput == 8){
                intCounter--;
                chrArray[intCounter] = chrUserInput;
                chrArray[intCounter+1] = '\0';
            }else{
                chrArray[intCounter] = 32;
            }
        }
    }


    //Letras Maiúsculas + espaço +  caracteres especiais
    for(intCounter = 0; intCounter < intStringLength; intCounter ++) {
        if (intTypeID == 3) {
            chrUserInput = getche();
            //Letras Maiúsculas + espaço +  caracteres especiais
            if ((chrUserInput > 64 && chrUserInput < 91) || (chrUserInput == 32) ||(chrUserInput > 32 && chrUserInput < 48) || (chrUserInput > 57 && chrUserInput < 65) || (chrUserInput > 90 && chrUserInput < 97)) {
                chrArray[intCounter] = chrUserInput;
            }
            //Tecla de Enter
            else if (chrUserInput == 13) {
                intCounter = intStringLength;
            }
            //Tecla de BackSpace
            else if (chrUserInput == 8) {
                intCounter--;
                chrArray[intCounter] = chrUserInput;
                chrArray[intCounter + 1] = '\0';
            } else {
                chrArray[intCounter] = 32;
            }
        }
    }

    //Letras minúsculas + espaço +  caracteres especiais
    for(intCounter = 0; intCounter < intStringLength; intCounter ++) {
        if (intTypeID == 4) {
            chrUserInput = getche();
            //Letras Maiúsculas + espaço +  caracteres especiais
            if ((chrUserInput > 96 && chrUserInput < 123) || (chrUserInput == 32) ||(chrUserInput > 32 && chrUserInput < 48) || (chrUserInput > 57 && chrUserInput < 65) || (chrUserInput > 90 && chrUserInput < 97)) {
                chrArray[intCounter] = chrUserInput;
            }
            //Tecla de Enter
            else if (chrUserInput == 10) {
                intCounter = intStringLength;
            }
            //Tecla de BackSpace
            else if (chrUserInput == 8) {
                intCounter--;
                chrArray[intCounter] = chrUserInput;
                chrArray[intCounter + 1] = '\0';
            } else {
                chrArray[intCounter] = 32;
            }
        }
    }

    //Letras Maiúsculas + minúsculas + espaço +  números
    for(intCounter = 0; intCounter < intStringLength; intCounter ++) {
        if (intTypeID == 7) {
            chrUserInput = getche();
            //Letras Maiúsculas + espaço +  caracteres especiais
            if ((chrUserInput > 96 && chrUserInput < 123) || (chrUserInput == 32) ||(chrUserInput > 64 && chrUserInput < 91) || (chrUserInput > 47 && chrUserInput < 58)) {
                chrArray[intCounter] = chrUserInput;
            }
            //Tecla de Enter
            else if (chrUserInput == 13) {
                intCounter = intStringLength;
            }
            //Tecla de BackSpace
            else if (chrUserInput == 8) {
                intCounter--;
                chrArray[intCounter] = chrUserInput;
                chrArray[intCounter + 1] = '\0';
            } else {
                chrArray[intCounter] = 32;
            }
        }
    }

    printf("TESTE: %s", chrArray);

}


void main(){
//    int intMenuChoice = 0, intStringLength = 0, intExit = 0;
//    while (intExit != 1){
//        printMenu(1);
//        scanf("%d", &intMenuChoice);
//
//        if (intMenuChoice == 1 || intMenuChoice == 2){
//            if (intMenuChoice == 1){
//                printf(MENU_DATA_TYPE_STRING_LENGTH);
//                scanf("%d", &intStringLength);
//            }
//            intMenuChoice = 0;
//            printMenu(2);
//            scanf("%d", &intMenuChoice);
//            switch (intMenuChoice) {
//
//                case 1:
//                    break;
//                case 2:
//                    break;
//                case 3:
//                    break;
//                case 4:
//                    break;
//                case 5:
//                    break;
//                case 6:
//                    break;
//                case 7:
//                    break;
//                case 8:
//                    break;
//                default:
//                    printf(MENU_EXIT_PROGRAM);
//                    break;
//            }
//        }else if(intMenuChoice == 0){
//            printf(MENU_EXIT_PROGRAM);
//            intExit = 1;
//        }
//
//
//
//    }

    entradaDados(4, 10);

}