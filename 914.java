class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int[] vis = new int[10005];
        for (int i = 0; i < deck.length; ++i) {
            vis[deck[i]]++;
        }
        int num = -1;
        for (int i = 0; i < 10005; ++i) {
            if (vis[i] == 0)    continue;
            if (num == -1)  num = vis[i];
            num = gcd(num, vis[i]);
        }
        return num > 1;
    }
    public int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}