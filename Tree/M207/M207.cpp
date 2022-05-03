#include<iostream>
#include<vector>
using namespace std;

class Sol {
    int x;
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        vector<vector<int> > *edge = new vector<vector<int> >;
        edge->push_back(prerequisites[0]);
        int j = 0;
        for(int i=1; i< prerequisites.size() ; i++ ){
            while(j < edge->size()){
                if(edge->at(0).at(0) == prerequisites[i][1] && edge->at(0).at(1) == prerequisites[i][0])
                    return false;
                else{
                  if(j == (edge->size()-1)){
                      edge->push_back(prerequisites[i]);
                      break;
                  }
                    j++;
                }
            }
            j = 0;
        }
        return (numCourses == edge->size()) ? 1: 0;
    }
};

int main(){
    vector<vector<int> > foo{
        {0,1},
        {1,2},
        {2,3},
        {1,0}
    };
    Sol *ddext = new Sol;
    cout<< ddext->canFinish(foo.size(), foo)<< endl;
    return 0;
    //problem 01, 12, 20
}

