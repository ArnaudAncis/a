#include "formats.h"
#include "filters.h"
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
		options.push_back("mosaic");
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
		else if (option == "invert")
		{
			filter.add(std::make_shared<InvertFilter>());

			std::cout << "Invert" << std::endl;
		}
		else if (option == "hflip")
		{
			filter.add(std::make_shared<HorizontalFlipFilter>());

			std::cout << "Horizontal flip" << std::endl;
		}
		else if (option == "vflip")
		{
			filter.add(std::make_shared<VerticalFlipFilter>());

			std::cout << "Vertical flip" << std::endl;
		}
		else if (option == "red")
		{
			filter.add(std::make_shared<RedFilter>());

			std::cout << "Red filter" << std::endl;
		}
		else if (option == "green")
		{
			filter.add(std::make_shared<GreenFilter>());

			std::cout << "Green filter" << std::endl;
		}
		else if (option == "blue")
		{
			filter.add(std::make_shared<BlueFilter>());

			std::cout << "Blue filter" << std::endl;
		}
		else if (option == "mosaic")
		{
			int size = std::stoi(options.front());
			options.pop_front();
			filter.add(std::make_shared<MosaicFilter>(size));

			std::cout << "Mosaic with size " << size << std::endl;
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