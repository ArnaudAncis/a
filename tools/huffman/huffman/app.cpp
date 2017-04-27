#include "frequency-table.h"
#include "huffman-tree.h"
#include <iostream>
#include <bitset>
#include <string>
#include <sstream>


std::string show(const std::vector<bool>& bits)
{
    std::stringstream ss;

    for (auto bit : bits)
    {
        ss << bit ? "1" : "0";
    }

    return ss.str();
}


int main()
{
    std::cout << "Enter a string: ";

    std::string string;
    std::cin >> string;
    std::cout << std::endl;

    FrequencyTable<char> ft = count(string);

    std::cout << "Frequencies" << std::endl;
    for (auto c : ft.elements())
    {
        std::cout << c << " " << ft[c] << std::endl;
    }
    std::cout << std::endl;

    auto tree = build_tree(ft);
    auto codes = tree->extract_codes();

    std::cout << "Codes" << std::endl;
    for (auto it : codes)
    {
        std::cout << it.first << " " << show(it.second) << std::endl;
    }
    std::cout << std::endl;

    std::vector<bool> encoding;
    for (auto c : string)
    {
        for (auto bit : codes[c])
        {
            encoding.push_back(bit);
        }
    }

    std::cout << "Encoding: " << show(encoding) << std::endl;
}
