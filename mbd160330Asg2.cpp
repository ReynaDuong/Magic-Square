
/**
 * Magic Square
 * This program is to construct a magic square, which consists of N2 squares,
 * each of which contains a number from 1 through N2 such that the rows, columns,
 * and diagonals sum to the same thing
 *
 * The program asks user to enter an odd number and validate the input to only accept odd numbers
 * The program ends when the user enters 0
 * Then it prints the square and the sum of each row/ column or diagonal
 *
 * Input: Number greater than or equal to 3, or 0 to stop the program
 *
 * Output:  The magic square with n rows and n columns organized in rows- columns
 *          The sum of each row or column and diagonal
 *
 *
 * Written by Minh Duong (mbd160330) at The University of Texas at Dallas
 * starting January 22nd, 2017
 *
 * CS 1337. 009
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;


int getInt();
bool isInt(string);
void makeSquare(int **, int);
void displaySquare( int **, int);


int main()
{
    int num = 0; // number inputted

    /*
     * The loop keeps the program to keep asking for another number
     * until the user presses 0
     */
    do
    {
        // Get the number and validate the input
        num = getInt();
        // if the user enters 0, then break the loop and end the program
        if ( num == 0)
            break;

        // if the number entered is less than 3 or is an even number then skip the rest of the loop and
        // return to ask for another
        if ( num < 3 || (num % 2 == 0))
        {
            cout << "Invalid input" << endl;
            continue;
        }


        // create a dynamic array to hold the magic square and initialize it with 0
        int **magicSquare; // pointer to create the array
        magicSquare = new int*[num];
        /*
         * for each element in the new array, create an array of num elements
         */
        for(int i = 0; i < num; i++)
            magicSquare[i] = new int[num];

        // initialize with 0
        for ( int row = 0; row < num; row++)
        {
            for (int coll = 0; coll < num; coll++)
                magicSquare[row][coll] = 0;
        }


        // Construct the magic square
        makeSquare(magicSquare, num);


        // Display the square
        displaySquare(magicSquare, num);


        // The sum of each row, column
        int sum = 0; // sum of each row/column/diagonal

        sum = num * (num * num +1)/2; // the formula for the magic square
        cout << "The sum of each row, column and diagonal is " << sum << endl;


        // Free the memory held
        for(int i = 0; i < num; i++)
            delete [] magicSquare[i];

        delete [] magicSquare;
        magicSquare= nullptr;

        cout << endl;
    }
    while ( num != 0);

    return 0;
}



/**
 * This function gives the user instruction on which to enter
 * then it calls the function isInt() to check if the string is a number
 * If the user enters a number, then turn the string to an int and return that value
 * If not, then return -1
 *
 * @return an integer
 */
int getInt()
{
    string num;
    cout << " Please enter an odd number greater than or equal to 3(enter 0 to exit): " ;
    getline(cin, num);
    if ( isInt(num)) // if the user enters a proper number, then turn the string to an int, else return -1
        return atoi(num.c_str());
    else
        return -1;
}


/**
 * this function receives a string num as parameter and step through every characters
 * in the string to check if the string user enters is all-digit( a number) or not
 * and return true/ false if all characters are/ are not all-digit
 * @param num input from user
 * @return a boolean value
 */
bool isInt(string num)
{
    // step through each character of the string and check if it is a all-digit string
    for ( int iNum = 0; iNum < num.length(); iNum++)
    {
        if (!isdigit(num[iNum])) // if there is a character that is not digit, then return false
            return false;
    }
    return true; // if all characters are digits, then return true
}


/**
 * This function constructs the square by first put 1 in the middle of the first row
 * The following numbers will be filled in the upper and to the right
 * if there is no place, then put the number in the square under the original one
 * @param ptr : the pointer that hold the square
 * @param num : the number entered by user
 */
void makeSquare( int ** ptr, int num)
{
    int curCol = num/2 ; // the current column, starting with the the middle columns
    int curRow = 0; //the current row, starting with the middle of the first row


    /*
     * The loop counts from 1 to (num * num) and assign the value to the appropriate square in the large magic square
     * It first fill up the middle square of the first row with 1
     * Then it will determine the next square to fill up
     * if the next square that is calculated is already occupied
     * then the value will be assigned to the square right under the previous one
     */
    for( int count = 1; count <= (num* num); count ++)
    {
        // assign the value to the square
        ptr[curRow][curCol] = count;

        // formula for the next square
        int newRow; // the next row
        int newCol; // the next column

        // Calculate the next row, column
        newRow = (curRow - 1 + num) % num;
        newCol = (curCol + 1) % num;

         if (ptr[newRow][newCol] == 0) // if the square intended is not occupied
         {
             curCol = newCol;
             curRow = newRow;
         }
        else // if not, assign the value to the one under the current square
         {
            curRow = curRow +1;
         }
    }
}



/**
 * This function to to display the magic square in rows and columns
 * Each value in the square is printed in a space of 6 and left-jutified
 * @param ptr the array that holds the square
 * @param num number of elements for each row and column
 */
void displaySquare(int ** ptr, int num)
{
    /*
     * display the array in rows and columns
     * set a space of 6 minimum for each element and left-justified
     */
    for ( int row = 0; row < num ; row++ )
    {
        for (int collumn = 0; collumn < num; collumn++)
            cout << left << setw(6)<<ptr[row][collumn];
        cout << endl;
    }
}