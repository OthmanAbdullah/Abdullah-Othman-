// Author:    Othman Abdullah.
// Date:      2022.04.04.
// Title:     Watering King Competition.
#include "comp.h"

char *areas[] = {"Friend Tree", "Horse", "Snake Creek", "Cabbage Garden", "Sula", "MillPlot", "Pasture"};
;

// Task: 	Print Possible Areas.
// Input:    Nothing: void function.
// Output:   Nothing: void function.
// Activity: List out all the possible areas.
void printPossibleAreas()
{
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
    printf("Possible areas: \n");
    for (int i = 0; i < 7; i++)
    {
        printf("\n%d- %s", i + 1, areas[i]);
    }
    printf("\nChoose a number from the numbers of the areas  above: ");
}

// Task: 	validate the input if it's a valid number or not (valid: if it is > 0 or <= 7 ).
// Input:    pointer to area number variable.
// Output:   modifies the value of the variable through out the pointer.
// Activity: It validates the the given number if it is good or not(good meaning that its a number from the listed numbers in the screen(0<n<=7)), if the user entered another
//           number, then it doesn't allow that number to be stored, rather it keeps asking for the proper number of area from the listed ones.
void validate(int *areaNum)
{
    int tmp;
    do
    {
        printPossibleAreas();
        scanf("%d", &tmp);
        if (tmp < 1 || tmp > 7)
        {
            printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
            printf("\033[0;31m"); // Set the text to the color red.
            printf("Invalid input!, choose a number between 1 and 7\n");
            printf("\033[0m"); // Resets the text to default color.
        }
    } while (tmp < 1 || tmp > 7);
    *areaNum = tmp - 1;
}

// Task: 	Adding applicant into the file(where our data are stored(the applicants data)).
// Input:    a line and a file name.
// Output:   Nothing: prints the line to the file.
// Activity: Prints the name to the file througout the file pointer.
void addToFile(char *line, char *fname)
{
    FILE *filePtr;
    filePtr = fopen(fname, "a+");

    fprintf(filePtr, "%s", strcat(line, "\n"));
    fclose(filePtr);
}

// Task: 	Check if any of the applicants stored in the  file contains the given name or not;
// Input:    name and the file name;
// Output:   Boolean value.
// Activity: Cheks if the given line is similar to the name of any of the applicants stored in the given file.
bool nameExistsInFile(char name[], char fname[])
{
    FILE *fPtr;
    fPtr = fopen(fname, "r");
    bool flag = false;
    char line[MAX_LIMIT];
    while (fgets(line, MAX_LIMIT, fPtr) != NULL)
    {
        if (isNameInLine(name, line))
            flag = true;
    }
    fclose(fPtr);
    return flag;
}

// Task: 	Add applicant;
// Input:    name and the file name;
// Output:   void.
// Activity: Asks for the input from the user, and add the given applican't information to the file that we are storing our data in.
void add(char *fname)
{
    // system("clear");
    printf("\033[0;31m"); // Set the text to the color red.
    printf("<<<---------------------------------ADDING SECTION--------------------------------->>>\n");
    printf("\033[0m"); // Resets the text to default color.
    applicant a;
    getchar();
    printf("Enter the bunny's name: ");
    fgets(a.name, MAX_LIMIT, stdin);
    a.name[strcspn(a.name, "\n")] = 0;

    if (!nameExistsInFile(a.name, fname))
    {
        validate(&(a.area));
        printf("Enter the number of enteries: ");
        scanf("%d", &(a.numOfEnteries));

        char *line = malloc(1024);
        strcat(line, a.name);
        line[strcspn(line, "\n")] = 0;
        strcat(line, ";");
        strcat(line, areas[a.area]);
        char buffer[100];
        sprintf(buffer, ";%d", a.numOfEnteries);
        strcat(line, buffer);

        addToFile(line, "data.txt");
        // system("clear");
        printf("\033[0;31m"); // Set the text to the color red.
        printf("\n<<<<<<-----------The data have been successfully added!----------->>>>>>>\n");
        printf("\033[0m"); // Resets the text to default color.
        free(line);
    }
    else
    {
        printf("The applicant's name already exists in the file!\n");
    }
}

