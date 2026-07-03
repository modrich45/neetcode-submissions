class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
        long long hours = 0;

        for (int bananas : piles) {
            hours += (bananas + k - 1) / k;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = 0;
        for (int bananas : piles)
            mx = max(mx, bananas);

        int low = 1, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canEat(piles, h, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};