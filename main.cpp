/***************************************************************
 * Fecha: 20 de agosto de 2022
 * Autor: Kevin Fabian Chepe.
 * Tema: Taller de Ejercicios usando EIGEN
 * Materia: Introducción a la HPC
 **************************************************************/

#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>

/* Se crean tipos de datos personalizados */
typedef Eigen::Matrix<float, 2, 2> mA;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> mAd;
typedef Eigen::Matrix<float, 2, 2> mB;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> mBd;
typedef Eigen::Matrix<float, 2, 2> mC;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> mCd;
typedef Eigen::Matrix<float, 2, 2> mX;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> mXd;



void ejercicio1(){
    mA A;
    mB B;
    mX X;
    //Se inicializa manualmente las matrices
    A << 4, -2, 1, -7;
    B << -1, 2, 6, -5;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;

    // Se realiza la operación de X = 3A - 4B
    X = (3*A.array()) - (4*B.array());
    std::cout << "\n Resultado de X = 3A - 4B: \n"<< X <<std::endl;
}

void ejercicio2(){
    mA A;
    mB B;
    mX X;
    //Se inicializa manualmente las matrices
    A<<0,-1,2,1;
    B<<1,2,3,4;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;

    // Se realiza la operación de 2X + 4A = 3BA, utlizando despeje
    // Despeje (X = (3*(A*B) - (4*A))/2))

    //Se multiplican las matrices A y B y se multiplica por 3 (X = (3 * (A*B)))
    X = ((B*A)*3);
    //Se multiplica la matriz A por 4 (4*A)
    A = (A.array()*4);
    //Se resta la matriz A menos la matriz X (X - A)
    X = X.array()-A.array();
    //Se divide en dos (X = X/2)
    X.array() /= 2;
    std::cout << "\n Resultado de 2X + 4A = 3BA: \n"<< X <<std::endl;
}

void ejercicio3(){
    mAd A(2,2);
    mBd B(2,2);
    mCd C(2,2);
    mXd X(2,2);
    //Se inicializa manualmente las matrices
    A<<-3,2,3,3;
    B<<5,3,9,4;
    C<<1,1,0,0;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;
    std::cout <<"\n  C  \n"<<C<< std::endl;

    // Se realiza la operación de (A*X*(B^T) = C), utlizando despeje
    // Despeje (X = C/A*(B^T)

    //Se multiplican las matrices, teniendo en cuenta que A y B son inversas para hacer bien la operación del despeje
    X = A.inverse()*C*B.inverse();
    std::cout << "\n Resultado de A*X*(B^T) = C: \n"<< X <<std::endl;
}

void ejercicio4(){
    mAd A(2,2);
    mBd B(2,2);
    mXd X(2,2);
    //Se inicializa manualmente las matrices
    A<<2,1,-4,-3;
    B<<2,2,6,4;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;

    // Se realiza la operación de (X*A = B), utlizando despeje
    // Despeje (X = B/A)

    //Se realiza la multiplicación de la inversa de A para no entrar en divisiones de matrices
    X = B*A.inverse();
    std::cout << "\n Resultado de X*A = B: \n"<< X <<std::endl;
}

void ejercicio5(){
    mAd A(2,3);
    mBd B(3,2);
    mCd C(2,2);
    mXd X(2,2);
    //Se inicializa manualmente las matrices
    A<<3,0,-1,0,2,1;
    B<<1,2,1,0,0,6;
    C<<-2,0,-2,-5;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;
    std::cout <<"\n  C  \n"<<C<< std::endl;

    // Se realiza la operación de (X = 2*(A*B + C))

    //Se realiza la multiplicación de de matriz A por B
    X = (A*B);

    //Se hace la suma de la anterior operacion mas la matriz C
    X = X.array()+ C.array();

    //Se multiplica el resultado por 2
    X = X.array() * 2;

    std::cout << "\n Resultado de X = 2*(A*B + C): \n"<< X <<std::endl;
}