// Task: 	Extract the name from the given line containing the data of an applicant;
// Input:    The line it self;
// Output:   the name.
// Activity: Extract the name from the line and returning it.
char *nameFromLine(char *line)
{
    int i = 0;
    while (line[i] != ';')
    {
        i++;
    }
    char *substring = malloc(i + 1);
    strncpy(substring, line, i);
    substring[i + 1] = '\0';
    return substring;
}

bool isNameInLine(char *givenName, char *line)
{
    bool flag = false;
    char *name = nameFromLine(line);
    if (strcmp(name, givenName) == 0)
        flag = true;
    free(name);
    return flag;
}

// Task: 	Concatinate two strings and append an integer to the end of the result.
// Input:    string(the string we want to cocatinate into), int(number of enteries that we want to append it to the reulst of the catentation of the twp strings), int(indecating the endex of an area that we want to concatenate it) ;
// Output:   void.
// Activity: catinate the name with the area and the number if enteries into one single line.
void myStrcat(char *buffer, int numOfEnteries, int area)
{
    strcat(buffer, ";");
    strcat(buffer, areas[area]);
    printf("buffer contains:%s", buffer);
    printf("buffer contains: %s\n", buffer);
    char buffer2[100];
    sprintf(buffer2, ";%d", numOfEnteries);
    strcat(buffer, buffer2);
    strcat(buffer, "\n");
    buffer[strlen(buffer)] = '\0';
}

