#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee
{
    int id;
    char password[9];
};

struct entries
{
    int id, accounter_id, deposit, withdraw, balance;
    char time[9], date[12];
};

struct customer
{
    int id, balance, creator_id;
    char name[40], mobile_number[11];
};

int wrong_password()
{

    int temp;

    printf("\n\nPassword is wrong \nEnter 0 for try again or enter nonzero value for back to home :- ");
    scanf("%d", &temp);

    return temp;
}

int wrong_id()
{

    int temp;

    printf("\n\nId is not exist \nEnter 0 for try again or enter nonzero value for back to home :- ");
    scanf("%d", &temp);

    return temp;
}

void copy_file(char file1[10], char file2[10])
{

    char c;
    FILE *f1, *f2;

    f1 = fopen(file1, "w");
    f2 = fopen(file2, "r");

    while (fread(&c, sizeof(char), 1, f2))
    {
        fwrite(&c, sizeof(char), 1, f1);
    }

    fclose(f1);
    fclose(f2);
}

int count_customer()
{

    struct customer customer;
    int count = 0;
    FILE *f;

    f = fopen("customer", "r");
    while (fread(&customer, sizeof(struct customer), 1, f))
    {
        count++;
    }

    return count;
}

int count_ex_customer()
{

    struct customer customer;
    int count = 0;
    FILE *f;

    f = fopen("ex_customer", "r");
    while (fread(&customer, sizeof(struct customer), 1, f))
    {
        count++;
    }

    return count;
}

void get_mobile_number(char *mobile_number)
{

    char *number;

input_number:
    number = mobile_number;

    printf("\nenter mobile number of customer :-");
    fscanf(stdin, "%s", number);

    for (int i = 0; i < 11; i++, number++)
    {
        if (i != 10 && *number == '\0')
        {
            printf("\nEnter 10 numbers");
            goto input_number;
        }

        if (i == 10 && *number != '\0')
        {
            printf("\nEnter only 10 numbers");
            goto input_number;
        }

        if (i != 10 && (*number < 48 || *number > 57))
        {
            printf("\nEnter only numbers (0 to 9)\n");
            goto input_number;
        }
    }

    return;
}

int get_positive_number(int category)
{

    int n;

input:
    scanf("%d", &n);
    if (n <= 0)
    {
        if (category == 1)
        {
            printf("\nenter greater then 0 for deposit money :-");
            goto input;
        }
        else if (category == -1)
        {
            printf("\nenter greater then 0 for withdraw money :-");
            goto input;
        }
    }
    //printf("n=%d",n);
    return n;
}

int check_id(int id)
{

    struct customer customer;
    FILE *f;

    f = fopen("customer", "r");

    while (fread(&customer, sizeof(struct customer), 1, f))
    {
        if (customer.id == id)
        {
            return 1;
        }
    }

    fclose(f);

    return 0;
}

int check_ex_id(int id)
{

    struct customer customer;
    FILE *f;

    f = fopen("ex_customer", "r");

    while (fread(&customer, sizeof(struct customer), 1, f))
    {
        if (customer.id == id)
        {
            return 1;
        }
    }

    fclose(f);

    return 0;
}

void menu_login()
{

    printf("\n\n_________________________Home_________________________\n");

    printf("\n1 :- Login as owner");
    printf("\n2 :- Login as employee");
    printf("\n3 :- exit");

    printf("\n\n______________________________________________________");

    printf("\n\nEnter number as your work :- ");
}

int owner_login()
{

    char password[9], t_password[9];
    FILE *f;

    // f = fopen("owner", "w");

    // char r[9]= "74857485";

    // fwrite(&r,sizeof(r),1,f);

    // fclose(f);

    printf("\nEnter password :-");
    fscanf(stdin, "%s", &t_password);

    f = fopen("owner", "r");

    fread(&password, sizeof(password), 1, f);

    fclose(f);

    if (!(strcmp(t_password, password)))
    {
        return 7485;
    }
    else
    {
        return 0;
    }
}

int employee_login()
{
    struct employee employee, t_employee;

    FILE *f = fopen("employee", "r");
input_id:
    printf("\nenter employee id :-");
    scanf("%d", &t_employee.id);

    while (fread(&employee, sizeof(struct employee), 1, f))
    {
        //printf("\nemployee.id = %d  t_employee.id = %d",employee.id,t_employee.id);

        if (employee.id == t_employee.id)
        {
        input_password:
            printf("enter password :-");
            fscanf(stdin, "%s", &t_employee.password);
            if (strcmp(t_employee.password, employee.password))
            {
                if (wrong_password())
                {
                    return 0;
                }
                else
                {
                    goto input_password;
                }
            }
            else
            {
                return employee.id;
            }
        }
    }
    if (wrong_id())
    {
        return 0;
    }
    else
    {
        goto input_id;
    }
}

