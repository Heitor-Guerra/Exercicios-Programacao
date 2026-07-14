#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <string>

using namespace std;


int main() {
    unordered_map<string, unordered_map<string, pair<float, float>>> students;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string student;
        int num_dim;
        cin >> student >> num_dim;

        unordered_map<string, pair<float, float>> disc;
        for(int j = 0; j < num_dim; j++) {
            string disciplina;
            float falta;
            float media;

            cin >> disciplina >> falta >> media;

            disc[disciplina] = make_pair(falta, media);
        }

        students[student] = disc;
    }

    cin >> n;

    for(int i = 0; i < n; i++) {
        string student, disciplina;
        cin >> student >> disciplina;
        
        unordered_map<string, pair<float, float>> disciplinas =  students[student];
        
        if(disciplinas.count(disciplina) <= 0) {
            cout << "NAO_CURSOU" << endl;
            continue;
        }

        pair<float, float> dados = disciplinas[disciplina];

        float falta = dados.first;
        float media = dados.second;

        if(falta <= 0.25 && media >= 7) {
            cout << "APROVADO" << endl;
        } else {
            cout << "REPROVADO" << endl;
        }
    }


    return 0;
}