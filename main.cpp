/* *******************
 * File name : main.cpp
 * Author : Marcin Piotrowski
 * Created : 11.04.2015    21:04
 * Brief : This is main file, it includes main function.
 * *******************
 */


#include "mainwindow.h"
#include <QApplication>
#include <Eigen>


/*  Function
    *@brief This is main function.
    *@param int argc - number of arguments
    *@param char *argv[] - arguments
    *@retval int
    */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);   /** Create application **/
    MainWindow mainWindow;          /** Create main window **/
    mainWindow.show();              /** Show main window **/

    return app.exec();              /** Wait for application to end **/
}
