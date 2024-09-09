// DANH SÁCH LIÊN KẾT ĐÔI
#include <stdio.h>
#include <malloc.h>
// Cấu trúc danh sách liên kết đôi
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node node;
// ham tao node moi
node* makeNode(int x)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// duyet qua DSLK doi (tuong tu nhu duyet qua DSLK don)
void duyet(node* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
// dem so luong node trong DSLK doi (Tuong tu nhu dem trong DSLK don)
int size(node* head) {
    int count = 0;
    while (head != NULL) {
        ++count;
        head = head->next;
    }
    return count;
}
// them node moi vao dau cua DSLK doi
void pushFront(node** head, int x)
{
    node* newNode = makeNode(x);
    newNode->next = (*head);
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}

// them node moi vao cuoi cua DSLK doi
void pushBack(node** head, int x)
{
    node* newNode = makeNode(x);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// them node vao giua DSLK doi
void insert(node** head, int k, int x)
{
    int n = size(*head);
    if (k < 1 || k > n + 1) {
        printf("Vi tri khong hop le ! \n");
        return;
    }
    if (k == 1) {
        pushFront(head, x);
    }
    else if (k == n + 1)  pushBack(head, x);
    else {
        node* temp = *head;
        for (int i = 1; i < k - 1; i++) {
            temp = temp->next;
        }
        // temp: node thu k - 1
        node* newNode = makeNode(x);
        newNode->next = temp->next; // node thu k
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}
// xoa node o dau DSLK doi
void popFront(node **head)
{
    if (*head == NULL) return;
    node *temp = *head;
    *head = temp->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
        free(temp);
    }
}

// xoa node o cuoi DSLK doi
void popBack(node **head)
{
    if (*head == NULL) return;
    node *temp = *head;
    if (temp->next ==  NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    } 
    // node *last = temp->next; // node cuoi
    // temp->next = NULL;
    // last->prev = NULL;
    // free(last);
    temp->prev->next = NULL;
    free(temp);
}
void erase(node **head, int k)
{
    int n = size(*head);
    if (k < 1 || k > n) {
        printf("Vi tri khong hop le ! \n");
        return;
    }
    if (k == 1) popFront(head);
    else {
        node *temp = *head;
        for (int i = 1; i <= k - 1; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next; // k - 1 => k + 1: next
        temp->next->prev = temp->prev; // k + 1 => k - 1: prev
        free(temp);
    }
}

// duyet nguoc DSLK doi
void duyetnguoc(node *head)
{
    if (head == NULL) return;
    while (head->next != NULL) {
        head = head->next;
    }
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
}

// sap xep DSLK doi
void sort(node *head)
{
    for (node *i = head; i != NULL; i = i->next) {
        node *min = i;
        for (node *j = i->next; j != NULL; j = j->next) {
            if (min->data > j->data) {
                min = j;
            }
        }
        int temp = min->data;
        min->data = i->data;
        i->data = temp;
    }
}
int main()
{
    node* head = NULL;
    while (1) {
        printf("--------------------------------------\n");
        printf("1. Them vao cuoi \n");
        printf("2. Them vao dau \n");
        printf("3. Chen vao giua \n");
        printf("4. Xoa dau \n");
        printf("5. Xoa cuoi \n");
        printf("6. Xoa giua \n");
        printf("7. Sap xep DSLK \n");
        printf("8. Duyet DSLK\n");
        printf("9. Duyet nguoc DSLK \n");
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
            pushFront(&head, x);
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
        sort(head);
        }
        else if (lc == 8) {
            duyet(head);
        }
        else if (lc == 9) {
            duyetnguoc(head);
        }
        else if (lc == 0) {
            break;
        }
    }
    return 0;
}