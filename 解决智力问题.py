class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        @functools.lru_cache(None)
        def solve(t=0) :
            if t >= len(questions) :
                return 0
            points, brainpower = questions[t]
            return max(points+solve(t+brainpower+1), solve(t+1))
        
        return solve()

    
// dp：（C++）
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = int(questions.size());
        vector<long long> dp(n + 1);
        for (int i = 0; i < n; i += 1) {
            // do or not do
            dp[i + 1] = max(dp[i + 1], dp[i]);
            auto& qus = questions[i];
            int right_most = min(n, i + qus[1] + 1);
            dp[right_most] = max(dp[i] + qus[0], dp[right_most]);
        }
        return dp[n];
    }
};

