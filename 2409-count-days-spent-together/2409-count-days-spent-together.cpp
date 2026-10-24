class Solution {
public:
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(countDays(arriveAlice), countDays(arriveBob));
        int end = min(countDays(leaveAlice), countDays(leaveBob));

        return max(0, end - start + 1);
    }

    int countDays(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        int dayCount = 0;

        for(int i = 0; i < month - 1; i++) {
            dayCount += days[i];
        }

        return dayCount + day;
    }
};