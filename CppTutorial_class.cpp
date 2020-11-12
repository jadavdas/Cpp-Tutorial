#include <iostream>
#include <cstdlib>
#include <string>

//Classes are expanded concept of data structures, they can contain data members and functions (methods)
//An object is an instantiation of a class. In terms of variables, a class would be the type (like int, float, string etc. ) and an object would be the variable (like a, b, str etc.)
//Protected fields & methods can only be accesses in this classes that inherit from this class
//Private is used when you want to block access to all code aside from code in this class
//Public is used when you want to provide access to anything with access to an object
using namespace std;

//Simple class (classification of Rectangle)
namespace ex1 {
    class Rectangle {
        //By default private
        //Data should be in private to avoid mishandling
        int width, height;
    public:
        //Declared within the class but definition is outside of the class
        void SetValues(int, int); //Mutator
        int GetWidth(); //Accessor
        int GetHeight() { return height; }
        //Declaration and definition are within the class for simple calculation
        int Area() { return width * height; }
    };
    //Scope operator (::) is used to define a member outside of the class
    //Mutator gives access to private member to set the values
    void Rectangle::SetValues(int x, int y) {
        //width = x; height = y;
        //OR (every member function (except static) receives a "this" pointer
        this->width = x; this->height = y;
    }
    //Accessor gives access to private member to get the values
    int Rectangle::GetWidth() { return width;}

    void TEST()
    {
        //Multiple objects can be created using single blueprint of the object class
        ex1::Rectangle r1, r2; // These are created in stack
        r1.SetValues(3, 4);
        r2.SetValues(5, 6);
        cout << "Area of r1 : " << r1.Area() << endl;
        cout << "Area of r2 : " << r2.Area() << endl;
        cout << "Width of r1 : " << r1.GetWidth() << endl;
        cout << "Pointer to an object in Stack" << endl;
        ex1::Rectangle* pr1; // This is created in stack
        pr1 = &r1;
        pr1->SetValues(3, 4);
        cout << "Area of r1 : " << pr1->Area() << endl;
        cout << "Pointer to an object in Heap" << endl;
        ex1::Rectangle* p;
        p = new ex1::Rectangle;
        ex1::Rectangle* q = new ex1::Rectangle; // P & q are created in Heap
        p->SetValues(3, 4);
        q->SetValues(5, 6);
        cout << "Area of r1 : " << p->Area() << endl;
        cout << "Area of r2 : " << q->Area() << endl;
        delete p, q; // clear the allocated space from Heap
    }
}

//Constructor and overloading constructors
namespace ex2 {
    class Rectangle {
        int width, height;
    public:
        //A constructor is automatically called whenever a new object of the class is created, allowing the class to initialize member variables or allocate storage
        //Declaration is same like a regular function, name matches the class name and without any return type; not even void
        //Like other function, constructor can also be overloaded with different paramters
        //Default constructor is provided by compilier when there is no constructor (see example later). It is overtaken by user defined constructor
        Rectangle(); //non-parameterized constructor
        Rectangle(int, int); //parameterized constructor
        Rectangle(Rectangle& red) { width = red.width; height = red.height; } //copy constructor
        int Area() { return width * height; }
    };
    //Non-parameterized constructor
    Rectangle::Rectangle() { width = 5; height = 5;}
    
    //Various ways of member initialization in constructors
    //Rectangle::Rectangle(int x, int y) { width = x; height = y;}
    //Rectangle::Rectangle(int x, int y) : width(x) { height = y; }
    Rectangle::Rectangle(int x, int y) : width(x), height(y) {} //empty body function

    void TEST()
    {
        ex2::Rectangle r3(3, 4);
        ex2::Rectangle r4; // not alloed r4()
        ex2::Rectangle cr3(r3); //copy constructor
        cout << "Area of r1 : " << r3.Area() << endl;
        cout << "Area of r2 : " << r4.Area() << endl;
        cout << "Area of r1 : " << cr3.Area() << endl;
    }

    void TEST2()
    {
        //Objects can be pointed to by pointers: once declared, a class becomes a valid type, so it can be used as the type pointed to by a pointer
        ex2::Rectangle obj(3, 4);
        ex2::Rectangle* p1, * p2, * p3;
        p1 = &obj;
        p2 = new ex2::Rectangle(5, 6);
        p3 = new ex2::Rectangle[2]{ {2, 5}, {3, 6} };
        cout << "obj's area: " << obj.Area() << "\n";
        cout << "p1's area: " << p1->Area() << "\n";
        cout << "p2's area: " << p2->Area() << endl;
        cout << "p3[0]'s area: " << p3[0].Area() << endl;
        cout << "p3[1]'s area: " << p3[1].Area() << endl;
    }
}

