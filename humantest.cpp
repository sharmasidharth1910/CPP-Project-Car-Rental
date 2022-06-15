#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <direct.h>
#include <iomanip>
#include <string>
#include <time.h>
#include <random>
#include <sstream>

using namespace std;
int ctr = 0;

const int ch_MAX = 36;

string RandomString(int ch)
{
    char alpha[ch_MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z', '0', '1',
                          '2', '3', '4', '5', '6', '7', '8', '9'};
    string result = "";

    srand(time(NULL));

    for (int i = 0; i < ch - 1; i++)
        result = result + alpha[rand() % ch_MAX];

    return result;
}

class customer
{
public:
    string customername;
    string carmodel;
    string carNo;
    int number_car;
    char data;

    customer() {}

    customer(string name)
    {
        this->customername = name;
    }
};

class SignUp : public customer
{
public:
    string username;
    string emailId;
    string password;
    int size;

public:
    SignUp() {}

    SignUp(string str, string id, string pass) : customer(str)
    {
        username = str;
        emailId = id;
        password = pass;
        string st1;
        ifstream in;
        in.open("userData.txt");
        ofstream out;
        out.open("temp.txt");

        while (in >> st1)
        {
            out << st1 << " ";
            if ((++ctr) % 3 == 0)
                out << "\n";
        }

        out << username << " ";
        out << emailId << " ";
        out << password << " ";
        out.close();
        in.close();
        char filename[] = "userData.txt";

        if (remove(filename) == 0)
            cout << "file removed";
        else
            cout << "error";

        rename("temp.txt", "userData.txt");
        login();
    }

public:
    static void Admin()
    {
        string ss = "Human";
        string s1 = "human123";
        string pass = "123@";
        string st1;
        ifstream in;
        in.open("adminData.txt");
        ofstream out;
        out.open("tem.txt");

        while (in >> st1)
        {
            out << st1 << " ";
            if ((++ctr) % 3 == 0)
            {
                out << "\n";
            }
        }

        out << ss << " ";
        out << s1 << " ";
        out << pass << " ";
        out.close();
        in.close();
        char filename[] = "adminData.txt";
        remove(filename);
        rename("tem.txt", "adminData.txt");
    }

public:
    static string Adminlogin()
    {
        system("CLS");
        string pass = "";
        char ch;
        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
        cout << "\t\t\t\t\t------------------------------";
        cout << "\n\t\t\t\t\t\t     LOGIN \n";
        cout << "\t\t\t\t\t------------------------------\n\n";
        cout << "\t\t\t\t\t Enter  ID: ";
        string id;
        cin >> id;
        cout << "\t\t\t\t\t Enter PWD: ";
        cin >> pass;
        if (AuthenticateAdmin(id, pass))
        {
            cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
            system("PAUSE");
            system("CLS");
            return id;
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
            system("PAUSE");
            system("CLS");
            Adminlogin();
        }
    }

public:
    static string login()
    {
        system("CLS");
        string pass = "";
        char ch;
        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
        cout << "\t\t\t\t\t------------------------------";
        cout << "\n\t\t\t\t\t\t     LOGIN \n";
        cout << "\t\t\t\t\t------------------------------\n\n";
        cout << "\t\t\t\t\t Enter  ID: ";
        string id;
        cin >> id;
        cout << "\t\t\t\t\t Enter PWD: ";
        cin >> pass;

        if (Authenticate(id, pass))
        {
            cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
            system("PAUSE");
            system("CLS");

            return id;
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
            system("PAUSE");
            system("CLS");
            login();
        }
    }

public:
    static bool Authenticate(string id, string pass)
    {

        ifstream in;
        string st1, st2, st3;
        in.open("userData.txt");

        while (in.eof() == 0)
        {
            in >> st1;
            in >> st2;
            in >> st3;

            if (id == st2 && pass == st3)
                return true;
        }

        in.close();

        return false;
    }

public:
    static bool AuthenticateAdmin(string id, string pass)
    {
        Admin();
        ifstream in;
        string st1, st2, st3;
        in.open("adminData.txt");

        while (in.eof() == 0)
        {
            in >> st1;
            in >> st2;
            in >> st3;

            if (id == st2 && pass == st3)
                return true;
        }

        in.close();

        return false;
    }
};

