#include <iostream>
#include <eigen3/Eigen/Dense>     /*Biblioteca de eigen, llamado desde el enlance simbolico*/

int main()
{
    /* Se hace uso de la biblioteca Eigen Dense */
    /* Se re quiere declarar una matriz double 2x2 */

    Eigen::Matrix2d matriz2d;

    /* Se llena la matriz con cualquier número */
    matriz2d << 2,3,4,0;
    std::cout << "Se presenta la matriz" << std::endl;
    std::cout << matriz2d << std::endl;

    return 0;
}
