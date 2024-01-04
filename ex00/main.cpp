/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:59:35 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/04 13:28:35 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./bitcoin [input_file]" << std::endl;
        return 1;
    }
    std::ifstream file2(argv[1]);
    std::ifstream file("data.csv");
    if (!file2.is_open()) {
        std::cout << "Error opening " << argv[1] << std::endl;
        return 1;
    }
    if (!file.is_open()) {
        std::cout << "Error opening data.csv" << std::endl;
        return 1;
    }
    std::string line;
    std::string top;
    std::getline(file, top);
    std::getline(file, line);
    std::multimap<std::string, std::string> data;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, price;
        std::getline(ss, date, ',');
        std::getline(ss, price, ',');
        data.insert(std::make_pair(date, price));
    }


    std::string line2;
    std::string top2;
    std::getline(file2, top2);
    if (top2 != "date | value") {
        std::cout << "Error: " << argv[1] << " is not in the correct format" << std::endl;
        return 1;
    }

    std::multimap<std::string, std::string> data2;
    while (std::getline(file2, line2)) {
        std::stringstream ss(line2);
        std::string date, price;
        std::getline(ss, date, '|');
        std::getline(ss, price, '|');
        data2.insert(std::make_pair(date, price));
    }
    validateData(data2);
    Calculat_Bitcoin_value(data, data2);
    file2.close();
    file.close();
    return 0;
}   