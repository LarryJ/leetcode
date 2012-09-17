/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    struct myComp {
        bool operator() (const Interval a, const Interval b) {
            return a.start < b.start;
        }
    };

    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        myComp comp;
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> result;
        if(intervals.size() == 0)
            return result;
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start > end) {
                Interval newInterval(start, end);
                result.push_back(newInterval);
                start = intervals[i].start;
                end = intervals[i].end;
            } else {
                if (intervals[i].end > end)
                    end = intervals[i].end;
            }
        }
        Interval tmp(start, end);
        result.push_back(tmp);
        return result;
    }
};