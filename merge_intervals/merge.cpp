/*
 * =====================================================================================
 *
 *       Filename:  merge.cpp
 *
 *        Version:  1.0
 *        Created:  12/31/2013 20:45:51
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
    int len = intervals.size();
    if (len == 0) {
        intervals.push_back(newInterval);
        return intervals;
    }
    else {
        vector<Interval> ints;
        int index = 0;
        while (index < intervals.size() && intervals[index].end < newInterval.start) {
            ints.push_back(intervals[index]);
            index++;
        }
        while (index < intervals.size() && intervals[index].end >= newInterval.start && intervals[index].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[index].start);
            newInterval.end = max(newInterval.end, intervals[index].end);
            index++;
        }
        ints.push_back(newInterval);
        while (index < intervals.size() && intervals[index].start > newInterval.end) {
            ints.push_back(intervals[index]);
            index++;
        }
        return ints;
    }
}

vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> ints;
    for (int i = 0; i < intervals.size(); i++) {
        ints = insert(ints, intervals[i]);
    }
    return ints;
}

void printIntervals(vector<Interval> &intervals) {
    for (int i = 0; i < intervals.size(); i++) {
        cout << "[" << intervals[i].start << "," << intervals[i].end << "],";
    }
}

int main() {
    vector<Interval> intervals;
    intervals.push_back(Interval(2,3));
    intervals.push_back(Interval(3,7));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));
    intervals.push_back(Interval(0,1));
    intervals.push_back(Interval(20,30));
    vector<Interval> ints = merge(intervals);
    printIntervals(ints);
    return 0;
}
