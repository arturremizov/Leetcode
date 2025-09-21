#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class MovieRentingSystem {
    unordered_map<int, set<pair<int, int>>> movieToShops; // movie -> (price, shop)
    vector<unordered_map<int, int>> shopToMovieAndPrice; // shop -> (movie -> price)
    set<tuple<int, int, int>> rentedMovies; // (price, shop, movie)
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        shopToMovieAndPrice.resize(n);
        for (vector<int>& entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            movieToShops[movie].insert({price, shop});
            shopToMovieAndPrice[shop][movie] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        for (auto [price, shop] : movieToShops[movie]) {
            result.push_back(shop);
            if (result.size() == 5) break;
        }   
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = shopToMovieAndPrice[shop][movie];
        movieToShops[movie].erase({price, shop});
        rentedMovies.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = shopToMovieAndPrice[shop][movie];
        movieToShops[movie].insert({price, shop});
        rentedMovies.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        for (auto [price, shop, movie] : rentedMovies) {
            result.push_back({shop, movie});
            if (result.size() == 5) break;
        }   
        return result;
    }
};

int main() {
    vector<vector<int>> entries = {{0,1,5}, {0,2,6}, {0,3,7}, {1,1,4}, {1,2,7}, {2,1,5}};
    MovieRentingSystem* movieRentingSystem = new MovieRentingSystem(3, entries);
    vector<int> searchRes1 = movieRentingSystem->search(1); // [1, 0, 2]
    cout << "[";
    for (int i = 0; i < searchRes1.size(); ++i) {
        cout << searchRes1[i];
        if (i < searchRes1.size() - 1) {
            cout << ",";
        }
    }
    cout << "]\n";
    
    movieRentingSystem->rent(0,1);
    movieRentingSystem->rent(1,2);

    vector<vector<int>> report = movieRentingSystem->report(); // [[0, 1], [1, 2]]
    for (int i = 0; i < report.size(); ++i) {
        cout << "[";
        for (int j = 0; j < report[i].size(); ++j) {
            cout << report[i][j];
            if (j < report[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i < report.size() - 1) {
            cout << ",";
        }
    }
    cout << "\n";

    movieRentingSystem->drop(1,2);

    vector<int> searchRes2 = movieRentingSystem->search(2); // [0, 1]
    cout << "[";
    for (int i = 0; i < searchRes2.size(); ++i) {
        cout << searchRes2[i];
        if (i < searchRes2.size() - 1) {
            cout << ",";
        }
    }
    cout << "]\n";
} 