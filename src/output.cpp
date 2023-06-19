#include <iostream>
#include <fstream>
#include "output.h"

general_info::~general_info() {}

void help_info::see_info()
{
    std::cout << "*** Статистична обробка послідовного ряду ***" << std::endl
              << std::endl
              << "Для виводу в термінал" << std::endl
              << "onerow -d [перше_число] [друге_число] ... [наступне_число]" << std::endl
              << "Для виводу в файл" << std::endl
              << "onerow -df [перше_число] [друге_число] ... [наступне_число]" << std::endl
              << "Для довідки" << std::endl
              << "onerow [-h|--help]" << std::endl
              << "Для додаткової інформації" << std::endl
              << "onerow -i" << std::endl;
}

void inf_indo::see_info()
{
    std::cout << "Утиліта визначає показники первинних статистичних даних:" << std::endl
              << std::endl
              << "- Середнє арифметичне - число, що дорівнює сумі всіх чисел послідовності, поділеної на їх кількість" << std::endl
              << "  Є однією з мір центральної тенденції" << std::endl
              << std::endl
              << "- Середнє квадратичне - число, що дорівнює квадратному кореню з середнього арифметичного" << std::endl
              << "  квадратів чисел послідовності" << std::endl
              << std::endl
              << "- Дисперсія випадкової величини - міра розподілу значень випадкової величини" << std::endl
              << "  відносно її математичного очікування" << std::endl
              << std::endl
              << "- Середнє квадратичне відхилення - найбільш поширений показник розсіювання," << std::endl
              << "  дорівнює квадратному кореню з дисперсії. Середнє квадратичне відхилення можна вважати мірою невизначеності" << std::endl
              << std::endl
              << "- Коефіцієнт варіації - це міра відносного розподілу випадкової величиин" << std::endl
              << std::endl
              << "- Стандартна похибка середнього - величина, яка характеризує стандартне відхилення" << std::endl
              << "  вибіркового середнього, розрахована по виборці n із генеральної сукупності (+-)" << std::endl
              << std::endl
              << "- Відносна похибка середньої величини - стандартна похибка середньої" << std::endl;
}

//--------------------------------------------------

data_info::~data_info() {}

void screen_info::see_info(statistics *stat)
{

    std::cout << "Послідовність: ";
    for (auto data : stat->data)
    {
        std::cout << data << ' ';
    }
    std::cout << std::endl;

    std::cout << "Число елементів: " << stat->data.size() << std::endl;
    std::cout << "Сума чисел: " << stat->sum << std::endl;
    std::cout << "Середнє арифметичне: " << stat->average << std::endl;
    std::cout << "Середнє квадратичне: " << stat->root_mean_square << std::endl;
    std::cout << "Дисперсія: " << stat->dispersion << std::endl;
    std::cout << "Стандартне відхилення: " << stat->deviation << std::endl;
    std::cout << "Коефіцієнт варіації: " << stat->variation_co << std::endl;
    std::cout << "Похибка середньої величини: " << stat->mean_error << std::endl;
    std::cout << "Відносна похибка середньої величини: " << stat->relative_mean_error << std::endl;
}

void file_info::see_info(statistics *stat)
{
    std::ofstream writer("one-rstat.csv", std::ios::app);
    const std::string coma = ",";
    const char quo = '\"';

    std::locale m_loc("uk_UA.utf8");
    writer.imbue(m_loc);

    writer << "Послідовність: " << coma;
    for (auto data : stat->data)
    {
        writer << quo << data << quo << coma;
    }
    writer << std::endl;

    writer << "Число елементів:" << coma << quo << stat->data.size() << quo << std::endl;
    writer << "Сума чисел: " << coma << quo << stat->sum << quo << std::endl;
    writer << "Середнє арифметичне:" << coma << quo << stat->average << quo << std::endl;
    writer << "Середнє квадратичне: " << coma << quo << stat->root_mean_square << quo << std::endl;
    writer << "Дисперсія:" << coma << quo << stat->dispersion << quo << std::endl;
    writer << "Стандартне відхилення:" << coma << quo << stat->deviation << quo << std::endl;
    writer << "Коефіцієнт варіації:" << coma << quo << stat->variation_co << quo << std::endl;
    writer << "Похибка середньої величини:" << coma << quo << stat->mean_error << quo << std::endl;
    writer << "Відносна похибка середньої величини:" << coma << quo << stat->relative_mean_error << quo << std::endl;
    writer << "" << std::endl;

    std::cout << "Дані додані у файл one-rstat.csv" << std::endl;
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
