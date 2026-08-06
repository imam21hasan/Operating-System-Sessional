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

void fcfs(int n, int at[], int bt[])
{
    int ct[MAX], tat[MAX], wt[MAX], rt[MAX], pid[MAX];

    for (int i = 0; i < n; i++)
        pid[i] = i + 1;

    // Sort by Arrival Time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                swap(at[j], at[j + 1]);
                swap(bt[j], bt[j + 1]);
                swap(pid[j], pid[j + 1]);
            }
        }
    }

    int time = 0;
    int timeline[MAX], t_index = 0;

    cout << "\nGantt Chart:\n|";

    for (int i = 0; i < n; i++)
    {
        if (time < at[i])
        {
            cout << " Idle |";
            time = at[i];
            timeline[t_index++] = time;
        }

        cout << " P" << pid[i] << " |";

        rt[i] = time - at[i];
        time += bt[i];
        ct[i] = time;

        timeline[t_index++] = time;
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

    cout << "Enter number of processes: ";
    cin >> n;

    int at[MAX], bt[MAX];

    cout << "Enter Arrival Time: ";
    for (int i = 0; i < n; i++)
        cin >> at[i];

    cout << "Enter Burst Time: ";
    for (int i = 0; i < n; i++)
        cin >> bt[i];

    fcfs(n, at, bt);

    return 0;
}
