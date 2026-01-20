class Solution {
    string d;
    vector<char> undone;
  public:
    void append(char x) {
        d.push_back(x);
        undone.clear();
    }
    void undo() {
        if (d.empty()) return;
        undone.push_back(d.back());
        d.pop_back();
    }
    void redo() {
        if (undone.empty()) return;
        d.push_back(undone.back());
        undone.pop_back();
    }
    string read() {
        return d;
    }
};
