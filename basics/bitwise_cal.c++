#include <iostream>
using namespace std;
int main()
{
    int a = 4;
    int b = 6;
    cout << "a&b  -->>" << (a & b)<<endl;  //AND
    cout << "a|b -->>" << (a | b)<<endl;    //OR
    cout << "~b -->>" << (~b)<<endl;    //NOT
    cout << "a^b -->>" << (a ^ b)<<endl <<endl;    //XOR

    cout<<(17<<1)<<endl;   //RIGHT SHIFT  ,ADD ZERO AT RIGHT SIDE OF BINARY IN +VE AND IN -VE COMPILER DEPENDENT
    cout<<(17<<2)<<endl;    //RIGHT SHIFT ,CAN ALSO BE FOUNT BY MULTIPLYING BY '2*N' WHERE N IS THE POSITION TO BE SHIFT
    cout<<(19>>1)<<endl;    //LEFT SHIFT  ,ADD ADD ZERO AT LEFT SIDE OF BINARY
    cout<<(19>>2)<<endl;    //LEFT SHIFT  ,CAN BE FOUND BY DIVIDING UNTIL REMAINDER , IN CASE OF BIG NUMBER IT MAKES +VE NO. TO -VE
    

}
