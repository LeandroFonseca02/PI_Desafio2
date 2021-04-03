#include <stdio.h>
#include <stdlib.h>
#include "textlib.h"

#ifdef _WIN32
#include <conio.h>
#endif

#ifdef linux
#include "coniolinux.h"
#endif


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
}

void letrasMaiscEspaco(){
    //Letras Maiúsculas + espaço

    int intStringPosition = 0, intStringLength = 0;

    printf(MENU_DATA_TYPE_STRING_LENGTH);
    fflush(stdin);
    scanf("%d", &intStringLength);

    char chrData[intStringLength];
    char chrUserInput = '\0';
    char *chrUserData = chrData;

    printf(MENU_DATA_ENTRY);

    do {
        chrUserInput = (char) getche();
        //Letras Maiúsculas + espaço
        if ((chrUserInput > 64 && chrUserInput < 91) || (chrUserInput == 32)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = '\0';
            intStringPosition++;
        }
            //Tecla de Enter
        else if(chrUserInput == 13){
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
        printf(MENU_DATA_RESULT, chrUserData);
}

void letrasMinuscEspaco(){
    //Letras minusculas + espaço
    int intStringPosition = 0, intStringLength = 0;

    printf(MENU_DATA_TYPE_STRING_LENGTH);
    fflush(stdin);
    scanf("%d", &intStringLength);

    char chrData[intStringLength];
    char chrUserInput = '\0';
    char *chrUserData = chrData;

    printf(MENU_DATA_ENTRY);

    do {
        chrUserInput = (char) getche();

        //Letras minusculas + espaço
        if ((chrUserInput > 96 && chrUserInput < 123) || (chrUserInput == 32)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = '\0';
            intStringPosition++;
        }
            //Tecla de Enter
        else if(chrUserInput == 13){
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
    printf(MENU_DATA_RESULT, chrUserData);
}

void letrasMaiscEspacoEspeciais(){
    //Letras Maiúsculas + espaço +  caracteres especiais
    int intStringPosition = 0, intStringLength = 0;

    printf(MENU_DATA_TYPE_STRING_LENGTH);
    fflush(stdin);
    scanf("%d", &intStringLength);

    char chrData[intStringLength];
    char chrUserInput = '\0';
    char *chrUserData = chrData;

    printf(MENU_DATA_ENTRY);

    do {
        chrUserInput = (char) getche();
        //Letras Maiúsculas + espaço +  caracteres especiais
        if ((chrUserInput > 64 && chrUserInput < 91) || (chrUserInput == 32) ||(chrUserInput > 32 && chrUserInput < 48) || (chrUserInput > 57 && chrUserInput < 65) || (chrUserInput > 90 && chrUserInput < 97)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = '\0';
            intStringPosition++;
        }
            //Tecla de Enter
        else if(chrUserInput == 13){
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
    printf(MENU_DATA_RESULT, chrUserData);
}

void letrasMinuscEspacoEspeciais(){
    //Letras minúsculas + espaço +  caracteres especiais
    int intStringPosition = 0, intStringLength = 0;

    printf(MENU_DATA_TYPE_STRING_LENGTH);
    fflush(stdin);
    scanf("%d", &intStringLength);

    char chrData[intStringLength];
    char chrUserInput = '\0';
    char *chrUserData = chrData;

    printf(MENU_DATA_ENTRY);

    do {
        chrUserInput = (char) getche();
        //Letras Maiúsculas + espaço +  caracteres especiais
        if ((chrUserInput > 96 && chrUserInput < 123) || (chrUserInput == 32) ||(chrUserInput > 32 && chrUserInput < 48) || (chrUserInput > 57 && chrUserInput < 65) || (chrUserInput > 90 && chrUserInput < 97)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = '\0';
            intStringPosition++;
        }
            //Tecla de Enter
        else if(chrUserInput == 13){
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
    printf(MENU_DATA_RESULT, chrUserData);
}

void numerosInteiros(){
    //Numeros Inteiros
    int intStringPosition = 0, intStringLength = 20;
    char chrData[intStringLength];
    char chrUserInput = '\0';
    char *chrUserData = chrData;

    printf(MENU_DATA_ENTRY);

    do {
        chrUserInput = (char) getche();
        //Numeros Inteiros
        if (chrUserInput > 47 && chrUserInput < 58) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = '\0';
            intStringPosition++;
        }
            //Tecla de Enter
        else if(chrUserInput == 13){
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
    printf(MENU_DATA_RESULT, chrUserData);
}

void numerosDecimais(){
    //Numeros Decimais
    int intStringPosition = 0, intDecimalLength = 0, intIntLength = 20, intDecimalFlag =0;

    printf(MENU_DATA_TYPE_DECIMAL_LENGTH);
    fflush(stdin);
    scanf("%d", &intDecimalLength);

    char chrData[intIntLength+intDecimalLength];
    char chrUserInput = '\0';
    char *chrUserData = chrData;

    printf(MENU_DATA_ENTRY);

    do {
        chrUserInput = (char) getche();
        //Numeros Inteiros
        if (chrUserInput > 47 && chrUserInput < 58) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = '\0';
            intStringPosition++;
        }
            //Tecla de Enter
        else if (chrUserInput == 10) {
            intStringPosition = intDecimalLength+intIntLength+1;
        }
            //Tecla de BackSpace
        else if (chrUserInput == 8) {
            intStringPosition--;
            chrUserData[intStringPosition] = '\0';
        }
            //Ponto Decimal
        else if (chrUserInput == 46){
            if(intDecimalFlag == 0){
                chrUserData[intStringPosition] = chrUserInput;
                intDecimalFlag = 1;
            } else{
                intStringPosition--;
                chrUserData[intStringPosition] = '\0';
            }

        } else {
            intStringPosition--;
            chrUserData[intStringPosition] = '\0';
        }
    } while (intStringPosition < intIntLength+intDecimalLength);
    printf(MENU_DATA_RESULT, chrUserData);
}

void letrasMaiscMinuscNumEspaco(){
    //Letras maiúsculas, minúsculas, números e espaço
    int intStringPosition = 0, intStringLength = 0;

    printf(MENU_DATA_TYPE_STRING_LENGTH);
    fflush(stdin);
    scanf("%d", &intStringLength);
    char chrData[intStringLength];
    char chrUserInput = '\0';
    char *chrUserData = chrData;

    printf(MENU_DATA_ENTRY);

    do {
        chrUserInput = (char) getche();
        //Letras maiúsculas, minúsculas, números e espaço
        if ((chrUserInput > 64 && chrUserInput < 91) || (chrUserInput > 96 && chrUserInput < 123) || (chrUserInput > 47 && chrUserInput < 58) || (chrUserInput == 32)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = '\0';
            intStringPosition++;
        }
            //Tecla de Enter
        else if(chrUserInput == 13){
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
    printf(MENU_DATA_RESULT, chrUserData);
}

void todosCaracteres(){

}