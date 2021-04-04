#include <stdio.h>
#include <stdlib.h>
#include "textlib.h"
#include <ctype.h>

#ifdef _WIN32
#include <conio.h>
#endif

#ifdef linux
#include "coniolinux.h"
#endif

void clearArray(int intStringLength, int intArray[intStringLength]){
    for (int i = 0; i <intStringLength; ++i) {
        intArray[i] = 0;
    }
}

void clear_screen()
{
#if defined(linux) || defined(unix) || defined(APPLE)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
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
    int intKeycode = 0, intUnicode = 0;
    intKeycode = getche();
    intUnicode = 255 - 195 + intKeycode + 4;
    return intUnicode;
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
    int chrData[intStringLength];
    int chrUserInput = 0;
    int *chrUserData = chrData;

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
            //Letras portuguesas maisculas windows Latin-1 CP850
        else if ((chrUserInput == 128) || (chrUserInput == 144) || (chrUserInput > 180 && chrUserInput < 184) || (chrUserInput == 199) || (chrUserInput == 210) || (chrUserInput == 212) || (chrUserInput == 214) || (chrUserInput == 222) || (chrUserInput == 224) || (chrUserInput == 226) || (chrUserInput == 227) || (chrUserInput == 229) || (chrUserInput == 233) || (chrUserInput == 234) || (chrUserInput == 235)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
            //Tecla de Enter        10 - Linux             13 - Windows
        else if(chrUserInput == 10 || chrUserInput == 13){
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
    int chrData[intStringLength];
    int chrUserInput = 0;
    int *chrUserData = chrData;

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
            //Letras portuguesas minusculas windows Latin-1 CP850
        else if ((chrUserInput == 130) || (chrUserInput == 131) || (chrUserInput == 133) || (chrUserInput == 135) || (chrUserInput == 136) || (chrUserInput == 138) || (chrUserInput == 140) || (chrUserInput == 141) || (chrUserInput == 147) || (chrUserInput == 149) || (chrUserInput == 150) || (chrUserInput == 151) || (chrUserInput > 159 && chrUserInput < 164) || (chrUserInput == 198) || (chrUserInput == 228)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
            //Tecla de Enter        10 - Linux             13 - Windows
        else if(chrUserInput == 10 || chrUserInput == 13){
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
    int chrData[intStringLength];
    int chrUserInput = 0;
    int *chrUserData = chrData;

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
            //Letras portuguesas maisculas windows Latin-1 CP850
        else if ((chrUserInput == 128) || (chrUserInput == 144) || (chrUserInput > 180 && chrUserInput < 184) || (chrUserInput == 199) || (chrUserInput == 210) || (chrUserInput == 212) || (chrUserInput == 214) || (chrUserInput == 222) || (chrUserInput == 224) || (chrUserInput == 226) || (chrUserInput == 227) || (chrUserInput == 229) || (chrUserInput == 233) || (chrUserInput == 234) || (chrUserInput == 235)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
            //Tecla de Enter        10 - Linux             13 - Windows
        else if(chrUserInput == 10 || chrUserInput == 13){
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
    int chrData[intStringLength];
    int chrUserInput = 0;
    int *chrUserData = chrData;

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
            //Letras portuguesas minusculas windows Latin-1 CP850
        else if ((chrUserInput == 130) || (chrUserInput == 131) || (chrUserInput == 133) || (chrUserInput == 135) || (chrUserInput == 136) || (chrUserInput == 138) || (chrUserInput == 140) || (chrUserInput == 141) || (chrUserInput == 147) || (chrUserInput == 149) || (chrUserInput == 150) || (chrUserInput == 151) || (chrUserInput > 159 && chrUserInput < 164) || (chrUserInput == 198) || (chrUserInput == 228)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
            //Tecla de Enter        10 - Linux             13 - Windows
        else if(chrUserInput == 10 || chrUserInput == 13){
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
    int chrData[intStringLength];
    int chrUserInput = 0;
    int *chrUserData = chrData;

    clearArray(intStringLength,chrData);

    printf(MENU_DATA_ENTRY);

    do {
        chrUserInput = getche();
        //Numeros Inteiros
        if (chrUserInput > 47 && chrUserInput < 58) {
            chrUserData[intStringPosition] = chrUserInput;
            intStringPosition++;
        }
            //Tecla de Enter        10 - Linux             13 - Windows
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

    int chrData[intIntLength+intDecimalLength];
    int chrUserInput = 0;
    int *chrUserData = chrData;

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
            //Tecla de Enter        10 - Linux             13 - Windows
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

    int chrData[intStringLength];
    int chrUserInput = 0;
    int *chrUserData = chrData;

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
            //Letras portuguesas windows Latin-1 CP850
        else if ((chrUserInput == 130) || (chrUserInput == 131) || (chrUserInput == 133) || (chrUserInput == 135) || (chrUserInput == 136) || (chrUserInput == 138) || (chrUserInput == 140) || (chrUserInput == 141) || (chrUserInput == 147) || (chrUserInput == 149) || (chrUserInput == 150) || (chrUserInput == 151) || (chrUserInput > 159 && chrUserInput < 164) || (chrUserInput == 198) || (chrUserInput == 228) || (chrUserInput == 128) || (chrUserInput == 144) || (chrUserInput > 180 && chrUserInput < 184) || (chrUserInput == 199) || (chrUserInput == 210) || (chrUserInput == 212) || (chrUserInput == 214) || (chrUserInput == 222) || (chrUserInput == 224) || (chrUserInput == 226) || (chrUserInput == 227) || (chrUserInput == 229) || (chrUserInput == 233) || (chrUserInput == 234) || (chrUserInput == 235)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
            //Tecla de Enter        10 - Linux             13 - Windows
        else if(chrUserInput == 10 || chrUserInput == 13){
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

    int chrData[intStringLength];
    int chrUserInput = 0;
    int *chrUserData = chrData;

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
            //Letras portuguesas windows Latin-1 CP850
        else if ((chrUserInput == 130) || (chrUserInput == 131) || (chrUserInput == 133) || (chrUserInput == 135) || (chrUserInput == 136) || (chrUserInput == 138) || (chrUserInput == 140) || (chrUserInput == 141) || (chrUserInput == 147) || (chrUserInput == 149) || (chrUserInput == 150) || (chrUserInput == 151) || (chrUserInput > 159 && chrUserInput < 164) || (chrUserInput == 198) || (chrUserInput == 228) || (chrUserInput == 128) || (chrUserInput == 144) || (chrUserInput > 180 && chrUserInput < 184) || (chrUserInput == 199) || (chrUserInput == 210) || (chrUserInput == 212) || (chrUserInput == 214) || (chrUserInput == 222) || (chrUserInput == 224) || (chrUserInput == 226) || (chrUserInput == 227) || (chrUserInput == 229) || (chrUserInput == 233) || (chrUserInput == 234) || (chrUserInput == 235)) {
            chrUserData[intStringPosition] = chrUserInput;
            chrUserData[intStringPosition+1] = 0;
            intStringPosition++;
        }
            //Tecla de Enter        10 - Linux             13 - Windows
        else if(chrUserInput == 10 || chrUserInput == 13){
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