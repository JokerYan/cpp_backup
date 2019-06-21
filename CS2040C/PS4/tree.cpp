#include <stdio.h>

class Node{
    public:
        Node* leftChild;
        Node* rightChild;
        int value, depth;
        Node(int v, int d){
            value = v;
            depth = d;
            leftChild = nullptr;
            rightChild = nullptr;
        }
};

int main(){
    int N;
    scanf("%d", &N);

    int C = 0;

    int rootValue;
    scanf("%d", &rootValue);
    Node* root = new Node(rootValue, 0);
    printf("%d\n", 0);


    for(int i = 1; i < N; i++){
        int value;
        scanf("%d", &value);
        while(true){
            // printf("this is node %d\n", thisNode->value);
            if(value > thisNode->value){
                if(thisNode->rightChild == nullptr){
                    Node* newNode = new Node(value, thisNode->depth + 1);
                    thisNode->rightChild = newNode;
                    C += newNode->depth;
                    // printf("value %d is under %d at depth of %d\n", value, thisNode->value, newNode->depth);
                    break;
                }else{
                    // printf("going down from %d to %d\n", thisNode->value, thisNode->rightChild->value);
                    thisNode = thisNode->rightChild;
                }
            }else{
                if(thisNode->leftChild == nullptr){
                    Node* newNode = new Node(value, thisNode->depth + 1);
                    thisNode->leftChild = newNode;
                    C += newNode->depth;
                    // printf("value %d is under %d at depth of %d\n", value, thisNode->value, newNode->depth);
                    break;
                }else{
                    // printf("going down from %d to %d\n", thisNode->value, thisNode->leftChild->value);
                    thisNode = thisNode->leftChild;
                }
            }
        }
        printf("%d\n", C);
    }

    return 0;
}