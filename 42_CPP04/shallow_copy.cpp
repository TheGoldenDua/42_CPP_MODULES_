
// #include <iostream>

// class MyClass
// {
//     private:
//         int n;
//     public:
//         MyClass(){}
//         MyClass(int j)
//         {
//            n = j;
//         }
//         MyClass(const MyClass& copy)
//         {
//             *this = copy;
//         }
//         ~MyClass(){};

//         void set_number(int set)
//         {
//             n = set;
//         }

//         int get_number(void)
//         {
//             return (n);
//         }
// };

// int main()
// {
//     MyClass nb(5);
//     std::cout << "my number is:" << nb.get_number();

//     std::cout << std::endl;
//     MyClass nb2 = nb;
//     std::cout << "my nb2 is:" << nb2.get_number() << std::endl;;

// }

#include <iostream>
using namespace std;


class box
{
    private:
        int length;
        int height;
        int *p;

    public:
        void set_dimensions(int length1, int height1, int x)
        {
            length = length1;
            height = height1;
            p = new int;
            *p = x;
        }

        void show_data()
        {
            cout << " Length = " << length
                 << "\n Height = " << height
                << "\n P int pointing to = "<<p
                << endl;
        }
};

int main()
{
    
    box B1, B3;

   
    B1.set_dimensions(14, 12, 16);
    B1.show_data();

    // When copying the data of object
    // at the time of initialization
    // then copy is made through
    // COPY CONSTRUCTOR

    // When copying the data of object
    // after initialization then the
    // copy is done through DEFAULT
    // ASSIGNMENT OPERATOR
    B3 = B1;
    B3.show_data();

    return 0;
}