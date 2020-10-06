#include "Event.h"

#ifndef BUDGET
#define BUDGET

#include <iostream>
using namespace std;

class Budget {
	friend ostream& operator<<(ostream&, const Budget&);
	friend istream& operator>>(istream&, Budget&);
private:
	static const int INITIAL_CAPACITY = 5; // initial capacity of backing array
	static const int PERCENT = 100; // used for percentage calculations
	Event *backingArray; 
	Currency curr;
	Month m;
	int numResizes; // used for backing array resizing
	int numEvents;
	int currArrLength; // used for backing array resizing
	double fixedPercentage;
	double varPercentage;
	double savePercentage; // percentages
	double afterTaxIncome;
	double amountLeft;
	double amountSpent; // total amounts
	double condFixedAmount;
	double condVarAmount;
	double condSaveAmount; // total conditional amounts
	double currFixedAmount;
	double currVarAmount;
	double currSaveAmount; // conditional amounts left to spend
	double currFixedSpent;
	double currVarSpent;
	double currSaveSpent; // conditional amounts already spent
	double currFixedAmountPercentage;
	double currFixedSpentPercentage;
	double currVarAmountPercentage; 
	double currVarSpentPercentage;
	double currSaveAmountPercentage;
	double currSaveSpentPercentage;
	double currTotalAmountPercentage;
	double currTotalSpentPercentage; // current total & conditional percentages left to spend & already spent

public:
	Event& operator[](int);
	Budget(Currency curr = nullCurrency, Month mon = nullMonth, double a = 0, 
		double b = 50, double c = 30, double d = 20): 
		afterTaxIncome(a), amountLeft(a), fixedPercentage(b / PERCENT),
		varPercentage(c / PERCENT), savePercentage(d / PERCENT), curr(curr), m(mon)  {
		numEvents = 0;
		condFixedAmount = round(a * fixedPercentage);
		condVarAmount = round(a * varPercentage);
		condSaveAmount = round(a * savePercentage);
		currFixedAmount = condFixedAmount;
		currVarAmount = condVarAmount;
		currSaveAmount = condSaveAmount;
		currFixedSpent = 0;
		currVarSpent = 0;
		currSaveSpent = 0;
		currFixedAmountPercentage = PERCENT / PERCENT;
		currVarAmountPercentage = PERCENT / PERCENT;
		currSaveAmountPercentage = PERCENT / PERCENT;
		currTotalAmountPercentage = PERCENT / PERCENT;
		currFixedSpentPercentage = 0;
		currVarSpentPercentage = 0;
		currSaveSpentPercentage = 0;
		currTotalSpentPercentage = 0;
		amountSpent = 0;
		numResizes = 0;
		currArrLength = INITIAL_CAPACITY;
		backingArray = new Event[INITIAL_CAPACITY];
	}

	/*
	Adds event to budget event array
	*/
	void addEvent(Event e) {
		if (numEvents + 1 > currArrLength) {
			resize();
		}
		backingArray[numEvents++] = e;
		amountLeft -= e.getAmount();
		amountSpent += e.getAmount();
		currTotalAmountPercentage -= (e.getAmount() / afterTaxIncome);
		currTotalSpentPercentage += (e.getAmount() / afterTaxIncome);
		if (e.getSpendingType() == FIXED) {
			currFixedAmount -= e.getAmount();
			currFixedSpent += e.getAmount();
			currFixedAmountPercentage -= (e.getAmount() / condFixedAmount);
			currFixedSpentPercentage += (e.getAmount() / condFixedAmount);
		} else if (e.getSpendingType() == VARIABLE) {
			currVarAmount -= e.getAmount();
			currVarSpent += e.getAmount();
			currVarAmountPercentage -= (e.getAmount() / condVarAmount);
			currVarSpentPercentage += (e.getAmount() / condVarAmount);
		} else if (e.getSpendingType() == SAVINGS) {
			currSaveAmount -= e.getAmount();
			currSaveSpent += e.getAmount();
			currSaveAmountPercentage -= (e.getAmount() / condSaveAmount);
			currSaveSpentPercentage += (e.getAmount() / condSaveAmount);
		}
	}

