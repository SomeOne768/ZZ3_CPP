#include <cstdlib>
#include <Point.hpp>
#include <Cartesien.hpp>
#include <Polaire.hpp>
#include <vector>

int main()
{
    std::vector<Point*> v;
    Cartesien c{1, 0};
    Polaire p{45, 3};

    v.push_back(&c);
    v.push_back(&p);

    for(auto p: v)
    {
        std::cout << *p << "\n";
    }

    return EXIT_SUCCESS;
}
