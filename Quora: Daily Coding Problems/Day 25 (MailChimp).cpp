You are given an array representing the heights of neighboring buildings on a city street, from east to west.
The city assessor would like you to write an algorithm that returns how many of these buildings have a view of the setting sun,
in order to properly value the street.

For example, given the array [3, 7, 8, 3, 6, 1], you should return 3.
Since the top floors of the buildings with heights 8, 6, and 1 all have an unobstructed view to the west.

Can you do this using just one pass through the array?

```
/*
This function take input the arrary and the size of the array as n
This solution is O(n).
*/
int countView(int arr[], int n){
	int i,c=0,max_so_far=INT_MIN;
	for(i=n-1;i>=0;i--){
		if(arr[i]>max_so_far){
			c++;
			max_so_far=arr[i];
		}
	}
	return c;
}
```
