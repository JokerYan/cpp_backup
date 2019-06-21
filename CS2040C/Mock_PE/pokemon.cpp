#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct pokemon{
    long long index, attack, defence, health;
};

bool compAttack(const pokemon& a, const pokemon& b){
    return a.attack > b.attack;
}

bool compDefence(const pokemon& a, const pokemon& b){
    return a.defence > b.defence;
}

bool compHealth(const pokemon& a, const pokemon& b){
    return a.health > b.health;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, K; cin >> N >> K;

    vector<pokemon> allPokemon;
    for(int i = 0; i < N; i++){
        long long A, D, H;
        cin >> A >> D >> H;
        allPokemon.push_back(pokemon{i, A, D, H});
    }

    set<int> selected;
    sort(allPokemon.begin(), allPokemon.end(), compAttack);
    auto firstPokemon = allPokemon.begin();
    for(int i = 0; i < K; i++){
        selected.insert((*firstPokemon).index);
        ++firstPokemon;
    }
    
    sort(allPokemon.begin(), allPokemon.end(), compDefence);
    firstPokemon = allPokemon.begin();
    for(int i = 0; i < K; i++){
        selected.insert((*firstPokemon).index);
        ++firstPokemon;
    }
    
    sort(allPokemon.begin(), allPokemon.end(), compHealth);
    firstPokemon = allPokemon.begin();
    for(int i = 0; i < K; i++){
        selected.insert((*firstPokemon).index);
        ++firstPokemon;
    }
    cout << selected.size() << endl;

    return 0;
}