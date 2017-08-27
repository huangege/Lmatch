//
// Created by HuanGege on 05/12/2016.
//

#include "main.h"

vector<string> split(string line, string s) {
    vector<string> v;
    int l = 0;
    int r = 0;
    if (line == "") return v;

    r = line.find(s, l);
    while (r != string::npos) {
        if (l != r)
            v.push_back(line.substr(l, r - l));
        l = r + s.length();
        r = line.find(s, l);
    }
    if (l != r)
        v.push_back(line.substr(l));
    return v;
}

vector<string> splitBy(string line, string s) {
    vector<string> v;
    int l = 0;
    int r = 0;
    if (line == "" || s == "") return v;

    r = line.find(s, l);
    while (r != string::npos) {
        if (l != r)
            v.push_back(line.substr(l, r - l));
        else
            v.push_back("");
        l = r + s.length();
        r = line.find(s, l);
    }
    if (l != r)
        v.push_back(line.substr(l));
    return v;
}