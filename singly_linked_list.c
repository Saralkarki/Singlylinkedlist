#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}node;
int count = 0;

node *create_head();
node *insert(node *head);
void display(node *head);
bool search(int n, node *head);
void destroy(node *head);
void destroy_indi(node *head, int n);

int main(void){
    node *head=NULL;
    head = create_head(head);
    // display(head);
    printf("\n");
    head = insert(head);
    display(head);
     printf("Count: %i\n", count);
    // printf("The count is: %i \n",count);
     printf("\n");
    search(6, head);
    destroy_indi(head, 2);
    display(head);
    printf("\n");
    search(6, head);
    printf("Count: %i", count);
     printf("\n");
    destroy(head);
}

node *create_head(node *head){
    head = (node*)(malloc(sizeof(node)));
    printf("Insert a Number: ");
    scanf("%i", &(head->data));
    head->next = NULL;
    return head;
}

node *insert(node *head){
    node* temp = NULL;
//     node* p = NULL;
    int n;
    printf("Length of the linked list: ");
    scanf("%i", &n);
    for (int i = 0; i < n; i++){
        temp = (node*)(malloc(sizeof(node)));
        printf("Number: ");
        scanf("%i", &(temp->data));
//         p = head;
//         while( p-> next != NULL){
//             p = p->next;
//         }
        temp -> next = head;
        head = temp;
    }
    return head;

}

void display(node *head){
    node *p= NULL;
    p = head;
    count = 0;
    while(p != NULL){
        printf("%i ->",  p -> data);
        p = p -> next ;
        count++;
    }
}
bool search(int n, node *head){
    node *p = head;
    while (p != NULL){
        if ( p->data == n){
            printf("Found you\n");
            return true;
        }
        else{
            p = p->next;
        }
    }
    printf("Could not find you\n");
    return false;
}
void destroy(node *head){
        node *p = head;
        node *temp = NULL;
        while (p != NULL){
           temp = p-> next;
        //   printf("%i ", p->data);
           free(p);
           p = temp;
        }
        free(temp);
}
void destroy_indi(node *head, int n){
    node *p = head;
    node *temp = NULL;
    int count_del = 1;
    while (count_del != n){
        p = p-> next;
        count_del++;
    }
    temp = p;
    p = p->next;
    head -> next = p;
    free(temp);
}
