#include <iostream>
#include "output.h"

void help();
void info();
void data_run(std::vector<float> *put_data);

int main(int argc, char *argv[])
{
    const std::string k_help_one = "-h";
    const std::string k_help_two = "--help";
    const std::string k_info = "-i";
    const std::string k_data = "-d";
    const std::string k_file = "-df";
    std::string similar;

    if (argc >= 2)
    {
        similar = (std::string)argv[1];
    }

    if (argc == 2)
    {
        if (similar == k_help_one || similar == k_help_two)
        {
            print_info inf(new help_info);
            inf._print();
        }

        if (similar == k_info)
        {
            print_info inf(new inf_indo);
            inf._print();
        }
    }

    else if (argc >= 3 && similar == k_data || argc >= 3 && similar == k_file)
    {
        std::vector<float> data;
        for (int i = 0; i < argc; i++)
        {
            if (i >= 2)
            {
                data.push_back(atof(argv[i]));
            }
        }

        if (similar == k_data)
        {
            print_info inf(new screen_info);
            inf._print(data);
        }

        if (similar == k_file)
        {
            print_info inf(new file_info);
            inf._print(data);
        }
    }

    else
    {
        std::cout << "error... use -h or --help for details" << std::endl;
    }

    return 0;
}