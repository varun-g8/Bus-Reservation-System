// Header File required For This Project
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
char ch[10][130] = {"Sandeep Express", "Varun Express", "Keerthi Express", "Priyanka Express", "Uday Express"};
// ch[10][13] is used to Add Bus name
char des[10][130] = {"Bellary To Mumbai", "Bellary To Mysuru", "Bellary To Pune", "Bellary To Vijayawada", "Bellary To Hyderabad"};
// des[10][130] is used to Add Bus Route
char tim[10][30] = {"10:30 pm", "11:45 pm", " 6:30 pm", " 5:30 pm", " 7:45 pm"};
// tim[10][130] is used to Add Bus Timing
int amt[10] = {800, 500, 700, 600, 450};
// amt[10] is used to Add Amount for each bus
char name[32][100] = {'\0'};
// name[32][100] is used to Add customer Name
char number[32][5] = {'\0'};
// number[32][100] is used to Add customer Seat number
char phno[32];
// phno[32] is used to Add customer Phone number
int age;
// age is used to Add customer Age
int num1[32] = {0};
// num1[32] is a list of remaining seat
int C_ancle = 60;
// C_ancle is used for amount required for cancellation
int trno;
// trno is used for Bus number

// Below writen function are used in this project
void bus();
// for list of bus
void name_number(int booking, char numstr[100]);
// for Adding Name and Seat number to read_number(int trno) and void read_name(int trno)
void booking();
// for Booking the tickets
int read_number(int trno);
// for reading and writing the number from the file
void read_name(int trno);
// for reading and writing the name from the file
void status();
// for printing the status by user input
void status_1(int trno);
// for printing the status while booking ticket
void cancle();
// for Cancling the tickets
void recipt(int seat, char name[25], int amt, char des[25], char busname[25], char tim[trno - 1], int age, char phno[25]);
//for Printing the ticket by their customer name
void login();
// for login

