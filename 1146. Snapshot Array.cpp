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

        it--; // get the element just before the snap_id

        return it->second;
    }
};
