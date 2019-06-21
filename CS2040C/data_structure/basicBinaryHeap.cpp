#include <stdio.h>
#include <vector>

using namespace std;

class basicBinaryHeap{
private:
    vector<int> compact_vector;
    int heap_size;
    
    int parent(int i){return i >> 1;};
    int left(int i){return i << 1;};
    int right(int i){return (i << 1) + 1;};

    void shift_up(int index){
        if(index == 1) return;
        if(compact_vector[index] > compact_vector[parent(index)]){
            swap(compact_vector[index], compact_vector[parent(index)]);
            shift_up(parent(index));
        }
    }

    void shift_down(int index){
        if(index >= heap_size) return;
        int swap_id = index;
        if(left(index) <= heap_size && compact_vector[left(index)] > compact_vector[swap_id]) swap_id = left(index);
        if(right(index) <= heap_size && compact_vector[right(index)] > compact_vector[swap_id]) swap_id = right(index);
        if(swap_id != index){
            swap(compact_vector[index], compact_vector[swap_id]);
            shift_down(swap_id);
        }
        return;
    }

public:
    basicBinaryHeap(){
        heap_size = 0;
        compact_vector.clear();
        compact_vector.push_back(-1);
    }

    void insert(int value){
        if(heap_size + 2 > compact_vector.size()) compact_vector.push_back(-1);
        compact_vector[++heap_size] = value;
        shift_up(heap_size);
    }

    int getMax(){
        return compact_vector[1]; //may have exception when the size is 0;
    }

    int extractMax(){
        int taken = compact_vector[1];
        swap(compact_vector[1], compact_vector[heap_size--]);
        shift_down(1);
        return taken;
    }

    bool isEmpty(){
        return (heap_size == 0);
    }

    void printAll(){
        while(!isEmpty()){
            printf("%d ", extractMax());
        }
        // for(int i = 0; i < compact_vector.size(); i++){
        //     printf("%d ", compact_vector[i]);
        // }
        printf("\n");
    }
};

int main(){
    int test_data[] = {5, 23, 3, 53, 24, 1, 98, 44, 76};
    basicBinaryHeap heap;
    for(int i = 0; i < sizeof(test_data) / sizeof(test_data[0]); i++){
        heap.insert(test_data[i]);
    }
    heap.printAll();

    return 0;
}