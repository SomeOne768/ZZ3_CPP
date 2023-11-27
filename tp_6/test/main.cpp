#include <iostream>
#include <thread>

void zzz(unsigned n)
{
    std::cout << "[" << n << "] zzz..."
              << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{

    // Exemple 1
    std::thread t[4];

    for (int i = 0; i < 4; i++)
        t[i] = std::thread(zzz, i);

    for (int i = 0; i < 4; i++)
        t[i].join();

    // Exemple 2
    std::thread t2[4];
    for (int i = 0; i < 4; i++)
        t2[i] = std::thread([](unsigned n)
                            {
                                std::cout << "[" << n << "] zzz..." << "\n";
                                std::this_thread::sleep_for(std::chrono::seconds(1)); 
                            }, i);
    for (int i = 0; i < 4; i++)
        t2[i].join();

    // Exemple 3
    std::thread t3[4];
    for (int i = 0; i < 4; i++)
        t3[i] = std::thread([=]()
                            {
                                std::cout << "[" << i << "] zzz..." << "\n";
                                std::this_thread::sleep_for(std::chrono::seconds(1)); 
                            });
    for (int i = 0; i < 4; i++)
        t3[i].join();

    return 0;
}