#include <iostream>
#include <sstream>

#include "spending_cat.h"
#include "Event.h"
#include "currency.h"
#include "Month.h"
#include "Date.h"
#include "budget.h"

using namespace std;


int main() {

	/*
	Brief introduction & tutorial of project to user
	*/
	cout << "Hello! Welcome to my final project of my C++ Programming Class for Fall 2019 at Tsinghua University, "
		<< "a beautifully student-made budget application! It is my hope that my app can help you save your hard-earned "
		<< "money." << endl << endl;
	
	cout << "Author: Charlie Comeau // 龚成荫. Second year CS major from Georgia Tech, currently studying abroad in Beijing.";

	/*
	Clarifying Assumptions made during programming
	*/
	cout << "These are the following assumptions that I made while creating this. " << endl;
	cout << "1) Spending Events can be broken down into 3 categories: FIXED, VARIABLE, and SAVINGS." << endl << "\tFixed spendings "
		<< "stem from buying necessities and tend to cost about the same each month, such as rent, mortgage, car payments, "
		<< "taxes, college tuition, loans, food, and insurance." << endl;
	cout << "\tVariable spendings stem from purchases that are either infrequent, for non-necessities, or of unpredictable costs"
		<< ", such as eating out, going out, car repairs, house repairs, gifts, traveling, and \"fun money\"" << endl;
	cout << "\tSavings stem from money leftover after accounting for Fixed and Variable spendings. When major emergencies, unexpected events,"
		<< " or large spending events happen, such as a medical accident, family emergency, car accident, paying for college, "
		<< "vacations, etc, we pull out the extra money needed to pay from our savings. Savings is the most important part of " 
		<<  " a budget, but also the hardest part to do." << endl;
	cout << "2) For our budget, savings is not just money leftover after fixed and variable savings. We believe savings is and should be a "
		"deliberate act, thus we allow you to \"set aside\" money for savings and cannot be further used for other purposes. " 
		<< "Because savings is the hardest part of following a budget, we believe that making it a deliberate act will help " 
		<<  "our user achieve their monetary goals." << endl;
	cout << "3) The default settings of our budget follows the 50/30/20 rule - the most popular proportion for each " 
		<< "aforementioned spending category. That is to devote 50% to fixed costs, 30% to variable costs, and 20% for savings" << endl;
	cout << "4) For percentages and monetary amounts, we automatically round all input and output to the nearest hundredth. "
		<< "However for calculations that require more precision such as foreign exchange, we do not round until after the "
		<< "initial calculation. As a result, conditional spending amounts and multiple foreign exchange changes may" 
		<< " be off by a hundredth of a percent or one monetary cent." << endl;
	cout << "5) This budget is a budget for one calendar month, thus all spending events should happen within that month." << endl;
	cout << "6) This budget accounts for money leftover AFTER TAX, or after-tax income." << endl;
	cout << "7) This budget assumes that all events within the budget are of the same currency." << endl << endl;

	/*
	Flashy fancy features
	*/
	cout << "FAAAAANCY features of this application!" << endl;
	cout << "1) Can perform for-ex(foreign exchange) operations! Between the US Dollar, the Chinese Yuan (Renminbi), "
		<< "the Euro, and the British Pound (USD, CNY, EUR, GBP)" << endl;
	cout << "2) Automatically calculates conditional spending amounts and percentages of each category: how much money allocated"
		<< " for each category, how much money and the percentage of each category already spent, how much money and the percentage"
		<< " of each category left to spend / can still spend." << endl;
	cout << "3) Automatically calculates total spending amounts and percentages of each category: how much money and the percentage "
		<< "already spent and how much money and the percentage left to spend / can still spend" << endl;
	cout << "4) Can choose your own percentages for each of the spending categories - must sum to 100" << endl << endl;

	/*
	Step-by-step general features of input
	*/
	cout << "General features of this application:" << endl;
	cout << "1) Choose your currency" << endl;
	cout << "2) Choose your month" << endl;
	cout << "3) Enter your after-tax income " << endl;
	cout << "4) Enter your conditional Percentages for the 3 spending categories (50/30/20 default or a different combination that"
		<< " sums to 100" << endl;
	cout << "\t4.1) Confirm whether all previous inputted data is correct. If not, repeat 1-4)" << endl; 
	cout << "5) Begin entering your events! Continue until you have entered them all" << endl;
	cout << "\t5.1) Enter in the event date" << endl;
	cout << "\t5.2) Enter in the event type" << endl;
	cout << "\t5.3) Enter in the event monetary amount" << endl;
	cout << "\t5.4) Enter in the event name" << endl;
	cout << "\t5.5) If needed, enter in an event note" << endl;
	cout << "\t5.6) Confirm whether all previous event inputted data is correct. If not, repeat 5.1-5.5" << endl;
	cout << "6) After initial event input, if needed, can now modify existing event & budget data" << endl;
	cout << "\t7.1) Add an additional event (repeats steps 5.1-5.5)" << endl;
	cout << "\t7.2) Delete an event" << endl;
	cout << "\t7.3) Change an event's monetary amount" << endl;
	cout << "\t7.4) Change an event's spending type" << endl;
	cout << "\t7.5) Change an event's name" << endl;
	cout << "\t7.6) Change an event's note" << endl;
	cout << "\t7.7) Change the conditional percentages for the spending types of the budget" << endl;
	cout << "\t7.8) Change total after-tax income" << endl;
	cout << "\t7.9) Change currency used (for-ex - foreign exchange operation)" << endl;
	cout << "8) Can continue modifying events and budgets as needed" << endl;
	cout << "******Best experience comes from expanding interaction page to full screen!******" << endl << endl;

	cout << "If you've made it this far, thank you for reading the tutorial. Now, time to start your budget!" << endl << endl;
	
	Budget cash;
	cin >> cash;
	
	/*
	Sample data used during testing! If you want to verify the correctness of my calculations, but
	don't want to type everything in, here is a sample budget, complete with relevant calculations

	In order to use, comment out above Budget "cash" & cin initialization and uncomment below budget 
	"cash" & cash's addEvent initializations
	*/

	//Budget cash(USD, FEB, 10000, 40, 40, 20);

	//cash.addEvent(Event(USD, FIXED, 1000, "Event 1", "I do hope this works", FEB, 1));
	//cash.addEvent(Event(USD, VARIABLE, 2200, "Event 2", "double trouble!", FEB, 2));
	//cash.addEvent(Event(USD, FIXED, 331, "Event 3", "Groceries with mom", FEB, 3));
	//cash.addEvent(Event(USD, SAVINGS, 39.439, "Event 4", "My attempt at savings", FEB, 4));
	//cash.addEvent(Event(USD, VARIABLE, 22, "Event 5", "Sophie's gift", FEB, 5));
	//cash.addEvent(Event(USD, SAVINGS, 11.208765, "Event 6", "Hallelujah", FEB, 6));

	//cash.calculate();
	//cout << cash;

	/*
	Below are my debug statements, used to verify all of the modification operations
	*/

	// checks deleteEvent() for all 3 spending types
	//cash.deleteEvent(6); // savings
	//cash.deleteEvent(2); // variable
	//cash.deleteEvent(1); // fixed

	// checks changeEventAmount() for all 3 spending types
	//cash.changeEventAmount(1, 900); // fixed
	//cash.changeEventAmount(2, 1200); // variable
	//cash.changeEventAmount(6, 21.21); // savings

	// checks changeEventType() for all 6 spending type combinations
	//cash.changeEventType(1, VARIABLE); // fixed to var
	//cash.changeEventType(2, FIXED); // var to fixed
	//cash.changeEventType(1, SAVINGS); // fixed to save
	//cash.changeEventType(6, FIXED); // save to fixed
	//cash.changeEventType(5, SAVINGS); // var to save
	//cash.changeEventType(6, VARIABLE); // save to var
	//cash.changeEventType(1, FIXED); // event 1 is already FIXED, nothing's suppose to change

	// checks changeEventName()
	//cash.changeEventName(1, "testing...");

	// checks changeEventNote()
	//cash.changeEventNote(2, "oopsie poopsies");

	// checks changeConditionalP to default %s
	//cash.changeConditionalP(.4555, .202, .3425);

	// checks changeAfterTaxIncome()
	//cash.changeAfterTaxIncome(20000);

	// checks changeCurrency from USD to CNY
	//cash.changeCurrency(CNY);

	// statements used for printing new budget
	cash.calculate();
	cout << cash << endl;

	string change;
	const int smallWidth = 8;
	cout << "Would you like to change any data? Please enter \"y\" for yes, or anything else otherwise" << endl;
	cin >> change;

	/*
	Budget editing loop continues until user decides to stop, uses string
	*/
	while (change == "y") {
		string changeNum;
		cout << "What would you like to change? Please enter a valid input" << endl << endl;
		cout << "1 = add an additional Event" << endl
			<< "2 = delete an Event" << endl
			<< "3 = change an Event's monetary amount" << endl
			<< "4 = change an Event's spending type" << endl
			<< "5 = change an Event's name" << endl
			<< "6 = change an Event's note" << endl
			<< "7 = change conditional percentages for the spending types" << endl
			<< "8 = change total After-tax income" << endl
			<< "9 = change currency used (forex foreign exchange)" << endl;
		cin >> changeNum;

		/*
		Uses a string for error handling when input contains non-numbers
		*/
		while (!(changeNum == "1" || changeNum == "2" || changeNum == "3" || changeNum == "4" || changeNum == "5"
			|| changeNum == "6" || changeNum == "7" || changeNum == "8" || changeNum == "9")) {
				cout << "INVALID NUM INPUT, MUST BE AN INTEGER (1-9)" << endl;
				cin >> changeNum;
		}

		if (changeNum == "1") { // Adds an event to the bottom of the budget
			Event e(cash.getCurr(), nullSpending, -1, "", "", cash.getMonth());
			cin >> e;
			cash.addEvent(e);
		} else if (changeNum == "2") { // Deletes an event at index i
			string done = "n";
			int realIndex;
			
			while (done == "n") {
				realIndex = 0;
				/*
				Uses stringstream for error handling when index amount input contains non-numbers
				*/
				string pseudoIndex;
				cout << "Please enter a valid index from 1 to " << cash.getNumEvents() 
					<< " of the event that you would like to delete" << endl;
				cin >> pseudoIndex;
				stringstream first(pseudoIndex);
			
				first >> realIndex;
				while (realIndex < 1 || realIndex > cash.getNumEvents()) {
					cout << "INVALID INDEX INPUT, MUST BE AN INTEGER FROM 1 TO " << cash.getNumEvents() << endl;
					string innerIndex;
					cin >> innerIndex;
					stringstream next(innerIndex);
					next >> realIndex;
				}

				/*
				Asks for user confirmation over correctness of inputted data
				-index of budget event to be deleted
				*/
				cout << "Please confirm whether your inputted data is correct. If not, please enter \"n\""
					<< " , otherwise enter anything else" << endl << endl;
				cout << "INDEX TO BE DELETED: " << realIndex << endl;
				cout << "EVENT IN QUESTION)    " << cash[realIndex - 1];
				cin >> done;
			}
			cash.deleteEvent(realIndex - 1);

		} else if (changeNum == "3") { // modifies an event amount at index i
			string done = "n";
			int realIndex;
			double realAmount = 0;

			
			while (done == "n") {
				realIndex = 0;
				/*
				Uses stringstream for error handling when index amount input contains non-numbers
				*/
				string pseudoIndex;
				cout << "Please enter a valid index from 1 to " << cash.getNumEvents() 
					<< " of the event you would like to modify" << endl;
				cin >> pseudoIndex;
				stringstream first(pseudoIndex);
				first >> realIndex;
				while (realIndex < 1 || realIndex > cash.getNumEvents()) {
					cout << "INVALID INDEX INPUT, MUST BE AN INTEGER FROM 1 TO " << cash.getNumEvents() << endl;
					string innerIndex;
					cin >> innerIndex;
					stringstream next(innerIndex);
					next >> realIndex;
				}

				/*
				Uses stringstream for error handling when monetary amount input contains non-numbers
				*/
				string pseudoAmount;
				cout << "Please enter in a the new monetary amount. Note decimal values are rounded to the nearest hundredth" 
					<< ", and input that begins with non-numbers are interpreted as 0" << endl;
				cin >> pseudoAmount;
				stringstream second(pseudoAmount);
				second >> realAmount;
				while (realAmount < 0) {
					realAmount = 0;
					cout << "INVALID AMOUNT INPUT, MUST BE A NONNEGATIVE AMOUNT (X > 0)" << endl;
					string innerAmount;
					cin >> innerAmount;
					stringstream next(innerAmount);
					next >> realAmount;
				}
				realAmount = round(realAmount);

				/*
				Asks for user confirmation over correctness of inputted data
				-index of budget event amount to be modified
				*/
				cout << "Please confirm whether your inputted data is correct. If not, please enter \"n\""
					<< " , otherwise enter anything else" << endl << endl;
				cout << "INDEX TO BE MODIFIED: " << realIndex << "     NEW AMOUNT: " << setw(smallWidth) << realAmount << endl;
				cout << "EVENT IN QUESTION)    " << cash[realIndex - 1];
				cin >> done;
			}
			cash.changeEventAmount(realIndex, realAmount);
		} else if (changeNum == "4") { // modifies an event spending type at index i
			string done = "n";
			int realIndex;
			Spending_Cat newType = nullSpending;

			while (done == "n") {
				realIndex = 0;
				/*
				Uses stringstream for error handling when index amount input contains non-numbers
				*/
				string pseudoIndex;
				cout << "Please enter a valid index from 1 to " << cash.getNumEvents() 
					<< " of the event you would like to modify" << endl;
				cin >> pseudoIndex;
				stringstream first(pseudoIndex);
				first >> realIndex;
				while (realIndex < 1 || realIndex > cash.getNumEvents()) {
					cout << "INVALID INDEX INPUT, MUST BE AN INTEGER FROM 1 TO " << cash.getNumEvents() << endl;
					string innerIndex;
					cin >> innerIndex;
					stringstream next(innerIndex);
					next >> realIndex;
				}

				cin >> newType;
				while (newType == nullSpending) {
					cout << "INVALID SPENDING TYPE INPUT, MUST BE AN INTEGER (1-3)" << endl;
					cin >> newType;
				}


				/*
				Asks for user confirmation over correctness of inputted data
				-index of budget event spending type to be modified
				*/
				cout << "Please confirm whether your inputted data is correct. If not, please enter \"n\""
					<< " , otherwise enter anything else" << endl << endl;
				cout << "INDEX TO BE MODIFIED: " << realIndex << "     NEW SPENDING TYPE: " << newType << endl;
				cout << "EVENT IN QUESTION)    " << cash[realIndex - 1];
				cin >> done;
			}
			cash.changeEventType(realIndex, newType);
		} else if (changeNum == "5") { // modifies an event name at index i
			string newName;
			int realIndex;
			string done = "n";
			while (done == "n") {
				realIndex = 0;
				/*
				Uses stringstream for error handling when index amount input contains non-numbers
				*/
				string pseudoIndex;
				cout << "Please enter a valid index from 1 to " << cash.getNumEvents() 
					<< " of the event you would like to modify" << endl;
				cin >> pseudoIndex;
				stringstream first(pseudoIndex);
				first >> realIndex;
				while (realIndex < 1 || realIndex > cash.getNumEvents()) {
					cout << "INVALID INDEX INPUT, MUST BE AN INTEGER FROM 1 TO " << cash.getNumEvents() << endl;
					string innerIndex;
					cin >> innerIndex;
					stringstream next(innerIndex);
					next >> realIndex;
				}

				cout << "Please enter in the new Event name" << endl;
				cin.ignore();
				getline(cin, newName);


				/*
				Asks for user confirmation over correctness of inputted data
				-index of budget event name to be modified
				*/
				cout << "Please confirm whether your inputted data is correct. If not, please enter \"n\""
					<< " , otherwise enter anything else" << endl << endl;
				cout << "INDEX TO BE MODIFIED: " << realIndex << "     NEW EVENT NAME: " << newName << endl;
				cout << "EVENT IN QUESTION)    " << cash[realIndex - 1];
				cin >> done;
			}
			cash.changeEventName(realIndex, newName);

		} else if (changeNum == "6") { // modifies an event note at index i
			string newNote;
			int realIndex;
			string done = "n";
			while (done == "n") {
				realIndex = 0;
				/*
				Uses stringstream for error handling when index amount input contains non-numbers
				*/
				string pseudoIndex;
				cout << "Please enter a valid index from 1 to " << cash.getNumEvents() 
					<< " of the event you would like to modify" << endl;
				cin >> pseudoIndex;
				stringstream first(pseudoIndex);
				first >> realIndex;
				while (realIndex < 1 || realIndex > cash.getNumEvents()) {
					cout << "INVALID INDEX INPUT, MUST BE AN INTEGER FROM 1 TO " << cash.getNumEvents() << endl;
					string innerIndex;
					cin >> innerIndex;
					stringstream next(innerIndex);
					next >> realIndex;
				}

				cout << "Please enter in the new Event note" << endl;
				cin.ignore();
				getline(cin, newNote);

				/*
				Asks for user confirmation over correctness of inputted data
				-index of budget event note to be modified
				*/
				cout << "Please confirm whether your inputted data is correct. If not, please enter \"n\""
					<< " , otherwise enter anything else" << endl << endl;
				cout << "INDEX TO BE MODIFIED: " << realIndex << "     NEW EVENT NOTE: " << newNote << endl;
				cout << "EVENT IN QUESTION)    " << cash[realIndex - 1];
				cin >> done;
			}
			cash.changeEventNote(realIndex, newNote);

		} else if (changeNum == "7") { // modifies the budget's conditional % for each spending type
			bool partOneNotDone = true;
			string pseudoDefault;
			string pseudoFixedP;
			string pseudoVarP;
			string pseudoSaveP;
			double realFixedP = 0;
			double realVarP = 0;
			double realSaveP = 0;
			string done = "n";
			
			while (done == "n") {

				cout << "For the spending percentages, would you like the default 50, "
					<< "30, 20 or a more custom input?"
					<< " Please input \"d\" for default or anything else otherwise" << endl;
				cin >> pseudoDefault;
		
				if (pseudoDefault != "d") {
					/*
					Uses stringstream for error handling when any percentage input contains non-numbers,
					with additional loops when input percentage values are either below 0 or above 100
					*/
					while (partOneNotDone || realFixedP + realVarP + realSaveP != 1) {
						double leftoverP = 1;
						const int leftWidthSize = 15;
						const int numWidthSize = 6;
						cout << "Please input a percentage (0 - 100) of your income that you would " 
							<< "like to dedicate for Fixed spendings. Note percentages are " 
							<< "rounded to the nearest hundredth." << endl;
						cin >> pseudoFixedP;
						stringstream fixedStream(pseudoFixedP);
						fixedStream >> realFixedP;
						while (realFixedP < 0 || realFixedP > 100) {
							realFixedP = 0;
							cout << "INVALID PERCENTAGE INPUT, MUST BE A NUMBER BETWEEN 0 AND 100" << endl;
							string innerFixed;
							cin >> innerFixed;
							stringstream inner(innerFixed);
							inner >> realFixedP;
						}
						realFixedP = round(realFixedP) / 100;
						leftoverP -= realFixedP;
						cout << setw(leftWidthSize) << right << "Fixed P input: " << setw(numWidthSize) 
							<< realFixedP * 100 << "%" << "          P% left: " << leftoverP * 100 
							<< "%" << endl;

						cout << "Please input a percentage (0 - 100) of your income that you would " 
							<< "like to dedicate for Variable spendings. Note percentages are " 
							<< "rounded to the nearest hundredth." << endl;
						cin >> pseudoVarP;
						stringstream varStream(pseudoVarP);
						varStream >> realVarP;
						while (realVarP < 0 || realVarP > 100) {
							realVarP = 0;
							cout << "INVALID PERCENTAGE INPUT, MUST BE A NUMBER BETWEEN 0 AND 100" << endl;
							string innerVar;
							cin >> innerVar;
							stringstream inner(innerVar);
							inner >> realVarP;
						}
						realVarP = round(realVarP) / 100;
						leftoverP -= realVarP;
						cout << setw(leftWidthSize) << right << "Var P input: " << setw(numWidthSize)
							<< realVarP * 100 << "%" << "          P% left: " << leftoverP * 100 
							<< "%" << endl;

						cout << "Please input a percentage (0 - 100) of your income that you would "
							<< "like to dedicate for Savings. Note percentages are " 
							<< "rounded to the nearest hundredth." << endl;
						cin >> pseudoSaveP;
						stringstream saveStream(pseudoSaveP);
						saveStream >> realSaveP;
						while (realSaveP < 0 || realSaveP > 100) {
							double realSaveP = 0;
							cout << "INVALID PERCENTAGE INPUT, MUST BE A NUMBER BETWEEN 0 AND 100" << endl;
							string innerSave;
							cin >> innerSave;
							stringstream inner(innerSave);
							inner >> realSaveP;
						}
						realSaveP = round(realSaveP) / 100;
						leftoverP -= realSaveP;
						if (abs(leftoverP) < .001) {
							leftoverP = 0;
						}
						cout << setw(leftWidthSize) << right << "Save P input: " << setw(numWidthSize)
							<< realSaveP * 100 << "%" << "          P% left: " << leftoverP * 100 
							<< "%" << endl;
							
						double totalPercentage = realFixedP + realVarP + realSaveP;
						/*
						Checks whether input combination is valid (exactly sums to 100) or not
						*/
						if (totalPercentage != 1) {
							cout << endl << "INVALID PERCENTAGE COMBINATION, PERCENTAGES MUST COLLECTIVELY "
								<< "ADD UP TO EXACTLY 100. Your percentages collectively add up to " 
								<< totalPercentage << ". Please re-enter" << endl;
						} else {
							partOneNotDone = false;
						}
					}
				} else {
					realFixedP = .5;
					realVarP = .3;
					realSaveP = .2;
				}

				/*
				Asks for user confirmation over correctness of inputted data
				-respective new percentages for fixed, var, & savings
				*/
				cout << "Please confirm whether your inputted data is correct. If not, please enter \"n\""
					<< " , otherwise enter anything else" << endl << endl;
				cout << "NEW FIXED %: " << realFixedP * 100 << "%     NEW VARIABLE %: " << realVarP * 100
					<< "%     NEW SAVINGS %: " << realSaveP * 100 << "%" << endl;
				cin >> done;
			}
			cash.changeConditionalP(realFixedP, realVarP, realSaveP);

		} else if (changeNum == "8") { // modifies the budget's after-tax income
			string done = "n";
			double newIncome = 0;

			while (done == "n") {
				/*
				Uses stringstream for error handling when monetary income amount input contains non-numbers
				*/
				string pseudoIncome;
				cout << "Please enter in your new total after-tax income. " 
					<< "Note decimal values are rounded to the nearest hundredth" 
					<< ", and input that begins with non-numbers are interpreted as 0" << endl;
				cin >> pseudoIncome;
				stringstream incomeStream(pseudoIncome);
				incomeStream >> newIncome;
				while (newIncome < 0) {
					newIncome = 0;
					cout << "INVALID INCOME INPUT, MUST BE A NONNEGATIVE AMOUNT" << endl;
					string innerIncome;
					cin >> innerIncome;
					stringstream next(innerIncome);
					next >> newIncome;
				}
				newIncome = round(newIncome);
		
				/*
				Asks for user confirmation over correctness of inputted data
				-new budget after-tax income
				*/
				cout << "Please confirm whether your inputted data is correct. If not, please enter \"n\""
					<< " , otherwise enter anything else" << endl << endl;
				cout << "NEW AFTER-TAX INCOME CURRENCY: " << setw(smallWidth) << newIncome << endl;
				cin >> done;
			}
			cash.changeAfterTaxIncome(newIncome);

		} else if (changeNum == "9") { // modifies the budget's currency and performs for-ex foreign exchange operations
			string done = "n";
			Currency oldCurr = cash.getCurr();
			Currency newCurr = nullCurrency;

			/*
			Prints out the exchange rates to be used in calculations for user convenience.
			Note it only prints out the relevant rates for the current budget's currency
			*/
			cout << "Here are the exchange rates for the ";
			if (oldCurr == 1) {
				cout << "US Dollar: " << endl << endl;
				cout << "USD to CNY: " << setw(smallWidth) << "7.00823" 
					<< "      " << "CNY to USD: .142689" << endl;
				cout << "USD to EUR: " << setw(smallWidth) << ".899561" 
					<< "      " << "EUR to USD: 1.11165" << endl;
				cout << "USD to GBP: " << setw(smallWidth) << ".767975" 
					<< "      " << "GBP to USD: 1.30212" << endl << endl;
			} else if (oldCurr == 2) {
				cout << "Chinese Yuan / Renminbi:" << endl;
				cout << "CNY to USD: " << setw(smallWidth) << ".142689" 
					<< "      " << "USD to CNY: 7.00823" << endl;
				cout << "CNY to EUR: " << setw(smallWidth) << ".128349" 
					<< "      " << "EUR to CNY: 7.79123" << endl;
				cout << "CNY to GBP: " << setw(smallWidth) << ".109585" 
					<< "      " << "GBP to CNY: 9.12530" << endl << endl;
			} else if (oldCurr == 3) {
				cout << "Euro: " << endl;
				cout << "EUR to USD: " << setw(smallWidth) << "1.11165" 
					<< "      " << "USD to EUR: .899561" << endl;
				cout << "EUR to CNY: " << setw(smallWidth) << "7.79123" 
					<< "      " << "CNY to EUR: .128349" << endl;
				cout << "EUR to GBP: " << setw(smallWidth) << "0.853729" 
					<< "      " << "GBP to EUR: 1.17133" << endl << endl;
			} else if (oldCurr == 4) {
				cout << "British Pound:" << endl;
				cout << "GBP to USD: " << setw(smallWidth) << "1.30212" 
					<< "      " << "USD to GBP: .767975" << endl;
				cout << "GBP to CNY: " << setw(smallWidth) << "9.12530" 
					<< "      " << "CNY to GBP: .109585" << endl;
				cout << "GBP to EUR: " << setw(smallWidth) << "1.17133" 
					<< "      " << "EUR to GBP: 0.853729" << endl << endl;
			}

			while (done == "n") {
				cin >> newCurr;
				while (newCurr == nullCurrency) {
					cout << "INVALID CURRENCY INPUT, MUST BE AN INTEGER (1-4)" << endl;
					cin >> newCurr;
				}

				/*
				Asks for user confirmation over correctness of inputted data
				-new budget currency to be converted into
				*/
				cout << "Please confirm whether your inputted data is correct. If not, please enter \"n\""
					<< " , otherwise enter anything else" << endl << endl;
				cout << "NEW BUDGET CURRENCY: " << newCurr << endl;
				cin >> done;
			}
			cash.changeCurrency(newCurr);
		}
		cash.calculate();
		cout << "This is your current budget." << endl << endl;
		cout << cash;
		cout << "Would you like to change anymore data? Please enter \"y\" for yes, or anything else otherwise" << endl;
		cin >> change;
	}
	
	/*
	Prints out one final, completed budget as determined by user.
	*/
	cout << endl << "Great! This is your final budget." << endl;
	cash.calculate();
	cout << cash;

	return 0;
}