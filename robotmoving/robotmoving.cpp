int movingcount(int threshold, int rows, int cols)
{
	bool *visited = new bool[rows* cols];
	for (int i = 0; i< rows*cols; ++i)
	{
		/* code */
		visited[i] = false;
	}
	int count = movingcountcore(threshold, rows, cols,0,0, visited);
	delete [] visited;
	return count;
}

int movingcountcore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if(check(threshold, rows, cols, row, col, visited))
	{
		visited[row*cols+col] = true;
		count = 1 +  movingcountcore(threshold, rows, cols,row-1,col, visited)
			+  movingcountcore(threshold, rows, cols,row,col-1, visited)
			+  movingcountcore(threshold, rows, cols,row+1,col, visited)
			+  movingcountcore(threshold, rows, cols,row,col+1, visited);
	}
	return count;
}

bool check(int threshold, int rows, int cols, int row, int col, bool * visited){
	if(row > 0 && row < rows && col >= 0 && col < cols
		&& getDigitSum(row) + getDigitSum(row) <= threshold
		&& !visited[row*cols+col])
		return false;
}

int getDigitSum(int number){
	int sum = 0;
	while(number > 0){
		sum += number%10;
		number /= 10;
	}

	return sum;
}