// Thuật toán sắp xếp Merge Sort
#include <stdio.h>
#include <math.h>
// merge
// Trộn các phần tử từ chỉ số left => chỉ số mid và các phần tử từ chỉ số mid + 1 đến chỉ số right
// thành các phần tử tăng dần
void merge(int a[], int l , int m, int r) 
{
    //tạm thời lưu các phần tử từ chỉ số l => chỉ số m vào 1 mảng
    // lưu các phần tử từ chỉ số m + 1 => r vào 1 mảng
    int n1 = m - l + 1, n2 = r - m;
    int x[n1], y[n2];
    // đưa các phần tử từ chỉ số l => m vào mảng x
    for (int i = 0; i < n1; i++) {
        x[i] = a[l + i];
    }
    // đưa các phần tử từ chỉ số m + 1 => r vào mảng y
    for (int i = 0; i < n2; i++) {
        y[i] = a[m + i + 1];
    }
    // trộn 2 mảng x, y => gán lại cho mang a[l. r]
    int index = l;
    int i = 0, j = 0;
    while(i < n1 && j < n2) {
        if (x[i] <= y[j]) {
            a[index++] = x[i++];
        } else {
            a[index++] = y[j++];
        }
        while (i < n1) {
            a[index++] = x[i++];
        }
        while (j < n2) {
            a[index++] = y[j++];
        }
    }
}

void merge_sort(int a[], int l, int r)
{
    if(l < r) {
        int m = (l + r) / 2;
        merge_sort(a, l, m); // gọi đệ quy nửa bên trái
        merge_sort(a, m + 1, r); //gọi đệ quy nửa bên phải
        merge(a, l, m , r);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}