// Inherited class from customer class
class rent : public customer
{
public:
    int days;
    int rentalfee;
    string date;
    string code;

    rent(string st)
    {
        customername = st;
    }
    void delBook()
    {
        int ctr = 0;
        ifstream bin;
        ofstream bout;
        string str;
        string s;
        cout << "Enter code";
        cin >> s;
        bin.open("book.txt");
        bout.open("b_temp.txt");
        while (bin >> str)
        {
            if (str == s)
            {
                bin >> str;
                bin >> str;
                bin >> str;
                bin >> str;
            }
            else
            {
                bout << str << " ";
                ++ctr;
                if (ctr % 5 == 0)
                {
                    bout << endl;
                }
            }
        }
        bin.close();
        bout.close();
        char filename1[] = "book.txt";
        remove(filename1);
        rename("b_temp.txt", "book.txt");
        // cout<<"after while";
        // sleep(3);
    }

    void decide()
    {
        int ch;
        bool checkBookingAvailable = false;

    begin:
        system("CLS");
        cout << "\n\t\t\t\t\t\t\t 1.Book Your Car " << endl;
        cout << "\n\t\t\t\t\t\t\t 2.Show your Bookings " << endl;
        cout << "\n\t\t\t\t\t\t\t 3.Delete Bookings " << endl;
        cout << "\n\t\t\t\t\t\t\t 4.Exit " << endl;
        cout << "Enter your choice :" << endl;

        cin >> ch;
        string st1, code_disp;
        ifstream in;

        switch (ch)
        {
        case 1:
            system("PAUSE");
            system("CLS");
            data();
            break;
        case 2:
            in.open("book.txt");
            system("CLS");
            cout << "Booking details are : " << endl;

            while (in >> st1)
            {
                code_disp = st1;
                in >> st1;
                if (st1 == customername)
                {
                    checkBookingAvailable = true;
                    cout << endl;
                    cout << "your transaction code is : " << code_disp << endl;
                    cout << "User Name : " << st1 << endl;
                    in >> st1;
                    cout << "Booking Date : " << st1 << endl;
                    in >> st1;
                    cout << "Number Of Cars : " << st1 << endl;
                    in >> st1;
                    cout << "Type Of Car : " << st1 << endl;
                    cout << endl
                         << "------------------------------------------" << endl;
                }
                else
                {
                    in >> st1;
                    in >> st1;
                    in >> st1;
                }
            }

            if (!checkBookingAvailable)
                cout << endl
                     << "Currently there are no active bookings." << endl
                     << endl;

            system("PAUSE");
            in.close();
            goto begin;
            break;

        case 3:
            delBook();
            goto begin;

            break;

        case 4:
            cout << "Thanks for visiting";
            sleep(5);
            exit(0);

        default:
            cout << "Enter Valid Choice Only";
            goto begin;
        }
    }

    bool correctDate(int bd, int bm, int by)
    {
        string st = __DATE__;
        string m = "";
        string d = "";
        int i = 0;

        while (st[i] != ' ')
        {
            m += st[i];
            i++;
        }

        i++;

        while (st[i] != ' ')
        {
            d += st[i];
            i++;
        }

        m = (m == "Jan")   ? "1"
            : (m == "Feb") ? "2"
            : (m == "Mar") ? "3"
            : (m == "Apr") ? "4"
            : (m == "May") ? "5"
            : (m == "Jun") ? "6"
            : (m == "Jul") ? "7"
            : (m == "Aug") ? "8"
            : (m == "Sep") ? "9"
            : (m == "Oct") ? "10"
            : (m == "Nov") ? "11"
            : (m == "Dec") ? "12"
                           : "999";

        int cd, cm, cy;
        stringstream obj, obj1;
        obj << d;
        obj >> cd;
        obj1 << m;
        obj1 >> cm;
        cy = 2022;

        if (by >= cy)
            if (bm >= cm || (bm < cm && by > cy) && bm <= 12)
                if ((bd > cd || (bd <= cd && (bm > cm || by > cy))) && (bd <= 30))
                    return true;
                else
                    return false;
            else
                return false;
        else
            return false;
    }

