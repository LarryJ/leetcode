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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<Interval> result;
		if(intervals.size() == 0) {
			result.push_back(newInterval);
			return result;
		}
		int startPlace = -1;
		int endPlace = -1;
		// find the position of newInterval.start
		if(newInterval.start >= intervals[0].start) {
			for(int i = 0; i < intervals.size() - 1; i++) {
				if(newInterval.start >= intervals[i].start && newInterval.start < intervals[i + 1].start) {
					startPlace = i;
					break;
				}
			}
			if(startPlace == -1) {
				startPlace = intervals.size() - 1;
			}
		}
		// find the position of newInterval.end
		if(newInterval.end >= intervals[0].start) {
			for(int i = 0; i < intervals.size() - 1; i++) {
				if(newInterval.end >= intervals[i].start && newInterval.end < intervals[i + 1].start) {
					endPlace = i;
					break;
				}
			}
			if(endPlace == -1) {
				endPlace = intervals.size() - 1;
			}
		}
		if(startPlace == -1) {
			if(endPlace == -1) {
				result.push_back(newInterval);
				return result;
			} else {
				if(newInterval.end <= intervals[endPlace].end) {
					interval inter(newInterval.start, intervals[endPlace].end);
					result.push_back(inter);
					for(int i = endPlace + 1; i < intervals.size(); i++) {
						result.push_back(intervals[i]);
					}
					return result;
				} else {
					result.push_back(newInterval);
					for(int i = endPlace + 1; i < intervals.size(); i++) {
						result.push_back(intervals[i]);
					}
					return result;
				}
			}
		} else {
			for(int i = 0; i <= startPlace - 1; i++) {
				result.push_back(intervals[i]);
			}
			if(newInterval.start > intervals[startPlace].end) {
				result.push_back(intervals[startPlace]);
				if(newInterval.end <= intervals[endPlace].end) {
					interval inter(newInterval.start, intervals[endPlace].end);
					result.push_back(inter);
				} else {
					result.push_back(newInterval);
				}
			} else {
				if(newInterval.end <= intervals[endPlace].end) {
					interval inter(intervals[startPlace].start, intervals[endPlace].end);
					result.push_back(inter);
				} else {
					interval inter(intervals[startPlace].start, newInterval.end);
					result.push_back(inter);
				}
			}
			for(int i = endPlace + 1; i < intervals.size(); i++) {
					result.push_back(intervals[i]);
			}
			return result;
		}
    }
};