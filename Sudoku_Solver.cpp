// https://leetcode.com/problems/sudoku-solver

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void transform_input() {
    ifstream fin("input-output/in.txt");
    ofstream fout("input-output/out.txt");
    char ch, last_ch;

    bool newline = true;

    while(fin >> ch) {
        switch (ch) {
            case '[':
                fout << '{';
                if (newline) {
                    fout << endl << "\t";
                    newline = false;
                }
                break;

            case ']':
                if (last_ch == ']') fout << endl;
                  
                fout << '}';
                break;

            case ',':
                fout << ch;
                if (last_ch == ']') fout << endl << "\t";
                break;

            case '"':
                fout << "'";
                break;

            default:
                fout << ch;
                break;
        }
        last_ch = ch;
    }

    fout << ";";
}

void print_board(const vector<vector<char>>& board) {

    system("clear");

    // Column indexes
    cout << "    ";
    for (int j = 0; j < 9; ++j) {
        cout << j << ' ';
        if (j == 2 || j == 5) cout << "  ";
    }
    cout << "\n";

    for (int i = 0; i < 9; ++i) {

        if (i % 3 == 0)
            cout << "  +-------+-------+-------+\n";

        cout << i << " | ";

        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << ' ';
            if ((j + 1) % 3 == 0)
                cout << "| ";
        }

        cout << "\n";
    }

    cout << "  +-------+-------+-------+\n";
}

class Solution {
private:
    bool isValid(const vector<vector<char>>& board, int r, int c, char d) {
        for (int j = 0; j < 9; ++j) {
            if (board[r][j] == d) return false;
        }

        for (int i = 0; i < 9; ++i) {
            if (board[i][c] == d) return false;
        }

        int startR = (r / 3) * 3;
        int startC = (c / 3) * 3;
        for (int i = startR; i < startR + 3; ++i) {
            for (int j = startC; j < startC + 3; ++j) {
                if (board[i][j] == d) return false;
            }
        }

        return true;
    }

    vector<char> getCandidates(const vector<vector<char>>& board, int r, int c) {
        vector<char> candidates;
        for (char d = '1'; d <= '9'; ++d) {
            if (isValid(board, r, c, d)) {
                candidates.push_back(d);
            }
        }
        return candidates;
    }

    bool backtrack(vector<vector<char>>& board) {
        int bestR = -1;
        int bestC = -1;
        vector<char> bestCandidates;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') continue;

                vector<char> candidates = getCandidates(board, i, j);
                if (candidates.empty()) return false;

                if (bestR == -1 || candidates.size() < bestCandidates.size()) {
                    bestR = i;
                    bestC = j;
                    bestCandidates = candidates;

                    if (bestCandidates.size() == 1) break;
                }
            }
            if (bestR != -1 && bestCandidates.size() == 1) break;
        }

        // print_board(board);
        if (bestR == -1) return true;

        for (char d : bestCandidates) {
            board[bestR][bestC] = d;
            // print_board(board);

            if (backtrack(board)) return true;

            board[bestR][bestC] = '.';
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};

int main () {
    vector<vector<char>> board = {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}
    };
    Solution obj;
    obj.solveSudoku(board);
    print_board(board);

    // transform_input();

    cout << endl << endl;
}
