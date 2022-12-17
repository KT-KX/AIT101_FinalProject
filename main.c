#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int validation=0;
int wrongattempt=0;
int infiniteloop=1;
int mainmenuselection;

void add(){
    int wantroom=0;
    int room=0;
    char name[40];
    char phonenumber[20];
    int day=0;
    char checkindate[11];
    char checkoutdate[11];

    FILE *fptr;
	fptr=fopen("C:\\Users\\Koh Ming Kai\\Downloads\\HOTEL_MANAGEMENT_SYSTEM_IN_C_PROGRAMMING_WITH_SOURCE_CODE\\HotelMgmt C Updated\\Hotel Management System C UPDT\\addroom.txt","a+");
    if(fptr==NULL);
    {
        printf("Good day sir and madam!\n");
        printf("Please fill up the form below to reserve your room.\03\n");
        printf("Please enter your name : ");
        gets(name);
        printf("Please enter your phone number : ");
        gets(phonenumber);
        printf("Please enter date to check-in (DD/MM/YYYY) : ");
        gets(checkindate);
        printf("Please enter date to check-out (DD/MM/YYYY) : ");
        gets(checkoutdate);
        printf("How many rooms you want? : ");
        scanf("%d",&wantroom);
        printf("You have succesfully booked a room.\n");
        printf("Thank you for choosing us.\n");
        printf("\03\03\03");
    }
    fprintf(fptr,"\n%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%d",name, phonenumber, checkindate, checkoutdate, wantroom);

    fclose(fptr);

    return 0;
};
void edit();
void removerecord();
void view();
void search();
void login(){
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
int main(void){
    time_t timenow;
    time(&timenow);
    printf(" ------------------------------------------------------\n");     
	printf("|                                                      |\n");
	printf("|  *       *   *         *   *       *    *         *  |\n");
	printf("|    *   *     * *     * *   *       *    * *     * *  |\n");
	printf("|      *       *  *   *  *   *       *    *  *   *  *  |\n");
	printf("|    *   *     *    *    *   *       *    *    *    *  |\n");
	printf("|  *       *   *    *    *   * * * * *    *    *    *  |\n");
	printf("|                                                      |\n");                       
	printf(" ------------------------------------------------------\n");
    printf("\n\n--------------------------------------------------------");
    printf("\n\tDate and Time: %s",ctime(&timenow));
    printf("--------------------------------------------------------\n\n");
    printf("Press any key to login! ");
    getch();
    login();
    while (validation==2)
    {
        exit(1);
    }
    system("cls");
 
    while (infiniteloop==1)
    {   
        printf("\n ---------------------------------------");
        printf("\n|     XMUM Hotel Reservation System     |");
        printf("\n|                                       |");
        printf("\n|  Main Menu                            |");
        printf("\n|  1) Room Booking/Reservation          |");
        printf("\n|  2) Edit Customer Record              |");
        printf("\n|  3) Remove/Delete Customer Record     |");
        printf("\n|  4) View Customer Record              |");
        printf("\n|  5) Search Customer Record            |");;
        printf("\n|  6) Exit                              |");
        printf("\n ---------------------------------------");
        printf("\n Your Selection: ");
        scanf("%d",&mainmenuselection);
        if(mainmenuselection==1){
            add();
        }else if (mainmenuselection==2){
            edit();
        }else if (mainmenuselection==3){
            removerecord();
        }else if (mainmenuselection==4){
            view();
        }else if (mainmenuselection==5){
            search();
        }else if (mainmenuselection==6){
            system("cls");
            printf("THANK YOU. SEE YOU NEXT TIME");
            exit(0);
        }else{
            printf("\n\nInvalid Input.Please Try Again");
            printf("\nPress any key to continue. ");
            getch();
        }
        
    }
    
    return 0;

}

void add(){
    system("cls");
    printf("please edit here");
}

void edit(){
    system("cls");
    printf("please edit here");
}
void removerecord(){
    system("cls");
    printf("please edit here");
}
void view(){
    system("cls");
    printf("please edit here");
}
void search(){
    system("cls");
    printf("please edit here");
}
