// CPP program to calculate sum 
// in an interval and update with 
// square root 
#include <bits/stdc++.h> 
using namespace std; 

// Maximum size of input array 
const int MAX = 100; 

int BIT[MAX + 1]; 

// structure for queries with members type, 
// leftIndex, rightIndex of the query 
struct queries { 
	int type, l, r; 
}; 

// function for updating the value 
void update(int x, int val, int n) 
{ 
	for (x; x <= n; x += x & -x) { 
		BIT[x] += val; 
	} 
} 

// function for calculating the required 
// sum between two indexes 
int sum(int x) 
{ 
	int s = 0; 
	for (x; x > 0; x -= x & -x) { 
		s += BIT[x]; 
	} 
	return s; 
} 

// function to return answer to queries 
void answerQueries(int arr[], queries que[], int n, int q) 
{ 
	// Declaring a Set 
	set<int> s; 
	for (int i = 1; i < n; i++) { 

		// inserting indexes of those numbers 
		// which are greater than 1 
		if (arr[i] > 1) 
			s.insert(i); 
		update(i, arr[i], n); 
	} 

	for (int i = 0; i < q; i++) { 

		// update query 
		if (que[i].type == 1) { 
			while (true) { 

				// find the left index of query in 
				// the set using binary search 
				auto it = s.lower_bound(que[i].l); 

				// if it crosses the right index of 
				// query or end of set, then break 
				if (it == s.end() || *it > que[i].r) 
					break; 

				que[i].l = *it; 

				// update the value of arr[i] to 
				// its square root 
				update(*it, (int)sqrt(arr[*it]) - arr[*it], n); 

				arr[*it] = (int)sqrt(arr[*it]); 

				// if updated value becomes equal to 1 
				// remove it from the set 
				if (arr[*it] == 1) 
					s.erase(*it); 

				// increment the index 
				que[i].l++; 
			} 
		} 

		// sum query 
		else { 
			cout << (sum(que[i].r) - sum(que[i].l - 1)) << endl; 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	int q = 4; 

	// input array using 1-based indexing 
	int arr[] = { 0, 4, 5, 1, 2, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// declaring array of structure of type queries 
	queries que[q + 1]; 

	que[0].type = 2, que[0].l = 1, que[0].r = 5; 
	que[1].type = 1, que[1].l = 1, que[1].r = 2; 
	que[2].type = 1, que[2].l = 2, que[2].r = 4; 
	que[3].type = 2, que[3].l = 1, que[3].r = 5; 

	// answer the Queries 
	answerQueries(arr, que, n, q); 

	return 0; 
} 
