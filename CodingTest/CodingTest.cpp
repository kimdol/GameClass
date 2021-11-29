#include <iostream>

using namespace std;

class AA
{
private:
    int a, b;

public:
    AA()
        : a{ 0 }, b{ 0 }
    {

    }
    ~AA()
    {

    }

    void Input()
    {
        cin >> a >> b;
        
    }

    void Output()
    {

        if (a > b)
        {
            cout << '>';
        }
        else if (a < b)
        {
            cout << '<';
        }
        else
        {
            cout << "==";
        }
    }
};

int main()
{
    AA a;
    a.Input();
    a.Output();

    return 0;
}