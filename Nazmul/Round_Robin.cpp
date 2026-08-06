#include <iostream>
using namespace std;

#define MAX 100

void printTable(int n, int pid[], int at[], int bt[],
                int ct[], int tat[], int wt[], int rt[])
{
    cout << "\n\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\t"
             << rt[i] << endl;
    }
}

void rr(int n, int at[], int bt[])
{
    int tq;

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int rem_bt[MAX], ct[MAX], tat[MAX], wt[MAX], rt[MAX];
    int visited[MAX] = {0}, pid[MAX];

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        rem_bt[i] = bt[i];
    }

    int time = 0, completed = 0;
    int timeline[MAX], t_index = 0;

    cout << "\nGantt Chart:\n|";

    while (completed < n)
    {
        int executed = 0;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && rem_bt[i] > 0)
            {
                if (!visited[i])
                {
                    rt[i] = time - at[i];
                    visited[i] = 1;
                }

                cout << " P" << pid[i] << " |";

                if (rem_bt[i] > tq)
                {
                    time += tq;
                    rem_bt[i] -= tq;
                }
                else
                {
                    time += rem_bt[i];
                    rem_bt[i] = 0;
                    ct[i] = time;
                    completed++;
                }

                timeline[t_index++] = time;
                executed = 1;
            }
        }

        if (!executed)
        {
            cout << " Idle |";
            time++;
            timeline[t_index++] = time;
        }
    }

    cout << "\n0";

    for (int i = 0; i < t_index; i++)
    {
        cout << "    " << timeline[i];
    }

    cout << endl;

    float avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printTable(n, pid, at, bt, ct, tat, wt, rt);

    cout << "\nAverage Waiting Time = "
         << avgWT / n << endl;

    cout << "Average Turnaround Time = "
         << avgTAT / n << endl;
}

int main()
{
    int n;

    cout << "Enter number of processes : ";
    cin >> n;

    int at[MAX], bt[MAX];

    cout << "Enter Arrival Time : ";
    for (int i = 0; i < n; i++)
        cin >> at[i];

    cout << "Enter Burst Time : ";
    for (int i = 0; i < n; i++)
        cin >> bt[i];

    rr(n, at, bt);

    return 0;
}
