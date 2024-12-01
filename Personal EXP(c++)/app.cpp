#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<fstream>
#include<iomanip>

//1.To strore individual expense
struct Expense{
	std::string category;
	double amount;
	std::string date;
	
	//2.Display Expenses
	void display() const{
		std:: cout << std::setw(10) << category << "\t"
		           << std::setw(8) << amount << "\t"
		           << date << std::endl;	
	}
};
struct Budget{ //pascal case
	double totalIncome; //Camelcase
	double totalExpense;
	Budget() : totalIncome(0.0),totalExpense(0.0){
	}
	
	double remainingBudget() const{
		return totalIncome - totalExpense;
	}
	
	void displayBudgetStatus() const{
		std:: cout<< "Total Income : $"<<totalIncome << std::endl;
		std:: cout<< "Total Expense : $"<<totalExpense <<std::endl;
		double balance = remainingBudget();
		std::cout << "Remaining Balance : $"<< balance << std::endl;
		if(balance >= 0){
			std::cout << "You are within your planned budget";
	    }
		else{
			std::cout << "Warning : You have exceeded your planned budget ! ";
		}	
		
	}
};
void addExpense(std::vector<Expense> &expenses,Budget &budget){
	Expense e;
	std::cout << "Enter expense category(eg.Food,Travel,Cloth etc..) : ";
	std::cin >> e.category;
	std::cout << "Enter amount : ";
	std::cin >> e.amount;
	std::cout << "Enter date (DD/MM/YYYY): ";
	std::cin >> e.date;
	expenses.push_back(e);
	budget.totalExpense += e.amount;
	std::cout << "Expense added successfully !\n";
}
void displayExpense(std::vector<Expense>& expenses){
	std::cout << "\n--- Expense List ---\n";
	std::cout << std::setw(10) << "| Category |" << "\t"
	          << std::setw(8) << "| Amount |" << "\t"
			  << "| Date |" << std::endl;
	for(size_t i = 0;i < expenses.size();++i){
		expenses[i].display();
	}		   	
}
void savetoFile(std::vector<Expense>& expenses){
	std::ofstream outFile("expenses.txt");
	for(size_t i = 0;i<expenses.size();++i){
		outFile << expenses[i].category << "," << expenses[i].amount << "," << expenses[i].date << std::endl;
		
	}
	outFile.close();
	std::cout << "Expenses saved to File successfully.\n";
}

void loadfromFile(std::vector<Expense>& expenses){
	std::ifstream inFile("expenses.txt");
	Expense e;
	while(inFile >> e.category >> e.amount >> e.date){
		expenses.push_back(e);
	}
	inFile.close();
}

int main(){
	Budget budget;
	std::vector<Expense> expenses;
	std::cout << "\t\t\t\t\t\t My Personal Exp Tracker \n ";
	std::cout << "\nEnter Total Income : $";
	std::cin >> budget.totalIncome;
	
	int choice;
	while(choice !=6){
		std::cout << " \nMenu:\n";
		std::cout << "1. Add Expense\n";
		std::cout << "2. Display Expenses\n";
		std::cout << "3. Display Budget Status \n";
		std::cout << "4. Save Expenses to File\n";
		std::cout << "5. Load Expenses from File\n";
		std::cout << "6. Exit\n";
		std::cout << "Enter Your Choice :\n";
		std::cin >> choice;
		
		switch(choice){
			case 1:
				addExpense(expenses,budget);
				break;
			case 2:
				displayExpense(expenses);
				break;
			case 3:
				budget.displayBudgetStatus();
				break;
			case 4:
				savetoFile(expenses);
				break;
			case 5:
				loadfromFile(expenses);
				break;
			case 6:
				std::cout << "Thank you for using My Personal Tracker. Adios!";
				break;	
			default:
			    std::cout << "Invalid amount.Please Try Again";
				break;					
	}
        }
    return 0;
}
	


