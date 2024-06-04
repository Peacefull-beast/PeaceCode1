class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        map<int, int> timestamp;

        // Collecting all the events (pickup and dropoff)
        for (const auto& trip : trips) 
        {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];
            timestamp[start] += passengers;  // passengers getting on
            timestamp[end] -= passengers;    // passengers getting off
        }

        int currentPassengers = 0;

        // Iterate over all events in sorted order of locations
        for (const auto& [point, change] : timestamp) 
        {
            currentPassengers += change;
            if (currentPassengers > capacity)
                return false;
        }

        return true;
    }
};
