#include <string.h>
#include <stdio.h>

void login(){
    
    int validation=0;
    int wrongattempt=0;
    char username[15] = "aitgroup10"; // default username
    char password[15] = "finalfullmark"; // default username
    char usernameinput[15]; 
    char passwordinput[15];
    //strcmp is the function to compare two string 
    //if two string comparing is not equal to zero means they are not equal vice versa
    while (strcmp(username,usernameinput)!=0 && strcmp(password,passwordinput)!=0)
    {
        printf("\nEnter Login Details ");
        printf("\n------------------------------------------------------");
        printf("\nUSERNAME: ");
        scanf("%s",usernameinput);
        printf("PASSWORD: ");
        scanf("%s",&passwordinput);
        // here compare the user input and default whether it is the same
        if (strcmp(username,usernameinput)==0 && strcmp(password,passwordinput)==0)
        {
            printf("\nLogin Successfully. ");
            getch();
            validation = 1; //validate 
        }else{
        //wrong attempt +1 , if more than 3 time, will automatically quit program
           wrongattempt+=1; 
           if(wrongattempt==3){
            printf("\nPlease find administrator to reset your password");
            getch();
             validation=2;  
             break;
           }else{
            printf("\nLogin Failed. Wrong username or password!");
            printf("\nTry again! or Press CTRL-C to terminate the program");
           }
        }
    }
}