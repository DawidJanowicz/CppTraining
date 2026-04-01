#include <iostream>
int main()
{
	int a;
	double b, c;
	std::cout << "start\n";
	std::cout << "Wybierz dzialanie\n";
	std::cout << "1 - dodawanie\n";
	std::cout << "2 - odejmowanie\n";
	std::cout << "3 - mnozenie\n";
	std::cout << "4 - dzielenie\n";
	std::cout << "5 - wyjscie\n";
	std::cin >> a;
	do
	{
		std::cout << "start petli\n";
		switch (a) {
		case 1:
			std::cout << "dodawanie\n";
			std::cout << "Liczba 1: ";
			std::cin >> b;
			std::cout << "Liczba 2: ";
			std::cin >> c;
			std::cout << "Wynik to: " << b + c << std::endl;
			std::cout << "Wybierz dzialanie\n";
			std::cin >> a;
			break;
		case 2:
			std::cout << "odejmowanie\n";
			std::cout << "Liczba 1: ";
			std::cin >> b;
			std::cout << "Liczba 2: ";
			std::cin >> c;
			std::cout << "Wynik to: " << b - c << std::endl;
			std::cout << "Wybierz dzialanie\n";
			std::cin >> a;
			break;
		case 3:
			std::cout << "mnozenie\n";
			std::cout << "Liczba 1: ";
			std::cin >> b;
			std::cout << "Liczba 2: ";
			std::cin >> c;
			std::cout << "Wynik to: " << b * c << std::endl;
			std::cout << "Wybierz dzialanie\n";
			std::cin >> a;
			break;
		case 4:
			std::cout << "dzielenie\n";
			std::cout << "Liczba 1: ";
			std::cin >> b;
			std::cout << "Liczba 2: ";
			std::cin >> c;
			if (b == 0 || c == 0)
			{
				std::cout << "Nigdy cholero nie dziel przez 0!\n";
			}
			else {
				std::cout << "Wynik to: " << b / c << std::endl;
			}
			std::cout << "Wybierz dzialanie\n";
			std::cin >> a;
			break;
		case 5:
			std::cout << "wyjscie\n";
			return 1;
			break;
		default:
			std::cout << "wybierz nr od 1 do 5\n";
			std::cout << "Wybierz dzialanie\n";
			std::cin >> a;
		}
	} while (true);
	return 0;
}