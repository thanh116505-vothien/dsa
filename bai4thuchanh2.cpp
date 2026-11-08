#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai bao cau truc sinh vien
typedef struct {
    char ten[50];
    int ma;
    float d1, d2, d3;
} SV;

// Khai bao node danh sach lien ket don
typedef struct Node {
    SV data;
    struct Node *next;
} Node;

// Ham tao node moi
Node* createNode(SV sv) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        return NULL;
    }
    newNode->data = sv;
    newNode->next = NULL;
    return newNode;
}

// Them sinh vien vao cuoi danh sach
void append(Node **head, SV sv) {
    Node *newNode = createNode(sv);
    if (newNode == NULL) return;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}

// In danh sach sinh vien
void printList(Node *head) {
    printf("\n%-20s %-10s %-8s %-8s %-8s\n", "Ho ten", "Ma SV", "Diem 1", "Diem 2", "Diem 3");
    Node *p = head;
    while (p != NULL) {
        printf("%-20s %-10d %-8.2f %-8.2f %-8.2f\n", p->data.ten, p->data.ma, p->data.d1, p->data.d2, p->data.d3);
        p = p->next;
    }
}

// Giai phong bo nho
void freeList(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node *head = NULL;
    int n;
    printf("So luong sv: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        SV sv;
        while (getchar() != '\n'); // xoa bo nho dem
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("Ho ten: ");
        fgets(sv.ten, sizeof(sv.ten), stdin);
        sv.ten[strcspn(sv.ten, "\n")] = '\0';
        printf("Ma SV: ");
        scanf("%d", &sv.ma);
        printf("Diem 1: ");
        scanf("%f", &sv.d1);
        printf("Diem 2: ");
        scanf("%f", &sv.d2);
        printf("Diem 3: ");
        scanf("%f", &sv.d3);

        append(&head, sv);
    }

    printList(head);
    freeList(head);

    return 0;
}