//Uniform initialization
namespace ex3 {
    class Circle {
        double radius;
    public:
        Circle(double r) { radius = r; }
        double Perimeter() { return 2 * 3.1415 * radius; }
        double Get() { return radius; }
    };

    void TEST()
    {
        ex3::Circle c1(10.0); // functional form
        ex3::Circle c2 = 20.0; // assignment initialization
        ex3::Circle c3{ 30.0 }; //uniform initialization
        ex3::Circle c4 = { 40.0 }; //POD (Plain Old Data) - like
        cout << "Perimeter way 1: " << c1.Perimeter() << endl;
        cout << "Perimeter way 2: " << c2.Perimeter() << endl;
        cout << "Perimeter way 3: " << c3.Perimeter() << endl;
        cout << "Perimeter way 4: " << c4.Perimeter() << endl;
    }
}

//class keyword can be replaced by struct and everything remains same and work correctly
//Only difference: struct: members have public access by default; class: members have private access by default 
namespace ex4 {
    struct Circle {
        double radius;
    public:
        Circle(double r) { radius = r; }
        double Perimeter() { return 2 * 3.1415 * radius; }
    };

    void TEST()
    {
        ex4::Circle c5(10.0);
        cout << "Perimenter : " << c5.Perimeter() << endl;
    }
}

//class keyword can be replaced by union and everything remains same and work correctly
//union only stores one data member at a time
//Only difference: union: members have public access by default; class: members have private access by default 
namespace ex5 {
    union Circle {
        double radius;
        //double height;
    public:
        Circle(double r) { radius = r; }
        double Perimeter() { return 2 * 3.1415 * radius; }
    };

    void TEST()
    {
        ex5::Circle c6(10.0);
        cout << "Perimenter : " << c6.Perimeter() << endl;
    }
}

//Operator overloading: operator(sign)
namespace ex6 {
    class Vector {
    public:
        int x, y;
        //Vector() {};
        Vector(int a, int b) : x(a), y(b) {}
        //Vector operator+(const Vector& );
        //Vector operator+(const Vector lhs, const Vector rhs); //+ operator
        friend Vector operator+(const Vector lhs, const Vector rhs); //+ operator
        bool isEqual(Vector& param);
        Vector& operator=(const Vector& param); // assignment operator
        //static member: remebers how many objects are created, used like a global variable
        static int n;
        Vector() { n++; };
    };
    //Operator can be overloaded three ways
    //1. as a member operator overlaod
    /*
    Vector Vector::operator+(const Vector& param) {
        Vector temp;
        temp.x = x + param.x;
        temp.y = y + param.y;
        return temp;
    }
    */
    /*
    //2. as a non-member operator overloads
    Vector operator+(const Vector& lhs, const Vector& rhs) {
        Vector temp;
        temp.x = lhs.x + rhs.x;
        temp.y = lhs.y + rhs.y;
        return temp;
    }
    */
    //3. as a non-member operator overloads using friend keyword
    Vector operator+(const Vector lhs, const Vector rhs) {
        Vector temp;
        temp.x = lhs.x + rhs.x;
        temp.y = lhs.y + rhs.y;
        return temp;
    }
    bool Vector::isEqual(Vector& param) {
        if (param.x == this->x && param.y == this->y) return true;
        else return false;
    }
    //Each object gets its own copy of the data member using "this" pointer
    //"this" pointer is passed a hidden argument to all non-static member function calls and is available as a local variable within the body of all non-static functions
    //"This" pointer is not available static member function
    Vector& Vector::operator= (const Vector& param) {
        x = param.x;
        y = param.y;
        return *this; 
    }
    int Vector::n = 0;

    void TEST()
    {
        ex6::Vector v1(3, 1);
        ex6::Vector v2(1, 2);
        ex6::Vector result;
        result = v1 + v2;
        //result = v1.operator+(v2);
        cout << result.x << "," << result.y << endl;
        ex6::Vector v3(1, 2);
        cout << "isEqual : " << v2.isEqual(v3) << endl;
        ex6::Vector v4 = v2;
        cout << v4.x << "," << v4.y << endl;
        cout << "Number of objects : " << ex6::Vector::n << endl;
    }
}

