#include <iostream>
#include <string>
using namespace std;

class Time {
    private:
        int seconds;

    public:

    explicit Time(int seconds) :
        seconds(seconds)
    {}

    string convert_to_minutes() {
        string result;

        int minutes = seconds / 60;
        int seconds = this->seconds % 60;

        result += to_string(minutes);
        result += ":";
        result += to_string(seconds);
        return result;
    }

    string convert_to_hours() {
        string result;

        int hours = seconds / 3600;
        int minutes = (seconds % 3600) / 60;
        int seconds = this->seconds % 60;

        result += to_string(hours);
        result += ":";
        result += to_string(minutes);
        result += ":";
        result += to_string(seconds);
        return result;
    }
};

int main() {
    Time time(230);
    cout << time.convert_to_minutes() << endl;
    cout << time.convert_to_hours() << endl;
}