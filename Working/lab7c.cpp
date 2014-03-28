#include<iostream>
#include<cmath>
using namespace std;

//structure declarations
struct polar
{
   double distance; //distance from origin
   double angle; //direction from origin
};

struct rect
{
   double x; // horizontal distance from origin
   double y; // vertical distance from origin
};

//prototypes

polar rect_to_polar(rect &xypos);

void show_polar(polar &dapos);

rect polar_to_rect(polar &dapos);

void show_rect(rect &xypos);


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

//Convert Polar to Rectangular Coordinates

rect polar_to_rect(polar &dapos)
{
   rect answer;
   const double Rad_to_deg = 0.01745329252;
   answer.x = dapos.distance * cos(dapos.angle * Rad_to_deg);
   answer.y = dapos.distance * sin(dapos.angle * Rad_to_deg);

   //Fix coordinates for angles 0, 90, 270, 180 degrees
   if (dapos.angle == 90||dapos.angle == 270)
   {
       answer.x = 0;
   }

   if (dapos.angle == 0||dapos.angle==180)
   {
       answer.y = 0;
   }


return answer; // Display Cartesian Coordinates
}

//Show Rectangular Coordinates

void show_rect(rect &xypos)
{
cout << "x = " << xypos.x << ", y = " << xypos.y;
}

polar rect_to_polar(rect &xypos)
{
   polar answer;

   answer.distance = sqrt( xypos.x * xypos.x + xypos.y *xypos.y);
   answer.angle = atan2(xypos.y,xypos.x);

return answer; // returns a polar structure
}

// show polar coordinates, converting angle to degrees
void show_polar (polar &dapos)
{
const double Rad_to_deg = 57.29577951;

cout << "distance = " << dapos.distance;
cout << ", angle = " << dapos.angle * Rad_to_deg;
cout << " degrees\n";
}


