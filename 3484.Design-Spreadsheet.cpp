#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spreadsheet {
    vector<vector<int>> matrix;
public:
    Spreadsheet(int rows) {
        matrix.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [col, row] = colAndRowFromCell(cell);
        matrix[row][col] = value;
    }
    
    void resetCell(string cell) {
        auto [col, row] = colAndRowFromCell(cell);
        matrix[row][col] = 0;
    }
    
    int getValue(string formula) {
        int i = formula.find("+");
        int x = valueForParameter(formula.substr(1, i - 1));
        int y = valueForParameter(formula.substr(i + 1));
        return x + y;
    }
private:
    pair<int, int> colAndRowFromCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1, cell.length() - 1)) - 1;
        return {col, row};
    }
    int valueForParameter(string s) {
        if (isDigit(s)) return stoi(s);
        auto [col, row] = colAndRowFromCell(s);
        return matrix[row][col];
    }
    bool isDigit(string& s) {
        for (char c : s) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
};

int main() {
    Spreadsheet* spreadsheet = new Spreadsheet(12);
    cout << spreadsheet->getValue("=5+7") << endl; // 12
    spreadsheet->setCell("A1", 10);
    cout << spreadsheet->getValue("=A1+6") << endl; // 16
    spreadsheet->setCell("B2", 15);
    cout << spreadsheet->getValue("=A1+B2") << endl; // 25
    spreadsheet->resetCell("A1");
    cout << spreadsheet->getValue("=A1+B2") << endl; // 15
} 