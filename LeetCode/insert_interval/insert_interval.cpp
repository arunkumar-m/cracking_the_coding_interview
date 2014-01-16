/*
 * =====================================================================================
 *
 *       Filename:  insert_interval.cpp
 *
 *        Version:  1.0
 *        Created:  12/25/2013 17:51:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int x, int y) : start(x), end(y) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> v;
    int i = 0;
    int n = intervals.size();
    while (i < n && newInterval.start > intervals[i].end) {
        v.push_back(intervals[i]);
        i++;
    }
    while (i < n && newInterval.end >= intervals[i].start) {
        newInterval.start = min(intervals[i].start, newInterval.start);
        newInterval.end = max(intervals[i].end, newInterval.end);
        i++;
    }
    v.push_back(newInterval);
    while (i < n) {
        v.push_back(intervals[i]);
        i++;
    }
    return v;
}

void printIntervals(vector<Interval> &intervals) {
    for (int i = 0; i < intervals.size(); i++) {
        cout << "[" << intervals[i].start << "," << intervals[i].end << "],";
    }
    cout << endl;
}

int main() {
    vector<Interval> intervals;
    intervals.push_back(Interval(1,4));
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(7,8));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(12,16));
    Interval newInterval(5, 6);
    printIntervals(intervals);
    intervals = insert(intervals, newInterval);
    printIntervals(intervals);
}
