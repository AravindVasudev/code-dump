#include <iostream>
#include <fstream>
#include <map>
#include "lib/json.hpp"

using json = nlohmann::json;

#define FILE "./scores.json"
const std::map<std::string, int> grade_vs_points = {
    {"S", 10},
    {"A", 9},
    {"B", 8},
    {"C", 7},
    {"D", 6},
    {"E", 5},
    {"U", 0}
};

// reads a file and returns it as JSON
json read_json_file(const std::string& file) {
    std::ifstream ifs(file);
    std::string filestr(
        (std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>())
    );

    return json::parse(filestr);
}

// this calculates total credits and grade point * credit total and returns a pair
std::pair<int, int> calculate_credit_sum(json sem) {
    int credits = 0;
    int grade_times_credit = 0;

    for (auto& it : sem) {
        const std::string key = it[0].get<std::string>();
        const int value = it[1].get<int>();

        credits += value;
        grade_times_credit += grade_vs_points.at(key) * value;
    }

    return std::pair<int, int>(grade_times_credit, credits);
}

double calculate_gpa(const std::pair<int, int>& credit_grade_credit) {
    const double gpa = credit_grade_credit.first / (double) credit_grade_credit.second;
    return std::round(gpa * 100) / 100.0;
}

json calculate_cgpa(json scores) {
    json gpas;
    std::pair<int, int> total_credit_grade_credit;
    int i = 0;

    for (auto& sem : scores) {
        const std::pair<int, int> credit_grade_credit = calculate_credit_sum(sem);

        gpas["GPAS"][i++] = calculate_gpa(credit_grade_credit);

        total_credit_grade_credit.first += credit_grade_credit.first;
        total_credit_grade_credit.second += credit_grade_credit.second;
    }

    gpas["CGPA"] = calculate_gpa(total_credit_grade_credit);

    return gpas;
}

int main() {
    std::cout << std::setw(4) << calculate_cgpa(read_json_file(FILE)) << std::endl;

    return 0;
}