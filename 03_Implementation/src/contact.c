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
void mainmenu(void)
	{
		int choice;

		system("cls");
		printf("\n------------------------------------------------------------------------------------------------");

		printf("MAIN MENU");
		printf("\n------------------------------------------------------------------------------------------------");
        printf("\n\t \xB2\xB2\xB2\xB2\xB2\xB2 Contact Management System \xB2\xB2\xB2\xB2\xB2\xB2");

        printf("\n\n\n\t\t\tMAIN MENU\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t<1> Add new Contact\n\t\t<2> List all Contacts\n\t\t<3> Search for contact\n\t\t<4> Edit a Contact\n\t\t<5> Delete a Contact\n\t\t<0> Exit\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t");

		scanf("%i",&choice);
		switch(choice)
			{
				case 1:
				add_contact();
				break;
				case 2:
			    	list_contact();
				break;
				case 3:
				search_contact();
				break;
                		case 4:
				edit_contact();
				break;
				case 5:
				delete_contact();
				case 6:
				exit(0);
				break;

				default:
					printf("Exiting");
					exit(0);


			}
}



/* *********************Add new contacts************  */

    void add_contact()
    {

            char answer;

            system("cls");

            fp=fopen("contact.txt","a");

            fflush(stdin);

            printf("\nFullName :");

            scanf("%[^\n]",&list.name);

            fflush(stdin);

            printf("Phone:");

            gets(list.ph);


            //scanf("%ld",&list.ph);

            fflush(stdin);

            printf("address:");

            scanf("%[^\n]",&list.add);

            fflush(stdin);

            printf("email address:");

            gets(list.email);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

            fclose(fp);

            printf("\n\t\t Do you want to add another contact?[Y/N]:");

            scanf("%s",&answer);

            while(toupper(answer)!='Y'&& toupper(answer)!='N')

            {
                printf("Invalid!\n\tDo you want to add another contact?[Y/N]:");

                scanf("%s",&answer);
            }
            if(toupper(answer)=='Y')

            {
                add_contact();
            }

            else
            {
                printf("\n\t\tPress any key to go to mainmenu.....");
                mainmenu();
            }
    }



        /* *********************list of contacts*************************  */

    void list_contact()
    {
        char answer;
        system("cls");

        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t\tLIST OF CONTACTS\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("contact.txt","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nPhone\t: %s\nAddress\t: %s\nEmail\t: %s\n",list.name,

                           list.ph,list.add,list.email);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }
        mainmenu();


    }

        /* *******************search contacts**********************  */

    void search_contact()
    {


            char answer;

            system("cls");
            found=0;

            printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("contact.txt","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Phone\t: %s\n..::Address\t: %s\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }


            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n\t\t Do you want to add search another contact ?[Y/N]:");

            scanf("%s",&answer);

            while(toupper(answer)!='Y'&& toupper(answer)!='N')
            {
                printf("Invalid!\n\tDo you want to search another contact?[Y/N]:");

                scanf("%s",&answer);
            }
            if(toupper(answer)=='Y')
            {
                search_contact();
            }
            else
            {
                printf("\n\t\tPress any key to go to mainmenu.....");

                mainmenu();
            }

    }

        /* *********************edit contacts************************/

 void edit_contact()

 {      char answer;
        system("cls");

        fp=fopen("contact.txt","r");

        ft=fopen("temp.txt","w");

        fflush(stdin);

        printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",name);

        printf("..::Name(Use identical):");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::Phone:");

        //scanf("%ld",&list.ph);
        gets(list.ph);

        fflush(stdin);

        printf("..::address:");

        scanf("%[^\n]",&list.add);

        fflush(stdin);

        printf("..::email address:");

        gets(list.email);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.txt");

        rename("temp.txt","contact.txt");



        printf("\n\t\t Do you want to edit another contact?[Y/N]:");

	    scanf("%s",&answer);

        while(toupper(answer)!='Y'&& toupper(answer)!='N')
        {
            printf("Invalid!\n\tDo you want to edit another contact ?[Y/N]:");
            scanf("%s",&answer);
        }
        if(toupper(answer)=='Y')
        {
            edit_contact();
        }
        else
        {
            printf("\n\t\tPress any key to go to mainmenu.....");
            mainmenu();
        }
 }





void delete_contact()
{
        char answer;
        system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("contact.txt","r");

        ft=fopen("temp.txt","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.txt");

        rename("temp.txt","contact.txt");


        printf("contact successfully deleted!!!");

        printf("\n\t\t Do you want to delete another contact?[Y/N]:");

	    scanf("%s",&answer);

        while(toupper(answer)!='Y'&& toupper(answer)!='N')
        {
            printf("Invalid!\n\tDo you want to delete another contact ?[Y/N]:");
            scanf("%s",&answer);
        }
        if(toupper(answer)=='Y')
        {
            delete_contact();
        }
        else
        {
            printf("\n\t\tPress any key to go to mainmenu.....");
            mainmenu();
        }


    }


