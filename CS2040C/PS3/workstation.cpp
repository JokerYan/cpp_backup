#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct Person{
    int arrive, leave;
};

struct arriveEarlier{
    bool operator()(Person a, Person  b){
        return a.arrive > b.arrive;
    }
};

struct leaveEarlier{
    bool operator()(Person a, Person  b){
        return a.leave > b.leave;
    }
};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    priority_queue<Person, vector<Person>, arriveEarlier> people;
    priority_queue<Person, vector<Person>, leaveEarlier> workstations;
    for(int i = 0; i < n; i++){
        int arrive, stay;
        scanf("%d %d", &arrive, &stay);
        Person person{arrive, arrive + stay};
        people.push(person);
    }

    int count = 0;
    while(!people.empty()){
        // printf("next person: %d\n", people.top().arrive);
        if(workstations.empty()){
            count++;
            workstations.push(people.top());
            people.pop();
        }
        else if(workstations.top().leave <= people.top().arrive){
            Person next = workstations.top();
            bool arranged = false;
            while(next.leave + m < people.top().arrive && next.leave <= people.top().arrive){
                workstations.pop();
                if(workstations.empty()){
                    arranged = true;
                    count++;
                    workstations.push(people.top());
                    people.pop();
                    break;
                }
                next = workstations.top();
            }
            if(!arranged){
                if(next.leave <= people.top().arrive){
                    workstations.pop();
                    workstations.push(people.top());
                    people.pop();
                }else{
                    workstations.push(people.top());
                    people.pop();
                    count++;
                }
            }
        }else{
            workstations.push(people.top());
            people.pop();
            count++;
        }
    }
    printf("%d", n - count);

    return 0;
}