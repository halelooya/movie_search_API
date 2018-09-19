#include <iostream>
#include <unordered_map>
#include <string>
#include <vector> 
#include <fstream>
#include <sstream>
#include <set>
using namespace std;

int main() 
{
    ifstream fin("raw_data.txt");
    string name,keywords;
    vector<string> movie_name;
    unordered_map<string,set<int> > index;
    for (int i=0;i<1000;i++){
    	getline(fin,name);
    	movie_name.push_back(name);

    	getline(fin,keywords);
    	istringstream iss(keywords);
    	for (string word;iss>>word;){
    		index[word].insert(i);
    	}
    }
    fin.close();

    ofstream fout("indexed_data.txt");
    for (int i=0;i<movie_name.size();i++) fout<<movie_name[i]<<endl;
    for (auto it : index){
    	fout << it.first << endl;
    	for (int num:it.second) fout<<num<<" ";
    	fout << endl;
    }
    fout.close();
    return 0;
}