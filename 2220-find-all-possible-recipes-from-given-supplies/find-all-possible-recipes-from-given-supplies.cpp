class Solution {
public:

    vector<string> findAllRecipes(
        vector<string>& recipes,
        vector<vector<string>>& ingredients,
        vector<string>& supplies) {

        // ingredient -> recipes that depend on it
        unordered_map<string, vector<string>> graph;

        // Number of ingredients still required
        unordered_map<string, int> indegree;

        // Initially available supplies
        queue<string> q;

        for(auto s : supplies) {
            q.push(s);
        }

        // Build dependency graph
        for(int i = 0; i < recipes.size(); i++) {

            indegree[recipes[i]] = ingredients[i].size();

            for(auto ingredient : ingredients[i]) {

                graph[ingredient].push_back(recipes[i]);
            }
        }

        vector<string> ans;

        // Process available items
        while(!q.empty()) {

            string item = q.front();
            q.pop();

            // This item helps these recipes
            for(auto recipe : graph[item]) {

                indegree[recipe]--;

                // All ingredients are now available
                if(indegree[recipe] == 0) {

                    ans.push_back(recipe);

                    // Recipe itself becomes a new supply
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};