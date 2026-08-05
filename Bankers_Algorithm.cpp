#include <iostream>
using namespace std;

int n, m;
int alloc[10][10], maxR[10][10], need[10][10], avail[10];

bool isSafe()
{
    int work[10];
    bool finish[10] = {false};
    int safeSeq[10];
    int count = 0;

    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    while (count < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                bool ok = true;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                {
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += alloc[i][j];
                    }
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found)
            break;
    }

    if (count == n)
    {
        cout << "\nThe system is in a safe state.";
        cout << "\nSafe sequence : ";
        for (int i = 0; i < n; i++)
            cout << "P" << safeSeq[i] + 1 << (i < n - 1 ? " -> " : "\n");
        return true;
    }
    else
    {
        cout << "\nThe system is in an unsafe state.";
        return false;
    }
}

int main()
{
    cout << "Number of Processes : ";
    cin >> n;
    cout << "Number of Resources : ";
    cin >> m;

    cout << "\nAllocation Matrix :\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];
    }

    cout << "\nMax Matrix :\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        for (int j = 0; j < m; j++)
            cin >> maxR[i][j];
    }

    cout << "\nAvailable : ";
    for (int j = 0; j < m; j++)
        cin >> avail[j];

    cout << "\nNeed Matrix :\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << ": ";
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maxR[i][j] - alloc[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    isSafe();

    return 0;
}
