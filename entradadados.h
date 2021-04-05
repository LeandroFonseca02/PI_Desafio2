#include <stdio.h>
#include <stdlib.h>
#include "textlib.h"
#include <ctype.h>
#include "coniolinux.h"


void clearArray(int intStringLength, unsigned char chrArray[intStringLength]){
    for (int i = 0; i <intStringLength; ++i) {
        chrArray[i] = 0;
    }
}

void clsKeyboardBuffer(void){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF){
        return;
    }
}

int checkContinue()
{
    char chrCheckContinue = '\0';
    int intExit = 1;
    printf(MENU_RETURN_OPTION);
    scanf(" %c", &chrCheckContinue);

    if(tolower(chrCheckContinue) == 115){
        intExit = 0;
    }
    else if (tolower(chrCheckContinue) == 110){
        intExit = 01;
    }else {
        printf(MENU_EXIT_PROGRAM);
    }
    return intExit;
}

int linuxPTchar(){
    //Caracteres Portugueses Linux
    //Linux - Se utilizar unsigned char e subtrair ao ultimo numero da tabela extendida ascii (255)
    //o 195 que é a keycode das teclas especiais no layout portugues, e somar
    //o segundo keycode do caracter e somar 4 obtem-se o codigo ascii da extended table utf-8
    //printf("%lc %d\n", 255-195+((int)chr)+4,255-195+((int)chr)+4);
    int intKeycode = 0, intUTF8 = 0;
    intKeycode = getche();
    intUTF8 = 255 - 195 + intKeycode + 4;
    return intUTF8;
}

void printStartMenu() {
    printf(MENU_SEPARADOR);
    printf(MENU_DATA_TYPE);
    printf(MENU_SEPARADOR);
    printf(MENU_DATA_TYPE_STRING_TYPE1);
    printf(MENU_DATA_TYPE_STRING_TYPE2);
    printf(MENU_DATA_TYPE_STRING_TYPE3);
    printf(MENU_DATA_TYPE_STRING_TYPE4);
    printf(MENU_DATA_TYPE_NUM_TYPE1);
    printf(MENU_DATA_TYPE_NUM_TYPE2);
    printf(MENU_DATA_TYPE_STRING_TYPE5);
    printf(MENU_DATA_TYPE_STRING_TYPE6);
    printf(MENU_DATA_EXIT);
    printf(MENU_SEPARADOR);
    printf(MENU_DATA_TYPE_OPTION);
    fflush(stdin);
}

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

void letrasMinuscEspaco(){
    //Letras minusculas + espaço

    printf(MENU_SELECTED_OPTION_2);

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

        //Letras minusculas + espaço
        if ((chrUserInput > 96 && chrUserInput < 123) || (chrUserInput == 32)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
            //Letras portuguesas minusculas linux
        else if(chrUserInput == 195){
            chrUserInput = linuxPTchar();
            if(chrUserInput > 223 && chrUserInput < 255){
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
            intStringPosition--;
            chrUserData[intStringPosition] = 0;
        }else{
            chrUserData[intStringPosition] = 0;
        }
    } while (intStringPosition < intStringLength);
    printf(MENU_DATA_RESULT);
    for (intStringPosition = 0; intStringPosition < intStringLength; intStringPosition++){
        printf("%lc",chrUserData[intStringPosition]);
    }
}

void letrasMaiscEspacoEspeciais(){
    //Letras Maiúsculas + espaço +  caracteres especiais

    printf(MENU_SELECTED_OPTION_3);

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
        //Letras Maiúsculas + espaço +  caracteres especiais
        if ((chrUserInput > 64 && chrUserInput < 91) || (chrUserInput == 32) ||(chrUserInput > 32 && chrUserInput < 48) || (chrUserInput > 57 && chrUserInput < 65) || (chrUserInput > 90 && chrUserInput < 97)) {
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
            intStringPosition--;
            chrUserData[intStringPosition] = 0;
        }else{
            chrUserData[intStringPosition] = 0;
        }
    } while (intStringPosition < intStringLength);
    printf(MENU_DATA_RESULT);
    for (intStringPosition = 0; intStringPosition < intStringLength; intStringPosition++){
        printf("%lc",chrUserData[intStringPosition]);
    }
}