void menu_employee()
{

    printf("\n\n_________________________Menu_________________________\n");

    printf("\n 1 :- Create new account");
    printf("\n 2 :- Deposit");
    printf("\n 3 :- Withdraw");
    printf("\n 4 :- Information about customer");
    printf("\n 5 :- Show entries of customer");
    printf("\n 6 :- Edit information of customer");
    printf("\n 7 :- Close account of customer");
    printf("\n 8 :- Show list of customer");
    printf("\n 9 :- Show list of ex customer");
    printf("\n10 :- Show entries of ex customer");
    printf("\n11 :- Change your password");
    printf("\n12 :- Logout");

    printf("\n\n______________________________________________________");

    printf("\n\nEnter number as your work :- ");
}

void menu_owner()
{

    printf("\n\n_________________________Menu_________________________\n");

    printf("\n 1 :- Create new account");
    printf("\n 2 :- Deposit");
    printf("\n 3 :- Withdraw");
    printf("\n 4 :- Information about customer");
    printf("\n 5 :- Show entries of customer");
    printf("\n 6 :- Edit information of customer");
    printf("\n 7 :- Close account of customer");
    printf("\n 8 :- Show list of customer");
    printf("\n 9 :- Show list of ex customer");
    printf("\n10 :- Show entries of ex customer");
    printf("\n11 :- Show list of employee");
    printf("\n12 :- Add employee");
    printf("\n13 :- Remove employee");
    printf("\n14 :- Change password of employee");
    printf("\n15 :- Change your password");
    printf("\n16 :- Logout");

    printf("\n\n______________________________________________________");

    printf("\n\nEnter number as your work :- ");
}

void list_employee()
{
    struct employee employee, t_employee;

    FILE *f = fopen("employee", "r");

    printf("\n\n___________________List of employee___________________\n");

    printf("\n\nID\tPassword\n");
    while (fread(&employee, sizeof(struct employee), 1, f))
    {
        printf("\n%d\t%s", employee.id, employee.password);
    }
    fclose(f);
}

void add_employee()
{

    char password[9], t_password[9];
    struct employee employee, t_employee;
    FILE *f;
    int temp;

    // f=fopen("employee","w");

    // struct employee emp={ 1 , "11111111" };

    // fwrite(&emp,sizeof(struct employee),1,f);

    // fclose(f);

input:

    printf("\nEnter id for employee :-");
    scanf("%d", &t_employee.id);

    f = fopen("employee", "r");

    while (fread(&employee, sizeof(struct employee), 1, f))
    {
        if (employee.id == t_employee.id || t_employee.id == 7485 || t_employee.id == 0)
        {
            printf("\nId is already exist \nEnter 0 for try again or enter nonzero value for back to menu:-");
            scanf("%d", &temp);
            if (temp)
            {
                return;
            }
            else
            {
                goto input;
            }
        }
    }

    fclose(f);

    printf("Enter password for new employee :-");
    fscanf(stdin, "%s", &t_employee.password);

owner_password:

    printf("\nEnter password of owner for add this employee :-");
    fscanf(stdin, "%s", &t_password);

    f = fopen("owner", "r");

    fread(&password, sizeof(password), 1, f);

    fclose(f);

    if (!(strcmp(t_password, password)))
    {
        f = fopen("employee", "a");

        fwrite(&t_employee, sizeof(struct employee), 1, f);

        fclose(f);
        printf("\n\n_______________Employee add successfully______________");
    }
    else
    {
        printf("\nPassword is wrong \nEnter 0 for try again or enter nonzero value for back to menu :- ");
        scanf("%d", &temp);
        if (temp)
        {
            return;
        }
        else
        {
            goto owner_password;
        }
    }
}

