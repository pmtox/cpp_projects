
#include <bits/stdc++.h>
using namespace std;

const int N = 5;  // small grid for easy testing

void printGrid(vector<string> &grid) {
    for(auto row: grid) cout << row << endl;
    cout << endl;
}

int main() {
    vector<string> grid(N, string(N, '.'));

    vector<pair<int,int>> snake;
    snake.push_back({N/2, N/2});  // start in middle
    grid[N/2][N/2] = 'S';

    srand(time(0));
    int fx = rand()%N, fy = rand()%N;
    grid[fx][fy] = 'F';  // place food

    char dir;
    bool gameOver = false;

    while(!gameOver) {
        printGrid(grid);

        cout << "Enter direction (w/a/s/d): ";
        cin >> dir;

        pair<int,int> head = snake.back();
        pair<int,int> newHead = head;

        if(dir=='w') newHead.first--;
        else if(dir=='s') newHead.first++;
        else if(dir=='a') newHead.second--;
        else if(dir=='d') newHead.second++;

        // Check collision
        if(newHead.first<0 || newHead.first>=N || newHead.second<0 || newHead.second>=N) {
            gameOver = true;
            break;
        }
        for(auto p: snake) if(p==newHead) gameOver = true;
        if(gameOver) break;

        // Move snake
        snake.push_back(newHead);

        if(newHead.first==fx && newHead.second==fy) {
            // Snake eats food, grow
            do {
                fx = rand()%N; fy = rand()%N;
            } while(grid[fx][fy]!='.');
            grid[fx][fy] = 'F';
        } else {
            // remove tail
            pair<int,int> tail = snake.front();
            grid[tail.first][tail.second] = '.';
            snake.erase(snake.begin());
        }

        // Update grid
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(grid[i][j]!='F') grid[i][j]='.';
        for(auto p: snake) grid[p.first][p.second]='S';
    }

    cout << "Game Over! Score: " << snake.size()-1 << endl;
    return 0;
}

