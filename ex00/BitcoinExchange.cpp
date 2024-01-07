/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:26:15 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/07 15:33:35 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int is_valid_date(std::string year, std::string mounth, std::string day){
    int y = std::atoi(year.c_str());
    int m = std::atoi(mounth.c_str());
    int d = std::atoi(day.c_str());

    std::time_t currentTime = std::time(NULL);
    std::tm *localTime = std::localtime(&currentTime);
    int currentYear = localTime->tm_year + 1900;
    int currentMounth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;

    
    if (y < 2009)
        return 0;
    if (m < 1 || m > 12)
        return 0;
    if (d < 1 || d > 31)
        return 0;
    if (y > currentYear)
        return 0;
    if (y == currentYear){
        if (m > currentMounth)
            return 0;
        if (m == currentMounth && d > currentDay)
            return 0;
    }
    return 1;
}

bool validateData(std::multimap<std::string, std::string>::iterator it) {
        int length = it->first.size();
        if (it->first[length - 1] != ' ' || it->second[0] != ' ') {
            std::cerr << "Error: input.txt is not in the correct format" << std::endl;
            return false;
        }

        if (it->first.size() != 11 || it->first[4] != '-' || it->first[7] != '-') {
            std::cerr << "Error: input.txt is not in the correct format" << std::endl;
            return false;
        }

        for (size_t j = 0; j < it->first.length(); j++) {
            if (j == '-' || j == ' ') {
                j++;
            }

            if (isalpha(it->first[j])) {
                std::cerr << "Error: input.txt is not in the correct format" << std::endl;
                return false;
            }
        }
    
        for (size_t i = 0; i < it->second.length(); i++) {
            if (it->second[i] == ' ') {
                i++;
                if (isalpha(it->second[i]) || !isdigit(it->second[i])) {
                    std::cerr << "Error: input.txt is not in the correct format" << std::endl;
                    return false;
                }
                if (std::atof(it->second.c_str()) > 1000) {
                    std::cerr << "Error: input.txt is not in the correct format" << std::endl;
                    return false;
                }
            }
        }

        std::stringstream new_(it->first);
        std::string year, month, day;
        std::getline(new_, year, '-');
        std::getline(new_, month, '-');
        std::getline(new_, day, ' ');
        if (is_valid_date(year, month, day) == 0) {
            std::cerr << "Error: Invalid Date" << std::endl;
            return false;
        }
        return true;
    }


void Calculat_Bitcoin_value(std::multimap<std::string, std::string>& data, std::multimap<std::string, std::string>& data2){
    float Bitocoin_price = 0;
        for(std::multimap<std::string, std::string>::iterator it2 = data2.begin(); it2 != data2.end(); it2++) {
            std::string it2First = it2->first;
            if (!it2First.empty() && it2First[it2First.length() - 1] == ' ') {
                it2First.erase(it2First.length() - 1);
            }
            if (!validateData(it2)){
                continue;;
            }
            else
            {
                std::multimap<std::string, std::string>::iterator it = data.find(it2First);
                if(it->first == it2First){
                    Bitocoin_price = std::atof(it->second.c_str()) * std::atof(it2->second.c_str());
                    std::cout << it2->first << " => " << Bitocoin_price << std::endl;
                }
                else
                    std::cerr << "NOT FOUND" << std::endl;
            }
                
        }
    }