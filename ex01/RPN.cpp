/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:20:56 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/06 15:21:01 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

float polish_calcul(float n1, float n2, char oper){
    if(oper == '+')
        return n1 + n2;
    else if(oper == '-'){
        return n1 - n2;
    }
    else if(oper == '/'){
        return n1 / n2;
    }
    else if(oper == '*'){
        return n1 * n2;
    }
    else
        return 0;   
}
void valid_argument(std::string av){
    for(size_t i = 0; i < av.length(); i++){
        if(!isdigit(av[i]) && av[i] != '+' && av[i] != '-' && av[i] != '*' && av[i] != '/'){
            std::cerr << "Invalid ARGUMENTS" << std::endl;
            exit(0);
        }
    }
}
std::string remove_spaces(std::string polish){
    std::string str = polish;
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;

}

float polish_parse(std::string av){
    std::stack<float> stack;
        for(size_t i  = 0; i < av.length(); i++){
            if(isdigit(av[i])){
                stack.push(av[i]- '0');
            }
            else{
                float num2  = stack.top();
                stack.pop();
                float num1  = stack.top();
                stack.pop();
                float result = polish_calcul(num1, num2, av[i]);
                stack.push(result);
            }
        }
        return stack.top();
}