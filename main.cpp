
#include "main.h"

using namespace std;

void printLabels(string outputFile, Graph g) {
    set<string> s;
    ofstream os(outputFile);

    for (Node i : g.nodes) {
        for (string label : i.labels) {
            s.insert(label);
        }
    }

    for (string label : s) {
        os << label << endl;
    }

    os.close();
}

int main(){
    Exp exp;

    //exp.exp1Limited();
    //exp.exp1Graph();
    //exp.exp1NoNodelabel();
    //exp.exp1NoEdgelabel();
    //exp.exp2Limited();
    //exp.exp2Graph();
    //exp.exp2NoNodelabel();
    //exp.exp2NoEdgelabel();
    //exp.exp3Limited();
    //exp.exp3Graph();
    //exp.exp3NoNodelabel();
    //exp.exp3NoEdgelabel();
    exp.expAll();
}