#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h> 
#include "include/dirent.h"    // ��� ������ � ������������
#include <sys/stat.h>                           // ��� ������������ ������� �����
#include <locale.h>
#include <stdlib.h>
#include <time.h>

/// �������, ������������ ������ �����
int getFileSize(const char* file) {
    struct stat st;
    int full_size = 0;

    if (stat(file, &st) == 0) {
        // ���� ��� �����
        if ((st.st_mode & S_IFMT) == S_IFDIR)
            return -1;
        // ���� ������� ����
        else if ((st.st_mode & S_IFMT) == S_IFREG)
            return st.st_size;
        // ���� ���-�� ���� (�����, FIFO (����������� �����) � ��.)
        else
            return -2;
    }
}
//������ ������� � �������� ������
void getSizesFromDir(char* path, int* i) {
    struct dirent* cur_file;
    DIR* dir;
    char full_file_path[200];

    // ��������� ������� ����������
    dir = opendir(path);
    // ���� ������� ������� ����������
    if (dir) {
        // ��������� ����� ������ ���������� � ���������� cur_file, ���� ����� �� ��������
        while ((cur_file = readdir(dir)) != NULL) {
            // ���������� ��������� ����� ./ � ../
            // ���� �������� ������, ������������ �� . ��� .. - ���������� ��
            if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
                // �������� ���� � ����� ����������, ��������� ������ ����������� ����������,
                // ��������� ��� �������� (����� ��� �����)
                strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
                // �������� ������ ��� -1, ���� ��� �� ����, � ��������� �����
                int cur_file_size = getFileSize(full_file_path);
                if (cur_file_size >= 0)
                {
                    (*i)++;
                    // ��� ����� �������� ��� ��� � ������
                    //printf("\n%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
                }
                else if (cur_file_size == -1)
                    // ��� ��������� ����� �������� ���������� ���������� �����
                    getSizesFromDir(full_file_path, i);
            }
        }
        // �� �������� ������� ����������
        closedir(dir);
    }
}
//��������� ������� ���������� ������ � ������ �����
void GetMasDir(char* path, char** file_name, int* file_size, int n, int* save_n)
{
    struct dirent* cur_file;
    DIR* dir;
    char full_file_path[200];
    char tmp[200];

    // ��������� ������� ����������
    dir = opendir(path);
    // ���� ������� ������� ����������
    if (dir) {
        // ��������� ����� ������ ���������� � ���������� cur_file, ���� ����� �� ��������
        while ((cur_file = readdir(dir)) != NULL) {
            // ���������� ��������� ����� ./ � ../
            // ���� �������� ������, ������������ �� . ��� .. - ���������� ��
            if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
                // �������� ���� � ����� ����������, ��������� ������ ����������� ����������,
                // ��������� ��� �������� (����� ��� �����)
                strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
                // �������� ������ ��� -1, ���� ��� �� ����, � ��������� �����
                int cur_file_size = getFileSize(full_file_path);
                if (cur_file_size >= 0)
                {
                    n = *save_n;
                    file_size[n] = cur_file_size;
                    int j;
                    for (j = 0; cur_file->d_name[j] != '\0'; j++)
                    {
                        file_name[n][j] = cur_file->d_name[j];
                    }
                    file_name[n][j] = '\0';
                    n++;
                    *save_n = n;
                    // ��� ����� �������� ��� ��� � ������
                    //printf("\n%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
                    //printf("%s - %d (mas)", file_name[k - 1], file_size[k - 1]);
                }
                else if (cur_file_size == -1)
                {
                    // ��� ��������� ����� �������� ���������� ���������� �����
                    n = *save_n;
                    GetMasDir(full_file_path, file_name, file_size, *save_n, save_n);
                }
            }
        }
        // �� �������� ������� ����������
        n = *save_n;
        closedir(dir);
    }
}

void PrintMas(char** file_name, int* file_size, int i)
{
    printf("\n");
    for (int k = 0; k < i; k++)
    {
        printf("%s - %d B (%d kb)\n", file_name[k], file_size[k], file_size[k] / 1024);
    }
}

void SortVstavka(char** file_name, int* file_size, int i)
{
    for (int j = 1; j < i; ++j)
    {
        int k = j;
        while (file_size[k - 1] > file_size[k])
        {
            int tmps = file_size[k - 1];
            file_size[k - 1] = file_size[k];
            file_size[k] = tmps;

            char* tmpn = file_name[k - 1];
            file_name[k - 1] = file_name[k];
            file_name[k] = tmpn;
            k -= 1;
        }
    }
}

void SortShell(char** file_name, int* file_size, int n)
{
    int i, j, step;
    int tmps;
    char* tmpn;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmps = file_size[i]; tmpn = file_name[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmps < file_size[j - step])
                {
                    file_size[j] = file_size[j - step];
                    file_name[j] = file_name[j - step];
                }
                else
                    break;
            }
            file_size[j] = tmps; 
            file_name[j] = tmpn;
        }
}

void SortCounting(char** file_name, int* file_size, int n)
{
    int k;
    int sortedMassSIZE[2000] = {0};
    char sortedMassNAME[2000][200];
    for (int i = 0; i < n; i++)
    {
        k = 0;
        for (int j = 0; j < n; j++)
        {
            if (file_size[i] > file_size[j])
                k++;
        }
        sortedMassSIZE[k] = file_size[i];
        strcpy(sortedMassNAME[k], file_name[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (sortedMassSIZE[i] != 0)
        {
            file_size[i] = sortedMassSIZE[i];
            file_name[i] = sortedMassNAME[i];
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "");
    char path[200];
    int i = 0, sort, s = 1, time, save_n = 0;
    // ��������� ���� (�� ���� scanf_s ��� ������)
    printf("������� ���� � ��������: ");
    gets(path);
    getSizesFromDir(path, &i);

    do
    {
        int* file_size = (int*)malloc(i * sizeof(int*));
        char** file_name = (char**)malloc(i * sizeof(char*));
        for (int k = 0; k != i; k++)
        {
            file_name[k] = (char*)malloc(i* 2 * sizeof(char));
        }

        GetMasDir(path, file_name, file_size, save_n, &save_n);
        save_n = 0;
        printf("\n1. ������ ����� �������\n2. ������� ����� ����������\n3. ���������� ������ ������\n0. ����� �� ���������\n��� �����: ");
        scanf_s("%d", &sort);
        switch(sort)
        {
        case 1:
            printf("������� ���� � ��������: ");
            scanf("%s", &path);
            i = 0;
            getSizesFromDir(path, &i);
            break;
        case 2:
            printf("\n����� ��� ����������?\n1. ���������\n2. �����\n3. ���������\n0. ����� �� ���������\n����: ");
            scanf_s("%d", &s);
            switch (s)
            {
            case 1:
                time = clock();
                SortVstavka(file_name, file_size, i);
                PrintMas(file_name, file_size, i);
                time = clock() - time;
                printf("\n%d (ms)\n", time); break;
            case 2:
                time = clock();
                SortShell(file_name, file_size, i);
                PrintMas(file_name, file_size, i);
                time = clock() - time;
                printf("\n%d (ms)\n", time); break;
            case 3:
                time = clock();
                SortCounting(file_name, file_size, i);
                PrintMas(file_name, file_size, i);
                time = clock() - time;
                printf("\n%d (ms)\n", time); break;
            }break;
        case 3:
            PrintMas(file_name, file_size, i);
            break;
        case 0:
            s = 0;
            break;
        }
    } while (s != 0);
    return 0;
}