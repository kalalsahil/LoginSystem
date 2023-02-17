#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define Enter 13
#define Tab 9
#define BCKSPC 8

struct user
{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};

void takeinput(char ch[50])
{
    fgets(ch,50,stdin);
    ch[strlen(ch)-1]='\0';
}

char generateUsername(char email[50],char username[50])
{
    int i;
    for(i=0;i<strlen(email);i++)
    {
        if (email[i] == '@')
        {
            break;
        } 
        else 
        {
            username[i] = email[i];
        }
    }
    username[i]='\0';
}

void takepassword(char pwd[50])
{

    fgets(pwd,50,stdin);
}

int main()
{
    FILE *fp;
    int opt, usrFound = 0;
    struct user user;
    char password[50], password2[50],s[50];

    printf("\n\t\t\t\t------------Welcome to Login System------------");
    printf("\nPlease Choose your operation");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3.Exit");

    printf("\n\nEnter your choice:\t");
    scanf("%d",&opt);
    fgetc(stdin);

    switch(opt)
    {
    case 1:
    {
        system("cls");
        printf("\nEnter your full name:\t");
        takeinput(user.fullName);
        printf("\nEnter your email:\t");
        takeinput(user.email);
        printf("\nEnter your contact number:\t");
        takeinput(user.phone);
        printf("\nEnter your password:\t");
        takepassword(user.password);
        printf("Confirm your password: \t");
        takepassword(password2);

        if (!strcmp(user.password,password2))
        {
            generateUsername(user.email,user.username);
            fp = fopen("Users.dat","a+");
            fwrite(&user,sizeof(struct user),1,fp);
            if (fwrite != 0)
            {
                printf("\nUser registration success, Your username is %s",user.username);
            }
            else
            {
                printf("\n\nSorry something went wrong:(");
            }
            fclose(fp);
 
        }
        else
        {
            printf("\nPassword do not match");
            Beep(750,300);
        }
        break;
    }
    case 2:
    {
        system("cls");
        char username[50],pword[50];
        struct user usr;
        printf("\nEnter your username:\t");
        takeinput(username);
        printf("\nEnter your password:\t");
        takepassword(pword);

        fp=fopen("Users.dat","r");
        while(fread(&usr,sizeof(struct user),1,fp))
        {
            if (!strcmp(usr.username,username))
            {
                if (!strcmp(usr.password,pword))
                {
                    system("cls");
                    printf("\n\t\t\t\t\t\tWelcome %s",usr.fullName);
                    printf("\n\n|Full Name:\t%s",usr.fullName);
                    printf("\n|Email:\t\t%s",usr.email);
                    printf("\n|Username:\t%s",usr.username);
                    printf("\n|Contact number:\t%s",usr.phone); 
                }
                else
                {
                    printf("\n\nInvalid password!");
                    Beep(800,300);
                }
                usrFound = 1;
            }
        }
        if (!usrFound)
        {
            printf("User is not registered!");
            Beep(800,300);
        }
        fclose(fp);
        break;
    }
    case 3:
    {
        system("cls");
        printf("\t\t\tbye bye");
    }
    }
    return 0;
}