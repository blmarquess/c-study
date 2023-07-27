// escreva um programa que captura o nome de uma pessoa e a idade dela e imprime no terminal um ola para esta pessoa

#include <iostream>
#include <string>

int main()
{
    struct person
    {
        std::string name;
        int age;
    };

    const int name_size = 50;
    char name[name_size];
    int age;

    std::cout << "Digite seu nome: ";
    std::cin.getline(name, name_size);

    std::cout << "Digite sua idade: ";
    std::cin >> age;

    const person person = {name, age};

    std::cout << "Ola " << person.name << ", voce tem " << person.age << " anos." << std::endl;

    return 0;
}