void ejercicio6(){
    mAd A(3,3);
    mBd B(3,3);
    mXd X(3,3);
    //Se inicializa manualmente las matrices
    A<<1,5,-1,-1,2,2,0,-3,3;
    B<<-1,-4,3,1,-2,-2,-3,3,-5;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;

    // Se realiza la operación de (X = A +3*B)

    //Se realiza la multiplicación de 3 por B
    X = (3*B);

    //Se suma lo anterior a la matriz A
    X = X.array() + A.array();

    std::cout << "\n Resultado de X = A +3*B: \n"<< X <<std::endl;
}

void ejercicio7(){
    mAd A(3,3);
    mBd B(3,3);
    mXd X(3,3);
    //Se inicializa manualmente las matrices
    A<<2,7,3,3,9,4,1,5,3;
    B<<1,0,2,0,1,0,0,0,1;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;

    // Se realiza la operación de (XA = B)

    //Se realiza la multiplicación de matriz B por la inversa de A para no dividir las matrices
    X = B*A.inverse();

    std::cout << "\n Resultado de XA = B: \n"<< X <<std::endl;
}

void ejercicio8(){
    mAd A(3,3);
    mBd B(3,3);
    mXd X(3,3);
    //Se inicializa manualmente las matrices
    A<<1,1,1,6,5,4,13,10,8;
    B<<0,1,2,1,0,2,1,2,0;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;

    // Se realiza la operación de (AX = B)

    //Se realiza la multiplicación de matriz B inversa por la matriz de A para no dividir las matrices
    X = (B.inverse()*A).inverse();

    std::cout << "\n Resultado de AX = B: \n"<< X <<std::endl;
}

void ejercicio9(){
    mAd A(2,2);
    mXd X(2,2);
    //Se inicializa manualmente las matrices
    A<<3,-1,0,2;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;

    // Se realiza la operación de (X = A(^T)*A-2*A)

    //Se realiza la operación por partes y se opera exactamente igual a la formula
    X = (2*A);
    A = (A.transpose()*A);
    X = A - X;

    std::cout << "\n Resultado de X = A(^T)*A-2*A: \n"<< X <<std::endl;
}

void ejercicio10(){
    mAd A(2,2);
    mXd X(2,2);
    //Se inicializa manualmente las matrices
    A<<4,2,-1,0;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;

    // Se realiza la operación de (X =A^3)

    //Se multiplica la matriz tres veces para hallar el cubo de la matriz
    X = A * A * A;

    std::cout << "\n Resultado de X =A^3: \n"<< X <<std::endl;
}

void ejercicio11(){
    mAd A(2,2);
    mAd At(2,2);
    mBd B(2,2);
    mCd C(2,2);
    mXd X(2,2);
    //Se inicializa manualmente las matrices
    A<<2,4,3,2;
    B<<1,0,2,1;
    C<<7,5,6,1;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;
    std::cout <<"\n  C  \n"<<C<< std::endl;

    // Se realiza la operación de ((A^T)*X*B = C)

    //Se se saca la transpuesta de A
    At = A.transpose();

    //Se realiza la multiplicación la las tres matrics con sus respectivas inversas para evitar la división
    X = At.inverse()*C*B.inverse();

    std::cout << "\n Resultado de (A^T)*X*B = C: \n"<< X <<std::endl;
}

void ejercicio12(){
    mAd A(2,3);
    mBd B(3,2);
    mXd X(2,2);
    //Se inicializa manualmente las matrices
    A<<1,0,-2,2,-1,3;
    B<<2,-3,-2,0,-1,-2;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;

    // Se realiza la operación de (X = A*(A^T)-2*A*B)

    //Se realiza la multiplicacion de 2 por A y B
    B = 2*A*B;

    // Multiplica A por la transpuesta de la misma
    A = A*A.transpose();

    //Se realiza la operación con las variables que contienen los valores antes operados
    X = A - B;

    std::cout << "\n Resultado de X = A*(A^T)-2*A*B: \n"<< X <<std::endl;
}

