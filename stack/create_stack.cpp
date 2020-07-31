#include<bits/stdc++.h>
using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
private:    
	stack<int> s;
    vector<int> maxv;
	vector<int> minv;

public:
    MinMaxStack(){
        	maxv.push_back(INT_MIN);
	        minv.push_back(INT_MAX);
    }
  int peek() {
		if(!s.empty()){
				return s.top();
		}
		return -1;
  }

  int pop() {
		if(!s.empty()){
				int a = s.top();
				s.pop();
				if(maxv[maxv.size()-1]==a)maxv.pop_back();
				if(minv[minv.size()-1]==a)minv.pop_back();
				return a;
		}
		return -1;
  }

  void push(int number) {
		s.push(number);
		if(number>=maxv[maxv.size()-1])maxv.push_back(number);
		if(number<=minv[minv.size()-1])minv.push_back(number);
		return;
  }

  int getMin() {
		if(minv.size()>1){
				return minv[minv.size()-1];
		}
		return -1;
  }

  int getMax() {
		if(maxv.size()>1){
			return maxv[maxv.size()-1];
		}
		return -1;
  }
};
