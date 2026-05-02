#include <iostream>
using namespace std;

class Point {
    private:
        int x;
        int y;
    
    public:
        Point() : x(0), y(0) {}
        int get_x() { return this->x; }
        int get_y() { return this->y; }
        void set_x(int x) { this->x = x; }
        void set_y(int y) { this->y = y; }
    };

#include <vector>

void vector_examples() {
    vector<int> v1;
    
    int x;
    cout << "Digite quantos valores teremos no vector: ";
    cin >> x;
    for (int i=0; i<x; i++) {
        v1.push_back(i+10);
    }

    cout << "Valores no vetor v1: ";
    for (int i=0; i<v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << "\n";

    cout << "Valores no vetor v1 (outra possibilidade): ";
    for (auto v : v1) {
        cout << v << " ";
    }
    cout << "\n";

    vector<int> v2(15, -1);
    cout << "Valores no vetor v2: ";
    for (auto v : v2) {
        cout << v << " ";
    }
    cout << "\n";

    cout << "Digite quantos valores teremos no vector: ";
    cin >> x;
    vector<int> v3(x);
    for (int i=0; i<x; i++) {
        cin >> v3[i]; // precisa garantir que posição i existe
    }

    cout << "Valores no vetor v3: ";
    for (auto v : v3) {
        cout << v << " ";
    }
    cout << "\n";

    vector<Point> vp(2);
    vp[0].set_x(10);
    vp.at(0).set_x(20);
    cout << vp[0].get_x() << "\n";

    vector<vector<int>> m(3, vector<int>(4, -1));
    for (int i=0; i<m.size(); i++) {
        for (int j=0; j<m[i].size(); j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

#include <utility>

void pair_examples() {
    pair<int,bool> p;
    p.first = 10;
    p.second = false;

    cout << "(" << p.first << ",";
    if (p.second) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout <<")\n";

}

void tuple_examples() {
    tuple<int,bool,int,bool> t;
    t = {-1,false,10,true};
    if (get<3>(t)) {
        cout << "verdadeiro!!\n";
    }
}

#include <queue>
void queue_examples() {
    queue<int> q;
    q.emplace(3);
    q.emplace(10);
    q.emplace(100);
    if (q.front() == 3) {
        cout << "inicio é 3!\n";
        q.pop();
    }
    if (!q.empty()) {
        cout << q.front() << "\n";
    }
}

#include <stack>
void stack_examples() {
    stack<int> s;
    for (int i=0; i<5; i++) {
        s.push(i+5);
    }
    cout << "pilha = ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

#include <algorithm>
void sort_examples() {
    vector<int> v = {4,5,0,1};
    sort(v.begin(), v.end());
    for (int valor : v) {
        cout << valor << " ";
    }
    cout << "\n";
}

#include <map>
void map_examples() {
    map<string,int> periodo;
    periodo["gustavo"] = 2;
    cout << periodo["gustavo"] << "\n";
    cout << periodo["abc"] << "\n";
}

int main() {
    // vector_examples();
    // pair_examples();
    // tuple_examples();
    // queue_examples();
    // stack_examples();
    // sort_examples();
    // map_examples();

    return 0;
}