void remove_employee()
{

    FILE *f, *t_f;
    struct employee employee, t_employee;
    char password[9], t_password[9];
    int temp;

input:
    printf("\nEnter id of employee for remove :-");
    scanf("%d", &t_employee.id);

    f = fopen("employee", "r");

    while (fread(&employee, sizeof(struct employee), 1, f))
    {
        if (employee.id == t_employee.id)
        {
        password:
            printf("\nEnter password of owner for remove this employee :-");
            fscanf(stdin, "%s", &t_password);

            f = fopen("owner", "r");

            fread(&password, sizeof(password), 1, f);

            fclose(f);

            if (!(strcmp(t_password, password)))
            {
                f = fopen("employee", "r");
                t_f = fopen("temp", "w");

                while (fread(&employee, sizeof(struct employee), 1, f))
                {
                    if (employee.id != t_employee.id)
                    {
                        fwrite(&employee, sizeof(struct employee), 1, t_f);
                    }
                }

                fclose(t_f);
                fclose(f);

                copy_file("employee", "temp");

                printf("\n\n_____________Employee remove successfully_____________");
                return;
            }
            else
            {
                printf("\nPassword is wrong \nEnter 0 for try again or enter nonzero value for back to menu :- ");
                scanf("%d", &temp);
                if (temp)
                {
                    return;
                }
                else
                {
                    goto password;
                }
            }
        }
    }

    printf("\nId is not exist \nEnter 0 for try again or enter nonzero value for back to menu:-");
    scanf("%d", &temp);
    if (temp)
    {
        return;
    }
    else
    {
        goto input;
    }

    fclose(f);
}

void change_password_fo_employee_by_owner()
{

    FILE *f, *t_f;
    struct employee employee, t_employee;
    char password[9], t_password[9];
    int temp;

input:
    printf("\nEnter id of employee for change password :-");
    scanf("%d", &t_employee.id);

    f = fopen("employee", "r");

    while (fread(&employee, sizeof(struct employee), 1, f))
    {
        if (employee.id == t_employee.id)
        {

            printf("\nEnter new password :-");
            fscanf(stdin, "%s", &t_employee.password);

        password:
            printf("\nEnter password of owner for change password of this employee :-");
            fscanf(stdin, "%s", &t_password);

            f = fopen("owner", "r");

            fread(&password, sizeof(password), 1, f);

            fclose(f);

            if (!(strcmp(t_password, password)))
            {
                f = fopen("employee", "r");
                t_f = fopen("temp", "w");

                while (fread(&employee, sizeof(struct employee), 1, f))
                {
                    if (employee.id != t_employee.id)
                    {
                        fwrite(&employee, sizeof(struct employee), 1, t_f);
                    }
                    else
                    {
                        fwrite(&t_employee, sizeof(struct employee), 1, t_f);
                    }
                }

                fclose(t_f);
                fclose(f);

                copy_file("employee", "temp");

                printf("\n\n____________Password change successfully_____________");
                return;
            }
            else
            {
                printf("\nPassword is wrong enter 0 for try again or enter nonzero value for back to menu :- ");
                scanf("%d", &temp);
                if (temp)
                {
                    return;
                }
                else
                {
                    goto password;
                }
            }
        }
    }

    printf("\nId is not exist \nEnter 0 for try again or enter nonzero value for back to menu:-");
    scanf("%d", &temp);
    if (temp)
    {
        return;
    }
    else
    {
        goto input;
    }

    fclose(f);
}

void change_password_of_owner()
{

    int temp;
    char password[9], t_password[9];
    FILE *f;

old_password:

    printf("\nEnter courent password :-");
    fscanf(stdin, "%s", &t_password);

    f = fopen("owner", "r");

    fread(&password, sizeof(password), 1, f);

    fclose(f);

    if (!(strcmp(password, t_password)))
    {
    new_password:

        printf("\nEnter new password :-");
        fscanf(stdin, "%s", &t_password);
        printf("Enter new password again:-");
        fscanf(stdin, "%s", &password);

        if (!(strcmp(password, t_password)))
        {
            f = fopen("owner", "w");

            fwrite(&t_password, sizeof(t_password), 1, f);

            fclose(f);

            printf("\n\n____________Password change successfully_____________");
        }
        else
        {
            printf("\n\nPassword not match\nEnter 0 for try agein or enter nonzero value for back to menu:-");
            scanf("%d", &temp);
            if (temp)
            {
                return;
            }
            else
            {
                goto new_password;
            }
        }
    }
    else
    {
        printf("\nPassword is wrong \nEnter 0 for try again or enter nonzero value for back to menu :- ");
        scanf("%d", &temp);
        if (temp)
        {
            return;
        }
        else
        {
            goto old_password;
        }
    }
}

