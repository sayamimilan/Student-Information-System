#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
void menu();
void add();
void list();
void search();
void dele();

void main()
{
	char username[40];
	char password[40];
	clrscr();
	printf("***LOGIN***\n\n\n");
	entry:
	printf("\nUsername:");
	scanf("%s",username);
	printf("\nPassword:");
	scanf("%s",password);
	clrscr();
	if(strcmp(username,"admin")==0)
	{
		if(strcmp(password,"admin")==0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n--------------------------students information system----------------------\n\n");
			textcolor(GREEN+BLINK);
			cprintf("                                press enter");
			textcolor(WHITE);
			getch();
			clrscr();
		}
	}
	else
	{
		printf("The username and password is incorrect");
		goto entry;
	}
	menu();
	getch();
}

void menu()
{
	int x,i,n;
	clrscr();
	printf("************************************************\n");
	printf("\tMAIN MENU-STUDENT INFORMATION SYSTEM\n");
	printf("************************************************\n");
	printf("1:Add Records\n");
	printf("2:List Records\n");
	printf("3:Search Records\n");
	printf("4:Delete Records\n");
	printf("5:Exit\n");
	printf("************************************************\n");
	printf("Please enter the option\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			add();
			break;
		case 2:
			list();
			break;
		case 3:
			search();
			break;
		case 4:
			dele();
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Error! Wrong Number is Entered \nPlease Try Again\n");
	}
	getch();
	menu();
}

void add()
{
	FILE *fptr;

	char id[100],fname[40],lname[40],address[40],faculty[40],s[1],phone[40];

	int n,i;
	clrscr();
	printf("\n\n\n----------ADD RECORDS---------\n\n\n");
	printf("Please enter the following student information.\n\n");
	fptr = fopen("data.txt","a+");
	if(fptr == NULL)
	{
		printf("error");
       //	exit(1);
	}
	printf("Enter the number of students: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter ID              :");
		scanf("%s",id);
		printf("\nEnter First Name      :");
		scanf("%s",fname);
		printf("\nEnter Last Name       :");
		scanf("%s",lname);
		printf("\nEnter address         :");
		scanf("%s",address);
		printf("\nEnter faculty         :");
		scanf("%s",faculty);
		printf("\nEnter Phone Number    :");
		scanf("%s",phone);
		l2:
		printf("\nEnter sex (m/f)       :");
		scanf("%s",s);
		if (strcmp(s,"m")==0 || strcmp(s,"f")==0)
		{
			goto l1;
		}
		else
		{
			printf("invalid input \n");
			goto l2;
		}
		l1:
		fprintf(fptr,"%s \n",id);
		fprintf(fptr,"%s \n",fname);
		fprintf(fptr,"%s \n",lname);
		fprintf(fptr,"%s \n",address);
		fprintf(fptr,"%s \n",faculty);
		fprintf(fptr,"%s \n",s);
		fprintf(fptr,"%s \n",phone);
		printf("\n----------------------------------------------------\n");
	}
	fclose(fptr);
	//return 0;
	getch();
	menu();
}

void list()
{
	FILE *fptr;
	char id[100],fname[40],lname[40],address[40],faculty[40],s[1],phone[40];
	fptr=fopen("data.txt","r");
	clrscr();
	printf("all list\n");
	while(fscanf(fptr,"%s%s%s%s%s%s%s",id,fname,lname,address,faculty,s,phone)!=EOF)
	{
		printf("\n\t ID is : %s",id);
		printf("\n\t first name is : %s",fname);
		printf("\n\t second name is : %s",lname);
		printf("\n\t address is : %s",address);
		printf("\n\t faculty is : %s",faculty);
		printf("\n\t sex is : %s",s);
		printf("\n\t phone number is : %s",phone);
		printf("\n\t-----------------------------------------------\n");
	}
	fclose(fptr);
	getch();
	menu();
}

void search()
{
	FILE *fptr;
	char name[40];
	char id[100];
	char fname[40];
	char lname[40];
	char address[40];
	char faculty[40];
	char s[1];
	char phone[40];
	fptr=fopen("data.txt","r");
	clrscr();
	printf(" Search list");
	printf("\n\t enter name :");
	scanf("%s",name);
	while(fscanf(fptr,"%s%s%s%s%s%s%s",id,fname,lname,address,faculty,s,phone)!=EOF)
	{
		if(strcmp(name,fname)==0)
		{
			printf("\n\t ID is : %s",id);
			printf("\n\t first name is : %s",fname);
			printf("\n\t last name is :%s",lname);
			printf("\n\t address is : %s",address);
			printf("\n\t faculty is : %s",faculty);
			printf("\n\t sex is : %s",s);
			printf("\n\t phone number is : %s",phone);
		}
	}
	fclose(fptr);
	getch();
	menu();
}

void dele()
{
	FILE *fptr,*fdel;
	char name[40];
	char id[100];
	char fname[40];
	char lname[40];
	char address[40];
	char faculty[40];
	char s[1];
	char phone[40];
	fptr=fopen("raman.txt","r+");
	fdel=fopen("student.txt","w");
	clrscr();
	printf("Delete entry");
	printf("\n\t enter name :");
	scanf("%s",name);
	while(fscanf(fptr," %s %s %s %s %s %s %s  ",id,fname,lname,address,faculty,s,phone)!=EOF)
	{
		if(strcmp(name,fname)==0)
		{
			continue;
		}
		fprintf(fdel,"%s%s%s%s%s%s%s",id,fname,lname,address,faculty,s,phone);
	}
	fclose(fptr);
	fclose(fdel);
	fptr=fopen("data.txt","w");
	fdel=fopen("student.txt","r");
	while(fscanf(fdel,"%s%s%s%s%s%s%s",id,fname,lname,address,faculty,s,phone)!=EOF)
	{
		fprintf(fptr,"%s%s%s%s%s%s%s ",id,fname,lname,address,faculty,s,phone);
	}
	fclose(fptr);
	fclose(fdel);
	remove("student.txt");
	printf("\n\t Press Enter to continue");
	getch();
	menu();
}