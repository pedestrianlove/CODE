int fibonacci (int number)
{
	int* fib = malloc (sizeof(int) * number);
	for (int i = 0; i < number; i++)
		fib[i] = 0;
	
	int pivot = 0;
	while (pivot < number) {
		if (pivot == 1 || pivot == 2)
			fib[pivot] = 1;
		else
			fib[pivot] = fib[pivot-1] + fib[pivot-2];

		pivot ++;
	}

	// output
	for (int i = 0; i < number; i++)
		printf ("%d ", fib[i]);
	printf ("\n");
	free (fib);

	return 0;
}
