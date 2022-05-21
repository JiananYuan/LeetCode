class TopVotedCandidate {
public:
    vector<int> times;
    // <time, winner>
    map<int, int> time_to_winner;
    // <winnner, score>
    map<int, int> winner_to_score;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this -> times.clear();
        this -> time_to_winner.clear();
        this -> winner_to_score.clear();
        int len = int(persons.size());
        int max_score = 0;
        int max_person = 0;
        for (int i = 0; i < len; i += 1) {
            int person = persons[i];
            int time = times[i];
            if (winner_to_score.count(person) == 0) {
                winner_to_score.insert(make_pair(person, 1));
            }
            else {
                winner_to_score[person] += 1;
            }
            if (max_score <= winner_to_score[person]) {
                max_score = winner_to_score[person];
                max_person = person;
            }
            time_to_winner.insert(make_pair(time, max_person));
        }
        this -> times.assign(times.begin(), times.end());
    }
    
    int q(int t) {
        int i = 0;
        int j = int(times.size()) - 1;
        int mid = 0;
        while (i <= j) {
            mid = (i + j) >> 1;
            if (times[mid] == t) {
                break;
            }
            else if (times[mid] > t) {
                j = mid - 1;
            }
            else if (times[mid] < t) {
                i = mid + 1;
            }
        }
        if (times[mid] != t && mid > 0 && times[mid] > t && times[mid - 1] <= t) {
            mid -= 1;
        }
        int floor_time = times[mid];
        return time_to_winner[floor_time];
    }
};

