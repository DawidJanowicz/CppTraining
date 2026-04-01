//Zainspirowane pokerem z wiedzmina 2

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Dice {
public:
    int val = 1;
    int rollC = 0;
    bool isSelected = false;
    bool canBeSelected = true;
    int order;

    int roll() {
        val = (rand() % 6) + 1;
        rollC++;
        if (rollC == 2) {
            canBeSelected = false;
        }
        return val;
    }

    int wys() {
        std::cout << std::boolalpha;
        std::cout << "Kosc nr: " << 1 + order << " Wartosc: " << val
            << " Wybrana?: " << isSelected << " Mozna wybrac?: "
            << canBeSelected << " RC: " << rollC << '\n';
        return 0;
    }
};

struct GameResult {
    bool straight;
    bool fiveOK;
    bool fourOK;
    bool house;
    bool threeOK;
    bool twoPair;
    bool pair;
    std::vector<std::vector<int> > groups;
    std::vector<int> values;
};

int main()
{
    srand(time(NULL));
    int arr[5];
    Dice dice[5];

    for (int i = 0; i < 5; i++) {
        dice[i].order = i;
    }

    std::cout << "Oto twoje kosci!\n";
    std::cout << "----------------------------------------------------------------------------------\n";
    for (int i = 0; i < 5; i++) {
        dice[i].roll();
        dice[i].wys();
        if (i == 4) {
            std::cout << "----------------------------------------------------------------------------------\n";
        }
    }

label1:
    std::cout << "1.Wybierz kosc do przerzucenia\n";
    std::cout << "2.Rzuc koscmi!\n";
    std::cout << "3.Wyswietl kosci\n";
    std::cout << "4.Skoncz runde\n";
    std::cout << "5.Wyjscie\n";
    std::cout << "----------------------------------------------------------------------------------\n";
    int menu, selection;
    std::cin >> menu;

    while (true) {
        switch (menu) {
        case 1:
            std::cout << "----------------------------------------------------------------------------------\n";
            std::cout << "Wybierz kosci ktore chcesz zaznaczyc (po kolei)\n";
            std::cout << "Wybranie zaznaczonej kosci odznaczy ja\n";
            std::cout << "Aby wyswietlic kosce wpisz 6.\n";
            std::cout << "Gdy skonczysz wpisz 7.\n";
            std::cout << "----------------------------------------------------------------------------------\n";
            for (int i = 0; i < 5; i++) {
                dice[i].wys();
                if (i == 4) {
                    std::cout << "----------------------------------------------------------------------------------\n";
                }
            }
            while (true) {
                std::cin >> selection;
                switch (selection) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    std::cout << "Wybrano kosc: " << selection << "\n";
                    if (dice[selection - 1].rollC < 2) {
                        if (dice[selection - 1].canBeSelected == true) {
                            dice[selection - 1].isSelected = true;
                            dice[selection - 1].canBeSelected = false;
                        }
                        else {
                            std::cout << "Ta kosc byla juz wybrana wiec zostanie odznaczona!\n";
                            dice[selection - 1].isSelected = false;
                            if (dice[selection - 1].rollC < 2) {
                                dice[selection - 1].canBeSelected = true;
                            }
                        }
                    }
                    else {
                        std::cout << "Mozna tylko raz przerzucic kosc!\n";
                    }
                    break;
                case 6:
                    for (int i = 0; i < 5; i++) {
                        dice[i].wys();
                        if (i == 4) {
                            std::cout << "----------------------------------------------------------------------------------\n";
                        }
                    }
                    break;
                case 7:
                    std::cout << "Zakonczono wybieranie\n";
                    goto label1;
                    break;
                default:
                    std::cout << "Podaj liczbe od 1 do 7\n";
                }
            }
            break;

        case 2:
            std::cout << "**********************************************************************************\n";
            std::cout << "*********************************Rzucamy!*****************************************\n";
            std::cout << "**********************************************************************************\n";
            for (int i = 0; i < 5; i++) {
                if (dice[i].isSelected == true) {
                    dice[i].roll();
                    dice[i].isSelected = false;
                    if (dice[i].rollC < 2) {
                        dice[i].canBeSelected = true;
                    }
                }
            }
            for (int i = 0; i < 5; i++) {
                arr[i] = dice[i].val;
            }
            for (int i = 0; i < 5; i++) {
                dice[i].wys();
                if (i == 4) {
                    std::cout << "----------------------------------------------------------------------------------\n";
                }
            }
            std::cout << "1.Wybierz kosc do przerzucenia\n";
            std::cout << "2.Rzuc koscmi!\n";
            std::cout << "3.Wyswietl kosci\n";
            std::cout << "4.Skoncz runde\n";
            std::cout << "5.Wyjscie\n";
            std::cout << "----------------------------------------------------------------------------------\n";
            std::cin >> menu;
            break;

        case 3:
            std::cout << "Oto twoje kosci!\n";
            std::cout << "----------------------------------------------------------------------------------\n";
            for (int i = 0; i < 5; i++) {
                dice[i].wys();
                if (i == 4) {
                    std::cout << "----------------------------------------------------------------------------------\n";
                }
            }
            std::cout << "1.Wybierz kosc do przerzucenia\n";
            std::cout << "2.Rzuc koscmi!\n";
            std::cout << "3.Wyswietl kosci\n";
            std::cout << "4.Skoncz runde\n";
            std::cout << "5.Wyjscie\n";
            std::cout << "----------------------------------------------------------------------------------\n";
            std::cin >> menu;
            break;

        case 4: {
            std::cout << "Twoje kosci to...\n";
            for (int i = 0; i < 5; i++) {
                arr[i] = dice[i].val;
            }
            std::sort(arr, arr + 5);
            for (int i = 0; i < 5; i++) {
                std::cout << arr[i];
            }
            std::cout << '\n';
            std::unordered_map<int, std::vector<int> > groups;
            for (int i = 0; i < 5; i++) {
                groups[arr[i]].push_back(arr[i]);
            }
            GameResult result;
            result.straight = false;
            result.fiveOK = false;
            result.fourOK = false;
            result.house = false;
            result.threeOK = false;
            result.twoPair = false;
            result.pair = false;


            std::unordered_map<int, std::vector<int> >::iterator it;
            for (it = groups.begin(); it != groups.end(); ++it) {
                if (it->second.size() > 1) {
                    result.groups.push_back(it->second);
                    result.values.push_back(it->first);
                }
            }
            for (int i = 0; i < result.groups.size(); i++) {
                int size = result.groups[i].size();
                if (size == 5) result.fiveOK = true;
                else if (size == 4) result.fourOK = true;
                else if (size == 3) result.threeOK = true;
                else if (size == 2) {
                    if (result.pair) result.twoPair = true;
                    else result.pair = true;
                }
            }
            if (result.threeOK && result.pair) {
                result.house = true;
            }
            if (arr[4] - arr[3] == 1 && arr[3] - arr[2] == 1 && arr[2] - arr[1] == 1 && arr[1] - arr[0] == 1) {
                result.straight = true;
            }
            if (result.fiveOK) std::cout << "Piatka!\n";
            else if (result.fourOK) std::cout << "Czworka!\n";
            else if (result.house) std::cout << "Full!\n";
            else if (result.straight) std::cout << "Strit!\n";
            else if (result.threeOK) std::cout << "Trójka!\n";
            else if (result.twoPair) std::cout << "Dwie pary!\n";
            else if (result.pair) std::cout << "Para!\n";
            else std::cout << "Wysoka karta: " << arr[4] << "\n";
            std::cout << "1.Wybierz kosc do przerzucenia\n";
            std::cout << "2.Rzuc koscmi!\n";
            std::cout << "3.Wyswietl kosci\n";
            std::cout << "4.Skoncz runde\n";
            std::cout << "5.Wyjscie\n";
            std::cout << "----------------------------------------------------------------------------------\n";
                std::cin >> menu;
            break;
        }

        case 5:
            std::cout << "narazie";
            return 1;

        default:
            std::cout << "Podaj liczbe od 1 do 5\n";
            std::cout << "----------------------------------------------------------------------------------\n";
            std::cout << "1.Wybierz kosc do przerzucenia\n";
            std::cout << "2.Rzuc koscmi!\n";
            std::cout << "3.Wyswietl kosci\n";
            std::cout << "4.Skoncz runde\n";
            std::cout << "5.Wyjscie\n";
            std::cout << "----------------------------------------------------------------------------------\n";
            std::cin >> menu;
            break;
        }
    }
    return 0;
}