#include <stdio.h>
#include <stdlib.h>

int MCS(int* nums, int i, int j)
{
	if (i == j)
		return nums[i];
	int middle = (i + j) / 2;
	int s1 = MCS(nums, i, middle);
	int s2 = MCS(nums, middle + 1, j);
	int max = nums[middle];
	int sum = nums[middle];
	int a1 = 0;
	for (int k = middle - 1; k >= i; k--)
	{
		sum += nums[k];
		if (sum > max)
			max = sum;
	}
	a1 += max;
	max = nums[middle + 1];
	sum = nums[middle + 1];
	for (int k = middle + 2; k <= j; k++)
	{
		sum += nums[k];
		if (sum > max)
			max = sum;
	}
	a1 += max;
	return s1 > s2 ? (s1 > a1 ? s1 : a1) : (s2 > a1 ? s2 : a1);
}

int maxSubArray(int* nums, int numsSize) {
	return MCS(nums, 0, numsSize - 1);
}

int main(void)
{
	int *numbers, size;
	printf("The size of array is: ");
	scanf("%d", &size);
	numbers = (int *)malloc(sizeof(int) * size);
	puts("Please input numbers: ");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &numbers[i]);
	}
	printf("Max Contiguous Subarray is: %d\n", maxSubArray(numbers, size));
	free(numbers);
	return 0;
}