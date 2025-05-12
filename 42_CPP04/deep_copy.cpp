
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