	/*
	Deletes event at index a
	*/
	void deleteEvent(int a) {
		Event temp = backingArray[a - 1];
		for (int i = a - 1; i < numEvents - 1; i++) {
			backingArray[i] = backingArray[i + 1];
		}
		Event erase;
		backingArray[numEvents--] = erase;
		amountLeft += temp.getAmount();
		amountSpent -= temp.getAmount();
		currTotalAmountPercentage += (temp.getAmount() / afterTaxIncome);
		currTotalSpentPercentage -= (temp.getAmount() / afterTaxIncome);

		if (temp.getSpendingType() == FIXED) {
			currFixedAmount += temp.getAmount();
			currFixedSpent -= temp.getAmount();
			currFixedAmountPercentage += (temp.getAmount() / condFixedAmount);
			currFixedSpentPercentage -= (temp.getAmount() / condFixedAmount);
		} else if (temp.getSpendingType() == VARIABLE) {
			currVarAmount += temp.getAmount();
			currVarSpent -= temp.getAmount();
			currVarAmountPercentage += (temp.getAmount() / condVarAmount);
			currVarSpentPercentage -= (temp.getAmount() / condVarAmount);
		} else if (temp.getSpendingType() == SAVINGS) {
			currSaveAmount += temp.getAmount();
			currSaveSpent -= temp.getAmount();
			currSaveAmountPercentage += (temp.getAmount() / condSaveAmount);
			currSaveSpentPercentage -= (temp.getAmount() / condSaveAmount);
		}
	}

	/*
	Modifies an event amount at index i
	*/
	void changeEventAmount(int index, double newAmount) {
		newAmount = round(newAmount);
		Event curr = backingArray[index - 1];
		double oldAmount = curr.getAmount();
		backingArray[index - 1].changeAmount(newAmount);
		double dif = newAmount - oldAmount;
		amountSpent += dif;
		amountLeft -= dif;
		currTotalAmountPercentage -= (dif / afterTaxIncome);
		currTotalSpentPercentage += (dif / afterTaxIncome);
		if (curr.getSpendingType() == FIXED) {
			currFixedSpent += dif;
			currFixedAmount -= dif;
			currFixedAmountPercentage -= (dif / condFixedAmount);
			currFixedSpentPercentage += (dif / condFixedAmount);
		} else if (curr.getSpendingType() == VARIABLE) {
			currVarSpent += dif;
			currVarAmount -= dif;
			currVarAmountPercentage -= (dif / condVarAmount);
			currVarSpentPercentage += (dif / condVarAmount);
		} else if (curr.getSpendingType() == SAVINGS) {
			currSaveSpent += dif;
			currSaveAmount -= dif;
			currSaveAmountPercentage -= (dif / condSaveAmount);
			currSaveSpentPercentage += (dif / condSaveAmount);
		}
	}

	/*
	Modifies an event spending type at index i
	*/
	void changeEventType(int index, Spending_Cat newType) {
		Event curr = backingArray[index - 1];
		Spending_Cat oldType = curr.getSpendingType();
		double amountChange = curr.getAmount();
		backingArray[index - 1].changeSpendingType(newType);
		if (oldType == FIXED && newType == VARIABLE) {
			currFixedSpent -= amountChange;
			currFixedAmount += amountChange;
			currVarSpent += amountChange;
			currVarAmount -= amountChange;
			currFixedAmountPercentage += (amountChange / condFixedAmount);
			currFixedSpentPercentage -= (amountChange / condFixedAmount);
			currVarAmountPercentage -= (amountChange / condVarAmount);
			currVarSpentPercentage += (amountChange / condVarAmount);
		} else if (oldType == VARIABLE && newType == FIXED) {
			currFixedSpent += amountChange;
			currFixedAmount -= amountChange;
			currVarSpent -= amountChange;
			currVarAmount += amountChange;
			currFixedAmountPercentage -= (amountChange / condFixedAmount);
			currFixedSpentPercentage += (amountChange / condFixedAmount);
			currVarAmountPercentage += (amountChange / condVarAmount);
			currVarSpentPercentage -= (amountChange / condVarAmount);
		} else if (oldType == FIXED && newType == SAVINGS) {
			currFixedSpent -= amountChange;
			currFixedAmount += amountChange;
			currSaveSpent += amountChange;
			currSaveAmount -= amountChange;
			currFixedAmountPercentage += (amountChange / condFixedAmount);
			currFixedSpentPercentage -= (amountChange / condFixedAmount);
			currSaveAmountPercentage -= (amountChange / condSaveAmount);
			currSaveSpentPercentage += (amountChange / condSaveAmount);
		} else if (oldType == SAVINGS && newType == FIXED) {
			currSaveSpent -= amountChange;
			currSaveAmount += amountChange;
			currFixedSpent += amountChange;
			currFixedAmount -= amountChange;
			currFixedAmountPercentage -= (amountChange / condFixedAmount);
			currFixedSpentPercentage += (amountChange / condFixedAmount);
			currSaveAmountPercentage += (amountChange / condSaveAmount);
			currSaveSpentPercentage -= (amountChange / condSaveAmount);
		} else if (oldType == VARIABLE && newType == SAVINGS) {
			currVarSpent -= amountChange;
			currVarAmount += amountChange;
			currSaveSpent += amountChange;
			currSaveAmount -= amountChange;
			currVarAmountPercentage += (amountChange / condVarAmount);
			currVarSpentPercentage -= (amountChange / condVarAmount);
			currSaveAmountPercentage -= (amountChange / condSaveAmount);
			currSaveSpentPercentage += (amountChange / condSaveAmount);
		} else if (oldType == SAVINGS && newType == VARIABLE) {
			currSaveSpent -= amountChange;
			currSaveAmount += amountChange;
			currVarSpent += amountChange;
			currVarAmount -= amountChange;
			currSaveAmountPercentage += (amountChange / condSaveAmount);
			currSaveSpentPercentage -= (amountChange / condSaveAmount);
			currVarAmountPercentage -= (amountChange / condVarAmount);
			currVarSpentPercentage += (amountChange / condVarAmount);
		}
	}

