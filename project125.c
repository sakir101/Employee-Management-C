#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int x, i=1, i1=1, i2=1; //x=Taking total number of employee
char id1[20];
char username[20]="Management";
int password=1234;
char u[20];
int p;
int x1, j=1;
int position, total=0;


typedef struct Emplyee //Declaring a structure to store employee detail
{
    //properties of employee
    char id[20];
    char name[20];
    int age;
    int contact_number;
    float salary;
    struct Emplyee *next; //storing address part of link-list
} node;

node *newnode=NULL,  *temp, *temp1;

void menu2() //Login part
{
    printf("For Login\n");
    printf("Enter Username: ");
    gets(u);
    printf("Enter Password: ");
    scanf("%d",&p);
    if(strcmp(strlwr(username), strlwr(u))==0 && password==p)
    {
        return;
    }
    else
    {
        printf("Username or Password is incorrect\n");
        getchar();
        menu2();
    }
}


int design() //intro part
{
    printf("\t\t\t\t|--------------------------------------------------|\n");
    printf("\t\t\t\t|\t\tWELCOME TO OUR PROJECT\t\t   |\n");
    printf("\t\t\t\t|--------------------------------------------------|\n");
    printf("\t\t\t\t|--------------------------------------------------|\n");
    printf("\t\t\t\t|\t\tCREATED BY                         |\n\n");
    printf("\t\t\t\t|\t1.Israt Jahan(203-15-3858)                 |\n\n");
    printf("\t\t\t\t|\t2.Ajijul Hoque(183-15-2320)                |\n\n");
    printf("\t\t\t\t|\t3.Nusrat Faruqi(203-15-3885)               |\n\n");
    printf("\t\t\t\t|\t4.Afjal Hossain Shenam(203-15-3859)        |\n\n");
    printf("\t\t\t\t|\t5.Sakir Hossain Faruque(203-15-3862)       |\n\n");
    printf("\t\t\t\t|\t6.Abdul Fattah Mujtabir Samin(203-15-3880) |\n\n");
    printf("\t\t\t\t|--------------------------------------------------|\n\n");
}


int menu() //giving options to user
{
    printf("\t\t\t\t##########################################\n");
    printf("\t\t\t\t####       EMPLOYEE MANAGEMENT        ####\n");
    printf("\t\t\t\t##########################################\n");
    printf("\t\t\t\t#### 1. Add Employee                  ####\n");
    printf("\t\t\t\t#### 2. Add New Employee              ####\n");
    printf("\t\t\t\t#### 3. Display Employees             ####\n");
    printf("\t\t\t\t#### 4. Search an Employee            ####\n");
    printf("\t\t\t\t#### 5. Update data of an Employee    ####\n");
    printf("\t\t\t\t#### 6. Remove an Employee            ####\n");
    printf("\t\t\t\t#### 7. Exit                          ####\n");
    printf("\t\t\t\t##########################################\n");
    printf("\t\t\t\tReply: ");
}

//insert section
void addEmployee() //insert employee list continuously
{
    FILE *fp;
    fp=fopen("data management.bin", "ab");
    while(i<=x)
    {
        printf("Employee Number: %d\n",i);
        newnode=(node *)malloc(sizeof(node));
        getchar();
        printf("#### Name: "); //insert data of an employee
        gets(newnode->name);
        printf("#### ID: ");
        gets(newnode->id);
        printf("#### Age: ");
        scanf("%d",&newnode->age);
        printf("#### Contact Number: ");
        scanf("%d",&newnode->contact_number);
        printf("#### Salary: ");
        scanf("%f",&newnode->salary);
        printf("##########################################\n");
        printf("##########################################\n");
        newnode->next=NULL;
        fwrite(newnode, sizeof(*newnode), 1, fp); //data store in file
        i++;
    }

    i=1;
    x=0;
    fclose(fp);
    return;
}


