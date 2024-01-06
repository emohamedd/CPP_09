/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:27:58 by emohamed          #+#    #+#             */
/*   Updated: 2024/01/06 15:21:15 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stack>

float polish_calcul(float n1, float n2, char oper);
void valid_argument(std::string av);
std::string remove_spaces(std::string polish);
float polish_parse(std::string av);