	/*
	Modifies an event name at index i
	*/
	void changeEventName(int index, string s) {
		backingArray[index - 1].changeTitle(s);
	}

	/*
	Modifies an event note at index i
	*/
	void changeEventNote(int index, string s) {
		backingArray[index - 1].changeNote(s);
	}

	/*
	Modifies the budget's conditional % for each spending type
	*/
	void changeConditionalP(double a, double b, double c) {
		fixedPercentage = round(a * 100) / 100;
		varPercentage = round(b * 100) / 100;
		savePercentage = round(c * 100) / 100;
		condFixedAmount = round(afterTaxIncome * fixedPercentage);
		condVarAmount = round(afterTaxIncome * varPercentage);
		condSaveAmount = round(afterTaxIncome * savePercentage);
		calculate();
	}

	/*
	Modifies the budget's after-tax income
	*/
	void changeAfterTaxIncome(double a) {
		afterTaxIncome = round(a);
		condFixedAmount = round(afterTaxIncome * fixedPercentage);
		condVarAmount = round(afterTaxIncome * varPercentage);
		condSaveAmount = round(afterTaxIncome * savePercentage);
		calculate();
	}

	/*
	Modifies the budget's currency and performs for-ex foreign exchange operations
	*/
	void changeCurrency(Currency newC) {
		Currency oldC = curr;
		curr = newC;
		double exchangeRate = 0;
		if (oldC == newC) {
			exchangeRate = 1;
		} else if (oldC == USD && newC == CNY) {
			exchangeRate = 7.00823;
		} else if (oldC == CNY && newC == USD) {
			exchangeRate = .142689;
		} else if (oldC == USD && newC == EUR) {
			exchangeRate = .899561;
		} else if (oldC == EUR && newC == USD) {
			exchangeRate = 1.11165;
		} else if (oldC == USD && newC == GBP) {
			exchangeRate = .767975;
		} else if (oldC == GBP && newC == USD) {
			exchangeRate = 1.30212;
		} else if (oldC == CNY && newC == EUR) {
			exchangeRate = .128349;
		} else if (oldC == EUR && newC == CNY) {
			exchangeRate = 7.79123;
		} else if (oldC == CNY && newC == GBP) {
			exchangeRate = .109585;
		} else if (oldC == GBP && newC == CNY) {
			exchangeRate = 9.12530;
		} else if (oldC == EUR && newC == GBP) {
			exchangeRate = 0.853729;
		} else if (oldC == GBP && newC == EUR) {
			exchangeRate = 1.17133;
		}
		changeAfterTaxIncome(round(afterTaxIncome * exchangeRate));
		for (int i = 0; i < numEvents; i++) {
			backingArray[i].changeAmount(round(backingArray[i].getAmount() * exchangeRate));
			backingArray[i].changeCurrency(newC);
		}
		calculate();
	}

	/*
	Resizes backing array * 2 when previous array fills up completely
	*/
	void resize() {
		currArrLength *= 2;
		Event *tempArray = new Event[currArrLength];
		for (int i = 0; i < numEvents; i++) {
			tempArray[i] = backingArray[i];
		}
		backingArray = tempArray;
	}

	/*
	Recalculates all relevant data from scratch, to help counter any potential round off errors
	or double binary weird calculations
	*/
	void calculate() {
		double sum = 0;
		double fixedSum = 0;
		double varSum = 0;
		double saveSum = 0;

		for (int i = 0; i < numEvents; i++) {
			sum += backingArray[i].getAmount();
			if (backingArray[i].getSpendingType() == FIXED) {
				fixedSum += backingArray[i].getAmount();
			} else if (backingArray[i].getSpendingType() == VARIABLE) {
				varSum += backingArray[i].getAmount();
			} else if (backingArray[i].getSpendingType() == SAVINGS) {
				saveSum += backingArray[i].getAmount();
			}
		}
		amountSpent = sum;
		amountLeft = afterTaxIncome - amountSpent;
		currTotalSpentPercentage = amountSpent / afterTaxIncome;
		currTotalAmountPercentage = amountLeft / afterTaxIncome;
		currFixedSpent = fixedSum;
		currFixedAmount = condFixedAmount - fixedSum;
		currFixedSpentPercentage = currFixedSpent / condFixedAmount;
		currFixedAmountPercentage = currFixedAmount / condFixedAmount;
		currVarSpent = varSum;
		currVarAmount = condVarAmount - varSum;
		currVarSpentPercentage = currVarSpent / condVarAmount;
		currVarAmountPercentage = currVarAmount / condVarAmount;
		currSaveSpent = saveSum;
		currSaveAmount = condSaveAmount - saveSum;
		currSaveSpentPercentage = currSaveSpent / condSaveAmount;
		currSaveAmountPercentage = currSaveAmount / condSaveAmount;
	}

