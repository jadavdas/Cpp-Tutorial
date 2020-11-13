//--------TEMPLATES / OTERATORS

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <fstream>
#include <deque>
#include <iterator>
#include <functional>

using namespace std;

//-----------MACROS--------
//This is a macro constant that will replace PI with 3.14159 in the code before execution
#define PI 3.14159

//This is a macro function that will do the same with a function
#define AREA_CIRCLE(radius) (PI* (pow(radius, 2)))

//--------FUNCTIONS AS OBJECTS--------
namespace ex_fun_object {
    //1. Created to store as a variable and to pass into another functions
    double MultBy2(double num) {
        return num * 2;
    }

    //2. Functions can receive other functions, the first double is the return type
    //followed by the data types for the parameter
    double DoMath(function<double(double)>func, double num) {
        return func(num);
    }

    //3. You can store functions in a vector
    double MultBy3(double num) {
        return num * 3;
    }

    void TEST()
    {
        //1. You can store functions as variables
        auto times2 = MultBy2;
        cout << "5 * 2 = " << times2(5) << endl;

        //2. Pass a function into a function
        cout << "6 * 2 = " << DoMath(times2, 6) << endl;

        //3. You can store functions in a vector
        //Create a vector using the function parameters and then load the function into the vector
        vector<function<double(double)>> funcs(2);
        funcs[0] = MultBy2;
        funcs[1] = MultBy3;
        cout << " 2 * 10 = " << funcs[0](10) << endl;
    }
}
//------TEMPLATE FUNCTIONS------
//We use templaes to create functions or classes that can work with many types
//Templates differ from function overloading in that 
//instead of having a function that does similar things with different objects 
//a template does the smae thing with different objects
namespace ex_template_function {
    //This says this is a function template that generates functions that except 1 parameter
    template <typename T>
    void Times2(T val) {
        cout << val << " * 2 = " << val * 2 << endl;
    }

    //Receive multiple paramter and return a value
    template <typename T>
    T Add(T val, T val2) {
        return val + val2;
    }

    //Work with chars and strings
    template <typename T>
    T Max(T val, T val2) {
        return (val < val2) ? val2 : val;
    }

    void TEST()
    {
        //The template function can receive ints or floats
        Times2(5);
        Times2(5.4);

        //Multiple parameters and returned value
        cout << "5 + 4 = " << Add(5, 4) << endl;
        cout << "5.5 + 4. 6 = " << Add(5.5, 4.6) << endl;

        //Get biggest value
        cout << "Max 4 or 8 = " << Max(4, 8) << endl;
        cout << "Max A or B = " << Max('A', 'B') << endl;
        cout << "Max Dog or Cat = " << Max("Dog", "Cat") << endl;
    }
}
//------END OF TEMPLATE FUNCTIONS------

//------TEMPLATE CLASS------
//Template classes are classes that can work with different data types
//You can define that you may receive parameters with different types, but they don't have to be different
namespace ex_template_class {
    template <typename T, typename U>
    class Person {
    public:
        T height;
        U weight;
        static int numOfPeople;
        Person(T h, U w) {
            height = h, weight = w;
            numOfPeople++;
        }
        void GetData() {
            cout << "Height : " << height << " and Weight : " << weight << endl;
        }
    };
    //You have to initialize static class members
    template<typename T, typename U> int Person<T, U> ::numOfPeople = 0;

    void TEST()
    {
        //When creating the object you must define the data types used
        Person<double, int> mikeTyson(5.83, 216);
        mikeTyson.GetData();

        //You access static values using the object and not the class
        cout << "Number of people : " << mikeTyson.numOfPeople << endl;
    }
}

//-----CONTAINERS------
//We have already seen the STL container vector
//There are many other special way of storing data

//-------DOUBLE ENDED QUEUE------
//A double ended queue (Deck) is a dynamic array that can be expanded or contracted on both ends
namespace ex_container {
    void TEST()
    {
        //A double ended queue (Deck) is a dynamic array that can be expanded or contracted on both ends
        deque<int> nums = { 1, 2, 3, 4 };
        nums.push_front(0);
        nums.push_back(5);
        for (int x : nums)
            cout << x << endl;

        //You can access index, values, but they are costly because values aren't stored
        //contigously, but instead use multiple arrays
        cout << nums[0] << endl;
    }
}

// ------ITERATORS--------
//Iterators are used to point at container memory locations
namespace ex_iterator {
    void TEST()
    {
        vector<int> nums2 = { 1, 2, 3, 4 };

        //Define an iterator as the same type
        vector<int>::iterator itr;

        //Refer to the vectors begin ad end while increasing the iterator
        for (itr = nums2.begin(); itr < nums2.end(); itr++) {
            //Get value at the pointer
            cout << *itr << endl;
        }

        //You can also increment a set number of spaces
        //Create an iterator and point it at the beginning of the vector
        vector<int>::iterator itr2 = nums2.begin();

        //Advance 2 spaces
        advance(itr2, 2);
        cout << *itr2 << endl;

        //Next works like advance, but it returns an iterator
        auto itr3 = next(itr2, 1);
        cout << *itr3 << endl;

        //Previous moves a set number of indexes and returns an iterator
        auto itr4 = prev(itr2, 1);
        cout << *itr4 << endl;
        cout << "\n";

        //You can also insert at a defined index
        vector<int> nums3 = { 1, 4, 5, 6 };
        vector<int> nums4 = { 2, 3 };
        auto itr5 = nums3.begin();
        advance(itr5, 1);
        copy(nums4.begin(), nums4.end(), inserter(nums3, itr5));

        for (int& i : nums3)
            cout << i << endl;
    }
}

