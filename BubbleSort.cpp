#include <iostream>
using namespace std;
void BubbleSort()
{
    int a[] = {31, 42, 18, 60, 90}; // n=5
    int n = 5;
    int round;
    for (round = 0; round < n - 1; round++)
    {
        int flag = 0;
        for (int i = 0; i < n - round - 1; i++)
        {
            int c;
            if (a[i] > a[i + 1])
            {
                flag = 1;
                c = a[i];
                a[i] = a[i + 1];
                a[i + 1] = c;
            }
        }
        if (flag == 0)
            break;
    }
    for (int i = 0; i < n; i++)
        cout << " " << a[i];
    cout << endl;
    cout << round << endl;
}
int main()
{
    BubbleSort();
    return 0;
}