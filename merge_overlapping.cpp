vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return intervals; // If there are 0 or 1 intervals, no merging needed

    sort(intervals.begin(), intervals.end()); // Sort the intervals based on their start points
    vector<vector<int>> output; // Vector to store the merged intervals
    output.push_back(intervals[0]); // Push the first interval to the output

    for (int i = 1; i < intervals.size(); i++) {
        if (output.back()[1] >= intervals[i][0]) {
            output.back()[1] = max(output.back()[1], intervals[i][1]); // Merge overlapping intervals
        } else {
            output.push_back(intervals[i]); // Add non-overlapping interval to the output
        }
    }
    return output;
}
// leetcode merge overlapping intervals