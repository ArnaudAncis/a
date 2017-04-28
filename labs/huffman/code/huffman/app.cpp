#include "frequency-table.h"
#include "huffman-tree.h"
#include <iostream>
#include <bitset>
#include <string>
#include <sstream>


void encode()
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
        std::cout << it.first << " " << it.second << std::endl;
    }
    std::cout << std::endl;

    Bits encoding;
    for (auto c : string)
    {
        encoding.concatenate(codes[c]);
    }

    std::cout << "Encoding: " << encoding << std::endl;
    std::cout << "Length: " << encoding.size() << std::endl;
}


int main()
{
    encode();
}
