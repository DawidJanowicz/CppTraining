//From BroCode cpp tutorial
#include <iostream>
#include <cmath>
int main()
{
    double a, b;
    std::cout << "Podaj po kolei boki przyprostokatnych.\n";
    std::cout << "Bok A: ";
    std::cin >> a;
    std::cout << "Bok B: ";
    std::cin >> b;
    std::cout << "Naprzeciwprostokatna C wynosi: " << sqrt(pow(a, 2) + pow(b, 2));
}