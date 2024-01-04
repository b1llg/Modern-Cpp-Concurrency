#include <iostream>
#include <thread>
#include <chrono>

void sleep(int time)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

bool checkinput(int input)
{
    return input == 1 || input == 2 || input ==3 || input == 100 ? false : true;
}

void clean()
{
    std::cout << "cleaning...\n";
    sleep(2000);
    std::cout << "done cleaning!\n";
}

void fullSpeed()
{
    std::cout << "full speed...\n";
    sleep(2000);
    std::cout << "done full speed!\n";
}

void stop()
{
    std::cout << "stop...\n";
    sleep(2000);
    std::cout << "done stop!\n";
}

int main()
{

    int command{0};

    while (command != 100) // exit if command is 100
    {
        // Check that the command is either 1,2,3 or 100       
        do
        {
             std::cout << "Command: \n";
             std::cin >> command;
        } while (checkinput(command));

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
        else
        {
            std::cout << "Enter a valid command\n"; 
        }
    }

    return 0;
}