/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:57:38 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/04 13:28:43 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <ostream>
#include <ctime>

int is_valid_date(std::string year, std::string mounth, std::string day);
void validateData(std::multimap<std::string, std::string>& data);
void Calculat_Bitcoin_value(std::multimap<std::string, std::string>& data, std::multimap<std::string, std::string>& data2);
