#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct Person
{
    char name[30];
    unsigned int age;
    char job[30];
} Person;

Person** iterator;
int size = 10;
int regesterd_persons = 0;

void person_addition(char *person_name, int person_age, char *new_person_job)
{
    if (size <= regesterd_persons)
    {
        size += 5;
        iterator = realloc(iterator, size * sizeof(Person));

        for (int i = regesterd_persons; i < size; i++)
        {
            iterator[i] = malloc(sizeof(Person));
        }
    }

    strcpy(iterator[regesterd_persons]->name,person_name);
    strcpy(iterator[regesterd_persons]->job, new_person_job);
    iterator[regesterd_persons]->age = person_age;
    regesterd_persons++;
}

bool Exiting_item(char input)
{
    char exsistint_operation[4] = {'A', 'X', 'L', 'D'};
    for (int i = 0; i < 4; i++)
    {
        if (input == exsistint_operation[i])
            return true;
    }
    return false;
}

void database_listing()
{
    for (int i = 0; i < regesterd_persons; i++)
    {
        printf("Name: %s        Age: %u        Job: %s \n\n", iterator[i]->name, iterator[i]->age, iterator[i]->job);
    }
}


void deleting_person(int Index)
{
    regesterd_persons--;

    for (int i = 0; i < regesterd_persons; i++)
    {
        if (i >= Index)
        {
            strcpy(iterator[i]->name, iterator[i + 1]->name);
            iterator[i]->age = iterator[i + 1]->age;
            strcpy(iterator[i]->job, iterator[i + 1]->job);
        }

     
    }

    if (size - regesterd_persons >= 5 && size > 10)
    {
        for (int i = size - 1; i > regesterd_persons; i--)
        {
            free(iterator[i]);
        }

        size -= 5;

        iterator = (Person **)realloc(iterator, size * (sizeof(Person *)));
    }
}


void Exit_program()
{

    for (int i = 0; i > size; i++)
    {
        free(iterator[i]);
    }

    free(iterator);
    exit(0);
}


int main()
{
    iterator = (Person **)malloc(size * sizeof(Person *));
    
    for (int i = 0; i < size; i++)
    {
        iterator[i] = malloc(sizeof(Person));
    }

    bool exsist;

    /// INPUT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("-------------------------------------------------------------------------------------------------------------------------------\n");

    printf("The Menu: \n");
    printf("Click : \n");
    printf("- A:TO ADD A NEW PERSON TO THE DATABASE.\n");
    printf("- L:TO LIST THE DATABASE.\n");
    printf("- D:TO DELTE A PERSON FROM THE DATABASE.\n");
    printf("- X:TO EXIT FROM THE PROGRAM.\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------\n");

    char operation;
    do
    {
        do
        {
            printf("Select one of the item in the menu :  ");
            scanf(" %c", &operation);
            exsist = Exiting_item(operation);
            if (!(exsist))
            {
                printf("Invalid input! \n ");
                printf("-------------------------------------------------------------------------------------------------------------------------------\n");
                printf("The Menu: \n");
                printf("Click : \n");
                printf("- A:TO ADD A NEW PERSON TO THE DATABASE.\n");
                printf("- L:TO LIST THE DATABASE.\n");
                printf("- D:TO DELTE A PERSON FROM THE DATABASE.\n");
                printf("- X:TO EXIT FROM THE PROGRAM.\n");
                printf("-------------------------------------------------------------------------------------------------------------------------------\n");
            }
        } while (!(exsist));

        switch (operation)
        {
        case 'A':

            printf("Adding a new person :- \n");
            Person new_person;
            do
            {
                printf("Please enter the person's name : ");
                scanf("%s", new_person.name);
                if (strlen(new_person.name) > 30)
                {
                    printf("Invalid input,length of the word bigger than 30!\n");
                }

            } while (strlen(new_person.name) > 30);

            printf("Please enter the person's Age : ");
            scanf("%u", &new_person.age);
            unsigned int new_person_age = new_person.age;

            do
            {
                printf("Please enter the person's job : ");
                scanf("%s", new_person.job);
                if (strlen(new_person.job) > 30)
                {
                    printf("Invalid input,length of the word bigger than 30! \n");
                }
            } while (strlen(new_person.job) > 30);
            person_addition(new_person.name, new_person_age, new_person.job);


            printf("INFORMATION WERE SAVED SUCCESSFULLY\n");
            printf("--------------------------------------------------------------------------------------------------------------------------------\n");
            printf("There are already %d person(s) in the database \n", regesterd_persons);
            printf("The size of the  database now is %d  \n", size);

            break;

        case 'D':
        if (regesterd_persons == 0)
            {
                printf("The database is empty.\n\n");
            }
             printf("Please enter the name of the person you want to delete from the database: ");
                char temp_delName[30];
                scanf("%s", temp_delName);
                int Indexex = 0;
                while (Indexex < regesterd_persons && ((strcmp(temp_delName, iterator[Indexex]->name)) != 0))
                {
                    Indexex++;
                }
                if (Indexex >= regesterd_persons)
                {
                    printf("There is no such name, please check whether you entered an existing name.\n\n");
                }

                else
                {
                    printf("\n\n%s INFORMATIONS WERE DELETED SUCCESSFULLY.\n ", iterator[Indexex]->name);

                    deleting_person(Indexex);
                    printf("\n");
                }
            
            break;


        case 'L':
         if (regesterd_persons == 0)
            {
                printf("the database is empty.\n\n");
            }

            database_listing();

            break;

             case 'X':
            Exit_program();
     break;
        default:
            printf("WRONG Input!.\n\n");
        }

    } while (operation != 'X');

    return 0;
}