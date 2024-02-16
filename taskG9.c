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

void remove_space (int size, char array[]) // Удаление пробелов
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] != ' ')
		{
			array[j++] = array[i];
		}
	}
	array[j] = '\0';
}

void remove_the_same (int size, char array[]) // Удаление повторяющихся символов
{
	int counter = 1;
	for (int i = 1; i < size; i++) 
	{
		int j;
		for (j = 0; j < counter; j++)
		{
			if (array[i] == array[j])
			{
				break;
			}
		}
		if (j == counter)
		{
			array[counter] = array[i];
			counter++;
		}
	}
	array[counter] = '\0';
	for (int i = 0; i < counter; i++)
	{
		printf("%c", array[i]); // Печатаем массив
	}
}

int main (void)
{
	FILE *f;
	char array[1000], *pa, *filename = "taskG9.txt";
	int n;
	pa = array;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	puts("Введите строку из меленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 сивмолов.");
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
	remove_space(n, pa);
	remove_the_same(n, pa);
	printf("\nЗапись измененных данных в файл taskG9new.txt");
	f = fopen("taskG9new.txt", "w+");
	write_file(f, n, pa);
	fclose(f);
	return 0;
}