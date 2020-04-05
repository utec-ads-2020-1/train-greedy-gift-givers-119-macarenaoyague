#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {

    int numberOfPeople;
    string string;
    std::string name;
    int moneySpent, numberTo;

    while (cin)
    {
        vector <pair <std::string, int>> pairs;

        getline(cin, string);
        numberOfPeople = stoi(string);
        getline(cin, string);
        stringstream s(string);

        for (int i = 0; i<numberOfPeople; i++)
        {
            getline(s, string, ' ');
            pair <std::string, char> pair;
            pair.first = string; pair.second = 0; pairs.push_back(pair);
        }


        for (int i = 0; i<numberOfPeople; i++)
        {
            int nameIndex;
            getline(cin, string);
            stringstream s(string);

            getline(s, name, ' ');
            getline(s, string, ' ');
            moneySpent = stoi(string);
            getline(s, string, ' ');
            numberTo = stoi(string);

            for (int k = 0; k<numberOfPeople; k++)
                if (pairs[k].first == name)
                {
                    nameIndex = k;
                    break;
                }

             if (numberTo != 0)
                 pairs[nameIndex].second -= (moneySpent/numberTo)*numberTo;
             else pairs[nameIndex].second -= moneySpent;

             for (int j = 0; j<numberTo; j++)
             {
                 getline(s, name, ' ');
                 for (int k = 0; k<numberOfPeople; k++)
                    if (pairs[k].first == name)
                    {
                        pairs[k].second += moneySpent/numberTo;
                        break;
                    }
             }
        }

        for (auto &element: pairs)
            cout<<element.first<<" "<<element.second<<endl;
        cout<<endl;
    }

    return 0;
}

