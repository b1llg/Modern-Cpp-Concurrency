#include <iostream>
#include <thread>

void test()
{
    std::cout << "Hello from test\n";
}

void run()
{
    std::thread thread1(test);
    if (thread1.joinable())
    {
        std::cout << "thread1 is joinable\n";
        thread1.join();
    }
    else
    {
        std::cout << "thread1 is NOT joinable\n";
    }


    if (thread1.joinable())
    {
        std::cout << "thread1 is joinable\n";
    }
    else
    {
        std::cout << "thread1 is NOT joinable\n";
    }
}


int main()
{

    run();

    std::cout << "Hello from main\n";

    return 0;
}