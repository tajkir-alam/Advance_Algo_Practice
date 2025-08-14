#include<bits/stdc++.h>
using namespace std;
int ar[100004];
int arrayCopy[100004];
void WriteFile()
{
    freopen("Input.txt","w",stdout);

    int N =100000;
    cout<<N<<endl;
    for(int i=0;i<N;i++)
    {
        int x = rand();
        cout<<x<<" ";
    }
    cout<<endl;

}

int br[100000];
float QuickSort(int ar[],int N)
{
    float time = 0;
    clock_t start= clock();

    /// Coding Start
/// Finish your code within start to end

        sort(ar,ar+N);
    /// Coding End


    clock_t total=  clock() - start;
//     time = start - ed;
     cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in Quick Sort is "<< float(total)/1000.0<<endl;
    for(int i=0;i<N;i++)cout<<ar[i]<<" ";
    cout<<endl;
}

float MergeSort(int ar[],int N)
{
    float time = 0;
    clock_t start= clock();

    /// Coding Start

    /// Coding End


    clock_t total=  clock() - start;
//     time = start - ed;
     cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in Merge Sort is "<< float(total)/1000.0<<endl;
    for(int i=0;i<N;i++)cout<<ar[i]<<" ";
    cout<<endl;
}

float HeapSort(int ar[],int N)
{
    float time = 0;
    clock_t start= clock();

    /// Coding Start

    /// Coding End


    clock_t total=  clock() - start;
//     time = start - ed;
     cerr<<setprecision(10)<<fixed;
    cerr<<"Total Time Taken in Heap Sort is "<< float(total)/1000.0<<endl;
    for(int i=0;i<N;i++)cout<<ar[i]<<" ";
    cout<<endl;
}

int main()
{
    //WriteFile();

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&ar[i]);
    }

    QuickSort(ar,N ); ///
//    MergeSort(ar,N );
//    HeapSort(ar,N );
//    InsertionSort(ar,N );

    ///....


    return 0;
}
