#include <iostream>
#include <fstream>
#include "output.h"

general_info::~general_info() {}

void help_info::see_info()
{
    std::cout << "*** Статистическая обработка ряда чисел ***" << std::endl
              << std::endl
              << "Для вывода в терминал" << std::endl
              << "onerow -d [первое число] [второе число] ... [... число]" << std::endl
              << "Для вывода в файл" << std::endl
              << "onerow -df [первое число] [второе число] ... [... число]" << std::endl
              << "Для вывода справки" << std::endl
              << "onerow [-h|--help]" << std::endl
              << "Для просмотра дополнительной информации" << std::endl
              << "onerow -i" << std::endl;
}

void inf_indo::see_info()
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

//--------------------------------------------------

data_info::~data_info() {}

void screen_info::see_info(statistics *stat)
{

    std::cout << "Последовательность:";
    for (auto data : stat->data)
    {
        std::cout << data << ' ';
    }
    std::cout << std::endl;

    std::cout << "Число элементов: " << stat->data.size() << std::endl;
    std::cout << "Сумма чисел: " << stat->sum << std::endl;
    std::cout << "Среднее арифметическое: " << stat->average << std::endl;
    std::cout << "Среднее квадратическое: " << stat->root_mean_square << std::endl;
    std::cout << "Дисперсия: " << stat->dispersion << std::endl;
    std::cout << "Стандартное отклонение: " << stat->deviation << std::endl;
    std::cout << "Коэффициент вариации: " << stat->variation_co << std::endl;
    std::cout << "Ошибка средней величины: " << stat->mean_error << std::endl;
    std::cout << "Относительная ошибка средней величины: " << stat->relative_mean_error << std::endl;
}

void file_info::see_info(statistics *stat)
{
    std::ofstream writer("one-rstat.csv", std::ios::app);
    const std::string coma = ",";
    const char quo = '\"';

    std::locale m_loc("uk_UA.utf8");
    writer.imbue(m_loc);

    writer << "Последовательность: " << coma;
    for (auto data : stat->data)
    {
        writer << quo << data << quo << coma;
    }
    writer << std::endl;

    writer << "Число элементов:" << coma << quo << stat->data.size() << quo << std::endl;
    writer << "Сумма чисел: " << coma << quo << stat->sum << quo << std::endl;
    writer << "Среднее арифметическое:" << coma << quo << stat->average << quo << std::endl;
    writer << "Среднее квадратическое: " << coma << quo << stat->root_mean_square << quo << std::endl;
    writer << "Дисперсия:" << coma << quo << stat->dispersion << quo << std::endl;
    writer << "Стандартное отклонение:" << coma << quo << stat->deviation << quo << std::endl;
    writer << "Коэффициент вариации:" << coma << quo << stat->variation_co << quo << std::endl;
    writer << "Ошибка средней величины:" << coma << quo << stat->mean_error << quo << std::endl;
    writer << "Относительная ошибка средней величины:" << coma << quo << stat->relative_mean_error << quo << std::endl;
    writer << "" << std::endl;

    std::cout << "Данные добавлены в файл chlor-dada.csv" << std::endl;
}

//--------------------------------------------------

print_info::print_info(general_info *temp) : g_info(temp) {}
print_info::print_info(data_info *temp) : d_info(temp) {}

void print_info::_print() { g_info->see_info(); }
void print_info::_print(statistics stat) { d_info->see_info(&stat); }

print_info::~print_info()
{
    delete g_info;
    g_info = nullptr;

    delete d_info;
    d_info = nullptr;
}
