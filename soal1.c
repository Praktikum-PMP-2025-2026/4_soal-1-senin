/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4
 *   Hari dan Tanggal    : Senin, 4 Mei 2026
 *   Nama (NIM)          : 13224024
 *   Nama File           : soal1.c
 *   Deskripsi           : program yang bisa sambung, pasang, dan mencari kargo
 * 
 */
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int num;
    struct node * next;
}node;

node * PushFront (node * head, int num){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->num = num;
    newNode->next = head;
    return newNode;
}

node * PushBack (node * head, int num){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->num = num;
    newNode->next = NULL;
// kemungkinan pertama kosong
    if (head == NULL) return newNode;

    node * temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

node * Del (node *head, int num){
    node * temp = head;
    node * prev = head;
    // head yang mau di del
    if (temp->num == num)
    {
        temp = temp->next;
        free(prev);
        return temp;
    }
    else{
        while (temp != NULL)
        {
        if (temp->num == num)
        {   
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        }
        return head;
    }
    
    
}

int Find (node *head, int num){
    node * temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->num == num) return index;
        index ++;
        temp = temp->next;
    }
    if (temp == NULL) return -1;    
}

void Display (node *head){
    node * temp = head;
    if (head == NULL) printf("LIST EMPTY\n");
    else{
        printf("LIST ");
        while (temp != NULL)
        {   
            printf("%d ", temp->num);
            temp = temp->next;
        }
    }
    
}

int main(){
    int Q; scanf("%d", &Q);
    int op; int x;
    node * head  = (node*)malloc(sizeof(node));
    head = NULL;

    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &op);

        if (op == 1)
        {
            scanf("%d", &x);
            head = PushFront(head, x);
        }
        
        else if (op == 2)
        {
            scanf("%d", &x);
            head = PushBack(head, x);
        }

        else if (op == 3)
        {
            scanf("%d", &x);
            head = Del(head, x);
        }

        else if (op == 4)
        {
            scanf("%d", &x);
            int index = Find(head, x);
            if (index == -1)
            {
                printf("NOT FOUND\n");
            }
            else{
                printf("FOUND %d\n", index);
            }
        }
    }
    Display(head);
    return 0;
}