void add_in_first() //add employee at first position in linked list
{
    FILE *fp, *fp1;
    fp=fopen("data management.bin", "rb");
    fp1=fopen("data management1.bin", "wb");
    node *temp2, *temp3;
    temp2=(node *)malloc(sizeof(node));
    temp3=(node *)malloc(sizeof(node));
    while(j<=x1) //Total Employee Number=x1
    {
        //Employee information
        getchar();
        printf("#### Name: ");
        gets(temp2->name);
        printf("#### ID: ");
        gets(temp2->id);
        printf("#### Age: ");
        scanf("%d",&temp2->age);
        printf("#### Contact Number: ");
        scanf("%d",&temp2->contact_number);
        printf("#### Salary: ");
        scanf("%f",&temp2->salary);
        printf("##########################################\n");
        printf("##########################################\n");
        temp2->next=NULL;
        fwrite(temp2, sizeof(*temp2), 1, fp1); //data store in file
        j++;
    }
    j=1;
    x1=0;
    while(fread(temp2, sizeof(*temp2), 1, fp)==1) //data read from file
    {
        fwrite(temp2, sizeof(*temp2), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    remove("data management.bin");
    rename("data management1.bin", "data management.bin");
}


void add_in_position() //insert employee at position in linked list
{
    int j1=1;
    printf("Which Position Do You Want To Insert? ");
    scanf("%d",&position);
    if(position<=1 || position>=total)
    {
        printf("\nInvalid Position\n");
        add_in_position();
        return;
        getchar();
    }
    FILE *fp, *fp1;
    fp=fopen("data management.bin", "rb");
    fp1=fopen("data management1.bin", "wb");
    node *temp2, *temp3;
    temp2=(node *)malloc(sizeof(node));
    temp3=(node *)malloc(sizeof(node));
    while(fread(temp3, sizeof(*temp3), 1, fp)==1)
    {
        if(j1==position)
        {
            //employee information
            getchar();
            printf("#### Name: ");
            gets(temp2->name);
            printf("#### ID: ");
            gets(temp2->id);
            printf("#### Age: ");
            scanf("%d",&temp2->age);
            printf("#### Contact Number: ");
            scanf("%d",&temp2->contact_number);
            printf("#### Salary: ");
            scanf("%f",&temp2->salary);
            printf("##########################################\n");
            printf("##########################################\n");
            temp2->next=NULL;
            fwrite(temp2, sizeof(*temp2), 1, fp1);
            fwrite(temp3, sizeof(*temp3), 1, fp1);
        }
        else
        {
            fwrite(temp3, sizeof(*temp3), 1, fp1);
        }
        j1++;
    }
    fclose(fp);
    fclose(fp1);
    remove("data management.bin");
    rename("data management1.bin", "data management.bin");
    total=0;
}

//employee display in console
void displayEmployees()
{
    FILE *fp;
    temp1=(node *)malloc(sizeof(node));
    fp=fopen("data management.bin", "rb");
    if(fp==NULL)
    {
        printf("File is empty!");
        exit(1);
    }
    else
    {
        //employee information
        printf("\n\n                                         All Employee Details                    \n");
        printf("-----------------------------------------------------------------------------------\n");
        printf("| SL No  | Name               | ID       | Age    | Phone Number   | Salary        |\n");
        printf("-----------------------------------------------------------------------------------\n");
        while(fread(temp1, sizeof(*temp1), 1, fp)==1)
        {
            printf("|%-8d",i1);
            printf("|%-20s",temp1->name);
            printf("|%-10s",temp1->id);
            printf("|%-8d",temp1->age);
            printf("|0%-15d",temp1->contact_number);
            printf("|%-15f|\n",temp1->salary);
            printf("-----------------------------------------------------------------------------------\n");
            i1++;
        }
    }
    i1=1;
    fclose(fp);
}


void searchEmployee() //search an employee from file
{
    FILE *fp;
    fp=fopen("data management.bin", "rb");
    node *temp2;
    temp2=(node *)malloc(sizeof(node));
    printf("Enter ID: ");
    gets(id1);
    if(fp==NULL)
    {
        printf("File is empty!");
        exit(1);
    }
    else
    {
        while(fread(temp2, sizeof(*temp2), 1, fp)==1)
        {
            if(strcmp(temp2->id, id1)==0)
            {
                //employee information
                printf("\n\n                                         The Employee Details                    \n");
                printf("-----------------------------------------------------------------------------------\n");
                printf("| SL No  | Name               | ID       | Age    | Phone Number   | Salary        |\n");
                printf("-----------------------------------------------------------------------------------\n");
                printf("|%-8d",i2);
                printf("|%-20s",temp2->name);
                printf("|%-10s",temp2->id);
                printf("|%-8d",temp2->age);
                printf("|0%-15d",temp2->contact_number);
                printf("|%-15f|\n",temp2->salary);
                return;
            }
        }
        if(strcmp(temp2->id, id1)!=0)
        {
            printf("Data Not Found!");
        }
    }
    fclose(fp);
}


void updateEmployee() //update information of an employee in data management file
{
    FILE *fp;
    fp=fopen("data management.bin", "rb");
    printf("Enter ID: ");
    gets(id1);
    node *temp2;
    temp2=(node *)malloc(sizeof(node));
    if(fp==NULL)
    {
        printf("File is empty!");
        exit(1);
    }
    else
    {
        while(fread(temp2, sizeof(*temp2), 1, fp)==1)
        {
            if(strcmp(temp2->id, id1)==0)
            {
                //Employee information
                printf("\n\n                                         The Employee Details                    \n");
                printf("-----------------------------------------------------------------------------------\n");
                printf("| SL No  | Name               | ID       | Age    | Phone Number   | Salary        |\n");
                printf("-----------------------------------------------------------------------------------\n");
                printf("|%-8d",i2);
                printf("|%-20s",temp2->name);
                printf("|%-10s",temp2->id);
                printf("|%-8d",temp2->age);
                printf("|0%-15d",temp2->contact_number);
                printf("|%-15f|\n",temp2->salary);
                int x;
                printf("Do you really want to change: 1. Yes 2.No: ");
                scanf("%d",&x);
                if(x==1)
                {
                    fclose(fp);
                    updated();
                    return;
                }
                else
                {
                    fclose(fp);
                    return;
                }
            }
        }
        if(strcmp(temp2->id, id1)!=0)
        {
            printf("Data Not Found!");
            fclose(fp);
        }
    }

}


void updated() //update information of an employee in data management file
{
    FILE *fp, *fp1;
    fp=fopen("data management.bin", "rb");
    fp1=fopen("data management1.bin", "wb");
    node *temp2;
    temp2=(node *)malloc(sizeof(node));

    char name1[20];
    char id2[20];
    int age1;
    int contact_number1;
    float salary1;
    while(fread(temp2, sizeof(*temp2), 1, fp)==1)
    {
        if(strcmp(temp2->id, id1)==0)
        {
            while(1)
            {
                int x1;
                printf("1.Update Name\n");
                printf("2.Update ID\n");
                printf("3.Update Age\n");
                printf("4.Update Contact Number\n");
                printf("5.Update Salary\n");
                printf("6.Break\n");
                scanf("%d",&x1);
                getchar();
                if(x1==1)
                {
                    printf("Enter New Name: ");
                    gets(name1);
                    strcpy(temp2->name, name1);
                }
                else if(x1==2)
                {
                    printf("Enter New ID: ");
                    gets(id2);
                    strcpy(temp2->id, id2);
                }
                else if(x1==3)
                {
                    printf("Enter New Age: ");
                    scanf("%d",&age1);
                    temp2->age=age1;
                }
                else if(x1==4)
                {
                    printf("Enter New Contact Number: ");
                    scanf("%d",&contact_number1);
                    temp2->contact_number=contact_number1;
                }
                else if(x1==5)
                {
                    printf("Enter New Salary: ");
                    scanf("%f",&salary1);
                    temp2->salary=salary1;
                }
                else
                {
                    printf("Data Updated Successfully!");
                    break;
                }
            }
            fwrite(temp2, sizeof(*temp2), 1, fp1); //insert data in data management1 file
        }
        else
        {
            fwrite(temp2, 1, sizeof(*temp2),  fp1); //insert data in data management1 file
        }
    }

    fclose(fp);
    fclose(fp1);
    remove("data management.bin");
    rename("data management1.bin", "data management.bin");
}


void removeEmployee() //remove an employee from file
{
    FILE *fp;
    fp=fopen("data management.bin", "rb");
    int key;
    node *temp2;
    temp2=(node *)malloc(sizeof(node));
    printf("Enter ID For That Employee: ");
    gets(id1);
    if(fp==NULL)
    {
        printf("File is empty!");
        exit(1);
    }
    else
    {
        while(fread(temp2, sizeof(*temp2), 1, fp)==1)
        {
            if(strcmp(temp2->id, id1)==0)
            {
                //Employee information
                printf("\n\n                                         The Employee Details                    \n");
                printf("-----------------------------------------------------------------------------------\n");
                printf("| SL No  | Name               | ID       | Age    | Phone Number   | Salary        |\n");
                printf("-----------------------------------------------------------------------------------\n");
                printf("|%-8d",i2);
                printf("|%-20s",temp2->name);
                printf("|%-10s",temp2->id);
                printf("|%-8d",temp2->age);
                printf("|0%-15d",temp2->contact_number);
                printf("|%-15f|\n",temp2->salary);
                printf("For Delete Type 1: ");
                scanf("%d",&key);
                getchar();
                if(key==1)
                {
                    printf("Data Removed Successfully!");
                    fclose(fp);
                    removeddata();

                    return;
                }
                else
                {
                    fclose(fp);
                    return;
                }
            }
        }
        if(strcmp(temp2->id, id1)!=0)
        {
            printf("Data Not Found!");
            fclose(fp);
        }
    }
}


void removeddata() //remove an employee from file
{
    FILE *fp, *fp1;
    fp=fopen("data management.bin", "rb");
    fp1=fopen("data management1.bin", "wb");
    node *temp2;
    temp2=(node *)malloc(sizeof(node));
    while(fread(temp2, sizeof(*temp2), 1, fp)==1)
    {
        if(strcmp(temp2->id, id1)!=0)
        {
            fwrite(temp2, sizeof(*temp2), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("data management.bin");
    rename("data management1.bin", "data management.bin");
    return;
}


int main()
{
    int n;
    int q;
    system("cls");
    design();
    getchar();
    system("cls");
    menu2();
    getchar();
    while(1)
    {
        system("cls");
        menu();
        scanf("%d",&n);
        getchar();
        system("cls");
        switch(n)
        {
        case 1:
            printf("##########################################\n");
            printf("####          ADD EMPLOYEE            ####\n");
            printf("##########################################\n");
            printf("Enter total number of employee: ");
            scanf("%d",&x);
            addEmployee();
            break;
        case 2:

            printf("##########################################\n");
            printf("####          ADD NEW EMPLOYEE            ####\n");
            printf("##########################################\n");
            printf("Select one\n");
            printf("1. Add in First\n");
            printf("2. Add in Position\n");
            printf("3. Add in Last\n");
            printf("Reply: ");
            scanf("%d",&q);
            if(q==1)
            {
                system("cls");
                printf("Enter Total Number of Employee: ");
                scanf("%d",&x1);
                add_in_first();
                getchar();
            }
            else if(q==2)
            {
                system("cls");
                FILE *fp;
                fp=fopen("data management.bin", "rb");
                node *temp2;
                temp2=(node *)malloc(sizeof(node));
                while(fread(temp2, sizeof(*temp2), 1, fp)==1)
                {
                    total++;
                }
                printf("\nTotal Employee Number: %d\n",total);
                fclose(fp);
                add_in_position();
                getchar();
            }
            else if(q==3)
            {
                system("cls");
                printf("Enter Total Number of Employee: ");
                scanf("%d",&x);
                addEmployee();
                getchar();
            }
            break;
        case 3:
            printf("##########################################\n");
            printf("####       DISPLAY EMPLOYEES          ####\n");
            printf("##########################################\n");
            displayEmployees();
            getchar();
            break;
        case 4:
            printf("##########################################\n");
            printf("####       SEARCH EMPLOYEE BY ID      ####\n");
            printf("##########################################\n");
            searchEmployee();
            getchar();
            break;
        case 5:
            printf("##########################################\n");
            printf("####       UPDATE EMPLOYEE DATA      ####\n");
            printf("##########################################\n");
            updateEmployee();
            getchar();
            break;
        case 6:
            printf("##########################################\n");
            printf("####       REMOVE AN EMPLOYEE     ####\n");
            printf("##########################################\n");
            removeEmployee();
            getchar();
            break;
        case 7:
            exit(0);
            getchar();
            break;
        default:
            printf("Invalid Input\n");
            getchar();
            break;
        }
    }
}


