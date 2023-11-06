class SeatManager {
    int last=0;
    priority_queue<int,vector<int>,greater<int>> que;
public:
    SeatManager(int n) {
    }
    
    int reserve() {
        if(que.empty()){
            last++;
            return last;
        }else {
            int top=que.top();que.pop();
            return top;
        }
    }
    
    void unreserve(int seat) {
        if(last==seat){
            last--;
        }else que.push(seat);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */