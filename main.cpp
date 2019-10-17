#include <iostream>
#include <cmath>
#include <stdio.h>
#include "main.h"



struct point gradient ( point solution )
{
    struct point result;
    result.x = 2*solution.x - 8;
    result.y = 2*solution.y + 16;
    result.z = 2*solution.z + 10;
    return result;
}

struct point vector_value ( point solution )
{
    struct point result;
    /*
    result.x = pow((solution.x-4), 2);
    result.y = pow((solution.y+8), 2);
    result.z = pow((solution.z+5), 2);
    */

    printf("vector value\n");
    return result;
}

double value ( point solution )
{
    double result;
    /*
    point vector_result;
    vector_result = vector_value( solution );
    result = vector_result.x + vector_result.y + vector_result.z;
    return result;
     */

    result = pow( (solution.x-4), 2) + pow((solution.y+8), 2) + pow((solution.z+5), 2);

    //result = pow( ( pow(solution.x,2) + solution.y - 11 ),2 ) + pow( ( solution.x + pow(solution.y, 2) - 7 ), 2);
    return result;
}

double compute_derivation ( point solution, point epsilon, double epsilon_scalar )
{
    double result;
    struct point solution_u, solution_l;

    solution_u.x = solution.x + epsilon.x;
    solution_u.y = solution.y + epsilon.y;
    solution_u.z = solution.z + epsilon.z;

    solution_l.x = solution.x - epsilon.x;
    solution_l.y = solution.y - epsilon.y;
    solution_l.z = solution.z - epsilon.z;

    result = (value( solution_u ) - value( solution_l )) / ( 2*epsilon_scalar );

    return result;
}

struct point euler_gradient ( point solution )
{
    struct point result;
    double div_x, div_y, div_z;
    struct point epsilon_x, epsilon_y, epsilon_z;

    epsilon_x.x = 0.1;
    epsilon_x.y = 0;
    epsilon_x.z = 0;

    epsilon_y.x = 0;
    epsilon_y.y = 0.1;
    epsilon_y.z = 0;

    epsilon_z.x = 0;
    epsilon_z.y = 0;
    epsilon_z.z = 0.1;

    result.x = compute_derivation( solution, epsilon_x, 0.1 );
    result.y = compute_derivation( solution, epsilon_y, 0.1 );
    result.z = compute_derivation( solution, epsilon_z, 0.1 );

    return result;
}

double vector_distance ( point a, point b )
{
    return sqrt( pow( ( a.x - b.x ), 2) + pow( ( a.y - b.y ), 2 ) + pow( ( a.z - b.z ),2 ) );
}

struct point negative_vector ( point a )
{
    point result;
    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;

    return result;
}

int main()
{
    struct point solution;
    struct point direction;
    solution.x = 6;
    solution.y = -10;
    solution.z = -9;
    double function_value;
    struct point gradient_value, euler_point;
    struct point zero_vector;

    zero_vector.x = 0;
    zero_vector.y = 0;
    zero_vector.z = 0;

    double lambda_lower, lambda_upper, lambda;
    lambda_lower = 0;
    lambda_upper = 2; /* TODO: implementiraj uvrstavanje za gornju granicu */
/*
    function_value = value(solution);
    std::cout << function_value << std::endl;

    gradient_value = gradient(solution);
    euler_point = euler_gradient(solution);
    //std::cout << gradient_value.x << gradient_value.y << gradient_value.z << std::endl;
    printf("[ %f %f %f ]\n", gradient_value.x, gradient_value.y, gradient_value.z);
    printf("[ %f %f %f ]\n", euler_point.x, euler_point.y, euler_point.z);
*/
    int i = 0;
    while(true) {
        if ( ( vector_distance(zero_vector, euler_gradient(solution)) ) < 0.01 )
            break;
        direction = euler_gradient( solution );
        direction = negative_vector( direction );
        while(true) {
            lambda = (lambda_lower + lambda_upper) / 2;
            struct point sol_theta;
            sol_theta.x = solution.x + lambda*direction.x;
            sol_theta.y = solution.y + lambda*direction.y;
            sol_theta.z = solution.z + lambda*direction.z;

            struct point der_theta = euler_gradient( sol_theta );
            //printf("%f %f %f\n", der_theta.x, der_theta.y, der_theta.z);
            double tmp;
            tmp = der_theta.x * direction.x + der_theta.y * direction.y + der_theta.z * direction.z;
            //printf("%f\n", tmp);
            if ( fabs(tmp) < 0.01 ) {
                break;
            }
            else if ( tmp > 0 ) {
                lambda_upper = lambda;
            }
            else {
                lambda_lower = lambda;
            }
            i++;
        }

        printf("%f %f %f\n", lambda*direction.x, lambda*direction.y, lambda*direction.z);
        solution.x = solution.x + lambda * direction.x;
        solution.y = solution.y + lambda * direction.y;
        solution.z = solution.z + lambda * direction.z;
    }
    printf("%f %f %f\n", solution.x, solution.y, solution.z);
    return 0;
}