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

void sjf(int n, int at[], int bt[])
{
    int ct[MAX], tat[MAX], wt[MAX], rt[MAX];
    int completed[MAX] = {0}, pid[MAX];

    for (int i = 0; i < n; i++)
        pid[i] = i + 1;

    int time = 0, done = 0;
    int timeline[MAX], t_index = 0;

    cout << "\nGantt Chart:\n|";

    while (done < n)
    {
        int idx = -1;
        int min_bt = 100000;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && !completed[i])
            {
                if (bt[i] < min_bt)
                {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            cout << " Idle |";
            time++;
            timeline[t_index++] = time;
            continue;
        }

        cout << " P" << pid[idx] << " |";

        rt[idx] = time - at[idx];
        time += bt[idx];
        ct[idx] = time;

        timeline[t_index++] = time;

        completed[idx] = 1;
        done++;
    }

    cout << "\n0";

    for (int i = 0; i < t_index; i++)
        cout << "    " << timeline[i];

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

    sjf(n, at, bt);

    return 0;
}
