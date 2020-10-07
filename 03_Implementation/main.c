#include<contact.h>
struct contact

{


    char name[20],add[60],email[30],ph[20];
    char answer;

} list;

char query[20],name[20];

FILE *fp, *ft;

int i,n,ch,l,found,k,n,a;
char user[10];
char pass[10];

void main()
{

	n=login(user,pass);
	if(n==1)
    	{

        printf("  \n\n\n       WELCOME TO CONTACT MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL");
        printf("\n\n\n\t\t\t\tPress any key to continue...");
        getch();
        mainmenu();
    	}
    	else
        {
           printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;
	    main();

        }
   	if (a>2)
        {
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

	}
}
