class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        int cnt = 0;
        list1.add(1);
        if (rowIndex == 0)  return list1;
        for (int i = 1; i <= rowIndex; ++i) {
            cnt++;
            if (cnt % 2 == 1) {
                for (int j = 0; j <= i; ++j) {
                    if (j == 0 || j == i) {
                        list2.add(1);
                    } else {
                        list2.add(list1.get(j - 1) + list1.get(j));
                    }
                }
                list1.clear();
            } else {
                for (int j = 0; j <= i; ++j) {
                    if (j == 0 || j == i) {
                        list1.add(1);
                    } else {
                        list1.add(list2.get(j - 1) + list2.get(j));
                    }
                }
                list2.clear();
            }
        }
        return cnt % 2 == 0 ? list1 : list2;
    }
}

class Solution {
    public List<Integer> getRow(int rowIndex) {
        Integer[] pascal = new Integer[rowIndex + 1];
        pascal[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == i || j == 0) {
                    pascal[j] = 1;
                } else {
                    pascal[j] = pascal[j] + pascal[j - 1];
                }
            }
        }
        return Arrays.asList(pascal);
    }
}