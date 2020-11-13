//Includes functions used to read and write data
#include<iostream>

//Contains functions for converting from 1 data type to another, random number generation, memory management, 
//searching, math, sorting and other general purpose functions
#include<cstdlib>

//Allows you to use the STL string class
#include<string>

//Provides functions to find min and max values for data types
#include<limits>

//array, file I/O, time, math
#include<vector>
#include<sstream>
#include<numeric>
#include<ctime>
#include<cmath>

//state that we can use standard namespace which means we don't have to type std::cout for output
using namespace std;

//A global variable is declared outside of all functions and it can be accessed any place in the code
int imGlobal = 0;

//use const to declare a variable const that value cannot be changed
const double PI = 3.141;

//------Data Types-------
//Data types define how much memory to set aside for data we wanto to store
//Booleans can have a value of true (1) or false (0)
namespace ex_data_type {
    void TEST()
    {
        bool married = true;

        //chars store 256 single characters represented by keys on your keyboard
        char myGrade = 'A';

        //There are many integer types with different min and max values
        cout << "Min unsigned short int " << numeric_limits<unsigned short int>::min() << endl;
        cout << "Max unsigned short int " << numeric_limits<unsigned short int>::max() << endl;
        cout << "Min short int " << numeric_limits<short int>::min() << endl;
        cout << "Max short int " << numeric_limits<short int>::max() << endl;
        cout << "Min int " << numeric_limits<int>::min() << endl;
        cout << "Max int " << numeric_limits<int>::max() << endl;
        cout << "Min long " << numeric_limits<long>::min() << endl;
        cout << "Max long " << numeric_limits<long>::max() << endl;

        //Floating type numbers have decimal places
        cout << "Min float " << numeric_limits<float>::min() << endl;
        cout << "Max float " << numeric_limits<float>::max() << endl;
        cout << "Min double " << numeric_limits<double>::min() << endl;
        cout << "Max double " << numeric_limits<double>::max() << endl;
        cout << "Min long double " << numeric_limits<long double>::min() << endl;
        cout << "Max long double " << numeric_limits<long double>::max() << endl;

        //The float is accurate to 6 digits
        float f1 = 1.1111111;
        float f2 = 1.1111111;

        //printf allows you to print with formatting. Here I say I want to print 7 decimals
        printf("Sum = %0.7f\n", (f1 + f2));

        //doubles have 15 digits of precision
        double d1 = 1.1111111111111111;
        double d2 = 1.1111111111111111;
        printf("Sum = %.16f\n", (d1 + d2));

        //you can have the compilier assign the type
        auto whatAmI = true;

        //Get the number of bytes assigned to a type
        cout << "int Bytes : " << sizeof(int) << endl;

        //char, int, 5 space right justified int, 3 decimal float/double, string specifiers
        printf("%c %d %5d %0.3f %s\n", 'A', 10, 5, 3.1234, "Hi");

        //create a string
        string q1 = "Enter a number : ";

        //create strings to store values
        string num1, num2;

        //receive user input and store it
        cin >> num1;

        cout << "Enter another number : ";
        cin >> num2;

        //convert strings into ints
        int nNum1 = stoi(num1);
        int nNum2 = stoi(num2);

        //Math Operators
        printf("%d + %d = %d\n", nNum1, nNum2, (nNum1 + nNum2));
        printf("%d - %d = %d\n", nNum1, nNum2, (nNum1 - nNum2));
        printf("%d * %d = %d\n", nNum1, nNum2, (nNum1 * nNum2));
        printf("%d / %d = %d\n", nNum1, nNum2, (nNum1 / nNum2));
        printf("%d %% %d = %d\n", nNum1, nNum2, (nNum1 % nNum2));
        cout << "\n";
    }
}

