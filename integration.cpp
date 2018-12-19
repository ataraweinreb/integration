#include <iostream>
using namespace std;

// Returns the area under the curve between x=a and x=b.
// The function passed as the first parameter determines the shape of the curve.
// Use a Riemann sum to estimate the area by dividing it into narrow rectangles (each rectangle should have a width of .0001)
// and adding up the areas of the individual rectangles.
// For a rectangle at horizontal position x, the height will be f(x).
// (when you call f(x) it'll call whatever function you passed as the first parameter)

typedef double (*FUNC)(double); //creates a pointer to a func which takes in a double and returns a double

double integrate(FUNC f, double a, double b) {
    //init vars to store sum and base
    double sum=0; 
    double base=.0001;
    for(double i=a; i<b; i+=base){ //for loop starts from the first endp and runs until 2nd endp, incrementing by the base
        sum+=f(i)*base; //add area of rectangle to sum
    }
    return sum;
}

double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
   return 0;
}
