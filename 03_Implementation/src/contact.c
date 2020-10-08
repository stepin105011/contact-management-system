#include<contact.h>

int login(char user[10],char pass[10])
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];


    printf("\n  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\  LOGIN FORM  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\  ");
    printf(" \n\n                  ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n\n                  ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

    if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	k=1;

	}
	else
	{
		k=0;


	}

    return k;

}
