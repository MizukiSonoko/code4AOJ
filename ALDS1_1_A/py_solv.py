#! /usr/bin/python

if __name__ == "__main__":
	n = int(raw_input())
	array = map(int, raw_input().split())
	for i in range(1, n):
		print " ".join(map(str, array))
		key = array[i]
		j = i - 1 
		while j >= 0 and array[j] > key:
			array[j+1] = array[j]
			j -= 1
		array[j+1] = key

	print " ".join(map(str, array))