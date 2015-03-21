//  CSC 125 - Online
//  nwilliams_week2lab.cpp
//  Author: Nick Williams on 2/13/15.
//  Description:
//      This program displays a menu that lists User options for mathematical computations, using functions.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void calculate_surface_volume(float, float, float);
bool is_even(int);
unsigned int factorial(float);
void powerTo(float, int);
void display_menu();
void display_even(int);
void display_odd(int);
float get_base();
int get_exp();

int main(int argc, const char * argv[]) {
    
    int user_selection;
    
    cout << "Welcome to CSC 125 Review!\n\n";
    
    // do while Re-Generates Main Menu Until User Quit Command
    do
    {
        // Main Menu Generation to Screen
        display_menu();
        
        cin >> user_selection;
        
        while (!cin) //Throws an error if alpha char entered
        {
            cin.clear();
            cin.ignore();
            cout << "Please enter specifically 1, 2, 3, 4, or 5: ";
            
            cin >> user_selection;
        }
        
        switch (user_selection)
        {
            case 1: //Volume and Surface Area
            {
                float dimension[3] = {0, 0, 0};
                string dim_title[3] = {"length", "width", "height"};
                
                cout << "**Volume and Surface Area**\n\n";
                cout << "Please Enter the Dimensions of a Box\n\n";
                
                // Retrieves User Input and Stores Values into an Array
                for (int i = 0; i < 3; i++) //Iterates through 3 dimensions
                {
                    cout << dim_title[i] + ": ";
                    cin >> dimension[i];
                    
                    while ((dimension[i] <= 0) || (!cin)) //Throws error for neg# or alpha char
                    {
                        cout << "You must enter a postive numerical value!\n\n";
                        cin.clear();
                        cin.ignore();
                        cout << dim_title[i] + ": ";
                        cin >> dimension[i];
                    }
                }
                
                // Calculates Volume & Surface Area and Displays Final Calculations
                calculate_surface_volume(dimension[0], dimension[1], dimension[2]);
                
                cout << "Press Enter to Return to Main Menu\n";
                
                cin.get();
                cin.ignore();
                
                break;
            }
            case 2: //Even/Odd
            {
                int user_input;
                
                cout << "**Even/Odd**\n\n";
                cout << "Please Enter a Positive Integer: ";
                
                cin >> user_input;
                
                while ((user_input <= 0) || (!cin)) //Throws error for neg# or alpha char
                {
                    cout << "You must enter a postive integer: ";
                    cin.clear();
                    cin.ignore();
                    cin >> user_input;
                }
                
                //Even/Odd Determination and Output of Sequence
                if (is_even(user_input))
                {
                    display_even(user_input);
                }
                else
                {
                    display_odd(user_input);
                }
                
                cout << "\n\nPress Enter to Return to Main Menu\n";
                
                cin.get();
                cin.ignore();
                
                break;
            }
            case 3: //Factorial
            {
                float user_input;
                
                cout << "**Factorial!**\n\n";
                cout << "Please Enter a Positive Number between 1 and 20: ";
                
                cin >> user_input;
                
                while ((user_input <= 0) || (user_input > 20) || (!cin))
                {
                    cout << "You must enter a postive number between 1 and 20: ";
                    cin.clear();
                    cin.ignore();
                    cin >> user_input;
                }
                
                cout << endl << user_input << " Factorial equals " << factorial(user_input) << endl;
                
                cout << "\n\nPress Enter to Return to Main Menu\n";
                
                cin.get();
                cin.ignore();
                
                break;
            }
            case 4: //X^n
            {
                float base;
                int exponent;
                
                cout << "**Powers of X**\n\n";
                base = get_base();
                exponent = get_exp();
                
                powerTo(base, exponent);
                
                cout << "\n\nPress Enter to Return to Main Menu\n";
                
                cin.get();
                cin.ignore();
                
                break;
            }
            case 5: //Quit
            {
                break;
            }
            default: //Invalid Input
            {
                break;
            }
        }
    } while (user_selection != 5);
    
    cout << "Thank you, and Enjoy Your Day!";
}

void display_menu()
{
    cout << "MAIN MENU\n\n";
    cout << "Please Choose One of the Following Calculations\n";
    cout << "by Entering the Integer Value that\n";
    cout << "Corresponds to your Selection (1 - 5)\n\n";
    cout << "1 - Volume and Surface Area\n";
    cout << "2 - Even/Odd\n";
    cout << "3 - Factorial!\n";
    cout << "4 - Powers of X\n";
    cout << "5 - QUIT\n\n";
    cout << "Your Selection: ";
}

void calculate_surface_volume(float x, float y, float z)
{
    float volume = 0;
    float surface_area = 0;
    
    volume = (x * y * z);
    surface_area = (2 * ((x * y) + (y * z) + (z * x)));
    
    cout << "Thanks! With sides of lengths ";
    cout << fixed << setprecision(2) << x << ", ";
    cout << fixed << setprecision(2) << y << ", and ";
    cout << fixed << setprecision(2) << z << ",\n";
    cout << "The Volume of your Box is ";
    cout << fixed << setprecision(2) << volume << " Cubed Units.\n";
    cout << "The Surface Area of your Box is ";
    cout << fixed << setprecision(2) << surface_area << " Units Square.\n\n";
    cout << scientific;
}

bool is_even(int x)
{
    if (x % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void display_even(int x)
{
    cout << "You Entered an EVEN Number!\n\n";
    cout << "Here are the even numbers up to yours: \n";
    
    for (int i = 0; i <= x; i += 2)
    {
        cout << i << " ";
    }
}

void display_odd(int x)
{
    cout << "You Entered an ODD Number!\n\n";
    cout << "Here are the odd numbers up to yours: \n";
    
    for (int i = 1; i <= x; i += 2)
    {
        cout << i << " ";
    }
}

unsigned int factorial(float x)
{
    unsigned int factorial = 1;
    unsigned int y;
    
    if (x - int(x) == 0)
    {
        y = x;
    }
    else
    {
        y = int(x);
    }
    
    for (int i = y; i > 0; i--) //Factorial Calculation
    {
        factorial *= i;
    }
    
    return factorial;
}

void powerTo(float x, int y)
{
    float final_calculation = 1;
    
    for (int i = y; i > 0; i--) //Exponential Calculation
    {
        final_calculation *= x;
    }
    
    cout << endl << x << " to the power of " << y
    << " Equals: " << final_calculation << endl;
}

float get_base()
{
    float x;
    
    cout << "Please Enter a Positive Integer Base and Exponent between 1-15: \n\n";
    cout << "Base: ";
    cin >> x;
    
    while ((x <= 0) || (x > 15) || (!cin))
    {
        cout << "You must enter a postive number between 1 and 15: ";
        cin.clear();
        cin.ignore();
        cin >> x;
    }
    
    return x;
}

int get_exp()
{
    int x;
    
    cout << "Exponent: ";
    cin >> x;
    
    while ((x <= 0) || (x > 15) || (!cin))
    {
        cout << "You must enter a postive integer between 1 and 15: ";
        cin.clear();
        cin.ignore();
        cin >> x;
    }
    
    return x;
}