#include <bits/stdc++.h>
using namespace std;

int n, m;

int allocation[50][50];
int maxMatrix[50][50];
int needMatrix[50][50];
int available[10];

bool isSafe()
{
    int work[10];
    bool finish[10] = {false};

    int safeSeq[10];
    int count = 0;

    for (int i = 0; i < m; i++)
        work[i] = available[i];

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
                    if (needMatrix[i][j] > work[j])
                    {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                {
                    for (int j = 0; j < m; j++)
                        work[j] += allocation[i][j];

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
        cout << endl;
        cout << "Safe State! Sequence: ";

        for (int i = 0; i < n; i++)
        {
            cout << "P" << safeSeq[i];
            if (i < n - 1)
                cout << " -> ";
        }

        cout << endl;
        return true;
    }
    else
    {
        cout << endl;
        cout << "Unsafe State! Deadlock risk." << endl;
        return false;
    }
}

int main()
{
    cout << "Enter Number of Processes: ";
    cin >> n;

    cout << "Enter Number of Resources: ";
    cin >> m;

    cout << endl;
    cout << "Allocation Matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++)
            cin >> allocation[i][j];
    }

    cout << endl;
    cout << "Max Matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++)
            cin >> maxMatrix[i][j];
    }

    cout << endl;
    cout << "Available: ";

    for (int j = 0; j < m; j++)
        cin >> available[j];

    cout << endl;
    cout << "Need Matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << ": ";

        for (int j = 0; j < m; j++)
        {
            needMatrix[i][j] = maxMatrix[i][j] - allocation[i][j];
            cout << needMatrix[i][j] << " ";
        }

        cout << endl;
    }

    isSafe();

    return 0;
}

