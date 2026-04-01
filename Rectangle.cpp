//BroCode Rectangle Pusty w srodku|Empty inside
int main()
{
	int a, b;
label1:
	std::cout << "Stworzmy prostokat podaj blok A: "; //szerokosc
	std::cin >> a;
	std::cout << "podaj blok B: "; //wysokosc | columns
	std::cin >> b;
	if (a <= 0 || b <= 0) {
		std::cout << "Dlugosc bloku musi byc wieksza niz 0\n";
		goto label1;
	}
	if (a == 1 && b == 1) {
		std::cout << "*";
		goto label2;
	}
	if (a == 1 && b > 1) {
		for (int i = 0; i < b; i++)
		{
			std::cout << "*\n";
		}
		goto label2;
	}
	if (b == 1) {
		for (int i = 0; i < a; i++)
		{
			std::cout << "*";
		}goto label2;
	}
	//gorny bok | top
	for (int i = 1; i <= a; i++)
	{
		std::cout << '*';
	}
	std::cout << std::endl;
	//srodek | middle
	for (int i = 0; i < (b - 2); ++i)
	{
		std::cout << "*";
		for (int j = 0; j < (a - 2); ++j)
		{
			std::cout << ' ';
		}
		std::cout << '*' << std::endl;
	}
	//dolny bok | bottom
	for (int i = 0; i < a; i++)
	{
		std::cout << '*';
	}
	std::cout << std::endl;
label2:
	return 0;
}
