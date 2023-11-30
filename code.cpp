#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
#include <conio.h>
using namespace std;

bool isRational(double number) {
    // Convert the number to a string with high precision
    stringstream ss;
    ss << setprecision(20) << number;
    string numberStr = ss.str();

    // Check if the string contains a repeating or non-terminating part
    size_t pos = numberStr.find("("); // Look for a repeating part
    if (pos != string::npos) {
        return false; // It has a repeating part, so it's not rational
    }

    pos = numberStr.find("."); // Look for a non-terminating part
    if (pos == string::npos) {
        return true; // No decimal point, so it's rational
    }

    return false; // It has a decimal point, but no repeating part, so it's not rational
}

// Function to generate a random integer between min and max (inclusive)
int generateRandomInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}
int main()
{
    char choice;
    do {
        int a = 0, j = 2, enroll[51], count = 2;
        for (; a <= 51; ++a)  //printing enroolments
        {
            if (j != 60 && j != 70)
            {
                enroll[a] = j;
                if (a < 4)
                {
                    cout << "01-131232-00" << enroll[a] << "\t";
                    if (count >= 6)
                    {
                        cout << "\n";
                        count = 1;
                    }
                }
                else if (a > 3 && a < 49)
                {
                    cout << "01-131232-0" << enroll[a] << "\t";
                    if (count >= 6)
                    {
                        cout << "\n";
                        count = 1;
                    }
                }
                else
                {
                    cout << "01-131232-" << enroll[a] << "\t";
                    if (count >= 6)
                    {
                        cout << "\n";
                        count = 1;
                    }
                }
                count++;
            }
            j = j + 2;
        }
        srand(static_cast<unsigned>(time(0)));

        float groupSize;
        cout << "\n\nHow many students you want to be in a group: ";
        cin >> groupSize;

        if (groupSize <= 0)
        {
            cout << "Group size must be a positive integer." << endl;
            return 1;
        }
        float totalGroups;
        totalGroups = 50 / groupSize;

        if (isRational(totalGroups))
        {
            totalGroups;
        }
        else
        {
            totalGroups++;
        }


        // Create a vector of even numbers from 2 to 104
        vector<int> evenNumbers;
        for (int i = 2; i <= 104; i += 2)
        {
            if (i != 60 && i != 70)
            {
                evenNumbers.push_back(i);
            }
        }

        // Shuffle the vector to randomize the order
        random_shuffle(evenNumbers.begin(), evenNumbers.end());

        int currentIndex = 0;
        for (int group = 1; group <= totalGroups; ++group)
        {
            vector<int> groupData;

            for (int i = 0; i < groupSize; ++i)
            {
                if (currentIndex < evenNumbers.size())
                {
                    groupData.push_back(evenNumbers[currentIndex]);
                    currentIndex++;
                }
            }
            if (group <= 9)
            {
                cout << "Group " << group << "  - \t";
            }
            else
            {
                cout << "Group " << group << " - \t";
            }

            for (int i = 0; i < groupData.size(); ++i)
            {
                if (groupData[i] <= 8)
                {
                    cout << "01-131232-00" << groupData[i];
                }
                else if (groupData[i] >= 10 && groupData[i] < 100)
                {
                    cout << "01-131232-0" << groupData[i];
                }
                else
                {
                    cout << "01-131232-" << groupData[i];
                }

                if (i < groupData.size() - 1)
                {
                    cout << "\t";
                }
            }

            cout << endl;
        }
        cout << "\nPress any key to retry ('0' for to exit)";
        cin >> choice;
    } while (choice != '0');
    return 0;
}
