
class SeatManager {
private:
    int last;
    priority_queue<int , vector<int>, greater<int>> not_reserve;
public:
    SeatManager(int n) {
        this->last = 0;
    }
    int reserve() {
        if(this->not_reserve.empty()){
            this->last += 1;
            return this->last;
        } else{
            int res = this->not_reserve.top();
            this->not_reserve.pop();
            return res;
        }
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber == this->last){
            this->last -= 1;
        } else{
            this->not_reserve.push(seatNumber);
        }
    }
};
