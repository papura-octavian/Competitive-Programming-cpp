// https://leetcode.com/problems/valid-sudoku

#include<iostream>
#include<vector>
#include<fstream>
#include<map>

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

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // frequency map
        map<char, bool> freq;

        //  ======== Testing line ========

        for (auto line : board) {
            for (char ch : line) {
                // do not count emty squares
                if (ch == '.') continue;

                // we found 2 identical number on a line
                if(freq[ch]) return false;

                // mark number as in the line
                freq[ch] = true;
            } 
            // clear from previous initializations
            freq.clear();
        }

        // ======== Testing Column ========

        // clear from previous initializations
        freq.clear();

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // do not count emty squares
                if (board[j][i] == '.') continue;

                // we found 2 identical number on a column
                if(freq[board[j][i]]) return false;

                // mark number as in the column
                freq[board[j][i]] = true;
            }
            // clear from previous initializations
            freq.clear();
        }

        // ======== Testing Squares ========

        for (int i = 0; i < 9; i += 3){
            for (int j = 0; j < 9; j += 3) {
                if(!square_check(board, i, j)) return false;
            }
        }

        return true;
    }

    private: bool square_check(vector<vector<char>>& board, int row, int col) {
        map<char, bool> freq;
        
        for (int i = row; i < row + 3; ++i) {
            for (int j = col; j < col + 3; ++j) {
                // do not count emty squares
                if (board[j][i] == '.') continue;

                // we found 2 identical number on a column
                if(freq[board[j][i]]) return false;

                // mark number as in the column
                freq[board[j][i]] = true;
            }
        }

        return true;
    }
};

int main () {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;
    if (obj.isValidSudoku(board)) cout << "TRUE";
    else cout << "FALSE";

    cout << endl << endl;
}