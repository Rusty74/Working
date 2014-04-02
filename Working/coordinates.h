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