void change_password_fo_employee_by_self(int login_id)
{
    FILE *f, *t_f;
    struct employee employee, t_employee;

    t_employee.id = login_id;

    f = fopen("employee", "r");

    while (fread(&employee, sizeof(struct employee), 1, f))
    {
        if (employee.id == login_id)
        {
        old_password:
            printf("\nEnter courent password :-");
            fscanf(stdin, "%s", &t_employee.password);

            if (!(strcmp(t_employee.password, employee.password)))
            {
            new_password:

                printf("\nEnter new password :-");
                fscanf(stdin, "%s", &t_employee.password);
                printf("Enter new password again:-");
                fscanf(stdin, "%s", &employee.password);

                if (!(strcmp(t_employee.password, employee.password)))
                {
                    f = fopen("employee", "r");
                    t_f = fopen("temp", "w");

                    while (fread(&employee, sizeof(struct employee), 1, f))
                    {
                        if (employee.id != login_id)
                        {
                            fwrite(&employee, sizeof(struct employee), 1, t_f);
                        }
                        else
                        {
                            fwrite(&t_employee, sizeof(struct employee), 1, t_f);
                        }
                    }

                    fclose(t_f);
                    fclose(f);

                    copy_file("employee", "temp");

                    printf("\n\n____________Password change successfully_____________");
                    return;
                }
                else
                {
                    int temp;

                    printf("\n\nPassword not match\nEnter 0 for try agein or enter nonzero value for back to menu:-");
                    scanf("%d", &temp);
                    if (temp)
                    {
                        return;
                    }
                    else
                    {
                        goto new_password;
                    }
                }
            }
            else
            {
                if (wrong_password())
                {
                    return;
                }
                else
                {
                    goto old_password;
                }
            }
        }
    }
}

void Create_new_account(int login_id)
{
    FILE *f;
    char file[10], date[20], time[10];
    struct customer customer;

    printf("\nEnter name of customer :-");
    fscanf(stdin, "%s", &customer.name);

    get_mobile_number(customer.mobile_number);

    customer.id = count_customer() + count_ex_customer() + 1;

    customer.creator_id = login_id;

    printf("enter money for first deposit :-");

    customer.balance = get_positive_number(1);

    f = fopen("customer", "a");

    fwrite(&customer, sizeof(struct customer), 1, f);

    fclose(f);

    {
        itoa(customer.id, file, 10);

        f = fopen(file, "w");

        struct entries entrie;

        entrie.balance = customer.balance;
        entrie.accounter_id = login_id;
        strcpy(entrie.date, __DATE__);
        entrie.deposit = customer.balance;
        entrie.id = customer.id;
        strcpy(entrie.time, __TIME__);
        entrie.withdraw = 0;

        fwrite(&entrie, sizeof(struct entries), 1, f);

        fclose(f);
    }

    printf("\nThe ID of new customer :- %d", customer.id);

    printf("\n\n_______________Customer add successfully______________");
}

void list_customer()
{

    FILE *f;
    struct customer customer;

    f = fopen("customer", "r");

    printf("\n\n___________________List of customer___________________\n");

    while (fread(&customer, sizeof(struct customer), 1, f))
    {
        printf("\n           ID :- %d", customer.id);
        printf("\n         Name :- %s", customer.name);
        printf("\nMobile number :- %s", customer.mobile_number);
        printf("\n      Balance :- %d", customer.balance);
        printf("\n   Creator id :- %d", customer.creator_id);

        printf("\n\n_______________________________________________________\n");
    }

    fclose(f);
}

void deposit(int login_id)
{
    struct entries entrie;

input_id:

    printf("\nEnter id of customer for deposit :-");
    scanf("%d", &entrie.id);
    if (check_id(entrie.id))
    {
        printf("\nenter number for deposit money :-");
        entrie.deposit = get_positive_number(1);
        entrie.withdraw = 0;
        entrie.accounter_id = login_id;
        strcpy(entrie.date, __DATE__);
        strcpy(entrie.time, __TIME__);

        FILE *f, *t_f;
        struct customer customer;

        f = fopen("customer", "r");
        t_f = fopen("temp", "w");

        while (fread(&customer, sizeof(struct customer), 1, f))
        {
            if (customer.id != entrie.id)
            {
                fwrite(&customer, sizeof(struct customer), 1, t_f);
            }
            else
            {
                customer.balance = customer.balance + entrie.deposit;
                entrie.balance = customer.balance;

                fwrite(&customer, sizeof(struct customer), 1, t_f);
            }
        }

        fclose(t_f);
        fclose(f);

        copy_file("customer", "temp");

        char file[10];
        itoa(entrie.id, file, 10);

        f = fopen(file, "a");

        fwrite(&entrie, sizeof(struct entries), 1, f);

        fclose(f);
    }
    else
    {
        if (!(wrong_id()))
        {
            goto input_id;
        }
        else
        {
            return;
        }
    }
}

