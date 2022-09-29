#include <iostream>
#include <string>
#include <numeric>

// Recibe un caracter para verificar si se encuentra en un rango
// de caracteres utilizando el codigo ascii
bool checkByAscii(const char character, const int begin, const int end)
{
    int asciiValue;
    asciiValue = int(character);
    return asciiValue >= begin && asciiValue <= end;
}

// Devuelve verdadero si el caracter ingresado en un numero
// Los numeros se encuenctran ubicados entre la posicion 48 y 57 del codigo ascii
bool isANumber(const char character)
{
    return checkByAscii(character, 48, 57);
}

// Devuelve verdadero si el caracter ingresado en una letra minuscula
// Las letras minusculas se encuenctran ubicadas entre la posicion 97
// y 122 del codigo ascii
bool isALowerCaseLetter(const char character)
{
    return checkByAscii(character, 97, 122);
}

// Devuelve verdadero si el caracter ingresado en una letra mayuscula
// Las letras mayusculas se encuenctran ubicadas entre la posicion
// 97 y 122 del codigo ascii
bool isAUpperCaseLetter(const char character)
{
    return checkByAscii(character, 65, 90);
}

// Devuelve verdadero si el caracter ingresado en una letra
// Incluyendo las minusculas y mayusculas
bool isALetter(const char character)
{
    return isALowerCaseLetter(character) || isAUpperCaseLetter(character);
}

// Recibe una cadena de caracteres y opera un predicado ingresado por parámetro
// Segun el resultado del predicado se aumenta en 1 el contador inicial
int myReduce(std::string data, int initValue, bool (*checkFunc)(char))
{
    for (int i = 0; i < data.length(); i++)
    {
        if (checkFunc(data[i]))
        {
            initValue = initValue + 1;
        }
    }

    return initValue;
}

// Realiza la misma funcion que el myReduce, pero en vez de un predicado,
// recibe un codigo ascii y aumenta el contador inicial si encuenta coincidencias
int countByASCII(std::string data, int asciiValue, int initValue)
{
    for (int i = 0; i < data.length(); i++)
    {
        if (checkByAscii(data[i], asciiValue, asciiValue))
        {
            initValue = initValue + 1;
        }
    }

    return initValue;
}

int countNumbers(std::string data)
{
    return myReduce(data, 0, &isANumber);
}

int countLetters(std::string data)
{
    return myReduce(data, 0, &isALetter);
}

int countChars(std::string data, char target)
{
    int amount;
    int asciiValue;

    amount = 0;
    asciiValue = int(target);

    amount = countByASCII(data, asciiValue, 0);

    if (isALetter(target))
    {
        int asciiComplement;

        asciiComplement = asciiValue > 90 ? asciiValue - 32 : asciiValue + 32;
        amount = countByASCII(data, asciiComplement, amount);
    }

    return amount;
}

int main()
{
    std::string data = "4$$Ee&95KPfjT$%TJ7#6T2%tcnS#3$^";

    // Exercise 1
    std::cout << "Cantidad de letras en la cadena: " << countNumbers(data) << std::endl;

    // Exercise 2
    std::cout << "Cantidad de digitos en la cadena: " << countLetters(data) << std::endl;

    // Exercise 3
    char input;

    std::cout << "Ingrese el digito a buscar coincidencias: " << std::endl;
    std::cin >> input;

    std::cout << "Cantidad de digitos en la cadena: " << countChars(data, input) << std::endl;

    return 0;
}