class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();
        for (int i = 1; i <= numRows; ++i) {
            List<Integer> tmp = new ArrayList<Integer>();
            for (int j = 1; j <= i; ++j) {
                if (j == 1 || j == i) {
                    tmp.add(1);
                } else {
                    tmp.add(list.get(i - 2).get(j - 1) + list.get(i - 2).get(j - 2));
                }
            }
            list.add(tmp);
        }
        return list;
    }
}