	/*
	Getters for Budget class's private members
	*/
	int getNumEvents() {
		return numEvents;
	}

	Month getMonth() {
		return m;
	}

	Currency getCurr() {
		return curr;
	}

	double getCurrTotalAmountPercentage() {
		return currTotalAmountPercentage;
	}

	double getCurrTotalSpentPercentage() {
		return currTotalSpentPercentage;
	}

	double getCurrFixedAmountPercentage() {
		return currFixedAmountPercentage;
	}

	double getCurrFixedSpentPercentage() {
		return currFixedSpentPercentage;
	}

	double getCurrVarAmountPercentage() {
		return currVarAmountPercentage;
	}

	double getCurrVarSpentPercentage() {
		return currVarSpentPercentage;
	}

	double getCurrSaveAmountPercentage() {
		return currSaveAmountPercentage;
	}

	double getCurrSaveSpentPercentage() {
		return currSaveSpentPercentage;
	}

	double getAmountSpent() {
		return amountSpent;
	}

	double getAmountLeft() {
		return amountLeft;
	}

	double getAfterTaxIncome() {
		return afterTaxIncome;
	}

	double getFixedPercentage() {
		return fixedPercentage;
	}

	double getVarPercentage() {
		return varPercentage;
	}

	double getSavePercentage() {
		return savePercentage;
	}

	double getCondFixedAmount() {
		return condFixedAmount;
	}

	double getCondVarAmount() {
		return condVarAmount;
	}

	double getCondSaveAmount() {
		return condSaveAmount;
	}

	double getCurrFixedAmount() {
		return currFixedAmount;
	}

	double getCurrVarAmount() {
		return currVarAmount;
	}

	double getCurrSaveAmount() {
		return currSaveAmount;
	}

	double getCurrFixedSpent() {
		return currFixedSpent;
	}

	double getCurrVarSpent() {
		return currVarAmount;
	}

	double getCurrSaveSpent() {
		return currSaveSpent;
	}

};

/*
Allows Budget object in runner file to access backing array using hard brackets, like an array
*/
Event& Budget::operator[](int a) {
	return backingArray[a];
}

