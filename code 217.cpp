#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int i, j, k, n = 5, aux, d[17];
    double a, c[17];
    cout << endl << "Enter your estimated monthly electricity consumption (in kWh): ";
    cin >> a;
    if (a <= 100)
        c[4] = a * 0.68;
    if (a > 100 && a <= 255)
        c[4] = a * 0.8;
    if (a > 300)
        c[4] = a * 1.3;
    if (a > 255 && a <= 300)
        c[4] = 255 * 0.8 + 1.3 * (a - 255);
    c[1] = c[4];
    c[2] = c[4];
    c[3] = 10.8 + c[4];
    if (a <= 100)
        c[5] = c[4];
    if (a > 100)
        c[5] = a * 0.77;
    for (i = 1; i <= n; ++i)
        d[i] = i;
    for (i = 1; i < n; ++i)
    {
        for (j = i + 1; j <= n; ++j)
        {
            if (c[d[i]] > c[d[j]])
            {
                aux = d[i];
                d[i] = d[j];
                d[j] = aux;
            }
        }
    }
    cout << endl << "The monthly subscriptions with which you get the lowest invoice values are the following (in ascending order of monthly invoice values):" << endl << endl;
    for (i = 1; i <= n; ++i)
    {
        cout << i << ") ";
        if (d[i] == 1)
            cout << "Enel Simplu Online Rez";
        if (d[i] == 2)
            cout << "Enel Simplu Anual Rez";
        if (d[i] == 3)
            cout << "Enel Relaxat";
        if (d[i] == 4)
            cout << "RCS";
        if (d[i] == 5)
            cout << "Hidroelectrica";
        cout <<"; Monthly invoice amount = ";
        cout << fixed << setprecision(2) << c[d[i]];
        cout << " RON"<< endl;
    }
}
