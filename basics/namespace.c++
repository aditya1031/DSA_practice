#include <iostream>

namespace first{
    int x=40;
}

namespace second{
    int x=4;
}
int main(){

    int x=90;
    std::cout<<first::x;
    return 0;
}