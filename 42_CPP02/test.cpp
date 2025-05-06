
#include <iostream>
#include <string>

using namespace std;

class store 
{
    private:
        string *str;
    public:
        store()
        {
            this->str = new string;
        }

        ~store()
        {
            delete str;
        }
        
        void get_str();
        string operator+(store &tmp);
};

void store::get_str()
{
    cout << "ENTER YOUR STRING : ";
    cin >> *str;
}

string store::operator+(store &tmp)
{
    return *str + *(tmp.str);
}

int main()
{   
    store s1;
    store s2;

    s1.get_str();
    s2.get_str();
    
    string res = s1+s2;
    cout << "concatenated string : " << res << endl;
    return 0;
}