/**************************************************************************************
*
*Project Name: Event planning agency
*
*Author: Bassant Ahmed
*
**************************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int n = 300;

class Event
{
private:
	char EventName[n];
	char CustomerName[n];
	int GuestCount;
	int EventDuration;
	int NumberOfWaiters;
	float CostPerWaiter;
	float FoodCost;
	float TotalCost;
	float DepositAmount;
public:
	Event() //Constructor
	{
		//Put initial values to all variables because if user doesn't enter a value.
		EventName[0] = '\0';
		CustomerName[0] = '\0';
		GuestCount = 0;
		EventDuration = 0;
		NumberOfWaiters = 0;
		CostPerWaiter = 0;
		FoodCost = 0;
		TotalCost = 0;
		DepositAmount = 0;
	}
	void getEventName()
	{
		char en[n];
		char EN[n];
		cout << "Enter the name of the event \n";//Ask the user to enter event name
		cin.getline(en, n);
		for (int i = 0; i < n; i++)
		 EN[i] = en[i];
		while (strlen(EN)==0)//To check that user enter the event name
		{
			cout << "Please enter the name of the event: \n";
			cin.getline(EN, n);
		}
		for (int i = 0; i < n; i++)
		EventName[i] = EN[i];

	}
	void getCustomerName()
	{
		char cn[n];
		char CN[n];
		//Ask the user to enter his first and last name
		cout << "Enter the customer's first and last name \n";
		cin.getline(cn, n);
		for (int i = 0; i < n; i++)
			CN[i] = cn[i];
		while (strlen(CN) == 0)//To check that user enter the customer's name
		{
			cout << "Please enter the customer's first and last name: \n";
			cin.getline(CN, n);
		}
		for (int i = 0; i < n; i++)
			CustomerName[i] = CN[i];
	}
	void getGuestCount()
	{
		char s[n];
		//Ask the user to enter the number of guests
		cout << "Enter the number of guests \n";
		cin.getline(s, n);
		bool flag = true;
		int i = 0;
		while (flag)
		{
			if (s[i] == '\0') //when reaches null terminator
				flag = false;

			else if (s[i] >= 48 && s[i] <= 57)//To check for digits only
			{
				flag = true;
				i++;
			}
			else {
				cout << "Please enter valid number : \n";
				cin.getline(s, n);
				i = 0;
			}
		}
		GuestCount = atoi(s); // Function to transform from array to integer
	}
	void getEventDuration()
	{
		char s[n];
		//Ask the user to enter number of minutes
		cout << "Enter the number of minutes in the event \n";
		cin.getline(s, n);
		bool flag = true;
		int i = 0;
		while (flag)
		{
			if (s[i] == '\0') //when reaches null terminator
				flag = false;

			else if ((s[i] >= 48 && s[i] <= 57) || s[i] == 46) //only checks presence of digits and decimal point
			{
				flag = true;
				i++;
			}
			else {
				cout << "Please enter valid number : \n";
				cin.getline(s, n);
				i = 0;
			}
		}
		float ed;
		ed = atof(s);
		EventDuration = round(ed);//To approximate the number of minutes
		cout << "\n---------------------------------------\n";
	}
	void CalculateCost()
	{
		NumberOfWaiters = ceil(float(GuestCount) / 20);//Number of waiters
		//Calculate cost per waiter
		int h(0);
		while (EventDuration >= 60)
		{
			h++;
			EventDuration -= 60;
		}
		CostPerWaiter = ((h * 46.5) + (EventDuration));
		//Calculate food cost
		FoodCost = GuestCount * 54.5;
		//Calculate total cost
		TotalCost = CostPerWaiter * NumberOfWaiters + FoodCost;
		//Deposit Amount
		DepositAmount = TotalCost * 0.25;
	}
	void PrintInfo()
	{
		cout << EventName << " Event\n";
		cout << "Event estimate for " << CustomerName << endl;
		cout << "---------------------------------------\n";
		cout << "Number of waiters: " << NumberOfWaiters << endl;
		cout << "The cost per waiter: " << CostPerWaiter << " EGP" << endl;
		cout << "The cost for food is: " << FoodCost << " EGP" << endl;
		cout << "Total cost is:" << TotalCost << " EGP" << endl;
		cout << "Please provide a 25% deposit to reserve the event \n";
		cout << "The deposit needed is: " << DepositAmount << " EGP" << endl;
	}
};

int main()
{
	Event ev1;
	ev1.getEventName();
	ev1.getCustomerName();
	ev1.getGuestCount();
	ev1.getEventDuration();
	ev1.CalculateCost();
	ev1.PrintInfo();

	return 0;
}
