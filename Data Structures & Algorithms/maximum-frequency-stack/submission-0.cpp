class FreqStack {
public:
    std::unordered_map<int,int> counts;
    std::unordered_map<int,std::stack<int>> stacks;
    int max_count;
    FreqStack() {
        max_count = 0;
    }
    
    void push(int val) {
        counts[val]++;
        int val_count = counts[val];

        if(val_count > max_count){
            max_count = val_count;
            stacks[val_count] = std::stack<int>();
        }
        stacks[val_count].push(val);
    }
    
    int pop() {
        int res = stacks[max_count].top();
        stacks[max_count].pop();
        counts[res]--;
        if(stacks[max_count].empty()){
            max_count--;
        }

        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */