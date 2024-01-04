/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:57:38 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/04 09:54:43 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <ostream>
#include <ctime>

int is_valid_date(std::string year, std::string mounth, std::string day);
bool validateData(std::map<std::string, std::string>& data);
