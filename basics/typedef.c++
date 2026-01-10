#include <iostream>

typedef std::string text_t; // here we are giving the data type string an alias of text_t for making it easier to read and type generally used for large complex data type and to better differentiate b/w typedef datatype e use "_t" at the end of the new name .
 
//now the typedef is repalced with 'using'
using num_t=int ;
//more stuitable for templates

int main()
{

    text_t name;
    num_t age=32;
    name = "aditya kumar";
    std::cout << name << "\n";
    std::cout<<age;
    return 0;
}