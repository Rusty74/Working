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
