#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class MazeMaker
{
private:
    int m_maxSizeX;
    int m_maxSizeY;
    int axis[50][50];
    queue<pair<int,int> > m_queue;

public:
    int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol);
};

int MazeMaker::longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol) {
    m_maxSizeX = maze[0].length();
    m_maxSizeY = maze.size();
    pair<int,int> p;
    int maxValue = 0;
    int currentRow;
    int currentCol;
    int nextRow;
    int nextCol;

    for (int i = 0 ; i < 50 ; i++)
        for (int j = 0 ; j < 50 ; j++)
            axis[i][j] = -1;
    m_queue.push(make_pair(startRow,startCol));
    axis[startRow][startCol] = 0;

    while (!m_queue.empty()) {
        p = m_queue.front();
        currentRow = p.first;
        currentCol = p.second;
        m_queue.pop();
        for (int i = 0 ; i < moveRow.size() ; i++) {
            nextRow = currentRow + moveRow[i];
            nextCol = currentCol + moveCol[i];
            if (0 <= nextRow && nextRow < m_maxSizeY && 0 <= nextCol && nextCol < m_maxSizeX && axis[nextRow][nextCol] == -1 && maze[nextRow].at(nextCol) == '.') {
                axis[nextRow][nextCol] = axis[currentRow][currentCol] + 1;
                m_queue.push(make_pair(nextRow,nextCol));
            }
        }
    }

    for (int i = 0 ; i < m_maxSizeY ; i++) {
        for (int j = 0 ; j < m_maxSizeX ; j++) {
            if (axis[i][j] == -1 && maze[i].at(j) == '.') return -1;
            else maxValue = max(maxValue, axis[i][j]);
        }
    }
    return maxValue;
}

