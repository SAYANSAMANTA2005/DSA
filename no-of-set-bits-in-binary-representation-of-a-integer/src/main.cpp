int countOnes(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1); // Check the least significant bit
        n >>= 1;          // Right-shift to process the next bit
    }
    return count;
}