void rotateMatrix(int mat[][N]) //inplace
{
    // Consider all squares one by one
    for (int x = 0; x < N / 2; x++) {
        // Consider elements in group
        // of 4 in current square
        for (int y = x; y < N - x - 1; y++) {
            // Store current cell in
            // temp variable
            int temp = mat[x][y];
 
            // Move values from right to top
            mat[x][y] = mat[y][N - 1 - x];
 
            // Move values from bottom to right
            mat[y][N - 1 - x]
                = mat[N - 1 - x][N - 1 - y];
 
            // Move values from left to bottom
            mat[N - 1 - x][N - 1 - y]
                = mat[N - 1 - y][x];
 
            // Assign temp to left
            mat[N - 1 - y][x] = temp;
        }
    }
}
void findNext(char number[], int n)
{
    int i, j;
 
    // I) Start from the right most digit and find the first digit that is
    // smaller than the digit next to it.
    for (i = n-1; i > 0; i--)
        if (number[i] > number[i-1])
           break;
 
    // If no such digit is found, then all digits are in descending order
    // means there cannot be a greater number with same set of digits
    if (i==0)
    {
        cout << "Next number is not possible";
        return;
    }
 
    // II) Find the smallest digit on right side of (i-1)'th digit that is
    // greater than number[i-1]
    int x = number[i-1], smallest = i;
    for (j = i+1; j < n; j++)
        if (number[j] > x && number[j] < number[smallest])
            smallest = j;
 
    // III) Swap the above found smallest digit with number[i-1]
    swap(&number[smallest], &number[i-1]);
 
    // IV) Sort the digits after (i-1) in ascending order
    sort(number + i, number + n);
 
    cout << "Next number with same set of digits is " << number;
 
    return;
}