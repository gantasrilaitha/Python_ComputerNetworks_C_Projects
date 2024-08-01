#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
void insert_record(FILE *ptr);
void clean_stdin();
void display(FILE *ptr);
void search_and_print(FILE *ptr);
void update(FILE *ptr);
int search(FILE *ptr,char name_1[]);
int count();
void del();
void sort();
char filename[20];
void backup();
struct{
   char name[40];
  long long int mobile_num;
   char email[30];
   char profession[30];
char address[45];
}contact,sorte[200],temp;
int main()
{system("cls");
int pass,x=3;
printf("\t\t\t\t*****OPEN YOUR PHONEBOOK APPLICATION*****\n\n");
printf("Hint:Password is an integer\n");
while(x!=0){printf("Enter password");
scanf("%d",&pass);
if(pass==123){printf("Correct password");
system("cls");
FILE *fp;
int choice;
fp=fopen("hello.txt","rb+");
if(fp==NULL)
        {fp=fopen("hello.txt","wb+");
             if(fp==NULL)
             {
                printf("Error in opening File\n");
                exit(1);
             }
        }
	while(1)
        {
            system("cls");
printf("\t\t\t\t*****WELCOME TO YOUR PHONEBOOK*****\n\n");
printf("\t\t1.Enter the New contact details");
printf("\t\t\t2.Update the contact details\n\n");
printf("\t\t3.Delete the record");
printf("\t\t\t\t4.Display the list of records\n\n");
printf("\t\t5.Search particular record");
printf("\t\t\t6.Count the records\n\n");
printf("\t\t7.Sort the record");
printf("\t\t\t\t8.Backup the records\n\n");

printf("\nEnter the choice\n");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:insert_record(fp);
                    break;
             case 2:update(fp);
                    break;
           case 3:del(fp);
                    break;
	     case 4:display(fp);
				break;
            case 5:search_and_print(fp);
                    break;
		case 6:count(fp);
			break;
		case 7:sort(fp);
                   break;
		case 8:backup(fp);
			  break;
		default:printf("Please Enter the choice correctly");

            }
           _getch();
        }

}
else {printf("Wrong password,try again\n");
x--;
if(x>0)
{printf("You are left with %d chances\n",x);}
if(x==0){printf("You cannot access the data");}}
}

}

int len( long long int n){
if(n==0)
    return 0;
else
    return (1+len(n/10));
}

void insert_record(FILE *fp){
    char check[50];
    clean_stdin();
    fseek(fp,0,2);
    printf("Enter the contact name:");
    scanf("%[^\n]s",contact.name);
    printf("Enter the mobile number:");
    scanf("%lld",&contact.mobile_num);
    while(len(contact.mobile_num)!=10){
        printf("Enter the correct mobile number:");
        scanf("%lld",&contact.mobile_num);}
    printf("Enter the email:");
    clean_stdin();
    scanf("%s",contact.email);
    printf("Enter the profession:");
    clean_stdin();
    scanf("%[^\n]s",contact.profession);
    printf("Enter the address:");
    clean_stdin();
    scanf("%[^\n]s",contact.address);
    fwrite(&contact,sizeof(contact),1,fp);
}
int search(FILE *fp,char name_1[])
{
    int flag=0;

    rewind(fp);
    while(fread(&contact,sizeof(contact),1,fp)==1)
    {
        if(strcmp(name_1,contact.name)==0)
        {
            flag=1;
            break;
 }}
 if(flag==0)
    {
        return 0;
        //printf("Match not found\n");
    }

    return flag;
}
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
void display(FILE *fp){
    rewind(fp);
    while(fread(&contact,sizeof(contact),1,fp)==1)
    {
         printf("*****\n");
         printf("NAME:%s\n",contact.name);
         printf("MOBILE NUMBER:%lld\n",contact.mobile_num);
         printf("EMAIL ID:%s\n",contact.email);
         printf("PROFESSION:%s\n",contact.profession);
         printf("ADDRESS:%s\n",contact.address);
         printf("*****\n");
	}
}
void sort(FILE *fp){int i,j,k;
	k=0;
	rewind(fp);
	while(fread(&contact,sizeof(contact),1,fp)==1)
	{sorte[k++]=contact;
    }
     for(i=1;i<=k;i++)
        {for(j=0;j<k-i;j++)
            {if(strcmp(sorte[j].name,sorte[j+1].name)>0)
                {
                    temp=sorte[j];
                    sorte[j]=sorte[j+1];
                    sorte[j+1]=temp;

                }
            }
        }
        for(i=0;i<k;i++)
    {
         printf("***********************************\n");
         printf("NAME:%s\n",sorte[i].name);
         printf("MOBILE NUMBER:%lld\n",sorte[i].mobile_num);
         printf("EMAIL ID:%s\n",sorte[i].email);
         printf("PROFESSION:%s\n",sorte[i].profession);
	   printf("ADDRESS:%s\n",sorte[i].address);
         printf("***********************************\n");

    }
    if(count(fp)==0)
    {
    printf("\nContact list is Empty\n");
    }
}

int count(FILE *fp){rewind(fp);
int res;
int c=0;
while(fread(&contact,sizeof(contact),1,fp)==1)
{c++;}
printf("Number of Contact:%d\n",c);
return c;
}



