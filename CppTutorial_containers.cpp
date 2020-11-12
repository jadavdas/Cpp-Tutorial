
#include <iostream>
#include <cstdlib>
#include <deque>
#include <list>
#include <forward_list>
#include <iterator>
#include <vector>
#include <string>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

bool isEven(const int& val) {
    return (val % 2) == 0;
}

//---------DEQUES---------
//Contains data stored in order
//A deque (Deck) is a dynamic array like vectors except it also allows for insertion or deletion from the front
namespace ex_deque {
    
    void TEST()
    {
        deque<int>deq1;

        //Add to the end and front
        deq1.push_back(5);
        deq1.push_front(1);

        //Get the size
        cout << "Size : " << deq1.size() << endl;

        //Access by index
        cout << deq1[0] << endl;
        cout << deq1.at(1) << endl;
        cout << "\n";

        //Add values with assign
        deq1.assign({ 11, 12 });

        //Get the size
        cout << "Size : " << deq1.size() << endl;

        //Access by index
        cout << deq1[0] << endl;
        cout << deq1.at(1) << endl;
        cout << "\n";

        //Add at an index using an iterator
        deque<int>::iterator it = deq1.begin() + 1;
        deq1.insert(it, 3);

        for (int i : deq1)
            cout << i << endl;
        cout << "\n";

        //Add multiple values
        int tempArr[5] = { 6, 7, 8, 9, 10 };
        deq1.insert(deq1.end(), tempArr, tempArr + 5);
        for (int i : deq1)
            cout << i << endl;
        cout << "\n";

        //Erase at an index
        cout << "---Erase---" << endl;
        deq1.erase(deq1.begin() + 1);
        deq1.erase(deq1.end() - 1);
        for (int i : deq1)
            cout << i << endl;
        cout << "\n";

        //Erase 1st 2 elements
        deq1.erase(deq1.begin(), deq1.begin() + 2);
        for (int i : deq1)
            cout << i << endl;
        cout << "\n";

        cout << "Pop front and back" << endl;
        //Pop first value
        deq1.pop_front();
        //Pop last
        deq1.pop_back();
        for (int i : deq1)
            cout << i << endl;
        cout << "\n";

        cout << "----SWAP-----\n";
        //Create a deque with 2 50s
        deque<int> deq2(2, 50);

        //Swap values in deques
        deq1.swap(deq2);

        //Delete all values
        deq2.clear();

        //Cycle through the deque
        for (int i : deq1)
            cout << i << endl;
    }  
}

//--------LIST--------
//Lists are the most efficient at inserting, moving and extracting elements, but lack direct access to elements
namespace ex_list {

    void TEST()
    {
        //Add values
        int arr[5] = { 1, 2, 3, 4, 5 };
        list<int>list1;
        list1.insert(list1.begin(), arr, arr + 5);

        //Adding values with assign
        list1.assign({ 10, 20, 30 });

        //Add to end and front
        list1.push_back(5);
        list1.push_front(1);

        //Can't access index
        //cout << list1[0] << endl;

        //You can access the index with an iterator
        list<int>::iterator it2 = list1.begin();
        advance(it2, 1);
        cout << "2nd Index : " << *it2 << endl;

        //Insert at an index
        it2 = list1.begin();
        list1.insert(it2, 8);

        //Erase at an index
        list1.erase(list1.begin());

        //Erase 1st 2 elements
        it2 = list1.begin();
        list<int>::iterator it3 = list1.begin();
        advance(it3, 2);
        list1.erase(it2, it3);

        //Pop first value
        list1.pop_front();

        //Pop last
        list1.pop_back();

        //Get the size of the list
        cout << "Size : " << list1.size() << endl;

        //cycle through the list
        cout << "List 1 " << endl;
        for (auto i : list1)
            cout << i << endl;

        cout << "\n List 2\n";
        //Create another list
        int arr2[6] = { 10, 9, 8, 7, 6, 6 };
        list<int>list2;
        list2.insert(list2.begin(), arr2, arr2 + 6);

        //Sort the list
        list2.sort();

        //Reverse the list
        list2.reverse();

        //Remove duplicates
        list2.unique();

        //Remove a value
        list2.remove(6);

        //Remove if a condition is true
        //list2.remove_if(isEven);

        for (auto i : list2)
            cout << i << endl;

        //Merge lists
        //list1.merge(list2);
        cout << "Merge list" << endl;
        for (int i : list2)
            cout << i << endl;
    }
}