//------POINTER / MALLOC / TEMPLATES
//A smart pointer is a class that provides the power of pointers, but aslo handles
//the reallocation of memory when it is no longer required (The pointer is 
// automatically destroyed)

namespace ex_malloc {
    void TEST()
    {
        //----MALLOC EXAMPLE------
    //When you define a primitive type like int or float you define exactly
    //the amount of space to set aside

    //If you need to define how much space to set aside you could call malloc()
    // and tell it how much space to set aside and it returns the address to tha memory address

        int amtToStore;
        cout << "How many numbers do you want to store : ";
        cin >> amtToStore;

        //Cretae an int pointer and set aside enough space
        int* pNums;
        //Cast the pointer and define how much space to set aside
        pNums = (int*)malloc(amtToStore * sizeof(int));

        //Check if memory was allocated
        if (pNums != NULL) {
            int i = 0;

            //Store values
            while (i < amtToStore) {
                cout << "Enter a Number : ";
                cin >> pNums[i];
                i++;
            }
        }

        cout << "You entered these numbers \n";
        for (int i = 0; i < amtToStore; i++) {
            cout << pNums[i] << endl;
        }

        //Delete the pointer
        delete pNums;
    }
}

namespace ex_smartpointer {
    void TEST()
    {
        // Smart Pointer Solution
        int amtToStore;
        cout << "How many numbers do you want to store : ";
        cin >> amtToStore;

        //This memory will be automatically reallocated
        unique_ptr<int[]> pNums(new int[amtToStore]);

        //unique_ptr can only have one owner
        //so this throws an error
        //unique_ptr<int[]>pNum2 = pNums;
        //I'll cover how to do this with shared_ptr in a later tutorial

        // Check if memory was allocated
        if (pNums != NULL) {
            int i = 0;

            //Store values
            while (i < amtToStore) {
                cout << "Enter a Number : ";
                cin >> pNums[i];
                i++;
            }
        }

        cout << "You entered these numbers \n";
        for (int i = 0; i < amtToStore; i++) {
            cout << pNums[i] << endl;
        }
    }
}

//typedef creates an alias for a more complex type name
typedef vector<int32_t>intVec;

//Here I demonstrate how to use templates polymorphically
//Base class all pizzas inherit along with MakePizza which will be overridden

namespace pizza {
    class Pizza {
    public:
        virtual void MakePizza() = 0;
    };

    //The last templates that will be called
    class NYStyleCrust {
    public:
        string AddIngredient() {
            return "Crust so Thin You can see through it \n\n";
        }
    };

    class DeepDishCrust {
    public:
        string AddIngredient() {
            return "Super Awesome Chicago Deep Dish Crust\n\n";
        }
    };

    //End of last templates called
    //The middle templates called
    template <typename T>
    class LotsOfMeat : public T {
    public:
        string AddIngredient() {
            return "Lots of Random Meat, " + T::AddIngredient();
        }
    };

    template<typename T>
    class Vegan : public T {
    public:
        string AddIngredient() {
            return "Vegan Cheese, Veggies, " + T::AddIngredient();
        }
    };
    //End of middle templates called
    //We inherit from Pizza as well as the initial next template
    template<typename T>
    class MeatNYStyle : public T, public Pizza {
    public:
        void MakePizza() { cout << "Meat NY Style Pizza : " << T::AddIngredient(); }
    };

    template <typename T>
    class VeganDeepDish : public T, public Pizza {
    public:
        void MakePizza() { cout << "Vegan Deep Dish : " << T::AddIngredient(); }
    };

    void TEST()
    {
        //unique_ptr is a smart pointer that disposes of a pointer when it is no longer in use
        vector<unique_ptr<Pizza>> pizzaOrders;

        //Generate Pizza types and place then at the end of the vector
        pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>());
        pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());

        //Call the pizzas and execute the directions for making them
        for (auto& pizza : pizzaOrders) {
            pizza->MakePizza();
        }
    }
}


int main()
{
    
    cout << "Circle Area : " << AREA_CIRCLE(5) << endl;

    //--------FUNCTIONS AS OBJECTS-------
    ex_fun_object::TEST();
    //--------END OF FUNCTIONS AS OBJECTS-------

    //--------TEMPLATE FUNCTIONS-------
    ex_template_function::TEST();
    //--------END TEMPLATE FUNCTIONS-------

    //--------TEMPLATE CLASS-------
    ex_template_class::TEST();
    //--------END OF TEMPLATE CLASS-------

    //-------DOUBLE ENDED QUEUE------
    ex_container::TEST();
    //-------END OF DOUBLE ENDED QUEUE------

    //------ITERATORS--------  
    ex_iterator::TEST();
    //------END OF ITERATORS--------

    //------MALLOC--------  
    ex_malloc::TEST();
    //------END OF MALLOC--------

    //------Smart Pointer--------  
    ex_smartpointer::TEST();
    //------END OF Smart Pointer--------

    //------Pizza Example--------  
    ex_smartpointer::TEST();
    //------END OF Pizza Example--------

    return 0;
}
