// LÝ THUYẾT VỀ DANH SÁCH LIÊN KẾT
/*
- Khái niệm: Danh sách liên kết là một cấu trúc dữ liệu được sử dụng để lưu trữ các phần tử tương tự như mảng nhưng cónhiều điểm khác biệt.
- Tính chất: 
+ DSLK có thể mở rộng và thu hẹp một cách linh hoạt.
+ Phần tử cuối cùng trong DSLK trỏ vào NULL.
+ Không lãng phí bộ nhớ nhưng cần thêm bộ nhớ để lưu phần con trỏ.
+ Các phần tử trong DSLK được gọi là Node, được cấp phát động.
+ Đây là CTDL cấp phát động nên khi còn bộ nhớ thì sẽ còn thêm được phần tử vào DSLK.
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next; // link
};

typedef struct node node;
// duyệt danh sách liên kết và đếm số node trong danh sách liên kết đơn
void duyet(node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        // dich head sang phai
        head = head->next; // quan trong
    }
}

int size(node *head) {
    int count = 0;
    while(head != NULL) {
        ++count;
        head = head->next;
    }
    return count;
}

// ham tao 1 node moi them vao mot DSLK
node *makeNode (int x)
{
    // Cap phat dong 1 node
    node *newNote = (node*)malloc(sizeof(node));
    newNote->data = x;
    newNote->next = NULL;
    return newNote;
}

// Them node vao dau DSLK
void pushPront(node **head, int x){
    node *newNode = makeNode(x); // tao node moi
    newNode->next = (*head); // toan tu giai tham chieu
    (*head) = newNode;
}

// Them node vao cuoi DSLK
void pushBack(node **head, int x){
    node *newNode = makeNode(x);
    if (*head == NULL){
        *head = newNode; 
        return;
    }
    node *temp = *head; 
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// chen vao vi tri k trong DSLK
void insert(node **head,int k, int x)
{
      int n = size(*head);
      if (k < 1 || k > n + 1){
        printf("Vi tri chen khong hop le !\n");
        return;
      }
      if (k == 1) {
        pushPront(head, x);
      }
      else if (k == n + 1) {
        pushBack(head, x);
      }
      else {
        node *temp = *head;
        for (int i = 1; i < k - 1; i++){
            temp = temp->next;
        }
        node *newNode = makeNode(x);
        // Buoc 1: Phan next cua newNote luu dia chi cua note thu k
        newNode->next = temp->next;
        // Buoc 2: Phan next cua node thu k - 1 luu dia chi cua node moi
        temp->next = newNode;
      }
}
// xoa node o dau DSLK
void popFront(node **head)
{
    if (*head == NULL) return;
    node *temp = *head;
    *head = temp->next;
    free(temp);
}
// xoa node o cuoi DSLK
void popBack(node **head)
{
    if (*head == NULL) return;
    node *temp = *head;
    if (temp->next == NULL) {
        *head == NULL; 
        free(temp);
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Luu node cuoi cung
    node *last = temp->next;
    temp->next = NULL;
    free(last);
}
// xoa node o giua DSLK
void erase(node **head, int k)
{
    int n = size(*head);
    if (k < 1 || k > size(*head)) {
        printf("Vi tri khong hop le !\n");
        return;
    }
    if (k == 1) {
        popFront(head);
    }
    else if (k == n + 1) {
        popBack(head);
    } else {
        node *temp = (*head);
        for (int i = 1; i < k - 1; i++) {
            temp = temp->next;
            // temp : k - 1
        }
            node *del = temp->next; // node thu k
            temp->next = del->next;
            free(del);
    }
}

// sap xep cac node trong DSLK
void sort(node **head)
{
    for (node *i = (*head); i != NULL; i = i->next) {
        node *min = i;
        for (node *j = (i->next); j != NULL; j = j->next) {
            if (min->data > j->data) {
                min = j;
            }
        }
        // hoan vi
        int temp = min->data;
        min->data = i->data;
        i->data = temp;
    }
}
int main() 
{
    node *head = NULL;
    while(1){
        printf("--------------------------------------\n");
        printf("1. Them vao cuoi \n");
        printf("2. Them vao dau \n");
        printf("3. Chen vao giua \n");
        printf("4. Xoa dau \n");
        printf("5. Xoa cuoi \n");
        printf("6. Xoa giua \n");
        printf("7. Sap xep DSLK \n");
        printf("8. Duyet DSLK\n");
        printf("0. Thoat!\n");
        printf("---------------------------------------\n");
        printf("Nhap lua chon: ");
        int lc; scanf("%d", &lc);
        if (lc == 1) {
            printf("Nhap gia tri can them: ");
            int x; scanf("%d", &x);
            pushBack(&head, x);
        }
        else if (lc == 2) {
            printf("Nhap gia tri can them: ");
            int x; scanf("%d", &x);
            pushPront(&head, x);
        }   
        else if (lc == 3) {
            printf("Nhap gia tri can them: ");
            int x; scanf("%d", &x);
            printf("Nhap vi tri chen: ");
            int k; scanf("%d", &k);
            insert(&head, k, x);
        }
        else if (lc == 4) {
            popFront(&head);
        }
        else if (lc == 5) {
            popBack(&head);
        }
        else if (lc == 6) {
            printf("Nhap vi tri can xoa: ");
            int k; scanf("%d", &k);
            erase(&head, k);
        }
        else if (lc == 7) {
            sort(&head);
        }
        else if (lc == 8) {
            duyet(head);
        }
        else if (lc == 0) {
            break;
        }
    }   
     return 0;
}