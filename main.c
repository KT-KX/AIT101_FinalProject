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
/*
void removerecord(){
    system("cls");
    FILE *fptr;
    int i=1;
    char roomnumber[20];
    int close = 0;

  while(1){
    system("cls");
    //scanf("%s",&option);
    mainmenuselection=getch();
    switch(mainmenuselection){
      case 'y':
           system("cls");
      if((fptr=fopen("temp.txt","w"))==NULL)
        exit(0);
      if((fptr=fopen("Records.txt","r"))==NULL)
        exit(0);
      system("cls");
      printf("Enter your Room Number of the hotel to be removed: \n");
      scanf("%s",&roomnumber);
      while(fread(&customer,sizeof(s),1,fptr)==1){
        if(strcmp(s.roomnumber,roomnumber)==0){
          i = 0;
          continue;
        }
        else
          fwrite(&s,sizeof(s),l,t);
      }
      if(i==1){
        printf("\n\n Records of Customer in this Room number is not found!!\n");
        fclose(fptr);
        fclose(fptr);
        }
      else{
        printf("\n\nThe Customer is sucessfully removed..\n");
      }
      fclose(fptr);
      fclose(t);
      remove("Records.txt");
      rename("temp.txt","Records.txt");
      fclose(fptr);
      fclose(t);
      Sleep(3000);
      close-1;
      break;
      case 'n':
          close=1;
          break;
      }
      if(close==1)
        break;
}

}*/

void view(){
    system("cls");
    printf("please edit here");
}
void search(){
    system("cls");
    printf("please edit here");
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
    FILE *fptr;
    int j = 1;
    char roomnumber[20];
    long int size=sizeof(customer);
    if((fptr=fopen("addroom.txt","r+"))==NULL)
        exit(1);  
    printf("\nEnter Your Room Number: ");
    gets(roomnumber);
    gets(roomnumber);
   // printf("%s",roomnumber);
    fflush(stdin);
    while (fread(&customer,sizeof(customer),1,fptr)==1){
        if(strcmp(customer.roomnumber,roomnumber)==0){
            j=0;
            printf("Please enter your Room number: ");
            gets(customer.roomnumber);
            printf("Please enter your name : ");
            gets(customer.name);
            fflush(stdin);
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
		printf("\n\nTHE RECORD DOES NOT EXIST!!!!");
		fclose(fptr);
        printf("\nPress any key to continue!");
		getch();
	}else{
	fclose(fptr);
	printf("\n\nYOUR RECORD IS SUCCESSFULLY EDITED!!!");
    printf("\nPress any key to continue!");
	getch();
    }   
}