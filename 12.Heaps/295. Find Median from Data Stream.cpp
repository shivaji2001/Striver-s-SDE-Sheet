// R
// https://leetcode.com/problems/find-median-from-data-stream/description/
class MedianFinder {
public:
    priority_queue<int,vector<int>>maxpq;
    priority_queue<int,vector<int>,greater<int>>minpq;

    MedianFinder() {
        maxpq=priority_queue<int,vector<int>>();
        minpq=priority_queue<int,vector<int>,greater<int>>();
    }
    
    void addNum(int num) 
    {
      if(maxpq.size()==minpq.size())
      {
        if(minpq.size()>0 and   num>minpq.top())
        {
            maxpq.push(minpq.top());
            minpq.pop();
            minpq.push(num);
        }
        else
        {
            maxpq.push(num);
        }
      }
      else
      {
        if(num>=maxpq.top())
        {
            minpq.push(num);
        }
        else
        {
            minpq.push(maxpq.top());
            maxpq.pop();
            maxpq.push(num);
        }
      }
    }
    
    double findMedian() {
        int a=0;
        int b=0;
        if( (minpq.size()+maxpq.size())%2==0  )
        {
            int a=0;
            int b=0;
            if(minpq.size()>0)
              a=minpq.top();
            if(maxpq.size()>0)
              b=maxpq.top();
            return ((double)a+(double)b)/(double)2.0;
        }
        else
        {
            return maxpq.top();
        }
        
        
    }
};

