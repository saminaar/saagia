/* File: data_calculations.h
 *
 * Authors: Niilo Rannikko, Linnea Viitanen, Sami Naarminen, Mikko Tuovinen
 * Last changed: 18.4.2021
 * Course: Software Design, Spring 2021, mandatory group project
 *
 * Summary of this file:
 * Class for more complex calculations needed in the software.
 *
 */

#ifndef DATA_CALCULATIONS_H
#define DATA_CALCULATIONS_H

#include "data_structures.h"

#include <memory>
#include <map>
#include <vector>

#include <QString>

class Data_structures;

class Data_calculations
{

public:

    // Pointer to Data_structures object for related operations
    Data_calculations(std::shared_ptr<Data_structures> data_structures);

    /**
     * @brief average_temp_of_month: Calculates average average-, minimum and
     * maximum temperatures of given month
     * @param month: Desired month
     * @param year: Desired year
     * @return: vector with average average, average minimum and average
     * maximum temps
     */
    std::vector<float> average_temp_of_month(int month, int year);

    /**
     * @brief percentage_of_all_energy_prod
     * @param energy_type
     * @return percentage
     */
    float percentage_of_all_energy_prod(int energy_type);

private:

    //Pointer to Data_structures object for accessing data
    std::shared_ptr<Data_structures> data_structures_;

};

#endif // DATA_CALCULATIONS_H
