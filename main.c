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
    char roomnumber[10];
    char name[20];
    char phonenumber[15];
    char checkindate[15];
    char checkoutdate[15];
}customer;

void add();
void edit();
void removerecord();
void view();
void roomlist();

int main(void){
    time_t timenow; // time function to show time later
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
    printf("\n\tDate and Time: %s",ctime(&timenow)); // show date and time
    printf("--------------------------------------------------------\n\n");
    printf("Press any key to login! "); //login get character input
    getch();
    login(); // jump to login function
    // validation of login if true continue to next menu, else exit whole program
    // for details, please refer to the login.h file for the login function
    while (validation==2){
        exit(1);
    }

    system("cls");
    // main menu
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
        scanf("%d",&mainmenuselection); // get user selection 
        // jump to each function according to user input
        if(mainmenuselection==1){
            add(); // jump to add function
        }else if (mainmenuselection==2){
            edit(); // kump to edit function
        }else if (mainmenuselection==3){
            removerecord(); // jump to remove record function
        }else if (mainmenuselection==4){
            view(); // jump to view function
        }else if (mainmenuselection==5){
            roomlist(); // jump to roomlist function
        }else if (mainmenuselection==6){
            system("cls");
            printf("THANK YOU. SEE YOU NEXT TIME");
            exit(0); // exit the program
        }else{
            printf("\n\nInvalid Input.Please Try Again");
            printf("\nPress any key to continue. ");
            getch(); //continue if invalid input receive
        }    
    }
    return 0;
}

void add(){
    FILE *fptr; // declare fptr pointer variable to file datatype
	fptr=fopen("addroom.txt","a+"); 
    // open file location .a+ means open a file in both read and write mode
    if(fptr==NULL);{ // check whether the file is blank or not
        printf("Good day sir and madam!\n");
        printf("Please fill up the form below to reserve your room.\03\n");
        //input of user information
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
        printf("You have successfully booked a room.\n");
        printf("Thank you for choosing us.\n");
        printf("\03\03\03");
    }
    //write the input inside the text file
    fwrite(&customer,sizeof(customer),1,fptr);
	fflush(stdin); // clear the output buffer and move the buffered data to console 
    fclose(fptr); // close file
    printf("\nPress any key to continue!");
	getch(); // get any character of input from user 
}

void edit(){
    int i = 1;
    FILE *fptr; // declare fptr pointer variable to file datatype
    int j = 1;
    char roomnumber[20];
    long int size=sizeof(customer); // compute the size of struct
    if((fptr=fopen("addroom.txt","r+"))==NULL) // if txt file is empty then quit
        exit(1);  
    printf("\nEnter Your Room Number: "); 
    gets(roomnumber);
    gets(roomnumber);
    fflush(stdin);
    while (fread(&customer,sizeof(customer),1,fptr)==1){ // read if file have content
        if(strcmp(customer.roomnumber,roomnumber)==0){ // compare input with the data inside the txt file
            j=0;
            // get new information of the customer (by user input)
            printf("Please enter your new Room number: ");
            gets(customer.roomnumber);
            printf("Please enter your name : ");
            fflush(stdin); // clear the output buffer and move the buffered data to console 
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
            fseek(fptr,size,SEEK_CUR); // find the desired position in the txt file
			fwrite(&customer,sizeof(customer),1,fptr); // write the data inside the txt file
			break;
        }
    }
    if(j==1){
        // output result if no record is found
		printf("\n\nNO RECORD FOUND!!!!");
		fclose(fptr);
        printf("\nPress any key to continue!");
		getch(); // get any character to continue
	}else{
        fclose(fptr); //close file after the record is edited
        printf("\n\nRECORD EDITED SUCCESSFULLY!!!");
        printf("\nPress any key to continue!");
        getch();
    }   
}

void removerecord(){
	FILE *fptr, *t; // declare fptr,t pointer variable to file datatype
    int i=1;
    char roomnumber[20];
    //Check the existence of the file
    if ((t=fopen("temp.txt","w"))==NULL)
        exit(0);
    if((fptr=fopen("addroom.txt","r"))==NULL)
        exit(0);
    system("cls");
    printf("Enter the Room Number of the hotel to be removed from the record..\n");
    fflush(stdin); // clear the output buffer and move the buffered data to console 
    scanf("%s",roomnumber);
    while(fread(&customer,sizeof(customer),1,fptr)==1){
        //compare user input with data inside the text file
        if(strcmp(customer.roomnumber,roomnumber)==0){
            i=0; 
            continue;
        }
        else
            fwrite(&customer,sizeof(customer),1,t);
        }
        // if this already been deleted, prompt this message
        if(i==1){
            printf("\n\n Records of Customer in this room have been deleted...\n\n");
            getch();
            fclose(fptr);
            fclose(t);
            main();
        } 
    fclose(fptr);
    fclose(t);
    remove("addroom.txt"); // remove data 
    rename("temp.txt","addroom.txt"); 
    printf("\n\nThe customer is sucessfully removed. ");
    printf("\nEnter any key to continue.");
    fclose(fptr);
    fclose(t);
    getch(); //get charater input to continue
}

void view(){
    FILE *fptr; // declare fptr pointer variable to file datatype
	int i;
	fptr=fopen("addroom.txt","r"); //open text file

    printf("Room Number\tName\t\tPhone Number\tCheck In Date\tCheck Out Date");
	while(fread(&customer,sizeof(customer),1,fptr)==1) // read the file
	{
        // prompt result from the text file according data structure
		printf("\n%s \t\t%s \t%s \t%s \t%s",customer.roomnumber, customer.name, customer.phonenumber, customer.checkindate, customer.checkoutdate );
	}
	printf("\n");
    printf("\nPress any key to continue.");
	fclose(fptr); //close file
	getch(); // get character input
}

void roomlist(){
    int valid=1;
    //prompting the details and our room list 
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
    // jump to add function directly after showing all room list
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