void ejercicio13(){
    mAd A(1,3);
    mBd B(3,2);
    mCd C(2,1);
    mXd X(1,1);
    //Se inicializa manualmente las matrices
    A<<4,8,12;
    B<<3,2,0,1,-1,0;
    C<<3,-1;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;
    std::cout <<"\n  C  \n"<<C<< std::endl;

    // Se realiza la operación de (X = A*B*C)

    //Se realiza la multiplicacion de A por B y por C
    X = A*B*C;

    std::cout << "\n Resultado de X = A*B*C: \n"<< X <<std::endl;
}

void ejercicio14(){
    mAd A(3,3);
    mAd At(3,3);
    mBd B(3,3);
    mXd X(3,3);
    //Se inicializa manualmente las matrices
    A<<3,4,1,-1,-3,3,2,3,0;
    B<<3,9,7,1,11,7,7,5,7;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;

    // Se realiza la operación de ((A^T)*X = B)

    //Se halla la transpuesta de A

    //Se realiza la multiplicación de las inversas para evitar dividir
    X = B*A.transpose();

    std::cout << "\n Resultado de (A^T)*X = B: \n"<< X <<std::endl;
}

void ejercicio15(){
    mAd A(3,3);
    mBd B(3,3);
    mXd X(3,3);
    //Se inicializa manualmente las matrices
    A<<2,5,7,6,3,4,5,-2,-3;
    B<<-1,1,0,0,1,1,1,0,-1;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;

    // Se realiza la operación de (X*A = B)

    //Se realiza la multiplicación de la inversa de A por B para evitar dividir
    X = B*A.inverse();

    std::cout << "\n Resultado de X*A = B: \n"<< X <<std::endl;
}

void ejercicio16(){
    mAd A(4,4);
    mBd B(4,4);
    mXd X(4,4);
    //Se inicializa manualmente las matrices
    A<<1,1,1,1,1,1,-1,-1,1,-1,1,-1,1,-1,-1,1;
    B<<1,1,0,0,1,0,1,0,1,0,0,1,1,0,1,1;

    //Se imprimen las matrices
    std::cout <<"\n  A  \n"<<A<< std::endl;
    std::cout <<"\n  B  \n"<<B<< std::endl;

    // Se realiza la operación de (A*X = B)

    //Se realiza la multiplicación de la inversa de A por B para evitar dividir
    X = A.inverse()*B;

    std::cout << "\n Resultado de A*X = B: \n"<< X <<std::endl;
}

int main(){

    std::cout<<"--------------------Ejercicio (a)-------------------------------"<<std::endl;
    ejercicio1();
    std::cout<<"--------------------Ejercicio (b)-------------------------------"<<std::endl;
    ejercicio2();
    std::cout<<"--------------------Ejercicio (c)-------------------------------"<<std::endl;
    ejercicio3();
    std::cout<<"--------------------Ejercicio (d)-------------------------------"<<std::endl;
    ejercicio4();
    std::cout<<"--------------------Ejercicio (e)-------------------------------"<<std::endl;
    ejercicio5();
    std::cout<<"--------------------Ejercicio (f)-------------------------------"<<std::endl;
    ejercicio6();
    std::cout<<"--------------------Ejercicio (g)-------------------------------"<<std::endl;
    ejercicio7();
    std::cout<<"--------------------Ejercicio (h)-------------------------------"<<std::endl;
    ejercicio8();
    std::cout<<"--------------------Ejercicio (i)-------------------------------"<<std::endl;
    ejercicio9();
    std::cout<<"--------------------Ejercicio (j)-------------------------------"<<std::endl;
    ejercicio10();
    std::cout<<"--------------------Ejercicio (k)-------------------------------"<<std::endl;
    ejercicio11();
    std::cout<<"--------------------Ejercicio (l)-------------------------------"<<std::endl;
    ejercicio12();
    std::cout<<"--------------------Ejercicio (m)-------------------------------"<<std::endl;
    ejercicio13();
    std::cout<<"--------------------Ejercicio (n)-------------------------------"<<std::endl;
    ejercicio14();
    std::cout<<"--------------------Ejercicio (o)-------------------------------"<<std::endl;
    ejercicio15();
    std::cout<<"--------------------Ejercicio (p)-------------------------------"<<std::endl;
    ejercicio16();
    return 0;
}
