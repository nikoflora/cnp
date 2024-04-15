#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string generateCNP(int sex, int year, int month, int day, int region)
{
    string cnp = "";

    if (year >= 1900 && year <= 1999)
    {
        cnp += to_string(sex);
    }
    else if (year >= 2000 && year <= 2024)
    {
        cnp += to_string(sex + 4);
    }
    else if (year >= 1800 && year <= 1899)
    {
        cnp += to_string(sex + 2);
    }

    cnp += to_string(year).substr(2, 2);
    if (month < 10)
    {
        cnp += "0";
    }

    cnp += to_string(month);

    if (day < 10)
    {
        cnp += "0";
    }
    cnp += to_string(day);

    if (region < 10)
    {
        cnp += "0";
    }
    cnp += to_string(region);

    srand(time(0));
    int nnn = rand() % 250 + 1;
    if (nnn < 10)
    {
        cnp += "00";
    }
    else if (nnn < 100)
    {
        cnp += "0";
    }
    cnp += to_string(nnn);

    const string constant = "279146358279";
    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        sum += (cnp[i] - '0') * (constant[i] - '0');
    }
    int rest = sum % 11;
    if (rest < 10)
    {
        cnp += to_string(rest);
    }
    else
    {
        cnp += "1";
    }

    return cnp;
}

int main()
{
    int sex, year, month, day, region;
    char choice;
    cout << "Do you want a random CNP (Y/N)? ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        srand(time(0));
        sex = rand() % 2 + 1;
        year = rand() % 125 + 1900;
        month = rand() % 12 + 1;
        day = rand() % 28 + 1;
        region = rand() % 52 + 1;
    }
    else
    {
        cout << "Enter sex (1 for male, 2 for female): ";
        cin >> sex;
        cout << "Enter year of birth (YYYY): ";
        cin >> year;
        cout << "Enter month of birth (MM): ";
        cin >> month;
        cout << "Enter day of birth (DD): ";
        cin >> day;
        cout << "Enter region code: ";
        cin >> region;
    }
    string cnp = generateCNP(sex, year, month, day, region);
    cout << "Generated CNP: " << cnp << endl;

    return 0;
}
