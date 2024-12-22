#include <iostream>
#include <unordered_set>
using namespace std;

int getSquareOfSum(int n)
{
    int sum = 0;
    while (n != 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n = n / 10;
    }
    return sum;
}
bool happyNumber(int n)
{
    if (n <= 0)
        return false;
    unordered_set<int> set;
    n = getSquareOfSum(n);
    set.insert(n);
    while (n != 1)
    {
        n = getSquareOfSum(n);
        // find method on an unordered_set returns `end` iterator if the key is not found
        if (set.find(n) == set.end()) // key is not found
        {
            set.insert(n);
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter a number you want to check for happiness: ";
    cin >> n;
    if (happyNumber(n))
        cout << "The number is a happy number!" << endl;
    else
        cout << "The number is not a happy number" << endl;
    return 0;
}