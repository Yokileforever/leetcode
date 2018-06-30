class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> mp;
        for (int i = 0; i < hand.size(); ++i) {
            mp[hand[i]]++;
        }
        int pre = -1;
        int arr[hand.size() + W];
        memset(arr, 0, sizeof(arr));
        int cards = 0;
        int i = 0;
        for (auto it: mp) {
            int key = it.first, value = it.second;
            cards -= arr[i];
            if (cards > 0 && pre != -1 && key - 1 != pre) return false;
            if (value < cards)  return false;
            arr[i + W] += value - cards;
            cards = cards + (value - cards);
            i++;
            pre = key;
        }
        cards -= arr[i];
        return cards == 0;
    }
};