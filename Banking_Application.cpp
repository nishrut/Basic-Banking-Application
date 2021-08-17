// Basic Banking Application 

/*
    Source: C++ Reference Books
    Date: 9th October, 2020
*/

#include<iostream>

#include<iomanip>           // For "setw()",this library file is used to Manipulate the OUTPUT of C++ program.

#include<string.h>		   // For getline() function of string header file.

using namespace std;

class Bank                  // Core of Banking Application
{
    char name[30];            	   // Name of User
    long long int acno;           // Account Number of User
    char actype[30];         	 // Type of Account User has
    int bal;               		// Balance of User
    
	public:
    
	    void opbal(void);           // Method: Opening balance of User
    
	    void deposit(void);         // Method: Deposits of User
    
	    void withdraw(void);        // Method: Withdrawings of User
    
	    void display(void);         // Method: Display the Menu to User
};

void Bank :: opbal(void)            // For PERSONAL INFORMATION of User
{	
    cout<<"ENTER YOUR NAME: ";
    cin.ignore();					
    cin.getline(name,30);			// OR you can use "getline(cin,var_name)"		   
    /*
    When "cin.getline()" reads from the input, there is a newline character left in the input stream,
    so it doesn't read your c-string. 
	Use "cin.ignore()" beore calling getline()
    "getline()" function is used to read the whitespace of user input string.
    */
    
	cout<<"ENTER YOUR A/c NUMBER: ";
    cin>>acno;
    
	cout<<"ENTER TYPE OF YOUR A/c: ";
    cin.ignore();
    cin.getline(actype,30);
    
	cout<<"ENTER YOUR OPENING BALANCE: ";
    cin>>bal;
}

void Bank :: deposit(void)          // For DEPOSITS of User
{
	int deposit = 0;                // To DEPOSIT Amount by User
    
	cout<<"ENTER DEPOSIT AMOUNT: ";
    cin>>deposit;
    
	deposit = deposit + bal;
    
	cout<<endl<<"DEPOSIT BALANCE = "<<deposit<<endl;
    
	bal = deposit;
}

void Bank :: withdraw(void)         // For WITHDRAWINGS of User
{
    int withdraw;                   // To WITHDRAW Amount by User
    
	cout<<"BALANCE AMOUNT = "<<bal<<endl;
    
	cout<<endl<<"ENTER WITHDRAW AMOUNT: ";
    cin>>withdraw;
    
	bal = bal - withdraw;
    
	cout<<endl<<"AFTER WITHDRAWING BALANCE IS "<<bal<<endl;
}

void Bank :: display(void)          // DISPLAY Menu of the User
{
    cout<<endl<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    
	cout<<setw(50)<<"DETAILS"<<endl;				
	/*
	"setw()" is used to sets the field width to be used on output operations, library file: "iomanip"
    */
	cout<<setw(46)<<"NAME	   "<<name<<endl;
    
	cout<<setw(49)<<"A/c NUM.	  "<<acno<<endl;
    
	cout<<setw(51)<<"A/c TYPE     "<<actype<<endl;
    
	cout<<setw(51)<<"BALANCE      "<<bal<<endl;
    
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
}

int main()
{
    Bank b1;				// Object of Bank; name of object: "b1"
    
	int choice;                     // To give CHOICEs available to the User
    
	cout<<endl<<"ALL TRANSACTIONS ARE DONE IN INR";

    do                              // loop for the CHOICEs
    {
    	cout<<endl<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        
		cout<<"CHOICE LIST"<<endl<<endl;
        
		cout<<"1) TO ASSIGN OPENING BALANCE"<<endl;
        
		cout<<"2) To DEPOSIT"<<endl;
        
		cout<<"3) To WITHDRAW"<<endl;
        
		cout<<"4) TO DISPLAY ALL DETAILS"<<endl;
        
		cout<<"5) EXIT"<<endl;

        cout<<endl<<"ENTER YOUR CHOICE: ";
        cin>>choice;
        
		cout<<endl<<"------------------------------------------------------------------------------------------------------------------------"<<endl;

        switch(choice)              // For Selection of the CHOICE
        {
            case 1: b1.opbal();     // Call the Balance Method
                    break;
        
		    case 2: b1.deposit();   // Call the Deposit Method
                    break;
        
		    case 3: b1.withdraw();  // Call the Withdraw Method
                    break;
        
		    case 4: b1.display();   // Call the Display Method
                    break;
        
		    case 5: goto end;
        } 
    } while(1);
    
	end:
    
	return 0;
} 
