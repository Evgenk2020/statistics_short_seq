#include <iostream>
#include "stat.h"

void help();
void info();
void data_run(std::vector<float> *put_data);

int main(int argc, char *argv[])
{
    const std::string k_help_one = "-h";
    const std::string k_help_two = "--help";
    const std::string k_info = "-i";
    const std::string k_data = "-d";
    std::string similar;

    if (argc >= 2)
    {
        similar = (std::string)argv[1];
    }

    if (argc == 2)
    {
        if (similar == k_help_one || similar == k_help_two)
        {
            help();
        }

        if (similar == k_info)
        {
            info();
        }
    }

    else if (argc >= 3 && similar == k_data)
    {
        std::vector<float> data;
        for (int i = 0; i < argc; i++)
        {
            if (i >= 2)
            {
                data.push_back(atof(argv[i]));
            }
        }

        data_run(&data);
    }

    else
    {
        std::cout << "error... use -h or --help for details" << std::endl;
    }

    return 0;
}

void help()
{
    std::cout << "*** Статистическая обработка ряда чисел ***" << std::endl
              << std::endl
              << "Использование: " << std::endl
              << "onerow -d [первое число] [второе число] ... [... число]" << std::endl
              << "onerow [-h|--help] для вызова справки" << std::endl
              << "onerow -i для просмотра дополнительной информации" << std::endl;
}

void info()
{

    std::cout << "Утилита позволяет определять показатели первичных статистических данных:" << std::endl
              << std::endl
              << "- Среднее арифметическое - число, равное сумме всех чисел множества, деленной на их количество" << std::endl
              << "  Является одной из мер центральной тенденции" << std::endl
              << std::endl
              << "- Среднее квадратическое - число, равное квадратному корню из среднего арифметического" << std::endl
              << "  квадратов данных чисел" << std::endl
              << std::endl
              << "- Дисперсия случайной величины - мера разброса значений случайной величины" << std::endl
              << "  относительно ее математического ожидания" << std::endl
              << std::endl
              << "- Среднеквадратическое отклонение - наиболее распространенный показатель рассеивания," << std::endl
              << "  равен квадратному корню из дисперсии. Среднеквадратическое отклонение можно считать мерой неопределенности" << std::endl
              << std::endl
              << "- Коэффициент вариации - это мера относительного разброса случайной величины" << std::endl
              << std::endl
              << "- Стандартная ошибка среднего - величина, характеризующая стандартное отклонение" << std::endl
              << "  выборочного среднего, рассчитанное по выборке размера n из генеральной совокупности" << std::endl
              << std::endl
              << "- Относительная ошибка средней величины - стандартная ошибка среднего" << std::endl;
}

void data_run(std::vector<float> *put_data)
{
    statistics stat(*put_data);

    std::cout << "Число элементов: " << stat.number << std::endl;
    std::cout << "Сумма чисел: " << stat.sum << std::endl;
    std::cout << "Среднее арифметическое: " << stat.average << std::endl;
    std::cout << "Среднее квадратическое: " << stat.root_mean_square << std::endl;
    std::cout << "Дисперсия: " << stat.dispersion << std::endl;
    std::cout << "Стандартное отклонение: " << stat.deviation << std::endl;
    std::cout << "Коэффициент вариации: " << stat.variation_co << std::endl;
    std::cout << "Ошибка средней величины: " << stat.mean_error << std::endl;
    std::cout << "Относительная ошибка средней величины: " << stat.relative_mean_error << std::endl;
}
