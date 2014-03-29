#include <iostream>
#include <cmath>
#include "coordinates.h"
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
