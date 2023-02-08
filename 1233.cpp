#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


template<typename T>
void printVector(const T& t) {
    copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, ", "));
    cout << "\n";
}

vector<string> split(string const& s, char delim) {
    vector<string> res;
    stringstream ss(s);
    string subs;

    while (getline(ss, subs, delim)) res.emplace_back(subs);
    return res;
}

// Trie
struct node {
    int val;
    bool isEnd;
    vector<node*> children;
    node() : val(-1), isEnd(false), children(vector<node*>{}) {}
    node(int x) : val(x), isEnd(false), children(vector<node*>{}) {}
};

class Trie {
private:
    node* root;
    vector<vector<int>> main;
public:
    Trie() { root = new node(); }
    void insert(vector<int>& paths) {
        node* p = root;
        for (auto const& path : paths) {
            bool find = false;
            for (auto& child : p->children) {
                if (child->val == path) {
                    p = child;
                    find = true;
                    break;
                }
            }
            if (!find) {
                node* q = new node(path);
                p->children.emplace_back(q);
                p = q;
            }
        }
        p->isEnd = true;
    }

    vector<vector<int>> get_main() {
        vector<int> prefix{};
        dfs(prefix, root);
        return main;
    }
    void dfs(vector<int>& prefix, node* r) {
        prefix.emplace_back(r->val);
        if (r->isEnd) main.emplace_back(prefix);
        else for (auto const& p : r->children) {
            dfs(prefix, p);
        }
        prefix.pop_back();
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string, int> pathMap;
        Trie mytrie;
        int id = 0;        

        for (auto const& path : folder) {
            vector<string> paths = split(path, '/');
            vector<int> ids;
            size_t idx = 0;
            for (auto const& p : paths) {
                if (idx++ == 0) continue;
                if (!pathMap[p]) pathMap[p] = ++id;
                ids.emplace_back(pathMap[p]);
            }
            mytrie.insert(ids);
        }
        unordered_map<int, string> nameMap;
        for (auto const& [k, v] : pathMap) nameMap[v] = k;
        for (auto const& [k, v] : nameMap)
            cout << k << ", " << v << "\n";

        vector<vector<int>> id_res = mytrie.get_main();
        vector<string> res;
        for (auto const& id_v : id_res) {
            string s = "";
            for (int i = 1; i < id_v.size(); i++)
                s += "/" + nameMap[id_v[i]];
            res.emplace_back(s);
            cout << s << "\n";
        }

        //for (auto const& id_v : id_res) printVector(id_v);
        //cout << "here\n";
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> folder = 
        // {"/a","/a/b","/c/d","/c/d/e","/c/f"};
        // {"/a","/a/b/c","/a/b/d"};
        {"/a/b/c","/a/b/ca","/a/b/d"};
    vector<string> res = sol.removeSubfolders(folder);

    system("pause");
    return 0;

}