    void data()
    {
        cout << endl;
        do
        {
            // Option to select from the available set of Car variants
            cout << "\t\t\t\tPlease Select a Car" << endl;
            cout << "\t\t\t\tEnter 'A' for Mini." << endl;
            cout << "\t\t\t\tEnter 'B' for Micro." << endl;
            cout << "\t\t\t\tEnter 'C' for Sedan." << endl;
            cout << "\t\t\t\tEnter 'D' for XL." << endl;
            cout << endl;
            cout << "\t\t\t\tChoose a Car from the above options: ";
            cin >> carmodel;
            cout << endl;
            cout << "--------------------------------------------------------------------------" << endl;

            if (carmodel == "A")
            {

            first:
                system("CLS");
                cout << "\t\t\t\tPress 1 for Bajaj Qute taxi." << endl;
                cout << "\t\t\t\tPress 2 for Maruti Suzuki." << endl;
                cout << "\t\t\t\tPress 3 for Tesla model 2011." << endl;
                int c;
                cin >> c;

                if (c == 1)
                {
                    cout << "You have chosen Bajaj Qute taxi." << endl;
                    ifstream inA("1.txt"); // displaying details of model A
                    char str[200];
                    while (inA)
                    {
                        inA.getline(str, 200);
                        if (inA)
                            cout << str << endl;
                    }
                }
                else if (c == 2)
                {
                    cout << "You have chosen Maruti suzuki" << endl;
                    ifstream inA("A.txt"); // displaying details of model A
                    char str[200];
                    while (inA)
                    {
                        inA.getline(str, 200);
                        if (inA)
                            cout << str << endl;
                    }
                }
                else if (c == 3)
                {
                    // Displaying details of model A
                    cout << "You have chosen Tesla model 2011" << endl;
                    ifstream inA("A.txt");
                    char str[200];
                    while (inA)
                    {
                        inA.getline(str, 200);
                        if (inA)
                            cout << str << endl;
                    }
                }
                else
                {
                    cout << "\t\t\t\tSelect from given inputs." << endl;
                    goto first;
                }
            }
            sleep(2);

            if (carmodel == "B")
            {
            second:
                system("CLS");
                cout << "\t\t\t Press 1 for Swift ." << endl;
                cout << "\t\t\t Press 2 for Baleno." << endl;
                cout << "\t\t\t Press 3 for Wagon R." << endl;
                int c;
                cin >> c;
                if (c == 1)
                {
                    cout << "You have chosen Swift." << endl;
                    ifstream inA("1.txt"); // displaying details of model A
                    char str[200];
                    while (inA)
                    {
                        inA.getline(str, 200);
                        if (inA)
                            cout << str << endl;
                    }
                }
                else if (c == 2)
                {
                    cout << "You have chosen Baleno." << endl;
                    ifstream inA("A.txt"); // displaying details of model A
                    char str[200];
                    while (inA)
                    {
                        inA.getline(str, 200);
                        if (inA)
                            cout << str << endl;
                    }
                }
                else if (c == 3)
                {
                    cout << "You have chosen Wagon R." << endl;
                    ifstream inA("A.txt"); // displaying details of model A
                    char str[200];
                    while (inA)
                    {
                        inA.getline(str, 200);
                        if (inA)
                            cout << str << endl;
                    }
                }
                else
                {
                    cout << "\t\t\t\tSelect from given inputs." << endl;
                    goto second;
                }
            }
            sleep(2);

            if (carmodel == "C")
            {
            third:
                system("CLS");
                cout << "\t\t\t\tPress 1 for Honda Ciaz." << endl;
                cout << "\t\t\t\tPress 2 for Honda City." << endl;
                // cout<<"\t\t\t\tchoose 3 for Tesla model 2011."<<endl;
                int c;
                cin >> c;
                if (c == 1)
                {
                    cout << "You have chosen Honda Ciaz" << endl;
                    ifstream inA("1.txt"); // displaying details of model A
                    char str[200];
                    while (inA)
                    {
                        inA.getline(str, 200);
                        if (inA)
                            cout << str << endl;
                    }
                }
                else if (c == 2)
                {
                    cout << "You have chosen Honda City" << endl;
                    ifstream inA("A.txt"); // displaying details of model A
                    char str[200];
                    while (inA)
                    {
                        inA.getline(str, 200);
                        if (inA)
                            cout << str << endl;
                    }
                }
                else
                {
                    cout << "\t\t\t\tSelect from given inputs." << endl;
                    goto third;
                }
                sleep(2);
            }
            if (carmodel == "D")
            {
            fourth:
                system("CLS");
                cout << "\t\t\t\tPress 1 for Toyata Innova." << endl;
                cout << "\t\t\t\tPress 2 for Ertiga." << endl;
                // cout<<"\t\t\t\tchoose 3 for Tesla model 2011."<<endl;
                int c;
                cin >> c;
                if (c == 1)
                {
                    cout << "You have chosen Toyata Innova." << endl;
                    ifstream inA("1.txt"); // displaying details of model A
                    char str[200];
                    while (inA)
                    {
                        inA.getline(str, 200);
                        if (inA)
                            cout << str << endl;
                    }
                }
                else if (c == 2)
                {
                    cout << "You have chosen Ertiga." << endl;
                    ifstream inA("A.txt"); // displaying details of model A
                    char str[200];
                    while (inA)
                    {
                        inA.getline(str, 200);
                        if (inA)
                            cout << str << endl;
                    }
                }
                else
                {
                    cout << "\t\t\t\tSelect from given inputs." << endl;
                    goto fourth;
                }
                sleep(2);
            }

            if (carmodel != "A" && carmodel != "B" && carmodel != "C" && carmodel != "D")
                cout << "Invaild Car Model. Please try again!" << endl;

        } while (carmodel != "A" && carmodel != "B" && carmodel != "C" && carmodel != "D");

        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Please provide following information: " << endl;
        // getting data from user related to rental service
        cout << "Please select  No. of cars : ";
        cin >> number_car;
        cout << "Number of days you wish to rent the car : ";
        cin >> days;

        string d, m, y;
    reEnter:
        cout << "Enter the date (dd/mm/yy) for which you want to book the cars: ";
        cout << endl
             << "Enter Date : ";
        cin >> d;
        cout << endl
             << "Enter Month : ";
        cin >> m;
        cout << endl
             << "Enter Year :";
        cin >> y;
        cout << endl;

        int d1;
        int m1;
        int y1;

        try
        {
            d1 = stoi(d);
            m1 = stoi(m);
            y1 = stoi(y);
        }
        catch (int val)
        {
            cout << "Invalid input" << endl;
            goto reEnter;
        }

        if (!correctDate(d1, m1, y1))
        {
            cout << "Please!!! Enter Correct Date " << endl;
            sleep(3);
            goto reEnter;
        }

        string carmodel1;
        switch (carmodel[0])
        {
        case 'A':
            carmodel1 = "MINI";
            break;
        case 'B':
            carmodel1 = "MICRO";
            break;
        case 'C':
            carmodel1 = "SEDAN";
            break;
        case 'D':
            carmodel1 = "XL";
            break;
        }

        string temp = to_string(d1) + "/" + to_string(m1) + "/" + to_string(y1);
        date = temp;
        ofstream out;
        code = RandomString(10);
        out.open("book.txt", ios ::app);
        out << code << " " << customername << " " << date << " " << days << " " << carmodel1 << "\n";
        out.close();
    }

