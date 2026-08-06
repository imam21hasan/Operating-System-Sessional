#include <iostream>
using namespace std;

#define MAX 100

void printTable(int n, int pid[], int at[], int bt[],
                int ct[], int tat[], int wt[], int rt[])
{
    cout << "\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\tRT\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\t"
             << rt[i] << endl;
    }
}

void priorityNonPreemptive(int n, int at[], int bt[])
{
    int priority[MAX];

    cout << "Enter Priority: ";
    for (int i = 0; i < n; i++)
        cin >> priority[i];

    int pid[MAX], ct[MAX], tat[MAX], wt[MAX], rt[MAX];
    int completed[MAX] = {0};

    for (int i = 0; i < n; i++)
        pid[i] = i + 1;

    int done = 0, time = 0;

    int g_pid[MAX], timeline[MAX];
    int g_index = 0, t_index = 0;

    while (done < n)
    {
        int idx = -1;
        int bestPriority = 100000;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && !completed[i])
            {
                if (priority[i] < bestPriority)
                {
                    bestPriority = priority[i];
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            g_pid[g_index++] = 0;
            timeline[t_index++] = time;
            time++;
            continue;
        }

        g_pid[g_index++] = pid[idx];
        timeline[t_index++] = time;

        rt[idx] = time - at[idx];

        time += bt[idx];

        ct[idx] = time;
        completed[idx] = 1;
        done++;
    }

    timeline[t_index++] = time;

    cout << "\nGantt Chart:\n|";

    for (int i = 0; i < g_index; i++)
    {
        if (g_pid[i] == 0)
            cout << " Idle |";
        else
            cout << " P" << g_pid[i] << " |";
    }

    cout << "\n0";

    for (int i = 1; i < t_index; i++)
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

    cout << "\nAverage Waiting Time = " << avgWT / n << endl;
    cout << "Average Turnaround Time = " << avgTAT / n << endl;
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

    priorityNonPreemptive(n, at, bt);

    return 0;
}
