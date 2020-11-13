#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

//function prototype
double AddNumbers(double num1, double num2);
void AssignName();
void AssignAge(int age);
int AssignAge2(int age);
void AssignAge3(int* pAge);
void DoubleArray(int* arr, int size);

int main()
{
    //-----FUNCTIONS-----
    //You define function prototypes outside of main so main knows a functions basic setting.
    //Functions are also created outside of main and can be found after main below

    //Call a function that sums values
    printf("%.1f + %.1f = %.1f\n", 5.0, 4.0, AddNumbers(5, 4));

    //The function AssignName below creates a variable called name, but variables created in functions are not availbel outside of that function

    //Variable values changes in a function don't change that variable value outside the function
    int age2 = 43;
    AssignAge(age2);
    std::cout << "New Age : " << age2 << std::endl;

    //You could change the value by passing it back
    age2 = AssignAge2(age2);
    cout << "New Age : " << age2 << endl;

    //------POINTERS--------
    //A pointer stores a address in memory
    //You decalre a pointer to be of the same type as the data type to whoch it points
    //If you are storing the address of an int then the pointer is an int
    //When you declare a pointer give it a null value

    int* pAge2 = NULL;
    //The reference operator returns the address for a variable that can be stored in a pointer
    pAge2 = &age2;
    //Print the address Hexadecimal number
    cout << "Value at address : " << pAge2 << endl;
    //Get the value at that address with the dereference operator
    cout << "Value at address : " << *pAge2 << "\n";
    //We can create a pointer to an array and cycle through the data with ++ and -
    int intArray[] = { 1,2,3,4 };
    int* pIntArray = intArray;

    cout << "1st : " << *pIntArray << " and Address : " << pIntArray << endl;
    pIntArray++;
    cout << "2nd : " << *pIntArray << " and Address : " << pIntArray << endl;
    pIntArray--;
    cout << "1st : " << *pIntArray << " and Address : " << pIntArray << endl;

    //You can pass a pointer to a function and then the function can change that variable value globally
    age2 = 43;
    //Send the address for age to the function
    AssignAge3(&age2);
    cout << "Pointer Age : " << age2 << endl;

    //create an array and double values
    int arr[] = { 1, 2, 3, 4 };
    DoubleArray(arr, 4);
    for (int i = 0; i < 4; ++i) {
        cout << "Array : " << arr[i] << endl;
    }

    //------EXCEPTION HANDLING--------
    //Exceptions are error that occur when things don't go as expected
    //You try to execute code that could be troublesome and if an error occurs you catch it and throw it to another block of code for handling
    double num3 = 10, num4 = 0;
    try {
        if (num4 == 0) {
            throw "Division by zero error";
        }
        else {
            printf("%.1f /%.1f = %.1f", num3, num4, (num3 / num4));
        }
    }
    catch (const char* exp) {
        cout << "Error : " << exp << endl;
    }

    return 0;

}

//A function starts with the data type it will return or void if no value is returned.
//You also list the data types for the parameters passed into a function and you may assign them default values

double AddNumbers(double num1 = 0, double num2 = 0) {
    return num1 + num2;
}

//A variable created inside a function and can't be accessed outside of it
void AssignName() {
    string name = "Computer";
}

void AssignAge(int age) {
    age = 24;
}

int AssignAge2(int age) {
    age = 24;
    return age;
}

//Function that receives a pointer
void AssignAge3(int* pAge) {
    //Use dereference operator to change the value at the address
    *pAge = 22;
}

//Double values in array
void DoubleArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = arr[i] * 2;
    }
}