//"const" member function: when object of a class is qualified as a const
//Access of data memebers from outside is restricted
namespace ex7 {
    class MyClass {
    public:
        int x;
        MyClass(int val) : x(val) {}
        //int Get() { return x; } //const object can't access non-const member
        int Get() const { return x; } //const object access const member function
        const int& Get1() const { return x; } //const member function returning a const&
        int& Get1() { return x; } //member function returning a const&
    };
    void TEST()
    {
        //Member functions of a "const" object can only be called if they are themselves as "const" members
        //Get() is not specified as "const" cannot be called from foo.
        const MyClass foo(1);
        //foo.x = 2; //not valid : x cannot be modified
        cout << "My Class : " << foo.x << endl;
        cout << "acces const member Get() : " << foo.Get() << endl; //const object can access const member function
        cout << "Overloading members on constness" << endl;
        MyClass foo2(10);
        const MyClass foo3(20);
        foo2.Get1() = 15; //OK: Get1() return int&
        //foo3.Get1() = 25; // Not valid : Get1() returns const int&
        cout << "1st way: " << foo2.Get1() << endl;
        cout << "2nd way: " << foo3.Get1() << endl;
    }
}

//Class Templates: we can create class templates just like function templates
namespace ex8 {
    //define template class
    template<class T>
    class MyPair {
        T values[2];
    public:
        MyPair(T first, T second) {
            values[0] = first; values[1] = second;
        }
        T GetMax();
    };
    //all member function needs template class precedance except constructors that can be defined inline with class
    template <class T>
    T MyPair<T>::GetMax()
    {
        T result;
        result = values[0] > values[1] ? values[0] : values[1];
        return result;
    }

    void TEST()
    {
        ex8::MyPair<int>myObj(100, 75);
        cout << "Max : " << myObj.GetMax() << endl;
    }
    
}

//Special members
namespace ex9 {
    //Default constructor: if a class has no constructor, compilier assumes an implicit default constructor
    //as soon as a class has some constructor, then compilier no longer provides default constructor
    class Example1 {
    public:
        int total = 0 ;
        void Accumulate(int x) { total += x; }
    };

    void TEST()
    {
        ex9::Example1 ex;
        ex.Accumulate(2);
        cout << "Default constructor : " << ex.total << endl;
    }
}

//Friend functions and class
//Private and protected members of a class cannot be accessed from outside of the same calss
//However, these are possible using friend 
namespace ex10 {
    class Square; //This is necessary because Rectangle uses Square properties
    class Rectangle {
        int width, height;
    public:
        Rectangle() {}
        Rectangle(int x, int y) : width(x), height(y) {}
        int Area() { return width * height; }
        //Duplicate function is a friend of class Rectangle. Therefore, it can access private members
        //check in main function, it simply has access private and protected members without being a memeber
        friend Rectangle Duplicate(const Rectangle&);
        void Convert(Square a);
    };
    Rectangle Duplicate(const Rectangle& param)
    {
        Rectangle r;
        r.width = param.width * 2;
        r.height = param.height * 2;
        return r;
    }
    class Square {
        //Rectangle is a friend class by Square but Square is not by Rectangle
        //Member functions of Rectangle can access the protected and private members of Square but not other way around
        friend class Rectangle;
    private:
        int side;
    public:
        Square(int a) : side(a) {}
    };
    void Rectangle::Convert(Square a) {
        width = a.side;
        height = a.side;
    }
    void TEST()
    {
        Rectangle rec1, rec2(2, 3);
        rec1 = Duplicate(rec2); //possible using friend
        cout << "Area : " << rec1.Area() << endl;
        Square sqr(4);
        rec1.Convert(sqr);
        cout << "Convert : " << rec1.Area() << endl;
    }
}

//Inheritance 
//member of the derived class can access protected members, not private
//if they are public can be access from anywhere
namespace ex11 {
    //Single/Simple Inheritance
    class Rectangle {
    private:
        int width, height;
    public:
        Rectangle(int w = 0, int h = 0) { width = w; height = 0; }
        int GetWidth() { return width; }
        int GetHeight() { return height; }
        void SetWidth(int w) { width = w; }
        void SetHeight(int h) { height = h; }
        int Area() { return width * height; }
        int Perimeter() { return 2 * (width + height); }
    };

    class Cuboid : public Rectangle {
    private:
        int length;
    public:
        Cuboid(int w = 0, int h = 0, int l = 0) { length = l; SetWidth(w); SetHeight(h); }
        int GetLength() { return length; }
        void SetLength(int l) { length = l; }
        int Volume() { return GetWidth() * GetHeight() * GetLength(); }
    };

    class Employee {
    private:
        int eid;
        string name;
    public:
        Employee(int e, string n) { eid = e; name = n; }
        int GetEmployeeID() { return eid; }
        string GetName() { return name; }
    };

