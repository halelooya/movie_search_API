#include <iostream>
#include <unordered_map>
#include <string>
#include <vector> 
#include <fstream>
#include <sstream>
#include <unordered_set>
using namespace std;

vector<int> query(string keywords,unordered_map<string,unordered_set<int> >& index){
	istringstream iss(keywords);
	unordered_set<int> res;
	for (string word;iss>>word;){
    	if (index.find(word)!=index.end()){
    		if (res.size()==0) res=index[word];
    			else {
    				unordered_set<int> cur;
    				for (int i:res)
    					if (index[word].find(i)!=index[word].end()) cur.insert(i);
    				res=cur;
    			}
    	} 		
    }	
    return vector<int> (res.begin(),res.end());
}

int main() 
{
	cout<<"Loading indexed_data..."<<endl;
    ifstream fin("indexed_data.txt");
    string name,key,idx;
    vector<string> movie_name;
    unordered_map<string,unordered_set<int> > index;

    //Loading movie_name;
    for (int i=0;i<1000;i++){
    	getline(fin,name);
    	movie_name.push_back(name);
    }

    //Loading index;
    for (;getline(fin,key);){
    	if (getline(fin,idx)){
    		istringstream iss(idx);
    		for (int val;iss>>val;){
    			index[key].insert(val);
    		}	
    	}
    }

    fin.close();
    cout<<"Loading done..."<<endl;

    cout<<"/-------------------------------------------/"<<endl;
    cout<<"/--------Search-top-1000-IMDB-movie---------/"<<endl;
    cout<<"/-------------------------------------------/"<<endl;
    cout<<"/Search by movie_name / directors / writers / "<<endl;
    cout<<"/actors / genres / year / country / language/"<<endl;
    cout<<"/-------------------------------------------/"<<endl;
    cout<<endl;

    string keywords;
    cout<<"Please enter your keywords:(enter Q to quit)"<<endl;
    getline(cin,keywords);
    while (keywords!="Q"){
    	vector<int> res = query(keywords,index);
    	string ans="[";
    	for (int i:res){
    		if (ans.size()!=1) ans+=",";
    		ans+="\""+movie_name[i]+"\"";
    	}
    	ans+="]";
		cout<<"Search result:"<<endl;
		cout<<ans<<endl;
    	cout<<"/-------------------------------------------/"<<endl;
    	cout<<endl;
    	cout<<"Please enter your keywords:(enter Q to quit)"<<endl;	
    	getline(cin,keywords);
    }

    return 0;
}