#include <stdio.h>
#include "Banking.h"

int main()
{
    int work, login_id;

login:

    menu_login();
    scanf("%d", &work);

    if (work == 1)
    {
    login_owner:

        login_id = owner_login();
        // printf("login id :- %d",login_id);
        if (login_id)
        {
            printf("\n\n__________________login successfully__________________\n\n");

        owner_menu:

            menu_owner();
            scanf("%d", &work);

            if (work == 1)
            {
                Create_new_account(login_id);
                goto owner_menu;
            }
            else if (work == 2)
            {
                deposit(login_id);
                goto owner_menu;
            }
            else if (work == 3)
            {
                withdraw(login_id);
                goto owner_menu;
            }
            else if (work == 4)
            {
                info_customer();
                goto owner_menu;
            }
            else if (work == 5)
            {
                entries();
                goto owner_menu;
            }
            else if (work == 6)
            {
                edit_info_customer();
                goto owner_menu;
            }
            else if (work == 7)
            {
                close_account(login_id);
                goto owner_menu;
            }
            else if (work == 8)
            {
                list_customer();
                goto owner_menu;
            }
            else if (work == 9)
            {
                list_ex_customer();
                goto owner_menu;
            }
            else if (work == 10)
            {
                entries_ex();
                goto owner_menu;
            }
            else if (work == 11)
            {
                list_employee();
                goto owner_menu;
            }
            else if (work == 12)
            {
                add_employee();
                goto owner_menu;
            }
            else if (work == 13)
            {
                remove_employee();
                goto owner_menu;
            }
            else if (work == 14)
            {
                change_password_fo_employee_by_owner();
                goto owner_menu;
            }
            else if (work == 15)
            {
                change_password_of_owner();
                goto login;
            }
            else if (work == 16)
            {
                goto login;
            }
            else
            {
                printf("\n\nEnter correct inpute");
                goto owner_menu;
            }
        }
        else
        {
            if (wrong_password())
            {
                goto login;
            }
            else
            {
                goto login_owner;
            }
        }
    }
    else if (work == 2)
    {

    login_employee:

        login_id = employee_login();
        printf("login id :- %d", login_id);

        if (login_id)
        {
            printf("\n\n__________________login successfully__________________\n\n");

        employee_menu:

            menu_employee();
            scanf("%d", &work);

            if (work == 1)
            {
                Create_new_account(login_id);
                goto employee_menu;
            }
            else if (work == 2)
            {
                deposit(login_id);
                goto employee_menu;
            }
            else if (work == 3)
            {
                withdraw(login_id);
                goto employee_menu;
            }
            else if (work == 4)
            {
                info_customer();
                goto employee_menu;
            }
            else if (work == 5)
            {
                entries();
                goto employee_menu;
            }
            else if (work == 6)
            {
                edit_info_customer();
                goto employee_menu;
            }
            else if (work == 7)
            {
                close_account(login_id);
                goto employee_menu;
            }
            else if (work == 8)
            {
                list_customer();
                goto employee_menu;
            }
            else if (work == 9)
            {
                list_ex_customer();
                goto employee_menu;
            }
            else if (work == 10)
            {
                entries_ex();
                goto employee_menu;
            }
            else if (work == 11)
            {
                change_password_fo_employee_by_self(login_id);
                goto login;
            }
            else if (work == 12)
            {
                goto login;
            }
            else
            {
                printf("\n\nEnter correct inpute");
                goto employee_menu;
            }
        }
        else
        {
            goto login;
        }
    }
    else if (work == 3)
    {

        printf("\n\n___________________exat successfully__________________\n\n");
        return 143;
    }
    else
    {
        printf("\n\nEnter correct inpute");
        goto login;
    }
}