// Task: 	modify the data of an applicant based on his name.
// Input:    The name of the applocant, the file name.
// Output:   void.
// Activity: Modifies the data of an applicant based on the given information.
void modifyData(char *name, char *fname)
{

    FILE *fptr1, *fptr2;

    char str[MAX_LIMIT];
    char temp[] = "temp.txt";
    printf("%s", fname);
    fptr1 = fopen(fname, "r");
    if (!fptr1)
    {
        printf("Unable to open the input file!!\n");
        exit(1);
    }
    fptr2 = fopen(temp, "w");
    if (!fptr2)
    {
        printf("Unable to open a temporary file to write!!\n");
        fclose(fptr1);
        exit(1);
    }

    char *buffer = malloc(1204);
    printf("Enter the new data: \n");
    printf("New name: \n");
    fgets(buffer, MAX_LIMIT, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    int area;
    int numOfEnteries;
    validate(&area);
    printf("Enter the new number of enteries: ");
    scanf("%d", &numOfEnteries);
    myStrcat(buffer, numOfEnteries, area);

    while (fgets(str, MAX_LIMIT, fptr1) != NULL)
    {
        if (!isNameInLine(name, str))
        {
            fprintf(fptr2, "%s", str);
        }
        else
        {
            fprintf(fptr2, "%s", buffer);
        }
    }

    fclose(fptr1);
    fclose(fptr2);
    remove(fname);
    rename(temp, fname);
    // system("clear");
    printf("\033[0;31m"); // Set the text to the color red.
    printf("<<<--------------- Successfully modified -------------------->> \n");
    printf("\033[0m"); // Resets the text to default color.
}

// Task: 	Asking for the name of the applicant that the user want to modifiy its information
// Input:    the file name that contains the data of the applicants.
// Output:   void.
// Activity: asks for the input and call the 'modifyData' functio on that name.
void modify(char *fname)
{
    // system("clear");
    printf("\033[0;31m"); // Set the text to the color red.
    printf("<<<---------------------------------MODIFYING SECTION--------------------------------->>>\n");
    printf("\033[0m"); // Resets the text to default color.
    char name[1024];
    printf("Enter the name of the applicant to be modified: ");
    getchar();
    fgets(name, MAX_LIMIT, stdin);
    name[strcspn(name, "\n")] = 0;
    if (nameExistsInFile(name, fname))
    {
        modifyData(name, fname);
    }
    else
    {
        printf("\033[0;31m"); // Set the text to the color red.
        printf("The name doesn't exist!\n");
        printf("\033[0m"); // Resets the text to default color.
    }
}

// Task: 	Delte data of an applicant based on the given name of the applicant
// Input:    the name of the applicant and the file name that we are storing the data into.
// Output:   void.
// Activity: delete the data of that applicant.
void delData(char *name, char *fname)
{

    FILE *fptr1, *fptr2;
    char tmp[] = "tmp.txt";
    fptr1 = fopen(fname, "r");
    fptr2 = fopen(tmp, "w");

    if (!fptr1)
    {
        printf("Unable to open the input file!!\n");
        fclose(fptr1);
        exit(1);
    }
    if (!fptr2)
    {
        printf("Unable to open a temporary file to write!!\n");
        fclose(fptr1);
        exit(1);
    }
    char str[1024];

    while (fgets(str, MAX_LIMIT, fptr1) != NULL)
    {
        if (!isNameInLine(name, str))
        {
            fprintf(fptr2, "%s", str);
        }
    }

    fclose(fptr1);
    fclose(fptr2);
    remove(fname);
    rename(tmp, fname);
    printf(" Removed successfully..!! \n");
}

// Task: 	asks for the name of the applicant that we the user wants to delete its info from the file that stores the data.
// Input:    only the file name.
// Output:   void.
// Activity:  asks for the name of the applicant and call the delInfo function on the given information.
void Delete(char *fname)
{
    // system("clear");
    printf("\033[0;31m"); // Set the text to the color red.
    printf("<<<---------------------------------DELETING SECTION--------------------------------->>>\n");
    printf("\033[0m"); // Resets the text to default color.

    char name[1024];
    printf("Enter the name of the applicant to delete: ");
    getchar();
    fgets(name, MAX_LIMIT, stdin);
    name[strcspn(name, "\n")] = 0;
    if (nameExistsInFile(name, fname))
    {
        delData(name, fname);
    }
    else
    {
        printf("The name doesn't exist!\n");
    }
}

// Task: 	Given area, return the index of that area in the global constant array of areas defined above.
// Input:    the name of the area.
// Output:   int(the index of that area in the array) .
// Activity:  search for that area in the array and returns the index of it.
int getIndexOfArea(char *area)
{
    int i;
    for (i = 0; i < 7; i++)
    {
        if (strcmp(area, areas[i]) == 0)
            return i;
    }
    return -1;
}

// Task: 	Given a line contains the data of an applicant, we want to get the data of that applicant seperatly(ex: name , area ... ).
// Input:    a temporary applicant type(where we will store the data of the applicant), the line from the file containg the data.
// Output:   void.
// Activity:  split the line and puts the name of the applicant stored in the line into the name section of the record, area to the area section and the number of enteries to that section in the record.
void getApplicantInfo(applicant *tmp, char *line)
{

    int i = 0;
    while (line[i] != ';')
    {
        i++;
    }

    char buffer[128];
    strncpy(tmp->name, line, i);
    tmp->name[i + 1] = '\0';
    int j = i + 1;

    int it = 0;
    while (line[j] != ';')
    {
        buffer[it] = line[j];
        j++;
        it++;
    }
    buffer[it] = '\0';

    tmp->area = getIndexOfArea(buffer);

    int k = j + 1;
    char buffer2[128];
    it = 0;
    while (line[k] != '\n')
    {
        buffer2[it++] = line[k];
        k++;
    }

    tmp->numOfEnteries = atoi(buffer2);
}

// Task: 	Print the applicants in a certian area.
// Input:    the number of the area based on the listed list of areas, the file name.
// Output:   void.
// Activity: list out the applicants in that particular area.
void printApplicantsInArea(int choice, char *fname)
{
    FILE *fptr;
    fptr = fopen(fname, "r");
    if (fptr == NULL)
    {
        perror("Unable to open file!");
        exit(1);
    }
    printf("\n<<<------------------------------------------------------------>>\n");
    printf("Applicants in %s: \n", areas[choice - 1]);
    char buffer[128];
    int cnt = 0;
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        applicant tmp;
        getApplicantInfo(&tmp, buffer);
        if (strcmp(areas[tmp.area], areas[choice - 1]) == 0)
        {
            printf("%d- Name: %s,Area:%s, Number of enteries:%d\n", ++cnt, tmp.name, areas[tmp.area], tmp.numOfEnteries);
        }
    }

    fclose(fptr);
}

