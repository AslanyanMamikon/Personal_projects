
#include <iostream> 
using namespace std;


union Data {
    char str[24];
    char* def_str = nullptr;
};
class mystring {
    Data str;
    size_t size = 0;
public:

    mystring() {
        str.def_str = nullptr;
    }

    mystring(const char* value) {
        size = strlen(value);
        
        if (size >= 24) {
            str.def_str = new char[size + 1];
            for (int i = 0; i < size; ++i) {
                str.def_str[i] = value[i];
            }
            str.def_str[size] = '\0';
        }
        else {
            for (int i = 0; i < size; ++i) {
                str.str[i] = value[i];
            }
            str.str[size] = '\0';
            
            str.def_str = nullptr;
        }
    }

    mystring(const mystring& other) {
        *this = other;
    }

    ~mystring() {
        if (size > 24 && str.def_str != nullptr)
        {
            delete[] str.def_str;
        }
    }

    mystring& operator=(const mystring& other) {
        if (this != &other) {
            if (str.def_str != nullptr) {
                delete[] str.def_str;
                str.def_str = nullptr;
            }
            
            size = other.size;

            if (size >= 24) {
                str.def_str = new char[size + 1];
                for (int i = 0; i < size; ++i) {
                    str.def_str[i] = other.str.def_str[i];
                }
                str.def_str[size] = '\0';
            }
            else {
                for (int i = 0; i < size; ++i) {
                    str.str[i] = other.str.str[i];
                }
                str.str[size] = '\0';
                str.def_str = nullptr;
            }        
        }

        return *this;
    }

    void operator=(const char* value) {
        if (str.def_str != nullptr)
        {
            delete[]str.def_str;
            str.def_str = nullptr;
        }
        size = strlen(value);

        if (size >= 24)
        {
            str.def_str = new char[size + 1];
            for (int i = 0; i < size; ++i) {
                str.def_str[i] = value[i];
            }
            str.def_str[size] = '\0';
        }
        else
        {
            for (int i = 0; i < size; ++i) {
                str.str[i] = value[i];
            }
            str.str[size] = '\0';
        }
    }

    friend ostream& operator<<(ostream& out, const mystring& value);
    friend istream& operator>>(istream& in, const mystring& value);
    
};

ostream& operator<<(ostream& out, const mystring& st)
{
    if (st.size >= 24 && st.str.def_str != nullptr)
    {
        out << st.str.def_str;
    }
    else
    {
        out << st.str.str;
    }
    return out;
}
istream& operator>>(istream& in, mystring& st)
{
    char buffer[200];
    in.getline(buffer, sizeof(buffer));
    st = buffer;

    return in;
}

int main() {

    mystring str1 = "hello";

    cout << str1 << endl;

    cout << "*********" << endl;

    mystring str2 = str1;
    cout << str2 << endl;

    cout << "*********" << endl;
    mystring str;
    cin >> str;
    cout << str << endl;
    return 0;
}
