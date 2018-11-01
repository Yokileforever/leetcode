class Solution {
    public int numUniqueEmails(String[] emails) {
        HashMap map = new HashMap<String, Integer>();
        for (String email : emails) {
            String tmpA = "", tmpB = "";
            boolean f = false, isPlus = false;
            for (int j = 0; j < email.length(); ++j) {
                if (email.charAt(j) == '@')    f = true;
                if (f == false) {
                    if (email.charAt(j) == '.')    continue;
                    if (email.charAt(j) == '+')  isPlus = true;
                }
                if (f == false && isPlus == true)  continue;
                if (f == false)
                    tmpA = tmpA + email.charAt(j);
                else
                    tmpB = tmpB + email.charAt(j);
            }
            map.put(tmpA + tmpB, 1);
        }
        return map.size();
    }
}