void letrasMinuscEspacoEspeciais(){
    //Letras minúsculas + espaço +  caracteres especiais

    printf(MENU_SELECTED_OPTION_4);

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
        //Letras Minúsculas + espaço +  caracteres especiais
        if ((chrUserInput > 96 && chrUserInput < 123) || (chrUserInput == 32) ||(chrUserInput > 32 && chrUserInput < 48) || (chrUserInput > 57 && chrUserInput < 65) || (chrUserInput > 90 && chrUserInput < 97)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
        //Letras portuguesas minusculas linux
        else if(chrUserInput == 195){
            chrUserInput = linuxPTchar();
            if(chrUserInput > 223 && chrUserInput < 255){
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
            intStringPosition--;
            chrUserData[intStringPosition] = 0;
        }else{
            chrUserData[intStringPosition] = 0;
        }
    } while (intStringPosition < intStringLength);
    printf(MENU_DATA_RESULT);
    for (intStringPosition = 0; intStringPosition < intStringLength; intStringPosition++){
        printf("%lc",chrUserData[intStringPosition]);
    }
}

void numerosInteiros(){
    //Numeros Inteiros

    printf(MENU_SELECTED_OPTION_5);

    int intStringPosition = 0, intStringLength = 20;
    unsigned char chrData[intStringLength];
    unsigned char chrUserInput = 0;
    unsigned char *chrUserData = chrData;

    clearArray(intStringLength,chrData);

    printf(MENU_DATA_ENTRY);

    do {
        chrUserInput = getche();
        //Numeros Inteiros
        if (chrUserInput > 47 && chrUserInput < 58) {
            chrUserData[intStringPosition] = chrUserInput;
            intStringPosition++;
        }
            //Tecla de Enter
        else if(chrUserInput == 10 || chrUserInput == 13){
            intStringPosition = intStringLength+1;
        }
            //Tecla de BackSpace
        else if(chrUserInput == 8){
            intStringPosition--;
            chrUserData[intStringPosition] = '\0';
        }else{
            chrUserData[intStringPosition] = '\0';
        }
    } while (intStringPosition < intStringLength);
    printf(MENU_DATA_RESULT);
    for (intStringPosition = 0; intStringPosition < intStringLength; intStringPosition++){
        printf("%lc",chrUserData[intStringPosition]);
    }
}

void numerosDecimais(){
    //Numeros Decimais

    printf(MENU_SELECTED_OPTION_6);

    int intStringPosition = 0, intDecimalLength = 0, intIntLength = 20, intDecimalFlag =0;

    printf(MENU_DATA_TYPE_DECIMAL_LENGTH);
    fflush(stdin);
    scanf("%d", &intDecimalLength);

    clsKeyboardBuffer();

    unsigned char chrData[intIntLength+intDecimalLength];
    unsigned char chrUserInput = 0;
    unsigned char *chrUserData = chrData;

    clearArray(intDecimalLength+intIntLength, chrData);

    printf(MENU_DATA_ENTRY);

    do {
        chrUserInput = getche();
        //Numeros Inteiros
        if (chrUserInput > 47 && chrUserInput < 58) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
            //Tecla de Enter
        else if(chrUserInput == 10 || chrUserInput == 13){
            intStringPosition = intDecimalLength+intIntLength+1;
        }
            //Tecla de BackSpace
        else if (chrUserInput == 8) {
            intStringPosition--;
            chrUserData[intStringPosition] = 0;
        }
            //Ponto Decimal
        else if (chrUserInput == 46){
            if(intDecimalFlag == 0){
                chrUserData[intStringPosition] = chrUserInput;
                intStringPosition++;
                intDecimalFlag = 1;
            } else{
                chrUserData[intStringPosition] = 0;
            }

        } else {
            chrUserData[intStringPosition] = 0;
        }
    } while (intStringPosition < intIntLength+intDecimalLength);
    printf(MENU_DATA_RESULT);
    for (intStringPosition = 0; intStringPosition < intIntLength+intDecimalLength; intStringPosition++){
        printf("%lc",chrUserData[intStringPosition]);
    }
}

void letrasMaiscMinuscNumEspaco(){
    //Letras maiúsculas, minúsculas, números e espaço

    printf(MENU_SELECTED_OPTION_7);

    int intStringPosition = 0, intStringLength = 0;

    printf(MENU_DATA_TYPE_STRING_LENGTH);
    fflush(stdin);
    scanf("%d", &intStringLength);
    clsKeyboardBuffer();

    unsigned char chrData[intStringLength];
    unsigned char chrUserInput = 0;
    unsigned char *chrUserData = chrData;

    printf(MENU_DATA_ENTRY);

    clearArray(intStringLength,chrData);

    do {
        chrUserInput = getche();
        //Letras maiúsculas, minúsculas, números e espaço
        if ((chrUserInput > 64 && chrUserInput < 91) || (chrUserInput > 96 && chrUserInput < 123) || (chrUserInput > 47 && chrUserInput < 58) || (chrUserInput == 32)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
            //Letras portuguesas linux
        else if(chrUserInput == 195){
            chrUserInput = linuxPTchar();
            if(chrUserInput > 191 && chrUserInput < 255){
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
            intStringPosition--;
            chrUserData[intStringPosition] = 0;
        }else{
            chrUserData[intStringPosition] = 0;
        }
    } while (intStringPosition < intStringLength);
    printf(MENU_DATA_RESULT);
    for (intStringPosition = 0; intStringPosition < intStringLength; intStringPosition++){
        printf("%lc",chrUserData[intStringPosition]);
    }
}

void todosCaracteres(){
    //Todos caracteres

    printf(MENU_SELECTED_OPTION_8);

    int intStringPosition = 0, intStringLength = 0;

    printf(MENU_DATA_TYPE_STRING_LENGTH);
    fflush(stdin);
    scanf("%d", &intStringLength);
    clsKeyboardBuffer();

    unsigned char chrData[intStringLength];
    unsigned char chrUserInput = 0;
    unsigned char *chrUserData = chrData;

    printf(MENU_DATA_ENTRY);

    clearArray(intStringLength,chrData);

    do {
        chrUserInput = getche();
        //Letras maiúsculas, minúsculas, números e espaço
        if ((chrUserInput > 64 && chrUserInput < 91) || (chrUserInput > 96 && chrUserInput < 123) || (chrUserInput > 47 && chrUserInput < 58) || (chrUserInput == 32) || (chrUserInput > 32 && chrUserInput < 48) || (chrUserInput > 57 && chrUserInput < 65) || (chrUserInput > 90 && chrUserInput < 97)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
            //Letras portuguesas linux
        else if(chrUserInput == 195){
            chrUserInput = linuxPTchar();
            if(chrUserInput > 191 && chrUserInput < 255){
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
            intStringPosition--;
            chrUserData[intStringPosition] = 0;
        }else{
            chrUserData[intStringPosition] = 0;
        }
    } while (intStringPosition < intStringLength);
    printf(MENU_DATA_RESULT);
    for (intStringPosition = 0; intStringPosition < intStringLength; intStringPosition++){
        printf("%lc",chrUserData[intStringPosition]);
    }
}