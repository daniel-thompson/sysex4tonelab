/*
 * main.cpp
 *
 * Part of sysex4tonelab - A third party librarian for Vox Tonelab pedals
 *
 * Copyright (C) 2014 Daniel Thompson <daniel@redfelineninja.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */

#include <iostream>
#include <iterator>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    po::options_description desc("Allowed options");
    desc.add_options() // no semi-colon (uses functor chaining)
        ("help", "produce help message") //;
	("compression", po::value<double>(), "set compression level");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 0;
    }

    if (vm.count("compression")) {
        std::cout << "Compression level was set to "
             << vm["compression"].as<double>() << ".\n";
    } else {
        std::cout << "Compression level was not set.\n";
    }

    return 0;
}