void search_and_print(FILE *fp){
    char name_1[50];
    int flag=0;
    int choice_1;
    printf("1.Search on the basis of Name\n");
    printf("2.Search on the basis of Phone number\n");
    printf("Enter the choice:");
    scanf("%d",&choice_1);
    if(choice_1==1)
    {
           printf("Enter the name whose contact details want to know:");
           clean_stdin();
           scanf("%[^\n]s",name_1);
           rewind(fp);
           while(fread(&contact,sizeof(contact),1,fp)==1)
           {
                 if(strcmp(name_1,contact.name)==0)
                 {
                         printf("*****\n");
                         printf("NAME:%s\n",contact.name);
                         printf("MOBILE NUMBER:%lld\n",contact.mobile_num);
                         printf("EMAIL ID:%s\n",contact.email);
                         printf("PROFESSION:%s\n",contact.profession);
                         printf("ADDRESS:%s\n",contact.address);
                        printf("*****\n");
                        flag=1;
                         break;
                  }
            }
    if(flag==0)
    {
        printf("Match not found\n");
    }
    }
    else if(choice_1==2)
    {
           long long int temp_con;
            clean_stdin();
           printf("Enter the contact no whose contact details want to know:");
           scanf("%lld",&temp_con);
           rewind(fp);
           while(fread(&contact,sizeof(contact),1,fp)==1)
           {
                 if(contact.mobile_num==temp_con)
                 {
                         printf("*****\n");
                         printf("NAME:%s\n",contact.name);
                         printf("MOBILE NUMBER:%lld\n",contact.mobile_num);
                         printf("EMAIL ID:%s\n",contact.email);
                         printf("PROFESSION:%s\n",contact.profession);
                          printf("ADDRESS:%s\n",contact.address);
                        printf("*****\n");
                        flag=1;
                         break;
			}
            }
    if(flag==0)
    {
        printf("Match not found\n");
    }
    }
}

void update(FILE *fp)
{
    char check[50];
    char name_1[50];
    long size=sizeof(contact);
    clean_stdin();
    printf("Enter the name of the contact you want to modify:");
    scanf("%[^\n]s",&name_1);
    if(search(fp,name_1)==1)
    {
    clean_stdin();
    printf("Enter the New contact name:");
    scanf("%[^\n]s",&contact.name);
    printf("Enter the mobile number:");
    scanf("%lld",&contact.mobile_num);
     while(len(contact.mobile_num)!=10){
        printf("Enter the correct mobile number:");
        scanf("%lld",&contact.mobile_num);}
    int flag=0;
    printf("Want to enter email id:\n");
    printf("Enter yes or no\n");
    scanf("%s",&check);
    if(strcmp(check,"yes")==0)
    {
     printf("Enter the email:");
    scanf("%s",&contact.email);
    printf("email modified\n");
    }
    else
    {
       printf("email not modified\n");

    }
    printf("Want to enter profession :\n");
    printf("Enter yes or no\n");
    scanf("%s",check);
    if(strcmp(check,"yes")==0)
    {
    clean_stdin();
   printf("Enter the profession:");
    scanf("%[^\n]s",contact.profession);
    printf("profession modified\n");
    }
    else
    {
        printf("profession not modified\n");
    }
    printf("Want to enter address:\n");
    printf("Enter yes or no\n");
    scanf("%s",check);
    if(strcmp(check,"yes")==0)
    {
    clean_stdin();
    printf("Enter the address:");
    scanf("%[^\n]s",contact.address);
    printf("address modified\n");
    }
    else
    {
        printf("address not modified\n");
    }
    }
    else
    {
    printf("No match found");
    }
    fseek(fp,-size,1);
    fwrite(&contact,sizeof(contact),1,fp);
}
void del(FILE *fp){
FILE *tmp;
    char name_1[50];
    clean_stdin();
    printf("Enter the name whose contact details to be deleted:");
    scanf("%[^\n]s",&name_1);
    if(search(fp,name_1)==0)
    {return;}
    tmp=fopen("tmp.txt","wb");
    if(tmp==NULL)
    {
        printf("Error in opening file\n");
        exit(0);
    }
    rewind(fp);
    while(fread(&contact,sizeof(contact),1,fp)==1)
    {if(strcmp(name_1,contact.name)!=0)
        {fwrite(&contact,sizeof(contact),1,tmp);
        }
    }
    printf("Record deleted successfully");
    fclose(fp);
    fclose(tmp);
    remove("hello.txt");
    rename("temp.txt","hello.txt");
    fp=fopen("temp.txt","rb+");
}
void backup(FILE *fp)
{
    FILE *bp;
    char bpfile[40];
    printf("Enter the file name for copying the record\n");
    clean_stdin();
    gets(bpfile);
    bp=fopen(bpfile,"wb");
    if(bp==NULL)
    {
        printf("Error in opening file\n");
    }
    rewind(fp);

    while(fread(&contact,sizeof(contact),1,fp)==1)
    {
            fwrite(&contact,sizeof(contact),1,bp);
    }
    printf("Backup successful\n");
    fclose(fp);
    fclose(bp);

}