    void calculate()
    {
        sleep(1);
        system("CLS");
        cout << "Calculating rent. Please wait......" << endl;
        sleep(2);
        if (carmodel == "A" || carmodel == "a")
            rentalfee = (days * 56) * number_car;
        if (carmodel == "B" || carmodel == "b")
            rentalfee = (days * 60) * number_car;
        if (carmodel == "C" || carmodel == "c")
            rentalfee = (days * 75) * number_car;
        if (carmodel == "D" || carmodel == "d")
            rentalfee = (days * 100) * number_car;
    }

    // Function to display the Customer invoice for the car service booking.
    void showrent()
    {
        cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Invoice No. :"
             << "----------------------|" << setw(10) << "#" << code
             << " |" << endl;
        cout << "\t\t	| Customer Name:"
             << "---------------------|" << setw(10) << customername << " |" << endl;
        cout << "\t\t	| Car Model :"
             << "------------------------|" << setw(10) << carmodel << " |" << endl;
        cout << "\t\t	| No. of Cars :"
             << "----------------------|" << setw(10) << number_car << " |" << endl;
        cout << "\t\t	| Number of days :"
             << "-------------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t	| PickUp Date :"
             << "----------------------|" << setw(10) << date << " |" << endl;
        cout << "\t\t	| Your Rental Amount is :"
             << "------------|" << setw(10) << rentalfee << " |" << endl;
        cout << "\t\t	| Caution Money :"
             << "--------------------|" << setw(10) << "0"
             << " |" << endl;
        cout << "\t\t	| Advanced :"
             << "-------------------------|" << setw(10) << "0"
             << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Total Rental Amount is :"
             << "-------|" << setw(10) << rentalfee << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	 # This is a computer generated invoce and it does not" << endl;
        cout << "\t\t	 require an authorised signture #" << endl;
        cout << " " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	You are advised to pay up the amount before due date." << endl;
        cout << "\t\t	Otherwise penelty fee will be applied" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        int f;
        system("PAUSE");

        system("CLS");
        cout << "\t\t\t	Thanks for dealing with us" << endl;
    }
};

