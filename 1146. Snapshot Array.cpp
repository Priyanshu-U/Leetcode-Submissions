# Method 1 - Using inbuilt upperbound function
class SnapshotArray {
public:
    int snap_id;
    vector<map<int, int>> array_mem;

    SnapshotArray(int length) {
        
        snap_id = 0;
        array_mem.resize(length);
        
        for (int i = 0; i < length; ++i) {
            array_mem[i][0] = 0;
        }
    }

    void set(int index, int val) {
        array_mem[index][snap_id] = val;
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id) {
        auto it = array_mem[index].upper_bound(snap_id);
        if (it == array_mem[index].begin()) {
            return 0;
        }

        it--;

        return it->second;
    }
};

# Method 2 - Creating own Binary Search 

class SnapshotArray {
public:
    unordered_map<int,vector<pair<int,int>>> snapArray;
    int snapId = 0;
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        snapArray[index].push_back({snapId,val});
    }
    
    int snap() {
        snapId++;
        return snapId-1;
    }
    
    int get(int index, int snap_id) {

        auto itr = snapArray.find(index);
        if (itr==snapArray.end()){
            return 0;
        }
        vector<pair<int,int>> &values = itr->second;

        int size = values.size();

        int low = 0;
        int high = size-1;

        int mid;

        int ans = 0;

        while(low<=high){
            mid = low + (high - low)/2;

            if(values[mid].first<=snap_id){
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

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
