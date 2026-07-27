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
            auto it1 = m.begin();
            auto it2 = m.begin();

            advance(it1, half - 1);
            advance(it2, half);

            return ((double)(*it1) + (double)(*it2)) / 2.0;
        } else {
            auto it = m.begin();
            advance(it, half);

            return (double)(*it);
        }
    }
};