void withdraw(int login_id)
{
    struct entries entrie;

input_id:

    printf("\nEnter id of customer for withdraw :-");
    scanf("%d", &entrie.id);
    if (check_id(entrie.id))
    {
        FILE *f, *t_f;
        int balance;
        struct customer customer;

        f = fopen("customer", "r");

        while (fread(&customer, sizeof(struct customer), 1, f))
        {
            if (customer.id == entrie.id)
            {
                balance = customer.balance;
            }
        }

        fclose(f);

    input:
        printf("\nenter number for withdraw money :-");
        entrie.withdraw = get_positive_number(-1);

        if (balance >= entrie.withdraw)
        {
            entrie.deposit = 0;
            entrie.accounter_id = login_id;
            strcpy(entrie.date, __DATE__);
            strcpy(entrie.time, __TIME__);

            f = fopen("customer", "r");
            t_f = fopen("temp", "w");

            while (fread(&customer, sizeof(struct customer), 1, f))
            {
                if (customer.id != entrie.id)
                {
                    fwrite(&customer, sizeof(struct customer), 1, t_f);
                }
                else
                {
                    customer.balance = customer.balance - entrie.withdraw;
                    entrie.balance = customer.balance;

                    fwrite(&customer, sizeof(struct customer), 1, t_f);
                }
            }

            fclose(t_f);
            fclose(f);

            copy_file("customer", "temp");

            char file[10];
            itoa(entrie.id, file, 10);

            f = fopen(file, "a");

            fwrite(&entrie, sizeof(struct entries), 1, f);

            fclose(f);
        }
        else
        {
            int temp;

            printf("\nyour balance is not efficient for withdrwal");
            printf("\nEnter 0 for try again or enter nonzero value for back to menu :- ");
            scanf("%d", &temp);

            if (temp)
            {
                return;
            }
            else
            {
                goto input;
            }
        }
    }
    else
    {
        if (!(wrong_id()))
        {
            goto input_id;
        }
        else
        {
            return;
        }
    }
}

void info_customer()
{

    FILE *f;
    struct customer customer;
    int id;

input_id:

    printf("\nEnter id for get Information about customer :-");
    scanf("%d", &id);

    f = fopen("customer", "r");

    while (fread(&customer, sizeof(struct customer), 1, f))
    {

        if (customer.id == id)
        {
            printf("\n\n_______________________________________________________\n");

            printf("\n           ID :- %d", customer.id);
            printf("\n         Name :- %s", customer.name);
            printf("\nMobile number :- %s", customer.mobile_number);
            printf("\n      Balance :- %d", customer.balance);
            printf("\n   Creator id :- %d", customer.creator_id);

            printf("\n\n_______________________________________________________\n");
            return;
        }
    }
    if (wrong_id())
    {
        return;
    }
    else
    {
        goto input_id;
    }

    fclose(f);
}

void entries()
{

    FILE *f;
    struct entries entrie;
    int id;
    char file[10];

input_id:

    printf("\nEnter id for get entries of customer :-");
    scanf("%d", &id);

    f = fopen("customer", "r");

    if (check_id(id))
    {

        itoa(id, file, 10);
        f = fopen(file, "r");

        printf("\n\nDate\t\tTime\t\tDeposit\t\tWithdraw\tBalance\t\tAccounter id\n");
        while (fread(&entrie, sizeof(struct entries), 1, f))
        {
            printf("\n\n%s\t%s\t%d\t\t%d\t\t%d\t\t%d", entrie.date, entrie.time, entrie.deposit, entrie.withdraw, entrie.balance, entrie.accounter_id);
        }

        fclose(f);
    }

    else if (wrong_id())
    {
        return;
    }
    else
    {
        goto input_id;
    }

    fclose(f);
}

