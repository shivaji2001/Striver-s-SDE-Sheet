// https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

class myQueue {

  public:
    vector<int>v;
    int maxSize;
    myQueue(int n) {
        v.clear();
        maxSize=n;
    }

    bool isEmpty() {
       return v.size()==0;
    }

    bool isFull() {
        return v.size()==maxSize;
    }

    void enqueue(int x) {
        v.push_back(x);
    }

    void dequeue() {
        if(v.size()>0)
        {
            v.erase(v.begin());
        }
    }

    int getFront() {
        if(v.size()==0) return -1;
        return v[0];
    }

    int getRear() {
        if(v.size()==0) return -1;
        return v[v.size()-1];
    }
};