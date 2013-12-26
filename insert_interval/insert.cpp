/*
 * =====================================================================================
 *
 *       Filename:  insert.cpp
 *
 *        Version:  1.0
 *        Created:  12/25/2013 15:15:06
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
    // empty intervals
    if (intervals.size() == 0) {
        intervals.push_back(newInterval);
        return intervals;
    }
    // non-overlapping
    if (intervals[0].start > newInterval.end) {
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
    }
    for (int i = 0; i < intervals.size(); i++) {
        if ((i + 1 == intervals.size() && intervals[i].end < newInterval.start) || (i + 1 < intervals.size() && intervals[i].end < newInterval.start && intervals[i + 1].start > newInterval.end)) {
            intervals.insert(intervals.begin() + i + 1, newInterval);
            return intervals;
        }
    }
    // include
    for (int i = 0; i < intervals.size(); i++) {
        if (newInterval.start >= intervals[i].start && newInterval.end <= intervals[i].end) {
            return intervals;
        }
    }
    // overlap
    int begin = newInterval.start, end = newInterval.end;
    for (int i = intervals.size() - 1; i >= 0; i--) {
        if ((newInterval.start <= intervals[i].end && newInterval.end >= intervals[i].start) || (newInterval.end >= intervals[i].start && newInterval.start <= intervals[i].start)) {
            begin = min(begin, intervals[i].start);
            end = max(end, intervals[i].end);
            intervals.erase(intervals.begin() + i);
        }
    }
    // cout << begin << " " << end << endl;
    return insert(intervals, Interval(begin, end));
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
    intervals.push_back(Interval(7,8));
//    intervals.push_back(Interval(3,5));
//    intervals.push_back(Interval(6,7));
//    intervals.push_back(Interval(8,10));
//    intervals.push_back(Interval(12,16));
    Interval newInterval(5, 6);
    printIntervals(intervals);
    intervals = insert(intervals, newInterval);
    printIntervals(intervals);
    return 0;
}