//-----Conditionals------
//conditional operators : >, <, >=, <=, ==, !=
//logical operators : &&, ||, !
namespace ex_conditional {
    void TEST()
    {
        string sAge;
        cout << "Enter your age : ";
        cin >> sAge;
        int nAge = stoi(sAge);

        //used to output whether a birthday is important
        if ((nAge >= 1) && (nAge <= 18)) {
            cout << "No alcohol" << endl;
        }
        else if ((nAge == 21) || (nAge == 50)) {
            cout << "Important birthday" << endl;
        }
        else if (nAge >= 65) {
            cout << "No cigarette";
        }
        else {
            cout << "Not important" << endl;
        }

        //A ternary operator works like a compact if else statement. If the condition is true the first value is stored and otherwise the second
        int age43 = 43;
        bool canIVote = (age43 >= 18) ? true : false;
        //shows bool values as true or false
        cout.setf(ios::boolalpha);
        cout << "Can Jadav vote : " << canIVote << endl;
    }
}

//------ARRAYS-------
//An array is a collection of data of the same type. Once the size is defined it can't change.
namespace ex_array {
    void TEST()
    {
        //declare an array of 10 integers with the first value of 1.
        int arrnNums[10] = { 1 };

        //leave out the array length. It determined automatically
        int arrnNum2[] = { 1,2,3 };

        //create an array and assign some values. Rest will be assigened zeros
        int arrnNums3[5] = { 8,9 };

        //access array values using indices starting with 0
        cout << "1st value : " << arrnNums3[0] << endl;

        //change a value
        arrnNums3[0] = 7;
        cout << "1st value : " << arrnNums3[0] << endl;

        //A multidimensional array is like a spreadsheet.
        //1st Number : which sheet
        //2nd Number : which row
        //3rd Number : which column
        int arrnNums4[2][2][2] = { {{1,2}, {3,4}},
            {{5,6}, {7,8}} };
        cout << arrnNums4[0][1][1] << endl;
    }
}

//------VECTORS-------
//Vectors are used when you don't know how big the array size
namespace ex_vector {
    void TEST()
    {
        std::vector<int>vNums(2);

        //Add values
        vNums[0] = 1;
        vNums[1] = 2;

        //Add another to the end
        vNums.push_back(3);

        //Get vector size
        cout << "Vector size : " << vNums.size() << endl;
    }
}

//------LOOPING-------
//while loop continue to run the in tem as long as a condition is true
//create a variable used in the while condition before the while loop
namespace ex_loop {
    void TEST()
    {
        int i = 1;
        while (i <= 20) {
            //if a value is even don't print it
            if ((i % 2) == 0) {
                i += 1;
                //continue skips the rest of the code and jumps back to the beginning of the loop
                continue;
            }
            //break stops execution of the loop and jumps to the line after loop closing }
            if (i == 15) break;
            cout << i << "\n";
            //increment i so the loop eventually ends
            i += 1;
        }

        //A stringstream object receives strings separated by a space and then spits them out 1 by 1
        vector<string>words;
        stringstream ss("Some Random Words");
        string word;

        //A while loop will execute as long as there are more word
        while (getline(ss, word, ' ')) {
            words.push_back(word);
        }
        //cycle through each index in the vector using a for loop
        for (int i = 0; i < words.size(); ++i) {
            cout << words[i] << endl;
        }

        //An abbreviated for loop
        int arr3[] = { 1, 2, 3 };
        for (auto x : arr3) cout << x << endl;


        //do while loops are guaranteed to execute at least once. We'll create a secret number guessing game
        //We need to seed the random number generator time() returns the number of seconds
        //since 1, 1, 1970
        //include <ctime>
        srand(time(NULL));

        //Generate a random number up to 10
        int secretNum = rand() % 11;
        int guess = 0;
        do {
            cout << "Guess the number : ";
            cin >> guess;
            if (guess > secretNum) cout << "Too Big\n";
            if (guess < secretNum) cout << "Too Small\n";
        } while (secretNum != guess);
        cout << "You guessed it " << endl;
    }
}

