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

void priorityScheduling(int n, int at[], int bt[])
{
    int priority[MAX];

    cout << "Enter Priority : ";

    for (int i = 0; i < n; i++)
        cin >> priority[i];

    int pid[MAX], rt[MAX], wt[MAX], tat[MAX], ct[MAX];
    int rem_bt[MAX], visited[MAX] = {0};

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        rem_bt[i] = bt[i];
    }

    int completed = 0, time = 0;

    int g_pid[MAX], timeline[MAX];
    int g_index = 0, t_index = 0;

    int prev = -1;

    while (completed < n)
    {
        int idx = -1;
        int best_priority = 100000;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && rem_bt[i] > 0)
            {
                if (priority[i] < best_priority)
                {
                    best_priority = priority[i];
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            if (prev != 0)
            {
                g_pid[g_index++] = 0;
                timeline[t_index++] = time;
            }

            prev = 0;
            time++;
            continue;
        }

        if (!visited[idx])
        {
            rt[idx] = time - at[idx];
            visited[idx] = 1;
        }

        if (prev != pid[idx])
        {
            g_pid[g_index++] = pid[idx];
            timeline[t_index++] = time;
        }

        prev = pid[idx];

        rem_bt[idx]--;
        time++;

        if (rem_bt[idx] == 0)
        {
            ct[idx] = time;
            completed++;
        }
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

    priorityScheduling(n, at, bt);

    return 0;
}
