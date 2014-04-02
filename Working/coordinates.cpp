#include <iostream>
#include <cmath>
#include "coordinates.h"
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