// Task: 	Asks for the input's area and call the above function on the input .
// Input:    the file name.
// Output:   void.
// Activity: Asks for the number of area based on the printed list of areas.
void ListByArea(char *fname)
{
    int choice = 0;
    do
    {
        printPossibleAreas();
        scanf("%d", &choice);
        if (choice < 0 || choice > 7)
        {
            printf("Invalid input\n");
        }
    } while (choice < 0 || choice > 7);
    printApplicantsInArea(choice, fname);
}

// Task: 	List all the applicants stored in the data file.
// Input:    the file name.
// Output:   void.
// Activity: list out the applicants in the data file.
void listAll(char *fname)
{
    FILE *fptr;
    fptr = fopen(fname, "r");
    if (fptr == NULL)
    {
        perror("Unable to open file!");
        exit(1);
    }
    printf("\n<<<------------------------------------------------------------>>\n");
    printf("All applicants: \n");
    char buffer[128];
    int counter = 0;
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        applicant tmp;
        getApplicantInfo(&tmp, buffer);
        printf("%d- Name: %s\t,Area:%s, Number of enteries:%d\n", counter++, tmp.name, areas[tmp.area], tmp.numOfEnteries);
    }
}

char *extractAreaFromLine(char *line)
{
    int i = 0;
    while (line[i] != ';')
    {
        i++;
    }
    int j = i + 1;
    while (line[j] != ';')
    {
        j++;
    }
    char *substring = malloc(j - i + 1);
    strncpy(substring, line, i);
    int idx = 0;
    for (int k = i + 1; k < j; k++)
    {
        substring[idx++] = line[k];
    }
    substring[idx] = '\0';
    return substring;
}

