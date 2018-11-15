class Solution {
    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, new LogComparator());
        return logs;
    }
}

class LogComparator implements Comparator<String> {
    @Override
    public int compare(String log1, String log2) {
        String[] word1 = log1.split(" ");
        String[] word2 = log2.split(" ");
        
        int firstSpaceIndex = log1.indexOf(' ');
        int secondSpaceIndex = log2.indexOf(' ');
        
        boolean isLetter1 = isLetter(word1);
        boolean isLetter2 = isLetter(word2);
        
        if (isLetter1 && isLetter2) {
            return log1.substring(firstSpaceIndex + 1).compareTo(log2.substring(secondSpaceIndex + 1));
        } else if (isLetter1 != isLetter2)  {
            return isLetter1 ? -1 : 1;
        }
        return 0;
    }
    public boolean isLetter(String[] word) {
        String judge = word[1];
        char ch = judge.charAt(0);
        if (Character.isLetter(ch)) return true;
        return false;
    }
}