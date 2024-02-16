#include <stdio.h>
#include <locale.h>

int write_file (FILE *f, int size, char array[]) // Запись в файл
{
	int i;
	for (i = 0; i < size; i++)
	{
		fprintf (f, "%c", array[i]);
	}
	return i;
}

int read_file (FILE *f, int size, char array[]) // Чтение файла
{
	int i;
	for (i = 0; i < size; i++)
	{
		fscanf (f, "%c", &array[i]);
	}
	return i;
}

int input_array (char array[]) // Считывание введенного массива
{
	int i = 0;
	char c;
	while ((c = getchar()) != '\n')
	{
		array[i] = c;
		i++;
	}
	return i;
}

char swap_ab (char c) // Замена а на b и A на B
{
	if (c == 'a')
	{
		return 'b';
	}
	if (c == 'b')
	{
		return 'a';
	}
	if (c == 'A')
	{
		return 'B';
	}
	if (c == 'B')
	{
		return 'A';
	}
}

void change_ab (int size, char array[]) // Замена а на b
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == 'a' || array[i] == 'b' || array[i] == 'A' || array[i] == 'B')
		{
			array[i] = swap_ab(array[i]);
		}
	}
	for (int i = 0; i < size; i++) // Печатаем массив
	{
		printf("%c", array[i]);
	}
}

int main (void)
{
	FILE *f;
	char array[100], *pa, *filename = "taskG5.txt";
	int n;
	pa = array;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	puts("Введите строку из маленьких и больших английских букв");
	printf("Данные на входе: ");
	n = input_array(pa);
	f = fopen(filename, "w+");
	write_file(f, n, pa);
	fclose(f);
	printf("Запись введенных данных в файл %s\n", filename);
	f = fopen(filename, "r");
	read_file(f, n, pa);
	fclose(f);
	printf("Данные на выходе: ");
	change_ab(n, pa);
	return 0;
}