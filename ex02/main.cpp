/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:36:26 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/08 22:04:51 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av){
    if(ac < 2){
        std::cerr << "U need at least 2 elements" << std::endl;
    }
    else
    {
        std::vector<std::string> v;
        for (int i = 1; i < ac; i++)
        {
            v.push_back(av[i]);
        }
        for(int j = 0; j < ac - 1; j++)
            std::cout << v[j] << " ";
        std::cout << std::endl;
    }
}