#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person{
	char name[255];
	char month[255];
	int date, year, sort;
	Person *next, *prev;
}*head, *tail, *curr;

Person *createNode(char *name, int date, char *month, int year, int sort){
	Person *temp = (Person*)malloc(sizeof(Person));
	
	strcpy(temp->name, name);
	temp->date = date;
	strcpy(temp->month, month);
	temp->year = year;
	temp->sort = sort;
	
	temp->next = temp->prev = NULL;
	return temp;
}

void pushHead(char *name, int date, char *month, int year, int sort){
    Person *temp = createNode(name, date , month, year, sort);
    if(!head){
        head = tail = temp;
	}
	else{
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void pushTail(char *name, int date, char *month, int year, int sort){
    Person *temp = createNode(name, date , month, year, sort);
    if(!head){
        head = tail = temp;
    }
	else{
        tail->next = temp; 
        temp->prev = tail; 
        tail = temp;       
    }
}

void pushMid(char *name, int date, char *month, int year, int sort){
    if(!head){
        Person *temp = createNode(name, date , month, year, sort);
        head = tail = temp;
    }
	else if(sort < head->sort){ 
        pushHead(name, date , month, year, sort);
    }
	else if(sort > tail->sort){ 
        pushTail(name, date , month, year, sort);
    }
	else{
        Person *temp = createNode(name, date , month, year, sort);
        curr = head;
        while(curr->sort < sort){
            curr = curr->next;
        }
        temp->prev = curr->prev;
        temp->next = curr;

        curr->prev->next = temp;
        curr->prev = temp;
    }
}

void popHead(){
    if(head && head == tail){
        head = tail = NULL;
        free(head);
    }
	else{
        Person *newHead  = head->next;
        head->next = newHead->prev = NULL;
        free(head);
        head = newHead;
    }
}

void printAll(){
    if(!head){
        return;
    }
	else{
        curr = head;
        while(curr){                            
            printf("%d %s %d - %s\n", curr->date, curr->month, curr->year, curr->name); 
            curr = curr->next;
        }
        printf("\n");
    }
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		getchar();
		int date, year, mon;
		char month[255], name[255];
		scanf("%d %s %d - %[^\n]", &date, month, &year, name);
		
		if(strcmp(month, "january") == 0){
			mon = 1;
		}else if(strcmp(month, "february") == 0){
			mon = 2;
		}else if(strcmp(month, "march") == 0){
			mon = 3;
		}else if(strcmp(month, "april") == 0){
			mon = 4;
		}else if(strcmp(month, "may") == 0){
			mon = 5;
		}else if(strcmp(month, "june") == 0){
			mon = 6;
		}else if(strcmp(month, "july") == 0){
			mon = 7;
		}else if(strcmp(month, "august") == 0){
			mon = 8;
		}else if(strcmp(month, "september") == 0){
			mon = 9;
		}else if(strcmp(month, "october") == 0){
			mon = 10;
		}else if(strcmp(month, "november") == 0){
			mon = 11;
		}else if(strcmp(month, "december") == 0){
			mon = 12;
		}	
		int sort = year*12*30 + mon*30 + date;
		pushMid(name, date, month, year, sort);
	}
//	printf("\nSorted:\n");
//	printAll();
	
	if(m >= n){
		printf("All patients get the cure, %d cure left\n", m-n);
	}else{
		//printf("\nAnswer:\n");
		printf("Need %d more cure\n", n-m);
		while(m--){ // 4 3 2 1 0
			popHead();
		}
		printAll();
	}
	
	return 0;
}
