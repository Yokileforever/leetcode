class RecentCounter {
    LinkedList<Integer> list;
    public RecentCounter() {
        list = new LinkedList<Integer>();
    }
    
    public int ping(int t) {
        while (!list.isEmpty() && list.getFirst() < t - 3000) {
            list.removeFirst();
        }
        list.add(t);
        return list.size() == 0 ? null : list.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */