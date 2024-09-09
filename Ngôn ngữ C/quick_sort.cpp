// Thuật toán sắp xếp quick sort 
#include <stdio.h>
// Hàm phân hoạch Lomuto: trả về chỉ số của khóa (pivot)
int parition(int a[], int l, int r)
{
    int i = l - 1;
    int pivot = a[r];
    for (int j = l; j < r; j++) {
        // nếu a[j] > pivot : bỏ qua
        if (a[j] <= pivot) {
            // đưa a[j] lên đầu
            ++i;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    // đưa pivot vào giữa
    ++i;
    int tmp = a[i]; 
    a[i] = a[r];
    a[r] = tmp;
    printf("Phan hoach tu chi so: %d toi %d\n", l , r);
    for (int i = l; i <= r; i++) {
        printf("%d ", a[i]);
    } 
    printf("\n");   
     return i;
}

int quicksort(int a[], int l, int r) 
{
    if (l < r) {
        int pos = parition(a, l, r);
        // xét đệ quy về dãy bên trái
        quicksort(a, l, pos - 1);
        // xét đệ quy về dãy bên phải
        quicksort(a, pos + 1, r);
    }
}
int main() 
{
    int n;
    printf("Nhap so luong phan tu co trong mang: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    printf("Mang sau khi sap xep la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}