    class FullTimeEmployee : public Employee {
    private: 
        int salary;
    public:
        FullTimeEmployee(int e, string n, int sal) : Employee(e, n) // calling base constructor in this way
        {
            salary = sal;
        }
        int GetSalary() { return salary; }
    };

    class PartTimeEmployee : public Employee {
    private:
        int wage;
    public:
        PartTimeEmployee(int e, string n, int w) : Employee(e, n) { wage = w; }
        int GetWage() { return wage; }
    };

    void TEST()
    {
        Cuboid c(10, 5, 3);
        cout << "Get width : " << c.GetWidth() << endl;
        cout << "Volume : " << c.Volume() << endl;
        cout << "Area : " << c.Area() << endl;
    }
    void TEST2()
    {
        PartTimeEmployee p1(1, "John", 300);
        FullTimeEmployee p2(2, "Raj", 5000);
        cout << "Salary of " << p2.GetName() << "is " << p2.GetSalary() << endl;
        cout << "Wage of " << p1.GetName() << "is " << p1.GetWage() << endl;
    }
}

//Polymorphism
namespace ex12 {
    class Polygon {
    protected:
        int width, height;
    public:
        void SetValues(int a, int b) { width = a; height = b; }
        //virtual is defined to access area of rect and tri using polygon
        //virtual int Area() { return 0; }
        virtual int Area() = 0; // Abstract base class
        void PrintArea() { cout << this->Area() << "\n"; } //Pure virtual members can be called from the abstract base class
    };
    class Rectangle : public Polygon {
    public:
        int Area() { return width * height; }
    };
    class Triangle : public Polygon {
    public:
        int Area() { return width * height / 2; }
    };

    void TEST()
    {
        Rectangle rec3;
        Triangle tri;
        rec3.SetValues(4, 5);
        tri.SetValues(4, 5);
        cout << "Rectangle area : " << rec3.Area() << endl;
        cout << "Triangle area : " << tri.Area() << endl;
        cout << endl;
        cout << "Polymorphism" << endl;
        Polygon* poly1 = &rec3;
        Polygon* poly2 = &tri;
        poly1->SetValues(4, 5);
        poly2->SetValues(4, 5);
        //Polygon cannot access the area() of rectangle and tringle.
        //To do that virtual member comes in
        cout << "Rectangle area : " << rec3.Area() << endl;
        cout << "Triangle area : " << tri.Area() << endl;
        cout << endl;
        cout << "Virtual" << endl;
        //Polygon poly; // this works with virtual but not for pure virtual
        //Polygon* poly3 = &poly; // this works with virtual but not for pure virtual
        //poly3->SetValues(4, 5); // this works with virtual but not for pure virtual
        cout << "Rectangle area : " << poly1->Area() << endl;
        cout << "Triangle area : " << poly2->Area() << endl;
        //cout << "Polygon area : " << poly3->Area() << endl; // this works with virtual but not for pure virtual
        cout << endl;
        cout << "Pure Virtual" << endl;
        cout << "Rectangle area : " << endl;
        poly1->PrintArea();
        cout << "Triangle area : " << endl;
        poly2->PrintArea();
    }
}

//Dynamic Allocation
namespace ex13 {

    class Polygon {
    protected:
        int width, height;
    public:
        Polygon(int a, int b) : width(a), height(b) {}
        virtual int Area() = 0; // Abstract base class
        void PrintArea() { cout << this->Area() << "\n"; } //Pure virtual members can be called from the abstract base class
    };
    class Rectangle : public Polygon {
    public:
        Rectangle(int a, int b) : Polygon(a, b) {}
        int Area() { return width * height; }
    };
    class Triangle : public Polygon {
    public:
        Triangle(int a, int b) : Polygon(a, b) {}
        int Area() { return width * height / 2; }
    };
    void TEST()
    {
        Polygon* poly3 = new Rectangle(4, 5);
        Polygon* poly4 = new Triangle(4, 5);
        poly3->PrintArea();
        poly4->PrintArea();
        delete poly3;
        delete poly4;
    }
}

//Example of Complex Number
namespace cn {
    class Complex {
    private:
        int real, img;
    public:
        Complex(int r = 0, int i = 0) { real = r, img = i; }
        Complex Add(Complex x) {
            Complex temp;
            temp.real = real + x.real;
            temp.img = img + x.img;
            return temp;
        }
        void Display() {
            cout << real << " + " << img << "j";
        }
        friend Complex operator+(Complex c1, Complex c2);
        friend ostream& operator<<(ostream& os, Complex& c1);
    };
    Complex operator+(Complex c1, Complex c2)
    {
        Complex temp;
        temp.real = c1.real + c2.real;
        temp.img = c1.img + c2.img;
        return temp;
    }
    ostream& operator<<(ostream& os, Complex& c1)
    {
        os << c1.real << " + " << c1.img << "j";
        return os;
    }

