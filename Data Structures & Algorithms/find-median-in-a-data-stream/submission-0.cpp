class MedianFinder {
public:
    multiset<int> m;
    int size = 0;

    MedianFinder() {
    }

    void addNum(int num) {
        m.insert(num);
    }

    double findMedian() {
        size = m.size();

        if (size == 1) {
            return (double)(*m.begin());
        }

        int half = size / 2;

        if (size % 2 == 0) {
            auto it1 = next(m.begin(), half - 1);
            auto it2 = next(m.begin(), half);
            return ((double)(*it1) + (double)(*it2)) / 2.0;
        } else {
            auto it = next(m.begin(), half);
            return (double)(*it);
        }
    }
};
