#include <iostream>
#include <iomanip>
using namespace std;
void Create(int* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = -2 + rand() % 4;
    }
}
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}
void Mode(int* a, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (a[i] == 0 && i != size - 1)
        {
            for (int j = i; j < size; j++)
            {
                if (a[j] != 0)
                {
                    int tmp = a[j];
                    a[j] = a[i];
                    a[i] = tmp;
                }
            }
        }
    }
}
int Module(int* a, const int size)
{
    int max = abs(a[0]);
    for (int i = 1; i < size; i++)
        if (abs(a[i]) > max)
            max = abs(a[i]);
    return max;
}
int Sum(int* a, const int size)
{
    int sum = 0;
    int first = -1;
    int last = -1;
    for (int i = 0; i < size; i++)
    {
        if (a[i] >= 0 && first == -1)
        {
            first = i;
        }
        else
        {
            if (a[i] >= 0 && last == -1)
            {
                last = i;
            }
        }
    }
    for (int m = first + 1; m < last; m++)
    {
        sum += a[m];
    }
    return sum;
}

int main()
{
    srand(time(0));
    int n;
    cout << "  n = ";
    cin >> n;
    int* a = new int[n];
    Create(a, n);
    Print(a, n);
    cout << endl;
    Mode(a, n);
    Print(a, n);
    cout << endl;
    cout << "  Max module = " << Module(a, n) << endl;
    cout << "  Sum = " << Sum(a, n) << endl;
    delete[] a;
    return 0;
}