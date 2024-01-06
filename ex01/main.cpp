/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:27:45 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/06 15:21:22 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "Invalid ARGUMENTS" << std::endl;
        return 0;
    }
    std::string polish = remove_spaces(av[1]);
    valid_argument(polish);
    std::cout << polish_parse(polish) << std::endl;
}