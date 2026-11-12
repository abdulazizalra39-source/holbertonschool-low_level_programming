#include <stdio.h>

/**
 * clear_input - Discards the rest of the current input line
 */
void clear_input(void)
{
	int ch;

	ch = getchar();
	while (ch != '\n' && ch != EOF)
		ch = getchar();
}

/**
 * print_menu - Prints the calculator menu
 */
void print_menu(void)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
	printf("Choice: ");
}

/**
 * read_two - Reads two integers from the user
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Return: 1 on success, 0 on failure
 */
int read_two(int *a, int *b)
{
	printf("Enter a: ");
	if (scanf("%d", a) != 1)
		return (0);
	printf("Enter b: ");
	if (scanf("%d", b) != 1)
		return (0);
	return (1);
}

/**
 * calculate - Performs the chosen operation and prints the result
 * @choice: The menu choice (1 to 4)
 * @a: The first integer
 * @b: The second integer
 */
void calculate(int choice, int a, int b)
{
	if (choice == 1)
		printf("Result: %d\n", a + b);
	else if (choice == 2)
		printf("Result: %d\n", a - b);
	else if (choice == 3)
		printf("Result: %d\n", a * b);
	else if (b == 0)
		printf("Error: division by zero\n");
	else
		printf("Result: %d\n", a / b);
}

/**
 * main - Runs a simple calculator with a menu loop
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice, a, b;

	printf("Simple Calculator\n");
	while (1)
	{
		print_menu();
		if (scanf("%d", &choice) != 1)
		{
			if (feof(stdin))
			    break;
			clear_input();
			printf("Invalid choice\n");
			continue;
		}
		if (choice == 0)
			break;
		if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}
		if (!read_two(&a, &b))
		{
			clear_input();
			printf("Invalid input\n");
			continue;
		}
		calculate(choice, a, b);
	}
	printf("Bye!\n");
	return (0);
}
