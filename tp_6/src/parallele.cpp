#include <cstdlib>
#include <thread>
#include <vector>
#include "nombre.hpp"
#include <mutex>
#include <condition_variable>

unsigned compteur = 0;

std::mutex mutex;
std::condition_variable condition;

template <typename Callable>
void for_sequentiel(int x, int y, Callable c)
{
    for (int i = x; i < y; i++)
    {
        c(i);
    }
}


template <int N,typename Callable>
void for_parallele(int debut, int fin, Callable c)
{
    std::thread t[N];
    int taille = fin-debut;
    for(int i=0; i<N; i++)
    {
        t[i] = std::thread(for_sequentiel<Callable>, i*taille/4, (i+1)*taille/4, c);
    }

    for(auto &thread : t)
        thread.join();
}

int main()
{
    const unsigned taille = 24;

    std::vector<Nombre> a(taille);
    std::vector<Nombre> b(taille);
    std::vector<Nombre> c(taille);

    auto mutexVersion = [&](unsigned i){
        mutex.lock();
        a[i] = ++compteur;
        mutex.unlock();
        };
    
    auto lockGardVersion = [&](unsigned i)
    {
        {std::lock_guard<std::mutex> verrou(mutex);
        a[i] = ++compteur;}

        condition.notify_all();
    };

    for_parallele<4>(0, taille, lockGardVersion);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "compteur = " << compteur << std::endl;

    for_sequentiel(0, taille, [&](unsigned i){ a[i] = c[i] = a[i] * b[i]; });

    std::cout << "c = " << c << std::endl;

    return EXIT_SUCCESS;
}
