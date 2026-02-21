class Solution {
  public:
    
    int minPlatform(vector<int>& arr, vector<int>& dep) {
       vector<pair<int,char>>vp;
       int n=arr.size();
       for(int i=0;i<n;i++)
       {
           vp.push_back({arr[i],'a'});
           vp.push_back({dep[i],'d'});
       }
       sort(vp.begin(),vp.end());
       int activity=0;
       int platforms=0;
       for(int i=0;i<2*n;i++)
       {
           if(vp[i].second=='a')
           {
               activity++;
           }
           else
           {
               activity--;
           }
           platforms=max(platforms,activity);
       }
       return platforms;
        
    }
};
