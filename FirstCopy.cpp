#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <iomanip> 
using namespace std;
 int ctr = 0;

class SignUp{
	public :  string username;
	          string emailId ;
	          string password;
	          int size;
	          
	          
    public : SignUp( string str,  string id ,  string pass){
                 username = str;
                 emailId = id;
                 password = pass;
                 string st1;
                 ifstream in;
                 in.open("userData.txt");  
                 ofstream out;
                 out.open("temp.txt");

                 while(in>>st1){
		   	   //  in>>st1;
		   	     out<<st1<<" ";
		   	     if((++ctr) %3 == 0){
		   	     	out<<"\n";
					}
//				 out<<st1<<" ";
//		   	     in>>st1;
//		   	     cout<<st1;
//		   	     out<<st1<<" ";
//		   	     in>>st1;
//		   	     cout<<st1;
//		   	     out<<st1<<" ";
//		   	     sleep(5);
//		   	     out<<"\n";
		   	    }
		   	     //out<<"\n";
                 out<<username<<" ";
                 out<<emailId<<" ";
                 out<<password<<" ";
                 out.close();
                 in.close(); 
				 char filename[] = "userData.txt";               
				  if(remove(filename) == 0){
                 	cout<<"file removed";
				 }
				 else{
				 	cout<<"error";
				 }
                rename("temp.txt", "userData.txt");
				 login();              
	}
public : static	int login(){
                system("CLS");
                string pass ="";
                char ch;
                cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
                cout<<"\t\t\t\t\t------------------------------";
                cout<<"\n\t\t\t\t\t\t     LOGIN \n";	
                cout<<"\t\t\t\t\t------------------------------\n\n";	
                cout << "\t\t\t\t\t Enter  ID: ";
                string id;
                cin>>id;
                cout << "\t\t\t\t\t Enter PWD: ";
                cin>>pass;
                if(Authenticate(id,pass)){
                cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
                system("PAUSE");
                system ("CLS");
                }else{
                cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
                system("PAUSE");
                system("CLS");
                login();
                }
                return 1;
}
	
