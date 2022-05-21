#include "Report.h"
#include "direct.h"
#include <sys/types.h> //open
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h> //waitpid
#include <unistd.h>   // fork
// char notDone[50] " NOT-VACCINATED";
char notDone[] = " NOT-VACCINATED\n";

// char notDone[50] " NOT-VACCINATED";

char *totalList()
{
    char *Filename;
    Filename = (char *)malloc(100 * sizeof(char));
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    printf("Enter the name for the list you want to create: ");
    fgets(Filename, 100, stdin);
    Filename[strlen(Filename) - 1] = 'D';
    Filename[strlen(Filename)] = 'B';
    strcat(Filename, ".txt");
    printf("%s", Filename);
    FILE *fp = fopen(Filename, "w");
    fclose(fp);
    printf("Enter the data that you want to store: ");
    int i;
    do
    {
        addtoFile(Filename);
        printf("Please enter: \n");
        printf("0.exit\n");
        printf("1.Enter more data\n\n");
        scanf("%d", &i);
    } while (i != 0);
    return Filename;
}

int DisplayFiles()
{
    int temp;
    printf("/---------------Vaccination_Report------------------*\n");
    printf("What would you like to do?\n");
    printf("0.Exit\n");
    printf("1.Select a file from the database\n");
    printf("2.Create a new list\n\n");
    printf("/---------------------------------*\n");
    scanf("%d", &temp);
    system("clear");
    return temp;
}

int *countPatients(char *Filename, int *cnt2)
{
    FILE *fp = fopen(Filename, "r");
    struct Report *Data = findData(Filename);
    //if (Data == NULL) printf("File is Empty!\n"); return 0;
    int cnt = 0;
    int *list = (int *)malloc(sizeof(int) * Data[0].cnt);
    for (int i = 0; i < Data[0].cnt; i++)
    {
        if (!Data[i].vaccinated)
        {
            list[cnt] = i;
            cnt++;
        }
    }
    *cnt2 = cnt;
    return list;
}

int Displaymenu(char *Filename, int isThereFile)
{
    int temp;
    printf("/---------------------------------*\n");
    printf("Selected File: %s\nWhat would you like to do?\n", Filename);
    printf("0. Exit\n");
    printf("1. List all of the data in this file\n");
    printf("2. Modify the data on this file\n");
    printf("3. Add data to this file\n");
    printf("4. Launch vaccination bus\n");
    if (isThereFile)
    {
        printf("5. Delete Current file\n\n");
        printf("6. Return to previous menu\n");
    }
    printf("/---------------------------------*\n");
    scanf("%d", &temp);
    system("clear");
    return temp;
}
void readFile(char *Filename)
{
    int f;
    f = open(Filename, O_RDONLY);
    if (f < 0)
    {
        perror("Eroor");
        exit(1);
    }
    char c;
    printf("The data on this file:\n");
    while (read(f, &c, sizeof(c)))
    {
        printf("%c", c);
    }
    printf("\n");
}
struct Report *findData(char *Filename)
{
    FILE *fp = fopen(Filename, "r");
    if (fp == NULL)
    {
        perror("Error in Opening the file!");
        exit(1);
    }
    int LineBuffer = 100;
    char Line[LineBuffer];
    int cnt = 0;
    while (fgets(Line, LineBuffer, fp))
    {
        if (strlen(Line) > 5)
            cnt++;
    }
    struct Report *Data = (struct Report *)malloc(sizeof(struct Report) * cnt);
    fclose(fp);
    fp = fopen(Filename, "r");
    if (fp == NULL)
    {
        perror("Error in Opening the file!");
        exit(1);
    }
    printf("/--------------------------------------\n");
    //printf("The data on this file: \n");
    int i = 0, j = 0, nj = 0;
    while (fgets(Line, LineBuffer, fp))
    {
        j = 0;
        nj = 0;
        // //readName:
        while ((Line[j] >= 'A' && Line[j] <= 'Z') || (Line[j] >= 'a' && Line[j] <= 'z') || Line[j] == ' ')
        {
            Data[i].name[nj] = Line[j];
            nj++;
            j++;
        }
        Data[i].name[nj] = '\0';
        nj = 0;
        //readAge:
        while (Line[j] != '+')
        {
            Data[i].birth_year[nj] = Line[j];
            nj++;
            j++;
        }
        Data[i].birth_year[nj] = '\0';
        nj = 0;
        //phoneNumber:
        while ((Line[j] != 'N' && Line[j] != 'n') && (Line[j] != 'Y' && Line[j] != 'y'))
        {
            Data[i].phone_number[nj] = Line[j];
            nj++;
            j++;
        }
        Data[i].phone_number[nj] = '\0';
        nj = 0;
        //Yes,No:
        while (Line[j] != ' ')
        {
            Data[i].free[nj] = Line[j];
            nj++;
            j++;
        }
        Data[i].free[nj] = '\0';
        Data[i].cnt = cnt;
        while (Line[j] != '\0')
        {
            if (Line[j] == 'N' && Line[j + 1] == 'O')
            {
                Data[i].vaccinated = 0;
                break;
            }
            else
            {
                Data[i].vaccinated = 1;
            }
            j++;
        }
        i++;
    }
    printf("\n");
    fclose(fp);
    return Data;
}