//------FORWARD LIST---------
//A forward list is like a list, but each list item only has a link to the next item in the list and not to the item that proceeds it
//This makes them the quickest of the sequence containers
namespace ex_forward_list {

    void TEST()
    {
        forward_list<int>fl1;

        //Assign values
        fl1.assign({ 1, 2, 3, 4 });

        //Push and pop front
        fl1.push_front(0);
        for (auto i : fl1)
            cout << i << endl;
        fl1.pop_front();

        //Get 1st
        cout << "Front : " << fl1.front() << endl;

        //Get iterator for 1st element
        forward_list<int>::iterator it4 = fl1.begin();

        //Insert after 1st element
        it4 = fl1.insert_after(it4, 5);

        //Delete just entered 5
        it4 = fl1.erase_after(fl1.begin());

        //Place in 1st position
        fl1.emplace_front(6);

        //remover a value
        fl1.remove(6);

        //Remove if a condition is true
        fl1.remove_if(isEven);

        cout << "\n List 1 " << endl;
        for (auto i : fl1)
            cout << i << endl;

        forward_list<int> fl2;
        fl2.assign({ 9, 8, 7, 6, 6 });

        //Remove duplicates
        fl2.unique();

        //Sort
        fl2.sort();

        //Reverse
        fl2.reverse();

        //Merge lists
        fl2.pop_front();
        fl2.pop_front();

        //fl1.merge(fl2);

        cout << "\n List 2 " << endl;
        for (auto i : fl2)
            cout << i << endl;
    }
}


//-----ASSOCIATIVE CONTAINERS----
//Associative containers store sorted data which makes insertion slower, but searching faster
//------SET------
//Sets store unique sorted values using a key
namespace ex_set {

    void TEST()
    {
        std::set<int>set1{ 5, 4, 3, 2, 1, 1 };
        std::cout << "Size : " << set1.size() << std::endl;

        //Insert value
        set1.insert(0);

        //Subscript operator doesn't work
        //std::cout << set1[0] << std::endl;

        //Get values with an iterator
        std::set<int>::iterator it = set1.begin();
        it++;

        std::cout << "2nd : " << *it << std::endl;

        //Erase value
        set1.erase(5);

        //Erase last 2 
        it = set1.end();
        advance(it, -2);
        set1.erase(it, set1.end());

        //Add multiple values
        int arr[] = { 6, 7, 8, 9 };
        set1.insert(arr, arr + 4);

        //Find value, get iterator and then vaue
        auto val = set1.find(6);
        std::cout << "Found : " << *val << std::endl;

        //Get iterator to value 
        auto eight = set1.lower_bound(8);
        std::cout << "8 : " << *eight << std::endl;

        //Get iterator to value after
        auto nine = set1.upper_bound(8);
        std::cout << "9 : " << *nine << std::endl;
        for (int i : set1)
            std::cout << i << std::endl;

        //Swap values in sets
        std::set<int> set2{ 10, 11 };
        set1.swap(set2);

        for (int i : set1)
            std::cout << i << std::endl;

        //Check if empty and if not print values
        if (!set1.empty()) {
            for (int i : set1)
                std::cout << i << std::endl;
        }
    }
}

//------MULTISET-----
//Stores duplicate values in sorted order, other than that it is the same as set
namespace ex_multiset {

    void TEST()
    {
        std::multiset<int>mset1{ 1,1,2,3,4 };

        //Insert value
        mset1.insert(4);
        mset1.insert(0);

        if (!mset1.empty()) {
            for (int i : mset1)
                std::cout << i << std::endl;
        }
    }
}

//------MAP-----
//Stores using key values pairs and you can't have duplicate keys
namespace ex_map {

    void TEST()
    {
        std::map<int, std::string> map1;

        //Insert key values
        map1.insert(std::pair<int, std::string>(1, "Bart"));
        map1.insert(std::pair<int, std::string>(2, "Lisa"));
        map1.insert(std::pair<int, std::string>(3, "Marge"));
        map1.insert(std::pair<int, std::string>(4, "Homer"));

        //Find element by key
        auto match = map1.find(1);
        std::cout << match->second << std::endl;

        //Get iterator to value
        auto bart = map1.lower_bound(1);
        std::cout << "LB : " << bart->second << std::endl;

        //Get next iterator
        auto lisa = map1.upper_bound(1);
        std::cout << "UB : " << lisa->second << std::endl;

        //Print elements with an iterator
        std::map<int, std::string>::iterator it2;
        for (it2 = map1.begin(); it2 != map1.end(); ++it2) {
            std::cout << "Key : " << it2->first << std::endl;
            std::cout << "Value : " << it2->second << std::endl;
        }
    }
}

