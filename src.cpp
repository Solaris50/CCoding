/*
 *  Banking Record Systems C++ Project
 *	Practice 1
 *  Created on: Dec. 16, 2019
 *  Author: sunthapa
 */

#include <iostream>
//using namespace std;

int main();

class banking {
private:
	char account_number[20];
	char first_name[10];
	char last_name[10];
	double total_Balance;

public:

void read_data();
void show_data(unsigned int account_number, std::string first_name, std::string last_name, unsigned int total_Balance);
void add_record(unsigned int account_number, std::string first_name, std::string last_name);
double search_record(unsigned int record_number);
double edit_record(unsigned int record_number);
double delete_record(unsigned int record_number);
};

void banking::read_data() {
	std::cout << "Enter Account Number: ";
	std::cin >> account_number;
	std::cout << std::endl;
	std::cout << "Enter First Name: ";
	std::cin >> first_name;
	std::cout << std::endl;
	std::cout << "Enter Last Name: ";
	std::cin >> last_name;
	std::cout << std::endl;
	std::cout << "Enter Balance: ";
	std::cin >> total_Balance;
	std::cout << std::endl;
}

void banking::show_data(unsigned int account_number, std::string first_name, std::string last_name, unsigned int total_Balance) {
	std::cout << "Account Number: " << account_number << std::endl;
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Balance: " << total_Balance << std::endl;
}
double banking::search_record(unsigned int record_number){
	banking::account_number[20];
	banking::total_Balance;
	int count{0};
	char l;

for(int i = 0; i < 20; i++){
	++count;
}
std::cout << "There are " << count << " records in the file"<< std::endl;
std::cout << "Enter Record Number to Search for ";
std::cin >> l;
return l;
}

int main() {
	int n;


	std::cout << "***Account Information System***"<< std::endl;
	std::cout << "Select one option below" << std::endl;
	std::cout << "\t1-->Add record to file" << std::endl;
	std::cout << "\t2-->Show record from file" << std::endl;
	std::cout << "\t3-->Search record from file" << std::endl;
	std::cout << "\t4-->Update Record" << std::endl;
	std::cout << "\t5-->Delete Record" << std::endl;
	std::cout << "\t6-->Quit" << std::endl;

	std::cout << "Enter your choice: ";
	std::cin >> n;

	if (n == 1){

		}
	else if(n==2) {

		}
	else if(n==3) {
		banking::account_number[20];
			banking::first_name[20];
			banking::last_name[20];
			banking::total_Balance;
		for ( int i = 0; i < 20; i++) {
			if (account_number[i] == l) {
				std::cout << "Account Number: " << l <<std::endl;
				std::cout << "First Name: " << first_name[i] << std::endl;
				std::cout << "Last Name: " << last_name[i] << std::endl;
				std::cout << "Current Balance: Rs " << total_balance;
			}
			else {
			}
		}
		}
	else if(n==4) {

		}
	else if(n==5) {

		}
	else if(n==6) {
		std::cout << "Thank you for your time";
		}
	else {
		std::cout << "Invalid Option Please Try Again";
	}
	return 0;
}



