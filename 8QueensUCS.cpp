Initial state : An empty board, in this case queue i.e. no queen present on the board

Set of states : The states are the number of queens that lie between 0 to 8

state operation : The operation is to move queen in such a position on the board such that neither does it attack nor is attcked by the present queens.

path cost : The path cost is same for states at each level.
			The cost of first level is 1, then it keeps increasing by 1 and reaches till 8;

Goal state : A 2D matrix with 8 queens present on it , all in non attacking positions.




#include <bits/stdc++.h>
using namespace std;

struct cell{    //structure for a cell of board
        vector<int> states;
        int cost;
        int next_cell;
};

struct compare{ //funtion to compare the cost of going to two different cells
        bool operator()(cell c1, cell c2){
                return c1.cost < c2.cost;
        }
};

int ans=0;
cell create_new_cell(cell , int );
bool check(vector<int> , int , int );
void ucs(priority_queue<cell, vector<cell>, compare> , int );
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
        first.next_cell = 1; //row where the next queen is being placed
        pq.push(first);

        ucs(pq,n);

        cout << "All possible solutions = " <<ans<<endl;
}

cell create_new_cell(cell temp, int next_row){ //creating a new cell
        vector<int> v;
        if(temp.states.size()){
                v.assign(temp.states.begin(), temp.states.end());
        }
        v.push_back(next_row);
        cell new_cell;
        new_cell.states = v;
        new_cell.cost = temp.cost;
        new_cell.next_cell = v.size();
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

void ucs(priority_queue<cell, vector<cell>, compare> q, int n){
        int just_next_cell = 1;
        while(true){
                cell v;
                if(q.size()){
                        v = q.top();
                        q.pop();
                }
                else{
                        if(just_next_cell == n) return;
                        v.states.push_back(just_next_cell++);
                        v.cost = 0;
                        v.next_cell = 1;
                }
                if(v.states.size() == n){
                        if(checkGoal(v.states)){
                        		ans++;
                                printSol(v.states);
                        }
                        continue;
                }
                for(int i=0; i<n; i++){
                        if(check(v.states, i, v.next_cell)){
                                cell new_cell = create_new_cell(v, i);
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


