/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:36:26 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/09 13:22:44 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int check_isnumber(char **av){
    for(int check = 1; av[check]; check++){
        for(int i = 0; av[check][i]; i++){
            if (!isdigit(av[check][i])){
                std::cerr << "Error: bad input => " << av[check] << std::endl;
                return 0;
            }
        }
    }
    return 1;
}

int main(int ac, char **av){
    if(ac < 2){
        std::cerr << "U need at least 2 elements" << std::endl;
    }
        if (!check_isnumber(av))
            return 0;
        std::vector<std::vector<int> > main_v;
        for(int i = 1; i < ac; i++){
            std::vector<int> vectored;
            int num = std::atoi(av[i]);
            vectored.push_back(num);
            main_v.push_back(vectored);
        }

        for(size_t i = 0; i < main_v.size(); i++){
            std::cout << main_v[i][0] << " ";
        }
        std::cout << std::endl;
}