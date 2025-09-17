#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

class FoodRatings {
    unordered_map<string, set<pair<int, string>>> cuisinesFood;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        const int n = foods.size();
        for (int i = 0; i < n; ++i) {
            cuisinesFood[cuisines[i]].insert({-ratings[i], foods[i]});
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int rating = foodToRating[food];
        cuisinesFood[cuisine].erase({-rating, food});
        cuisinesFood[cuisine].insert({-newRating, food});
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return (*cuisinesFood[cuisine].begin()).second;
    }
};

int main() {
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};
    FoodRatings* foodRatings = new FoodRatings(foods, cuisines, ratings);
    cout << foodRatings->highestRated("korean") << endl; // kimchi
    cout << foodRatings->highestRated("japanese") << endl; // ramen
    foodRatings->changeRating("sushi", 16);
    cout << foodRatings->highestRated("japanese") << endl; // sushi
    foodRatings->changeRating("ramen", 16);
    cout << foodRatings->highestRated("japanese") << endl; // ramen
}