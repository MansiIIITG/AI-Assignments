#include <bits/stdc++.h>
using namespace std;

struct cell{    //structure for a cell of board
        vector<int> states;
        int cost; //cost function
        int next_cell;
        int h; //heuristic function
};

struct compare{ //funtion to compare the cost of going to two different cells
        bool operator()(cell c1, cell c2){
                return c1.cost < c2.cost;
        }
};

int ans=0;
cell create_new_cell(cell , int, int );
bool check(vector<int> , int , int );
void astarAlgo(priority_queue<cell, vector<cell>, compare> , int );
bool checkGoal(vector<int> );
void printSol(vector<int> );


int main(){
        int n;
        cout<<"n = ";
        cin>>n;
        cout<<n<<endl;
        priority_queue<cell, vector<cell>, compare> pq;
        cell first;
        first.states.push_back(0); //placing queen at (0,0)
        first.cost = 0;
        first.h = n-0; //my heuristic function is h(i) = n-i
        first.next_cell = 1; //row where the next queen is being placed
        pq.push(first);

        astarAlgo(pq,n);

        cout << "All possible solutions = " <<ans<<endl;
}

cell create_new_cell(cell temp, int next_row, int n){ //creating a new cell
        vector<int> v;
        if(temp.states.size()){
                v.assign(temp.states.begin(), temp.states.end());
        }
        v.push_back(next_row);
        cell new_cell;
        new_cell.states = v;
        new_cell.cost = temp.cost + temp.h +1;
        new_cell.next_cell = v.size();
        temp.h = n- temp.states.size();
        return new_cell;
}

bool check(vector<int> curr, int row, int col){ //checking whether placing the queen at this position is safe or not
        for(int i=0; i<curr.size(); i++){
                if(curr[i] == row || abs(curr[i]-row) == abs(col-i)){
                        return false;
                }
        }
        return true;
}

void astarAlgo(priority_queue<cell, vector<cell>, compare> q, int n){
	int nfirst_cell = 1;
	while(true){
		cell c;
		if(q.size()){
			c = q.top();
			q.pop();
		}
		else{
			if(nfirst_cell == n) return;
			c.states.push_back(nfirst_cell++);
			c.cost = 0;
			c.next_cell = 1;
			c.h = n - 0;
		}
		if(c.states.size() == n){
			if(checkGoal(c.states)){
			    ans++;
				printSol(c.states);
			}
			continue;
		}
		for(int i=0; i<n; i++){
			if(check(c.states, i, c.next_cell)){
				cell new_cell = create_new_cell(c, i, n);
				q.push(new_cell);
			}
		}
	}
}

bool checkGoal(vector<int> v){ 
        for(int i=0; i<v.size(); i++){
                for(int j=0; j<v.size(); j++){
                        if(i==j) continue;
                        if(v[i] == v[j] || abs(v[i]-v[j]) == abs(i-j)){
                                return false;
                        }
                }
        }
        return true;
}




void printSol(vector<int> v){
        cout << "[ ";
        for(auto i : v){
                cout << i << " ";
        }
        cout << "]\n";
}


