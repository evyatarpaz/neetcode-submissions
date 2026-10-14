class Solution {

    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for(String s : strs){
            sb.append(s.length()).append('#').append(s);
        }
        return sb.toString();
    }

    public List<String> decode(String str) {
        List<String> res = new ArrayList<>();
        int n = str.length();
        if(n == 0) return res;
        int i = 0;
        while(i<n){
            int j = i;
            while(str.charAt(j) != '#'){
                j++;
            }
            int len = Integer.parseInt(str.substring(i,j));
            i = j+1;
            j = i + len;
            res.add(str.substring(i,j));
            i = j;
        }
        return res;
    }
}














