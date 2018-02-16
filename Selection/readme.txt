Readme - Selection

To run: just use run.sh with a txt file in the current directory with the appropriate format

Input file's format must be as follows:
    First line: Integer i representing the ith smallest value to find
    Second line: Array of integers with a single space between each element and no space at the end

    For example:
    7
    4 5 8 2 4 7 5 0 8 2 3 9 23 48 ­12 49

---------------------------------------------------------------------------------------------------

This problem is incomplete. All of the intended code is there and will run, but for some inputs, it may give incorrect output or cause an infinite loop/infinite recursion. I haven't been able to find a pattern to why some inputs work and some don't other than it appears to sometimes begin to skip over certain values in the input list.

My implementation is based off the pseudocode in the book for select (p.216) other than instead of using randomized_partition, it uses the partition algorithm on p.171 that's provided for quicksort. Finally, vectorElementSwap is a helper method I wrote to swap the values of 2 elements in a single vector.

I suspect the problem may be at the end of select in the last if/else block where it checks if the ith smallest is in the elements larger than/smaller than or equal to the pivot. In that first check, it almost appears as though pivotLocation should be the location checked, but trying that didn't help and moves further away from the book's pseudocode implementation.

If the code doesn't get stuck in an infinite loop/infinite recursion, the ith smallest value is written to the output file even though it may not be correct.
