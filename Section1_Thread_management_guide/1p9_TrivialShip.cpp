#include <iostream>
#include <thread>
#include <chrono>

void sleep(int time)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void clean()
{
    std::cout << "\t\tcleaning...\n";
    sleep(2000);
    std::cout << "\t\tdone cleaning!\n";
}

void fullSpeed()
{
    std::cout << "\t\tfull speed...\n";
    sleep(2000);
    std::cout << "\t\tdone full speed!\n";
}

void stop()
{
    std::cout << "\t\tstopping...\n";
    sleep(2000);
    std::cout << "\t\tdone stopping!\n";
}

int main()
{

    int command{0};

    while (command != 100) // exit if command is 100
    {
        // Check that the command is either 1,2,3 or 100       

        std::cout << "Command: \n";
        std::cin >> command;


        if (command == 1) // call functions
        {
            std::thread thread1(clean);
            thread1.detach();
        }
        else if (command == 2)
        {
            std::thread thread2(fullSpeed);
            thread2.join();
        }
        else if (command == 3)
        {
            std::thread thread3(stop);
            thread3.join();
        }
        else if (command == 100)
        {
            std::cout << "Exiting program!\n";
        }
        else
        {
            std::cout << "Enter a valid command\n"; 
        }
    }

    return 0;
}