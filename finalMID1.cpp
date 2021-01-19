#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person{
    char name[255];
    int date, year;
    char month[20];
    Person *next, *prev;
}*head, *tail, *curr;

Person *createNode(char *name, int date, char *month, int year) {
    Person *temp = (Person*)malloc(sizeof(Person));
    strcpy(temp->name, name);
    temp->date = date;
    strcpy(temp->month, month);
    temp->year = year;
    temp->prev = temp->next = NULL;
    return temp;
}

void pushHead(char *name, int date, char *month, int year){
    Person *temp = createNode(name, date, month, year);
    if(!head){
        head = tail = temp;
    }else{
        head->prev = temp;
        temp->next = head;
        head = temp;
  }
}

void popHead() {
    if (!head){
        return;
    } else if(head == tail) {
        head->prev = NULL;
        head->next = NULL;
        free(head);
        head = NULL;
    }else {
        curr = head;
        head = head->next;
        free(curr);
        head->prev = NULL;
    }
}


void pushTail(char *name, int date, char *month, int year) {
    Person *temp = createNode(name, date, month, year);
    if(!head) {
        head = tail = temp;
    }else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void pushMid(char *name, int date, char *month, int year) {
    Person *temp = createNode(name, date, month, year);

    if(!head) {
        head = tail = temp;
    }else if(year < head->year) {
        pushHead(name, date, month, year);
    }else if(year > tail->year) {
        pushTail(name, date, month, year);
    }else{
        curr = head;
        while(curr){
        if(curr->year > temp->year){
            curr->prev->next = temp;
            temp->prev = curr->prev;
            temp->next = curr;
            curr->prev = temp;
            break;
        }
        curr = curr->next;
        }
    }
}

void printAll(){
  if(!head) {
    return;
  }
  curr = head;
  while(curr) {
    printf("%d %s %d - %s\n", curr->date, curr->month, curr->year, curr->name);
    curr = curr->next;
  }
}

void check(int n, int m) {
    curr = head;
    if(n-m == 0){
        printf("There is enough cure\n");
        return;
    }else if(m > n){
        printf("All patients get the cure, %d cure left\n", m-n);
        return;
    }else{
        printf("Need %d more cure\n", n-m);
        while(m){
            popHead();
            m--;
        }
        printAll();
    }
   
}

int main(){
    int n,m;
    char name[255], month[20];
    int date, year;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        getchar();
        scanf("%d %s %d - %[^\n]", &date, month, &year, name);
        pushMid(name, date, month, year);
    }
    check(n,m);

    return 0;
}
