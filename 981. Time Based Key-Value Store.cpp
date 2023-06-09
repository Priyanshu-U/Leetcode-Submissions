# Method 1 - Using a Map of string:vector<pair<int,string>> and using the monotonous nature of timestamps for binary search on that vector.
class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> tm;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
 
        auto itr = tm.find(key);
        if (itr == tm.end())
        return "";
        std::vector<std::pair<int, string>> &values = itr->second;
        // Make sure to use a referrence instead of copying or calling the values from the map directly everytime, it increases the complexity, space and time, significantly.
        

        int size = values.size();
        int low = 0;
        int high = size - 1;
        int mid;
        string ans="";

        while(low<=high){
            mid = low + (high - low)/2;
            if(values[mid].first<=timestamp){
                ans = values[mid].second;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
        
    }
};
