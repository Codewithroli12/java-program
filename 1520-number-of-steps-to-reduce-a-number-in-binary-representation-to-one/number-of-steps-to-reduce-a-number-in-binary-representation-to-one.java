class Solution {
    public int numSteps(String s) {
        int steps = 0;
        int carry = 0;

        // Start from rightmost bit and move left (ignore MSB at index 0)
        for (int i = s.length() - 1; i > 0; i--) {
            int bit = s.charAt(i) - '0';
            
            if (bit + carry == 1) {
                // Odd → +1 step for add operation
                // +1 step for divide
                steps += 2;
                carry = 1;
            } else {
                // Even → just divide by 2
                steps += 1;
            }
        }

        // If carry remains, we need one final step
        return steps + carry;
    }
}