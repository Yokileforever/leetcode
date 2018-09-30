class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        int[] letter = new int[200];
        for (int i = 0; i < B.length; ++i) {
            int[] tmp = new int[200];
            for (int j = 0; j < B[i].length(); ++j) {
                tmp[B[i].charAt(j)]++;
            }
            for (int j = 'a'; j <= 'z'; ++j) {
                letter[j] = Math.max(letter[j], tmp[j]);
            }
        }
        List<String> list = new ArrayList<String>();
        for (int i = 0; i < A.length; ++i) {
            int[] tmp = new int[200];
            for (int j = 0; j < A[i].length(); ++j) {
                tmp[A[i].charAt(j)]++;
            }
            boolean f = true;
            for (int j = 'a'; j <= 'z'; ++j) {
                if (letter[j] > tmp[j]) f = false;
            }
            if (f)  list.add(A[i]);
        }
        return list;
    }
}