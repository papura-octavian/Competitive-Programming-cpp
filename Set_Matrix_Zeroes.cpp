#include <iostream>
#include <vector>
#include <map>
#include <fstream>

// https://leetcode.com/problems/set-matrix-zeroes

using namespace std;

void show_matrix(vector<vector<int>>& matrix) {
    system("clear");

    for (auto line : matrix) {
        for(auto col : line) {
            cout << col << " ";
        }
        cout << endl;
    }

    cout << "\n\n";
}

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

    struct poz {
        int col;
        int row;
    };

public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<poz> zero_poz;

        // find zpositions of 0
        for (int line = 0; line < matrix.size(); ++line) {
            for(int col = 0; col < matrix[line].size(); ++col) {
                if(!matrix[line][col]) zero_poz.push_back({col, line});
            }
        }

        // cross replace every zero
        for (poz p : zero_poz) cross_replace(matrix, p);
    }

private:
    void cross_replace(vector<vector<int>>& matrix, poz p) {

        // Direction: Up
        for (int i = p.row - 1; i >= 0; --i) matrix[i][p.col] = 0;

        // Direction : Down
        for (int i = p.row + 1; i < matrix.size(); ++i) matrix[i][p.col] = 0;

        // Direction: Left
        for (int j = p.col - 1; j >= 0; --j) matrix[p.row][j] = 0;

        // Direction: Right
        for (int j = p.col + 1; j < matrix[p.row].size(); ++j) matrix[p.row][j] = 0;
    }
};

int main () {
    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    Solution obj;
    obj.setZeroes(matrix);

    // transform_input();
    show_matrix(matrix);
        
    return 0;
}
