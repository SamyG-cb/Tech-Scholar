#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cctype>

using namespace std;

typedef map<string, int> MapTree;
typedef pair<string,int> p;


int main(){


    ifstream fin;
    string file_name, word;
    MapTree map;
    vector<p> vec;
    cout << "Enter the file name: ";
    cin >> file_name;
    fin.open(file_name);

    if(!fin){
        cout<< "Counldn't find the file"<<endl;
        exit(1);
    }

    while (!fin.eof()){
        fin >> word;
        for(int i = 0; i < word.length(); i++){
            if(ispunct(word[i])){
                word.erase(i--,1);

            }
        }
        ++map[word];
    }
    for (MapTree::iterator iter = map.begin(); iter != map.end(); ++iter){
            cout << iter->first << " occured "<< iter->second << " times.\n";
    }
    copy(map.begin(),
    map.end(),
    back_inserter<vector<p>>(vec));
    sort(vec.begin(), vec.end(),[](const p& l, const p& r) {
        if (l.second != r.second)
            return l.second > r.second;

        return l.first > r.first;
    });

    for (auto const &p: vec) {
        cout << '{' << p.first << "," << p.second << '}' << '\n';
    }
    fin.close();
    ofstream fout;
    fout.open("Result.csv", ofstream::out | ofstream::app);
    fout <<"Word"<<"occor" <<endl;

    for (auto const &p: vec) {
        fout << '{' << p.first << "," << p.second << '}' << '\n';
    }
    fout.close();
}