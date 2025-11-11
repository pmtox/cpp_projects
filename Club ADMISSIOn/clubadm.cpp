// Project: CLUB approval Program
// Author: Prashant Mishra
// Features: file handeling, saves data, feedbacks,Booleans,questions, 3-attempt limit, 

#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

void gySOL(string name , bool passed){
	if(passed){
		cout << "HELLO, " << name << "!" << endl;
		cout<< "WELCOME TO THE CLUB!" << endl;
	} else {
		cout<< "Soryy, " << name << " Better luck next time" << endl;
	}
}
void userfeedbacks(string feedback , string name){
	cout << name << ", " << "Thanks for feedback!" << endl;
}

int validInput(string question , int &attempts){
	int answer;
	while (attempts > 0){
		cout << question << "ENTER 1 for yes ; 0 for NO"<< " : ";
		cin >> answer;
		
		if (answer == 0 || answer == 1){
			return answer;
		} else{
			attempts--;
			if(attempts > 0){
				cout<< "You have " << attempts << " left" << endl;
			} else{
				cout<< "YOU DONT DESERVE TO BE HERE!" << endl;
				exit(0);
			}
		}
	}
}
void applicantsData(string name , bool passed , string feedback){
	ofstream file("applications.txt" , ios::app);
	
	if (!file){
	cout<< "ERROR IN OPENING THE FILE";
	} 
	file << "Name : " << name << " | Result : " << (passed?"Passed" : "Failed") << endl <<"Feedback : " << (!feedback.empty()? feedback : "NIL") <<endl;
	file.close();
	cout << "Applicant's Data is stored successfully" << endl;
}

int main(){
	string name;
	cout<< "Enter your name" << " : ";
	cin>> name;
	
	cout<< "Write 1 if done 0 if not"<< endl;
	int attempts = 4;
	int question1 = validInput("YOU KNOW PROGRAMMING? : " , attempts);
	int question2 = validInput("You've done DSA? : " , attempts);
	int question3 = validInput("Done any projects before? : " , attempts);;

	bool passed = question1 && question2 && question3;
		gySOL(name , passed);
		
	string feedback;
	cout << "ANY FEEDBACK? : " ;
	cin.ignore();
	getline(cin , feedback);
	
	userfeedbacks(feedback, name);
	
	applicantsData(name , passed, feedback);
		 return 0;
}

