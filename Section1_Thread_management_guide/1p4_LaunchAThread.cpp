#include <iostream>
#include <thread>

void foo()
{
    std::cout << "Hello from foo - tid::" << std::this_thread::get_id() << std::endl;
}

class callable_class
{

public:

    void operator()()
    {
            std::cout << "Hello from class with function call operator - tid::" << std::this_thread::get_id() << std::endl;
    }
};

int main()
{

    std::thread thread1(foo);

    callable_class obj;
    std::thread thread2(obj);

    std::thread thread3([]
    {
            std::cout << "Hello from lambda- tid::" << std::this_thread::get_id() << std::endl;
    });

    thread1.join();
    thread2.join();
    thread3.join();

    std::cout << "Hello from main - tid::" << std::this_thread::get_id() << std::endl;
    return 0;
}