ostream& operator<<(ostream& out, const Budget& a) {
	/*
	Budget header. Prints currency, month, & total current number of Events
	*/	
	out << "----------------------------------------------------------------"
		<< "----------------------------------------------------------------"
		<< "----------------------------------";
	out << endl << "CURRENCY: " << a.curr << "                 " << "MONTH: ";
	printFullName(a.m);
	out << "                 " << "Total number of Events: " << a.numEvents << endl << endl;
	
	/*
	Prints all actual events from Event array.
	*/
	for(int i = 0; i < a.numEvents; i++) {
		out << "EVENT " << (i + 1) << ") " << a.backingArray[i];
	}

	const int largeWidth = 35;
	const int medWidth = 22;
	const int smallWidth = 8;
	const int totalWidth = 34;
	const int bigTotalWidth = 50;
	const int percentWidth = 5;

	/*
	Prints budget analysis: total & conditional analysis for each spending type
	*/
	out << endl << setw(totalWidth) << "          MONEY LEFTOVER          " 
		<< "               " << setw(totalWidth) << "            MONEY SPENT           " 
		<< "               " << setw(bigTotalWidth) 
		<< "                 MONEY ALLOCATION                 " << endl;
	out << right << setw(medWidth) << "Fixed money left: " << left 
		<< setprecision(numDigits(a.currFixedAmount) + 2) << setw(smallWidth)
		<< a.currFixedAmount << a.curr << "   " << setw(percentWidth) << right << round(a.currFixedAmountPercentage * 100) << "%"
		<< "  |   " << right <<setw(medWidth) << "Fixed money spent: " 
		<< left << setprecision(numDigits(a.currFixedSpent) + 2) << setw(smallWidth)
		<< a.currFixedSpent << a.curr << "   " << setw(percentWidth) << right << round(a.currFixedSpentPercentage * 100) << "%"
		<< "    | " << right <<setw(largeWidth) 
		<< "Total fixed money allocated: "  << left << setprecision(numDigits(a.condFixedAmount) + 2) 
		<< setw(smallWidth) << a.condFixedAmount << a.curr << "   " << a.fixedPercentage * 100 << "%" << endl;
	out << right << setw(medWidth) << "Variable money left: " << left 
		<< setprecision(numDigits(a.currVarAmount) + 2) << setw(smallWidth)
		<< a.currVarAmount << a.curr << "   " << setw(percentWidth) << right << round(a.currVarAmountPercentage * 100) << "%"
		<< "  |   " << right <<setw(medWidth) << "Variable money spent: " 
		<< left << setprecision(numDigits(a.currVarSpent) + 2) << setw(smallWidth)
		<< a.currVarSpent << a.curr << "   " << setw(percentWidth) << right << round(a.currVarSpentPercentage * 100) << "%"
		<< "    | " << right <<setw(largeWidth) 
		<< "Total variable money allocated: "  << left << setprecision(numDigits(a.condVarAmount) + 2) 
		<< setw(smallWidth) << a.condVarAmount << a.curr << "   " << a.varPercentage * 100 << "%" << endl;
	out << right << setw(medWidth) << "Savings money left: " << left 
		<< setprecision(numDigits(a.currSaveAmount) + 2) << setw(smallWidth)
		<< a.currSaveAmount << a.curr << "   " << setw(percentWidth) << right << round(a.currSaveAmountPercentage * 100) << "%"
		<< "  |   " << right <<setw(medWidth) << "Savings money saved: " 
		<< left << setprecision(numDigits(a.currSaveSpent) + 2) << setw(smallWidth)
		<< a.currSaveSpent << a.curr << "   " << setw(percentWidth) << right << round(a.currSaveSpentPercentage * 100) << "%"
		<< "    | " << right <<setw(largeWidth) 
		<< "Total savings money allocated: "  << left << setprecision(numDigits(a.condSaveAmount) + 2) 
		<< setw(smallWidth) << a.condSaveAmount << a.curr << "   " << a.savePercentage * 100 << "%" << endl << endl;
	out << right << setw(medWidth) << "Total money left: " << left 
		<< setprecision(numDigits(a.amountLeft) + 2) << setw(smallWidth)
		<< a.amountLeft << a.curr << "   " << setw(percentWidth) << right << round(a.currTotalAmountPercentage * 100) << "%"
		<< "  |   " << right <<setw(medWidth) << "Total money spent: " 
		<< left << setprecision(numDigits(a.amountSpent) + 2) << setw(smallWidth)
		<< a.amountSpent << a.curr << "   " << setw(percentWidth) << right << round(a.currTotalSpentPercentage * 100) << "%"
		<< "    | " << right <<setw(largeWidth) 
		<< "Total after-tax income: "  << left << setprecision(numDigits(a.afterTaxIncome) + 2) 
		<< setw(smallWidth) << a.afterTaxIncome << a.curr << "   " << 100 << "%" << endl << endl;
	/*
	Messages that notify the user when they have exceeded their budget in a certain category
	*/
	if (a.currFixedAmount <= 0) {
		out << "NOTE, YOU HAVE EXCEEDED YOUR BUDGET FOR FIXED SPENDINGS!" << endl << endl;
	} 
	if (a.currVarAmount <= 0) {
		out << "NOTE, YOU HAVE EXCEEDED YOUR BUDGET FOR VARIABLE SPENDINGS!" << endl << endl;
	} 
	if (a.currSaveAmount <= 0) {
		out << "NOTE, YOU HAVE EXCEEDED YOUR BUDGET FOR SAVINGS!" << endl << endl;
	} 
	if (a.amountLeft <= 0) {
		// very important message below when users have exceeded their entire budget. PLEASE DON'T MODIFY!!
		out << ",*************,,*/(((((//,,*(#%%%%%%%%%%%%%%%#(*,,,****************************************************,*/(((((((((/((((////****/((##%%%%%%\n"
			<< ",*************,,//((((((//,,*(%%%%%%%%%%%%%%%%%##/*****************************************************,,*/(///(//////****//((##%%%%%%%%%%%\n" 
			<< ",************,,*/(((((((//***/#%%%%%%%%%%%%%%%%%%%#(/***************************************************,*//////////*//((#%%%%%%%%%%%%%%%%%\n"
			<< ",***********,,*////////////***/##%%%%%%%%%%%%%%%%%%%##(*,***********************************************,,*////////(###%%%%%%%%%%%%%%%%%%%%\n" 
			<< ",**********,,,*/*******//////**/(#%%%%%%%%%%%%%%%%%%%%%#(/**********************************************,,,***/(##%%%%%%%%%%%%%%%%%%%%%%%%%\n" 
			<< ",*********,,,,*************///***/(#%%%%%%%%%%%%%%%%%%%%%%#(/***********************************,****,****/((#%%%%%%%%%%%%%%%%%%%%%%%%%%%%#\n" 
			<< ",*********,,,***************//****/(##%%%%%%%%%%%%%%%%%%%%%%##//**************//////////////////////((#####%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#(\n" 
			<< ",********,,,,***********************/(#%%%%%%%%%%%%%%%%%%%%%%%##################%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##(/\n" 
			<< ",*******,..,***********************,,*/##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%###((//\n" 
			<< ",*******,.,,***********************,,,,*(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##(//**//\n" 
			<< ",******,.,,,************************,,,,*/(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#(//*******\n" 
			<< ",*****,,,,,********,***,,,,,,,,,,,,*,,,,,,*/(######%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##(/**********\n" 
			<< ",*****,..,*******,,,,,,,,,,,,,,,,,,,,,,*,,,,*///((#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%###(/************\n" 
			<< ",*****,,,*******,,,,,*,,,,,,,,,,,,,,,,,****,,,*/(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#######(//**************\n" 
			<< ",****,.,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,**,,,/(%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#((//******************\n" 
			<< ",***,..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,..,,,,,,,*(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#(/*******************\n" 
			<< ",**,,.,,,,,,,,,,,,,,,,,,,,,,,,,,.......,,,,,,/#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#####%%%%%%%%%%%%%%%%#(/******************\n" 
			<< ",**,..,,,,,,,,,,,,,,,,,,,,,,,,,......,,,*,,,*(#%%%%%%%%##(((/(##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##(((/*/((#%%%%%%%%%%%%%%#(/*****************\n" 
			<< ",*,..,,,,,,,,,,,,,,,,,,,,,,,,,,,.....,,**,,*/#%%%%%%%##((((*,**/#%%%%%%%%%%%%%%%%%%%%%%%%%%%%##((##/,,,*(#%%%%%%%%%%%%%%#(*****************\n" 
			<< ".*,.,,,**,,,,,,,,,,,,,,,,,,,,,,,,,,*****,,,/(%%%%%%%%#(//(#/,..*/#%%%%%%%%%%%%%%%%%%%%%%%%%%%#(//(#/,..,/(#%%%%%%%%%%%%%%#/*****///////////\n" 
			<< ".,..,,,,,,,,,,,,,,,,,,,,,,,,,,*,,*******,,,(#%%%%%%%%#(*,,,....,/#%%%%%%%%%%%%%%%%%%%%%%%%%%%#(*,,,....,/(#%%%%%%%%%%%%%%#(*,**////////////\n" 
			<< ".,..,,,,,,,,,...........,,,,,,*,********,,*(#%%%%%%%%%#(/*,,...,/#%%%%%%%%%%%%%%%%%%%%%%%%%%%%#(/*,,..,*/##%%%%%%%%%%%%%%%#(***////////////\n" 
			<< "...,,,,,,,................,,*,**********,,/#%%%%%%%%%%%%#((////((#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##((///(#%%%%%%%%%%%%%%%%%%(/**////////////\n" 
			<< " ..,,,,,,.................,,,**********,,*(#%%%%%%%%%%%%%%%%%%#%%%%%%%%#((///((#%%%%%%%%%%%%%%%%%%%%%#%%%%%%%%%%%%%%%%%%%%%#/**////////////\n" 
			<< ".,,,,,,,,.................,,***********,,/(####%%%%%%%%%%%%%%%%%%%%%%%%#(/*,,,*(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#(/*////////////\n" 
			<< ".,***,,,,,,..............,,,**********,..,***//((##%%%%%%%%%%%%%%%%%%%%%%%##((##%%%%%%%%%%%%%%%%%%%%%%%%%##(((((((((###%%%%%#/**///////////\n" 
			<< ".*****,,,,,,,,,,,,,,,,,,,*************,..,*******/(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##///*//////((#%%%%%#(**///////////\n" 
			<< ".****************/******/***////*****,.,*///////**/#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#(////////////(#%%%%%#/**//////////\n" 
			<< ".***********************/////*******,..,*//////////(#%%%%%%%%%%%%%%%%%%%%##########%%%%%%%%%%%%%%%%%%%%#(///////////*/(#%%%%%#(***/////////\n" 
			<< ".************************///********,..,*//////////#%%%%%%%%%%%%%%%%%%#(//*****///(((##%%%%%%%%%%%%%%%%#(///////////**/##%%%%##/***////////\n" 
			<< ".***********************************,.,,***///////(#%%%%%%%%%%%%%%%%#(/*,,,*//((((////(#%%%%%%%%%%%%%%%#((////////////(#%%%%%%#(*********//\n" 
			<< ",***********,,,*,,*,,**************,,,*//******//(#%%%%%%%%%%%%%%%%%#(*,,*/(((#####(((((#%%%%%%%%%%%%%%%##///////////(#%%%%%%%%#(***///////\n" 
			<< ",*************,,**,,,************,,,,,/(##((((####%%%%%%%%%%%%%%%%%%%(/**/(((#((((#((//(#%%%%%%%%%%%%%%%%%#(((((((((##%%%%%%%%%%#/**///////\n" 
			<< ",******************************,,,,,,,*(#%#%%%%%%%%%%%%%%%%%%%%%%%%%%#(**/((#(#(((#((//(#%%%%%%%%%%%%%%%%%%%%%%%#%#%%%%%%%%%%%%%#(**///////\n" 
			<< ",*************,**************,****,,,,,/(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%#(/*/((((#((((///(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%(/*///////\n" 
			<< ",*************************************,*/#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##(////////////(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#/**/////*\n" 
			<< ",******////****///////////////////////***/#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%####(((((((###%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#(********\n" 
			<< ".,*,****///////////////////////////////***/#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#(/*******\n" 
			<< ".,,,,*****//////////////////////////*******(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##(*******\n" 
			<< ".,,,,,,***********/////////////////********/(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%(*******"
			<< endl << endl;
		out << "NOTE, YOU HAVE EXCEEDED YOUR ENTIRE BUDGET!!!!!!!!!!!!!!!!!!" << endl << endl;
	}
	out << "----------------------------------------------------------------"
		<< "----------------------------------------------------------------"
		<< "----------------------------------" << endl;

	return out;
}

