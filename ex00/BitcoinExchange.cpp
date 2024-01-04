/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:26:15 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/04 09:39:46 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int is_valid_date(std::string year, std::string mounth, std::string day){
    int y = std::stoi(year);
    int m = std::stoi(mounth);
    int d = std::stoi(day);

    std::time_t currentTime = std::time(nullptr);
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