void editFile(char *Filename)
{
    FILE *fp;
    struct Report *Data = findData(Filename);
    for (int i = 0; i < Data[0].cnt; i++)
    {
        printf("%d. %s%s%s%s%s", i, Data[i].name, Data[i].birth_year, Data[i].phone_number, Data[i].free, Data[i].vaccinated ? " VACCINATED" : notDone);
    }
    printf("\n/-------------------Input the number of the line you'd like to edit or remove: \n");
    printf("Index: ");
    int index;
    scanf("%d", &index);
    printf("/-------------------\nWould you like to edit or remove the selected line?\n");
    printf("1.Edit. \n");
    printf("2.Remove.\n");
    int choice;
    scanf("%d", &choice);
    char temp;
    //In case of exit, original file should not be deleted
    fp = fopen("temp.txt", "w");
    //Clear the buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    //Bool to check if all is good
    int goodAndWell = 0;
    switch (choice)
    {
    case 1:
        printf("Enter the new Data: \n");
        printf("Name: ");
        fseek(stdin, 0, SEEK_END);
        fgets(Data[index].name, 100, stdin);
        if (strlen(Data[index].name) > 0 && Data[index].name[strlen(Data[index].name) - 1] == '\n')
        {
            Data[index].name[strlen(Data[index].name) - 1] = '\0';
            Data[index].name[strlen(Data[index].name)] = ' ';
        }
        printf("Date of Birth: ");
        fgets(Data[index].birth_year, 100, stdin);
        if (strlen(Data[index].birth_year) > 0 && Data[index].birth_year[strlen(Data[index].birth_year) - 1] == '\n')
        {
            Data[index].birth_year[strlen(Data[index].birth_year) - 1] = '\0';
            Data[index].birth_year[strlen(Data[index].birth_year)] = ' ';
        }
        printf("Phone number(specifiy country code using +): ");
        fgets(Data[index].phone_number, 100, stdin);
        if (strlen(Data[index].phone_number) > 0 && Data[index].phone_number[strlen(Data[index].phone_number) - 1] == '\n')
        {
            Data[index].phone_number[strlen(Data[index].phone_number) - 1] = '\0';
            Data[index].phone_number[strlen(Data[index].phone_number)] = ' ';
        }
        printf("eligeable for free vaccination? Yes/No: ");
        fgets(Data[index].free, 100, stdin);
        if (strlen(Data[index].free) > 0 && Data[index].free[strlen(Data[index].free) - 1] == '\n')
        {
            Data[index].free[strlen(Data[index].free) - 1] = '\0';
            Data[index].free[strlen(Data[index].free)] = ' ';
        }
        for (int i = 0; i < Data[0].cnt; i++)
        {
            if (Data[i].phone_number[0] == '+')
            {
                fprintf(fp, "%s%s%s%s%s", Data[i].name, Data[i].birth_year, Data[i].phone_number, Data[i].free, Data[i].vaccinated ? "VACCINATED\n" : notDone);
            }
            else
            {
                fprintf(fp, "%s%s+%s%s%s", Data[i].name, Data[i].birth_year, Data[i].phone_number, Data[i].free, Data[i].vaccinated ? "VACCINATED\n" : notDone);
            }
        }
        printf("Change successful!\n");
        goodAndWell = 1;
        break;
    case 2:
        for (int i = 0; i < Data[i].cnt; i++)
        {
            if (index == i)
            {
                continue;
            }
            else
            {
                fprintf(fp, "%s%s%s%s%s", Data[i].name, Data[i].birth_year, Data[i].phone_number, Data[i].free, Data[i].vaccinated ? "VACCINATED\n" : notDone);
            }
        }
        printf("Change successful!\n");
        goodAndWell = 1;
        break;
    default:
        printf("Invalid choice. Exiting program\n");
        break;
    }
    if (goodAndWell)
    {
        remove(Filename);
        if (rename("temp.txt", Filename))
        {
            printf("Blow up");
        }
    }
    fclose(fp);
}
void removeFile(char *Filename)
{
    int i;
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    printf("Are you sure you want to delete the selected file?\n");
    printf("1.Yes\n");
    printf("2.No\n");
    scanf("%d", &i);
    if (i == 1)
    {
        printf("Really?\n");
        scanf("%d", &i);
        if (i == 1)
        {
            remove(Filename);
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
}
void addtoFile(char *Filename)
{
    FILE *fp = fopen(Filename, "a");
    struct Report to_be_added;
    //Clear the buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    printf("Enter the new Data: \n");
    printf("Name: ");
    fseek(stdin, 0, SEEK_END);
    fgets(to_be_added.name, 100, stdin);
    if (strlen(to_be_added.name) > 0 && to_be_added.name[strlen(to_be_added.name) - 1] == '\n')
    {

        to_be_added.name[strlen(to_be_added.name) - 1] = '\0';
        to_be_added.name[strlen(to_be_added.name)] = ' ';
    }
    printf("Date of Birth: ");
    fgets(to_be_added.birth_year, 100, stdin);
    if (strlen(to_be_added.birth_year) > 0 && to_be_added.birth_year[strlen(to_be_added.birth_year) - 1] == '\n')
    {
        to_be_added.birth_year[strlen(to_be_added.birth_year) - 1] = '\0';
        to_be_added.birth_year[strlen(to_be_added.birth_year)] = ' ';
    }
    printf("Phone number(specifiy country code using +): ");
    fgets(to_be_added.phone_number, 100, stdin);
    if (strlen(to_be_added.phone_number) > 0 && to_be_added.phone_number[strlen(to_be_added.phone_number) - 1] == '\n')
    {
        to_be_added.phone_number[strlen(to_be_added.phone_number) - 1] = '\0';
        to_be_added.phone_number[strlen(to_be_added.phone_number)] = ' ';
    }
    printf("eligeable for free vaccination? Yes/No: ");
    fgets(to_be_added.free, 100, stdin);
    if (strlen(to_be_added.free) > 0 && to_be_added.free[strlen(to_be_added.free) - 1] == '\n')
    {
        to_be_added.free[strlen(to_be_added.free) - 1] = '\0';
        to_be_added.free[strlen(to_be_added.free)] = ' ';
    }
    to_be_added.vaccinated = 0;
    if (to_be_added.phone_number[0] == '+')
    {
        fprintf(fp, "%s%s%s%s%s\n", to_be_added.name, to_be_added.birth_year, to_be_added.phone_number, to_be_added.free, to_be_added.vaccinated ? "VACCINATED\n" : notDone);
    }
    else
    {
        fprintf(fp, "%s%s+%s%s%s\n", to_be_added.name, to_be_added.birth_year, to_be_added.phone_number, to_be_added.free, to_be_added.vaccinated ? "VACCINATED\n" : notDone);
    }

    printf("Successfully added!\n");
    return;
}

void File(char *myfile)
{
    int i;
    do
    {
        i = Displaymenu(myfile, 0);
        switch (i)
        {
        case 0:
            return;
            break;
        case 1:
            readFile(myfile);
            break;
        case 2:
            editFile(myfile);
            break;
        case 3:
            addtoFile(myfile);
            break;
        case 4:
            launchBus(myfile);
            break;
        default:
            break;
        }
    } while (i != 0);
}

void noFile(char *myfile)
{
    int i = DisplayFiles();
    if (i == 0)
    {
        exit(0);
    }
    else if (i == 1)
    {
        myfile = printDir();
    }
    else if (i == 2)
    {
        myfile = totalList();
    }
    else
    {
        while (i != 0 && i != 1)
        {
            printf("Invalid input.\n Enter again: ");
            scanf("%d", &i);
        }
        if (i == 0)
        {
            return;
        }
    }
    do
    {
        i = Displaymenu(myfile, 1);
        switch (i)
        {
        case 0:
            return;
            break;
        case 1:
            readFile(myfile);
            break;
        case 2:
            editFile(myfile);
            break;
        case 3:
            addtoFile(myfile);
            break;
        case 4:
            launchBus(myfile);
            break;
        case 5:
            removeFile(myfile);
        case 6:
            i = DisplayFiles();
            break;
        default:
            break;
        }
    } while (i != 0);
}

void handleSignleBus1(int signum)
{
    printf("FIRE UP BUS 1!\n");
    return;
}

void handleSignleBus2(int signum)
{
    printf("FIRE UP BUS 2!\n");
    return;
}
void launchBus(char *filename)
{
    int cnt;
    int *countOfPatients = countPatients(filename, &cnt);
    if (cnt > 4)
    {
        printf("Launching the busses!\n");
        int tempcnt;
        tempcnt = (cnt >= 10) ? 10 : 5;
        signal(SIGUSR1, handleSignleBus1);
        struct Report *Data = findData(filename);
        unlink("/tmp/doe1pq");
        int fd, fid = mkfifo("/tmp/doe1pq", S_IRUSR | S_IWUSR);
        if (fid == -1)
        {
            perror("Dumb!");
            exit(EXIT_FAILURE);
        }
        //Forking the proccess.
        pid_t bus1 = fork();
        if (bus1 < 0)
        {
            perror("Dumb!");
            exit(EXIT_FAILURE);
        }
        else if (bus1 > 1) // dada
        {
            pause(); // wait for signal from bus1
            printf("Sending Patients to the buses!\n");
            sleep(1);
            fd = open("/tmp/doe1pq", O_WRONLY);
            int five = 5;
            write(fd, &five, sizeof(int)); 
            for (int i = 0; i < 5; i++)
            {
                write(fd, &countOfPatients[i], sizeof(int));
            }
            close(fd); // Closing write descriptor
            printf("The operating commitee is done writing to bus 1!\n");
            if (tempcnt > 5)
            {
                sleep(3);
                printf("Launching bus 2!\n");
                signal(SIGUSR2, handleSignleBus2);
                unlink("/tmp/doe1pq2");
                int fd2, fid2 = mkfifo("/tmp/doe1pq2", S_IRUSR | S_IWUSR);
                if (fid2 == -1)
                {
                    perror("Dumb!");
                    exit(EXIT_FAILURE);
                }
                pid_t bus2 = fork();
                if (bus2 < 0)
                {
                    perror("Dumb!");
                    exit(EXIT_FAILURE);
                }
                else if (bus2 > 1)
                { // new dada
                    pause();
                    fd2 = open("/tmp/doe1pq2", O_WRONLY);
                    int five = 5;
                    write(fd2, &five, sizeof(int));
                    for (int i = 5; i < 10; i++)
                    {
                        write(fd2, &countOfPatients[i], sizeof(int));
                    }
                    close(fd2);
                    printf("The operating commitee is done writing to bus 2!\n");
                    sleep(4);
                    return;
                }
                else
                {
                    Data = findData(filename);
                    sleep(1);
                    kill(getppid(), SIGUSR2);
                    int cntwo;
                    fd = open("/tmp/doe1pq2", O_RDONLY);
                    read(fd, &cntwo, sizeof(int));
                    int list[cntwo];
                    read(fd, list, sizeof(int) * cntwo);
                    close(fd);
                    for (int i = 0; i < cntwo; i++)
                    {
                        int j = list[i];
                        srand(time(NULL));
                        int chance = (rand() % 10) <= 8;
                        if (chance)
                        {
                            printf("%s is going to be vaccinated in bus2!\n", Data[j].name);
                            Data[j].vaccinated = 1;
                        }
                        else
                        {
                            printf("%s arrived too late! He can't get the vaccine now!\n", Data[j].name);
                        }
                    }
                    modify_file(filename, Data);
                    exit(1);
                }
            }
            else
                printf("There is not enough people to launch bus 2!");
        }
        else
        { // Bus1 Process
            sleep(1);
            kill(getppid(), SIGUSR1);
            // close(pipefd[1]); //Usually we close the unused write end
            int cntwo;
            fd = open("/tmp/doe1pq", O_RDONLY);
            read(fd, &cntwo, sizeof(int));
            int list[cntwo];
            read(fd, list, sizeof(int) * cntwo);
            printf("bus1 is done recieving the patients!\n");
            close(fd);
            for (int i = 0; i < cntwo; i++)
            {
                int j = list[i];
                srand(time(NULL));
                int chance = (rand() % 10) <= 8;
                if (chance)
                {
                    printf("%s%s is going to be vaccinated in bus 1!\n", Data[j].name, Data[j].birth_year);
                    Data[j].vaccinated = 1;
                }
                else
                {
                    printf("%s%s arrived too late! He can't get the vaccine now!\n", Data[j].name, Data[j].birth_year);
                }
            }
            modify_file(filename, Data);
            // sleep(3);
            exit(1);
        }
    }
    else
    {
        printf("Not enough people in this database to start a bus!");
        return;
    }
}

void modify_file(const char *filename, struct Report *Data)
{
    FILE *fp;
    fp = fopen("temp.txt", "w");
    for (int i = 0; i < Data[0].cnt; i++)
    {
        // printf("%d\n",Data[i].vaccinated );
        fprintf(fp, "%s%s%s%s%s", Data[i].name, Data[i].birth_year, Data[i].phone_number, Data[i].free, Data[i].vaccinated ? " VACCINATED\n" : notDone);
    }
    fclose(fp);
    remove(filename);
    if (rename("temp.txt", filename))
    {
        printf("Blow up");
    }
}