// Starting point of the code
class welcome
{
public:
    int welcome1()
    {
        // Reading file data to display onto the console
        ifstream in("welcome.txt");

        if (!in)
            cout << "Cannot open input file.\n";

        char str[1000];

        while (in)
        {
            in.getline(str, 1000);
            if (in)
                cout << str << endl;
        }

        in.close();
        sleep(1);
        cout << "\nStarting the program. Please wait....." << endl;
        sleep(1);
        cout << "\nLoading up files....." << endl;
        sleep(1);
        system("CLS");
    }
};

int main()
{
    welcome obj1;
    obj1.welcome1();

    int choice;
validChoice:
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
    cout << "\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t     1.SIGNUP \n";
    cout << "\n\t\t\t\t\t\t     2.LOGIN \n";
    cout << "\n\t\t\t\t\t\t     3.Admin \n";
    cout << "\n\t\t\t\t\t\t     4.Exit \n";
    cout << "\t\t\t\t\t------------------------------\n\n";
    cout << "\n\t\t\t\t Enter Your Choice :\t";

    cin >> choice;

    if (choice == 1)
    {
        cout << "Redirecting.........";
        sleep(2);
        system("CLS");
        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
        cout << "\t\t\t\t\t------------------------------";
        cout << "\n\t\t\t\t\t\t     SIGNUP \n";
        cout << "\t\t\t\t\t------------------------------\n\n";

        string name;
        string id;
        string pwd;

        cout << "\n\t\t\t\t Enter Your     Name :\t";
        cin >> name;
        cout << "\n\t\t\t\t Enter Your   UserID :\t";
        cin >> id;
        cout << "\n\t\t\t\t Enter Your password :\t";
        cin >> pwd;

        SignUp obj_3(name, id, pwd);
        rent obj2(id);
    again:
        obj2.decide();
        obj2.calculate();
        obj2.showrent();
        goto again;

        system("PAUSE");
        system("CLS");
    }
    else if (choice == 2)
    {
        cout << "Redirecting.........";
        sleep(2);
        system("CLS");
        rent obj2(SignUp ::login());
    again1:
        obj2.decide();
        obj2.calculate();
        obj2.showrent();
        goto again1;
    }
    else if (choice == 3)
    {
        cout << "Redirecting.........";
        sleep(2);
        system("CLS");
        rent obj4(SignUp ::Adminlogin());

        ifstream file;
        string st4;
        file.open("Book.txt");
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Transaction_ID \t\t\t  Customer Name  \t\t Date \t\t\t  No. of cars \t\t Car Model\n " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        while (file >> st4)
        {

            cout << st4 << "\t\t\t| ";
            file >> st4;
            cout << st4 << "\t\t\t| ";
            file >> st4;
            cout << st4 << "\t\t\t| ";
            file >> st4;
            cout << st4 << "\t\t\t| ";
            file >> st4;
            cout << st4 << endl;
        }
        file.close();
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Do you want to continue (Y/N) :";
        char ch;
        cin >> ch;
        if (ch == 'Y' ||ch== 'y')
        {
            system("CLS");
            goto validChoice;
        }
        else if(ch=='N'||ch=='n')
        {
            exit(0);
        }
    }
    else if (choice == 4)
    {
        exit(0);
    }
    else
    {
        cout << "\n\t\t\t\t\t\t Enter Valid Choice Only!!!!!!!!";
        sleep(2);
        system("CLS");
        goto validChoice;
    }

    return 0;
}
