#include <iostream>
#include <thread>

void functionC()
{
    std::cout << "Hello from function C - tid::" << std::this_thread::get_id() << std::endl;
}

void functionA()
{
    std::cout << "Hello from function A - tid::" << std::this_thread::get_id() << std::endl;

    std::thread threadC(functionC);
    threadC.join();
}

void functionB()
{
    std::cout << "Hello from function B - tid::" << std::this_thread::get_id() << std::endl;
}



int main()
{   
    std::thread threadA(functionA);
    std::thread threadB(functionB);

    std::cout << "Hello from main - tid::" << std::this_thread::get_id() << std::endl; 

    threadA.join();
    threadB.join();


    return 0;
}
