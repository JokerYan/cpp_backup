#include <stdio.h>
#include <map>

using namespace std;

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

    long long C = 0;
    map<int, Node*> bbst;

    int rootValue;
    scanf("%d", &rootValue);
    Node* root = new Node(rootValue, 0);
    bbst[rootValue] = root;
    printf("%d\n", 0);


    for(int i = 1; i < N; i++){
        int value;
        scanf("%d", &value);

        Node* newNode = new Node(value, -1);
        bbst[value] = newNode;

        auto lower = bbst.lower_bound(value);
        auto upper = bbst.upper_bound(value);

        if(upper == bbst.end()){
            (--lower)->second->rightChild = newNode;
            newNode->depth = lower->second->depth + 1;
            // printf("upper not exist. node %d go under node %d\n", newNode->value, lower->second->value);
        }else if(lower == bbst.begin()){
            upper->second->leftChild = newNode;
            newNode->depth = upper->second->depth + 1;
            // printf("lower not exist. node %d go under node %d\n", newNode->value, upper->second->value);
        }else{
            --lower;
            if(lower->second->depth > upper->second->depth){
                lower->second->rightChild = newNode;
                newNode->depth = lower->second->depth + 1;
                // printf("under lower. node %d go under node %d\n", newNode->value, lower->second->value);
            }else{
                upper->second->leftChild = newNode;
                newNode->depth = upper->second->depth + 1;
                // printf("under upper. node %d go under node %d\n", newNode->value, upper->second->value);
            }
        }

        C += newNode->depth;
        printf("%lld\n", C);
    }

    return 0;
}