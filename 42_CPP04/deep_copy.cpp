
#include <iostream>

// class MyClass
// {
//     private:
//         int *n;
//     public:
//         MyClass()
//         {
//             n = new int(0);
//         }
//         MyClass(int j)
//         {
//             n = new int(j);
//             *n = j;
//         }
//         MyClass(const MyClass& copy)
//         {
//             n = new int(*(copy.n));
//         }
//         ~MyClass()
//         {
//             delete n;
//         };

//         void set_number(int set)
//         {
//             *n = set;
//         }

//         int get_number(void)
//         {
//             return (*n);
//         }
// };

// int main()
// {
//     MyClass nb(5);
//     std::cout << "my number is:" << nb.get_number();

//     std::cout << std::endl;
//     MyClass nb2 = nb;
//     std::cout << "my nb2 is:" << nb2.get_number() << std::endl;

// }


#include <iostream>
using namespace std;

class box
{
    private:
        int length;
        int height;
        int *breadth;

    public:
        box()
        {
            breadth = new int;
        }
        
        void set_dimensions(int len, int heig, int brea)
        {
            length = len;
            height = heig;
            *breadth = brea;
        }

        void show_data()
        {
            cout << " Length = " << length
                 << "\n Height = " << height
                << "\n Breadth= "<< *breadth
                << endl;
        }

        box(const box& copy)
        {
            length = copy.length;
            height = copy.height;;
            breadth = new int;
            *breadth = *(copy.breadth);
        }

        ~box()
        {
            delete breadth;
        }
};


int main()
{
    box first;

    first.set_dimensions(12, 14, 16);
    first.show_data();

    cout << std::endl;

    // When the data will be copied then
    // all the resources will also get
    // allocated to the new object
    box second = first;
    second.show_data();

    return 0;
}