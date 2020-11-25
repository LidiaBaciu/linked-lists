#include <stdio.h>
#include <stdlib.h>

struct g_node{
       int info;
       struct g_node *next;
};

void push_element_begining(struct g_node *head ,int new_element_value){
       struct g_node *new_element = malloc(sizeof(struct g_node));

       new_element->info = new_element_value;
       new_element->next = head->next;
       head->next = new_element;
}

void push_n_elements_begining(struct g_node *head, int n){

        struct g_node *iterator = head;

        int value;
        int index;

        for( index = 1; index <= n; index++){
                struct g_node *new_element = malloc(n*sizeof(struct g_node));
                printf("What is the value of the %d element?", index);
                scanf("%d", &value);

                new_element->info = value;
                new_element->next = iterator->next;
                iterator->next = new_element;
                iterator = iterator->next;
                new_element->next = NULL;

        }

}

void push_element_end(struct g_node *head ,int new_element_value){
       struct g_node *new_element = malloc(sizeof(struct g_node));
       struct g_node *iterator = head;
       struct g_node *last_element;

       while (iterator->next != NULL) {
               iterator = iterator->next;
       }
       last_element = iterator;

       last_element->next = new_element;
       new_element->info = new_element_value;
       new_element->next = NULL;
}

void print_list(struct g_node *head){
       struct g_node *iterator = head;

       printf("\n List: ");
       while (iterator->next != NULL) {
               printf("%d ", iterator->next->info);
               iterator = iterator->next;
       }
}


int find_postion_of_value(struct g_node *head ,int new_element_value){
       int position = -1;
        struct g_node *iterator = head;
        while ( iterator-> next != NULL && iterator->info != new_element_value){
                position++;
                iterator = iterator->next;
        }

       return position;
}


void push_element(struct g_node *head ,int new_element_value, int position){
        struct g_node *iterator = head;
        struct g_node *newnode = malloc(sizeof(struct g_node));
        int index = 0;

        while( iterator->next != NULL && index < position){
                index++;
                iterator = iterator->next;
        }

        newnode->next = iterator->next;
        newnode->info = new_element_value;
        iterator->next = newnode;

}



void pop_element(struct g_node *head , int position){

        struct g_node *iterator = head;
        int index = 0;

        while( iterator->next != NULL && index <= position){
                index++;
                iterator = iterator->next;
        }

        printf("\nPop %d ", iterator->info);
        iterator->info = iterator->next->info;
        iterator->next = iterator->next->next;

}



int pop_element_begining(struct g_node *head){
       struct g_node *poped_element = malloc(sizeof(struct g_node));

       poped_element->info = head->next->info;

       int popped_info;
       popped_info = poped_element->info;

       head->next = head->next->next;
       head->info = head->next->info;

       return popped_info;

}



int pop_element_end(struct g_node *head){
       struct g_node *poped_element = malloc(sizeof(struct g_node));
       struct g_node *iterator = head;

       while( iterator->next->next != NULL){
                iterator = iterator->next;
       }

       int popped;
       popped = iterator->next->info;
       iterator->next = NULL;

       return popped;

}

void pop_back(struct g_node *head, int n){
        struct g_node *iterator = head;
        int index;
        index = 1;

        while( index <= n ){
                iterator = head;
                while( iterator->next->next != NULL){
                        iterator = iterator->next;
                }
                iterator->next = NULL;
                index++;
        }

        //if(index <= n) printf("\n not enough elements \n");

}

void pop_begining(struct g_node *head, int n){
       struct g_node *iterator = malloc(n*sizeof(struct g_node));
        int index;
        index = 1;

        while( index <= n){

               head->next = head->next->next;
               head->info = head->next->info;
               index++;
        }

}
void push_back(struct g_node *head, int n){


       struct g_node *iterator = head;
       struct g_node *last_element;
        int index;
        index = 1;

       while (iterator->next != NULL) {
               iterator = iterator->next;
       }

        last_element = iterator;

       while(index <= n){

                struct g_node *new_element = malloc(n*sizeof(struct g_node));
               last_element->next = new_element;
               new_element->info = index;
               new_element->next = NULL;
               index++;
               last_element = last_element->next;

       }
}

void push_begining(struct g_node *head, int n){


        struct g_node *iterator = head;

        int index;
        index = 0;

        while ( index < n){
                struct g_node *new_element = malloc(n*sizeof(struct g_node));
                new_element->info = index;
                new_element->next = iterator->next;
                iterator->next = new_element;
                index++;
        }


}

int main(){
       struct g_node *head = malloc(sizeof(struct g_node));

       head->next = NULL;

       push_elements_begining(head, 6);

       print_list(head);

       free(head);

       return 0;

}
