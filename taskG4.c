#include <stdio.h>
#include <locale.h>

int write_file (FILE *f, int size, char array[]) // Запись в файл
{
	for (int i = 0; i < size; i++)
	{
		fprintf (f, "%c", array[i]);
	}
	return i;
}

int read_file (FILE *f, int size, char array[]) // Чтение файла
{
	for (int i = 0; i < size; i++)
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

void find_the_same (int size, char array[]) // Поиск одинаковых букв в двух словах
{
	int i = 0, flag = 0, counter;
	while (i < size)
	{
		if (array[i] == ' ')
		{
			flag = i;
		}
		i++;
	}
	for (int i = 0; i < flag; i++)
	{
		counter = 0;
		for (int j = size - 1; j >= 0; j--)
		{
			if(array[i] == array[j])
			{
				counter++;
			}
		}
		if (counter == 2)
		{
			printf("%c ", array[i]);
		}
	}
}

int main (void)
{
	FILE *f;
	char array[100], *pa, *filename = "taskG4.txt";
	int n;
	pa = array;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	puts("Введите два слова из маленьких английских букв через пробел");
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
	find_the_same(n, pa);
	return 0;
}