    void TEST()
    {
        Complex c1(3, 7), c2(5, 4);
        Complex c3;
        c3 = c1.Add(c2);
        c3.Display();
        cout << endl;
        c3 = c2.Add(c1);
        c3.Display();
        cout << endl;
        c3 = c1 + c2;
        cout << c3 << endl;
    }
}

//Example of Rational Number
namespace rn {
    class Rational
    {
    private:
        int p, q;
    public:
        Rational() { p = 1; q = 1; }
        Rational(int p, int q) { this->p = p; this->q = q; }
        Rational(Rational& r) { this->p = r.p; this->q = r.q; }
        int GetP() { return p; }
        int GetQ() { return q; }
        void SetP(int p) { this->p = p; }
        void SetQ(int q) { this->q = q; }
        Rational operator+(Rational r)
        {
            Rational t;
            t.p = this->p * r.q + this->q * r.p;
            t.q = this->q * r.q;
            return t;
        }
        friend ostream& operator << (ostream& os, Rational& r);
    };
    ostream& operator<<(ostream& os, Rational& r) {
        os << r.p << "/" << r.q;
        return os;
    }
    void TEST()
    {
        Rational r1(3, 4), r2(2, 5), r3;
        r3 = r1 + r2;
        cout << "Sum of " << r1 << " and " << r2 << " is " << r3 << endl;
    }
}

//Example Shapes
namespace poly {
    class Shape {
    public:
        virtual float Area() = 0;
        virtual float Perimeter() = 0;
    };
    class Rectangle :public Shape {
    private:
        float width, height;
    public:
        Rectangle(int w = 0, int h = 0) :width(w), height(h) {}
        float Area() { return width * height; }
        float Perimeter() { return 2 * (width + height); }
    };
    class Circle :public Shape {
    private:
        float radius;
    public:
        Circle(float r) { radius = r; }
        float Area() { return 3.1415 * radius * radius; }
        float Perimeter() { return 2 * 3.1415 * radius; }
    };
    void TEST()
    {
        Shape* s = new Rectangle(10, 5);
        cout << "Area of rectangle : " << s->Area() << endl;
        cout << "Perimeter of rectangle: " << s->Perimeter() << endl;
        s = new Circle(10);
        cout << "Area of circle: " << s->Area() << endl;
        cout << "Perimeter of circle: " << s->Perimeter() << endl;

        delete s;
    }
}
int main(int argc, char** argv)
{
    
    cout << "Example 1: Simple Class" << endl;
    ex1::TEST();
    cout << endl;
 
    cout << "Example 2: Constructors" << endl;
    ex2::TEST();
    cout << endl;

    cout << "Example 2: Pointers to classes" << endl;
    ex2::TEST2();
    cout << endl;

    cout << "Example 3: Various Ways of Object Initiation" << endl;
    ex3::TEST();
    cout << endl;

    cout << "Example 4: Classes defined with struct" << endl;
    ex4::TEST();
    cout << endl;

    cout << "Example 5: Classes defined with union" << endl;
    ex5::TEST();
    cout << endl;

    cout << "Example 6: Operator overloading" << endl;
    ex6::TEST();
    cout << endl;

    cout << "Example 7: When an object is qualified as a const object" << endl;
    ex7::TEST();
    cout << endl;

    cout << "Example 8: Template class" << endl;
    ex8::TEST();
    cout << endl;

    cout << "Example 9: Default constructor" << endl;
    
    cout << endl;

    cout << "Example 10: Friend function and class" << endl;
    ex10::TEST();
    cout << endl;

    cout << "Example 11: Inheritance" << endl;
    ex11::TEST();
    cout << endl;
    ex11::TEST2();
    cout << endl;

    cout << "Example 12: Polymorphism" << endl;
    ex12::TEST();
    cout << endl;

    cout << "Example 13: Dynamic Allocation" << endl;
    ex13::TEST();
    cout << endl;

    cout << "Example : Complex Number" << endl;
    cn::TEST();
    cout << endl;

    cout << "Eaxmple: Sum of Two Rational Numbers" << endl;
    rn::TEST();
    cout << endl;

    cout << "Eaxmple: Polymorphism" << endl;
    poly::TEST();
    cout << endl;

    return 0;
}
