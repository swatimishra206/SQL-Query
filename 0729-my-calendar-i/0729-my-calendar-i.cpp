
class MyCalendar {
private:
    vector<pair<int, int>> events;

public:
    MyCalendar() {
    }

    bool book(int startTime, int endTime) {
        for (auto event : events) {
            int existingStart = event.first;
            int existingEnd = event.second;

            if (startTime < existingEnd &&
                endTime > existingStart) {
                return false;
            }
        }

        events.push_back({startTime, endTime});
        return true;
    }
};
