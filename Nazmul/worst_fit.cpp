#include <iostream>
using namespace std;

void worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[100];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int worstIdx = -1;

        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << endl;
    cout << "Worst Fit Allocation:" << endl;
    cout << "Process No.\tProcess Size\tBlock No." << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t\t" << processSize[i] << "\t\t";

        if (allocation[i] != -1)
            cout << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated" << endl;
    }
}

int main()
{
    int m, n;

    cout << "Enter number of memory blocks: ";
    cin >> m;

    int blockSize[100];

    cout << "Enter block sizes:" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> blockSize[i];
    }

    cout << "Enter number of processes: ";
    cin >> n;

    int processSize[100];

    cout << "Enter process sizes:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> processSize[i];
    }

    worstFit(blockSize, m, processSize, n);

    return 0;
}