istream& operator>>(istream& in, Budget& a) {
	
	string confirm = "n";
	const int medWidth = 22;

	/*
	Input loop for currency, month, income, and spending percentages,
	in that order. Input loop continues until user declares their input is correct
	*/
	while (confirm == "n") {
		bool partOneNotDone = true;
		string pseudoIncome;
		string pseudoFixedP;
		string pseudoVarP;
		string pseudoSaveP;

		in >> a.curr;
		while (a.curr == nullCurrency) {
			cout << "INVALID CURRENCY INPUT, MUST BE AN INTEGER (1-4)" << endl;
			in >> a.curr;
		}

		in >> a.m;
		while (a.m == nullMonth) {
			cout << "INVALID MONTH INPUT, MUST BE AN INTEGER (1-12)" << endl;
			in >> a.m;
		}

		/*
		Uses stringstream for error handling when monetary income amount input contains non-numbers
		*/
		cout << "Please enter in your total after-tax income. " 
			<< "Note decimal values are rounded to the nearest hundredth" 
			<< ", and input that begins with non-numbers are interpreted as 0" << endl;
		in >> pseudoIncome;
		stringstream incomeStream(pseudoIncome);
		double realIncome = 0;
		incomeStream >> realIncome;
		while (realIncome < 0) {
			realIncome = 0;
			cout << "INVALID INCOME INPUT, MUST BE A NONNEGATIVE AMOUNT" << endl;
			string innerIncome;
			in >> innerIncome;
			stringstream next(innerIncome);
			next >> realIncome;
		}
		a.afterTaxIncome = round(realIncome);

		string pseudoDefault;
		cout << "For the spending percentages, would you like the default 50, "
			<< "30, 20 or a more custom input?"
			<< " Please input \"d\" for default or anything else otherwise" << endl;
		in >> pseudoDefault;
		
		if (pseudoDefault != "d") {
			/*
			Uses stringstream for error handling when any percentage input contains non-numbers,
			with additional loops when input percentage values are either below 0 or above 100
			*/
			while (partOneNotDone || a.fixedPercentage + a.varPercentage + a.savePercentage != 1) {
				double leftoverP = 1;
				const int leftWidthSize = 15;
				const int numWidthSize = 6;
				cout << "Please input a percentage (0 - 100) of your income that you would " 
					<< "like to dedicate for Fixed spendings. Note percentages are " 
					<< "rounded to the nearest hundredth." << endl;
				in >> pseudoFixedP;
				stringstream fixedStream(pseudoFixedP);
				double realFixedP = 0;
				fixedStream >> realFixedP;
				while (realFixedP < 0 || realFixedP > 100) {
					realFixedP = 0;
					cout << "INVALID PERCENTAGE INPUT, MUST BE A NUMBER BETWEEN 0 AND 100" << endl;
					string innerFixed;
					in >> innerFixed;
					stringstream inner(innerFixed);
					inner >> realFixedP;
				}
				a.fixedPercentage = round(realFixedP) / 100;
				leftoverP -= a.fixedPercentage;
				cout << setw(leftWidthSize) << right << "Fixed P input: " << setw(numWidthSize) 
					<< a.fixedPercentage * 100 << "%" << "          P% left: " << leftoverP * 100 
					<< "%" << endl;

				cout << "Please input a percentage (0 - 100) of your income that you would " 
					<< "like to dedicate for Variable spendings. Note percentages are " 
					<< "rounded to the nearest hundredth." << endl;
				in >> pseudoVarP;
				stringstream varStream(pseudoVarP);
				double realVarP = 0;
				varStream >> realVarP;
				while (realVarP < 0 || realVarP > 100) {
					realVarP = 0;
					cout << "INVALID PERCENTAGE INPUT, MUST BE A NUMBER BETWEEN 0 AND 100" << endl;
					string innerVar;
					in >> innerVar;
					stringstream inner(innerVar);
					inner >> realVarP;
				}
				a.varPercentage = round(realVarP) / 100;
				leftoverP -= a.varPercentage;
				cout << setw(leftWidthSize) << right << "Var P input: " << setw(numWidthSize)
					<< a.varPercentage * 100 << "%" << "          P% left: " << leftoverP * 100 
					<< "%" << endl;

				cout << "Please input a percentage (0 - 100) of your income that you would "
					<< "like to dedicate for Savings. Note percentages are " 
					<< "rounded to the nearest hundredth." << endl;
				in >> pseudoSaveP;
				stringstream saveStream(pseudoSaveP);
				double realSaveP = 0;
				saveStream >> realSaveP;
				while (realSaveP < 0 || realSaveP > 100) {
					realSaveP = 0;
					cout << "INVALID PERCENTAGE INPUT, MUST BE A NUMBER BETWEEN 0 AND 100" << endl;
					string innerSave;
					in >> innerSave;
					stringstream inner(innerSave);
					inner >> realSaveP;
				}
				a.savePercentage = round(realSaveP) / 100;
				leftoverP -= a.savePercentage;
				if (abs(leftoverP) < .001) {
					leftoverP = 0;
				}
				cout << setw(leftWidthSize) << right << "Save P input: " << setw(numWidthSize)
					<< a.savePercentage * 100 << "%" << "          P% left: " << leftoverP * 100 
					<< "%" << endl;

				double totalPercentage = a.fixedPercentage + a.varPercentage + a.savePercentage;
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
			a.fixedPercentage = .5;
			a.varPercentage = .3;
			a.savePercentage = .2;
		}

		/*
		Asks for user confirmation over correctness of inputted data
			-Budget currency, month, after-tax income, & fixed, var, & savings %
		*/
		cout << "Please confirm whether these numbers are correct. "
			<< "If not, input \"n\" to re-enter, otherwise input anything else" << endl;
		const int specialWidth = 21;
		cout << setw(specialWidth) << right << "Currency chosen:" << left << a.curr << endl;
		cout << setw(medWidth) << right << "Month chosen: " << a.m << endl;
		cout << setw(medWidth) << right << "After-tax income: " << a.afterTaxIncome  << a.curr << endl;
		cout << setw(medWidth) << right << "Fixed Percentage: " << a.fixedPercentage * 100 << "%" << endl;
		cout << setw(medWidth) << right << "Variable Percentage: " << a.varPercentage * 100 << "%" << endl;
		cout << setw(medWidth) << right << "Savings Percentage: " << a.savePercentage * 100 << "%" << endl;
		in >> confirm;
	}

	/*
	Initializes total and conditional amounts for all 3 categories as determined by the user
	*/
	a.amountLeft = a.afterTaxIncome;
	a.condFixedAmount = round(a.fixedPercentage * a.afterTaxIncome);
	a.condVarAmount = round(a.varPercentage * a.afterTaxIncome);
	a.condSaveAmount = round(a.savePercentage * a.afterTaxIncome);
	a.currFixedAmount = a.condFixedAmount;
	a.currVarAmount = a.condVarAmount;
	a.currSaveAmount = a.condSaveAmount;

	const int largeWidth = 30;

	/*
	Prints calculated conditional values back to user
	*/
	cout << "Great! These are the money amounts allocated for each spending category" << endl << endl;
	cout << setw(largeWidth) << right << "Fixed Spending Allocation: " << a.condFixedAmount << a.curr << endl;
	cout << setw(largeWidth) << right << "Variable Spending Allocation: " << a.condVarAmount << a.curr << endl;
	cout << setw(largeWidth) << right << "Savings Allocation: " << a.condSaveAmount << a.curr << endl << endl;

	cout << "Now it's time to enter in your spending events." << endl << endl;

	/*
	Event input loop continues until user declares they have no more events to input
	*/
	string pseudoEventCheck = "y";
	while (pseudoEventCheck == "y") {
		Event e(a.curr, nullSpending, -1, "", "", a.m);
		in >> e;
		a.addEvent(e);

		cout << "This is your current budget with your new event." << endl << endl;
		cout << a;

		cout << endl << "Please input \"y\" to continue inputting events. Otherwise, please input anything else" << endl;
		in >> pseudoEventCheck;
		cout << endl;
	}

	a.calculate();
	return in;
}

#endif