//------STRINGS-------
namespace ex_string {
    void TEST()
    {
        //A C++ string is a series of characters that can be chnaged
        string str1 = "I'm a string";
        cout << "Beginning string : " << str1 << endl;
        //Get the 1st character
        cout << "1st : " << str1[0] << endl;
        //Get the last character
        cout << "Last : " << str1.back() << endl;
        //Get the string length
        cout << "Length : " << str1.length() << endl;
        //Copy a string to another
        string str2 = str1;
        cout << "Copied string :" << str2 << endl;
        //Copy a string after the 1st 4 characters
        string str3(str2, 4);
        cout << "Copied string after 4 character :" << str3 << endl;
        //Combine strings
        string str4 = str1 + " and you not";
        cout << "Combined string : " << str4 << endl;
        //Append to the end of a string
        str4.append("!");
        cout << "Append : " << str4 << endl;
        //Erase characters from a string from 1 index to another
        str4.erase(12, str4.length() - 1);
        cout << "Erased string : " << str4 << endl;

        //find() returns index where pattern is found or npos (End of String)
        if (str4.find("string") != string::npos)
            cout << "String Index : " << str4.find("string") << endl;

        //substr(x, y) returns a substring starting at index x with a length of y
        cout << "Sub-string : " << str4.substr(6, 6) << endl;

        // Conver int to string
        string strNum = to_string(1 + 2);
        cout << "I'm a string : " << strNum << endl;

        //Character functions
        char letterZ = 'z';
        char num5 = '5';
        char aSpace = ' ';
        cout << "Is z a letter or number : " << isalnum(letterZ) << endl;
        cout << "Is z a letter : " << isalpha(letterZ) << endl;
        cout << "Is 3 a number : " << isdigit(num5) << endl;
        cout << "Is space a space : " << isspace(aSpace) << endl;
    }
}

//------MATH FUNCTIONS-------
//There are numerous math functions provided by cmath (en.cppreference.com/w/cpp/numeric/math)
namespace ex_math {
    void TEST()
    {
        cout << "abs(-10) = " << abs(-10) << endl;
        cout << "max(5, 4) = " << max(5, 4) << endl;
        cout << "min(5, 4) = " << min(5, 4) << endl;
        cout << "fmax(5.3, 4.3) = " << fmax(5.3, 4.3) << endl;
        cout << "fmin(5.3, 4.3) = " << fmin(5.3, 4.3) << endl;
        cout << "ceil(10.45) = " << ceil(10.45) << endl;
        cout << "floor(10.45) = " << floor(10.45) << endl;
        cout << "round(10.45) = " << round(10.45) << endl;
        cout << "pow(2, 3) = " << pow(2, 3) << endl;
        cout << "sqrt(100) = " << sqrt(100) << endl;
        cout << "cbrt(1000) = " << cbrt(1000) << endl;

        // e ^ x
        cout << "exp(1) = " << exp(1) << endl;
        //2 ^ x
        cout << "exp2(1) = " << exp2(1) << endl;
        // e * e * e ~= 20 so log(20.079) ~= 3
        cout << "log(20.078) = " << log(20.078) << endl;
        //2 * 2 * 2 = 8
        cout << "log2(8) = " << log2(8) << endl;
        //Hypotenuse = sqrt(A^2 + B^2)
        cout << "hypot(2,3) = " << hypot(2, 3) << endl;
        //Also sin, co, tan asin, acos etc
    }
}

//execution of code starts in the main function argc and argv is optional data that could be passed to the program if it is executed in a terminal
//argc : number of arguments passed
//argv : array pointers to string
int main(int argc, char** argv)
{

    cout << "\n------Data Type------" << endl;
    ex_data_type::TEST();
    cout << endl;

    cout << "\n------Conditional------" << endl;
    ex_conditional::TEST();
    cout << endl;

    cout << "\n------Array------" << endl;
    ex_array::TEST();
    cout << endl;

    cout << "\n------Vector------" << endl;
    ex_vector::TEST();
    cout << endl;

    cout << "\n------loop------" << endl;
    ex_loop::TEST();
    cout << endl;

    cout << "\n------String------" << endl;
    ex_string::TEST();
    cout << endl;

    cout << "\n------Math------" << endl;
    ex_math::TEST();
    cout << endl;

    

    return 0;
}