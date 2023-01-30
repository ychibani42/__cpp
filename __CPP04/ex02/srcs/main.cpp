/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:59:55 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/17 18:48:57 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

# define NBR_ANIMAL 10

int	main(void)
{
	Animal* tab[NBR_ANIMAL];

	for (int i = 0; i < NBR_ANIMAL; i++)
	{
		if ((i) < NBR_ANIMAL / 2)
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
	}

	std::cout << std::endl;

	for (int i = 0; i < NBR_ANIMAL; i++)
		std::cout << "This animal is a " << tab[i]->getType() << "." << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < NBR_ANIMAL; i++)
		delete (tab[i]);

	std::cout << std::endl;

	Animal* cat = new Cat();
	std::string s1 = "miouaaa";
	std::string s2 = "grrrrrr";
	/*
	**	Animal* newAnimal = new Animal();
	**	newAnimal->set_idea(2, s2);
	**	std::cout << "Idea n.2 is " << newAnimal->get_idea(2) << std::endl;
	*/

	cat->set_idea(2, s2);
	cat->set_idea(67, s1);
	cat->set_idea(33, s2);
	cat->set_idea(-123, s2);

	std::cout << "Idea n.2 is " << cat->get_idea(2) << std::endl;
	std::cout << "Idea n.67 is " << cat->get_idea(67) << std::endl;
	std::cout << "Idea n.33 is " << cat->get_idea(33) << std::endl;
	std::cout << "Idea n.1 is " << cat->get_idea(1) << std::endl;
	std::cout << "Idea n.123 is " << cat->get_idea(123) << std::endl;

	delete (cat);

	std::cout << std::endl;

	return (0);
}