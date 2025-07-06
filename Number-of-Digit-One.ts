let digits: number[] = Array(12).fill(0);
let memo: number[][] = Array.from(Array(12), () => Array(12).fill(-1));

// This function calculates the number of digit '1's that appear when counting from 1 to the given number n.
function countDigitOne(n: number): number {
    let length = 0; // Initialize the length to store the number of digits in n.
    // Store the digits of n in reverse order.
    while (n > 0) {
        digits[++length] = n % 10; // Store the last digit of n.
        n = Math.floor(n / 10); // Remove the last digit from n.
    }
    // Reset the memoization array to -1 for each new computation.
    memo = Array.from(Array(12), () => Array(12).fill(-1));
    return dfs(length, 0, true); // Start the depth-first search from the most significant digit.
}

// This function uses depth-first search to count the number of occurrences of the digit '1'.
function dfs(pos: number, count: number, limit: boolean): number {
    if (pos <= 0) {
        return count; // Base case: If all positions are traversed, return the count of '1's.
    }
    if (!limit && memo[pos][count] !== -1) {
        return memo[pos][count]; // If we are not at the limit and we have a memoized result, return it.
    }
    let ans = 0; // Initialize the answer for the current recursion level.
    let upperBound = limit ? digits[pos] : 9; // Determine the upper bound for the current digit.
    // Enumerate possibilities for the current digit.
    for (let i = 0; i <= upperBound; ++i) {
        // Calculate the count of '1's for the next position, updating count if the current digit is '1'.
        ans += dfs(pos - 1, count + (i === 1 ? 1 : 0), limit && i === upperBound);
    }
    if (!limit) {
        memo[pos][count] = ans; // If not at the limit, memoize the result.
    }
    return ans; // Return the computed answer for the current digit position.
}
