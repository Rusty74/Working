#include<iostream>
#include<cmath>
using namespace std;

//structure declarations
struct polar
{
   double distance;     //distance from origin
   double angle;    //direction from origin
};

struct rect
{
   double x; // horizontal distance from origin
   double y; // vertical distance from origin
};

//prototypes

void rect_to_polar(const rect * pxy, polar * pda);

void show_polar (const polar * pda);

void polar_to_rect(const polar * pda);

void show_rect(const rect * pxy, polar * pda);


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

//Convert Polar to Rectangular Coordinates

void polar_to_rect(const polar * pda, rect * pxy)
{
   const double Rad_to_deg = 0.01745329252;
   pxy->x = pda->distance * cos(pda->angle * Rad_to_deg);
   pxy->y = pda->distance * sin(pda->angle * Rad_to_deg);

   //Fix coordinates for angles 0, 90, 270, 180 degrees
   if (pda->angle == 90||pda->distance == 270)
   {
       pxy->x = 0;
   }
   if (pda->angle == 0||pda->distance == 180)
   {
       pxy->y = 0;
   }


return; // Display Cartesian Coordinates
}

//Show Rectangular Coordinates

void show_rect(const rect * pxy,  polar * pda)
{
cout << "x = " << pxy->x << ", y = " << pxy->y;
}



void rect_to_polar(const rect * pxy,  polar * pda)
{
	pda->distance = sqrt( (pxy->x) * (pxy->x) + (pxy->y) * (pxy->y));
    pda->angle = atan2(pxy->y,  pxy->x); }

// show polar coordinates, converting angle to degrees

void show_polar (const polar * pda)
{
	const double Rad_to_deg = 57.29577951;
    cout << "distance = " << pda->distance;
    cout << ", angle = " << pda->angle * Rad_to_deg;
    cout << " degrees\n";
}

