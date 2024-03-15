#include <stdio.h>

void swap(int*, int, int);
void print(int *, int);
void quickSort(int *arr, int L, int R)
{
    if (L >= R) return; 
    int left = L - 1, right = R;
    int mid = arr[R], i;
    for (i = L; i < right; i++)
    {
        if (arr[i] < mid) swap(arr, i, ++left);
        else if (arr[i] > mid) swap(arr, i--, --right);
    }
    swap(arr, R, right);
    quickSort(arr, L, left);
    quickSort(arr, right + 1, R);
}

void swap(int *arr, int a, int b)
{
    if (a == b) return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

void print(int *arr, int len)
{
    int i;
    for (i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[10], i;
    for (i = 0; i < 10; i++) scanf("%d", &arr[i]);
    quickSort(arr, 0, 9);
    print(arr, 10);

    return 0;
}