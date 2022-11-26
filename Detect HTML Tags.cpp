#include <stdio.h>
#include <set>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

set<string> tags;

int main() {
    int n;
    cin >> n;
    getchar();

    string aux, s;
    tags.clear();

    while(n--) {
        getline(cin, aux);
        int size = aux.size();

        for(int i=0; i<size; i++) {
            if(aux[i] == '<') {
                s.clear();

                for(int j=aux[i+1] == '/' ? i+2 : i+1; aux[j] != ' ' && aux[j] != '/' && aux[j] != '>'; j++) {
                    s.push_back(aux[j]);
                }

                if(!tags.count(s)) {
                    tags.insert(s);
                }
            }
        }
    }

    bool first = true;
    for(set<string>::iterator it = tags.begin(); it != tags.end(); it++) {
        if(!first) cout << ";";
        first = false;
        cout << *it;
    }
    cout << endl;

    return 0;
}
