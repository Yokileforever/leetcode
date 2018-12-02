class Solution {
    public boolean isPalindrome(String s) {
        s = s.replaceAll("[^a-zA-Z0-9]", "");
        s = s.toLowerCase();
        System.out.println(s);
        StringBuffer sb = new StringBuffer(s);
        return sb.toString().equals(sb.reverse().toString());
    }
}