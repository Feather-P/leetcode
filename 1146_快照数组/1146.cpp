#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class SnapshotArray {
    public:
    SnapshotArray(int length) {
        snap_array.resize(length);
        for (int i = 0; i < length; i++) {
            snap_array[i].push_back(Node{0,0}); 
        }
    }

    auto set(int index, int val) -> void {
        auto it = snap_array.at(index).rbegin();
        if (it->snap_id == this->snap_id_counter) {
            it->value = val;
        } else {
            snap_array.at(index).push_back(
                Node{
                    val,
                    snap_id_counter
                }
            );
        }
    }

    auto snap() -> int {
        this->snap_id_counter++;
        return snap_id_counter - 1;
    }

    auto get(int index, int snap_id) -> int {
        auto &target = snap_array.at(index);
        auto it = upper_bound(target.begin(),
        target.end(),
        snap_id,
        [] (int id, Node node) -> bool {
            return id < node.snap_id;
            }
        );
        return prev(it)->value;
    }

    private:
    int snap_id_counter = 0;

    struct Node {
        int value;
        int snap_id;
    };

    vector<vector<Node>> snap_array;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */