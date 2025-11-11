//_______________________________________________________

// Project: Digital ATM Simulator
// Author: Prashant Mishra
// Features: PIN login, Deposit, Withdraw, 3-attempt limit

//________________________________________________________

#include<iostream>
using namespace std;
int main(){
	
long long balance = 1000;
long long deposit_amount;
int pin = 1234;
long long withdraw;
int mypin;
int options;
int attempts = 4;
bool accessgranted = false;
while(attempts > 0){
	cout<< "Enter Your Pin"<< " : ";
	cin>> mypin;
	if (mypin == pin){
		accessgranted = true;
		break;
	} else{
		attempts--;
		if(attempts > 0){
		cout << "You have " << attempts << " attempts Left" <<endl;
		} else{
		cout << endl <<"Your CARD is blocked due to wrong attempts";
		}
	}	
}
if (accessgranted){
	cout << "ACCESS GRANTED !!" << endl << endl << "---WELCOME TO ATM MENU---" << endl << endl;
	while (true){
	cout<< "MAIN MENU" << endl <<  endl;
	cout<< "HEY MEMBER" << endl;
	cout<<"1. Balance" << endl << "2. Deposit" << endl << "3. Withdraw" << endl<< "4. END" <<endl;
	cout<<endl;
	cout <<"Choose your option" << " : ";
	cin>>options;
	cout<<endl;
		switch (options){
			case 1:
				cout<< "Your balance is " << balance << endl << endl;
				break;
			case 2: 
				cout<<"ENTER AMOUNT TO DEPOSIT : ";
				cin >> deposit_amount;
				balance += deposit_amount;
				cout<< "Deposited " << deposit_amount << " to your account" << endl;
				cout<< "New balance is" << " : "  << balance << endl << endl;
				break;
			case 3:
				cout<< "ENTER AMOUNT TO WITHDRAW" << " : ";
				cin>> withdraw;
				if(withdraw <= balance){
					cout<< "Withdraw successfull "<< endl;
					balance = balance - withdraw;
					cout<< "New balance after withdraw : " << balance << " "<< endl;
				} else{
					cout<<"Insufficient balance!"<< endl << "please check your balance"<< endl << endl;
				}break;
			case 4:
				cout<<"BYE, HAVE A GREAT DAY..." << endl;
				return 0;
			default:
				cout<< "INVALID INPUT PLEASE TRY again!! " << endl;
			}
}
}
return 0;	
}