void StartWateringComp(char *fname)
{
    // system("clear");
    /// File of the data
    FILE *fptr;
    fptr = fopen(fname, "r");
    if (fptr == NULL)
    {
        perror("Could not open the file, ERROR!\n");
        exit(1);
    }
    /// Pipes for the communcation between the processes.
    int pipePtoChildA[2]; // unnamed pipe file descriptor array
    int pipePtoChildB[2]; // unnamed pipe file descriptor array
    int pipeChildAtoP[2]; // unnamed pipe file descriptor array
    int pipeChildBtoP[2]; // unnamed pipe file descriptor array
                          /// Data of the winner bunny
    int numberOfEggs = 0;
    char winnerBunny[128];
    /// Opening the pipes
    if (pipe(pipePtoChildA) == -1)
    {
        perror("Error with opening the pipePtoChildA pipe\n");
        exit(1);
    }
    if (pipe(pipePtoChildB) == -1)
    {
        perror("Error with opening the pipePtoChildB pipe\n");
        exit(1);
    }
    if (pipe(pipeChildAtoP) == -1)
    {
        perror("Error with opening the pipeChildAtoP pipe\n");
        exit(1);
    }
    if (pipe(pipeChildBtoP) == -1)
    {
        perror("Error with opening the pipeChildBtoP pipe\n");
        exit(1);
    }
    /// Forking supervisor(child 1) A
    pid_t superVisor_A = fork();
    if (superVisor_A == 0)
    {
        /// child A
        close(pipePtoChildA[1]);
        close(pipeChildAtoP[0]);
        int numOfbunniesInFirstGroupOfAreas = 0;
        read(pipePtoChildA[0], &numOfbunniesInFirstGroupOfAreas, sizeof(int));
        srand(time(NULL));
        for (int i = 0; i < numOfbunniesInFirstGroupOfAreas; i++)

        {
            int length = 0;
            char buffer[128];
            read(pipePtoChildA[0], &length, sizeof(int));
            read(pipePtoChildA[0], buffer, length);
            printf("Supervisor A received a bunny with data:%s\n", buffer);

            // Generating a random number
            // srand(getpid() + i);
            int rand_num = rand() % 100 ;
            write(pipeChildAtoP[1], &rand_num, sizeof(int));
            write(pipeChildAtoP[1], &length, sizeof(int));
            write(pipeChildAtoP[1], buffer, length);
        }
        close(pipePtoChildA[0]);
        close(pipeChildAtoP[1]);

        printf("Supervisor(Child) A sent the data to the parent\n");
        printf("Supervisor(Child) A finished\n");
        exit(EXIT_SUCCESS);
    }
    else if (superVisor_A > 0)
    {
        /// Forking supervisor(child 1) A
        pid_t superVisor_B = fork();
        if (superVisor_B == 0)
        {
            /// Child B
            close(pipePtoChildB[1]);
            close(pipeChildBtoP[0]);
            int numOfbunniesInSecondGroupOfAreas = 0;
            read(pipePtoChildB[0], &numOfbunniesInSecondGroupOfAreas, sizeof(int));
            for (int i = 0; i < numOfbunniesInSecondGroupOfAreas; i++)
            {
                int length = 0;
                char buffer[128];
                read(pipePtoChildB[0], &length, sizeof(int));
                read(pipePtoChildB[0], buffer, length);
                printf("Supervisor B received a bunny with data:%s\n", buffer);

                // Generating a random number
                srand(getpid() + i);
                int rand_num = rand() % 100;
                write(pipeChildBtoP[1], &rand_num, sizeof(int));
                write(pipeChildBtoP[1], &length, sizeof(int));
                write(pipeChildBtoP[1], buffer, length);
            }
            close(pipePtoChildB[0]);
            close(pipeChildBtoP[1]);
            printf("Supervisor(Child) sent the data to the parent\n");
            printf("Supervisor(Child) B finished\n");
                // printf("getpid() B:%d\n",getpid() );
            exit(EXIT_SUCCESS);
        }
        else if (superVisor_B > 0)
        {
            /// Parent
            // Max 128 binnoes on each group
            char bunniesInFirstGroupOfAreas[MAX_NUMBER_OF_BUNNIES_IN_FIRST_GROUP][100];   // Array for holding the bunnies in first group of areas
            char bunniesInSecondGroupOfAreas[MAX_NUMBER_OF_BUNNIES_IN_SECOND_GROUP][100]; // Array for holding the bunnies in second group of areas
            /// Filtering the bunnies
            char line[128];
            /// Reading the data from the file
            int ind1 = 0;
            int ind2 = 0;
            while (fgets(line, 100, fptr) != NULL)
            {
                char *areaInline = extractAreaFromLine(line);
                line[strlen(line) - 1] = '\0'; // printf("area: %s with length %ld\n" , areaInline, strlen(areaInline));
                if (getIndexOfArea(areaInline) < 4)
                {
                    strcpy(bunniesInFirstGroupOfAreas[ind1], line);
                    ind1++;
                    // printf("In bunniesInFirstGroupOfAreas : %s\n" ,line );
                }
                else
                {
                    strcpy(bunniesInSecondGroupOfAreas[ind2], line);
                    // printf("In bunniesInSecondGroupOfAreas : %s\n" ,bunniesInSecondGroupOfAreas[ind1] );
                    ind2++;
                }
                free(areaInline);
            }
            /// communcation between parent and child 1: sending the data of the bunnies in first group to child 1 and receiving the data from the child
            printf("\nParent write the data of the bunnies in the first group to the pipe that holds the data and send them to  supervisor 1\n\n");
            close(pipePtoChildA[0]);                     // closing the reading end;
            int len1 = ind1;                             // Number of bunnies in the first group
            write(pipePtoChildA[1], &len1, sizeof(int)); // send first the number of bunnies in the first group
            for (int i = 0; i < len1; i++)
            {                                                           //  the data in group 1
                int length = strlen(bunniesInFirstGroupOfAreas[i]) + 1; // holds the length of the i'th string
                write(pipePtoChildA[1], &length, sizeof(int));
                write(pipePtoChildA[1], bunniesInFirstGroupOfAreas[i], length);
                // printf("send:%s\n", bunniesInFirstGroupOfAreas[i]);
            }
            close(pipePtoChildA[1]); // closing the writing end;

            int status1;
            waitpid(superVisor_A, &status1, 0);
            close(pipeChildAtoP[1]);
            printf("\nParent recieved the following data from supervisor A:\n");
            for (int i = 0; i < len1; i++)
            {
                int numOfEggs;
                int length;
                char buffer[100];
                read(pipeChildAtoP[0], &numOfEggs, sizeof(int));
                read(pipeChildAtoP[0], &length, sizeof(int));
                read(pipeChildAtoP[0], buffer, length);
                printf("Bunny's data:%s, number of eggs:%d\n", buffer, numOfEggs);
                /// checking if the the current bunny have greater number of eggs then we update the winner
                if (numberOfEggs < numOfEggs)
                {
                    numberOfEggs = numOfEggs;
                    strcpy(winnerBunny, buffer);
                }
            }
            close(pipeChildAtoP[0]);
            printf("\nParent finished the communication with supervisor_A\n");
            /// communcation between parent and child 2: sending the data of the bunnies in second group to child 2 and receiving the data from there
            printf("\nParent write the data of the bunnies in the second group to the pipe that holds the data and send them to supervisor 2\n\n");
            close(pipePtoChildB[0]);                     // closing the reading end;
            int len2 = ind2;                             // Number of bunnies in the second group
            write(pipePtoChildB[1], &len2, sizeof(int)); // send first the number of bunnies in the second group
            for (int i = 0; i < len2; i++)
            {                                                            //  sending the data in group 2
                int length = strlen(bunniesInSecondGroupOfAreas[i]) + 1; // holds the length of the i'th string
                write(pipePtoChildB[1], &length, sizeof(int));
                write(pipePtoChildB[1], bunniesInSecondGroupOfAreas[i], length);
            }
            close(pipePtoChildB[1]); // closing the writing end;

            int status2;
            waitpid(superVisor_B, &status2, 0);
            close(pipeChildBtoP[1]);
            printf("\nParent recieved the following data from supervisor B:\n");
            for (int i = 0; i < len2; i++)
            {
                int numOfEggs;
                int length;
                char buffer[100];
                read(pipeChildBtoP[0], &numOfEggs, sizeof(int));
                read(pipeChildBtoP[0], &length, sizeof(int));
                read(pipeChildBtoP[0], buffer, length);
                printf("Bunny's data:%s, number of eggs:%d\n", buffer, numOfEggs);
                // checking if the the current bunny have greater number if eggs then we update the winner
                if (numberOfEggs < numOfEggs)
                {
                    numberOfEggs = numOfEggs;
                    strcpy(winnerBunny, buffer);
                }
            }
            close(pipeChildBtoP[0]);
            printf("\nParent finished the communication with supervisor_B\n");
            printf("\033[0;31m"); // Set the text to the color red.
            printf("----------------Winner is:%s, Number of collected eggs:%d---------------- \n", winnerBunny, numberOfEggs);
            printf("\033[0m"); // Resets the text to default color.
            printf("\nParent finished\n");
            /// Closing the data file
            fclose(fptr);
        }
        else
        {
            perror("Error with fork\n");
            exit(1);
        }
    }
    else
    {
        perror("Error with fork\n");
        exit(1);
    }
    // exit(EXIT_SUCCESS);
}

