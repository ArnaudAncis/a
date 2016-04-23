#include "formats.h"
#include "grayscale_filter.h"
#include "blur_filter.h"
#include "composed_filter.h"
#include <iostream>
#include <string>
#include <list>

int main(int argc, char** argv)
{
	std::list<std::string> options;
	for (int i = 0; i < argc; ++i)
	{
		options.push_back(argv[i]);
	}

	if (options.size() < 3)
	{
		std::cerr << "Expected at least two arguments" << std::endl;
		// exit(-1);

		options.push_back("e:/temp/fountain.bmp");
		options.push_back("e:/temp/fountain2.bmp");
		options.push_back("blur");
		options.push_back("5");
	}

	options.pop_front();
	std::string input = options.front();
	options.pop_front();
	std::string output = options.front();
	options.pop_front();

	
	std::cout << "Input file: " << input << std::endl;
	std::cout << "Output file: " << output << std::endl;

	ComposedFilter filter;
	while ( !options.empty() )
	{
		std::string option = options.front();
		options.pop_front();

		if (option == "grayscale")
		{
			filter.add(std::make_shared<GrayscaleFilter>());
			std::cout << "Grayscale" << std::endl;
		}
		else if (option == "blur")
		{
			int distance = std::stoi(options.front());
			options.pop_front();
			filter.add(std::make_shared<BlurFilter>(distance));

			std::cout << "Blur with distance " << distance << std::endl;
		}
		else
		{
			std::cerr << "Unrecognised filter " << option << std::endl;
			exit(-1);
		}
	}

	std::cout << "Loading bitmap" << std::endl;
	Bitmap original = load_bitmap(input);

	std::cout << "Applying filters" << std::endl;
	auto result = filter.apply(original);

	std::cout << "Saving bitmap" << std::endl;
	save_bitmap(output, *result);
}