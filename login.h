#include <string.h>
#include <stdio.h>

void login(){
    
    int validation=0;
    int wrongattempt=0;
    char username[15] = "aitgroup10";
    char password[15] = "finalfullmark";
    char usernameinput[15],c= ' ';
    char passwordinput[15],code[15];
    while (strcmp(username,usernameinput)!=0 && strcmp(password,passwordinput)!=0)
    {
        printf("\nEnter Login Details ");
        printf("\n------------------------------------------------------");
        printf("\nUSERNAME: ");
        scanf("%s",usernameinput);
        printf("PASSWORD: ");
        scanf("%s",&passwordinput);
        if (strcmp(username,usernameinput)==0 && strcmp(password,passwordinput)==0)
        {
            printf("\nLogin Successfully. ");
            validation = 1;
        }else{
           wrongattempt+=1;
           if(wrongattempt==3){
            printf("\nPlease find administrator to reset your password");
             validation=2;  
             break;
           }else{
            printf("\nLogin Failed. Wrong username or password!");
            printf("\nTry again! or Press CTRL-C to terminate the program");
           }
        }
    }
}