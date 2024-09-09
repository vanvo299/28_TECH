// Quay lui xâu nhị phân có độ dài k
#include <stdio.h>
int k, s[100];

void print()
{
    for (int i = 1; i <= k; i++) {
        printf("%d", s[i]);
    }
    printf("\n");
}
void Try(int i)
{
    // Duyet tat ca kha nang cua s[i]
    for (int j = 0; j <= 1; j++) {
        s[i] = j;
        if (i == k) print();
        else Try(i + 1);
        
    }
}
int main()
{
    printf("Nhap k: "); scanf("%d", &k);
    Try(1);
    return 0;
}