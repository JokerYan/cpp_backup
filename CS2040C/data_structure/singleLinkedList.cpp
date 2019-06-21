#include <stdio.h>

struct vertex{
    int value;
    struct vertex *next;
};

class SLL{
    private:
        struct vertex *head;
    public:
        SLL(){
            head = NULL;
        }

        void add(int v){
            if(head == NULL){
                struct vertex *next = new vertex{v, NULL};
                head = next;
            }else{
                struct vertex *current = head;
                while(current->next != NULL){
                    current = current->next;
                }
                struct vertex *next = new vertex{v, NULL}; 
                current->next = next;
            }
        }

        int get(int index){
            if(head == NULL) return -1;
            struct vertex *current = head;
            int indexLeft = index;
            while(indexLeft > 0 && current->next != NULL){
                current = current->next;
                indexLeft--;
            }
            if(indexLeft > 0) return -1;
            return current->value;
        }

        int search(int v){
            if(head == NULL) return -1;
            struct vertex *current = head;
            int index = 0;
            if(current->value == v) return index;
            while(current->next != NULL){
                current = current->next;
                index++;
                if(current->value == v) return index;
            }
            return -1;
        }

        bool insert(int v, int index){
            if(index == 0){
                struct vertex *next = new vertex{v, head};
                head = next;
                return true;
            }
            if(head == NULL) return false;
            struct vertex *current = head;
            int indexLeft = index - 1;
            while(indexLeft > 0 && current->next != NULL){
                current = current->next;
                indexLeft--;
            }
            if(indexLeft > 0) return false;
            struct vertex *next = new vertex{v, current->next};
            current->next = next;
            return true;
        }

        void printAll(){
            struct vertex *current = head;
            while(current != NULL){
                printf("%d ", current->value);
                current = current->next;
            }
            printf("\n");
        }
};

int main(){
    SLL sll = SLL();
    sll.add(1);
    sll.add(2);
    sll.add(3);
    sll.insert(5, 2);
    sll.printAll();

    return 0;
}