// Task: 	Excute the command given from the user based on the menu options.
// Input:    the user's choice from the menu
// Output:   void.
// Activity: call the function based on the menu printed to the user.
void excute(int choice)
{
    char fname[9];
    strcpy(fname, "data.txt");
    switch (choice)
    {
    case 1:
        add(fname);
        break;
    case 2:
        modify(fname);
        break;
    case 3:
        Delete(fname);
        break;
    case 4:
        ListByArea(fname);
        break;
    case 5:
        listAll(fname);
        break;
    case 6:
        StartWateringComp(fname);
        break;
    default:
        printf("See you !\n");
    }
}

// Task: 	Print the menu of possible operation that our programm supply.
// Input:    nothing.
// Output:   void.
// Activity: list out the menu options and validate the choice, call the excute function to excute the user's command .
void Menu()
{
    int choise;
    // system("clear");
    do
    {
        printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
        printf("Menu: \n");
        printf("0- Exit.\n");
        printf("1- Add new applicant.\n");
        printf("2- Modify an  existing application.\n");
        printf("3- Delete inofmation of an applicant\n");
        printf("4- List the applicants by area\n");
        printf("5- List all the applicants\n");
        printf("6- Start the watering compatition\n");
        printf("Choise:");
        scanf("%d", &choise);
        if (choise < 0 || choise > NUM_OF_MENU_OPTIONS)
        {
            printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
            printf("Invalid input!\n");
        }
        else
        {
            excute(choise);
        }

    } while (choise != 0);
}