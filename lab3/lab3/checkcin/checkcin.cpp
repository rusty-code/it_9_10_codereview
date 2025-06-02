
// #include "../checkcin/checkcin.h"
#include "checkcin.h"


template <typename _type>
_type checkcin(
        std::string interface_msg, // \n - custom
        std::string error_msg, // \n - custom
        const u_int16_t BFF_SIZE = 32767,
        const char END_BFF = '\n'
)
{
    using namespace std;

    _type user_input;

    bool success = false;
    while(!success)
    {
        cout << interface_msg;

        cin >> user_input;

        if(cin.fail()) // check buffer state
        {
            cin.clear();
            cout << error_msg;
        }
        else 
        {
            success = true;
        }
        cin.ignore(BFF_SIZE, END_BFF); // cancel of get next vars
    }

    return user_input;
}
