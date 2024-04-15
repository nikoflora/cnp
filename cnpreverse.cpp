#include <iostream>
#include <string>
#include <map>
using namespace std;
bool isValidCNP(const string &cnp)
{
    if (cnp.length() != 13)
        return false;

    const string constant = "279146358279";
    int sum = 0;

    for (int i = 0; i < 12; i++)
    {
        sum += (cnp[i] - '0') * (constant[i] - '0');
    }

    int remainder = sum % 11;
    int controlDigit = (remainder < 10) ? remainder : 1;

    return controlDigit == (cnp[12] - '0');
}

void displayCNPData(const string &cnp)
{
    if (!isValidCNP(cnp))
    {
        cout << "Invalid CNP." << '\n';
        return;
    }

    map<string, string> counties = {
        {"01", "Alba"}, {"02", "Arad"}, {"03", "Argeș"}, {"04", "Bacău"}, {"05", "Bihor"}, {"06", "Bistrița-Năsăud"}, {"07", "Botoșani"}, {"08", "Brașov"}, {"09", "Brăila"}, {"10", "Buzău"}, {"11", "Caraș-Severin"}, {"12", "Cluj"}, {"13", "Constanța"}, {"14", "Covasna"}, {"15", "Dâmbovița"}, {"16", "Dolj"}, {"17", "Galați"}, {"18", "Gorj"}, {"19", "Harghita"}, {"20", "Hunedoara"}, {"21", "Ialomița"}, {"22", "Iași"}, {"23", "Ilfov"}, {"24", "Maramureș"}, {"25", "Mehedinți"}, {"26", "Mureș"}, {"27", "Neamț"}, {"28", "Olt"}, {"29", "Prahova"}, {"30", "Satu Mare"}, {"31", "Sălaj"}, {"32", "Sibiu"}, {"33", "Suceava"}, {"34", "Teleorman"}, {"35", "Timiș"}, {"36", "Tulcea"}, {"37", "Vaslui"}, {"38", "Vâlcea"}, {"39", "Vrancea"}, {"40", "București"}, {"41", "București - Sector 1"}, {"42", "București - Sector 2"}, {"43", "București - Sector 3"}, {"44", "București - Sector 4"}, {"45", "București - Sector 5"}, {"46", "București - Sector 6"}, {"51", "Călărași"}, {"52", "Giurgiu"}, {"47", "Bucuresti - Sector 7 (desființat)"}, {"48", "Bucuresti - Sector 8 (desființat)"}};

    string genderAndCentury = cnp.substr(0, 1);
    string yearOfBirth = cnp.substr(1, 2);
    string monthOfBirth = cnp.substr(3, 2);
    string dayOfBirth = cnp.substr(5, 2);
    string countyCode = cnp.substr(7, 2);
    string uniqueIdentifier = cnp.substr(9, 3);

    string gender;
    string century;

    if (genderAndCentury == "1" || genderAndCentury == "3" || genderAndCentury == "5" || genderAndCentury == "7")
    {
        gender = "Male";
    }
    else
    {
        gender = "Female";
    }

    if (genderAndCentury == "1" || genderAndCentury == "2")
    {
        century = "19";
    }
    else if (genderAndCentury == "3" || genderAndCentury == "4")
    {
        century = "18";
    }
    else if (genderAndCentury == "5" || genderAndCentury == "6")
    {
        century = "20";
    }
    else
    {
        century = "Resident";
    }

    cout << "Gender: " << gender << '\n';
    cout << "Date of Birth: " << dayOfBirth << "/" << monthOfBirth << "/" << century << yearOfBirth << '\n';
    cout << "County of Birth: " << counties[countyCode] << '\n';
    cout << "Unique Identifier: " << uniqueIdentifier << '\n';
}

int main()
{
    string cnp;
    cout << "Enter CNP: ";
    cin >> cnp;

    displayCNPData(cnp);

    return 0;
}
