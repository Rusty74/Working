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
rplace = polar_to_rect(pplace);
show_rect(rplace);
}
}

else if (choice == 'r' || choice == 'R')
{
cout << "Enter the x and y values: ";

while (cin >> rplace.x >> rplace.y)
{
pplace = rect_to_polar(rplace);
show_polar(pplace);
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

