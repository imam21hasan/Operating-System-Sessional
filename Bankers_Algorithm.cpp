#include <iostream>
using namespace std;

int p, r;
int alloc[10][10], maxR[10][10], need[10][10], avail[10];

bool isSafe()
{
    int work[10];
    bool finish[10];
    int safeSeq[10];
    int count = 0;

    for (int i = 0; i < p; i++)
    {
        finish[i] = false;
    }

    for (int i = 0; i < r; i++)
    {
        work[i] = avail[i];
    }

    while (count < p)
    {
        bool found = false;
        for (int i = 0; i < p; i++)
        {
            if (!finish[i])
            {
                bool ok = true;

                for (int j = 0; j < r; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for (int j = 0; j < r; j++)
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
        {
            cout << "\nThe system is not in a safe state!" << endl;
            return false;
        }
    }

    cout << "\nThe system is in a SAFE state.\nFollowing is the SAFE Sequence : ";
    for (int i = 0; i < p - 1; i++)
    {
        cout << " P" << safeSeq[i] << " ->";
    }
    cout << " P" << safeSeq[p - 1] << endl;

    return true;
}

int main()
{
    cout << "Enter the number of processes : ";
    cin >> p;

    cout << "\nEnter the number of Resouces : ";
    cin >> r;

    cout << "\nAllocation matrix :\n";
    for (int i = 0; i < p; i++)
    {
        cout << "p-" << i + 1 << " : ";
        for (int j = 0; j < r; j++)
        {
            cin >> alloc[i][j];
        }
    }

    cout << "\nMax matrix :\n";
    for (int i = 0; i < p; i++)
    {
        cout << "p-" << i + 1 << " : ";
        for (int j = 0; j < r; j++)
        {
            cin >> maxR[i][j];
        }
    }

    cout << "\nAvailable : ";
    for (int i = 0; i < r; i++)
    {
        cin >> avail[i];
    }

    cout << "\nNeed matrix :\n";
    for (int i = 0; i < p; i++)
    {
        cout << "p-" << i << " : ";
        for (int j = 0; j < r; j++)
        {
            need[i][j] = maxR[i][j] - alloc[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    isSafe();
    return 0;
}
