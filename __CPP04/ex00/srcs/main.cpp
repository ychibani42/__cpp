/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:59:55 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/05 14:23:21 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog_class.hpp"
#include "Cat_class.hpp"
#include "Animal_class.hpp"

int main()
{
	std::cout << "CAT - DOG - ANIMAL TESTS" << std::endl << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;	
	std::cout << meta->getType() << " " << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "WRONGCAT - WRONGANIMAL TESTS" << std::endl << std::endl;
	
	const WrongAnimal* meta_bis = new WrongAnimal();
	const WrongAnimal* i_bis = new WrongCat();

	std::cout << i_bis->getType() << " " << std::endl;
	std::cout << meta_bis->getType() << " " << std::endl;

	i_bis->makeSound();
	meta_bis->makeSound();

	delete i_bis;
	delete meta_bis;

	return 0;
}


