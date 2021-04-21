/* File: database_handler.h
 *
 * Authors: Niilo Rannikko, Linnea Viitanen, Sami Naarminen, Mikko Tuovinen
 * Last changed: 18.4.2021
 * Course: Software Design, Spring 2021, mandatory group project
 *
 * Summary of this file:
 * Class for handling all external saving to and reading from files.
 */

#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H
#include <memory>

#include <QJsonObject>
#include <QString>
#include <memory>
#include <vector>
#include <string>
#include <QIODevice>

class Data_structures;

// default municipalities file
const QString DEFAULT_MUNICIPALITIES_FILE = ":/settings/municipalities.txt";

class Database_handler
{

public:

    Database_handler(std::shared_ptr<Data_structures> data_structures);

    /**
     * @brief load_data
     * @param file
     * @return
     */
    QString load_data(QString file);

    /**
     * @brief save_data
     * @param filename
     * @param parsedData
     * @return
     */
    bool save_data(QString filename, QString parsedData) const;
    //bool save_data(QString start_time, int data_type) const;

    /**
     * @brief read_municipalities
     * @return
     */
    std::vector<std::string> read_municipalities();

    bool save_to_file();

private:

    // Pointer to Data_structures object for related operations
    std::shared_ptr<Data_structures> data_structures_;

};

#endif // DATABASE_HANDLER_H
