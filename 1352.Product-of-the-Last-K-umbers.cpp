#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
    vector<int> prefixProduct;
public:
    ProductOfNumbers() {}
        
    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();
        } else if (prefixProduct.empty()) {
            prefixProduct.push_back(num);
        } else {
            int prevNum = prefixProduct.back();
            prefixProduct.push_back(prevNum * num);
        }
    }
        
    int getProduct(int k) {
        int size = prefixProduct.size();
        if (k > size) return 0;
        if (k == size) return prefixProduct.back();
        return prefixProduct.back() / prefixProduct[size - k - 1];
    }
};

int main() {
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);
    productOfNumbers.add(0);       
    productOfNumbers.add(2);         
    productOfNumbers.add(5);         
    productOfNumbers.add(4);         
    cout << productOfNumbers.getProduct(2) << endl; // 20
    cout << productOfNumbers.getProduct(3) << endl; // 40
    cout << productOfNumbers.getProduct(4) << endl; // 0
    productOfNumbers.add(8);         
    cout << productOfNumbers.getProduct(2) << endl; // 32
}