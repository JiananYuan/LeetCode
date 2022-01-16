class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        @functools.lru_cache(None)
        def solve(t=0) :
            if t >= len(questions) :
                return 0
            points, brainpower = questions[t]
            return max(points+solve(t+brainpower+1), solve(t+1))
        
        return solve()