    public:	static bool Authenticate(string id, string pass){
		   ifstream in;
           string st1 , st2 , st3;
		   in.open("userData.txt");
		   while(in.eof() == 0){
		   	     in>>st1;
		   	     in>> st2;
		   	     in>> st3;
		   	     
		   	     if(id == st2 && pass == st3){
		   	     	return true;
				}
		   }
		   in.close();
		   return false;
	}
};
class customer 
{
	private:
	public:
	string customername;
    string carmodel;
    int carnumber;
    char data;
    // variables defined in this class in public mode.
};
class rent : public customer // inhereted class from customer class
{
	public:
//	int days=0,rentalfee=0; // additional int vatiables defined
    int days;
    int rentalfee;
	void data()
	{
//	int login();
//	login();
//	cout << "\t\t\t\tPlease Enter your Name: "; //taking data from the user
//    cin >> customername;
//    cout<<endl;
//    do
//    {
//        cout <<"\t\t\t\tPlease Select a Car"<<endl; //giving user a choice to select among three different models
//        cout<<"\t\t\t\tEnter 'A' for Tesla 20011."<<endl;
//        cout<<"\t\t\t\tEnter 'B' for Hyundai 2015."<<endl;
//        cout<<"\t\t\t\tEnter 'C' for Ford 2017."<<endl;
//        cout<<endl;
//        cout<<"\t\t\t\tChoose a Car from the above options: ";
//        cin >>carmodel;
//        cout<<endl;
// cout<<"--------------------------------------------------------------------------"<<endl;
// if(carmodel=="A")
// {
// 	system("CLS");
// 
//		cout<<"You have choosed Tesla model 2011"<<endl;
//		 ifstream inA("A.txt"); //displaying details of model A
//         char str[200];
//         while(inA) {
//         inA.getline(str, 200);  
//         if(inA) cout << str << endl;
//}
//sleep(2);
//  }
//  if(carmodel=="B")
//  {
//  	system("CLS");
//  
//		cout<<"You have choosed Hyundai model 2015"<<endl;
//		 ifstream inB("B.txt"); //displaying details of model B
//         char str[200];
//         while(inB) {
//         inB.getline(str, 200);  
//         if(inB) cout << str << endl;
//         
//     }
//     sleep(2);
// }
// if(carmodel=="C")
// {
// 	system("CLS");
//	     cout<<"You have choosed Ford model 2017"<<endl;
//		 ifstream inC("C.txt"); //displaying details of model C
//         char str[200];
//         while(inC) {
//         inC.getline(str, 200);  
//         if(inC) cout << str << endl;
//     }
//     sleep(2);
//}  
//if(carmodel !="A" && carmodel !="B" &&  carmodel !="C" )
//     
//      cout<<"Invaild Car Model. Please try again!"<<endl;
//        }
//while(carmodel !="A" && carmodel !="B" &&  carmodel !="C" );
//    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<endl;
   do
    {
        cout <<"\t\t\t\tPlease Select a Car"<<endl; //giving user a choice to select among three different models
        cout<<"\t\t\t\tEnter 'A' for Mini."<<endl;
        cout<<"\t\t\t\tEnter 'B' for Micro."<<endl;
        cout<<"\t\t\t\tEnter 'C' for Sedan."<<endl;
        cout<<"\t\t\t\tEnter 'D' for XL."<<endl;
        cout<<endl;
        cout<<"\t\t\t\tChoose a Car from the above options: ";
        cin >>carmodel;
        cout<<endl;
 cout<<"--------------------------------------------------------------------------"<<endl;
 if(carmodel=="A")
 {
     first :
 	system("CLS");
 	cout<<"\t\t\t\tchoose 1 for Bajaj Qute taxi."<<endl;
 	cout<<"\t\t\t\tchoose 2 for Maruti Suzuki."<<endl;
 	cout<<"\t\t\t\tchoose 3 for Tesla model 2011."<<endl;
 	int c;
 	cin>>c;
 	if(c==1){
            cout<<"You have choosed Bajaj Qute taxi."<<endl;
             ifstream inA("1.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);  
         if(inA) cout << str << endl;
    
        
 	}
 }
	 else if(c==2){
 	    cout<<"you have choose Maruti suzuki"<<endl;
 	     ifstream inA("A.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);  
         if(inA) cout << str << endl;
 	
 	}}else if(c==3){
 	cout<<"You have choosed Tesla model 2011"<<endl;
		 ifstream inA("A.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);  
         if(inA) cout << str << endl;
       }
    }else{
    cout<<"\t\t\t\tSelect from given inputs."<<endl;
    goto first;
    }
}
sleep(2);
  
  if(carmodel=="B")
  {
  	 second :
 	system("CLS");
 	cout<<"\t\t\t\tchoose 1 for swift ."<<endl;
 	cout<<"\t\t\t\tchoose 2 for Baleno."<<endl;
 	cout<<"\t\t\t\tchoose 3 for Wagon R."<<endl;
 	int c;
 	cin>>c;
 	if(c==1){
            cout<<"You have choosed Swift."<<endl;
             ifstream inA("1.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);  
         if(inA) cout << str << endl;
    
        
 	}
 	}else if(c==2){
 	    cout<<"you have choose Baleno."<<endl;
 	     ifstream inA("A.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);  
         if(inA) cout << str << endl;
 	
 	}
 	}else if(c==3){
 	cout<<"You have choosed Wagon R."<<endl;
		 ifstream inA("A.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);  
         if(inA) cout << str << endl;
       }
    }else{
    cout<<"\t\t\t\tSelect from given inputs."<<endl;
    goto second;
    }
		
     }
     sleep(2);
 
 if(carmodel=="C")
 {
 	third :
 	system("CLS");
 	cout<<"\t\t\t\tchoose 1 for Honda Ciaz."<<endl;
 	cout<<"\t\t\t\tchoose 2 for Honda City."<<endl;
 	//cout<<"\t\t\t\tchoose 3 for Tesla model 2011."<<endl;
 	int c;
 	cin>>c;
 	if(c==1){
            cout<<"You have choosed Honda Ciaz"<<endl;
             ifstream inA("1.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);  
         if(inA) cout << str << endl;
    
        
 	}
 	}else if(c==2){
 	    cout<<"you have choose Honda City"<<endl;
 	     ifstream inA("A.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);  
         if(inA) cout << str << endl;
 	
 	}
 	}else{
    cout<<"\t\t\t\tSelect from given inputs."<<endl;
    goto third;
    }
     sleep(2);
}
if(carmodel=="D")
 {
 	fourth :
 	system("CLS");
 	cout<<"\t\t\t\tchoose 1 for Toyata Innova."<<endl;
 	cout<<"\t\t\t\tchoose 2 for Ertiga."<<endl;
 	//cout<<"\t\t\t\tchoose 3 for Tesla model 2011."<<endl;
 	int c;
 	cin>>c;
 	if(c==1){
            cout<<"You have choosed Toyata Innova."<<endl;
             ifstream inA("1.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);  
         if(inA) cout << str << endl;
    
        
 	}
 	}else if(c==2){
 	    cout<<"you have choose Ertiga."<<endl;
 	     ifstream inA("A.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);  
         if(inA) cout << str << endl;
 	
 	}
 	}else{
    cout<<"\t\t\t\tSelect from given inputs."<<endl;
    goto fourth;
    }
     sleep(2);
}
  
if(carmodel !="A" && carmodel !="B" &&  carmodel !="C"&& carmodel!="D" )
     
      cout<<"Invaild Car Model. Please try again!"<<endl;
      }
    while(carmodel !="A" && carmodel !="B" &&  carmodel !="C" && carmodel!="D");
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout << "Please provide following information: "<<endl; 
	//getting data from user related to rental service
    cout<<"Please select  No. of cars : ";
    cin >> carnumber;
    cout<<"Number of days you wish to rent the car : ";
    cin >> days;
    cout<<endl;
	}
	void calculate()
	{
		sleep(1);
		system ("CLS");
		cout<<"Calculating rent. Please wait......"<<endl;
		sleep(2);
		if(carmodel == "A"||carmodel=="a")
        rentalfee=(days*56)*carnumber;
        if(carmodel == "B" ||carmodel=="b")
        rentalfee=(days*60)*carnumber;
        if(carmodel == "C" ||carmodel=="c")
        rentalfee=(days*75)*carnumber;
    }
void showrent()
    {
    cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb81353"<<" |"<<endl;
    cout << "\t\t	| Customer Name:"<<"-----------------|"<<setw(10)<<customername<<" |"<<endl;
    cout << "\t\t	| Car Model :"<<"--------------------|"<<setw(10)<<carmodel<<" |"<<endl;
    cout << "\t\t	| Car No. :"<<"----------------------|"<<setw(10)<<carnumber<<" |"<<endl;
    cout << "\t\t	| Number of days :"<<"---------------|"<<setw(10)<<days<<" |"<<endl;
    cout << "\t\t	| Your Rental Amount is :"<<"--------|"<<setw(10)<<rentalfee<<" |"<<endl;
    cout << "\t\t	| Caution Money :"<<"----------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "\t\t	| Advanced :"<<"---------------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "\t\t	 ________________________________________________________"<<endl;
    cout <<"\n";
    cout << "\t\t	| Total Rental Amount is :"<<"-------|"<<setw(10)<<rentalfee<<" |"<<endl;
    cout << "\t\t	 ________________________________________________________"<<endl;
    cout << "\t\t	 # This is a computer generated invoce and it does not"<<endl;
    cout << "\t\t	 require an authorised signture #"<<endl;
    cout <<" "<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
    cout << "\t\t	Otherwise penelty fee will be applied"<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    int f;
    system("PAUSE");
    
    system ("CLS");
    cout << "\t\t\t	Thanks for dealing with us"<<endl;
	}
};
class welcome //welcome class
{
	public:
	int welcum()
	{
    ifstream in("welcome.txt"); //displaying welcome ASCII image text on output screen fn1353

    if(!in) {
    cout << "Cannot open input file.\n";
    }
    char str[1000];
    while(in) {
    in.getline(str, 1000);  // delim defaults to '\n' cp
    if(in) cout << str << endl;
  }
  in.close();
  sleep(1);
  cout<<"\nStarting the program please wait....."<<endl;
  sleep(1);
  cout<<"\nloading up files....."<<endl;
  sleep(1); //function which waits for (n) seconds
  system ("CLS"); //cleares screen
}

};
int main()
{
welcome obj1; //object created for welcome class
obj1.welcum(); //welcum function is called
rent obj2;
 int choice;
validChoice:  
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
   cout<<"\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t     1.SIGNUP \n";	
   cout<<"\n\t\t\t\t\t\t     2.LOGIN \n";	
   cout<<"\t\t\t\t\t------------------------------\n\n";
   cout<<"\n\t\t\t\t Enter Your Choice :\t";
  
   cin>>choice;
 //  system("PAUSE");
   cout<<"Redirecting.........";
   sleep(3);
   system("CLS");
   if(choice ==1){
   	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
   cout<<"\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t     SIGNUP \n";		
   cout<<"\t\t\t\t\t------------------------------\n\n";
  string name;
  string id;
  string pwd;
   cout<<"\n\t\t\t\t Enter Your     Name :\t";
   cin>>name;
   cout<<"\n\t\t\t\t Enter Your   UserID :\t";
   cin>>id;
   cout<<"\n\t\t\t\t Enter Your password :\t";
   cin>>pwd;
   SignUp obj_3(name,id,pwd); 
    system("PAUSE");
    system("CLS");
   }else if(choice ==2){
   //	int login();
   	SignUp ::login();
   }else{
   	cout<<"\n\t\t\t\t\t\t Enter Valid Choice Only!!!!!!!!";
   	sleep(2);
   	system("CLS");
   	goto validChoice;
   }
//object created for rent class and further member functions are called
obj2.data();
obj2.calculate();
obj2.showrent();

return 0; //end of the program
}



