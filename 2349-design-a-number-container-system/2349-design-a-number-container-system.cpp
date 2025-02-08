class NumberContainers {
public:
    unordered_map<int,set<int>>num_to_indice;
    unordered_map<int,int>indice_to_num;
    NumberContainers() {
        
    }
    void change(int index, int number) {
        if(indice_to_num.count(index)){ //if index is already occupied
            int oldnum=indice_to_num[index];
            num_to_indice[oldnum].erase(index); // Remove index from old number's set
            if(num_to_indice[oldnum].empty()){ // Clean up if set becomes empty
                num_to_indice.erase(oldnum);
            }
        }
        indice_to_num[index]=number;
        num_to_indice[number].insert(index);
    }
    
    int find(int number) {
        if(!num_to_indice[number].empty()){
            return *(num_to_indice[number].begin());
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */