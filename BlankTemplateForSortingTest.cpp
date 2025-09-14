#include <bits/stdc++.h>
using namespace std;
int ar[100004];
int arrayCopy[100004];
void WriteFile()
{
    freopen("Input.txt", "w", stdout);

    int N = 100000;
    cout << N << endl;
    for (int i = 0; i < N; i++)
    {
        int x = rand();
        cout << x << " ";
    }
    cout << endl;
}

float BubbleSort(int ar[], int N)
{
    clock_t start = clock();

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
    clock_t total = clock() - start;
    cerr << "Total Time Taken in Bubble Sort is " << float(total) / 1000.0 << endl;

    for (int i = 0; i < N; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
};

int br[100000];

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (i <= j)
    {
        while (i <= right && arr[i] <= pivot)
        {
            i++;
        }
        while (j > left && arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[left], arr[j]);
    return j;
};

void quickSortHelper(int arr[], int left, int right)
{
    if (left < right)
    {
        int p = partition(arr, left, right);
        quickSortHelper(arr, left, p - 1);
        quickSortHelper(arr, p + 1, right);
    }
}

float QuickSort(int arr[], int N)
{
    float time = 0;
    clock_t start = clock();

    /// Coding Start
    quickSortHelper(arr, 0, N - 1);
    /// Finish your code within start to end

    // sort(ar, ar + N);
    /// Coding End

    clock_t total = clock() - start;
    //     time = start - ed;
    cerr << setprecision(10) << fixed;
    cerr << "Total Time Taken in Quick Sort is " << float(total) / 1000.0 << endl;
    for (int i = 0; i < N; i++)
        cout << ar[i] << " ";
    cout << endl;
}

int KthElementUsingQuickSort(int arr[], int N)
{
    if (N <= 0)
        return -1;

    int pivot = arr[0];
    int i = 0;

    for (int j = 1; j < N; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[0], arr[i]);

    return i;
}

float MergeSort(int ar[], int N)
{
    float time = 0;
    clock_t start = clock();

    /// Coding Start

    /// Coding End

    clock_t total = clock() - start;
    //     time = start - ed;
    cerr << setprecision(10) << fixed;
    cerr << "Total Time Taken in Merge Sort is " << float(total) / 1000.0 << endl;
    for (int i = 0; i < N; i++)
        cout << ar[i] << " ";
    cout << endl;
}

float HeapSort(int ar[], int N)
{
    float time = 0;
    clock_t start = clock();

    /// Coding Start
    for (int start = N / 2 - 1; start >= 0; --start)
    {
        int root = start;
        while (true)
        {
            int left = 2 * root + 1;
            int right = 2 * root + 2;
            int largest = root;

            if (left < N && ar[left] > ar[largest])
            {
                largest = left;
            }
            if (right < N && ar[right] > ar[largest])
            {
                largest = right;
            }

            if (largest == root)
            {
                break;
            }

            int tmp = ar[root];
            ar[root] = ar[largest];
            ar[largest] = tmp;
            root = largest;
        }
    }

    for (int end = N - 1; end > 0; --end)
    {
        int tmp = ar[0];
        ar[0] = ar[end];
        ar[end] = tmp;

        int root = 0;
        while (true)
        {
            int left = 2 * root + 1;
            int right = 2 * root + 2;
            int largest = root;

            if(left < end && ar[left] > ar[largest]) {
                largest = left;
            }
            if(right < end && ar[right] > ar[largest]) {
                largest = right;
            }

            if(largest == root) {
                break;
            }

            int tmp2 = ar[root];
            ar[root] = ar[largest];
            ar[largest] = tmp2;
            root = largest;
        }
    }
    /// Coding End

    clock_t total = clock() - start;
    //     time = start - ed;
    cerr << setprecision(10) << fixed;
    cerr << "Total Time Taken in Heap Sort is " << float(total) / 1000.0 << endl;
    for (int i = 0; i < N; i++)
        cout << ar[i] << " ";
    cout << endl;
}

int main()
{
    WriteFile();

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &ar[i]);
    }

    // BubbleSort(ar, N);
    // QuickSort(ar, N);
    // int pos = KthElementUsingQuickSort(ar, N);
    // cerr << "Pivot final position: " << pos << endl;
    //    MergeSort(ar,N );
       HeapSort(ar,N );
    //    InsertionSort(ar,N );

    ///....

    return 0;
}
