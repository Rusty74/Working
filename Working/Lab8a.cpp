#include<iostream>
#include "coordinates.h"

int main()
{
	rect rplace;
	polar pplace;
	char choice;
	int quit;

	while (quit != 1)
	{
		cout << "\nEnter P (Polar to rectangular), R (Rectangular to polar), or Q (Quit): ";
		cin >> choice;

		if (choice == 'p' || choice == 'P')
		{
			cout << "Enter the distance and angle values: ";

			cin >> pplace.distance >> pplace.angle;
			{
				polar_to_rect(&pplace);
				show_rect(&rplace, &pplace);

			}
		}
		else if (choice == 'r' || choice == 'R')
		{
			cout << "Enter the x and y values: ";

			while (cin >> rplace.x >> rplace.y)
			{
				rect_to_polar(&rplace, &pplace);    // pass addresses
				show_polar(&pplace);                   // pass address
			}
		}



		else if (choice == 'Q' || choice == 'q')
		{
			cout << "Done!"<<endl;
			quit=1;
		}



		else
		{
				   cout << "Invalid Entry!"<<endl;
		}
	}

return 0;
}
