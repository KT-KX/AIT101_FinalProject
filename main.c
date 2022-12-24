#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "login.h"

int validation=0;
int wrongattempt=0;
int infiniteloop=1;
int mainmenuselection;
int roommenu;

struct CustomerDetails{
    char name[20];
    char phonenumber[15];
    char checkindate[15];
    char checkoutdate[15];
    char roomnumber[10];
}customer;

void add();
void edit();
void removerecord();
void view();
void roomlist();

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
    while (validation==2){
        exit(1);
    }

    system("cls");
    while (infiniteloop==1){   
        printf("\n ---------------------------------------");
        printf("\n|     XMUM Hotel Reservation System     |");
        printf("\n|                                       |");
        printf("\n|  Main Menu                            |");
        printf("\n|  1) Room Booking/Reservation          |");
        printf("\n|  2) Edit Customer Record              |");
        printf("\n|  3) Remove/Delete Customer Record     |");
        printf("\n|  4) View Customer Record              |");
        printf("\n|  5) Room List                         |");;
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
            roomlist();
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
    FILE *fptr;
	fptr=fopen("addroom.txt","a+");
    if(fptr==NULL);{
        printf("Good day sir and madam!\n");
        printf("Please fill up the form below to reserve your room.\03\n");
        printf("Please enter your Room number: ");
        gets(customer.roomnumber);
        gets(customer.roomnumber);
        printf("Please enter your name : ");
        gets(customer.name);
        printf("Please enter your phone number : ");
        gets(customer.phonenumber);
        printf("Please enter date to check-in (DD/MM/YYYY) : ");
        gets(customer.checkindate);
        printf("Please enter date to check-out (DD/MM/YYYY) : ");
        gets(customer.checkoutdate);  
        printf("You have succesfully booked a room.\n");
        printf("Thank you for choosing us.\n");
        printf("\03\03\03");
    }
    fwrite(&customer,sizeof(customer),1,fptr);
	fflush(stdin);
    fclose(fptr);
    printf("\nPress any key to continue!");
	getch();
}

void edit(){
    int i = 1;
    FILE *fptr;
    int j = 1;
    char roomnumber[20];
    long int size=sizeof(customer);
    if((fptr=fopen("addroom.txt","r+"))==NULL)
        exit(1);  
    printf("\nEnter Your Room Number: ");
    gets(roomnumber);
    gets(roomnumber);
    fflush(stdin);
    while (fread(&customer,sizeof(customer),1,fptr)==1){
        if(strcmp(customer.roomnumber,roomnumber)==0){
            j=0;
            printf("Please enter your Room number: ");
            gets(customer.roomnumber);
            printf("Please enter your name : ");
            fflush(stdin);
            gets(customer.name);
            printf("Please enter your phone number : ");
            gets(customer.phonenumber);
            printf("Please enter date to check-in (DD/MM/YYYY) : ");
            gets(customer.checkindate);
            printf("Please enter date to check-out (DD/MM/YYYY) : ");
            gets(customer.checkoutdate);
            printf("You have succesfully changed your details.\n");
            printf("Thank you for choosing us.\n");
            printf("\03\03\03");
            fseek(fptr,size,SEEK_CUR);
			fwrite(&customer,sizeof(customer),1,fptr);
			break;
        }
    }
    if(j==1){
		printf("\n\nNO RECORD FOUND!!!!");
		fclose(fptr);
        printf("\nPress any key to continue!");
		getch();
	}else{
        fclose(fptr);
        printf("\n\nRECORD EDITED SUCCESSFULLY!!!");
        printf("\nPress any key to continue!");
        getch();
    }   
}

void removerecord(){
	FILE *fptr, *t;
    int i=1;
    char roomnumber[20];
    //Check the existence of the file
    if ((t=fopen("temp.txt","w"))==NULL)
        exit(0);
    if((fptr=fopen("addroom.txt","r"))==NULL)
        exit(0);
    system("cls");
    printf("Enter the Room Number of the hotel to be removed from the record..\n");
    fflush(stdin);
    scanf("%s",roomnumber);
    while(fread(&customer,sizeof(customer),1,fptr)==1){
        if(strcmp(customer.roomnumber,roomnumber)==0){
            i=0;
            continue;
        }
        else
            fwrite(&customer,sizeof(customer),1,t);
        }
        if(i==1){
            printf("\n\n Records of Customer in this room have been deleted...\n\n");
            getch();
            fclose(fptr);
            fclose(t);
            main();
        } 
    fclose(fptr);
    fclose(t);
    remove("addroom.txt");
    rename("temp.txt","addroom.txt");
    printf("\n\nThe customer is sucessfully removed. ");
    printf("\nEnter any key to continue.");
    fclose(fptr);
    fclose(t);
    getch();
}

void view(){
    FILE *fptr;
	int i;
	fptr=fopen("addroom.txt","r");

    printf("Name\t\tPhone Number\t\tCheck In Date\t\tCheck Out Date\tRoom Number");
	while(fread(&customer,sizeof(customer),1,fptr)==1)
	{
		printf("\n%s \t%s \t\t%s \t\t%s \t%s",customer.name, customer.phonenumber, customer.checkindate, customer.checkoutdate, customer.roomnumber);
	}
	printf("\n");
    printf("\nPress any key to continue.");
	fclose(fptr);
	getch();
}

void roomlist(){
    int valid=1;
    system("cls");
    printf("\n                 ROOM LIST                 ");
    printf("\n===========================================");
    printf("\nType Of Room\tRoom Number\tPrice");
    for (int i = 1; i <10 ; i++)
    {
        printf("\nSingle\t\tA0%d\t\tRM150/night",i);
    }
    printf("\n-------------------------------------------");
    for (int i = 1; i <10 ; i++)
    {
        printf("\nDouble\t\tB0%d\t\tRM250/night",i);
    }
    printf("\n-------------------------------------------");
    for (int i = 1; i <6 ; i++)
    {
        printf("\nQueen\t\tQ0%d\t\tRM300/night",i);
    }
    printf("\n-------------------------------------------");
    for (int i = 1; i <6 ; i++)
    {
        printf("\nKing\t\tK0%d\t\tRM450/night",i);
    }
    printf("\n-------------------------------------------");
    for (int i = 1; i <4 ; i++)
    {
        printf("\nPremium\t\tP0%d\t\tRM550/night",i);
    }
    printf("\n-------------------------------------------");
    for (int i = 1; i <3 ; i++)
    {
        printf("\nDeluxe\t\tD0%d\t\tRM650/night",i);
    }
    printf("\n-------------------------------------------");
    for (int i = 1; i <3 ; i++)
    {
        printf("\nSupreme\t\tS0%d\t\tRM750/night",i);
    }
    printf("\n===========================================");
    printf("\n\n");

    while (valid==1)
    {
        printf("\n ---------------------------------------");
        printf("\n|     XMUM Hotel Reservation System     |");
        printf("\n|                                       |");
        printf("\n|  Room Menu                            |");
        printf("\n|  1) Room Booking/Reservation          |");
        printf("\n|  2) Exit                              |");
        printf("\n ---------------------------------------");
        printf("\n Your Selection: ");
        scanf("%d",&roommenu);
        if (roommenu==1){
            add();
        }else{
            break;
        }
    }
    printf("\nEnter any key to continue.");
    getch();
}