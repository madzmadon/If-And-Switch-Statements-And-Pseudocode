//Madison Evans
//Prompt the customer to input their customized art piece information, and then calculate and display an invoice from that data

/*
Create a symbolic constant PI - 3.1416
Build and display a menu for the user that displays the three choices of shapes available with an option to also quit the program
Prompt the customer to enter a desired art shape via a menu option.
    Display an error message if input is invalid
Prompt the customer to enter their name
Prompt the customer to input the dimensions of the shape they have chosen
Calculate the volume of the desired shape
    Use setprecision to calculate to the tenth of a decimal point
    a. Volume of a cube: side3
    b. Volume of a torus: (1/4) (PI)^2 (r + R) (R - r)^2
    c. Volume of an ellipsoid: (4/3) (PI) (a) (b) (c)
Calculate the handling fee and shipping charge based on the volume fo the shape
    Volume (x cubic feet)   Handling fee        Shipping Charge based on Volume
    0 < x <= 50              $5.55              $0.10 per cubic foot
    50 < x <= 100            $7.75              $0.23 for each cubic foot > 50
    100 < x <= 150           $9.50              $0.28 for each cubic foot > 100
    x > 150 $11.25 $0.32 for each cubic foot > 150
Calculate the total processing charge (sum of handling and shipping)
Create an invoice
    Display the name of the customer
    Display the name fo the chosen art shape
    Display the dimension(s) of the shape
    Display the calculated volume
    Display the handling fee
    Display the shipping charge
    Display the total pocessing charges
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

//symbolic constant PI - 3.1416
const double PI = 3.1416;

int main(){
    
    int shapeChoice;
    string name;
    
    //Cube Measurements
    double side;
    
    //Torus Measurements
    double majorRadius;
    double minorRadius;
    
    //Ellipsoid Measurements
    double aAxis;
    double bAxis;
    double cAxis;
    
    double volume;
    double handlingFee;
    double shippingCharge;
    double totalCharge;
    
    //Menu for the user + Prompt to input choice
    cout << " Please enter your choice of shape from the following menu:\n"
    << "1. Cube\n"
    << "2. Torus\n"
    << "3. Ellipsoid\n"
    << "4. Quit\n"
    << endl
    << "Enter Menu Choice: ";
    cin >> shapeChoice;
    
    //display invalid choice if outside of menu options
    if (shapeChoice > 4 || shapeChoice < 1)
            cout << "Invalid menu choice – Run program again.\n";
    
    //Prompt the customer to enter their name if menu option input valid
    if (shapeChoice >= 1 && shapeChoice <= 3)
    {
        cin.get();
        cout << "Enter the Name of the Customer: ";
        getline(cin, name);
    }
    
    //Prompt the customer to input the dimensions of the shape they have chosen and calculate volume
    switch (shapeChoice)
    {
        case 1:
            cout << "\nEnter the Side measurement of the cube: ";
            cin >> side;
            cout << endl << endl;
            volume = pow(side, 3);
            break;
            
        case 2:
            cout << "\nEnter the Major Radius (R) measurement of the Torus: ";
            cin >> majorRadius;
            cout << "/nEnter the minor radius (r) measurement of the Torus: ";
            cin >> minorRadius;
            cout << endl << endl;
            volume = (1.0/4.0) * pow(PI, 2.0) * (minorRadius + majorRadius) * pow((majorRadius - minorRadius), 2.0);
            //volume is not calculating right
            break;
            
        case 3:
            cout << "\nEnter the a-axis radius: ";
            cin >> aAxis;
            cout << "\nEnter the b-axis radius: ";
            cin >> bAxis;
            cout << "\nEnter the c-axis radius: ";
            cin >> cAxis;
            volume = (4.0/3.0) * PI * aAxis * bAxis * cAxis;
            //volume is not calculating right
            break;
            
        case 4:
            cout << "Thanks for using this program!!!\n";
            break;
    }
   
    //Calculate the handling fee and shipping charge based on the volume fo the shape
    if (volume > 0 && volume <= 50)
    {
        handlingFee = 5.55;
        shippingCharge = volume * .10;
    }else if (volume > 50 && volume <= 100)
    {
        handlingFee = 7.75;
        shippingCharge = (volume - 50) * .23;
    }else if (volume > 100 && volume <= 150)
    {
        handlingFee = 9.50;
        shippingCharge = (volume - 100) * .28;
    }else
    {
        handlingFee = 11.25;
        shippingCharge = (volume - 150) * .32;
    }
    
    //Calculate the total processing charge
    totalCharge = handlingFee + shippingCharge;
    
    
    cout << setprecision(1) << showpoint << fixed;
    
    //Create and display an invoice
    if (shapeChoice <= 3 && shapeChoice >= 1)
    {
        cout << "\n\nShipping Invoice for " << name << endl << endl;
    
        switch (shapeChoice)
        {
            case 1:
                cout << "Dimensions of the Cube: \n"
                << "Side: " << side << " feet\n\n";
            break;
        
            case 2:
                cout << "Dimensions of the Torus:\n"
                << "Major Radius (R): " << majorRadius
                << "minor radius (r): " << minorRadius << endl << endl;
            break;
    
            case 3:
                cout << "Dimensions of the Ellipsoid:\n"
                << "A-axis Radius: " << aAxis << " feet\n"
                << "B-axis Radius: " << bAxis << " feet\n"
                << "C-axis Radius: " << cAxis << " feet\n";
            break;
        }
    
    
        cout << "\nVolume: " << volume << " cubic feet\n\n";
    
        cout << setprecision(2) << showpoint << fixed;
        
        cout << "Handling fee................$" << handlingFee << endl
        << "Shipping Charge.............$" << shippingCharge << endl
        << "Total Processing Charges....$" << totalCharge << endl;
    }
}