void edit_info_customer()
{
    int id, work;
    struct customer customer;
    FILE *f, *t_f;

input_id:
    printf("\nEnter id for edit information of customer :-");
    scanf("%d", &id);

    if (check_id(id))
    {
        f = fopen("customer", "r");
        t_f = fopen("temp", "w");

        while (fread(&customer, sizeof(struct customer), 1, f))
        {
            if (customer.id == id)
            {
            edit_menu:

                printf("\n\n______________________Edit menu______________________\n");

                printf("\n1 :- Edit name ");
                printf("\n2 :- Edit mobile numbr");
                printf("\n3 :- Edit both");
                printf("\n4 :- Back to menu");

                printf("\n\n_______________________________________________________");

                printf("\n\nEnter number as your work :- ");
                scanf("%d",&work);

                if (work == 1)
                {
                    printf("\nEnter new name of customer :-");
                    scanf("%s", &customer.name);

                    printf("\n_________________Edit name successfully_________________");

                   
                }
                else if (work == 2)
                {
                    get_mobile_number(customer.mobile_number);

                    printf("\n_____________Edit mobile number successfully_____________");

                   
                }
                else if (work == 3)
                {
                    printf("\nEnter new name of customer :-");
                    scanf("%s", &customer.name);
                    get_mobile_number(customer.mobile_number);
                }
                else if (work == 4)
                {
                   
                }
                else
                {
                    printf("\n\nEnter correct inpute");
                    goto edit_menu;
                }

                fwrite(&customer, sizeof(struct customer), 1, t_f);
            }
            else
            {

                fwrite(&customer, sizeof(struct customer), 1, t_f);
            }
        }

        fclose(t_f);
        fclose(f);

        copy_file("customer", "temp");
    }

    else if (wrong_id())
    {
        return;
    }
    else
    {
        goto input_id;
    }
}

void close_account(int login_id)
{

    int id;
    FILE *f, *t_f, *r_f;
    char file[10];
    struct customer customer;
    struct entries entrie;

input_id:
    printf("\nEnter id for close account of customer :-");
    scanf("%d", &id);

    if (check_id(id))
    {
        itoa(id, file, 10);

        entrie.accounter_id = login_id;
        entrie.balance = 0;
        strcpy(entrie.date, __DATE__);
        strcpy(entrie.time, __TIME__);
        entrie.deposit = 0;
        entrie.id = id;

        f = fopen("customer", "r");
        t_f = fopen("temp", "w");

        while (fread(&customer, sizeof(struct customer), 1, f))
        {
            if (customer.id == id)
            {
                r_f = fopen("ex_customer", "a");

                entrie.withdraw = customer.balance;

                printf("\nPay %d RS to customer\n", customer.balance);

                customer.balance = 0;

                fwrite(&customer, sizeof(struct customer), 1, r_f);

                fclose(r_f);
            }
            else
            {

                fwrite(&customer, sizeof(struct customer), 1, t_f);
            }
        }
        fclose(t_f);
        fclose(f);

        f = fopen(file, "a");

        fwrite(&entrie, sizeof(struct entries), 1, f);

        fclose(f);

        copy_file("customer", "temp");
    }

    else if (wrong_id())
    {
        return;
    }
    else
    {
        goto input_id;
    }
}

void list_ex_customer()
{

    FILE *f;
    struct customer customer;

    f = fopen("ex_customer", "r");

    printf("\n\n__________________List of ex customer__________________\n");

    while (fread(&customer, sizeof(struct customer), 1, f))
    {
        printf("\n           ID :- %d", customer.id);
        printf("\n         Name :- %s", customer.name);
        printf("\nMobile number :- %s", customer.mobile_number);
        printf("\n      Balance :- %d", customer.balance);
        printf("\n   Creator id :- %d", customer.creator_id);

        printf("\n\n_______________________________________________________\n");
    }

    fclose(f);
}

void entries_ex()
{

    FILE *f;
    struct entries entrie;
    int id;
    char file[10];

input_id:

    printf("\nEnter id for get entries of ex customer :-");
    scanf("%d", &id);

    f = fopen("ex_customer", "r");

    if (check_ex_id(id))
    {

        itoa(id, file, 10);
        f = fopen(file, "r");

        printf("\n\nDate\t\tTime\t\tDeposit\t\tWithdraw\tBalance\t\tAccounter id\n");
        while (fread(&entrie, sizeof(struct entries), 1, f))
        {
            printf("\n\n%s\t%s\t%d\t\t%d\t\t%d\t\t%d", entrie.date, entrie.time, entrie.deposit, entrie.withdraw, entrie.balance, entrie.accounter_id);
        }

        fclose(f);
    }
    else if (wrong_id())
    {
        return;
    }
    else
    {
        goto input_id;
    }

    fclose(f);
}