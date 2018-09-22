class Solution {
    public List<Integer> grayCode(int n) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(0);
        if (n == 0) {
            return list;
        }
        int pre = 0;
        for (int i = 1; i < (1 << n); ++i) {
            if (i % 2 == 1) {
                pre = pre ^ 1;
            } else {
                int tmp = (pre) & (pre - 1);
                int real = pre - tmp;
                pre = pre ^ (real << 1);
            }
            list.add(pre);
        }
        return list;
    }
}

/** 
 * https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81
 * 求grey code两种方法
 * 直接排列: 对于第一项改变最右边的位元, 第二项改变右起第一个1左边的位元, 之后第三、第四项和前面一样反复
 * 镜射排列n位的gray code可以从n-1的grey code推理来!()[https://zh.wikipedia.org/wiki/File:Binary-reflected_Gray_code_construction.svg]
 */