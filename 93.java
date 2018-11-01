class Solution {
    public List<String> restoreIpAddresses(String s) {
        HashSet<String> hash = new HashSet();
        List<String> list = new ArrayList();
        dfs(s, 0, 0, hash, "");
        for (String x : hash) {
            list.add(x);
        }
        return list;
    }
    public void dfs(String s, int start, int cnt, HashSet<String> list, String ip) {
        if (cnt == 3) {
            String tmp = s.substring(start, s.length());
            if (!isAddress(tmp))    return;
            ip = ip + tmp;
            list.add(ip);
            return;
        }
        for (int i = start + 1; i < s.length(); ++i) {
            String tmp = s.substring(start, i);
            if (!isAddress(tmp))    break;
            dfs(s, i, cnt + 1, list, ip + tmp + ".");
        }
    }
    public boolean isAddress(String ip) {
        if (ip.length() > 3)    return false;
        if (ip.length() > 1 && ip.charAt(0) == '0') return false;
        if (Integer.parseInt(ip) > 255)    return false;
        return true;
    }
}