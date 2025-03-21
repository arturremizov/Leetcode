#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, bool> canCook;
        for (string supply : supplies) {
            canCook[supply] = true;
        }
 
        unordered_map<string, int> recipeToIndex;
        for (int i = 0; i < recipes.size(); ++i) {
            recipeToIndex[recipes[i]] = i;
        }

        vector<string> result;
        for (string recipe : recipes) {
            if (dfs(recipe, recipeToIndex, canCook, ingredients)) {
                result.push_back(recipe);
            }
        }
        return result;
    }
private:
    bool dfs(string recipe,
             unordered_map<string, int>& recipeToIndex,
             unordered_map<string, bool>& canCook,
             vector<vector<string>>& ingredients) {

        if (canCook.count(recipe)) 
            return canCook[recipe];

        canCook[recipe] = false;
        if (!recipeToIndex.count(recipe)) return false;
        
        for (string ingredient : ingredients[recipeToIndex[recipe]]) {
            if (!dfs(ingredient, recipeToIndex, canCook, ingredients)) {
                return false;
            }
        }
        canCook[recipe] = true;
        return true;
    }
};

int main() {
    Solution solution; 
    vector<string> recipes = {"bread","sandwich","burger"};
    vector<vector<string>> ingredients = {{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}};
    vector<string> supplies = {"yeast","flour","meat"};
    vector<string> result = solution.findAllRecipes(recipes,ingredients,supplies); //"bread","sandwich","burger"
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}