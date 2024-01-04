/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:27:59 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/04 09:32:33 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(){
    int i = is_valid_date("20009", "1", "5");
    if (i == 0){
        std::cerr << "Invalid DATE" << std::endl;
        exit(1);
    }
}