int main()
{
    int num, i;
    do
    {
        system("cls");
        printf("\n\n\n");
        printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
        printf("\t\t\t\t\t[1] : View Bus List\n");
        printf("\n");
        printf("\t\t\t\t\t[2] : Book Tickets\n");
        printf("\n");
        printf("\t\t\t\t\t[3] : Cancle Booking\n");
        printf("\n");
        printf("\t\t\t\t\t[4] : Bus Status Board\n");
        printf("\n");
        printf("\t\t\t\t\t[5] : Reset All Bus\n");
        printf("\n");
        printf("\t\t\t\t\t[6] : Exit\n\n");
        printf("===============================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            bus(); //for list of bus
            printf("\t\t\tPress any Key to continue...");
            break;
        case 2:
            booking(); //for booking the tickets
            break;
        case 3:
            cancle();
            break;
        case 4:
            status();
            printf("\t\t\tPress any Key to continue...");
            break;
        case 5:
            login();
            system("attrib -h -s -r /s *.dat");
            system("del  TICKET_FOLDER *.dat");
            system("del  TICKET_FOLDER *.txt");
            break;
        }
        getch();
    } while (num != 6);
    system("CLS");
    printf("\n\n\n\t==========================================================================================================\n");
    printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    printf("\t==========================================================================================================\n");
    printf("\t\t\t\t\t\t Team BITM");
    getch();
    return 0;
}
void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\tSNo\tBus Name\t\t  Destination\t\t\tAmount\t\t  Timing\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\t%d :  %s\t\t %s\t\t %d\t\t %s\n", i + 1, ch[i], des[i], amt[i], tim[i]);
        printf("\n");
    }
    printf("\n=============================================================================================================\n\n");
}
void booking()
{

    int i = 0;
    char numstr[100];
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n"); //for entering train number
    bus();                                                                                                                           //for seeing train least
    printf("\t\t\t\t\tEnter the Bus number : ");
    scanf("%d", &trno);
    if (trno > 0 && trno <= 5)
    {
        // HH:
        system("cls");
        printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n"); //for selecting coach
        printf("Bus Number : %d Bus Name : %s", trno, ch[trno - 1]);
        status_1(trno);
        FILE *f1, *fopen(); //for reading the seats from the user.
        char str1[80] = "32", str2[4], str3[4];
        int seat1, seat2, booking = 0;
        if (trno == 1)
        {
            system("attrib -h -s -r /s *.dat");
            f1 = fopen("tr1.dat", "r+");
            fgets(str1, 80, f1);
            fclose(f1);
            system("attrib +h +s +r /s *.dat");
        }
        else if (trno == 2)
        {
            system("attrib -h -s -r /s *.dat");
            f1 = fopen("tr2.dat", "r+");
            fgets(str1, 80, f1);
            fclose(f1);
            system("attrib +h +s +r /s *.dat");
        }
        else if (trno == 3)
        {
            system("attrib -h -s -r /s *.dat");
            f1 = fopen("tr3.dat", "r+");
            fgets(str1, 80, f1);
            fclose(f1);
            system("attrib +h +s +r /s *.dat");
        }
        else if (trno == 4)
        {
            system("attrib -h -s -r /s *.dat");
            f1 = fopen("tr4.dat", "r+");
            fgets(str1, 80, f1);
            fclose(f1);
            system("attrib +h +s +r /s *.dat");
        }
        else if (trno == 5)
        {
            system("attrib -h -s -r /s *.dat");
            f1 = fopen("tr5.dat", "r+");
            fgets(str1, 80, f1);
            fclose(f1);
            system("attrib +h +s +r /s *.dat");
        }
        seat1 = atoi(str1); //covert the string into number
        if (seat1 <= 0)
        {
            printf("There is no blank seat in this bus ");
        }
        else
        {
        HH:
            printf("\n\t\t\t\t\t\tNumber of Tickets : ");
            scanf("%d", &booking);
            if (booking > 0 && booking <= 32)
            {
                printf("\n");
                seat1 = seat1 - booking;
                itoa(trno, numstr, 10);
                name_number(booking, numstr);
                itoa(seat1, str1, 10);
                //for reading the seats from the user.
                if (trno == 1)
                {
                    system("attrib -h -s -r /s *.dat");
                    f1 = fopen("tr1.dat", "w");
                    fputs(str1, f1);
                    fclose(f1);
                    system("attrib +h +s +r /s *.dat");
                }
                else if (trno == 2)
                {
                    system("attrib -h -s -r /s *.dat");
                    f1 = fopen("tr2.dat", "w");
                    fputs(str1, f1);
                    fclose(f1);
                    system("attrib +h +s +r /s *.dat");
                }
                else if (trno == 3)
                {
                    system("attrib -h -s -r /s *.dat");
                    f1 = fopen("tr3.dat", "w");
                    fputs(str1, f1);
                    fclose(f1);
                    system("attrib +h +s +r /s *.dat");
                }
                else if (trno == 4)
                {
                    system("attrib -h -s -r /s *.dat");
                    f1 = fopen("tr4.dat", "w");
                    fputs(str1, f1);
                    fclose(f1);
                    system("attrib +h +s +r /s *.dat");
                }
                else if (trno == 5)
                {
                    system("attrib -h -s -r /s *.dat");
                    f1 = fopen("tr5.dat", "w");
                    fputs(str1, f1);
                    fclose(f1);
                    system("attrib +h +s +r /s *.dat");
                }
            }
            else
            {
                printf("\n==========================================================================================================\n");
                printf("\t\t\t Invalid Number of Tickets [%d] give in between 1 to 32\t\t\t\t\t\n", booking);
                printf("==========================================================================================================\n");
                getch();
                system("cls");
                goto HH;
            }
        }
    }
    else
    {
        printf("\n==========================================================================================================\n");
        printf("\t\t\t\t\t Bus Number [%d] Not Found\t\t\t\t\t\n", trno);
        printf("==========================================================================================================\n");
    }
}
void name_number(int booking, char numstr[100])
{
    char tempstr[100], tempstr1[12] = "status", tempstr2[12] = "number", tempstr3[12] = "List_", temp[10], seat[10];
    int number, trno, busno, tamount, t_amount = 0;
    FILE *a, *b, *c, *d, *e;
    int i = 0, test = 0;
    strcat(numstr, ".dat");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    strcat(tempstr3, numstr);
    trno = atoi(numstr);
    system("attrib -h -s -r /s *.dat");
    // aa:
    a = fopen(tempstr1, "a"); //for open the file to write the name in the file
    b = fopen(tempstr2, "a"); //for open the file for writing the number in the file
    e = fopen(tempstr3, "a");
    status_1(trno);
    for (i = 0; i < booking; i++) //for entering the person name and seat number in the file
    {
    bb:
        c = fopen("record.txt", "a+");
        printf("\n_______________________________________ Enter the details for ticket no [%d] _______________________________________\n\n\n", i + 1);
        printf("\t\t\t\t\tEnter the seat number : ");
        scanf("%d", &number);
        if (number > 0 && number <= 32)
        {
            while (fscanf(c, "%d %s\n", &busno, &seat) != EOF)
            {
                itoa(number, tempstr, 10);
                if (busno == trno && strcmp(tempstr, seat) == 0)
                {
                    printf("\n==========================================================================================================\n");
                    printf("\t\t\t\t\t Seat [%s] Already Reserved\t\t\t\t\t\n", seat);
                    printf("==========================================================================================================\n");
                    getch();
                    system("cls");
                    fclose(c);
                    goto bb;
                }
            }
            printf("\n\t\t\t\t\tEnter the name of person : ");
            scanf("%s", name[number - 1]);
            printf("\n\t\t\t\t\tEnter the Age of person : ");
            scanf("%d", &age);
            if (age >= 5 && age <= 12)
            {
                tamount = amt[trno - 1] / 2;
            }
            else if (age >= 60 && age <= 100)
            {
                tamount = amt[trno - 1] - 50;
            }
            else if (age > 12 && age < 60)
            {
                tamount = amt[trno - 1];
            }
            else
            {
                printf("\n==========================================================================================================\n");
                printf("\t\t\t\t\tNo Ticket \t\t\t\t\t\n");
                printf("==========================================================================================================\n");
                getch();
                break;
            }

            printf("\n\t\t\t\t\tEnter the Phone number of person : ");
            scanf("%s", phno);
            printf("_______________________________________________________________________________________________________________________\n\n");
            printf("\t\t\tPress any Key to continue...");
            getch();
            printf("\n");
            itoa(number, tempstr, 10);
            fprintf(a, "%s ", name[number - 1]);
            fprintf(b, "%s ", tempstr);
            fprintf(c, "%d %s\n", trno, tempstr);
            fprintf(e, "%s\t%s\t\t%d\t\t%s\t\t%s\t\t%d\t\t%10s\n", tempstr, name[number - 1], tamount, ch[trno - 1], des[trno - 1], age, phno);
            recipt(number, name[number - 1], tamount, des[trno - 1], ch[trno - 1], tim[trno - 1], age, phno);
            t_amount = t_amount + tamount;
            fclose(c);
        }
        else
        {
            printf("\n==========================================================================================================\n");
            printf("\t\t\t\t\t Invalid seat [%d] \t\t\t\t\t\n", number);
            printf("==========================================================================================================\n");
            getch();
            system("cls");
            goto bb;
        }
    }
    fclose(a);
    fclose(b);
    fclose(c);
    fclose(e);
    system("attrib +h +s +r /s *.dat");
    printf("\n\t\t\t\tThe Total booking amount is %d", t_amount);
    // printf("\n\t\t\t\tThe Total booking amount is %d", amt[trno - 1] * booking);
}
void recipt(int seat, char name[25], int amt, char des[25], char busname[25], char tim[trno - 1], int age, char phno[25])
{
    char temp[30] = "TICKET_FOLDER//", temp1[15], temp2[15] = ".txt";
    char temp3[15], name2[25];
    time_t t;
    time(&t);
    strcpy(name2, name);
    strcat(name2, ".txt");
    strcat(temp, name2);
    system("mkdir TICKET_FOLDER");
    system("cls");
    printf("\n\n\n\t_________________________________ Ticket _________________________________\n\n");
    printf("\t\tName : %s \t\tDate & Time : %s\n", name, ctime(&t));
    printf("\t\tSeat number : %d\n", seat);
    printf("\t\tRoute : %s\n", des);
    printf("\t\tAge : %d\n", age);
    printf("\t\tAmount : %d\n", amt);
    printf("\t\tPhone number : %10s\n", phno);
    printf("\t__________________________________________________________________________\n\n");
    FILE *a;
    a = fopen(temp, "w");
    fprintf(a, "\n\n\n_________________________________ Ticket _________________________________\n\n");
    fprintf(a, "\tName : %s \t\tDate & Time : %s\n", name, ctime(&t));
    fprintf(a, "\tSeat number : %d\n", seat);
    fprintf(a, "\tRoute : %s\n", des);
    fprintf(a, "\tAge : %d\n", age);
    fprintf(a, "\tAmount : %d\n", amt);
    fprintf(a, "\tPhone number : %10s\n", phno);
    fprintf(a, "__________________________________________________________________________");
    fclose(a);
}
int read_number(int trno) //for putting the numeric value in the array
{
    char tempstr[100], tempstr2[12] = "number";
    FILE *a, *b;
    char numstr[100];
    int i = 0, j = 0, k;
    itoa(trno, numstr, 10);
    strcat(numstr, ".dat");
    strcat(tempstr2, numstr);
    system("attrib -h -s -r /s *.dat");
    a = fopen(tempstr2, "a+"); //for open the file to write the name in the file
    while (!feof(a))
    {
        number[i][j] = fgetc(a);

        if (number[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    k = i;
    for (i = 0; i < k; i++)
    {
        num1[i] = atoi(number[i]);
    }
    fclose(a);
    system("attrib +h +s +r /s *.dat");
    return k;
}
void read_name(int trno) //for putting the numeric value in the array
{
    char tempstr1[12] = "status";
    FILE *b;
    char numstr[50];
    int i = 0, j = 0, k = 0;
    itoa(trno, numstr, 10);
    strcat(numstr, ".dat");
    strcat(tempstr1, numstr);
    system("attrib -h -s -r /s *.dat");
    b = fopen(tempstr1, "a+"); //for open the file to write the name in the file
    while (!feof(b))
    {
        name[i][j] = fgetc(b);

        if (name[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    name[i][j] = '\0';
    k = i;
    fclose(b);
    system("attrib +h +s +r /s *.dat");
}

void status()
{
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i, trno, index = 0, j, k = 0;
    bus();
    printf("\t\t\tEnter the number of bus : ");
    scanf("%d", &trno);
    system("cls");
    if (trno > 0 && trno <= 5)
    {
        j = read_number(trno);
        read_name(trno);
        printf("____________________________________________________________________________________________________________________\n\n");
        printf("\t\t\t\t\tBus_Name : %s\n", ch[trno - 1]);
        printf("\t\t\t\t\tBus_no : 0%d\n", trno);
        printf("\t\t\t\t\tBus_Route : %s\n", des[trno - 1]);
        printf("\t\t\t\t\tBus_Timing : %s\n", tim[trno - 1]);
        printf("____________________________________________________________________________________________________________________\n\n");
        char tempname[33][50] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
        for (i = 0; i < j; i++)
        {
            strcpy(tempname[num1[i]], name[i]);
            k++;
        }
        for (i = 0; i < 8; i++)
        {
            printf("\t\t\t\t");
            for (j = 0; j < 4; j++)
            {
                printf("%d.%s\t", index + 1, tempname[index + 1]);
                index++;
            }
            printf("\n\n");
        }
        printf("\n\n\t\t\t\t\t\tAvailable Seats : %d\n", 32 - k);
        printf("____________________________________________________________________________________________________________________\n\n");
    }
    else
    {
        printf("\n==========================================================================================================\n");
        printf("\t\t\t\t\t Bus Number [%d] Not Found\t\t\t\t\t\n", trno);
        printf("==========================================================================================================\n");
    }
}

void status_1(int trno)
{
    system("cls");
    printf("___________________________________________ BUS RESERVATION SYSTEM _________________________________________________\n\n");
    printf("\t\t\t\t\tBus_Name : %s\n", ch[trno - 1]);
    printf("\t\t\t\t\tBus_no : 0%d\n", trno);
    printf("\t\t\t\t\tBus_Route : %s\n", des[trno - 1]);
    printf("\t\t\t\t\tBus_Timing : %s\n", tim[trno - 1]);
    printf("____________________________________________________________________________________________________________________\n\n");
    int i, index = 0, j, k = 0;
    j = read_number(trno);
    read_name(trno);
    char tempname[33][50] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[num1[i]], name[i]);
        k++;
    }
    for (i = 0; i < 8; i++)
    {
        printf("\t\t\t\t");
        for (j = 0; j < 4; j++)
        {
            printf("%d.%s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n\n");
    }
    printf("\n\t\t\t\t\t\tAvailable Seats : %d\n", 32 - k);
    printf("____________________________________________________________________________________________________________________\n\n");
}

void cancle()
{
    int seat_no, i, j, seat, trno2, busno, seat_no2, test = 0, test1 = 0;
    char numstr[100], tempstr2[15] = "number", tempstr1[15] = "status", tempstr3[15] = "tr", temp[15], seat1[15], name2[25], u_seat[5];
    bus();
    printf("\t\t\tEnter the bus number : ");
    scanf("%d", &trno);
    if (trno >= 1 && trno <= 5)
    {
        itoa(trno, numstr, 10);
        strcat(numstr, ".dat");
        strcat(tempstr1, numstr);
        strcat(tempstr2, numstr);
        strcat(tempstr3, numstr);
        read_number(trno);
        read_name(trno);
        status_1(trno);
        FILE *a, *b, *c, *d, *e, *f;

    an:
        printf("\t\t\t\tEnter the seat number : ");
        scanf("%d", &seat_no);

        if (seat_no > 0 && seat_no <= 32)
        {
            system("attrib -h -s -r /s *.dat");
            a = fopen(tempstr1, "w");
            b = fopen(tempstr2, "w");

            for (i = 0; i < 32; i++)
            {
                if (num1[i] == seat_no)
                {
                    test1++;
                    for (j = 0; j < 32; j++)
                    {
                        if (num1[j] != seat_no && num1[j] != 0)
                        {
                            fprintf(b, "%d ", num1[j]);
                            fprintf(a, "%s", name[j]);
                        }
                        else if (num1[j] == seat_no && num1[j] != 0)

                        {
                            printf("\n======================================================================================================\n");
                            printf("\t\t\t\t\tTICKET CANCLATION \n");
                            printf("\n\t\t\t\t\tName : %s\n", name[j]);
                            printf("\t\t\t\t\tSeat number : %d\n", num1[j]);
                            printf("\t\t\t\t\tBus number : %d\n", trno);
                            printf("\t\t\t\t\tBus Route : %s\n", des[trno - 1]);
                            printf("\t\t\t\t\tBus Amount : %d\n", amt[trno - 1]);
                            printf("\t\t\t\t\tCanclation Charges : %d", C_ancle);
                            getch();
                            system("cls");
                            strcpy(name[j], "Empty ");
                            //Getting old Seat Data
                            c = fopen(tempstr3, "r+");
                            fgets(temp, 80, c);
                            seat = atoi(temp);
                            seat += 1;
                            fclose(c);
                            //Updating The Canceled Seat Data
                            d = fopen("temp.dat", "w");
                            itoa(seat, seat1, 10);
                            fputs(seat1, d);
                            fclose(d);
                            e = fopen("record.txt", "r");
                            f = fopen("new_record.txt", "w");
                            while (fscanf(e, "%d %s\n", &busno, &u_seat) != EOF)
                            {
                                seat_no2 = atoi(u_seat);
                                if (trno == busno && seat_no == seat_no2)
                                {
                                    test = 1;
                                }
                                else
                                {
                                    fprintf(f, "%d %s\n", busno, u_seat);
                                }
                            }
                            fclose(e);
                            fclose(f);
                        }
                    }
                    fclose(a);
                    fclose(b);
                }
            }
            if (test1 == 0)
            {
                printf("\n==========================================================================================================\n");
                printf("\t\t\t\t\tSeat  Number [%d] not Yet Reserved\t\t\t\t\t\n", seat_no);
                printf("==========================================================================================================\n");
                printf("\t\t\t\t\tpress any key to go back to menu..\t\t\t\t\t\n");
                getch();
                return;
            }
        }
        else
        {
            printf("\n==========================================================================================================\n");
            printf("\t\t\t\t\t Bus Seat  Number [%d] Invalid\t\t\t\t\t\n", seat_no);
            printf("==========================================================================================================\n");
            getch();
            goto an;
        }
        fclose(a);
        fclose(b);
        fclose(c);
        fclose(d);
        fclose(e);
        fclose(f);
        remove(tempstr3);
        rename("temp.dat", tempstr3);
        remove("record.txt");
        rename("new_record.txt", "record.txt");
        printf("\n\n");
        printf("======================================================================================================\n");
        printf("\t\t\t\tYour %d rupees has been Returned\t\t\t\n", amt[trno - 1] - C_ancle);
        printf("======================================================================================================\n");
        system("attrib +h +s +r /s *.dat");
    }
    else
    {
        printf("\n==========================================================================================================\n");
        printf("\t\t\t\t\t Bus Number [%d] Not Found\t\t\t\t\t\n", trno);
        printf("==========================================================================================================\n");
    }
}

void login()
{
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do
    {
        system("cls");
        printf("\n  =========================  LOGIN FORM  =========================  ");
        printf("\n\n                       ENTER USERNAME:-");
        scanf("%s", &uname);
        printf("\n                       ENTER PASSWORD:-");
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';
        if (strcmp(uname, "user") == 0 && strcmp(pword, "pass") == 0)
        {
            printf("\n\n\n\t\tWELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\tPress any key to continue...");
            getch(); //holds the screen
            break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;
            getch(); //holds the screen
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");
        getch();
    }
    system("cls");
}
