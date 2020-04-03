#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

class Matrix{
public:
    Matrix(int rows, int cols): rows_(rows), cols_(cols), values_(rows*cols){}
    int& operator()(int row, int col){
        return values_[row * cols_ + col];
    }

    int operator()(int row, int col) const {
        return values_[row * cols_ + col];
    }

    void Print(){
        for (int i = 0; i < rows_ * cols_; ++i) {
            if( i != 0 && i % cols_ == 0){
                cout << "\n";
            }
            cout << values_[i] << " ";
        }
        cout << "\n";
    }
private:
    int rows_, cols_;
    vector<int> values_;
};

// Test in main()
int main() {
    Matrix matrix(2,2);
    matrix(0,0) = 4;
    assert(matrix(0,0) == 4);
    matrix.Print();
}