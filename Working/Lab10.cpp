#include <iostream>
#include <cstring>
using namespace std;

struct history_event
{
	char activity; 			//'A' acuire; 'B' Buy; 'S' Sell; 'U' Update
	int shares_bought; 		//To be filled if activity == 'B'
	int shares_sold;		//To be filled if activity == 'S'
	double share_value;
	int shares;
	double total_value;
};
class Stock     // class declaration
{
private:
	char company[30];
	int shares;
	double share_val;
	double total_val;
	void set_tot()
	{
		total_val = shares * share_val;
	}

	int number_of_successful_buys = 0;
	int number_of_successful_sells = 0;
	int number_of_unsuccessful_buys = 0;
	int number_of_unsuccessful_sells = 0;
	int number_of_updates = 0;
	history_event events[1000];		// events array
	int number_of_events = 0;			// logical size of events array

public:
	void acquire(const char * co, int n, double pr);
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	void show();
	void print_statistics();
};

void Stock::acquire(const char * co, int n, double pr)
{
	strncpy(company, co, 29);
	company[29] = '\0';
	if (n < 0)
	{
		cout << "Number of shares purchased can't be negative.\n" << "Transaction is aborted.\n";
		shares=0;
		share_val 	= pr;
		set_tot();
		return;
	}
	else
	{
		shares = n;
		share_val = pr;
		set_tot();

		events[number_of_events].activity = 'A';
		events[number_of_events].share_value = share_val;
		events[number_of_events].shares = shares;
		events[number_of_events].total_value = total_val;

		number_of_successful_buys = 0;
		number_of_successful_sells = 0;
		number_of_updates = 0;
		number_of_events = 1;

	}		//end if else
}		//end acquire

void Stock::buy(int num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares can't be negative.\n" << "Transaction is aborted\n";

		number_of_unsuccessful_buys++;
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();

		number_of_successful_buys++;
		events[number_of_events].activity = 'B';
		events[number_of_events].shares_bought = num;
		events[number_of_events].share_value = share_val;
		events[number_of_events].shares = shares;
		events[number_of_events].total_value = total_val;

		number_of_events++;

	}		//end if else
}		//end buy

void Stock::sell(int num, double price)
{
	if(num < 0)
	{
		cout << "Number of shares purchased can't be negative.\n";
		cout << "Transaction is aborted.\n\n";
		number_of_unsuccessful_sells++;

	}
	else if(num > shares)
	{
		cout << "You can't sell more shares than you have!\n";
		cout << "Transaction is aborted.\n\n";
		number_of_unsuccessful_sells++;
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();

		events[number_of_events].activity = 'S';
		events[number_of_events].shares_sold = num;
		events[number_of_events].share_value = share_val;
		events[number_of_events].shares = shares;
		events[number_of_events].total_value = total_val;

		number_of_events++;
		number_of_successful_sells++;
	}
}		//end sell

void Stock::update(double price)
{
	share_val = price;
	set_tot();

	number_of_updates++;

	events[number_of_events].activity = "U";
	events[number_of_events].share_value = share_val;
	events[number_of_events].shares = shares;
	events[number_of_events].total_value = total_val;

	number_of_events++;
}

// Modify the print_statisitics method below to
// do the following:
// Print the contents of the events array (event by event)
// as shown on the execution example.
// Print the number of successful/Unsuccessful buys and sells
// and number_of_updates
// YOU MUST USE A SWITCH STATEMENT INSIDE YOU
// LOOP (i.e.,switch on events[i].Activity).
void Stock::print_statistics()
{
    cout << "************ SHARE HISTORY OF ";
    cout << company << endl << endl;

    for (int i = 0; i < number_of_events; i++)
    {
        char activity = events[i].activity;
        cout << "\nEvent #" << i << ": ";
        switch (activity)
        {
            case 'A':
                cout << "Acquired " << events[i].shares << " at $" <<
                events[i].share_value << " per share\n Total shares: " <<
                events[i].shares << " Total Worth: $" << events[i].total_value << endl;
                break;

            case 'B':
                cout << "Bought " << events[i].shares_bought << " at $" <<
                events[i].share_value << " per share\n Total shares: " <<
                events[i].shares << " Total Worth: $" << events[i].total_value << endl;
                break;

            case 'S':
                cout << "Sold " << events[i].shares_sold << " at $" <<
                events[i].share_value << " per share\n Total shares: " <<
                events[i].shares << " Total Worth: $" << events[i].total_value << endl;
                break;

            case 'U':
                cout << "Updated share price to $" << events[i].share_value <<
                " per share\n Total shares: " << events[i].shares <<
                " Total Worth: $" << events[i].total_value << endl;
                break;

            default:
                cout << "Error recording activity. Corrupt data." << endl;
                break;
        }		//end switch

    }		//end for loop

    cout << endl;

    cout << "Number of successful buys: " << number_of_successful_buys << endl;
    cout << "Number of unsuccessful buys: " << number_of_unsuccessful_buys << endl;
    cout << "Number of successful sells: " << number_of_successful_sells << endl;
    cout << "Number of unsuccessful sells: " << number_of_unsuccessful_sells << endl;
    cout << "Number of updates: " << number_of_updates << endl;

}//end print_statistics


// Complete the main program below so that the output
// comes up as the execution example
int main()
{
	cout.setf(ios_base::showpoint); //#.## format
	cout.precision(2);				//#.## format
	cout.setf(ios_base::showpoint); //#.## format

	Stock stock1;

	stock1.acquire("NanoSmart",20,12.50);
	stock1.show();
	
	cout << "Trying to buy 15 shares @ $18.25 per share...\n";
	stock1.buy(15,18.25);
	stock1.show();
	
	cout << "Trying to sell 400 shares @ $20.00 per share... \n";
	stock1.sell(400,20.00);
	stock1.show();

	cout << "Trying to sell 5 shares @ $20.00 per share... \n";
	stock1.buy(5,20.00);
	stock1.show();

	cout << "Trying to buy -10 shares @ $5.00 per share... \n";
	stock1.buy(-10, 5.00);
	stock1.show();

	cout << "Updating share price to $10.00... \n";
	stock1.update(10.00);
	stock1.show();

	cout << "Trying to buy 20 shares @ $15.00 per share... \n";
	stock1.buy(20, 15.00);
	stock1.show();
	
	cout << "Trying to sell 25 shares @ $10.00 per share... \n";
	stock1.sell(25, 10.00);
	stock1.show();

	cout << "Updating share price to $100.00... \n";
	stock1.update(100.00);
	stock1.show();

	cout << "Trying to sell 10 shares @ $50.00 per share... \n";
	stock1.sell(10, 50.00);
	stock1.show();

	cout << "Trying to buy 100 shares @ $10.00 per share... \n";
	stock1.buy(100, 10.00);
	stock1.show();

	cout << "Updating share price to $100.00... \n";
	stock1.update(100.00);
	stock1.show();

	stock1.print_statistics();

}
