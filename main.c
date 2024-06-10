#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> //Добавено за да мога да използвам командата strcmp




int main()
{



    char voice[100000];
    char phrase[100000];
    char etc[100000];
    char stop[1000];
    char charCommand[100000];
    char save[1000];
    char savename[1000];
    int isValid = 0;
    int i;
    const char *codenames[] = {         //създадено за да мога да направя проверка дали потребителя е въвел правилния код
    "af", "bg", "ca", "cs", "da", "de", "el", "en", "en-gb", "en-sc",
    "en-us", "es", "es-la", "et", "eu", "fa", "fi", "fr-be", "fr-fr",
    "ga", "gd", "grc", "gu", "hi", "hr", "hu", "hy", "id", "is", "it",
    "jbo", "ka", "kl", "kn", "ko", "ku", "la", "lfn", "lt", "lv", "mk",
    "ml", "ms", "nci", "ne", "nl", "no", "pa", "pl", "pt-br", "pt-pt",
    "ro", "ru", "si", "sk", "sl", "sq", "sr", "sv", "sw", "ta", "te",
    "th", "tr", "uk", "vi", "zh", "zh-yue"
};

    if (chdir("eSpeak/command_line") != 0) { //chdir променя директорията на терминала в eSpeak/commandline където е програмата, която изпълнява texttospeech
        perror("Error changing directory");//съобщение при грешка
        exit(EXIT_FAILURE);
    }


    do //изпълнява командата поне един път
    {


    printf(" \n");
    printf(" | | | | ___| | | ___    \n");
    printf(" | |_| |/ _ \\ | |/ _ \\  \n");
    printf(" |  _  |  __/ | | (_) |   \n");
    printf(" |_| |_|\\___|_|_|\\___( ) \n");
    printf(" \n");
    printf("Welcome to my text-to-speech converter!\n");

     printf("Enter text to convert to speech (recommended in latin): ");
    scanf(" %[^\n]s", phrase); // input за текста



    sprintf(charCommand, "espeak \"%s\"", phrase);// събирам цялата команда, която е един ред на терминала в CharCommand
    printf("Language Codes\t\tCorresponding Languages\n");
    printf("--------------------------------------------------------------\n");
    printf("af - Afrikaans\t\t\tbg - Bulgarian\t\t\tca - Catalan\n");
    printf("cs - Czech\t\t\tda - Danish\t\t\tde - German\n");
    printf("el - Greek\t\t\ten - English\t\t\ten-gb - English (UK)\n");
    printf("en-sc - Scottish English\ten-us - English (US)\t\tes - Spanish\n");
    printf("es-la - Spanish (Latin America)\tet - Estonian\t\t\teu - Basque\n");
    printf("fa - Persian\t\t\tfi - Finnish\t\t\tfr-be - French (Belgium)\n");
    printf("fr-fr - French (France)\t\tga - Irish (Gaeilge)\t\tgd - Scottish Gaelic\n");
    printf("grc - Greek (Ancient)\t\tgu - Gujarati\t\t\thi - Hindi\n");
    printf("hr - Croatian\t\t\thu - Hungarian\t\t\thy - Armenian\n");
    printf("id - Indonesian\t\t\tis - Icelandic\t\t\tit - Italian\n");
    printf("jbo - Lojban\t\t\tka - Georgian\t\t\tkl - Greenlandic\n");
    printf("kn - Kannada\t\t\tko - Korean\t\t\tku - Kurdish\n");
    printf("la - Latin\t\t\tlfn - Lingua Franca Nova\tlt - Lithuanian\n");
    printf("lv - Latvian\t\t\tmk - Macedonian\t\t\tml - Malayalam\n");
    printf("ms - Malay\t\t\tnci - Nahuatl (Classical)\tne - Nepali\n");
    printf("nl - Dutch\t\t\tno - Norwegian\t\t\tpa - Punjabi\n");
    printf("pl - Polish\t\t\tpt-br - Portuguese (Brazil)\tpt-pt - Portuguese (Portugal)\n");
    printf("ro - Romanian\t\t\tru - Russian\t\t\tsi - Sinhala\n");
    printf("sk - Slovak\t\t\tsl - Slovenian\t\t\tsq - Albanian\n");
    printf("sr - Serbian\t\t\tsv - Swedish\t\t\tsw - Swahili\n");
    printf("ta - Tamil\t\t\tte - Telugu\t\t\tth - Thai\n");
    printf("tr - Turkish\t\t\tuk - Ukrainian\t\t\tvi - Vietnamese\n");
    printf("zh - Mandarin (Chinese)\t\tzh-yue - Cantonese (Chinese)\n");


        while (!isValid) {//проверка дали потребителя е написал правилното кодове име и се повтаря тази стъпка докато не нацели кода
       printf("choose a voice by typing the accent code (for example en-gb is English British accent. Note that some accents sound the same):");
    scanf(" %[^\n]s", voice);

        // минава през целия лист с кодове
        for (i = 0; i < sizeof(codenames) / sizeof(codenames[0]); i++) {
            if (strcmp(codenames[i], voice) == 0) {
                isValid = 1;
                break;
            }
        }


        if (!isValid) {
            printf("Voice is not valid. Please try again.\n");
        }
    }

    printf("Voice Options (you can choose only one of them)\n");
printf("--------------------------------------------------------------------------------------------------\n");
printf("m1 - Male Low Tone\t\tf1 - Female Low Tone\t\twhisper - Whispered Voice\n");
printf("m2 - Male Mid Tone\t\tf2 - Female Mid Tone\t\tcroak - Drunk Voice\n");
printf("m3 - Male High Tone\t\tf3 - Female High Tone\t\ts - to skip\n");
printf("m4 - Male Higher Tone\t\tf4 - Female Higher Tone\n");
printf("Choose addtional settings (if you write something wrong, it will skip this part:)");
scanf(" %[^\n]s", etc);


        sprintf(charCommand, "espeak -v%s+%s \"%s\"", voice, etc, phrase); //добавяме отново

    system(charCommand); //изпълнение на командата
    //това е код за запазване на резултата, но не съм го добавил тъй като не се отварят файловете поради неизвестна причина
   /* printf("Type \"yes\" to save (anything other inpput will result in not saving):");
    scanf(" %[^\n]s", save);
    if(strcmp(save, "yes") == 0)
    {
        printf("Enter save file name:");
    scanf(" %[^\n]s", save);
        sprintf(charCommand + strlen(charCommand), " -w %s",savename);
    }*/
    printf("Type \"yes\" to quit (anything other input will result in redoing in restarting the program):");
    scanf(" %[^\n]s", stop);
    system("cls");
    isValid = 0;
    }
    while(strcmp(stop, "yes") != 0); // нов цикъл
    printf("\n");
    printf("BBBBB   Y   Y  EEEEE\n");
    printf("B    B   Y Y   E    \n");
    printf("BBBBB     Y    EEEE \n");
    printf("B    B    Y    E    \n");
    printf("BBBBB     Y    EEEEE\n");
    printf("\n");

    system("espeak -ven \"goodbye\"");



    return 0;

}
