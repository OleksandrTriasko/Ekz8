#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

double sumodd(const double* arr, const int n)
{
    double res = 0;
    for (int i = 0; i < n; i += 2)
        res += arr[i];
    return res;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введіть розмір масиву: ";
    int n;
    cin >> n;
    double* arr = new double[n];
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Сума елементів з непарними номерами: " << sumodd(arr, n) << endl;
    double sum1 = 0, sum2 = 0, sum3 = 0;
    bool b = true;
    for (int i = 0; i < n; i++)
    {
        sum3 += arr[i];
        if (b)
            sum1 += arr[i];
        if (arr[i] < 0)
        {
            b = false;
            sum2 = arr[i];
        }
        else
            sum2 += arr[i];
    }
    double res = sum3 - sum1 - sum2;
    cout << "Сума елементів масиву, розташованих між першим  і останнім від’ємними елементами: " << res << endl;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(arr[i]) > 1)
        {
            arr[j] = arr[i];
            j++;
        }
    }
    for (; j < n; j++)
        arr[j] = 0;
    cout << "Масив-результат: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
    cin.ignore();
}