//------MULTI-MAP-----
//Like map except you can have duplicate keys as long as the values are differnt
namespace ex_multi_map {

    void TEST()
    {
        std::multimap<int, std::string>mmap1;
        mmap1.insert(std::pair<int, std::string>(1, "Bart"));
        mmap1.insert(std::pair<int, std::string>(1, "Lisa"));
        mmap1.insert(std::pair<int, std::string>(3, "Marge"));
        std::map<int, std::string>::iterator it3;
        for (it3 = mmap1.begin(); it3 != mmap1.end(); ++it3)
        {
            std::cout << "Key : " << it3->first << std::endl;
            std::cout << "Value : " << it3->second << std::endl;
        }
    }
}

//-----CONTAINER ADAPTERS-----
//Adapt conatiners to provide a defined interface

//------STACK------
//Provides an interface for storing elements in a LIFO format
namespace ex_stack {
    void TEST()
    {
        std::stack<std::string> customers;
        customers.push("George");
        customers.push("Louise");
        customers.push("Florence");

        //Get number of elements
        int size = customers.size();
        //check if empty
        if (!customers.empty()) {
            for (int i = 0; i < size; i++) {
                //Get value with top
                std::cout << customers.top() << std::endl;

                //Delete last value entered
                customers.pop();
            }
        }
    }
}

//------QUEUE------
//Provides an interface for storing element in a FIFO format
namespace ex_queue {
    void TEST()
    {
        std::queue<std::string>cast;
        cast.push("Jadav");
        cast.push("Pintu");
        cast.push("Jhantu");
        int size2 = cast.size();

        if (!cast.empty()) {
            for (int i = 0; i < size2; i++) {
                //Get value with top
                std::cout << cast.front() << std::endl;

                //Delete last value entered
                cast.pop();
            }
        }
    }
}

//-----PRIORITY QUEUE------
//Elements are organized with the largest first
namespace ex_priority_queue {
    void TEST()
    {
        std::priority_queue<int>nums;
        nums.push(4);
        nums.push(8);
        nums.push(5);
        int size3 = nums.size();

        if (!nums.empty()) {
            for (int i = 0; i < size3; i++) {
                //Get value with top
                std::cout << nums.top() << std::endl;

                //Delete last value entered
                nums.pop();
            }
        }
    }
}

//-------ENUMS---------
//Custom data type that assigns names to constant integers so that a program is easier to read
//You can define the starting index, or any others
namespace ex_enum {
    void TEST()
    {
        enum day { Mon = 1, Tues, Wed, Thur, Fri = 5 };
        enum day tuesday = Tues;
        std::cout << "Tuesday is the " << tuesday << "nd day of the week\n";

        //Cycle through days
        for (int i = Mon; i <= Fri; i++)
            std::cout << i << std::endl;
    }
}
int main(int argc, char** argv)
{
    cout << "----Deque----" << endl;
    ex_deque::TEST();
    cout << endl;

    cout << "------List-----" << endl;
    ex_list::TEST();
    cout << endl;

    cout << "-----Forward List-----" << endl;
    ex_forward_list::TEST();
    cout << endl;

    cout << "----Set----" << endl;
    ex_set::TEST();
    cout << endl;

    cout << "----Multi-Set----" << endl;
    ex_multiset::TEST();
    cout << endl;

    cout << "----MAP----" << endl;
    ex_map::TEST();
    cout << endl;

    cout << "----Multi-MAP----" << endl;
    ex_multi_map::TEST();
    cout << endl;

    cout << "----Stack----" << endl;
    ex_stack::TEST();
    cout << endl;

    cout << "----Queue----" << endl;
    ex_queue::TEST();
    cout << endl;

    cout << "----Priority Queue----" << endl;
    ex_priority_queue::TEST();
    cout << endl;

    cout << "----Enum----" << endl;
    ex_enum::TEST();
    cout << endl;

    return 0;
}
