class Solution {
    public boolean hasAlternatingBits(int n) {
        String b = Integer.toBinaryString(n);

        for (int i = 0; i < b.length() - 1; i++) {
            if (b.charAt(i) == b.charAt(i + 1)) {
                return false;
            }
        }

        return true;
    }
}
