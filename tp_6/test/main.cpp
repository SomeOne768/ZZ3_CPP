#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex;
void zzz(unsigned n)
{
    mutex.lock();
    std::cout << "[" << n << "] zzz..."
              << "\n";

    mutex.unlock();
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
        t2[i] = std::thread([](unsigned n){
                                {std::lock_guard<std::mutex> verrou(mutex);
                                std::cout << "[" << n << "] zzz..." << "\n";}
                                std::this_thread::sleep_for(std::chrono::seconds(1)); },
                            i);
    for (int i = 0; i < 4; i++)
        t2[i].join();

    // Exemple 3
    std::thread t3[4];
    for (int i = 0; i < 4; i++)
        t3[i] = std::thread([=]()
                            {
                                {std::lock_guard<std::mutex> verrou(mutex);
                                std::cout << "[" << i << "] zzz..." << "\n";}
                                std::this_thread::sleep_for(std::chrono::seconds(1)); });
    for (int i = 0; i < 4; i++)
        t3[i].join();

    return 0;
}