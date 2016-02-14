#include <iostream>
#include <string>

int next_int();
std::string next_string();
double next_double();
void process_course();

void main()
{
    int n = next_int();

    for (int i = 0; i != n; ++i) process_course();
}

int next_int()
{
    int result;
    std::cin >> result;
    return result;
}

std::string next_string()
{
    std::string result;
    std::cin >> result;
    return result;
}

void process_course()
{
    std::string course_name = next_string();
    int grade_count = next_int();
    int total = 0;

    for (int i = 0; i != grade_count; ++i)
    {
        total += next_int();
    }

    double average = double(total) / grade_count;
    double rounded_average = ((int)((average + 0.005) * 100)) / 100.0;

    std::cout << course_name << " " << rounded_average << std::endl;
}
