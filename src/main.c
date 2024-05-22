#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./sort/sort.h"

int main() {
    FILE *after = fopen("after.txt", "w");
    FILE *before = fopen("before.txt", "w");
    if(before == NULL || after == NULL){
        printf("Ошибка открытия файла\n");
        return 0;
    }
    printf("Введите степень двойки чтобы задать кол-во элементов: ");
    int k = 0;
    scanf("%d", &k);
    if(k < 0){
        printf("Неверные данные\n");
        return 0;
    }
    int n = 1 << k; // 2^15 = 32768 элементов
    int *arr_bubble = (int *)malloc(n * sizeof(int));
    int *arr_quick = (int *)malloc(n * sizeof(int));

    // Генерация случайной последовательности
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr_bubble[i] = rand() % 1000;
        arr_quick[i] = arr_bubble[i];
        fprintf(before, "%d\n", arr_bubble[i]);
    }

    // Тестирование пузырьковой сортировки
    clock_t start = clock();
    bubble_sort(arr_bubble, n);
    clock_t end = clock();
    printf("Время выполнения пузырьковой сортировки: %.6f секунд\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Тестирование быстрой сортировки
    start = clock();
    quick_sort(arr_quick, 0, n - 1);
    end = clock();
    printf("Время выполнения быстрой сортировки: %.6f секунд\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (int i = 0; i < n; i++){
        fprintf(after, "%d %d\n", arr_bubble[i], arr_quick[i]);
    }

    fclose(after);
    fclose(before);

    free(arr_bubble);
    free(arr_quick);
    return 0;
}
