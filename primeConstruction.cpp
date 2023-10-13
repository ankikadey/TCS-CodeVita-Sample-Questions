#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool is_prime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return false;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void smallest_prime(vector<int> in_list)
{
    int res = -1;
    int q = *min_element(in_list.begin(), in_list.end());
    for (int p = q; p < 1000000; p++) //here the limit is 10^6 as 10^10 caused timed out issue
    {
        bool isvalid = true;
        for (auto num : in_list)
        {
            if (num != q && p % num != q)
            {
                isvalid = false;
                break;
            }
        }
        if (isvalid && is_prime(p))
        {
            cout << p << endl;
            return;
        }
    }
    
    cout << "None" << endl;

}

int main(int argc, char const *argv[])
{
    vector<int> in_list;
    int input;
    while (cin >> input)
    {
        in_list.push_back(input);
    }
    smallest_prime(in_list);
    return 0;
}