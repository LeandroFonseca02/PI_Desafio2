/*
Ismat - Engenheria Informática 1º Ano
Programação Imperatica - Prof. Francisco Pereira
Leandro Fonseca
Resumo: Desafio 2

 */
#include <stdio.h>
#include "textlib.h"
#include "entradadados.h"
#include "coniolinux.h"

//Prótotipos das funções
void letrasMaiscEspaco();

void letrasMaiscEspaco(){
    //Letras Maiúsculas + espaço

    printf(MENU_SELECTED_OPTION_1);

    int intStringPosition = 0, intStringLength = 0;

    printf(MENU_DATA_TYPE_STRING_LENGTH);

    scanf("%d", &intStringLength);
    clsKeyboardBuffer();
    unsigned char chrData[intStringLength];
    unsigned char chrUserInput = 0;
    unsigned char *chrUserData = chrData;

    clearArray(intStringLength,chrData);

    printf(MENU_DATA_ENTRY);

    do {
        chrUserInput = getche();
        //Letras Maiúsculas + espaço
        if ((chrUserInput > 64 && chrUserInput < 91) || (chrUserInput == 32)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
            //Letras portuguesas maisculas linux
        else if(chrUserInput == 195){
            chrUserInput = linuxPTchar();
            if(chrUserInput > 191 && chrUserInput < 222){
                chrUserData[intStringPosition] = chrUserInput;
                chrUserData[intStringPosition+1] = 0;
                intStringPosition++;
            }else{
                chrUserData[intStringPosition] = 0;
            }

        }
            //Tecla de Enter
        else if(chrUserInput == 10){
            intStringPosition = intStringLength+1;
        }
            //Tecla de BackSpace
        else if(chrUserInput == 8){
            chrUserData[intStringPosition] = 0;
            intStringPosition--;
        }else{
            chrUserData[intStringPosition] = 0;
        }
    } while (intStringPosition < intStringLength);
    printf(MENU_DATA_RESULT);
    for (intStringPosition = 0; intStringPosition < intStringLength; intStringPosition++){
        printf("%lc",chrUserData[intStringPosition]);
    }
}